#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Wire.h>
// Define the digital inputs
#define jB1 2  // Joystick button 1
#define jB2 3  // Joystick button 2
#define b1 4   // Button 1
#define b2 5   // Button 2
#define b3 6   // Button 3
#define b4 9   // Button 4
#define j1PotXPin A0 //Joystick 1 axis X
#define j1PotYPin A1 //Joystick 1 axis Y
#define j2PotXPin A2 //Joystick 2 axis X
#define j2PotYPin A3 //Joystick 2 axis Y

RF24 radio(7, 8);   // nRF24L01 (CE, CSN)
const byte address[6] = "00001"; // Address

// Max size of this struct is 32 bytes - NRF24L01 buffer limit
struct Data_Package {
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

void setup() {
  Serial.begin(9600);

  // Define the radio communication
  radio.begin();
  radio.openWritingPipe(address);
  radio.setAutoAck(false);
  radio.setDataRate(RF24_250KBPS);
  radio.setPALevel(RF24_PA_MIN); // It was originally LOW

  // Activate the Arduino internal pull-up resistors
  pinMode(jB1, INPUT_PULLUP);
  pinMode(jB2, INPUT_PULLUP);
  pinMode(b1, INPUT_PULLUP);
  pinMode(b2, INPUT_PULLUP);
  pinMode(b3, INPUT_PULLUP);
  pinMode(b4, INPUT_PULLUP);

  // Set initial default values
  data.j1PotX = 127; // Values from 0 to 255. When Joystick is in resting position, the value is in the middle, or 127. We actually map the pot value from 0 to 1023 to 0 to 255 because that's one BYTE value
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

void loop() {
  // Read all analog inputs and map them to one Byte value
  data.j1PotX = map(analogRead(j1PotXPin), 0, 1023, 0, 255); // Convert the analog read value from 0 to 1023 into a BYTE value from 0 to 255
  data.j1PotY = map(analogRead(j1PotYPin), 0, 1023, 0, 255);
  data.j2PotX = map(analogRead(j2PotXPin), 0, 1023, 0, 255);
  data.j2PotY = map(analogRead(j2PotYPin), 0, 1023, 0, 255);
  // Read all digital inputs
  data.j1Button = digitalRead(jB1);
  data.j2Button = digitalRead(jB2);
  data.button1 = digitalRead(b1);
  data.button2 = digitalRead(b2);
  data.button3 = digitalRead(b3);
  data.button4 = digitalRead(b4);
  // Send the whole data from the structure to the receiver
  radio.write(&data, sizeof(Data_Package));
}
