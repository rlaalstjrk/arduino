#include "FanControl.h"
FanControl::FanControl(int fanPin,int servoPin) {
  pinMode(fan_pin, INPUT);
	f_servo.attach(servo_pin);
  fan_pin=fanPin;
  fanServo_Pin=servoPin;
	fanState = false;
	servoAngle = 0;
};
bool FanControl::isFanActive() {
	return fanState;
};
void FanControl::fanStart( int delay) {
	int tmp = servoAngle;
	if ((fanState == false) && (servoAngle < 90)) {
		int i = tmp;
		while (i < 90) {
			i++;
			f_servo.write(i);
			delay(delay);
		}
		if (i >= 90) {
			fanState = true;
			servoAngle=i; 
		}
    digitalWrite(fan_pin,HIGH);
	}
};
void FanControl::fanStop(int delay) {
	int tmp = servoAngle;
	if ((fanState == true)&& (servoAngle > 0)) {
		digitalWrite(fan_pin,LOW);
		int i = tmp;
		while (i >0;) {
			i--;
			f_servo.write(i);
			delay(delay);
		}
		if (servoAngle <= 0) {
			fanState = false;
			servoAngle=i;
		}
	}
};