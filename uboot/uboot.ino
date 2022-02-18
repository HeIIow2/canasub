#include "Motor.h"
#include "LightSensor.h"

Motor motor1 = Motor(2, 3, 4);
LightSensor light1 = LightSensor(A0);
LightSensor light2 = LightSensor(A1);

bool forward = true;

void setup() {
  motor1.set_speed(1.0);
  motor1.forwards();

  Serial.begin(9600);
  delay(500);
}

void loop() {
  float direction_ = light1.get_value() - light2.get_value();

  Serial.println(direction_);

  if (direction_ > 0 && !forward) {
    motor1.forwards();
    forward = true;
  } else if(direction_ < 0 && forward) {
    motor1.backwards();
    forward = false;
  }
}
