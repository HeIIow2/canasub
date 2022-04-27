#include "Motor.h"



struct VECTOR2
{
    float x, y;

    void ConvertToVector(byte index, float value);

}

class Steering
{
    private:

    public:

    Steering();

    void Left();

    void Right();

    void Turn();

}