// #include <Stepper.h>

// const int stepsPerRevolution = 2048; // total steps per revolution
// const int stepChunk = 100; // steps to take in each chunk
// const int anglePerRevolution = 360;
// const int lidOpenAngle = 90;
// const int lidCloseAngle = -90;

// int stepCount = 0; // track steps taken

// // Motor Driver Pin Definition
// #define IN1 16
// #define IN2 5
// #define IN3 4
// #define IN4 0

// // Object initialization
// Stepper myStepper(stepsPerRevolution, IN1, IN3, IN2, IN4);

// // Function definition
// void setup() {
//   myStepper.setSpeed(5);
//   Serial.begin(9600);
// }

// void moveLid(int angle){
//   int stepsToMove = angleToSteps(angle);
//   myStepper.step(stepsToMove);
//   delay(2000);
// }

// int angleToSteps(int angle){
//   return (angle*stepsPerRevolution)/anglePerRevolution;
// }

// void loop() {
//   // open lid
//   moveLid(lidOpenAngle);
//   // close lid
//   moveLid(lidCloseAngle);

//   //Test
//   /*
//   if (stepCount < stepsPerRevolution) {
//     // Move in chunks
//     myStepper.step(stepChunk);
//     stepCount += stepChunk;
//     Serial.println("Moving...");
//   } else {
//     // Reset and pause after completing a revolution
//     Serial.println("Completed a revolution.");
//     stepCount = 0; // Reset step count for the next revolution
//     delay(1000); // Pause for a second
//   }
//   delay(100); // Short delay to prevent WDT reset
//   // while(== true){
//   // }
//   */
// }
