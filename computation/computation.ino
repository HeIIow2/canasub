#define SENSOR_NUMBERS 3
#define MEASURING_TIME 50

// Koordinaten der Sensoren
// x, y in cm
int sensor_koordinates[SENSOR_NUMBERS][2] = {
        {0, 0},
        {16, 0},
        {9, 6}
    };

void setup() 
{
    Serial.begin(9600);
    Serial.println("Started");
}


void loop() 
{
    static float sensor_values[SENSOR_NUMBERS] {};
    {
        /*
        Read the sensor values for MEASURING_TIME
        and stores the average in sensor_values.
        */

        Serial.print("Reading sensors: ");
        unsigned long start_measurement = millis();
        int mesurements = 0;

        while (millis() - start_measurement < MEASURING_TIME)
        {
            for (int i = 0; i < SENSOR_NUMBERS; i++)
            {
                sensor_values[i] += (float) analogRead(i) / 1023.0;
            }
            mesurements++;
        }
        
        for (int i = 0; i < SENSOR_NUMBERS; i++)
        {
            sensor_values[i] = sensor_values[i] / mesurements;
            Serial.print(sensor_values[i]);
            Serial.print(" ");
        }
        Serial.print("mesurements: ");
        Serial.println(mesurements);
    }
}