import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from sensor_msgs.msg import LaserScan
from std_msgs.msg import Int32
from robot_navigator.auto import AutonomousSearchController

class AutonomousNode(Node):
    def __init__(self):
        super().__init__('autonomous_search_node')
        
        
        self.controller = AutonomousSearchController(self)
        
        
        self.cmd_publisher = self.create_publisher(Twist, '/cmd_vel', 10)
        
        
        self.ultrasonic_sub = self.create_subscription(
            Int32, 
            '/ultrasonic_distance', 
            self.ultrasonic_callback, 
            10
        )
        
        # Periodic control loop timer running at 20 Hz (every 0.05 seconds)
        self.timer = self.create_timer(0.05, self.control_loop)

    def ultrasonic_callback(self, msg):
        # Update the ultrasonic distance reading in the controller state machine
        self.controller.update_sensor(msg.data/100)
        self.get_logger().info("hello")

    def control_loop(self):
        # Compute control commands (vx, vy, omega) based on the current active state
        vx, vy, omega = self.controller.compute_control_command()
        self.get_logger().info("i am computing")
        # Construct and publish the Twist message
        twist = Twist()
        self.get_logger().info(f"hello {vx} {omega}")
        twist.linear.x = float(vx)
        twist.linear.y = float(vy)
        twist.angular.z = float(omega)
        
        self.cmd_publisher.publish(twist)

def main():
    rclpy.init()
    node = AutonomousNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
    
