#include "Motor.h"



struct VECTOR2
{
    float x, y;

    void ConvertToVector(byte index, float value);

}

class Steering
{
    private:

    VECTOR2 V_SUB;
    VECTOR2 V_BOX;

    Motor drive;

    public:

    Steering();

    Steering(Motor frontMotor, Motor backMotor);

    void Left();

    void Right();

    void Turn(float angle);

    CalcTurnWay(float angle);

    void Turn();

}