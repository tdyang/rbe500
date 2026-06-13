import rclpy
from rclpy.node import Node
from std_msgs.msg import Int64

class NumberSubscriber(Node):
    def __init__(self):
        super().__init__('number_subscriber')
        self.subscription = self.create_subscription(
            Int64,
            'number_topic',
            self.listener_callback,
            10)

    def listener_callback(self, msg):
        number = msg.data
        parity = 'even' if number % 2 == 0 else 'odd'
        self.get_logger().info(
            f'I received {number}. It is an {parity} number.')

def main(args=None):
    rclpy.init(args=args)
    node = NumberSubscriber()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
