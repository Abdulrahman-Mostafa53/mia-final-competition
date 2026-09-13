from setuptools import find_packages, setup

package_name = 'robot_navigator'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/launch',['launch/go_bot.launch.py']),
        ('share/' + package_name + '/yolo_model',['yolo_model/best.pt'])
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='abdulrahman',
    maintainer_email='Abdulrahman-Mostafa53',
    description='TODO: Package description',
    license='TODO: License declaration',
    extras_require={
        'test': [
            'pytest',
        ],
    },
    entry_points={
        'console_scripts': [
            "yolo_camera = robot_navigator.yolo_camera:main",
            "movement_node = robot_navigator.movement_node:main",
            "autonomous_search_node = robot_navigator.autonomous_search_node:main",
            "scroll_detection_node = robot_navigator.scroll_detection:main"
        ],
    },
)
