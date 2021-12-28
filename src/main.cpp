// Use with 4 yellow motors.

#include <Arduino.h>

// Constants for Interrupt Pins
const byte MOTOR_A = 3;  // Motor 1 Interrupt Pin - INT 1 - Front Right Motor
const byte MOTOR_B = 2;  // Motor 2 Interrupt Pin - INT 0 - Front Left Motor
const byte MOTOR_C = 18; // Motor 3 Interrupt Pin - INT 2 - Back Left Motor
const byte MOTOR_D = 19; // Motor 4 Interrupt Pin - INT 3 - Back Right Motor

// Constant for steps in disk
const float stepcount = 20.00; // 20 Slots in disk, change if different

// Constant for wheel diameter
const float wheeldiameter = 48; // Wheel diameter in millimeters, change if different

// Integers for pulse counters
volatile int counter_A = 0;
volatile int counter_B = 0;
volatile int counter_C = 0;
volatile int counter_D = 0;

// Motor A (front right)
int enA = 5;
int in1 = 25;
int in2 = 24;

// Motor B (front left)
int enB = 6;
int in3 = 23;
int in4 = 22;

// Motor C (back left)
int enC = 12;
int in5 = 11;
int in6 = 10;

// Motor D (back right)
int enD = 7;
int in7 = 9;
int in8 = 8;

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
  float f_result = cm / cm_step;                     // Calculate result as a float
  result = (int)f_result;                            // Convert to an integer (note this is NOT rounded)

  return result; // End and return result
}

/* 
SetMotorDirection()
  Sets the pins on a motor to either HIGH or LOW based on the inputs.
  Input Types: int
  Inputs: pinNumber1, pinNumber2, pinLevel1, pinLevel2
*/
void SetMotorDirection(int pinNumber1, int pinNumber2, int pinLevel1, int pinLevel2)
{
  if (pinLevel1 == 1)
  {
    digitalWrite(pinNumber1, HIGH);
  }
  else
  {
    digitalWrite(pinNumber1, LOW);
  }
  if (pinLevel2 == 1)
  {
    digitalWrite(pinNumber2, HIGH);
  }
  else
  {
    digitalWrite(pinNumber2, LOW);
  }
}

/* 
ResetCounters()
  Resets all step counters to 0.
  Input Types: None
  Inputs: None
*/
void ResetCounters()
{
  counter_A = 0; //  reset counter A to zero
  counter_B = 0; //  reset counter B to zero
  counter_C = 0; //  reset counter B to zero
  counter_D = 0; //  reset counter B to zero
}

/* 
RunMotors()
  Runs the motors at specified speed and for a specified length.
  Input Types: int
  Inputs: steps, speed
*/
void RunMotors(int step, int speed)
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

  ResetCounters(); // Reset all counters
}

// Function to Move Forward
void MoveForward(int steps, int mspeed)
{
  ResetCounters(); // Reset all counters

  SetMotorDirection(in1, in2, 1, 0); // Set Motor A forward
  SetMotorDirection(in3, in4, 1, 0); // Set Motor B forward
  SetMotorDirection(in5, in6, 0, 1); // Set Motor C forward
  SetMotorDirection(in7, in8, 0, 1); // Set Motor D forward

  RunMotors(steps, mspeed); // Run motors for specified steps and speed
}

// Function to Move in Reverse
void MoveReverse(int steps, int mspeed)
{
  ResetCounters(); // Reset all counters

  SetMotorDirection(in1, in2, 0, 1); // Set Motor A reverse
  SetMotorDirection(in3, in4, 0, 1); // Set Motor B reverse
  SetMotorDirection(in5, in6, 1, 0); // Set Motor C reverse
  SetMotorDirection(in7, in8, 1, 0); // Set Motor D reverse

  RunMotors(steps, mspeed); // Run motors for specified steps and speed
}

// Function to Move Right Sideways
void MoveRight(int steps, int mspeed)
{
  ResetCounters(); // Reset all counters

  SetMotorDirection(in1, in2, 0, 1); // Set Motor A reverse
  SetMotorDirection(in3, in4, 1, 0); // Set Motor B forward
  SetMotorDirection(in5, in6, 1, 0); // Set Motor C reverse
  SetMotorDirection(in7, in8, 0, 1); // Set Motor D forward

  RunMotors(steps, mspeed); // Run motors for specified steps and speed
}

// Function to Move Left Sideways
void MoveLeft(int steps, int mspeed)
{
  ResetCounters(); // Reset all counters

  SetMotorDirection(in1, in2, 1, 0); // Set Motor A forward
  SetMotorDirection(in3, in4, 0, 1); // Set Motor B reverse
  SetMotorDirection(in5, in6, 0, 1); // Set Motor C forward
  SetMotorDirection(in7, in8, 1, 0); // Set Motor D reverse

  RunMotors(steps, mspeed); // Run motors for specified steps and speed
}

// Function to Move Right Forward
void MoveRightForward(int steps, int mspeed)
{
  ResetCounters(); // Reset all counters

  SetMotorDirection(in1, in2, 0, 0); // Set Motor A stopped
  SetMotorDirection(in3, in4, 1, 0); // Set Motor B forward
  SetMotorDirection(in5, in6, 0, 0); // Set Motor C stopped
  SetMotorDirection(in7, in8, 0, 1); // Set Motor D forward

  RunMotors(steps, mspeed); // Run motors for specified steps and speed
}

// Function to Move Left Forward
void MoveLeftForward(int steps, int mspeed)
{
  ResetCounters(); // Reset all counters

  SetMotorDirection(in1, in2, 1, 0); // Set Motor A forward
  SetMotorDirection(in3, in4, 0, 0); // Set Motor B stopped
  SetMotorDirection(in5, in6, 0, 1); // Set Motor C forward
  SetMotorDirection(in7, in8, 0, 0); // Set Motor D stopped

  RunMotors(steps, mspeed); // Run motors for specified steps and speed
}

// Function to Move Right reverse
void MoveRightReverse(int steps, int mspeed)
{
  ResetCounters(); // Reset all counters

  SetMotorDirection(in1, in2, 0, 1); // Set Motor A reverse
  SetMotorDirection(in3, in4, 0, 0); // Set Motor B stopped
  SetMotorDirection(in5, in6, 1, 0); // Set Motor C reverse
  SetMotorDirection(in7, in8, 0, 0); // Set Motor D stopped

  RunMotors(steps, mspeed); // Run motors for specified steps and speed
}

// Function to Move Left reverse
void MoveLeftReverse(int steps, int mspeed)
{
  ResetCounters(); // Reset all counters

  SetMotorDirection(in1, in2, 0, 0); // Set Motor A stopped
  SetMotorDirection(in3, in4, 0, 1); // Set Motor B reverse
  SetMotorDirection(in5, in6, 0, 0); // Set Motor C stopped
  SetMotorDirection(in7, in8, 1, 0); // Set Motor D forward

  RunMotors(steps, mspeed); // Run motors for specified steps and speed
}

void attachInterrupts()
{
  // Attach the Interrupts to their ISR's
  attachInterrupt(digitalPinToInterrupt(MOTOR_A), ISR_countA, RISING); // Increase counter A when speed sensor pin goes High
  attachInterrupt(digitalPinToInterrupt(MOTOR_B), ISR_countB, RISING); // Increase counter B when speed sensor pin goes High
  attachInterrupt(digitalPinToInterrupt(MOTOR_C), ISR_countC, RISING); // Increase counter C when speed sensor pin goes High
  attachInterrupt(digitalPinToInterrupt(MOTOR_D), ISR_countD, RISING); // Increase counter D when speed sensor pin goes High
}

void setup()
{
  attachInterrupts(); // Attach the Interrupts to their ISR's

  // Test Motor Movement:
  MoveForward(CMtoSteps(20), 255); // Ex: Forward at 255 speed for 20cm
  delay(1000);                     // Wait one second
  MoveReverse(CMtoSteps(20), 255);
  delay(1000);
  MoveRight(CMtoSteps(20), 255);
  delay(1000);
  MoveLeft(CMtoSteps(20), 255);
  delay(1000);
  MoveLeftForward(CMtoSteps(20), 255);
  delay(1000);
  MoveRightForward(CMtoSteps(20), 255);
  delay(1000);
  MoveLeftReverse(CMtoSteps(20), 255);
  delay(1000);
  MoveRightReverse(CMtoSteps(20), 255);
  delay(1000);
}

void loop()
{
  // Put whatever you want here!
}
