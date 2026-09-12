import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32  

class UltrasonicSubscriber(Node):
    def __init__(self):
        super().__init__('ultrasonic_subscriber')
        
        self.subscription = self.create_subscription(
            Float32,
            '/ultrasonic_distance',
            self.listener_callback,
            10
        )
        self.subscription  

    def listener_callback(self, msg):
        distance_cm = msg.data * 100
        self.get_logger().info(f'Measured Distance: {distance_cm:.2f} cm')

def main(args=None):
    rclpy.init(args=args)
    node = UltrasonicSubscriber()
    
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
