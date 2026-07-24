import rclpy
from rclpy.node import Node
from sensor_msgs.msg import JointState
from scara_ik.srv import JointToEEVelocity, EEToJointVelocity

A1 = 0.40
A2 = 0.30
SINGULARITY_TOL = 1e-4


def jacobian(theta1, theta2):
    s1, c1 = np.sin(theta1), np.cos(theta1)
    s12, c12 = np.sin(theta1 + theta2), np.cos(theta1 + theta2)
    return np.array([
        [-A1 * s1 - A2 * s12, -A2 * s12, 0.0],
        [ A1 * c1 + A2 * c12,  A2 * c12, 0.0],
        [ 0.0,                 0.0,      1.0]
    ])


class VelocityKinematicsNode(Node):

    def __init__(self):
        super().__init__('velocity_kinematics_node')

        # ── State ─────────────────────────────────────────────────────────────
        self.theta1 = 0.0
        self.theta2 = 0.0

        # ── Subscriber ────────────────────────────────────────────────────────
        self.js_sub = self.create_subscription(
            JointState,
            '/joint_states',
            self.joint_state_cb,
            10
        )

        # ── Services ──────────────────────────────────────────────────────────
        self.fwd_srv = self.create_service(
            JointToEEVelocity,
            '/scara/joint_to_ee_velocity',
            self.fwd_vel_cb
        )
        self.inv_srv = self.create_service(
            EEToJointVelocity,
            '/scara/ee_to_joint_velocity',
            self.inv_vel_cb
        )

        self.get_logger().info(
            'Velocity kinematics node ready.\n'
            '  Call: ros2 service call /scara/joint_to_ee_velocity '
            'scara_ik/srv/JointToEEVelocity "{theta1_dot: 0.1, theta2_dot: 0.0, d3_dot: 0.0}"\n'
            '  Call: ros2 service call /scara/ee_to_joint_velocity '
            'scara_ik/srv/EEToJointVelocity "{vx: 0.0, vy: 0.1, vz: 0.0}"'
        )

    def joint_state_cb(self, msg: JointState):
        if 'joint_1' in msg.name:
            self.theta1 = msg.position[msg.name.index('joint_1')]
        if 'joint_2' in msg.name:
            self.theta2 = msg.position[msg.name.index('joint_2')]

    def fwd_vel_cb(self, request, response):
        """Joint velocities -> end-effector velocity: xdot = Jv * qdot"""
        qdot = np.array([request.theta1_dot, request.theta2_dot, request.d3_dot])
        Jv = jacobian(self.theta1, self.theta2)
        xdot = Jv @ qdot

        response.vx, response.vy, response.vz = xdot.tolist()
        response.success = True
        response.message = 'OK'
        return response

    def inv_vel_cb(self, request, response):
        """End-effector velocity -> joint velocities: qdot = Jv^-1 * xdot"""
        xdot = np.array([request.vx, request.vy, request.vz])
        Jv = jacobian(self.theta1, self.theta2)
        det = np.linalg.det(Jv)

        if abs(det) < SINGULARITY_TOL:
            response.success = False
            response.message = (
                f'Near singular configuration (det(Jv)={det:.6f}, '
                f'theta2={self.theta2:.4f} rad). Refusing to invert.'
            )
            response.theta1_dot, response.theta2_dot, response.d3_dot = 0.0, 0.0, 0.0
            self.get_logger().warn(response.message)
            return response

        qdot = np.linalg.solve(Jv, xdot)
        response.theta1_dot, response.theta2_dot, response.d3_dot = qdot.tolist()
        response.success = True
        response.message = 'OK'
        return response


def main(args=None):
    rclpy.init(args=args)
    node = VelocityKinematicsNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()