#include "Motor.h"


#define MAX_SPEED 255

Motor::Motor()
{
	enable = 0;
	in1 = 0;
	in2 = 0;
}

Motor::Motor(int en_, int in1_, int in2_)
{
	enable = en_;
	in1 = in1_;
	in2 = in2_;

	pinMode(enable, OUTPUT);
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
	halt();
}


void Motor::halt()
{
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
}


void Motor::forwards()
{
	digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);
}

void Motor::backwards()
{
	digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);
}

void Motor::SetSpeed(float speed_)
{
	if (speed_ < 0.0 || speed_ > 1.0) {
		return;
	}

	analogWrite(enable, speed_ * MAX_SPEED);
}


