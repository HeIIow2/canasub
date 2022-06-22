// com 4
#include<Wire.h>

#define ADRESS 1
#define EXPECTED_BYTES BYTES_PER_FLOAT*2
#define BYTES_PER_FLOAT 4

#define UNEXPECTED_BYTES_ERROR "the sizes of the received bytes dont match!"


struct _blackbox
{
    /*
    These are the x and y parts of the positional vector of
    the blackbox.
    The vector is relative to the submarine.
    The values are in cm.
    */
    float x=0.0f;
    float y=0.0f;
};

_blackbox blackbox;



void setup() 
{
    Wire.begin(ADRESS); 

    Serial.begin(9600);
    Serial.println("Started");
}

char float_buff[BYTES_PER_FLOAT]={};
float read_float() {
    for (int i=0; i<BYTES_PER_FLOAT; i++) {
        float_buff[i] = Wire.read();
    }

    return *(float *)&float_buff;
}

void on_receive(int number_of_bytes) 
{
    if (number_of_bytes < EXPECTED_BYTES) return;
    /*
    The Bytes are (in order):
    X of the blackbox (in cm) 4 bytes - float
    Y of the blackbox (in cm) 4 bytes - float
    */

    Serial.print("X: ");
    Serial.println(read_float());
    Serial.print("X: ");
    Serial.println(read_float());

   // byte x_blackbox = Wire.
}

void read_ic2() 
{
    Serial.println(Wire.available());
    if (Wire.available() >= EXPECTED_BYTES)
    {
        if (Wire.available() % EXPECTED_BYTES != 0) {
            Serial.print("WARNING (I2C): there are ");
            Serial.print(Wire.available());
            Serial.print(" bytes availible, where ");
            Serial.print(EXPECTED_BYTES);
            Serial.println(" bytes have been expected");
        }

        Serial.println("available bytes");

        on_receive(Wire.available());
    }

}

void loop() 
{
    read_ic2();
}