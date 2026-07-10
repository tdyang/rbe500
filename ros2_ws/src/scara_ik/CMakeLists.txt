cmake_minimum_required(VERSION 3.8)
project(scara_ik)

find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(rclpy REQUIRED)

# Generate the custom service interface
rosidl_generate_interfaces(${PROJECT_NAME}
  "srv/ScaraIK.srv"
  "srv/SetJointPosition.srv"   # add this line
)

# Install the Python executable node
install(PROGRAMS
  scara_ik/ik_node.py
  DESTINATION lib/${PROJECT_NAME}
)

# Install the package init so Python can find scara_ik.srv at runtime
install(DIRECTORY scara_ik/
  DESTINATION lib/${PROJECT_NAME}
  FILES_MATCHING PATTERN "*.py"
)

ament_export_dependencies(rosidl_default_runtime)
ament_package()