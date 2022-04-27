#define SENSOR_PAIRS 1
// in cm
#define PAIR_DISTANCE 10
#define MEASURING_TIME 50


/*// Koordinaten der Sensoren
// x, y in cm
static const int sensor_koordinates[SENSOR_NUMBERS][2] = {
        {0, 0},
        {16, 0},
        {9, 6}
    };*/


void setup() 
{
    Serial.begin(9600);
    Serial.println("Started");
}


void loop() 
{
    static float sensor_pair_values[SENSOR_PAIRS][2];
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
            for (int i = 0; i < SENSOR_PAIRS; i++)
            {
                sensor_pair_values[i][0] += (float) analogRead(i*2);
                sensor_pair_values[i][1] += (float) analogRead(i*2+1);
            }
            mesurements++;
        }
        
        for (int i = 0; i < SENSOR_PAIRS; i++)
        {
            sensor_pair_values[i][0] = sensor_pair_values[i][0] / mesurements / 1023.0;
            sensor_pair_values[i][1] = sensor_pair_values[i][1] / mesurements / 1023.0;
            Serial.print("p" + String(i) + " ");
            Serial.print(sensor_pair_values[i][0]);
            Serial.print(" ");
            Serial.print(sensor_pair_values[i][1]);
            Serial.print("; ");
        }
        Serial.print("mesurements: ");
        Serial.println(mesurements);
    }
}