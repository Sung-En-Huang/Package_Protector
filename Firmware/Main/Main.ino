#include "ESP_Servo.h"
#include "ESP_Ultrasonic.h"

void setup()
{
    Serial.begin(115200);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    servo1.write(0);
}

void loop()
{
    while (monitor())
    {
        Serial.println("Activated");
        Serial.println("---------");
        unlock_pos();
    }
    delay(1000);
    lock_pos();
    delay(1000);
}