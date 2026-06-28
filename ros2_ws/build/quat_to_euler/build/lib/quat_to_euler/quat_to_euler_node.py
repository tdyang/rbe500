import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32MultiArray
import math

class QuatToEulerNode(Node):
    def __init__(self):
        super().__init__('quat_to_euler')
        self.subscription = self.create_subscription(
            Float32MultiArray,
            'quaternion',
            self.listener_callback,
            10)
        self.get_logger().info('Quaternion to Euler node started.')
        self.get_logger().info('Waiting for quaternion input [w, x, y, z]...')

    def listener_callback(self, msg):
        if len(msg.data) != 4:
            self.get_logger().error(
                f'Expected 4 values [w, x, y, z], got {len(msg.data)}')
            return

        w, x, y, z = msg.data

        # Validate it's a unit quaternion
        norm = math.sqrt(w**2 + x**2 + y**2 + z**2)
        if abs(norm - 1.0) > 0.01:
            self.get_logger().warn(
                f'Quaternion norm is {norm:.4f}, expected 1.0. '
                f'Results may be inaccurate.')

        # Conversion formulas (ZYX convention, from Wikipedia)
        # Roll (phi) - rotation about x
        sinr_cosp = 2.0 * (w * x + y * z)
        cosr_cosp = 1.0 - 2.0 * (x * x + y * y)
        phi = math.atan2(sinr_cosp, cosr_cosp)

        # Pitch (theta) - rotation about y
        sinp = 2.0 * (w * y - z * x)
        if abs(sinp) >= 1.0:
            # Gimbal lock: use 90 degrees
            theta = math.copysign(math.pi / 2, sinp)
        else:
            theta = math.asin(sinp)

        # Yaw (psi) - rotation about z
        siny_cosp = 2.0 * (w * z + x * y)
        cosy_cosp = 1.0 - 2.0 * (y * y + z * z)
        psi = math.atan2(siny_cosp, cosy_cosp)

        # Convert to degrees for readability
        phi_deg   = math.degrees(phi)
        theta_deg = math.degrees(theta)
        psi_deg   = math.degrees(psi)

        self.get_logger().info(
            f'\nReceived quaternion: w={w}, x={x}, y={y}, z={z}\n'
            f'  Roll  (phi)   = {phi:.4f} rad = {phi_deg:.2f} deg\n'
            f'  Pitch (theta) = {theta:.4f} rad = {theta_deg:.2f} deg\n'
            f'  Yaw   (psi)   = {psi:.4f} rad = {psi_deg:.2f} deg')

def main(args=None):
    rclpy.init(args=args)
    node = QuatToEulerNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
