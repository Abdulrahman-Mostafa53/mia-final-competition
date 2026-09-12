import math
import time


ROTATION_DURATION = 0.5
ROTATION_360_DURATION = ROTATION_DURATION + 5.0

STATION_TARGET_DISTANCE_1 = 1.4
STATION_TARGET_DISTANCE_2 = 0.7

FORWARD_SPEED = 2.0
ROTATION_SPEED = 0.55

class AutonomousSearchController:
    def __init__(self,node):
        self.state = "MOVING_TO_CENTER_X"
        self.ros_node = node    
        self.current_ultrasonic = 100
        self.vx = 0.0
        self.vy = 0.0
        self.omega = 0.0

    def update_sensor(self, ultrasonic_dist):
        self.current_ultrasonic = ultrasonic_dist/100

    def compute_control_command(self):
        if self.state == "MOVING_TO_CENTER_X":
            # if self.current_ultrasonic <= 0:
            #     return 0.0, 0.0, 0.0  # Sensor hasn't received a valid reading yet

            if self.current_ultrasonic <= STATION_TARGET_DISTANCE_1:

                self.reset_vel()
                self.state = "ROTATING_90"
                
            else:
                # Move forward or backward until we cover the required delta
                self.vx = FORWARD_SPEED


        elif self.state == "ROTATING_90":
            if not hasattr(self, 'rotation_start_time'):
                self.rotation_start_time = time.monotonic()  # Starting our stop watch
            
            # Check elapsed time
            elapsed_time = time.monotonic() - self.rotation_start_time
            self.ros_node.get_logger().info(f" {elapsed_time}")
            
            if elapsed_time < ROTATION_DURATION:
                self.omega = ROTATION_SPEED
            else:
                self.reset_vel()
                del self.rotation_start_time  # Clean up timer for safety
                self.state = "moveup"


        elif self.state == "moveup":
            self.ros_node.get_logger().info(" i mov rotatingwww")
            
            if self.current_ultrasonic <= STATION_TARGET_DISTANCE_2:
                self.ros_node.get_logger().info(f" i mov rotatingwww {self.current_ultrasonic}  {STATION_TARGET_DISTANCE_2}")
                self.vx = 0.0
                self.state = "ROTATING_360"
            else:
                # Move forward or backward until we cover the required delta
                self.vx = FORWARD_SPEED

        elif self.state == "ROTATING_360":
            # Record the start time on the first iteration of this state
            if not hasattr(self, 'rotation2_start_time'):
                self.rotation2_start_time = time.monotonic()  # Starting our stop watch
            
            # Check elapsed time
            elapsed_time = time.monotonic() - self.rotation2_start_time
            
            if elapsed_time < ROTATION_360_DURATION:
                self.omega = ROTATION_SPEED
            else:
                self.omega = 0.0
                self.reset_vel()
                del self.rotation2_start_time  # Clean up timer for safety
                self.state = ""


        return self.vx, self.vy, self.omega

    def reset_vel(self):
        self.vx = 0.0
        self.vy= 0.0
        self.omega =0.0
    
