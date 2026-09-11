import math

# --- System Constants ---
CAMERA_RANGE_X = 0.6                  # Base camera field of view range in meters
SCROLL_SIZE = 0.35                    # Scroll cube side length in meters
FIELD_WIDTH = 2.8                     # Field width in meters
FIELD_LENGTH = 1.65                   # Half-field length in meters
SCROLL_MATCH_THRESHOLD = 0.2          # Tolerance distance in meters to filter duplicate scrolls

# Robot Physical Dimensions
ROBOT_WIDTH = 0.6                     
ROBOT_LENGTH = 0.5

# Robot Movement Speeds Constants
SWEEPING_SPEED_Y = 0.6                      
FORWARD_SPEED_X = 1.0

# Dynamic range limits calculated from core constants 
MAX_DETECTION_RANGE = CAMERA_RANGE_X              # Maximum active range 

# Safety factors to prevent penalties 
WALL_MARGIN = 0.1                                             #  (10 cm allowance)
SAFE_MIN_X = WALL_MARGIN + (ROBOT_WIDTH / 2.0)                #  meters from left wall
SAFE_MAX_X = FIELD_WIDTH - WALL_MARGIN - (ROBOT_WIDTH / 2.0)  #  meters from right wall 
MOVING_ALLOWANCE = 0.05                               #  Safety allowance in meters added to targeted movement

class AutonomousSearchController:
    def __init__(self):

        self.current_x = 0.0
        self.current_y = 0.0

        self.target_scroll_y = 0.0
        self.target_scroll_x = 0.0

        self.detected_scrolls = []
        self.autonomous_complete = False
        self.strafe_direction = 1 
        self.target_y_limit = 0.0
        self.temp_x_limit = None
        self.search_state = "SWEEPING"
        
        # Flag to check if a scroll was detected in the current step
        self.scroll_detected_in_this_step = False

    def log_scroll_detection(self, scroll_x, scroll_y):
        # Verify if the detected scroll is new and not a duplicate
        is_new = True
        for (sx, sy) in self.detected_scrolls:
            distance = math.hypot(scroll_x - sx, scroll_y - sy)
            if distance < SCROLL_MATCH_THRESHOLD:  # Too close to an already logged scroll
                is_new = False
                break
        
        if is_new:
            self.detected_scrolls.append((scroll_x, scroll_y))
            self.scroll_detected_in_this_step = True  # Mark that a new scroll was found in this step!
            self.target_scroll_y = scroll_y
            self.target_scroll_x = scroll_x
            print(f"New scroll detected at coordinates: X={scroll_x:.2f}, Y={scroll_y:.2f}")
            
            # Check if we reached the required target (2 scrolls)
            if len(self.detected_scrolls) >= 2:
                self.autonomous_complete = True
                print("Both scrolls successfully detected! Switching to manual mode flag.")

    def compute_next_move(self, detected_objects_list):
        if self.autonomous_complete:
            return {"vx": 0.0, "vy": 0.0, "mode": "MANUAL"}

        # Reset the detection flag at the beginning of each loop step
        self.scroll_detected_in_this_step = False
        vx = 0.0
        vy = 0.0

        # Process detected objects
        for obj in detected_objects_list:
            if obj["class"] == "scroll":
                # Ensure the distance is within the active detection range 
                if obj["y"] <= MAX_DETECTION_RANGE:
                    self.log_scroll_detection(obj["x"], obj["y"])
        if self.search_state == "SWEEPING":
         
         vy = self.strafe_direction * SWEEPING_SPEED_Y
         vx = 0.0

         # Determine forward step distance based on whether a scroll was detected
         if self.scroll_detected_in_this_step:
             # Calculate safety margin to check if the scroll itself is trapped near the walls
             scroll_safe_margin = WALL_MARGIN + (ROBOT_WIDTH / 2.0) + (SCROLL_SIZE / 2.0) + MOVING_ALLOWANCE

             if (self.current_x < FIELD_WIDTH / 2.0 and self.target_scroll_x < FIELD_WIDTH / 2.0) or \
                (self.current_x >= FIELD_WIDTH / 2.0 and self.target_scroll_x >= FIELD_WIDTH / 2.0):

             
                 if self.target_scroll_x <= scroll_safe_margin or self.target_scroll_x >= FIELD_WIDTH - scroll_safe_margin:
                     print(f"Target scroll at X={self.target_scroll_x:.2f} is trapped near the wall! Adjusting strategy.")
                     self.strafe_direction *= -1
                     if self.target_scroll_x <= scroll_safe_margin:
                         self.temp_x_limit = self.target_scroll_x + (SCROLL_SIZE / 2.0) + (ROBOT_WIDTH / 2.0) + MOVING_ALLOWANCE
                     else:
                         self.temp_x_limit = self.target_scroll_x - (SCROLL_SIZE / 2.0) - (ROBOT_WIDTH / 2.0) - MOVING_ALLOWANCE
             else:
                 self.search_state = "MOVING_FORWARD"
                 step_dist = self.target_scroll_y + (SCROLL_SIZE / 2.0) + (ROBOT_LENGTH / 2.0)  + MOVING_ALLOWANCE
                 self.target_y_limit = self.current_y + step_dist
                 print(f"Scroll targeted at Y={self.target_scroll_y:.2f}: Applying dynamic forward step.")

         else:
             # No scroll detected: check if external current_x has reached the boundaries
             hit_boundary = False

             if self.temp_x_limit is not None:
               if self.strafe_direction == 1 and self.current_x >= self.temp_x_limit:
                 hit_boundary = True
               elif self.strafe_direction == -1 and self.current_x <= self.temp_x_limit:
                 hit_boundary = True
             else:
               # Check only the boundary corresponding to the current movement direction
                if self.strafe_direction == 1 and self.current_x >= SAFE_MAX_X:
                 hit_boundary = True
                elif self.strafe_direction == -1 and self.current_x <= SAFE_MIN_X:
                 hit_boundary = True

             if hit_boundary:
                 self.search_state = "MOVING_FORWARD"
                 self.strafe_direction *= -1
                 self.target_y_limit = self.current_y + MAX_DETECTION_RANGE
                 self.temp_x_limit = None
                 print(f"Boundary wall reached. Reversing direction and stepping forward to next row.")
             else:
                 print("Sweeping laterally: Monitoring current position.") 


        if self.search_state == "MOVING_FORWARD":
            vy = 0.0
            if self.current_y >= self.target_y_limit:
                vx = 0.0
                self.search_state = "SWEEPING"
                print("Forward movement target reached. Switching back to SWEEPING.")
            else:
                vx = FORWARD_SPEED_X
                print(f"Moving forward... Current Y: {self.current_y:.2f} / Target: {self.target_y_limit:.2f}")

        
        
        return {
            "vx": vx, 
            "vy": vy, 
            "mode": "AUTONOMOUS"
        }
    
