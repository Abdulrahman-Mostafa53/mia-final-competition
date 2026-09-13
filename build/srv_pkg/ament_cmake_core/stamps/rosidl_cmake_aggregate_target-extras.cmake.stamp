# generated from rosidl_cmake/cmake/rosidl_cmake_aggregate_target-extras.cmake.in

# Create a convenience aggregate target srv_pkg::srv_pkg
# that links all generated interface targets, so downstream packages can use
# a single modern CMake target name instead of ${srv_pkg_TARGETS}.
if(srv_pkg_TARGETS AND NOT TARGET srv_pkg::srv_pkg)
  add_library(srv_pkg::srv_pkg INTERFACE IMPORTED)
  set_target_properties(srv_pkg::srv_pkg PROPERTIES
    INTERFACE_LINK_LIBRARIES "${srv_pkg_TARGETS}")
endif()
