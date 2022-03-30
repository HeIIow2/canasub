#define SENSOR_NUMBERS 3

void setup() 
{
    Serial.begin(9600);
    Serial.println("Started");
}

void loop() 
{
    Serial.print("Reading sensors: ");
    int sensor_values[SENSOR_NUMBERS];
    for (int i = 0; i < SENSOR_NUMBERS; i++)
    {
        sensor_values[i] = analogRead(i);
        Serial.print(sensor_values[i]);
        Serial.print(" ");
    }
    Serial.println();

    delay(1000);
}