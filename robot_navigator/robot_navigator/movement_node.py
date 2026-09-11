import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist, TwistStamped
from pynput import keyboard


# define velocity key mappings
key_Linear_velocity_map = {"w": 5.0, "s": -5.0, "up": 5.0, "down": -5.0}
key_angular_velocity_map = {"d": -1.5, "a": 1.5, "right": -1.5, "left": 1.5}


class Movement_Node(Node):
    # turtle controller node class

    def __init__(self):
        super().__init__("movement_node")
        # using stamped velocity state

        # create initial subscribers and publishers
        self.speed_publisher = self.create_publisher(Twist, "/cmd_vel", 10)
        # listen for keyboard input
        self.keyboard_listener = keyboard.Listener(
            on_press=self.on_key_press, on_release=self.on_key_release
        )
        self.keyboard_listener.start()


    def on_key_press(self, key):
        # handle publishing velocity on key press and changing use_stamped_vel state
        msg = Twist()
        self.get_logger().info(str(key))
        try:
            if key.char in key_Linear_velocity_map.keys():
                print("chcaaaaaaaaaa ",key.char)
                msg.linear.x = key_Linear_velocity_map[key.char]
                self.speed_publisher.publish(msg)
            if key.char in key_angular_velocity_map.keys():
                msg.angular.z = key_angular_velocity_map[key.char]
                self.speed_publisher.publish(msg)
                
        except AttributeError:
            if key.name in key_Linear_velocity_map.keys():
                msg.linear.x = key_Linear_velocity_map[key.name]
                self.speed_publisher.publish(msg)
            if key.name in key_angular_velocity_map.keys():
                msg.angular.z = key_angular_velocity_map[key.name]
                self.speed_publisher.publish(msg)

    def on_key_release(self, key):
        # handle key release
        self.get_logger().info("key [released] {key}")
        msg = Twist()
        msg.linear.x = 0.0
        msg.linear.y = 0.0
        msg.angular.z = 0.0
        self.speed_publisher.publish(msg)



def main():
    rclpy.init()
    node = Movement_Node()
    rclpy.spin(node)
    node.keyboard_listener.stop()
    node.keyboard_listener.join()
    node.destroy_node()
    rclpy.shutdown()


if __name__ == "__main__":
    main()