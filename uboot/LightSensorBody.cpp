
#include <iostream>
#include <Arduino.h>

#include "LightSensor.h"
#include "LightSensorBody.h"


LightSensorBody::LightSensorBody()
{
	sensor1 = LightSensor(A0, 0, 0);
	sensor2 = LightSensor(A0, 0, 0);
	sensor3 = LightSensor(A0, 0, 0);
}

LightSensorBody::LightSensorBody(LightSensor sensor1_, LightSensor sensor2_, LightSensor sensor3_)
{
	sensor1 = sensor1_;
	sensor2 = sensor2_;
	sensor3 = sensor3_;
}
