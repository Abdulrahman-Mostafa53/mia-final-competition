import rclpy
from rclpy.node import Node 
from geometry_msgs.msg import Twist
from pynput import keyboard


class MovmentNode(Node):
    def __init__(self):
        super().__init__('Movment_node')

        self.pub=self.create_publisher(
            Twist,
            '/cmd_vel',
            10
        )
    
        self.linear_vel= 2.0 
        self.angular_vel=2.0 
        self.increase_speed = 0.5
        self.min_speed=0.5
        self.max_speed=5.0

        self.keys= set() ##store key state

        self.listener= keyboard.Listener(  ## show state of key
            on_press= self.key_pressed,
            on_release = self.key_released
        )
        self.listener.start()
        self.timer = self.create_timer( ## keep button state 
            0.05,
            self.move
        )
    def key_pressed(self,key):
        try:
            key=key.char.lower() # covert char  to lower case 
            self.keys.add(key) #store key in thhe pressed keys
        except AttributeError:
            if key ==keyboard.key.up:
                self.speed +=self.increase_speed

                if self.speed>self.max_speed:
                    self.speed= self.max_speed
                self.get_logger().info(f"speed : {self.speed}")
            elif key==keyboard.key.down:
                self.linear_vel -= self.increase_speed
                if self.linear_vel < self.min_speed:
                    self.linear_vel=self.min_speed
                self.get_logger().info(f"speed : {self.seed}")

            elif key == keyboard.key.space:
                self.keys.clear()
                self.pub_vel(
                    0.0,
                    0.0
                )
    def key_released(self,key):
        try:
            key= key.char.lower()
            self.keys.discard(key)
        except AttributeError:
            pass

        if key ==keyboard.keyCode.from_char('q'):
            self.keys.clear()
            self.pub_vel(
                0.0,
                0.0
            )
            self.get_logger().info("exiting...")
            rclpy.shutdown()


    def pub_vel(self,linear,angular):
            
            msg=Twist()
            msg.linear.x=float(linear)
            msg.angular.z=float(angular)
            self.pub.publish(msg)

            self.get_logger().info("use W, A, S, D , up , down to control the robot ")


    def run_loop(self):

        while rclpy.ok():
            twist=Twist()
            if 'w' in self.keys: ## forward
                 linear=self.linear_vel
            elif 's' in self.keys: ##backward
                linear= -self.linear_vel
            elif 'a' in self.keys: ## yaw left
                angular = self.angular_vel
            elif 'd' in self.keys: ## turn right
               angular= - self.angular_vel

            self.pub_vel(
                linear,
                angular
            )

    def stop(self):
        self,self.pub_vel(
            0.0,
            0.0
        )

        
def main():
    rclpy.init() # start ros communication 
    node=MovmentNode()
    try:
        node.run_loop()
    except KeyboardInterrupt:
        pass
    finally:
       node.stop()
       node.listener.stop()
       node.destroy_node()
       rclpy.shutdown()

if __name__ == '__main__':
    main()

