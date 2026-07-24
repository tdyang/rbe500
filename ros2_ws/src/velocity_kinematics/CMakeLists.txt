cmake_minimum_required(VERSION 3.8)
project(velocity_kinematics)

find_package(ament_cmake REQUIRED)
find_package(ament_cmake_python REQUIRED)
find_package(rclpy REQUIRED)
find_package(std_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  "srv/JointToEEVelocity.srv"
  "srv/EEToJointVelocity.srv"
)

ament_python_install_package(${PROJECT_NAME})

install(PROGRAMS
  velocity_kinematics/velocity_kinematics_node.py
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()