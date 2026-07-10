#!/usr/bin/env python3
"""
Inverse Kinematics service node for SCARA robot (RBE 500 PA1 Part 3).

Service:  /scara/compute_ik  (scara_ik/srv/ScaraIK)
  Request:  x, y, z   — desired EE position in base frame
  Response: theta1, theta2, d3, success, message

IK derivation:
  From FK:
    px = -a2*s12 - a1*s1
    py =  a2*c12 + a1*c1
    pz =  l1 - d3

  Step 1 — d3 directly from pz:
    d3 = l1 - pz

  Step 2 — θ2 via law of cosines (same as 2-link planar):
    r² = px² + py²
    cos(θ2) = (r² - a1² - a2²) / (2*a1*a2)    → θ2 = atan2(±√(1-c2²), c2)
    (elbow-up solution: positive √)

  Step 3 — θ1 algebraically:
    k1 = a1 + a2*cos(θ2)
    k2 = a2*sin(θ2)

    Note: px = -(a1*s1 + a2*s12) and py = a1*c1 + a2*c12
    Substituting and rearranging:
      py = k1*c1 - k2*s1
      px = -(k1*s1 + k2*c1)   → px = -k1*s1 - k2*c1

    Solving the 2×2 linear system:
      θ1 = atan2(-px*k1 - py*k2,  py*k1 - px*k2)
           (derived by multiplying and summing to isolate s1, c1)
"""

import math
import rclpy
from rclpy.node import Node
from scara_ik.srv import ScaraIK

# ── Robot constants (metres) ──────────────────────────────────────────────────
L1 = 0.45
A1 = 0.40
A2 = 0.30
D3_MIN = -0.20
D3_MAX =  0.20


class ScaraIKNode(Node):
    def __init__(self):
        super().__init__('scara_ik_node')

        self.srv = self.create_service(ScaraIK, '/scara/compute_ik', self.ik_callback)
        self.get_logger().info('SCARA IK service ready at /scara/compute_ik')

    def ik_callback(self, request, response):
        px = request.x
        py = request.y
        pz = request.z

        self.get_logger().info(f'IK request → ({px:.4f}, {py:.4f}, {pz:.4f})')

        # ── Step 1: d3 ────────────────────────────────────────────────────────
        d3 = L1 - pz

        if not (D3_MIN <= d3 <= D3_MAX):
            response.success = False
            response.message = (
                f'z={pz:.4f} out of reachable range. '
                f'd3={d3:.4f} must be in [{D3_MIN}, {D3_MAX}].'
            )
            self.get_logger().warn(response.message)
            return response

        # ── Step 2: θ2 via law of cosines ────────────────────────────────────
        r_sq = px**2 + py**2
        c2   = (r_sq - A1**2 - A2**2) / (2.0 * A1 * A2)

        if abs(c2) > 1.0:
            response.success = False
            response.message = (
                f'Position ({px:.4f}, {py:.4f}) is outside the planar workspace. '
                f'cos(θ2)={c2:.4f} — no real solution.'
            )
            self.get_logger().warn(response.message)
            return response

        # Elbow-up solution (positive sine)
        s2     = math.sqrt(1.0 - c2**2)
        theta2 = math.atan2(s2, c2)

        # ── Step 3: θ1 algebraically ─────────────────────────────────────────
        k1 = A1 + A2 * c2
        k2 = A2 * s2

        # From py =  k1*c1 - k2*s1
        #      px = -k1*s1 - k2*c1
        # Multiply first eq by k1, second by -k2 and add → c1*(k1²+k2²) = py*k1 - px*k2
        # Multiply first eq by k2, second by  k1 and add → s1*(k1²+k2²) = -px*k1 - py*k2
        theta1 = math.atan2(-px * k1 - py * k2,
                             py * k1 - px * k2)

        response.theta1  = theta1
        response.theta2  = theta2
        response.d3      = d3
        response.success = True
        response.message = (
            f'IK solved (elbow-up): '
            f'θ1={math.degrees(theta1):.2f}°  '
            f'θ2={math.degrees(theta2):.2f}°  '
            f'd3={d3:.4f} m'
        )

        self.get_logger().info(response.message)
        return response


def main(args=None):
    rclpy.init(args=args)
    node = ScaraIKNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()