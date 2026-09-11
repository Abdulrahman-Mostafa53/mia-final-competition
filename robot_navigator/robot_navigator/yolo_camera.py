import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
import cv2
from cv_bridge import CvBridge, CvBridgeError
from ultralytics import YOLO

class YoloCamera(Node):
    def __init__(self):
        super().__init__("yolo_camera")
        self.cam_subscriber = self.create_subscription(
            Image, "mono/image", self.analyze_camera, 10
        )
        self.model = YOLO("runs/detect/train/weights/best.pt")
        self.bridge_object = CvBridge()
        cv2.namedWindow("frame from camera", cv2.WINDOW_NORMAL)
    def analyze_camera(self, msg):
        try:
            cv_image = self.bridge_object.imgmsg_to_cv2(msg, desired_encoding="bgr8")
        except CvBridgeError as e:
            self.get_logger().error(f"CvBridge Error: {e}")
            return
        results = self.model(cv_image, conf=0.25, verbose=False)
        annotated_frame = results[0].plot()
        cv2.imshow('frame from camera', annotated_frame)
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
