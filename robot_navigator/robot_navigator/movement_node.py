import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist, TwistStamped
from pynput import keyboard
import math


# define velocity key mappings
key_Linear_velocity_map = {"x":{"w": 5.0, "s": -5.0}, "y":{"a": 5.0, "d": -5.0}}
key_angular_velocity_map = {"right": -1.5, "left": 1.5}
key_speed_map = {"up": 1, "down": -1}


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


        self.lin_speed_mul = 0.2
        self.ang_speed_mul = 0.2


    def on_key_press(self, key):
        # handle publishing velocity on key press and changing use_stamped_vel state
        msg = Twist()
        try:
            
            if key.char in key_Linear_velocity_map["x"].keys():
                msg.linear.x = key_Linear_velocity_map["x"][key.char]
                self.speed_publisher.publish(msg)

            elif key.char in key_Linear_velocity_map["y"].keys():
                msg.linear.y = key_Linear_velocity_map["y"][key.char]
                self.speed_publisher.publish(msg)
                
        except AttributeError:

            if key.name in key_angular_velocity_map.keys():
                msg.angular.z = key_angular_velocity_map[key.name]
                self.speed_publisher.publish(msg)

            if key.name in key_speed_map.keys():
                for dir in key_Linear_velocity_map:
                    for key_speed in key_Linear_velocity_map[dir]:
                        initial_val = key_Linear_velocity_map[dir][key_speed]
                        added_term = key_speed_map[key.name] * (initial_val*self.lin_speed_mul)

                        key_Linear_velocity_map[dir][key_speed] += added_term
                        final_val = key_Linear_velocity_map[dir][key_speed]
                        if abs(final_val)>=255:
                            key_Linear_velocity_map[dir][key_speed] = math.copysign(255,key_Linear_velocity_map[dir][key_speed])


                for key_speed in key_angular_velocity_map:
                    initial_val = key_angular_velocity_map[key_speed]
                    added_term =  key_speed_map[key.name] * (initial_val*self.ang_speed_mul)
                    key_angular_velocity_map[key_speed] += added_term
                    final_val = key_angular_velocity_map[key_speed]
                    
                    if abs(final_val)>=(3.14/4):
                        key_angular_velocity_map[key_speed] = math.copysign(3.14/4,key_angular_velocity_map[key_speed])
                        
            

    def on_key_release(self, key):
        # handle key release
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