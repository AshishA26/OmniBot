// Use with 4 yellow motors. This code does not have encoder code.

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