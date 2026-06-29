import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32MultiArray
from geometry_msgs.msg import Pose
import numpy as np

class FKNode(Node):
    def __init__(self):
        super().__init__('irb1400_fk')

        # ---- Robot DH parameters (mm) ----
        self.d1 = 475;  self.a1 = 150
        self.a2 = 600;  self.a3 = 120
        self.d4 = 720;  self.d6 = 85

        # ---- Subscriber 1 (HW3): forward kinematics ----
        self.fk_sub = self.create_subscription(
            Float32MultiArray,
            'joint_angles',
            self.fk_callback,
            10)

        # ---- Subscriber 2 (HW4): inverse kinematics ----
        self.ik_sub = self.create_subscription(
            Pose,
            'ee_pose',
            self.ik_callback,
            10)

        self.get_logger().info('IRB1400 FK+IK node started.')
        self.get_logger().info(
            '  Pub /joint_angles (Float32MultiArray) for FK.')
        self.get_logger().info(
            '  Pub /ee_pose (Pose) for IK.')

    # ============================================================ #
    # DH / FK helpers (unchanged from HW3)
    # ============================================================ #
    def dh_matrix(self, theta_deg, d, a, alpha_deg):
        """Standard DH 4x4 matrix. theta, alpha in degrees; d, a in mm."""
        th = np.radians(theta_deg)
        al = np.radians(alpha_deg)
        ct, st = np.cos(th), np.sin(th)
        ca, sa = np.cos(al), np.sin(al)
        return np.array([
            [ct, -st*ca,  st*sa, a*ct],
            [st,  ct*ca, -ct*sa, a*st],
            [ 0,     sa,     ca,    d],
            [ 0,      0,      0,    1]
        ])

    def fk(self, q_deg):
        """
        Forward kinematics for ABB IRB1400.
        Input:  q_deg -- [q1..q6] in degrees
        Output: 4x4 homogeneous transform H = T6^0
        """
        d1,a1 = self.d1, self.a1
        a2,a3 = self.a2, self.a3
        d4,d6 = self.d4, self.d6
        q = q_deg
        # DH table with joint offsets on joints 2 and 4
        params = [
            (q[0],        d1, a1,  90),
            (q[1] + 90,    0, a2,   0),
            (q[2],         0, a3,  90),
            (q[3] + 90,   d4,  0,  90),
            (q[4],         0,  0, -90),
            (q[5],        d6,  0,   0),
        ]
        T = np.eye(4)
        for th, d, a, al in params:
            T = T @ self.dh_matrix(th, d, a, al)
        return T

    def fk_partial(self, q_deg, n):
        """FK through first n joints only."""
        d1,a1 = self.d1, self.a1
        a2,a3 = self.a2, self.a3
        d4,d6 = self.d4, self.d6
        q = q_deg
        params = [
            (q[0],        d1, a1,  90),
            (q[1] + 90,    0, a2,   0),
            (q[2],         0, a3,  90),
            (q[3] + 90,   d4,  0,  90),
            (q[4],         0,  0, -90),
            (q[5],        d6,  0,   0),
        ]
        T = np.eye(4)
        for i in range(n):
            T = T @ self.dh_matrix(*params[i])
        return T

    # ============================================================ #
    # Inverse kinematics
    # ============================================================ #
    def ik(self, H):
        """
        Inverse kinematics for ABB IRB1400 using kinematic decoupling.
        Input:  H -- 4x4 desired end-effector pose
        Output: q -- [q1..q6] in degrees, or None if unreachable
        """
        d1,a1 = self.d1, self.a1
        a2,a3 = self.a2, self.a3
        d4,d6 = self.d4, self.d6

        p_ee = H[:3, 3]          # end-effector position
        R_ee = H[:3, :3]         # end-effector rotation

        # --- Step 1: Wrist center ---
        # p_w = p_ee - d6 * z6, where z6 = 3rd column of R_ee
        z6   = R_ee[:, 2]
        p_w  = p_ee - d6 * z6
        wx, wy, wz = p_w

        # --- Step 2: q1 (base rotation) ---
        q1 = np.degrees(np.arctan2(wy, wx))

        # --- Step 3: q2, q3 (arm plane geometry) ---
        r   = np.sqrt(wx**2 + wy**2) - a1   # horizontal reach
        h   = wz - d1                         # vertical reach
        L   = np.sqrt(a3**2 + d4**2)          # effective elbow link
        phi = np.degrees(np.arctan2(d4, a3))  # internal elbow angle
        D   = np.sqrt(r**2 + h**2)            # shoulder-to-wrist distance

        # Law of cosines
        cos_C = (D**2 - a2**2 - L**2) / (2 * a2 * L)
        if abs(cos_C) > 1.0:
            self.get_logger().error('IK: target out of reach!')
            return None
        C = np.degrees(np.arccos(cos_C))

        q3 = -(C - phi)
        gamma = np.degrees(np.arctan2(h, r))
        delta = np.degrees(np.arctan2(
            L * np.sin(np.radians(C)),
            a2 + L * np.cos(np.radians(C))))
        q2 = gamma + delta - 90.0             # account for DH offset

        # --- Step 4: Wrist angles (ZYZ decomposition) ---
        R03 = self.fk_partial([q1, q2, q3, 0, 0, 0], 3)[:3, :3]
        R36 = R03.T @ R_ee                    # wrist rotation matrix

        r13, r23, r33 = R36[0,2], R36[1,2], R36[2,2]
        r31, r32      = R36[2,0], R36[2,1]

        # ZYZ Euler extraction (with sign from wrist convention)
        q5_rad = -np.arctan2(np.sqrt(r13**2 + r23**2), r33)
        if abs(np.sin(q5_rad)) > 1e-6:
            q4_rad = np.arctan2(r23, r13) - np.pi / 2
            q6_rad = np.arctan2(r32, -r31)
        else:
            # Gimbal lock: set q4=0, solve for q6
            self.get_logger().warn('IK: gimbal lock detected, q4 set to 0.')
            q4_rad = 0.0
            q6_rad = np.arctan2(-R36[0,1], R36[0,0])

        q4 = np.degrees(q4_rad)
        q5 = np.degrees(q5_rad)
        q6 = np.degrees(q6_rad)

        return [q1, q2, q3, q4, q5, q6]

    # ============================================================ #
    # Callback: forward kinematics (HW3, unchanged)
    # ============================================================ #
    def fk_callback(self, msg):
        """Receive joint angles, compute FK, print pose."""
        if len(msg.data) != 6:
            self.get_logger().error(
                f'FK: expected 6 values, got {len(msg.data)}')
            return
        q = list(msg.data)
        H = self.fk(q)
        pos = H[:3, 3];  R = H[:3, :3]
        self.get_logger().info(
            f'\n[FK] joints (deg): {[round(qi,2) for qi in q]}\n'
            f'  Position (mm): x={pos[0]:.2f}  y={pos[1]:.2f}  z={pos[2]:.2f}\n'
            f'  Rotation:\n'
            f'    [{R[0,0]:7.4f}  {R[0,1]:7.4f}  {R[0,2]:7.4f}]\n'
            f'    [{R[1,0]:7.4f}  {R[1,1]:7.4f}  {R[1,2]:7.4f}]\n'
            f'    [{R[2,0]:7.4f}  {R[2,1]:7.4f}  {R[2,2]:7.4f}]')

    # ============================================================ #
    # Callback: inverse kinematics (HW4, new)
    # ============================================================ #
    def ik_callback(self, msg):
        """
        Receive a Pose message, convert to H matrix,
        solve IK, and print joint angles.
        """
        # Extract position
        px = msg.position.x
        py = msg.position.y
        pz = msg.position.z

        # Extract quaternion orientation
        qx = msg.orientation.x
        qy = msg.orientation.y
        qz = msg.orientation.z
        qw = msg.orientation.w

        # Convert quaternion to rotation matrix
        R = self.quat_to_rot(qw, qx, qy, qz)

        # Build 4x4 homogeneous transformation
        H = np.eye(4)
        H[:3, :3] = R
        H[:3,  3] = [px, py, pz]

        self.get_logger().info(
            f'\n[IK] Received pose: pos=({px:.2f},{py:.2f},{pz:.2f})')

        # Solve IK
        q = self.ik(H)
        if q is None:
            return

        self.get_logger().info(
            f'[IK] Joint angles (deg):\n'
            f'  q1={q[0]:.4f}  q2={q[1]:.4f}  q3={q[2]:.4f}\n'
            f'  q4={q[3]:.4f}  q5={q[4]:.4f}  q6={q[5]:.4f}')

        # Verify by running FK with the IK result
        H_check = self.fk(q)
        pos_err = np.linalg.norm(H_check[:3,3] - H[:3,3])
        self.get_logger().info(
            f'[IK] Verification FK position: '
            f'({H_check[0,3]:.2f}, {H_check[1,3]:.2f}, {H_check[2,3]:.2f}) mm'
            f'  |error|={pos_err:.4f} mm')

    def quat_to_rot(self, w, x, y, z):
        """Convert unit quaternion (w,x,y,z) to 3x3 rotation matrix."""
        return np.array([
            [1-2*(y*y+z*z),  2*(x*y-w*z),  2*(x*z+w*y)],
            [2*(x*y+w*z),  1-2*(x*x+z*z),  2*(y*z-w*x)],
            [2*(x*z-w*y),    2*(y*z+w*x),  1-2*(x*x+y*y)]
        ])

# ---------------------------------------------------------------- #
def main(args=None):
    rclpy.init(args=args)
    node = FKNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()