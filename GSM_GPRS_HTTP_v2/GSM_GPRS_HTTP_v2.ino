#include <SoftwareSerial.h>

#define SIM800_TX_PIN 10
#define SIM800_RX_PIN 11

SoftwareSerial serialSIM800(SIM800_TX_PIN, SIM800_RX_PIN);

void setup() {
  Serial.begin(9600);
  while (!Serial);

  serialSIM800.begin(4800);
  delay(1000);

  Serial.println("Testando SIM800L...");
}

void loop() {
  serialSIM800.println("AT");
  delay(100);
  ShowSerialData();

  serialSIM800.println("AT+SAPBR=3,1,\"Contype\",\"GPRS\"");
  delay(1000);
  ShowSerialData();
  
  serialSIM800.println("AT+SAPBR=3,1,\"APN\",\"timbrasil.br\"");
  delay(4000);
  ShowSerialData();
  
  serialSIM800.println("AT+SAPBR=3,1,\"USER\",\"tim\"");
  delay(4000);
  ShowSerialData();
  
  serialSIM800.println("AT+SAPBR=3,1,\"PWD\",\"tim\"");
  delay(4000);
  ShowSerialData();
  
  serialSIM800.println("AT+SAPBR=1,1");
  delay(2000);
  ShowSerialData();
  
  serialSIM800.println("AT+SAPBR=2,1");
  delay(2000);
  ShowSerialData();
  
  serialSIM800.println("AT+HTTPINIT");
  delay(2000);
  ShowSerialData();
  
  serialSIM800.println("AT+HTTPPARA=\"CID\",1");
  delay(2000);
  ShowSerialData();
  
  serialSIM800.println("AT+HTTPPARA=\"URL\",\"localhost/add.php?MSG_Texto1=teste3\"");
  delay(1000);
  ShowSerialData();
  
  serialSIM800.println("AT+HTTPACTION=0");
  delay(10000);
  ShowSerialData();

  serialSIM800.println("AT+HTTPREAD");
  delay(100);
  ShowSerialData();
}

void ShowSerialData() {
  while(serialSIM800.available()!=0) {
    Serial.write(serialSIM800.read());
  }
}
