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

Steering::Steering(Motor frontMotor, Motor backMotor)
{
    FrontMotor = frontMotor;
    BackMotor = backMotor;
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

void Steering::CalcTurnWay(float angle)
{
    float FrontMotorSpeed = FrontMotor.GetSpeed();
    float BackMotorSpeed = BackMotor.GetSpeed();

    

}