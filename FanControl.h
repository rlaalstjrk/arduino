#ifndef FanControl_H
#define FanControl_H

#include "Arduino.h"
#include "Servo.h"
class FanControl {
private:
	bool fanState;
	int servoAngle;
  int fan_pin;
  int fanServo_pin;
  Servo f_servo;
public:
	FanControl(int fan_pin,int servo_pin);
	bool isFanActive() {};
	void fanStrat(int delay) {};
	void fanStop(int delay) {};
};

#endif