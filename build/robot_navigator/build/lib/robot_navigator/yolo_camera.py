import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
import cv2
from cv_bridge import CvBridge, CvBridgeError
from ultralytics import YOLO
from ament_index_python.packages import get_package_share_directory
import os
from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy, DurabilityPolicy

qos_profile = QoSProfile(
    reliability=ReliabilityPolicy.BEST_EFFORT,
    durability=DurabilityPolicy.VOLATILE,
    history=HistoryPolicy.KEEP_LAST,
    depth=3
)



class YoloCamera(Node):
    def __init__(self):
        super().__init__("yolo_camera")

        pkg_share_dir = get_package_share_directory("robot_navigator")
        yolo_model_path = os.path.join(pkg_share_dir, "yolo_model", "best.pt")

        self.cam_subscriber = self.create_subscription(
            Image, "mono/image", self.analyze_camera, qos_profile
        )
        self.model = YOLO(yolo_model_path)
        self.bridge_object = CvBridge()
        cv2.namedWindow("frame from camera", cv2.WINDOW_NORMAL)

    def analyze_camera(self, msg):
        try:
            cv_image = self.bridge_object.imgmsg_to_cv2(msg, desired_encoding="bgr8")
        except CvBridgeError as e:
            self.get_logger().error(f"CvBridge Error: {e}")
            return
        results = self.model(cv_image, conf=0.5, verbose=False ,iou=0.5)
        annotated_frame = results[0].plot()
        cv2.imshow("frame from camera", annotated_frame)
        cv2.waitKey(1)

    def destroy_node(self):
        cv2.destroyAllWindows()
        super().destroy_node()


def main():
    rclpy.init(args=None)
    node = YoloCamera()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()
