import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/ziad/base/mia-final-competition/install/robot_kinematics_pkg'
