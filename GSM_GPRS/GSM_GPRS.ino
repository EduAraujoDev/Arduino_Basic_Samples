#include "SIM900.h"
#include <SoftwareSerial.h>
#include "sms.h"
#include "call.h"

SMSGSM sms;
CallGSM call;

boolean started = false;
char smsbuffer[160];
char n[20];
char numTelefone[12] = "11*********";

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

  enviaSMS();
  fazLigacao();
}

void loop() {
  if (started) {
    digitalWrite(LED_BUILTIN, HIGH);

    if (gsm.readSMS(smsbuffer, 160, n, 20)) {
      Serial.println(n);
      Serial.println(smsbuffer);
    }

    digitalWrite(LED_BUILTIN, LOW);
    delay(1000);
  }
}

void enviaSMS() {
  if (started) {
    if (sms.SendSMS(numTelefone, "Arduino SMS")) {
      Serial.println("\nSMS sent OK");
    }
  }
}

void fazLigacao() {
  Serial.println("\nDiscando....");
  call.Call(numTelefone);
  delay(10000);
   
  Serial.println("Desligando...");
  call.HangUp();
}
