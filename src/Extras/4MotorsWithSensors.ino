// Use with 4 yellow motors. This code has encoder code.

#include <Arduino.h>
#include <TimerOne.h>

// Constants for Interrupt Pins
// Change values if not using Arduino Uno

const byte MOTOR_A = 3;  // Motor 1 Interrupt Pin - INT 1 - Front Left Motor
const byte MOTOR_B = 2;  // Motor 2 Interrupt Pin - INT 0 - Front Right Motor
const byte MOTOR_C = 18; // Motor 3 Interrupt Pin - INT 2 - Back Left Motor
const byte MOTOR_D = 19; // Motor 4 Interrupt Pin - INT 3 - Back Right Motor

// Constant for steps in disk
const float stepcount = 20.00; // 20 Slots in disk, change if different

// Constant for wheel diameter
const float wheeldiameter = 66.10; // Wheel diameter in millimeters, change if different

// Integers for pulse counters
volatile int counter_A = 0;
volatile int counter_B = 0;
volatile int counter_C = 0;
volatile int counter_D = 0;

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

// Interrupt Service Routines

// Motor A pulse count ISR
void ISR_countA()
{
  counter_A++; // increment Motor A counter value
}

// Motor B pulse count ISR
void ISR_countB()
{
  counter_B++; // increment Motor B counter value
}
// Motor B pulse count ISR
void ISR_countC()
{
  counter_C++; // increment Motor C counter value
}
// Motor B pulse count ISR
void ISR_countD()
{
  counter_D++; // increment Motor D counter value
}

// Function to convert from centimeters to steps
int CMtoSteps(float cm)
{

  int result;                                        // Final calculation result
  float circumference = (wheeldiameter * 3.14) / 10; // Calculate wheel circumference in cm
  float cm_step = circumference / stepcount;         // CM per Step

  float f_result = cm / cm_step; // Calculate result as a float
  result = (int)f_result;        // Convert to an integer (note this is NOT rounded)

  return result; // End and return result
}

/* 
resetCounters()
  Resets all step counters to 0.
  Inputs: None
*/
void resetCounters()
{
  counter_A = 0; //  reset counter A to zero
  counter_B = 0; //  reset counter B to zero
  counter_C = 0; //  reset counter B to zero
  counter_D = 0; //  reset counter B to zero
}

/* 
runMotors()
  Runs the motors at specified speed and for a specified length.
  Inputs: int steps, int speed
*/
void runMotors(int step, int speed)
{
  while (step > counter_A && step > counter_B && step > counter_C && step > counter_D)
  {
    if (step > counter_A)
    {
      analogWrite(enA, speed);
    }
    else
    {
      analogWrite(enA, 0);
    }
    if (step > counter_B)
    {
      analogWrite(enB, speed);
    }
    else
    {
      analogWrite(enB, 0);
    }
    if (step > counter_C)
    {
      analogWrite(enC, speed);
    }
    else
    {
      analogWrite(enC, 0);
    }
    if (step > counter_D)
    {
      analogWrite(enD, speed);
    }
    else
    {
      analogWrite(enD, 0);
    }
  }
  // Stop when done
  analogWrite(enA, 0);
  analogWrite(enB, 0);
  analogWrite(enC, 0);
  analogWrite(enD, 0);
  // Reset all counters
  resetCounters();
}

// Function to Move Forward
void MoveForward(int steps, int mspeed)
{
  // Reset all counters
  resetCounters();

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

  // Run motors for specified steps and speed
  runMotors(steps, mspeed);
}

// Function to Move in Reverse
void MoveReverse(int steps, int mspeed)
{
  // Reset all counters
  resetCounters();

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

  // Run motors for specified steps and speed
  runMotors(steps, mspeed);
}

// Function to Spin Right
void SpinRight(int steps, int mspeed)
{
  // Reset all counters
  resetCounters();

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

  // Run motors for specified steps and speed
  runMotors(steps, mspeed);
}

// Function to Spin Left
void SpinLeft(int steps, int mspeed)
{
  resetCounters();

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

  // Run motors for specified steps and speed
  runMotors(steps, mspeed);
}

void setup()
{
  // Attach the Interrupts to their ISR's
  attachInterrupt(digitalPinToInterrupt(MOTOR_A), ISR_countA, RISING); // Increase counter A when speed sensor pin goes High
  attachInterrupt(digitalPinToInterrupt(MOTOR_B), ISR_countB, RISING); // Increase counter B when speed sensor pin goes High
  attachInterrupt(digitalPinToInterrupt(MOTOR_C), ISR_countC, RISING); // Increase counter C when speed sensor pin goes High
  attachInterrupt(digitalPinToInterrupt(MOTOR_D), ISR_countD, RISING); // Increase counter D when speed sensor pin goes High

  // Test Motor Movement:

  MoveForward(CMtoSteps(20), 255); // Ex: Forward at 255 speed for 20cm
  delay(1000);                     // Wait one second
  MoveReverse(CMtoSteps(20), 255);
  delay(1000); // Wait one second
  SpinRight(CMtoSteps(20), 255);
  delay(1000); // Wait one second
  SpinLeft(CMtoSteps(20), 255);
  delay(1000); // Wait one second
  MoveForward(CMtoSteps(20), 255);

  // MoveForward(CMtoSteps(50), 255);   // Forward half a metre at 255 speed
  // delay(1000);                       // Wait one second
  // MoveReverse(10, 255);              // Reverse 10 steps at 255 speed
  // delay(1000);                       // Wait one second
  // MoveForward(10, 150);              // Forward 10 steps at 150 speed
  // delay(1000);                       // Wait one second
  // MoveReverse(CMtoSteps(25.4), 200); // Reverse 25.4 cm at 200 speed
  // delay(1000);                       // Wait one second
  // SpinRight(20, 255);                // Spin right 20 steps at 255 speed
  // delay(1000);                       // Wait one second
  // SpinLeft(60, 175);                 // Spin left 60 steps at 175 speed
  // delay(1000);                       // Wait one second
  // MoveForward(1, 255);               // Forward 1 step at 255 speed
}

void loop()
{
  // Put whatever you want here!
}
