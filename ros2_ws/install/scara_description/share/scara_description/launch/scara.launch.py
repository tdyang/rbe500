import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import TimerAction, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.actions import Node


def generate_launch_description():
    pkg = get_package_share_directory('scara_description')
    urdf_file = os.path.join(pkg, 'urdf', 'scara.urdf')
    with open(urdf_file, 'r') as f:
        robot_description = f.read()

    gz_sim = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            os.path.join(
                get_package_share_directory('ros_gz_sim'),
                'launch', 'gz_sim.launch.py'
            )
        ]),
        launch_arguments={'gz_args': '-r empty.sdf'}.items()
    )

    return LaunchDescription([

        gz_sim,

        Node(
            package='robot_state_publisher',
            executable='robot_state_publisher',
            parameters=[{'robot_description': robot_description}],
            output='screen'
        ),

        TimerAction(period=5.0, actions=[
            Node(
                package='ros_gz_sim',
                executable='create',
                arguments=[
                    '-topic', '/robot_description',
                    '-name', 'scara',
                    '-x', '0', '-y', '0', '-z', '0.1'
                ],
                output='screen'
            ),
        ]),

        # Use ros2_gz_bridge with correct remapping for joint states
        TimerAction(period=7.0, actions=[
            Node(
                package='ros_gz_bridge',
                executable='parameter_bridge',
                arguments=[
                    '/world/empty/model/scara/joint_state@sensor_msgs/msg/JointState[gz.msgs.Model'
                ],
                ros_arguments=['--remap',
                    '/world/empty/model/scara/joint_state:=/joint_states'],
                output='screen'
            ),
        ]),

    ])
