cmake_minimum_required(VERSION 3.5)
project(param_test)

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

# Add executable
add_executable(parameter_node src/param_test_node.cpp)

# Add dependencies
ament_target_dependencies(parameter_node rclcpp)

# Install executable
install(TARGETS
  parameter_node
  DESTINATION lib/${PROJECT_NAME}
)

# Install launch files
install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME}/
)

# Install config files
install(DIRECTORY
  config
  DESTINATION share/${PROJECT_NAME}/
)

# Install package.xml
install(FILES package.xml
  DESTINATION share/${PROJECT_NAME}
)

ament_package()
