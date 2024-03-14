
# my_package_launch.py
import os
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    return LaunchDescription([
        # Declare the path to the YAML file as a launch argument
        # DeclareLaunchArgument(
        #     'param_file',
        #     default_value=[get_package_share_directory('param_test') + '/config/bms.yaml'],
        #     description='Path to the parameter YAML file'
        # ),
        
        # Start your node with loaded parameters
        Node(
            package='param_test',
            executable='parameter_node',
            output='screen',
            parameters= [os.path.join(
                get_package_share_directory('param_test'),
                'config', 'bms.yaml'
            )]
        )
    ])

# from launch import LaunchDescription
# from launch_ros.actions import Node
# from ament_index_python.packages import get_package_share_directory

# def generate_launch_description():
#     return LaunchDescription([
#         # Start your node with the path to bms.yaml as a parameter
#         Node(
#             package='param_test',
#             executable='parameter_node',
#             output='screen',
#             parameters=[{
#                 'param_file': get_package_share_directory('param_test') + '/config/bms.yaml'
#             }]
#         )
#     ])
