#!/usr/bin/env python3
"""
Forward Kinematics node for SCARA robot (RBE 500 PA1 Part 2).

SCARA DH parameters (from lecture notes):
  l1  = 0.45 m  — vertical height of joint 1 above base
  a1  = 0.40 m  — length of arm_1  (link between joint 1 and joint 2)
  a2  = 0.30 m  — length of link_2 (link between joint 2 and joint 3)
  d3  — prismatic displacement along z (joint_3, range -0.20 to +0.20 m)

FK closed-form result (T3_0 from Lecture 2 slides):
  c12 = cos(θ1 + θ2),  s12 = sin(θ1 + θ2)
  c1  = cos(θ1),       s1  = sin(θ1)

  px  = -a2*s12 - a1*s1      (T[0,3])
  py  =  a2*c12 + a1*c1      (T[1,3])
  pz  =  l1 - d3             (T[2,3])

  Orientation = rotation about z by (θ1 + θ2)
"""

import math
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import JointState
from geometry_msgs.msg import Pose

# ── Robot constants (metres) ──────────────────────────────────────────────────
L1 = 0.45   # column height (z-offset of joint_1 from world origin)
A1 = 0.40   # arm_1 length
A2 = 0.30   # link_2 length


class ScaraFKNode(Node):
    def __init__(self):
        super().__init__('scara_fk_node')

        self.sub = self.create_subscription(
            JointState,
            '/joint_states',
            self.joint_state_callback,
            10)

        self.pub = self.create_publisher(Pose, '/scara/ee_pose', 10)

        self.get_logger().info('SCARA FK node started — listening on /joint_states')

    @staticmethod
    def _get_joint(msg: JointState, name: str) -> float:
        if name in msg.name:
            return msg.position[msg.name.index(name)]
        return 0.0

    def joint_state_callback(self, msg: JointState):
        theta1 = self._get_joint(msg, 'joint_1')   # revolute (rad)
        theta2 = self._get_joint(msg, 'joint_2')   # revolute (rad)
        d3     = self._get_joint(msg, 'joint_3')   # prismatic (m)

        # ── FK (Lecture 2, T3_0 closed-form) ─────────────────────────────────
        c1  = math.cos(theta1)
        s1  = math.sin(theta1)
        c12 = math.cos(theta1 + theta2)
        s12 = math.sin(theta1 + theta2)

        px = -A2 * s12 - A1 * s1
        py =  A2 * c12 + A1 * c1
        pz =  L1 - d3

        # Pure rotation about z by (θ1 + θ2) → quaternion
        half = (theta1 + theta2) / 2.0
        qw = math.cos(half)
        qz = math.sin(half)

        # ── Publish ───────────────────────────────────────────────────────────
        pose = Pose()
        pose.position.x    = px
        pose.position.y    = py
        pose.position.z    = pz
        pose.orientation.x = 0.0
        pose.orientation.y = 0.0
        pose.orientation.z = qz
        pose.orientation.w = qw
        self.pub.publish(pose)

        self.get_logger().info(
            f'FK | θ1={math.degrees(theta1):.2f}° θ2={math.degrees(theta2):.2f}° '
            f'd3={d3:.4f}m → pos=({px:.4f}, {py:.4f}, {pz:.4f}) '
            f'quat=(0, 0, {qz:.4f}, {qw:.4f})'
        )


def main(args=None):
    rclpy.init(args=args)
    node = ScaraFKNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()