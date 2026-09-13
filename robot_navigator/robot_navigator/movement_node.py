import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from pynput import keyboard
import math


# define velocity key mappings
key_Linear_velocity_map = {"x":{"w": 255.0, "s": -255.0}, "y":{"a": 255.0, "d": -225.0}}
key_angular_velocity_map = {"right": -3.14, "left": 3.14}



class Movement_Node(Node):
    # turtle controller node class

    def __init__(self):
        super().__init__("movement_node")
        
        # create initial subscribers and publishers
        self.speed_publisher = self.create_publisher(Twist, "/cmd_vel", 10)
        # listen for keyboard input
        self.keyboard_listener = keyboard.Listener(
            on_press=self.on_key_press, on_release=self.on_key_release
        )
        self.keyboard_listener.start()
        self.move = True

        self.lin_speed_mul = 0.2
        self.ang_speed_mul = 0.2
        


    def on_key_press(self, key):
        # handle publishing velocity on key press and changing use_stamped_vel state
        msg = Twist()
        try:
            
            if key.char in key_Linear_velocity_map["x"].keys():
                msg.linear.x = key_Linear_velocity_map["x"][key.char]
                if self.move:
                    self.speed_publisher.publish(msg)
                    self.move = False

            elif key.char in key_Linear_velocity_map["y"].keys():
                msg.linear.y = key_Linear_velocity_map["y"][key.char]
                if self.move:
                    self.speed_publisher.publish(msg)
                    self.move = False
                
        except AttributeError:

            if key.name in key_angular_velocity_map.keys():
                msg.angular.z = key_angular_velocity_map[key.name]
                if self.move:
                    self.speed_publisher.publish(msg)
                    self.move = False


    def on_key_release(self, key):
        # handle key release
        msg = Twist()
        msg.linear.x = 0.0
        msg.linear.y = 0.0
        msg.angular.z = 0.0
        self.move =True
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