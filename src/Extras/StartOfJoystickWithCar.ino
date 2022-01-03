// Use with 4 yellow motors.

#include <Arduino.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(32, 33); // nRF24L01 (CE, CSN)
const byte address[6] = "00001";
unsigned long lastReceiveTime = 0;
unsigned long currentTime = 0;
// Max size of this struct is 32 bytes - NRF24L01 buffer limit
struct Data_Package
{
  byte j1PotX;
  byte j1PotY;
  byte j1Button;
  byte j2PotX;
  byte j2PotY;
  byte j2Button;
  byte button1;
  byte button2;
  byte button3;
  byte button4;
};
Data_Package data; //Create a variable with the above structure

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

// Function to Move Right reverse
void SpinRight(int steps, int mspeed)
{
  ResetCounters(); // Reset all counters

  SetMotorDirection(in1, in2, 0, 1); // Set Motor A reverse
  SetMotorDirection(in3, in4, 1, 0); // Set Motor B stopped
  SetMotorDirection(in5, in6, 0, 1); // Set Motor C reverse
  SetMotorDirection(in7, in8, 1, 0); // Set Motor D stopped

  RunMotors(steps, mspeed); // Run motors for specified steps and speed
}

// Function to Move Left reverse
void SpinLeft(int steps, int mspeed)
{
  ResetCounters(); // Reset all counters

  SetMotorDirection(in1, in2, 1, 0); // Set Motor A stopped
  SetMotorDirection(in3, in4, 0, 1); // Set Motor B reverse
  SetMotorDirection(in5, in6, 1, 0); // Set Motor C stopped
  SetMotorDirection(in7, in8, 0, 1); // Set Motor D forward

  RunMotors(steps, mspeed); // Run motors for specified steps and speed
}

// Function to Move Left reverse
void Stop()
{
  ResetCounters(); // Reset all counters

  SetMotorDirection(in1, in2, 0, 0); // Set Motor A stopped
  SetMotorDirection(in3, in4, 0, 0); // Set Motor B reverse
  SetMotorDirection(in5, in6, 0, 0); // Set Motor C stopped
  SetMotorDirection(in7, in8, 0, 0); // Set Motor D forward

  RunMotors(0, 0); // Run motors for specified steps and speed
}

void attachInterrupts()
{
  // Attach the Interrupts to their ISR's
  attachInterrupt(digitalPinToInterrupt(MOTOR_A), ISR_countA, RISING); // Increase counter A when speed sensor pin goes High
  attachInterrupt(digitalPinToInterrupt(MOTOR_B), ISR_countB, RISING); // Increase counter B when speed sensor pin goes High
  attachInterrupt(digitalPinToInterrupt(MOTOR_C), ISR_countC, RISING); // Increase counter C when speed sensor pin goes High
  attachInterrupt(digitalPinToInterrupt(MOTOR_D), ISR_countD, RISING); // Increase counter D when speed sensor pin goes High
}

void resetData()
{
  // Reset the values when there is no radio connection - Set initial default values
  data.j1PotX = 127;
  data.j1PotY = 127;
  data.j2PotX = 127;
  data.j2PotY = 127;
  data.j1Button = 1;
  data.j2Button = 1;
  data.button1 = 1;
  data.button2 = 1;
  data.button3 = 1;
  data.button4 = 1;
}

void setup()
{

  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setAutoAck(false);
  radio.setDataRate(RF24_250KBPS);
  radio.setPALevel(RF24_PA_MIN); // It was originally LOW
  radio.startListening();        //  Set the module as receiver
  resetData();

  attachInterrupts(); // Attach the Interrupts to their ISR's

  // Test Motor Movement:
  // MoveForward(CMtoSteps(20), 255); // Ex: Forward at 255 speed for 20cm
  // delay(1000);                     // Wait one second
  // MoveReverse(CMtoSteps(20), 255);
  // delay(1000);
  // MoveRight(CMtoSteps(20), 255);
  // delay(1000);
  // MoveLeft(CMtoSteps(20), 255);
  // delay(1000);
  // MoveLeftForward(CMtoSteps(20), 255);
  // delay(1000);
  // MoveRightForward(CMtoSteps(20), 255);
  // delay(1000);
  // MoveLeftReverse(CMtoSteps(20), 255);
  // delay(1000);
  // MoveRightReverse(CMtoSteps(20), 255);
  // delay(1000);
  // SpinLeft(CMtoSteps(20), 255);
  // delay(1000);
  // SpinRight(CMtoSteps(20), 255);
  // delay(1000);
}

void loop()
{
  // Check whether there is data to be received
  if (radio.available())
  {
    radio.read(&data, sizeof(Data_Package)); // Read the whole data and store it into the 'data' structure
    lastReceiveTime = millis();              // At this moment we have received the data
  }
  // Check whether we keep receving data, or we have a connection between the two modules
  currentTime = millis();
  if (currentTime - lastReceiveTime > 1000)
  {              // If current time is more then 1 second since we have recived the last data, that means we have lost connection
    resetData(); // If connection is lost, reset the data. It prevents unwanted behavior, for example if a drone has a throttle up and we lose connection, it can keep flying unless we reset the values
  }
  
  
  if (data.j1PotY < 145 && data.j1PotY > 110 && data.j1PotX < 145 && data.j1PotX > 110)
  {
    Stop();
  }
  else if (data.j1PotX > 130 && data.j1PotY < 145 && data.j1PotY > 110)
  {
    data.j1PotX = map(data.j1PotX, 130, 255, 150, 255);
    MoveForward(CMtoSteps(1), data.j1PotX);
  }
  else if (data.j1PotX < 126 && data.j1PotY < 145 && data.j1PotY > 110)
  {
    data.j1PotX = map(data.j1PotX, 126, 0, 150, 255);
    MoveReverse(CMtoSteps(1), data.j1PotX);
  }
  else if (data.j1PotY < 126 && data.j1PotX < 145 && data.j1PotX > 110)
  {
    data.j1PotY = map(data.j1PotY, 126, 0, 150, 255);
    MoveLeft(CMtoSteps(1), data.j1PotX);
  }
  else if (data.j1PotY > 130 && data.j1PotX < 145 && data.j1PotX > 110)
  {
    data.j1PotY = map(data.j1PotY, 130, 255, 150, 255);
    MoveRight(CMtoSteps(1), data.j1PotX);
  }

  // Print the data in the Serial Monitor

  // Use this portion below to see in the SERIAL PLOTTER

  // Serial.print(data.j1PotX);
  // Serial.print(" ");
  // Serial.print(data.j1PotY);
  // Serial.print(" ");
  // Serial.print(data.j2PotX);
  // Serial.print(" ");
  // Serial.print(data.j2PotY);
  // Serial.print(" ");
  // Serial.print(data.button1);
  // Serial.print(" ");
  // Serial.print(data.button2);
  // Serial.print(" ");
  // Serial.print(data.button3);
  // Serial.print(" ");
  // Serial.print(data.button4);
  // Serial.println("");

  // Use this portion below to see in SERIAL MONITOR

  //  Serial.print("j1PotX: ");
  //  Serial.print(data.j1PotX);
  //  Serial.print("; j1PotY: ");
  //  Serial.print(data.j1PotY);
  //  Serial.print("; j2PotX: ");
  //  Serial.println(data.j2PotX);
  //  Serial.print("; j2PotY: ");
  //  Serial.println(data.j2PotY);
  //  Serial.print("; button1: ");
  //  Serial.print(data.button1);
  //  Serial.print("; button2: ");
  //  Serial.print(data.button2);
  //  Serial.print("; button3: ");
  //  Serial.print(data.button3);
  //  Serial.print("; button4: ");
  //  Serial.print(data.button4);
  //  Serial.println("");
}
