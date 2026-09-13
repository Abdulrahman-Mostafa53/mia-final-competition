import math
import time
from pynput import keyboard
import rclpy

FORWARD_SPEED = 0.3
ROTATION_SPEED = 0.55

class AutonomousSearchController:
    def __init__(self,node):
        self.state = "pre_90"
        self.ros_node = node    
        self.current_ultrasonic = 100
        self.vx = 0.0
        self.vy = 0.0
        self.omega = 0.0
        self.keyboard_listener = keyboard.Listener(
            on_press=self.on_key_press
        )
        self.keyboard_listener.start()

    def on_key_press(self,key):
        if key.char == "m":
            self.state = ""
            self.ros_node.timer.cancel()
            rclpy.shutdown()

    def update_sensor(self, ultrasonic_dist):
        self.current_ultrasonic = ultrasonic_dist/100

    def compute_control_command(self):
        
        if self.state == "pre_90":
            if self.current_ultrasonic <= 0.18:
                self.reset_vel()
                self.state = "be_90"
            else:
                self.ros_node.get_logger().info(f'i see obstacle after distance : {self.current_ultrasonic}')
                self.omega = ROTATION_SPEED

        elif self.state == "be_90":
            if self.current_ultrasonic >= 1.11:
                self.ros_node.get_logger().info(f' reached destination , obstacle distance  : {self.current_ultrasonic}')
                self.reset_vel()
                self.state = "move_right"
            else:
                self.ros_node.get_logger().info(f'i see obstacle after distance : {self.current_ultrasonic}')
                self.omega = -ROTATION_SPEED

        elif self.state == "move_right":
            self.vy = -FORWARD_SPEED

        elif self.state == "":
            self.vx = 0.0
            self.vy = 0.0
            self.omega= 0.0


        return self.vx, self.vy, self.omega

    def reset_vel(self):
        self.vx = 0.0
        self.vy= 0.0
        self.omega =0.0
    
