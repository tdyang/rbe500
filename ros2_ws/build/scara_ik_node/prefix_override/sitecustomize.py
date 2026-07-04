import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/tracy/rbe500/ros2_ws/install/scara_ik_node'
