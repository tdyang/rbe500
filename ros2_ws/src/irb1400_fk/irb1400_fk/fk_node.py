import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32MultiArray
import numpy as np

class FKNode(Node):
    def __init__(self):
        super().__init__('irb1400_fk')

        # Subscribe to /joint_angles (Float32MultiArray: [q1..q6] in degrees)
        self.subscription = self.create_subscription(
            Float32MultiArray,
            'joint_angles',
            self.listener_callback,
            10)

        self.get_logger().info('IRB1400 FK node started.')
        self.get_logger().info(
            'Waiting for joint angles [q1..q6] in degrees...')

    # ------------------------------------------------------------------ #
    def dh_matrix(self, theta_deg, d, a, alpha_deg):
        """
        Compute the standard DH transformation matrix.
        Parameters: theta, alpha in degrees; d, a in mm.
        """
        theta = np.radians(theta_deg)
        alpha = np.radians(alpha_deg)
        ct, st = np.cos(theta), np.sin(theta)
        ca, sa = np.cos(alpha), np.sin(alpha)
        return np.array([
            [ct, -st*ca,  st*sa, a*ct],
            [st,  ct*ca, -ct*sa, a*st],
            [ 0,     sa,     ca,    d],
            [ 0,      0,      0,    1]
        ])

    # ------------------------------------------------------------------ #
    def forward_kinematics(self, q):
        """
        Compute FK for the ABB IRB1400 using standard DH convention.
        Input:  q   -- list of 6 joint angles in degrees
        Output: 4x4 homogeneous transformation matrix H = T6^0
        """
        # DH table: (theta_i, d_i mm, a_i mm, alpha_i deg)
        dh_params = [
            (q[0], 475, 150,  90),  # Joint 1: base yaw
            (q[1],   0, 600,   0),  # Joint 2: shoulder pitch
            (q[2],   0, 120,  90),  # Joint 3: elbow pitch
            (q[3], 720,   0, -90),  # Joint 4: wrist roll
            (q[4],   0,   0,  90),  # Joint 5: wrist pitch
            (q[5], 255,   0,   0),  # Joint 6: wrist yaw + EE
        ]
        T = np.eye(4)
        for theta, d, a, alpha in dh_params:
            T = T @ self.dh_matrix(theta, d, a, alpha)
        return T

    # ------------------------------------------------------------------ #
    def listener_callback(self, msg):
        """Receive joint angles, compute FK, and print result."""
        # Validate message length
        if len(msg.data) != 6:
            self.get_logger().error(
                f'Expected 6 joint angles, got {len(msg.data)}')
            return

        q = list(msg.data)

        # Compute forward kinematics
        H = self.forward_kinematics(q)

        # Extract position vector (mm) and rotation matrix
        pos = H[:3, 3]
        R   = H[:3, :3]

        # Print end-effector pose to terminal
        self.get_logger().info(
            f'\nReceived joints (deg): {[round(qi,2) for qi in q]}\n'
            f'  Position (mm):\n'
            f'    x = {pos[0]:.2f}\n'
            f'    y = {pos[1]:.2f}\n'
            f'    z = {pos[2]:.2f}\n'
            f'  Rotation matrix R_6^0:\n'
            f'    [{R[0,0]:7.4f}  {R[0,1]:7.4f}  {R[0,2]:7.4f}]\n'
            f'    [{R[1,0]:7.4f}  {R[1,1]:7.4f}  {R[1,2]:7.4f}]\n'
            f'    [{R[2,0]:7.4f}  {R[2,1]:7.4f}  {R[2,2]:7.4f}]'
        )

# ---------------------------------------------------------------------- #
def main(args=None):
    rclpy.init(args=args)
    node = FKNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()