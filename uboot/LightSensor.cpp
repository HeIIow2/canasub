#include "LightSensor.h"
#include <Arduino.h>

#define MAX_VAL 1023

LightSensor::LightSensor()
{
  pin = A0;
}

LightSensor::LightSensor(int pin_)
{
  pin = pin_;
}

float LightSensor::get_value()
{
  int raw_value = analogRead(pin);
  float value = (float)raw_value / (float)MAX_VAL;
  return value;
}
