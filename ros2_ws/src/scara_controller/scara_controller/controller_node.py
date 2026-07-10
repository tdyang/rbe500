#!/usr/bin/env python3
"""
Position controller node for SCARA robot (RBE 500 PA2 Part 2a/2b).

Subscribes: /joint_states  (sensor_msgs/JointState)  — from gz bridge
Publishes:  /scara/joint3_cmd  (std_msgs/Float64)  — effort command to Gazebo
Service:    /scara/set_joint3_position  (scara_ik/SetJointPosition)

PD controller implemented here. The Gazebo JointPositionController plugin
is set to p=1, i=0, d=0 so it acts as a direct pass-through, applying
whatever value this node publishes directly as joint effort.

  effort = Kp * error + Kd * d(error)/dt
"""

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import JointState
from std_msgs.msg import Float64
from scara_ik.srv import SetJointPosition

# ── PD Gains ──────────────────────────────────────────────────────────────────
KP = 800.0    # proportional gain  [N/m]
KD = 80.0     # derivative gain    [N·s/m]

# ── Joint limits ──────────────────────────────────────────────────────────────
J3_MIN = -0.20
J3_MAX =  0.20
EFFORT_LIMIT = 1000.0


class ScaraControllerNode(Node):

    def __init__(self):
        super().__init__('scara_controller')

        # ── State ─────────────────────────────────────────────────────────────
        self.ref_position = 0.0
        self.cur_position = 0.0
        self.prev_error   = 0.0
        self.prev_time    = None

        # ── Subscriber ────────────────────────────────────────────────────────
        self.js_sub = self.create_subscription(
            JointState,
            '/joint_states',
            self.joint_state_cb,
            10
        )

        # ── Publisher ─────────────────────────────────────────────────────────
        self.cmd_pub = self.create_publisher(
            Float64,
            '/scara/joint3_cmd',
            10
        )

        # ── Service ───────────────────────────────────────────────────────────
        self.srv = self.create_service(
            SetJointPosition,
            '/scara/set_joint3_position',
            self.set_position_cb
        )

        # ── Control loop at 100 Hz ────────────────────────────────────────────
        self.timer = self.create_timer(0.01, self.control_loop)

        self.get_logger().info(
            f'SCARA controller ready. Gains: Kp={KP}  Kd={KD}\n'
            '  Call: ros2 service call /scara/set_joint3_position '
            'scara_ik/srv/SetJointPosition "{position: 0.1}"'
        )

    def joint_state_cb(self, msg: JointState):
        if 'joint_3' in msg.name:
            idx = msg.name.index('joint_3')
            self.cur_position = msg.position[idx]

    def set_position_cb(self, request, response):
        target = request.position

        if not (J3_MIN <= target <= J3_MAX):
            response.success = False
            response.message = (
                f'Requested {target:.4f} m outside limits [{J3_MIN}, {J3_MAX}] m.'
            )
            self.get_logger().warn(response.message)
            return response

        self.ref_position = target
        response.success = True
        response.message = f'Reference position set to {target:.4f} m'
        self.get_logger().info(response.message)
        return response

    def control_loop(self):
        """PD control law at 100 Hz."""
        now = self.get_clock().now()

        if self.prev_time is None:
            self.prev_time = now
            return

        dt = (now - self.prev_time).nanoseconds * 1e-9
        if dt <= 0.0:
            return
        self.prev_time = now

        # PD law
        error     = self.ref_position - self.cur_position
        error_dot = (error - self.prev_error) / dt
        self.prev_error = error

        effort = KP * error + KD * error_dot
        effort = max(-EFFORT_LIMIT, min(EFFORT_LIMIT, effort))

        msg = Float64()
        msg.data = effort
        self.cmd_pub.publish(msg)

        self.get_logger().debug(
            f'PD | ref={self.ref_position:.4f}  cur={self.cur_position:.4f}  '
            f'err={error:.4f}  effort={effort:.2f}'
        )


def main(args=None):
    rclpy.init(args=args)
    node = ScaraControllerNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()