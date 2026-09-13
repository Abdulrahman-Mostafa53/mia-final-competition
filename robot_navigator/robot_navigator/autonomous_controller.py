import time

# --- Tunable constants ---
ROTATE_SPEED = 0.6                 # angular velocity used while scanning (rad/s, robot units)
FORWARD_SPEED = 0.3                # forward velocity used while approaching a scroll
APPROACH_DISTANCE = 0.8         # meters - ultrasonic threshold to stop approaching (tune w/ scroll size + robot width)
CONFIRM_FRAMES_REQUIRED = 30        # consecutive good frames needed before a scroll counts as "confirmed"
FRAME_CENTER_TOLERANCE = 0.1      # how far off-center (normalized -1..1) is still considered "centered enough"
FULL_ROTATION_TIME = 8.0           # seconds - estimated time for one full 360 at ROTATE_SPEED (tune empirically on the field)
REPOSITION_DRIVE_TIME = 1.5       # seconds - short forward hop if a full rotation finds nothing
REPOSITION_SAFE_DISTANCE = 0.5    # meters - ultrasonic safety cutoff during the repositioning hop
DISENGAGE_ROTATE_TIME = 4.0        # seconds - rotate away after confirming, before scanning again


class AutonomousSearchController:
    def __init__(self):
        self.state = "ROTATING_SCAN"
        self.state_entered_at = time.time()
        self.confirm_streak = 0

    def _enter_state(self, new_state):
        self.state = new_state
        self.state_entered_at = time.time()
        self.confirm_streak = 0

    def _time_in_state(self):
        return time.time() - self.state_entered_at

    def compute_next_move(self, detected_objects, ultrasonic_distance):
        """
        detected_objects: list of dicts, each like:
            {"class": "scroll", "confidence": 0.87, "center_x_norm": -0.15}
            center_x_norm is the object's horizontal offset from frame center,
            normalized to roughly -1 (far left) .. 0 (centered) .. 1 (far right).
        ultrasonic_distance: latest reading in meters from /ultrasonic_distance.

        Returns a dict: {"vx": forward_speed, "wz": angular_speed}
        vx = forward/backward velocity, wz = rotational velocity.
        Publish these directly onto /cmd_vel (mapped to your robot's Twist message).
        """
        best_scroll = self._best_scroll(detected_objects)

        if self.state == "ROTATING_SCAN":
            return self._do_rotating_scan(best_scroll)

        elif self.state == "APPROACHING":
            return self._do_approaching(best_scroll, ultrasonic_distance)

        elif self.state == "DISENGAGING":
            return self._do_disengaging()

        elif self.state == "REPOSITIONING":
            return self._do_repositioning(ultrasonic_distance)

        # Should never reach here
        return {"vx": 0.0, "wz": 0.0}
   

    def _best_scroll(self, detected_objects):
        VALID_TARGET_CLASSES = {"R2_fake", "R2_real"}
        targets = [o for o in detected_objects if o["class"] in VALID_TARGET_CLASSES]
        if not targets:
            return None
        return max(targets, key=lambda o: o["confidence"])

    def _do_rotating_scan(self, best_scroll):
        if best_scroll is not None:
            self._enter_state("APPROACHING")
            return {"vx": 0.0, "wz": 0.0}

        if self._time_in_state() >= FULL_ROTATION_TIME:
            self._enter_state("REPOSITIONING")
            return {"vx": 0.0, "wz": 0.0}

        # Keep spinning in place
        return {"vx": 0.0, "wz": ROTATE_SPEED}

    def _do_approaching(self, best_scroll, ultrasonic_distance):
        if best_scroll is None:
            # Lost sight of it - back off to scanning rather than driving blind
            self._enter_state("ROTATING_SCAN")
            return {"vx": 0.0, "wz": 0.0}

        # Steering correction to keep the scroll centered
        wz = -best_scroll["center_x_norm"] * ROTATE_SPEED
        if abs(best_scroll["center_x_norm"]) < FRAME_CENTER_TOLERANCE:
            wz = 0.0

        centered = abs(best_scroll["center_x_norm"]) < FRAME_CENTER_TOLERANCE
        close_enough = ultrasonic_distance is not None and ultrasonic_distance <= APPROACH_DISTANCE

        if centered and close_enough:
            self.confirm_streak += 1
        else:
            self.confirm_streak = 0

        if self.confirm_streak >= CONFIRM_FRAMES_REQUIRED:
            self._enter_state("DISENGAGING")
            return {"vx": 0.0, "wz": 0.0}

        # Still approaching: drive forward if not yet close, otherwise hold position
        vx = 0.0 if close_enough else FORWARD_SPEED
        return {"vx": vx, "wz": wz}

    def _do_disengaging(self):
        if self._time_in_state() >= DISENGAGE_ROTATE_TIME:
            self._enter_state("ROTATING_SCAN")
            return {"vx": 0.0, "wz": 0.0}
        # Turn away from the just-confirmed scroll before scanning again
        return {"vx": 0.0, "wz": ROTATE_SPEED}

    def _do_repositioning(self, ultrasonic_distance):
        blocked = ultrasonic_distance is not None and ultrasonic_distance <= REPOSITION_SAFE_DISTANCE
        if blocked:
            self._enter_state("ROTATING_SCAN")
            return {"vx": 0.0, "wz": 0.0}

        if self._time_in_state() >= REPOSITION_DRIVE_TIME:
            self._enter_state("ROTATING_SCAN")
            return {"vx": 0.0, "wz": 0.0}

        return {"vx": FORWARD_SPEED, "wz": 0.0}
    