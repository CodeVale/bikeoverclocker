#include <Arduino.h>

#define TIMER 100
#define OUTPUT_LEN 1000
#define MAGNET_SENSOR 23
#define SPEED_SENSOR 22
#define OUTPUT_PIN 1

bool magnet_mode = false;
unsigned int count = 0;

void setup() {
  pinMode(MAGNET_SENSOR, INPUT); //Magnetschalter
  pinMode(SPEED_SENSOR, INPUT);  //anderer Schalter halt
  pinMode(OUTPUT_PIN, OUTPUT);
  //Serial.begin(115200);
}

void loop() 
{
  while (true)
  {
    magnet_mode = digitalRead(MAGNET_SENSOR);
    //Serial.write("Magnetmode\n");
    if (magnet_mode == true)
    {
      magnet_mode = false;
      break;
    }
    delay(500);
  }
  for (unsigned int i = 0; i < TIMER; i++)
  {
    //Serial.print("for-loop \n");
    if (digitalRead(SPEED_SENSOR) == HIGH)
    {
      count = count + 1;
      //Serial.write("1");
      delay(500);
    }
    if (count == 2)
    {
      count = 0;
      //Serial.write("Output");
      digitalWrite(OUTPUT_PIN, HIGH);
      delay(OUTPUT_LEN);
      digitalWrite(OUTPUT_PIN, LOW);
      break;
    }
    delay(100);
  }
}