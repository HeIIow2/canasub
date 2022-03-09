#pragma once
class Motor
{
private:
	int enable;		
	int in1;
	int in2;

public:
	Motor();
	Motor(int en_, int in1_, int in2_);

	void halt();
	void forwards();
	void backwards();

	void SetSpeed(float speed_);
};
