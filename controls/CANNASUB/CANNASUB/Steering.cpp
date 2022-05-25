#include "Steering.h"

#define PI 3.14159265359

void VECTOR2::ConvertToVector()
{
    
}

Steering::Steering()
{
    FrontMotor = Motor();
    BackMotor = Motor();
}

Steering::Steering(Motor _drive, Pump Pump_Front, Pump Pump_Back)
{
    drive = _drive;
    FrontPump = Pump_Front;
    BackPump = Pump_Back;

}

void Steering::Left()
{

}

void Steering::Right()
{

}

void Steering::Left()
{

}

void Steering::Turn(float angle)
{
    pump1.setSpeed(a);
    pump2.setSpeed(a);

    if (angle == 0) return;


}

void Steering::Steer()
{
    if(V_BOX.x == V_SUB.x && V_BOX.y == V_SUB.y)
    {
        drive.setSpeed(0);

        return;
    }

    if(drive.GetSpeed() == 0) drive.StartMotor(speed_);

    WayToBox = sqrt(pow(V_BOX.x - V_SUB.x, 2) + pow(V_BOX.y - V_SUB.y, 2));

    if(WayToBoxPrev != WayToBox)
    {
        Turn(WayToBox);
        WayToBoxPrev = WayToBox;
    }

}