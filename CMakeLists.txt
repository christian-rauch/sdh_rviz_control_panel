cmake_minimum_required(VERSION 2.8.3)
project(sdh_rviz_control_panel)

find_package(catkin REQUIRED)
find_package(Qt4 REQUIRED COMPONENTS QtCore QtGui)

catkin_package(
	DEPENDS rviz
    CATKIN_DEPENDS
    INCLUDE_DIRS # TODO include
    LIBRARIES # TODO
)

include(${QT_USE_FILE})
include_directories(include/)

qt4_wrap_cpp(QT_MOC include/sdh_rviz_control_panel.h)
set(SOURCES src/sdh_rviz_control_panel.cpp ${QT_MOC})
add_library(SDHControlPanel ${SOURCES})
target_link_libraries(SDHControlPanel ${QT_LIBRARIES} ${catkin_LIBRARIES} ${rviz_DEFAULT_PLUGIN_LIBRARIES})

install(FILES plugin_description.xml
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)
install(TARGETS SDHControlPanel
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION})
