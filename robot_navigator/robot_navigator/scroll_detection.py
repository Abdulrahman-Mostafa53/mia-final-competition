import rclpy
from rclpy.node import Node

from sensor_msgs.msg import Image
from std_msgs.msg import Float32
from sensor_msgs.msg import LaserScan
from geometry_msgs.msg import Twist

from cv_bridge import CvBridge
from ultralytics import YOLO
import time

from pynput import keyboard


from robot_navigator.autonomous_controller import AutonomousSearchController

MODEL_PATH = "/home/abdulrahman/MIA/contest/src/robot_navigator/yolo_model/best.pt"          # path to your trained YOLO weights
CONFIDENCE_THRESHOLD = 0.5     # tune based on your F1-confidence curve
CONTROL_LOOP_HZ = 10.0          # how often we send a cmd_vel command


class ScrollDetectionNode(Node):
    def __init__(self):
        super().__init__("scroll_detection_node")

        self.bridge = CvBridge()
        self.model = YOLO(MODEL_PATH)
        self.controller = AutonomousSearchController()

        self.latest_ultrasonic = None
        self.latest_detections = []  # refreshed every time a new camera frame arrives

        # --- Subscriptions ---
        self.create_subscription(Image, "/mono/image", self.on_image, 10)
        self.create_subscription(LaserScan, "/ultrasonic_distance", self.on_ultrasonic, 10)

        # --- Publisher ---
        self.cmd_pub = self.create_publisher(Twist, "/cmd_vel", 10)

        # --- Control loop timer ---
        self.timer = self.create_timer(1.0 / CONTROL_LOOP_HZ, self.control_loop)

        self.get_logger().info("Scroll detection node started.")

        self.keyboard_listener = keyboard.Listener(
            on_press=self.shut_down_node
        )
        self.keyboard_listener.start()

    def shut_down_node(self,key):
        if key.char == "m":
            self.get_logger().info("killed auto node")
            self.timer.cancel()
            rclpy.shutdown()




    def on_ultrasonic(self, msg):
        self.latest_ultrasonic = min(msg.ranges)

    def on_image(self, msg: Image):
        # Convert the ROS image message into a plain OpenCV/numpy frame
        frame = self.bridge.imgmsg_to_cv2(msg, desired_encoding="bgr8")
        frame_width = frame.shape[1]

        results = self.model.predict(source=frame, conf=CONFIDENCE_THRESHOLD, verbose=False,iou = 0.5)

        detections = []
        for box in results[0].boxes:
            cls_id = int(box.cls[0])
            class_name = self.model.names[cls_id]
            confidence = float(box.conf[0])

            # box.xywh gives center_x, center_y, width, height in pixels
            x_center_px = float(box.xywh[0][0])

            # Normalize horizontal offset from frame center to roughly -1 .. 1
            center_x_norm = (x_center_px - (frame_width / 2.0)) / (frame_width / 2.0)

            detections.append({
                "class": class_name,
                "confidence": confidence,
                "center_x_norm": center_x_norm,
            })

        self.latest_detections = detections

    def control_loop(self):
        previous_state = self.controller.state

        move = self.controller.compute_next_move(
            detected_objects=self.latest_detections,
            ultrasonic_distance=self.latest_ultrasonic,
        )

        if self.controller.state != previous_state:
            self.get_logger().info(f"State changed: {previous_state} -> {self.controller.state}")

        twist = Twist()
        twist.linear.x = move["vx"]
        twist.angular.z = move["wz"]
        self.cmd_pub.publish(twist)


def main(args=None):
    rclpy.init(args=args)
    node = ScrollDetectionNode()
    try:
        time.sleep(7)
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == "__main__":
    main()