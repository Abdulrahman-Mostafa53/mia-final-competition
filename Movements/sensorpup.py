import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32
import serial

class UltrasonicSerialPublisher(Node):
    def __init__(self):
        super().__init__('ultrasonic_publisher')
        self.publisher_ = self.create_publisher(Float32, 'ultrasonic_distance', 10)
        self.timer = self.create_timer(0.1, self.timer_callback)
        
        self.serial_port = serial.Serial('/dev/ttyUSB0', 115200, timeout=1.0)

    def timer_callback(self):
        try:
            line = self.serial_port.readline().decode('utf-8').strip()
            if line:
                dist_val = float(line)
                if dist_val >= 0:
                    msg = Float32()
                    msg.data = dist_val
                    self.publisher_.publish(msg)
                    self.get_logger().info(f'Published Distance: {dist_val} cm')
        except (ValueError, serial.SerialException) as e:
            pass

def main(args=None):
    rclpy.init(args=args)
    node = UltrasonicSerialPublisher()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
