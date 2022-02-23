class LightSensorBody : LightSensor
{
private:
	LightSensor sensor1;
	LightSensor sensor2;
	LightSensor sensor3;

public:
	LightSensorBody();

	LightSensorBody(LightSensor sensor1_, LightSensor sensor2_, LightSensor sensor3_);
};