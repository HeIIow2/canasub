#define SENSOR_PAIRS 1
#define PAIR_SENSOR_DISTANCE 1.0
#define MEASURING_TIME 50


void setup() 
{
    Serial.begin(9600);
    Serial.println("Started");
}


void loop() 
{
    int start_time = millis();

    static float sensor_pair_values[SENSOR_PAIRS][2];
    {
        /*
        Read the sensor values for MEASURING_TIME
        and stores the average in sensor_values.
        */

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
        Serial.print("m: ");
        Serial.println(mesurements);
    }

    {
        /*
        trianguliere die beiden möglichen positionen der Lichtquelle
        da nur der Winkel wichtig ist ist die länge in cm egal 
        */

       for (int i = 0; i < SENSOR_PAIRS; i++)
       {
            // bassierend auf den Schnittpunkt zweier Kreise um die sensoren mit den werten als radius
            // x_light = (-val1^2 + val2^2 - PAIR_SENSOR_DISTANCE^2) / (-2*PAIR_SENSOR_DISTANCE)
            float x_light = (-sensor_pair_values[i][0]*sensor_pair_values[i][0] + sensor_pair_values[i][1]*sensor_pair_values[i][1] - PAIR_SENSOR_DISTANCE*PAIR_SENSOR_DISTANCE) / (-2.0 * PAIR_SENSOR_DISTANCE);

            // y_light = -sqrt(x_light^2 - val^2)
            float y_opt1 = sqrt(abs(x_light*x_light - sensor_pair_values[i][0]*sensor_pair_values[i][0]));
            float y_opt2 = sqrt(abs(x_light*x_light - sensor_pair_values[i][1]*sensor_pair_values[i][1]));
            float y_light = (y_opt1 + y_opt2) / 2.0;
            Serial.println("LIGHT(" + String(x_light) + "/" + String(y_light) + ")");
       }
    }

    int end_time = millis();
    Serial.println("Time: " + String(end_time - start_time) + "ms");
    Serial.println("");
}