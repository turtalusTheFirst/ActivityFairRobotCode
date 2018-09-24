#include <ROJoystick.h>
#include <RobotOpenGE.h>
#include <ROAnalog.h>
#include <ROPWM.h>
#include <ROSolenoid.h>
#include <ROTimer.h>
#include <ROEncoder.h>
#include <RODigitalIO.h>
#include <ROStatus.h>
#include <ROParameter.h>
#include <RODashboard.h>

const controllerIn = 3;
const shooterIn = 0;
const beltIn = 1;
const shakerIn = 2;

ROJoystick controller(controllerIn);
ROPWM shooter(shooterIn);
ROPWM belt(beltIn);
ROPWM shaker(shakerIn);

void setup() {
  // put your setup code here, to run once:
  RobotOpen.setIP(10,0,0,22);
  RobotOpen.begin(&enabled, &disabled, &timedtasks);
}

int translate (boolean val) {
  if (val == true) {
    return 255;
  } else {
    return 127;
  }
}

void enabled() {
  shooter.write(translate(controller.btnA()));
  belt.write(translate(controller.btnB()));
  shaker.write(translate(controller.btnX()));
}

void disabled() {
  shooter.detach();
  belt.detach();
  shaker.detach();
}

void timedtasks() {
  RODashboard.publish("Uptime Seconds", ROStatus.uptimeSeconds());
}

void loop() {
  // put your main code here, to run repeatedly:
  RobotOpen.syncDS();
}
