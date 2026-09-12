import math
import time

# ==========================================
# SYSTEM CONSTANTS (Field & Robot Dimensions)
# ==========================================
FIELD_WIDTH = 2.8          # Total field width horizontally (280 cm)
FIELD_LENGTH = 1.65        # Half-field length vertically (165 cm)
ROBOT_LENGTH = 0.6         # Robot length (60 cm)
ROBOT_WIDTH = 0.5          # Robot width / shoulders (50 cm)
ROTATION_DURATION = 3.0  # Duration in seconds for 90-degree rotation
ROTATION_360_DURATION = ROTATION_DURATION * 4.0
DISTANCE_ALLOWANCE = 0.05

# Half length (Distance from robot center to the front ultrasonic sensor)
ROBOT_HALF_LENGTH = ROBOT_LENGTH / 2.0  # 30 cm

# Target along X-axis: Robot center at 1.4 meters (midpoint of 280 cm)
TARGET_CENTER_X = 1.4 

# Thirds
STATION_TARGET_DISTANCE_1 = 1
STATION_TARGET_DISTANCE_2 = 0.5


# Movement Speeds
FORWARD_SPEED = 0.3
STRAFE_SPEED = 0.3
ROTATION_SPEED = 0.5

class AutonomousSearchController:
    def __init__(self):

        # State machine for controlling the execution sequence
        # 1. MOVING_TO_CENTER_X: Align X-axis to the center using delta & half-length
        # 2. STRAFING_FOR_CLEARANCE: Small lateral strafe left to gain clearance
        # 3. ROTATING_90: Rotate 90 degrees left to face the 165cm length axis
        # 4. SCANNING: Move longitudinally and stop at thirds (e.g., 1.1m and 0.55m)
        # 5. DONE: Finished

        self.state = "MOVING_TO_CENTER_X"
        
        self.current_ultrasonic = 0.0
        
        # Variables to store initial readings for Delta calculations
        self.initial_ultrasonic = None
        self.target_delta = 1.1  # 80 cm movement to center + 30 cm robot half length
        
        # Station target distances along the 165cm axis (ultrasonic readings)
        self.station_target_distances = [STATION_TARGET_DISTANCE_1, STATION_TARGET_DISTANCE_2] 
        self.current_station_idx = 0

    def update_sensor(self, ultrasonic_dist):
        # Update periodic ultrasonic sensor readings
        self.current_ultrasonic = ultrasonic_dist

    def compute_control_command(self):
        # Compute control commands (vx, vy, omega) based on the current state
        vx = 0.0
        vy = 0.0
        omega = 0.0

        # -------------------------------------------------------------
        # State 1: Reach X Center (Robot center at 1.4 meters)
        # -------------------------------------------------------------
        if self.state == "MOVING_TO_CENTER_X":
            if self.current_ultrasonic <= 0:
                return vx, vy, omega  # Sensor hasn't received a valid reading yet

            # On the first iteration of this state, log initial reading and calculate target
            if self.initial_ultrasonic is None:
                self.initial_ultrasonic = self.current_ultrasonic
                print(f"[Init] Initial Ultrasonic: {self.initial_ultrasonic}m | Target Delta: {self.target_delta}m")
            # Calculate current delta (how much distance we have covered/changed)
            current_delta = abs(self.initial_ultrasonic - self.current_ultrasonic)

            # If close enough to the target distance (within a 2cm tolerance)
            if abs(current_delta - self.target_delta) <= DISTANCE_ALLOWANCE:
                vx = 0.0
                print("[State Complete] Reached X Center! Moving to lateral strafe for clearance.")
                self.state = "ROTATING_90"
            else:
                # Move forward or backward until we cover the required delta
                if current_delta < self.target_delta:
                    vx = FORWARD_SPEED
                else:
                    vx = -FORWARD_SPEED

        # we will skip it now

        # -------------------------------------------------------------
        # State 2: Small lateral strafe left to ensure safe rotation clearance
        # -------------------------------------------------------------
        elif self.state == "STRAFING_FOR_CLEARANCE":
            # Strafe left for a brief duration or distance
            vy = STRAFE_SPEED 
            # After completing this lateral movement:
            # self.state = "ROTATING_90"
            pass

        # from state 1 to state 3 directly
         
        # -------------------------------------------------------------
        # State 3: Rotate 90 degrees left
        # -------------------------------------------------------------
        elif self.state == "ROTATING_90":
            # Record the start time on the first iteration of this state
            if not hasattr(self, 'rotation_start_time'):
                self.rotation_start_time = time.monotonic()  # Starting our stop watch
            
            # Check elapsed time
            elapsed_time = time.monotonic() - self.rotation_start_time
            
            if elapsed_time < ROTATION_DURATION:
                omega = ROTATION_SPEED
            else:
                omega = 0.0
                print(f"[State Complete] Rotated 90 degrees in {elapsed_time:.2f} seconds! Moving to scanning.")
                del self.rotation_start_time  # Clean up timer for safety
                self.state = "SCANNING"

        # -------------------------------------------------------------
        # State 4: Move longitudinally along the 165cm axis and stop at stations
        # -------------------------------------------------------------
        elif self.state == "SCANNING":
            if self.current_station_idx < len(self.station_target_distances):
                target_dist = self.station_target_distances[self.current_station_idx]
                
                # Directly rely on the front ultrasonic sensor (now facing the length axis)
                if abs(self.current_ultrasonic - target_dist) <= DISTANCE_ALLOWANCE:
                    vx = 0.0

                    print(f"[Station {self.current_station_idx}] Reached! Starting 360 Scan...")
                    
                    # --- 360-degree rotation ---
                    if not hasattr(self, 'scan_360_start_time'):
                        self.scan_360_start_time = time.monotonic()
                    
                    elapsed_360 = time.monotonic() - self.scan_360_start_time
                    
                    if elapsed_360 < ROTATION_360_DURATION:
                        omega = ROTATION_SPEED  
                     
                    else:
                        omega = 0.0
                        print(f"[Station {self.current_station_idx}] 360 Scan completed!")
                        del self.scan_360_start_time  # Clean up timer
                        self.current_station_idx += 1 # Move to the next station only after 360 scan finishes
                else:
                    if self.current_ultrasonic > target_dist:
                        vx = FORWARD_SPEED
                    else:
                        vx = -FORWARD_SPEED
            else:
                print("[Done] All scanning stations completed successfully!")
                self.state = "DONE"

        return vx, vy, omega
    
