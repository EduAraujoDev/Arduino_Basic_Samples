#include "SIM900.h"
#include <SoftwareSerial.h>
#include "sms.h"
#include "call.h"
#include "inetGSM.h"

SMSGSM sms;
CallGSM call;
InetGSM inet;

boolean started = false;
char smsbuffer[160];
char n[20];
char numTelefone[12] = "11984016212";

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

  // enviaSMS();
  // fazLigacao();
}

void loop() {
  if (started) {
    digitalWrite(LED_BUILTIN, HIGH);

    /* if (gsm.readSMS(smsbuffer, 160, n, 20)) {
      Serial.println(n);
      Serial.println(smsbuffer);
    } */

    Serial.println("-------------------------------------------------------------------------------------");
    acessaHttp();

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

void acessaHttp() {
  int numdata;
  char msg[50];
  
  if (inet.attachGPRS("tim.br", "tim", "tim")){
    Serial.println(F("status=Conectado..."));

    gsm.SimpleWriteln("AT+CIFSR");
    delay(5000);
    gsm.WhileSimpleRead();

    if(inet.httpPOST("www.eduaraujodev.com", 80, "/teste/add.php", "MSG_Texto1=teste", msg, 50)) {
      Serial.println(F("Dados enviados"));
      delay(5000);
    } else {
      Serial.println(F("Dados não enviados"));
    }
  } else {
    Serial.println(F("status=Nao conectado !!"));
  }
}
