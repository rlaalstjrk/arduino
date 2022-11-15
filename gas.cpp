/*
    Library for gas detection
*/

#include "gas.h"
#include <Arduino.h>

#define GAS_PIN A8

void DetectGasInit(void){
  pinMode(GAS_PIN, INPUT);
}

bool DetectGas(void){
  int gasValue = analogRead(GAS_PIN);
  if(gasValue > 500)
    return true;
  else
    return false;
}