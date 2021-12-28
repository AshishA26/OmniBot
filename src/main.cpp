// Use with 4 yellow motors.

#include <Arduino.h>

// Constants for Interrupt Pins
// Change values if not using Arduino Uno

const byte MOTOR_A = 3;  // Motor 1 Interrupt Pin - INT 1 - Front Left Motor
const byte MOTOR_B = 2;  // Motor 2 Interrupt Pin - INT 0 - Front Right Motor
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
  digitalWrite(in5, LOW);
  digitalWrite(in6, HIGH);

  // Set Motor D forward
  digitalWrite(in7, LOW);
  digitalWrite(in8, HIGH);

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
  digitalWrite(in5, HIGH);
  digitalWrite(in6, LOW);

  // Set Motor D reverse
  digitalWrite(in7, HIGH);
  digitalWrite(in8, LOW);

  // Run motors for specified steps and speed
  runMotors(steps, mspeed);
}

// Function to Move Right Sideways
void MoveRight(int steps, int mspeed)
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

// Function to Move Left Sideways
void MoveLeft(int steps, int mspeed)
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

// Function to Move Right Sideways
void MoveRightForward(int steps, int mspeed)
{
  // Reset all counters
  resetCounters();

  // Set Motor A stopped
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);

  // Set Motor B Forward
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  // Set Motor C stopped
  digitalWrite(in5, LOW);
  digitalWrite(in6, LOW);

  // Set Motor D Forward
  digitalWrite(in7, LOW);
  digitalWrite(in8, HIGH);

  // Run motors for specified steps and speed
  runMotors(steps, mspeed);
}

// Function to Move Left Sideways
void MoveLeftForward(int steps, int mspeed)
{
  // Reset all counters
  resetCounters();

  // Set Motor A forward
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  // Set Motor B stopped
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  // Set Motor C forward
  digitalWrite(in5, LOW);
  digitalWrite(in6, HIGH);

  // Set Motor D stopped
  digitalWrite(in7, LOW);
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
  // MoveForward(CMtoSteps(20), 255); // Ex: Forward at 255 speed for 20cm
  // delay(1000);                     // Wait one second
  // MoveReverse(CMtoSteps(20), 255);
  // delay(1000); // Wait one second
  // MoveRight(CMtoSteps(20), 255);
  // delay(1000); // Wait one second
  // MoveLeft(CMtoSteps(20), 255);
  // delay(1000); // Wait one second
  // MoveForward(CMtoSteps(20), 255);
  
  MoveLeftForward(CMtoSteps(20), 255);
  delay(1000); // Wait one second
  MoveRightForward(CMtoSteps(20), 255);
  delay(1000); // Wait one second
}

void loop()
{
  // Put whatever you want here!
}
