#include <Arduino.h>
#include <TimerOne.h>

// Motor A (front left)
int enA = 6;
int in1 = 22;
int in2 = 23;

// Motor B (front right)
int enB = 5;
int in3 = 25;
int in4 = 24;

// Motor C (back left)
int enC = 12;
int in5 = 8;
int in6 = 9;

// Motor D (back right)
int enD = 7;
int in7 = 10;
int in8 = 11;

void runMotors(int mspeed, float steps, float delayAmount) {
  // Run all the motors for a certain amount of time
  while (steps<delayAmount)
  {
    analogWrite(enA, mspeed);
    analogWrite(enB, mspeed);
    analogWrite(enC, mspeed);
    analogWrite(enD, mspeed);
    steps+=1;
  }
  // Stop when done
  analogWrite(enA, 0);
  analogWrite(enB, 0);
  analogWrite(enC, 0);
  analogWrite(enD, 0);
}

// Function to Move Forward
void MoveForward(int mspeed, float delayAmount)
{
  float steps = 0;
  // Set Motor A forward
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  // Set Motor B forward
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  // Set Motor C forward
  digitalWrite(in5, HIGH);
  digitalWrite(in6, LOW);

  // Set Motor D forward
  digitalWrite(in7, HIGH);
  digitalWrite(in8, LOW);

  // Run the motors at the specified speed, and amount of time
  runMotors(mspeed, steps, delayAmount);
}

// Function to Move in Reverse
void MoveReverse(int mspeed, float delayAmount)
{
  float steps = 0;
  // Set Motor A reverse
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

  // Set Motor B reverse
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

    // Set Motor C reverse
  digitalWrite(in5, LOW);
  digitalWrite(in6, HIGH);

  // Set Motor D reverse
  digitalWrite(in7, LOW);
  digitalWrite(in8, HIGH);

  // Run the motors at the specified speed, and amount of time
  runMotors(mspeed, steps, delayAmount);
}

// Function to Spin Right
void SpinRight(int mspeed, float delayAmount)
{
  float steps = 0;

  // Set Motor A reverse
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

  // Set Motor B forward
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

    // Set Motor C reverse
  digitalWrite(in5, HIGH);
  digitalWrite(in6, LOW);

  // Set Motor D forward
  digitalWrite(in7, LOW);
  digitalWrite(in8, HIGH);

  // Run the motors at the specified speed, and amount of time
  runMotors(mspeed, steps, delayAmount);
}

// Function to Spin Left
void SpinLeft(int mspeed, float delayAmount)
{
  float steps = 0;

  // Set Motor A forward
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  // Set Motor B reverse
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  // Set Motor C forward
  digitalWrite(in5, LOW);
  digitalWrite(in6, HIGH);

  // Set Motor D reverse
  digitalWrite(in7, HIGH);
  digitalWrite(in8, LOW);

  // Run the motors at the specified speed, and amount of time
  runMotors(mspeed, steps, delayAmount);
}

void setup()
{
  // Motor Movement
  // Format: MotorDirection(speed of motors (0-255), how long that action should last)

  MoveForward(255, 40000);  // Ex: Forward at 255 speed for 40000
  delay(1000);                       // Wait one second
  MoveReverse(255, 40000);
  delay(1000);                       // Wait one second
  SpinRight(255, 40000);
  delay(1000);                       // Wait one second
  SpinLeft(255, 40000);
  delay(1000);                       // Wait one second
  MoveForward(255, 20000);
}

void loop()
{

}



//***************************WORKING MOTOR CODE USING DELAYS************************//



// #include <Arduino.h>
// #include <TimerOne.h>

// /*
//   DroneBot Workshop 2017
//   http://dronebotworkshop.com
// */

// // Constants for Interrupt Pins
// // Change values if not using Arduino Uno

// const byte MOTOR_A = 3; // Motor 2 Interrupt Pin - INT 1 - Right Motor
// const byte MOTOR_B = 2; // Motor 1 Interrupt Pin - INT 0 - Left Motor

// // Constant for steps in disk
// const float stepcount = 20.00; // 20 Slots in disk, change if different

// // Constant for wheel diameter
// const float wheeldiameter = 66.10; // Wheel diameter in millimeters, change if different

// // Integers for pulse counters
// volatile int counter_A = 0;
// volatile int counter_B = 0;

// // Motor A (front left)
// int enA = 6;
// int in1 = 22;
// int in2 = 23;

// // Motor B (front right)
// int enB = 5;
// int in3 = 25;
// int in4 = 24;

// // Motor C (back left)
// int enC = 12;
// int in5 = 8;
// int in6 = 9;

// // Motor D (back right)
// int enD = 7;
// int in7 = 10;
// int in8 = 11;

// // Interrupt Service Routines

// // Motor A pulse count ISR
// void ISR_countA()
// {
//   counter_A++; // increment Motor A counter value
// }

// // Motor B pulse count ISR
// void ISR_countB()
// {
//   counter_B++; // increment Motor B counter value
// }

// // Function to convert from centimeters to steps
// int CMtoSteps(float cm)
// {
//   int result;                                        // Final calculation result
//   float circumference = (wheeldiameter * 3.14) / 10; // Calculate wheel circumference in cm
//   float cm_step = circumference / stepcount;         // CM per Step

//   float f_result = cm / cm_step; // Calculate result as a float
//   result = (int)f_result;        // Convert to an integer (note this is NOT rounded)

//   return result; // End and return result
// }

// // Function to Move Forward
// void MoveForward(int mspeed, float delayAmount)
// {
//   counter_A = 0; //  reset counter A to zero
//   counter_B = 0; //  reset counter B to zero
//   float steps = 0;
//   // Set Motor A forward
//   digitalWrite(in1, HIGH);
//   digitalWrite(in2, LOW);

//   // Set Motor B forward
//   digitalWrite(in3, HIGH);
//   digitalWrite(in4, LOW);

//   // Set Motor C forward
//   digitalWrite(in5, HIGH);
//   digitalWrite(in6, LOW);

//   // Set Motor D forward
//   digitalWrite(in7, HIGH);
//   digitalWrite(in8, LOW);

//   // Go forward until step value is reached
//   while (steps<delayAmount)
//   {
//     analogWrite(enA, mspeed);
//     analogWrite(enB, mspeed);
//     analogWrite(enC, mspeed);
//     analogWrite(enD, mspeed);
//     steps+=1;
//   }

//   // Stop when done
//   analogWrite(enA, 0);
//   analogWrite(enB, 0);
//   analogWrite(enC, 0);
//   analogWrite(enD, 0);
//   counter_A = 0; //  reset counter A to zero
//   counter_B = 0; //  reset counter B to zero
// }

// // Function to Move in Reverse
// void MoveReverse(int mspeed, float delayAmount)
// {
//   counter_A = 0; //  reset counter A to zero
//   counter_B = 0; //  reset counter B to zero
//   float steps = 0;
//   // Set Motor A reverse
//   digitalWrite(in1, LOW);
//   digitalWrite(in2, HIGH);

//   // Set Motor B reverse
//   digitalWrite(in3, LOW);
//   digitalWrite(in4, HIGH);

//     // Set Motor C reverse
//   digitalWrite(in5, LOW);
//   digitalWrite(in6, HIGH);

//   // Set Motor D reverse
//   digitalWrite(in7, LOW);
//   digitalWrite(in8, HIGH);

//   // Go in reverse until step value is reached
//   while (steps<delayAmount)
//   {
//     analogWrite(enA, mspeed);
//     analogWrite(enB, mspeed);
//     analogWrite(enC, mspeed);
//     analogWrite(enD, mspeed);
//     steps+=1;
//   }

//   // Stop when done
//   analogWrite(enA, 0);
//   analogWrite(enB, 0);
//   analogWrite(enC, 0);
//   analogWrite(enD, 0);
//   counter_A = 0; //  reset counter A to zero
//   counter_B = 0; //  reset counter B to zero
// }

// // Function to Spin Right
// void SpinRight(int mspeed, float delayAmount)
// {
//   float steps = 0;
//   counter_A = 0; //  reset counter A to zero
//   counter_B = 0; //  reset counter B to zero

//   // Set Motor A reverse
//   digitalWrite(in1, LOW);
//   digitalWrite(in2, HIGH);

//   // Set Motor B forward
//   digitalWrite(in3, HIGH);
//   digitalWrite(in4, LOW);

//     // Set Motor C reverse
//   digitalWrite(in5, HIGH);
//   digitalWrite(in6, LOW);

//   // Set Motor D forward
//   digitalWrite(in7, LOW);
//   digitalWrite(in8, HIGH);

//   // Go until step value is reached
//   while (steps<delayAmount)
//   {
//     analogWrite(enA, mspeed);
//     analogWrite(enB, mspeed);
//     analogWrite(enC, mspeed);
//     analogWrite(enD, mspeed);
//     steps+=1;
//   }

//   // Stop when done
//   analogWrite(enA, 0);
//   analogWrite(enB, 0);
//   analogWrite(enC, 0);
//   analogWrite(enD, 0);
//   counter_A = 0; //  reset counter A to zero
//   counter_B = 0; //  reset counter B to zero
// }

// // Function to Spin Left
// void SpinLeft(int mspeed, float delayAmount)
// {
//   counter_A = 0; //  reset counter A to zero
//   counter_B = 0; //  reset counter B to zero
//   float steps = 0;

//   // Set Motor A forward
//   digitalWrite(in1, HIGH);
//   digitalWrite(in2, LOW);

//   // Set Motor B reverse
//   digitalWrite(in3, LOW);
//   digitalWrite(in4, HIGH);

//   // Set Motor C forward
//   digitalWrite(in5, LOW);
//   digitalWrite(in6, HIGH);

//   // Set Motor D reverse
//   digitalWrite(in7, HIGH);
//   digitalWrite(in8, LOW);

//   // Go until step value is reached
//   while (steps<delayAmount)
//   {
//     analogWrite(enA, mspeed);
//     analogWrite(enB, mspeed);
//     analogWrite(enC, mspeed);
//     analogWrite(enD, mspeed);
//     steps+=1;
//   }

//   // Stop when done
//   analogWrite(enA, 0);
//   analogWrite(enB, 0);
//   analogWrite(enC, 0);
//   analogWrite(enD, 0);
//   counter_A = 0; //  reset counter A to zero
//   counter_B = 0; //  reset counter B to zero
// }

// void setup()
// {
//   // Attach the Interrupts to their ISR's
//   attachInterrupt(digitalPinToInterrupt(MOTOR_A), ISR_countA, RISING); // Increase counter A when speed sensor pin goes High
//   attachInterrupt(digitalPinToInterrupt(MOTOR_B), ISR_countB, RISING); // Increase counter B when speed sensor pin goes High

//   // Test Motor Movement  - Experiment with your own sequences here

//   MoveForward(255, 40000);  // Forward half a metre at 255 speed
//   delay(1000);                       // Wait one second
//   MoveReverse(255, 40000);              // Reverse 10 steps at 255 speed
//   delay(1000);                       // Wait one second
//   SpinRight(255, 40000);                // Spin right 20 steps at 255 speed
//   delay(1000);                       // Wait one second
//   SpinLeft(255, 40000);                 // Spin left 60 steps at 175 speed
//   delay(1000);                       // Wait one second
//   MoveForward(255, 20000);               // Forward 1 step at 255 speed
// }

// void loop()
// {
//   // Put whatever you want here!
// }







//************************************************ORIGINAL CODE**************************************************







// #include <Arduino.h>

// // Include the TimerOne Library from Paul Stoffregen
// #include <TimerOne.h>

// /*
//   Robot Car with Speed Sensor Demonstration
//   RobotCarSpeedSensorDemo.ino
//   Demonstrates use of Hardware Interrupts
//   to control motors on Robot Car

//   DroneBot Workshop 2017
//   http://dronebotworkshop.com
// */

// // Constants for Interrupt Pins
// // Change values if not using Arduino Uno

// const byte MOTOR_A = 3; // Motor 2 Interrupt Pin - INT 1 - Right Motor
// const byte MOTOR_B = 2; // Motor 1 Interrupt Pin - INT 0 - Left Motor

// // Constant for steps in disk
// const float stepcount = 20.00; // 20 Slots in disk, change if different

// // Constant for wheel diameter
// const float wheeldiameter = 66.10; // Wheel diameter in millimeters, change if different

// // Integers for pulse counters
// volatile int counter_A = 0;
// volatile int counter_B = 0;

// // Motor A

// int enA = 12;
// int in1 = 11;
// int in2 = 10;

// // Motor B

// int enB = 7;
// int in3 = 9;
// int in4 = 8;

// // Interrupt Service Routines

// // Motor A pulse count ISR
// void ISR_countA()
// {
//   counter_A++; // increment Motor A counter value
// }

// // Motor B pulse count ISR
// void ISR_countB()
// {
//   counter_B++; // increment Motor B counter value
// }

// // Function to convert from centimeters to steps
// int CMtoSteps(float cm)
// {

//   int result;                                        // Final calculation result
//   float circumference = (wheeldiameter * 3.14) / 10; // Calculate wheel circumference in cm
//   float cm_step = circumference / stepcount;         // CM per Step

//   float f_result = cm / cm_step; // Calculate result as a float
//   result = (int)f_result;        // Convert to an integer (note this is NOT rounded)

//   return result; // End and return result
// }

// // Function to Move Forward
// void MoveForward(int steps, int mspeed)
// {
//   counter_A = 0; //  reset counter A to zero
//   counter_B = 0; //  reset counter B to zero

//   // Set Motor A forward
//   digitalWrite(in1, HIGH);
//   digitalWrite(in2, LOW);

//   // Set Motor B forward
//   digitalWrite(in3, HIGH);
//   digitalWrite(in4, LOW);

//   // Go forward until step value is reached
//   while (steps > counter_A && steps > counter_B)
//   {

//     if (steps > counter_A)
//     {
//       analogWrite(enA, mspeed);
//     }
//     else
//     {
//       analogWrite(enA, 0);
//     }
//     if (steps > counter_B)
//     {
//       analogWrite(enB, mspeed);
//     }
//     else
//     {
//       analogWrite(enB, 0);
//     }
//   }

//   // Stop when done
//   analogWrite(enA, 0);
//   analogWrite(enB, 0);
//   counter_A = 0; //  reset counter A to zero
//   counter_B = 0; //  reset counter B to zero
// }

// // Function to Move in Reverse
// void MoveReverse(int steps, int mspeed)
// {
//   counter_A = 0; //  reset counter A to zero
//   counter_B = 0; //  reset counter B to zero

//   // Set Motor A reverse
//   digitalWrite(in1, LOW);
//   digitalWrite(in2, HIGH);

//   // Set Motor B reverse
//   digitalWrite(in3, LOW);
//   digitalWrite(in4, HIGH);

//   // Go in reverse until step value is reached
//   while (steps > counter_A && steps > counter_B)
//   {

//     if (steps > counter_A)
//     {
//       analogWrite(enA, mspeed);
//     }
//     else
//     {
//       analogWrite(enA, 0);
//     }
//     if (steps > counter_B)
//     {
//       analogWrite(enB, mspeed);
//     }
//     else
//     {
//       analogWrite(enB, 0);
//     }
//   }

//   // Stop when done
//   analogWrite(enA, 0);
//   analogWrite(enB, 0);
//   counter_A = 0; //  reset counter A to zero
//   counter_B = 0; //  reset counter B to zero
// }

// // Function to Spin Right
// void SpinRight(int steps, int mspeed)
// {
//   counter_A = 0; //  reset counter A to zero
//   counter_B = 0; //  reset counter B to zero

//   // Set Motor A reverse
//   digitalWrite(in1, LOW);
//   digitalWrite(in2, HIGH);

//   // Set Motor B forward
//   digitalWrite(in3, HIGH);
//   digitalWrite(in4, LOW);

//   // Go until step value is reached
//   while (steps > counter_A && steps > counter_B)
//   {

//     if (steps > counter_A)
//     {
//       analogWrite(enA, mspeed);
//     }
//     else
//     {
//       analogWrite(enA, 0);
//     }
//     if (steps > counter_B)
//     {
//       analogWrite(enB, mspeed);
//     }
//     else
//     {
//       analogWrite(enB, 0);
//     }
//   }

//   // Stop when done
//   analogWrite(enA, 0);
//   analogWrite(enB, 0);
//   counter_A = 0; //  reset counter A to zero
//   counter_B = 0; //  reset counter B to zero
// }

// // Function to Spin Left
// void SpinLeft(int steps, int mspeed)
// {
//   counter_A = 0; //  reset counter A to zero
//   counter_B = 0; //  reset counter B to zero

//   // Set Motor A forward
//   digitalWrite(in1, HIGH);
//   digitalWrite(in2, LOW);

//   // Set Motor B reverse
//   digitalWrite(in3, LOW);
//   digitalWrite(in4, HIGH);

//   // Go until step value is reached
//   while (steps > counter_A && steps > counter_B)
//   {

//     if (steps > counter_A)
//     {
//       analogWrite(enA, mspeed);
//     }
//     else
//     {
//       analogWrite(enA, 0);
//     }
//     if (steps > counter_B)
//     {
//       analogWrite(enB, mspeed);
//     }
//     else
//     {
//       analogWrite(enB, 0);
//     }
//   }

//   // Stop when done
//   analogWrite(enA, 0);
//   analogWrite(enB, 0);
//   counter_A = 0; //  reset counter A to zero
//   counter_B = 0; //  reset counter B to zero
// }

// void setup()
// {
//   // Attach the Interrupts to their ISR's
//   attachInterrupt(digitalPinToInterrupt(MOTOR_A), ISR_countA, RISING); // Increase counter A when speed sensor pin goes High
//   attachInterrupt(digitalPinToInterrupt(MOTOR_B), ISR_countB, RISING); // Increase counter B when speed sensor pin goes High

//   // Test Motor Movement  - Experiment with your own sequences here

//   MoveForward(CMtoSteps(50), 255);   // Forward half a metre at 255 speed
//   delay(1000);                       // Wait one second
//   MoveReverse(10, 255);              // Reverse 10 steps at 255 speed
//   delay(1000);                       // Wait one second
//   MoveForward(10, 150);              // Forward 10 steps at 150 speed
//   delay(1000);                       // Wait one second
//   MoveReverse(CMtoSteps(25.4), 200); // Reverse 25.4 cm at 200 speed
//   delay(1000);                       // Wait one second
//   SpinRight(20, 255);                // Spin right 20 steps at 255 speed
//   delay(1000);                       // Wait one second
//   SpinLeft(60, 175);                 // Spin left 60 steps at 175 speed
//   delay(1000);                       // Wait one second
//   MoveForward(1, 255);               // Forward 1 step at 255 speed
// }

// void loop()
// {
//   // Put whatever you want here!
// }
