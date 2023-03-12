// Replace GPIO Chip with Arduino
// Loosely based on Wire Examples by Eightbitswide

#include <Wire.h>

void setup() {
  Wire.begin(0x20);             // join I2C bus with address 0x20
  Wire.onReceive(receiveEvent); 
  Wire.onRequest(sendEvent);   
  Serial.begin(9600);          
}

void loop() {

}


void receiveEvent(int howMany) {
  while (1 < Wire.available()) { // loop through all but the last
    char c = Wire.read(); // receive byte as a character
  }
  
  char x = Wire.read();   
  if (x > 19) {
     Serial.print(x);}
  if (x == 13) {
     Serial.println(""); }   
}


void sendEvent()
{
  byte y = Serial.available();
 if (y != 0) {
   int x = Serial.read(); 

   if (x > 0){ Wire.print(char(x)); }
   if (x > 13) { Serial.print(char(x)); }      //remove or remark this line for full duplex.
   if (x == 13) { Serial.println(char(x)); }   //remove or remark this line for full duplex.
       
 }  

                       
}
