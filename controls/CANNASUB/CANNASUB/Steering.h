#include "Motor.h"
#include "Pump.h"



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
    Pump FrontPump;
    Pump BackPump;

    float WayToBox;
    float WayToBoxPrev;

    public:

    Steering();

    Steering(Motor _drive, Pump Pump_Front, Pump Pump_Back);

    StartDrive();

    void Left();

    void Right();

    void Turn(float angle);

    CalcTurnWay(float angle);

    void Turn();

    void Steer();

}