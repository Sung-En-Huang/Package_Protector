#ifndef ESP_SERVO_H
#define ESP_SERVO_H
#include <Servo.h>

Servo servo1;
const int servoPin = 1;
servo1.attach(servoPin, 500, 2400);

void lock_pos()
{
    servo1.write(0);
}

void unlock_pos()
{
    servo1.write(180);
}

#endif