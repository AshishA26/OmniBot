// Use with 4 yellow motors. This code does not have encoder code.

#include <Arduino.h>

// Motor A (front left)
int enA = 5;
int in1 = 25;
int in2 = 24;

// Motor B (front right)
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

void runMotors(int mspeed, float steps, float delayAmount)
{
  // Run all the motors for a certain amount of time
  while (steps < delayAmount)
  {
    analogWrite(enA, mspeed);
    analogWrite(enB, mspeed);
    analogWrite(enC, mspeed);
    analogWrite(enD, mspeed);
    steps += 1;
    delay(1);
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

  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(enC, OUTPUT);
  pinMode(enD, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(in5, OUTPUT);
  pinMode(in6, OUTPUT);
  pinMode(in7, OUTPUT);
  pinMode(in8, OUTPUT);

  MoveForward(255, 40000); // Ex: Forward at 255 speed for 40000
  delay(1000);             // Wait one second
  MoveReverse(255, 40000);
  delay(1000); // Wait one second
  SpinRight(255, 40000);
  delay(1000); // Wait one second
  SpinLeft(255, 40000);
  delay(1000); // Wait one second
  MoveForward(255, 20000);
}

void loop()
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
    analogWrite(enA, 255);
    analogWrite(enB, 255);
    analogWrite(enC, 255);
    analogWrite(enD, 255);
}