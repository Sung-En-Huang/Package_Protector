#ifndef ESP_LIDSTEPPERMOTOR_H
#define ESP_LIDSTEPPERMOTOR_H

#include <Stepper.h>

const int stepsPerRevolution = 2048; // total steps per revolution
// const int stepChunk = 10; // steps to take in each chunk
const int anglePerRevolution = 360;
const int lidOpenAngle = 90;
const int lidCloseAngle = -90;

// Motor Driver Pin Definition
const int motor1Pin = 16;
const int motor2Pin = 5;
const int motor3Pin = 4;
const int motor4Pin = 0;

// Object initialization
Stepper myStepper(stepsPerRevolution, motor1Pin, motor2Pin, motor3Pin, motor4Pin);
// Function definition
int angleToSteps(int angle){
  return (angle*stepsPerRevolution)/anglePerRevolution;
}

// void stepInit(){
//   // int stepCount = 0;
//   int stepsToMove = angleToSteps(lidOpenAngle);
//   int stepChunk = stepsToMove/10;
// }
void openLid(){
  int stepCount = 0; // track steps taken
  int stepsToMove = angleToSteps(lidOpenAngle);
  int stepChunk = stepsToMove/10;

  while(stepCount < stepsToMove) {
    // Move in chunks
    myStepper.step(stepChunk);
    stepCount += stepChunk;
    delay(100);
  }
  delay(1000);
}

void closeLid(){
  int stepCount = 0; // track steps taken
  int stepsToMove = angleToSteps(lidOpenAngle);
  int stepChunk = stepsToMove/10;

  while(stepCount > stepsToMove) {
    // Move in chunks
    myStepper.step(stepChunk);
    stepCount -= stepChunk;
    delay(100);
  }
  delay(1000);
}

#endif