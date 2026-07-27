#!/usr/bin/env python3
"""
Velocity controller node for SCARA robot (RBE 500 PA3 Part 3).

Subscribes: /joint_states                (sensor_msgs/JointState) -- velocity feedback
            /scara/jointX_vel_ref        (std_msgs/Float64) x3    -- velocity reference
Publishes:  /scara/jointX_vel_cmd        (std_msgs/Float64) x3    -- effort command

  effort = Kp * v_error + Ki * integral(v_error dt)

PI (not PD) because differentiating an already-noisy velocity signal
amplifies noise badly -- integral action handles steady-state error instead.
"""
import os
import csv
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import JointState
from std_msgs.msg import Float64

JOINT_NAMES = ['joint_1', 'joint_2', 'joint_3']

# Tuned per-joint against each joint's effective inertia (Step 4). joint_2's
# link has ~50x less rotational inertia than joint_1's (izz 0.01 vs 0.5), and
# joint_3's link mass is only 0.1 kg, so the same gains that suit joint_1
# make the other two wildly oversensitive to a step input -- they blow past
# the joint's velocity limit and chatter. Scaling gains down purely by that
# inertia ratio undershoots joint_2 the other way: Part 4's reference for
# joint_2 is not a step but a continuously-decreasing ramp (theta2 must keep
# shrinking to hold a constant +y Cartesian velocity), and gains that were
# stable for a step were too sluggish to track a moving target, leaving a
# persistent lag. joint_2's gains were raised again from that low point
# until the ramp-tracking lag closed without reintroducing chatter.
KP = {'joint_1': 20.0, 'joint_2': 3.0, 'joint_3': 8.0}
KI = {'joint_1': 2.0, 'joint_2': 1.5, 'joint_3': 1.0}

EFFORT_LIMIT = 1000.0
INTEGRAL_LIMIT = 50.0  # anti-windup clamp


class ScaraVelocityControllerNode(Node):

    def __init__(self):
        super().__init__('scara_velocity_controller')

        self.ref_velocity = {j: 0.0 for j in JOINT_NAMES}
        self.cur_velocity = {j: 0.0 for j in JOINT_NAMES}
        self.integral = {j: 0.0 for j in JOINT_NAMES}
        self.prev_time = None

        self.create_subscription(JointState, '/joint_states', self.joint_state_cb, 10)

        self.ref_subs = {
            j: self.create_subscription(
                Float64, f'/scara/{j.replace("_", "")}_vel_ref', self.make_ref_cb(j), 10)
            for j in JOINT_NAMES
        }

        self.cmd_pub = {
            j: self.create_publisher(Float64, f'/scara/{j.replace("_", "")}_effort_cmd', 10)
            for j in JOINT_NAMES
        }

        self.timer = self.create_timer(0.01, self.control_loop)  # 100 Hz

        log_dir = os.path.expanduser('~/rbe500/ros2_ws/src/scara_controller/logs')
        os.makedirs(log_dir, exist_ok=True)
        log_path = os.path.join(log_dir, 'velocity_log.csv')
        self.log_file = open(log_path, 'w', newline='')
        self.log_writer = csv.writer(self.log_file)
        self.log_writer.writerow([
            'time_s',
            'ref_joint1', 'cur_joint1',
            'ref_joint2', 'cur_joint2',
            'ref_joint3', 'cur_joint3',
        ])
        self.start_time = self.get_clock().now()

        self.get_logger().info(
            f'SCARA velocity controller ready. Gains: Kp={KP} Ki={KI}\n'
            '  Test with: ros2 topic pub /scara/joint1_vel_ref '
            'std_msgs/msg/Float64 "{data: 0.2}"'
        )

    def make_ref_cb(self, joint_name):
        def cb(msg):
            self.ref_velocity[joint_name] = msg.data
        return cb

    def joint_state_cb(self, msg: JointState):
        for name, vel in zip(msg.name, msg.velocity):
            if name in self.cur_velocity:
                self.cur_velocity[name] = vel

    def control_loop(self):
        now = self.get_clock().now()
        if self.prev_time is None:
            self.prev_time = now
            return
        dt = (now - self.prev_time).nanoseconds * 1e-9
        if dt <= 0.0:
            return
        self.prev_time = now

        for j in JOINT_NAMES:
            error = self.ref_velocity[j] - self.cur_velocity[j]

            self.integral[j] += error * dt
            self.integral[j] = max(-INTEGRAL_LIMIT, min(INTEGRAL_LIMIT, self.integral[j]))

            effort = KP[j] * error + KI[j] * self.integral[j]
            effort = max(-EFFORT_LIMIT, min(EFFORT_LIMIT, effort))

            msg = Float64()
            msg.data = effort
            self.cmd_pub[j].publish(msg)

        t = (now - self.start_time).nanoseconds * 1e-9
        self.log_writer.writerow([
            t,
            self.ref_velocity['joint_1'], self.cur_velocity['joint_1'],
            self.ref_velocity['joint_2'], self.cur_velocity['joint_2'],
            self.ref_velocity['joint_3'], self.cur_velocity['joint_3'],
        ])
        self.log_file.flush()

    def destroy_node(self):
        self.log_file.close()
        super().destroy_node()


def main(args=None):
    rclpy.init(args=args)
    node = ScaraVelocityControllerNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()