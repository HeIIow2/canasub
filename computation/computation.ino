#define SENSOR_PAIRS 2
#define COMPUTATION_COUNT (int) (SENSOR_PAIRS / 2) + (SENSOR_PAIRS % 2)
#define PAIR_SENSOR_DISTANCE 1.0f
#define DISTANCE_BETWEEN_PAIRS 9.0f
#define MEASURING_TIME 50

#define RESET_X_INTERVAL 1000

int last_reset_x;
int computation_list[COMPUTATION_COUNT][2];
int x_measurements = 0;

void setup() 
{
    Serial.begin(9600);
    Serial.println("Computation started");

    {
        /*
        Ich erstelle eine Liste, bei der jedes element eine Liste von zwei Werte ist.
        Die beiden Werte sind die Indices der Sensorenpaare die ich hintereinander messe.
        */
        int steps = (int) SENSOR_PAIRS / 2;

        if (SENSOR_PAIRS % 2 == 1) 
        {
            computation_list[0][0] = 0;
            computation_list[0][1] = SENSOR_PAIRS - 1;
        }

        for (int i=SENSOR_PAIRS % 2; i <= steps; i++)
        {
            computation_list[i][0] = i;
            computation_list[i][1] = i + steps;
        }
    }

    Serial.println("Started");

    last_reset_x = millis();
}


void loop() 
{
    // x is the factor to multiply the sensor distance by to get the distance in cm
    static float x = 0;

    static int start_time = millis();

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
                Serial.print(i);
                Serial.print(" ");
                Serial.print(analogRead(i*2));
                Serial.print(" ");
                Serial.println(analogRead(i*2+1));
                sensor_pair_values[i][0] += (float) analogRead(i*2);
                sensor_pair_values[i][1] += (float) analogRead(i*2+1);
            }
            Serial.println("");
            mesurements++;
        }
        
        for (int i = 0; i < SENSOR_PAIRS; i++)
        {
            // sensor_pair_values[i][0] = sensor_pair_values[i][0] / mesurements / 1023.0;
            // sensor_pair_values[i][1] = sensor_pair_values[i][1] / mesurements / 1023.0;
            sensor_pair_values[i][0] = sensor_pair_values[i][0] / mesurements;
            sensor_pair_values[i][1] = sensor_pair_values[i][1] / mesurements;
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
        // calculate the x factor
        for (int index = 0; index < COMPUTATION_COUNT; index++) {
            int i = computation_list[index][0];
            int j = computation_list[index][1];

            float a = sensor_pair_values[i][0];
            float b = sensor_pair_values[i][1];
            float c = sensor_pair_values[j][0];
            float d = sensor_pair_values[j][1];

            x = (2.0 * (3.0 * (b*b) + (c*c) - 3.0 * (d*d)) * (PAIR_SENSOR_DISTANCE*PAIR_SENSOR_DISTANCE)) / ((b*b*b*b) - ((c*c) - (d * d)));
            Serial.println("x:" + String(x));
            x_measurements++;
        }
        
        /*
        p: PAIR_SENSOR_DISTANCE
        */
    }

    {
        /*
        trianguliere die beiden möglichen positionen der Lichtquelle
        da nur der Winkel wichtig ist ist die länge in cm egal 
        */

       float lights_positions[SENSOR_PAIRS][2];

       for (int i = 0; i < SENSOR_PAIRS; i++)
       {
            // bassierend auf den Schnittpunkt zweier Kreise um die sensoren mit den werten als radius
            // x_light = (-val1^2 + val2^2 - PAIR_SENSOR_DISTANCE^2) / (-2*PAIR_SENSOR_DISTANCE)
            float x_light = (-sensor_pair_values[i][0]*sensor_pair_values[i][0] + sensor_pair_values[i][1]*sensor_pair_values[i][1] - PAIR_SENSOR_DISTANCE*PAIR_SENSOR_DISTANCE) / (-2.0 * PAIR_SENSOR_DISTANCE);

            // y_light = -sqrt(x_light^2 - val^2)
            float y_opt1 = sqrt(abs(x_light*x_light - sensor_pair_values[i][0]*sensor_pair_values[i][0]));
            float y_opt2 = sqrt(abs(x_light*x_light - sensor_pair_values[i][1]*sensor_pair_values[i][1]));
            float y_light = (y_opt1 + y_opt2) / 2.0;
            Serial.println("LIGHT(" + String(x_light * x) + "/" + String(y_light * x) + ")");
       }
    }

    // reset x if the interval passed
    if (millis() - last_reset_x > RESET_X_INTERVAL)
    {
        last_reset_x = millis();
        x = 0;
        x_measurements = 0;
    }


    int end_time = millis();
    Serial.println("Time: " + String(end_time - start_time) + "ms");
    Serial.println("");
}