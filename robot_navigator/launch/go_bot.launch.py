from launch import LaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.actions import IncludeLaunchDescription
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare
import os


def generate_launch_description():
    this_pkg_share = FindPackageShare(package="robot_navigator").find("robot_navigator")

    sim_pkg_share = FindPackageShare(package="car_nav2_mecanum").find(
        "car_nav2_mecanum"
    )

    bring_pkg_share = FindPackageShare(package="competetion_bringup").find(
        "competetion_bringup"
    )

    sim_launch_file = os.path.join(sim_pkg_share, "launch", "spawn_robot.launch.py")

    bring_launch_file = os.path.join(bring_pkg_share, "launch", "bringup.launch.py")

    simulation = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(sim_launch_file)
    )

    bring_up = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(bring_launch_file)
    )

    yolo_camera_node = Node(
        executable="yolo_camera", name="yolo_camera", package="robot_navigator"
    )

    robot_motion_node = Node(
        executable= "movement_node" , name="movement_node" , package="robot_navigator"
    )

    camera_driver_node = Node(
        executable= "mono_publisher" , name="mono_publisher" , package="camera_drivers"
    )

    auto_node = Node(
        executable= "autonomous_search_node" , name="autonomous_search_node" , package="robot_navigator"
    )
    scroll_det = Node(
        executable="scroll_detection_node" , name = "scroll_detection" , package="robot_navigator"
    )
    return LaunchDescription([simulation,robot_motion_node,yolo_camera_node,scroll_det])
