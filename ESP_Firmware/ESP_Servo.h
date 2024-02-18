#ifndef ESP_SERVO_H
#define ESP_SERVO_H

#include <Servo.h>

void lock_pos(Servo servo1)
{
    servo1.write(0);
}

void unlock_pos(Servo servo1)
{
    servo1.write(180);
}

#endif