/*
  door.h - Library to control magnetic door sensor.
*/

#include "door.h"
#include <Arduino.h>

#define PIN_MAG 1

void DoorInit(void){
  pinMode(1,OUTPUT);
}

bool DoorCheck(void){
  int magneticValue = digitalRead(1);
  if(magneticValue == HIGH){
    return true;
  }else {return false;}
}