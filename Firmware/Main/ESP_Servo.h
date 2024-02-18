#ifndef ESP_SERVO_H
#define ESP_SERVO_H

#include <Servo.h>

const int servoPin = 1;
Servo servo1;
void lock_pos()
{
    servo1.write(180);
    delay(1000);
}

void unlock_pos()
{
    servo1.write(0);
    delay(1000);
}

#endif