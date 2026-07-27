import rclpy
import numpy as np
from rclpy.node import Node
from sensor_msgs.msg import JointState
from velocity_kinematics.srv import JointToEEVelocity, EEToJointVelocity

A1 = 0.40
A2 = 0.30


def jacobian(theta1, theta2):
    s1, c1 = np.sin(theta1), np.cos(theta1)
    s12, c12 = np.sin(theta1 + theta2), np.cos(theta1 + theta2)
    return np.array([
        [-A1*s1 - A2*s12, -A2*s12, 0],
        [ A1*c1 + A2*c12,  A2*c12, 0],
        [ 0,               0,      1]
    ])


class VelocityKinematicsNode(Node):

    def __init__(self):
        super().__init__('velocity_kinematics_node')
        self.theta1 = 0.0
        self.theta2 = 0.0

        self.create_subscription(JointState, '/joint_states', self.joint_state_cb, 10)
        self.create_service(JointToEEVelocity, '/scara/joint_to_ee_velocity', self.fwd_vel_cb)
        self.create_service(EEToJointVelocity, '/scara/ee_to_joint_velocity', self.inv_vel_cb)

    def joint_state_cb(self, msg):
        if 'joint_1' in msg.name:
            self.theta1 = msg.position[msg.name.index('joint_1')]
        if 'joint_2' in msg.name:
            self.theta2 = msg.position[msg.name.index('joint_2')]

    def fwd_vel_cb(self, request, response):
        qdot = [request.theta1_dot, request.theta2_dot, request.d3_dot]
        vx, vy, vz = jacobian(self.theta1, self.theta2) @ qdot
        response.vx, response.vy, response.vz = vx, vy, vz
        response.success = True
        return response

    def inv_vel_cb(self, request, response):
        xdot = [request.vx, request.vy, request.vz]
        Jv = jacobian(self.theta1, self.theta2)
        try:
            q1, q2, q3 = np.linalg.solve(Jv, xdot)
        except np.linalg.LinAlgError:
            response.theta1_dot, response.theta2_dot, response.d3_dot = 0.0, 0.0, 0.0
            response.success = False
            response.message = (
                f'Singular Jacobian at theta1={self.theta1:.4f}, theta2={self.theta2:.4f} '
                '(theta2 near 0 or pi) -- no unique joint-velocity solution.'
            )
            self.get_logger().warn(response.message)
            return response
        response.theta1_dot, response.theta2_dot, response.d3_dot = q1, q2, q3
        response.success = True
        return response


def main(args=None):
    rclpy.init(args=args)
    node = VelocityKinematicsNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
