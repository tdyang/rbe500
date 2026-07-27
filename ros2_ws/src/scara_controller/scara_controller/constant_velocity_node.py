#!/usr/bin/env python3
"""
Constant Cartesian velocity reference node for SCARA robot (RBE 500 PA3 Part 4).

Calls /scara/ee_to_joint_velocity (velocity_kinematics/srv/EEToJointVelocity)
on a timer with a constant end-effector velocity in +y, and republishes the
resulting joint rates on /scara/jointX_vel_ref for the Part 3 velocity
controllers to track.

The Jacobian depends on the current joint configuration (see vk_node.py),
so the inverse velocity solve is repeated every cycle rather than computed
once -- as the robot moves along +y, the joint-space reference changes to
keep the end effector on a straight line.
"""
import rclpy
from rclpy.node import Node
from std_msgs.msg import Float64
from velocity_kinematics.srv import EEToJointVelocity

JOINT_NAMES = ['joint_1', 'joint_2', 'joint_3']
VY = 0.05  # m/s, constant end-effector velocity in +y


class ConstantVelocityNode(Node):

    def __init__(self):
        super().__init__('constant_velocity_node')

        self.cli = self.create_client(EEToJointVelocity, '/scara/ee_to_joint_velocity')
        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Waiting for /scara/ee_to_joint_velocity...')

        self.ref_pub = {
            j: self.create_publisher(Float64, f'/scara/{j.replace("_","")}_vel_ref', 10)
            for j in JOINT_NAMES
        }

        self.pending = False
        self.timer = self.create_timer(0.05, self.timer_cb)  # 20 Hz

        self.get_logger().info(
            f'Publishing constant EE velocity vy={VY} m/s -> joint vel refs'
        )

    def timer_cb(self):
        if self.pending:
            return  # previous request still in flight
        req = EEToJointVelocity.Request()
        req.vx = 0.0
        req.vy = VY
        req.vz = 0.0
        self.pending = True
        future = self.cli.call_async(req)
        future.add_done_callback(self.response_cb)

    def response_cb(self, future):
        self.pending = False
        try:
            resp = future.result()
        except Exception as e:
            self.get_logger().warn(f'Service call failed: {e}')
            return

        if not resp.success:
            self.get_logger().warn('Inverse velocity solve failed (near singularity?)')
            return

        qdot = {
            'joint_1': resp.theta1_dot,
            'joint_2': resp.theta2_dot,
            'joint_3': resp.d3_dot,
        }
        for j in JOINT_NAMES:
            msg = Float64()
            msg.data = qdot[j]
            self.ref_pub[j].publish(msg)

    def destroy_node(self):
        for j in JOINT_NAMES:
            self.ref_pub[j].publish(Float64(data=0.0))
        super().destroy_node()


def main(args=None):
    rclpy.init(args=args)
    node = ConstantVelocityNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
