import math
import time

# ==========================================
# SYSTEM CONSTANTS (Field & Robot Dimensions)
# ==========================================
FIELD_WIDTH = 2.8          # Total field width horizontally (280 cm)
FIELD_LENGTH = 1.65        # Half-field length vertically (165 cm)
ROBOT_LENGTH = 0.6         # Robot length (60 cm)
ROBOT_WIDTH = 0.5          # Robot width / shoulders (50 cm)
ROTATION_DURATION = 10.0 # Duration in seconds for 90-degree rotation
ROTATION_360_DURATION = ROTATION_DURATION * 4.0
DISTANCE_ALLOWANCE = 0.05

# Half length (Distance from robot center to the front ultrasonic sensor)
ROBOT_HALF_LENGTH = ROBOT_LENGTH / 2.0  # 30 cm

# Target along X-axis: Robot center at 1.4 meters (midpoint of 280 cm)
TARGET_CENTER_X = 1.4 

# Thirds
STATION_TARGET_DISTANCE_1 = 1.8
STATION_TARGET_DISTANCE_2 = 0.5


# Movement Speeds
FORWARD_SPEED = 50.0
STRAFE_SPEED = 50.0
ROTATION_SPEED = 50.0

class AutonomousSearchController:
    def __init__(self,node):

        # State machine for controlling the execution sequence
        # 1. MOVING_TO_CENTER_X: Align X-axis to the center using delta & half-length
        # 2. STRAFING_FOR_CLEARANCE: Small lateral strafe left to gain clearance
        # 3. ROTATING_90: Rotate 90 degrees left to face the 165cm length axis
        # 4. SCANNING: Move longitudinally and stop at thirds (e.g., 1.1m and 0.55m)
        # 5. DONE: Finished

        self.state = "ROTATING_90"

        self.ros_node = node
        
        self.current_ultrasonic = 100        # 3. ROTATING_90: Rotate 90 degrees left to face the 165cm length axis
        # 4. SCANNING: Move longitudinally and stop at thirds (e.g., 1.1m and 0.55m)
        # 5. DONE: Finished

        self.ros_node = node
        
        self.current_ultrasonic = 100
        
        # Station target distances along the 165cm axis (ultrasonic readings)
        self.station_target_distances = [STATION_TARGET_DISTANCE_1, STATION_TARGET_DISTANCE_2] 
        self.current_station_idx = 0

        self.vx = 0.0
        self.vy = 0.0
        self.omega = 0.0

    def update_sensor(self, ultrasonic_dist):
        # Update periodic ultrasonic sensor readings
        self.ros_node.get_logger().info(f"i entered compute {ultrasonic_dist}")
        self.current_ultrasonic = ultrasonic_dist

    def compute_control_command(self):
        # Compute control commands (vx, vy, omega) based on the current state
        # -------------------------------------------------------------
        # State 1: Reach X Center (Robot center at 1.4 meters)
        # -------------------------------------------------------------

        if self.state == "MOVING_TO_CENTER_X":
            if self.current_ultrasonic <= 0:
                return self.vx, self.vy, self.omega  # Sensor hasn't received a valid reading yet

            # If close enough to the target distance (within a 2cm tolerance)
            if abs(self.current_ultrasonic <= STATION_TARGET_DISTANCE_1):
                self.vx = 0.0
                print("[State Complete] Reached X Center! Moving to lateral strafe for clearance.")
                self.state = "ROTATING_90"
                self.current_station_idx = 1
            else:
                # Move forward or backward until we cover the required delta
                self.vx = FORWARD_SPEED

        # we will skip it now

        # -------------------------------------------------------------
        # State 2: Small lateral strafe left to ensure safe rotation clearance
        # -------------------------------------------------------------
        elif self.state == "STRAFING_FOR_CLEARANCE":
            # Strafe left for a brief duration or distance
            self.vy = STRAFE_SPEED 
            # After completing this lateral movement:
            # self.state = "ROTATING_90"
            pass

        # from state 1 to state 3 directly
         
        # -------------------------------------------------------------
        # State 3: Rotate 90 degrees left
        # -------------------------------------------------------------
        elif self.state == "ROTATING_90":
            # Record the start time on the first iteration of this state
            self.ros_node.get_logger().info("rotate now")
            if not hasattr(self, 'rotation_start_time'):
                self.rotation_start_time = time.monotonic()  # Starting our stop watch
            
            # Check elapsed time
            elapsed_time = time.monotonic() - self.rotation_start_time
            
            if elapsed_time < ROTATION_DURATION:
                self.omega = ROTATION_SPEED
            else:
                self.omega = 0.0
                print(f"[State Complete] Rotated 90 degrees in {elapsed_time:.2f} seconds! Moving to scanning.")
                del self.rotation_start_time  # Clean up timer for safety
                self.state = "moveup"

        # -------------------------------------------------------------
        # State 4: Move longitudinally along the 165cm axis and stop at stations
        # -------------------------------------------------------------

        elif self.state == "moveup":
            if not hasattr(self, 'move_up_start_time'):
                self.move_up_start_time = time.monotonic()  # Starting our stop watch
            
            # Check elapsed time
            elapsed_time = time.monotonic() - self.move_up_start_time
            self.ros_node.get_logger().info(f"elpaseddddd {elapsed_time:.2f}")
            if elapsed_time < 1.6:
                self.vx = FORWARD_SPEED
            else:
                self.vx = 0.0
                self.ros_node.get_logger().info(f"[State Complete] moved up in {elapsed_time:.2f} seconds! Moving to stop.")
                del self.move_up_start_time  # Clean up timer for safety
                self.state = "ROTATING_360"

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
                print(f"[State Complete] Rotated 90 degrees in {elapsed_time:.2f} seconds! Moving to scanning.")
                del self.rotation2_start_time  # Clean up timer for safety
                self.state = ""


        return self.vx, self.vy, self.omega
    
