import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import ExecuteProcess, TimerAction, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.actions import Node
from launch.substitutions import Command

def generate_launch_description():
    pkg = get_package_share_directory('scara_description')
    xacro_file = os.path.join(pkg, 'config', 'scara.config.xacro')

    gazebo_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            os.path.join(
                get_package_share_directory('gazebo_ros'),
                'launch', 'gazebo.launch.py'
            )
        ])
    )

    return LaunchDescription([

        gazebo_launch,

        Node(
            package='robot_state_publisher',
            executable='robot_state_publisher',
            parameters=[{
                'robot_description': Command(['xacro ', xacro_file])
            }],
            output='screen'
        ),

        TimerAction(
            period=5.0,
            actions=[
                Node(
                    package='gazebo_ros',
                    executable='spawn_entity.py',
                    arguments=[
                        '-topic', 'robot_description',
                        '-entity', 'scara',
                        '-x', '0',
                        '-y', '0',
                        '-z', '0.1'
                    ],
                    output='screen'
                ),
            ]
        ),

    ])