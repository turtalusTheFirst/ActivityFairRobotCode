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
ROJoystick controller(controllerIn);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  RobotOpen.begin(&enabled, &disabled, &timedtasks);
}

void enabled() {
  boolean a = controller.btnA();
  boolean b = controller.btnB();
  boolean x = controller.btnX();
  boolean y = controller.btnY();
  Serial.print("a: " + a);
  Serial.print("b: " + b);
  Serial.print("x: " + x);
  Serial.println("y: " + y);
}

void disabled () {}

void timedtasks() {
  RODashboard.publish("Uptime Seconds", ROStatus.uptimeSeconds());
}

void loop() {
  // put your main code here, to run repeatedly:
  RobotOpen.syncDS();
}
