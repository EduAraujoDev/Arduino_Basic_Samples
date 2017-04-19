#include <SoftwareSerial.h>
 
SoftwareSerial gps(4, 3);
 
void setup() {
  Serial.begin(9600);
  while(!Serial);
   
  gps.begin(9600);
  delay(1000);
   
  Serial.println("Setup Complete!");
}
 
void loop() {
  if(gps.available()){
    Serial.write(gps.read());
  }
  
  if(Serial.available()){    
    gps.write(Serial.read());
  }
}
