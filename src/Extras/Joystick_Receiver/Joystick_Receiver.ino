#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(7, 8);   // nRF24L01 (CE, CSN)
const byte address[6] = "00001";
unsigned long lastReceiveTime = 0;
unsigned long currentTime = 0;
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
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setAutoAck(false);
  radio.setDataRate(RF24_250KBPS);
  radio.setPALevel(RF24_PA_MIN); // It was originally LOW
  radio.startListening(); //  Set the module as receiver
  resetData();
}
void loop() {
  // Check whether there is data to be received
  if (radio.available()) {
    radio.read(&data, sizeof(Data_Package)); // Read the whole data and store it into the 'data' structure
    lastReceiveTime = millis(); // At this moment we have received the data
  }
  // Check whether we keep receving data, or we have a connection between the two modules
  currentTime = millis();
  if ( currentTime - lastReceiveTime > 1000 ) { // If current time is more then 1 second since we have recived the last data, that means we have lost connection
    resetData(); // If connection is lost, reset the data. It prevents unwanted behavior, for example if a drone has a throttle up and we lose connection, it can keep flying unless we reset the values
  }
  // Print the data in the Serial Monitor
  
  // Use this portion below to see in the SERIAL PLOTTER
  
  Serial.print(data.j1PotX);
  Serial.print(" ");
  Serial.print(data.j1PotY);
  Serial.print(" ");
  Serial.print(data.j2PotX);
  Serial.print(" ");
  Serial.print(data.j2PotY);
  Serial.print(" ");
  Serial.print(data.button1);
  Serial.print(" ");
  Serial.print(data.button2);
  Serial.print(" ");
  Serial.print(data.button3);
  Serial.print(" ");
  Serial.print(data.button4);
  Serial.println("");

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
void resetData() {
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
