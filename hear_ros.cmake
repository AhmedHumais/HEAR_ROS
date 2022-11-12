set(HEAR_ROS_INCLUDE_DIR ${CMAKE_CURRENT_LIST_DIR}/include)
set(HEAR_ROS_SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/src)

file(GLOB HEAR_ROS_SRCs ${HEAR_ROS_SOURCE_DIR}/*.cpp)

find_package(catkin REQUIRED COMPONENTS
    roscpp
    std_msgs
    nav_msgs
    std_srvs
    geometry_msgs
    tf2_geometry_msgs
    tf2
    tf2_ros
    nodelet
)

set(HEAR_ROS_LIBS ${catkin_LIBRARIES})

