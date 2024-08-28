# generated from catkin/cmake/template/pkg.context.pc.in
CATKIN_PACKAGE_PREFIX = ""
PROJECT_PKG_CONFIG_INCLUDE_DIRS = "${prefix}/include".split(';') if "${prefix}/include" != "" else []
PROJECT_CATKIN_DEPENDS = "roscpp;std_msgs;sensor_msgs;nav_msgs;geometry_msgs;tf;tf2;tf2_geometry_msgs".replace(';', ' ')
PKG_CONFIG_LIBRARIES_WITH_PREFIX = "-limu_encoder_odom".split(';') if "-limu_encoder_odom" != "" else []
PROJECT_NAME = "imu_encoder_odom"
PROJECT_SPACE_DIR = "/home/adg/catkin_ws/install"
PROJECT_VERSION = "0.0.0"
