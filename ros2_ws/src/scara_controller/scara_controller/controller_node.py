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

import os
import csv

# ── PD Gains ──────────────────────────────────────────────────────────────────
JOINT_NAMES = ['joint_1', 'joint_2', 'joint_3']
KP = {'joint_1': 50.0, 'joint_2': 50.0, 'joint_3': 800.0}
KD = {'joint_1': 5.0, 'joint_2': 5.0, 'joint_3': 80.0}

# ── Joint limits ──────────────────────────────────────────────────────────────
J3_MIN = {'joint_1': -1.57, 'joint_2': -1.57, 'joint_3': -0.20}
J3_MAX = {'joint_1': 1.57, 'joint_2': 1.57, 'joint_3': 0.20}
EFFORT_LIMIT = 1000.0


class ScaraControllerNode(Node):

    def __init__(self):
        super().__init__('scara_controller')

        # ── State ─────────────────────────────────────────────────────────────
        self.ref_position = {j: 0.0 for j in JOINT_NAMES}
        self.cur_position = {j: 0.0 for j in JOINT_NAMES}
        self.prev_error = {j: 0.0 for j in JOINT_NAMES}
        self.prev_time    = None

        # ── Subscriber ────────────────────────────────────────────────────────
        self.js_sub = self.create_subscription(
            JointState,
            '/joint_states',
            self.joint_state_cb,
            10
        )

        # ── Publisher ─────────────────────────────────────────────────────────
        self.cmd_pub = {
            j: self.create_publisher(Float64, f'/scara/{j.replace("_","")}_cmd', 10)
            for j in JOINT_NAMES
        }

        # ── Service ───────────────────────────────────────────────────────────
        self.srv = {
            j: self.create_service(
                SetJointPosition,
                f'/scara/set_{j.replace("_"),"")}_position',
                self.make_set_position_cb(j)
            )
            for j in JOINT_NAMES
        }

        # ── Control loop at 100 Hz ────────────────────────────────────────────
        self.timer = self.create_timer(0.01, self.control_loop)

        self.get_logger().info(
            f'SCARA controller ready. Gains: Kp={KP}  Kd={KD}\n'
            '  Call: ros2 service call /scara/set_joint3_position '
            'scara_ik/srv/SetJointPosition "{position: 0.1}"'
        )

        # ── CSV logging setup ─────────────────────────────────────────────────
        log_dir = os.path.expanduser('~/ros2_ws/src/scara_controller/logs')
        os.makedirs(log_dir, exist_ok = True)
        log_path = os.path.join(
          log_dir, 'joint3_log.csv')
        self.log_file = open(log_path, 'w', newline = '')
        self.log_writer = csv.writer(self.log_file)
        self.log_writer.writerow([
            'time_s', 
            'ref_joint1', 'cur_joint1',
            'ref_joint2', 'cur_joint2',
            'ref_joint3', 'cur_joint3'
        ])
        self.start_time = self.get_clock().now()
        self.get_logger().info(f'Part 2d: logging joint3 data to {log_path}')


    def joint_state_cb(self, msg: JointState):
        for name, val in zip(msg.name, msg.position):
            if name in self.cur_position:
                self.cur_position[name] = val
              
  def make_set_position_cb(self, joint_name):
    """Returns a service callback bound to a specific joint."""
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
      return set_position_cb

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
        for j in JOINT_NAMES:
          error     = self.ref_position[j] - self.cur_position[j]
          error_dot = (error - self.prev_error[j]) / dt
          self.prev_error[j] = error
  
          effort = KP[j] * error + KD[j] * error_dot
          effort = max(-EFFORT_LIMIT, min(EFFORT_LIMIT, effort))
  
          msg = Float64()
          msg.data = effort
          self.cmd_pub[j].publish(msg)
  
          self.get_logger().debug(
              f'{j} | ref={self.ref_position[j]:.4f}  cur={self.cur_position[j]:.4f}  '
              f'err={error:.4f}  effort={effort:.2f}'
          )

        # ── Log control cycle ─────────────────────────────────────────────────
        t_elapsed = (now - self.start_time).nanoseconds * 1e-9
        self.log_writer.writerow([
            t_elapsed,
            self.ref_position['joint_1'], self.cur_position['joint_1'],
            self.ref_position['joint_2'], self.cur_position['joint_2'],
            self.ref_position['joint_3'], self.cur_position['joint_3']
        ])
        self.log_file.flush()

    # ── Close log file on shutdown ────────────────────────────────────────────
    def destroy_node(self):
        self.log_file.close()
        super().destroy_node()

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
