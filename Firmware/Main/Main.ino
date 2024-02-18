#include "../../ESP_Firmware/ESP_Servo.h"
#include "../../ESP_Firmware/ESP_Ultrasonic.h"

Servo servo1;
void setup()
{
    Serial.begin(115200);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    servo1.attach(servoPin, 500, 2400);
    servo1.write(0);
}

void loop()
{
    while (monitor())
    {
        unlock_pos(servo1);
    }
    delay(1000);
    lock_pos(servo1);
    delay(1000);
}