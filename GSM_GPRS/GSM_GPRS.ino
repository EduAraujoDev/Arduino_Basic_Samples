#include "SIM900.h"
#include <SoftwareSerial.h>
#include "sms.h"

SMSGSM sms;

int numdata;
boolean started=false;
char smsbuffer[160];
char n[20];

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  
  Serial.begin(9600);
  Serial.println("GSM GPRS testing.");

  if (gsm.begin(2400)) {
    Serial.println("\nstatus=OK");
    started = true;
  } else {
    Serial.println("\nstatus=NOK");
  }

  if (started) {
    if (sms.SendSMS("11*********", "Arduino SMS")) {
      Serial.println("\nSMS sent OK");
    }
  }
}

void loop() {
  if(started){
    digitalWrite(LED_BUILTIN, HIGH);
    
    if(gsm.readSMS(smsbuffer, 160, n, 20)) {
      Serial.println(n);
      Serial.println(smsbuffer);
    }

    digitalWrite(LED_BUILTIN, LOW);
    delay(1000);
  }
}
