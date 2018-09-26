cmake_minimum_required(VERSION 2.8.3)
project(sdh_rviz_control_panel)

add_compile_options(-std=c++11)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

find_package(catkin REQUIRED COMPONENTS rviz)
find_package(Qt5 REQUIRED COMPONENTS Widgets)

catkin_package(
    CATKIN_DEPENDS rviz
    INCLUDE_DIRS # TODO include
    LIBRARIES # TODO
)

include_directories(${catkin_INCLUDE_DIRS})
include_directories(include/)

add_library(SDHControlPanel src/sdh_rviz_control_panel.cpp)
target_link_libraries(SDHControlPanel ${catkin_LIBRARIES} ${rviz_DEFAULT_PLUGIN_LIBRARIES} Qt5::Widgets)

install(FILES plugin_description.xml
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)
install(TARGETS SDHControlPanel
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION})
