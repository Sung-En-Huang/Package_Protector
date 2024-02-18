#ifndef ESP_LIDSTEPPERMOTOR_H
#define ESP_LIDSTEPPERMOTOR_H

#include <AccelStepper.h>

const int stepsPerRevolution = 2048;  // change this to fit the number of steps per revolution
const int anglePerRevolution = 360;
const int openLidAngle = -120;
const int closeLidAngle = -openLidAngle;
// ULN2003 Motor Driver Pins
#define IN1 5
#define IN2 4
#define IN3 14
#define IN4 12

// Object initialization
AccelStepper stepper(AccelStepper::HALF4WIRE, IN1, IN3, IN2, IN4);
// Function definition
int angleToStep(int angle){
  return (angle * stepsPerRevolution) / anglePerRevolution;
}
void openLid(){
  stepper.move(angleToStep(openLidAngle));
  while(stepper.distanceToGo() != 0){
    stepper.run();
    yield();
  }
}
void closeLid(){
  stepper.move(angleToStep(closeLidAngle));
  while(stepper.distanceToGo() != 0){
    stepper.run();
    yield();
  }
}

#endif