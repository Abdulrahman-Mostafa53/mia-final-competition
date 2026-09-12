import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from Autonomous import AutonomousSearchController

class RobotDriver(Node):
    def __init__(self):
        super().__init__('robot_driver')
        self.publisher_ = self.create_publisher(Twist, 'cmd_vel', 10)
        self.controller = AutonomousSearchController()
        self.timer = self.create_timer(0.1, self.send_velocity) 

    def send_velocity(self):
        detected_objects_list = []
        movement = self.controller.compute_next_move(detected_objects_list)

        msg = Twist()
        msg.linear.x = movement["vx"]
        msg.linear.y = movement["vy"]
        msg.angular.z = 0.0
        self.publisher_.publish(msg)

def main(args=None):
    rclpy.init(args=args)
    node = RobotDriver()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()
