/*
  checklife.h - Library to control unified sensors for life detection
*/

#include "checklife.h"
#include <Arduino.h>

#define PIN_DHT 13
#define PIN_PIR 23
#define PIN_SOUND A8
DHT dht(PIN_DHT, DHT22);

void CheckLifeInit(void){
  dht.begin();
  pinMode(PIN_PIR, INPUT);
  pinMode(PIN_SOUND, INPUT);
}

bool CheckLife(void){
  int pirValue = digitalRead(PIN_PIR);
  int soundValue = analogRead(PIN_SOUND);
  float temp = dht.readTemperature();
  float humi = dht.readHumidity();
  if((pirValue == 1 && soundValue > 50) || (pirValue == 1 && temp > 25 && humi > 30) )
    return true;
  else 
    return false;
}
