import rclpy
from rclpy.node import Node
from std_msgs.msg import Int64

class NumberPublisher(Node):
    def __init__(self):
        super().__init__('number_publisher')
        self.publisher_ = self.create_publisher(Int64, 'number_topic', 10)
        self.timer = self.create_timer(1.0, self.timer_callback)
        self.count = 1

    def timer_callback(self):
        msg = Int64()
        msg.data = self.count
        self.publisher_.publish(msg)
        self.get_logger().info(f'Publishing: {self.count}')
        self.count += 1

def main(args=None):
    rclpy.init(args=args)
    node = NumberPublisher()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
