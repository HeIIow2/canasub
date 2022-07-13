// com 4
#include<Wire.h>

#define ADRESS 1
#define BYTES_PER_FLOAT 8
#define EXPECTED_BYTES BYTES_PER_FLOAT*2

#define UNEXPECTED_BYTES_ERROR "the sizes of the received bytes dont match!"


float x_vector = 0;
float y_vector = 0;


void setup() 
{
    Wire.begin(); 

    Serial.begin(9600);
    Serial.println("Started");
}


char float_buff[BYTES_PER_FLOAT]={};
void loop() 
{
    // request data
    Wire.requestFrom(ADRESS, EXPECTED_BYTES);

    // read arrived data
    {
        if (Wire.available() >= EXPECTED_BYTES) {
            Serial.println("enough bytes are availible");

            if (Wire.available() % EXPECTED_BYTES != 0) 
            {
                Serial.println("WARNING: THERE AVAILIBLE BYTES DONT MATCH THE MESSAGE SIZE");
            }

            if (EXPECTED_BYTES % BYTES_PER_FLOAT != 0) 
            {
                Serial.println("WARNING: THE MESSAGE SIZE IS NO MULTIPLE OF THE BYTES PER FLOAT");
            }

            // read the x vector
            for (int i=0; i<BYTES_PER_FLOAT; i++) 
            {
                float_buff[i] = Wire.read();
            }
            x_vector = atof(float_buff);
            Serial.print("x vector: ");
            Serial.println(x_vector);

            // read the y vector
            for (int i=0; i<BYTES_PER_FLOAT; i++) 
            {
                float_buff[i] = Wire.read();
            }
            y_vector = atof(float_buff);
            
            Serial.print("y vector: ");
            Serial.println(y_vector);

        }
    }
}