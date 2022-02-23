//#define LIGHTSENSOR(int pin, int x, int y) LightSensor{pin,x,y}

class LightSensor
{
private:
	int pin;
	int x;
	int y;

public:
	LightSensor();
	LightSensor(int pin_, int x_, int y_);

	float get_value();
};
