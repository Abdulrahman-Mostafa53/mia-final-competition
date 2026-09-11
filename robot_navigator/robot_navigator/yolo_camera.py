import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
import cv2
from cv_bridge import CvBridge, CvBridgeError

cv2.namedWindow("frame from camera",cv2.WINDOW_NORMAL)

class YoloCamera(Node):
    def __init__(self):
        super().__init__("yolo_camera")
        self.cam_subscriber = self.create_subscription(
            Image, "mono/image", self.analyze_camera, 10
        )
        self.bridge_object = CvBridge()

    def analyze_camera(self, msg):
        try:
            cv_image = self.bridge_object.imgmsg_to_cv2(msg, desired_encoding="mono8")
            cv2.imshow('frame from camera',cv_image)
            cv2.waitKey(1)
        except CvBridgeError as e:
            print(e)


def main():
    rclpy.init()
    node = YoloCamera()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == "__main__":
    main()
