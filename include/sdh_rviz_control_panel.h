#pragma once

#include <QtGui>

#include <ros/ros.h>
#include <rviz/panel.h>

#include <std_srvs/Trigger.h>

namespace sdh_rviz_control_panel {
class SDHControlPanel : public rviz::Panel {
  Q_OBJECT

 public:
  SDHControlPanel(QWidget* parent = 0);

 protected Q_SLOTS:
  void initialise();
  void stop();
  void engage();
  void disengage();
  void close();
  void open();

 protected:
  QVBoxLayout* _vbox;

  QPushButton* _btnInitialise;
  QPushButton* _btnEmergencyStop;
  QPushButton* _btnEngage;
  QPushButton* _btnDisengage;
  QPushButton* _btnTactileClose;
  QPushButton* _btnTactileOpen;

 private:
  ros::NodeHandle nh;
  ros::ServiceClient srvInitialise_ =
      nh.serviceClient<std_srvs::Trigger>("/gripper/sdh_controller/init");
  ros::ServiceClient srvEmergencyStop_ =
      nh.serviceClient<std_srvs::Trigger>("/gripper/sdh_controller/stop");
  ros::ServiceClient srvEngage_ =
      nh.serviceClient<std_srvs::Trigger>("/gripper/sdh_controller/engage");
  ros::ServiceClient srvDisengage_ =
      nh.serviceClient<std_srvs::Trigger>("/gripper/sdh_controller/disengage");
  ros::ServiceClient srvTactileClose_ = nh.serviceClient<std_srvs::Trigger>(
      "/gripper/sdh_controller/tactile_close");
  ros::ServiceClient srvTactileOpen_ = nh.serviceClient<std_srvs::Trigger>(
      "/gripper/sdh_controller/tactile_open");
};
}
