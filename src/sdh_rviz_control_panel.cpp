#include "sdh_rviz_control_panel.h"
#include <pluginlib/class_list_macros.h>

namespace sdh_rviz_control_panel {
SDHControlPanel::SDHControlPanel(QWidget* parent) : rviz::Panel(parent) {
  _vbox = new QVBoxLayout();

  _btnInitialise = new QPushButton(tr("Initialise"));
  _btnEmergencyStop = new QPushButton(tr("Emergency Stop"));
  _btnEngage = new QPushButton(tr("Engage"));
  _btnDisengage = new QPushButton(tr("Disengage"));
  _btnTactileClose = new QPushButton(tr("Tactile Close"));
  _btnTactileOpen = new QPushButton(tr("Tactile Open"));

  _btnInitialise->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  _btnEmergencyStop->setSizePolicy(QSizePolicy::Expanding,
                                   QSizePolicy::Expanding);
  _btnEngage->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  _btnDisengage->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  _btnTactileClose->setSizePolicy(QSizePolicy::Expanding,
                                  QSizePolicy::Expanding);
  _btnTactileOpen->setSizePolicy(QSizePolicy::Expanding,
                                 QSizePolicy::Expanding);

  _vbox->addWidget(_btnInitialise);
  _vbox->addWidget(_btnEmergencyStop);
  _vbox->addWidget(_btnEngage);
  _vbox->addWidget(_btnDisengage);
  _vbox->addWidget(_btnTactileClose);
  _vbox->addWidget(_btnTactileOpen);

  connect(_btnInitialise, SIGNAL(clicked()), this, SLOT(initialise()));
  connect(_btnEmergencyStop, SIGNAL(clicked()), this, SLOT(stop()));
  connect(_btnEngage, SIGNAL(clicked()), this, SLOT(engage()));
  connect(_btnDisengage, SIGNAL(clicked()), this, SLOT(disengage()));
  connect(_btnTactileClose, SIGNAL(clicked()), this, SLOT(close()));
  connect(_btnTactileOpen, SIGNAL(clicked()), this, SLOT(open()));

  setLayout(_vbox);
}

void SDHControlPanel::initialise() {
  std_srvs::Trigger msg;
  srvInitialise_.call(msg);
}

void SDHControlPanel::stop() {
  std_srvs::Trigger msg;
  srvEmergencyStop_.call(msg);
}

void SDHControlPanel::engage() {
  std_srvs::Trigger msg;
  srvEngage_.call(msg);
}

void SDHControlPanel::disengage() {
  std_srvs::Trigger msg;
  srvDisengage_.call(msg);
}

void SDHControlPanel::close() {
  std_srvs::Trigger msg;
  srvTactileClose_.call(msg);
}

void SDHControlPanel::open() {
  std_srvs::Trigger msg;
  srvTactileOpen_.call(msg);
}
}

PLUGINLIB_EXPORT_CLASS(sdh_rviz_control_panel::SDHControlPanel, rviz::Panel)
