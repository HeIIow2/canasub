#include "Motor.h"
#include "LightSensor.h"
#include "LightSensorBody.h"

/*
Motor motor1 = Motor(2, 3, 4);
LightSensor light1 = LightSensor(A0);
LightSensor light2 = LightSensor(A1);

bool forward = true;
*/

LightSensor sensor1 = LightSensor(A0, 0, 0);
LightSensor sensor2 = LightSensor(A1, 140, 0);
LightSensor sensor3 = LightSensor(A2, 700, 580);

LightSensorBody body1;

void setup()
{
	Serial.begin(9600);

	body1 = LightSensorBody(sensor1, sensor2, sensor3);

	// motor1.set_speed(1.0);
	// motor1.forwards();
}


void loop()
{
	/*
	float direction_ = light1.get_value() - light2.get_value();

	Serial.println(direction_);

	if (direction_ > 0 && !forward)
	{
		motor1.forwards();
		forward = true;
	}
	else if (direction_ < 0 && forward)
	{
		motor1.backwards();
		forward = false;
	}
	*/
}

