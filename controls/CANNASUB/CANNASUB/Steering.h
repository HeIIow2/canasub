#include "Motor.h"



struct VECTOR2
{
    float x, y;

    void ConvertToVector(byte index, float value);

}

class Steering
{
    private:

    Motor FrontMotor;
    Motor BackMotor;

    public:

    Steering();

    Steering(Motor frontMotor, Motor backMotor);

    void Left();

    void Right();

    CalcTurnWay(float angle);

    void Turn();

}