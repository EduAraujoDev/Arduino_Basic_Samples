//#include "SIM900.h"
#include <SoftwareSerial.h>
#include "inetGSM.h"

InetGSM inet;

boolean started = false;

char smsbuffer[160];
char n[20];

byte valor;

void setup() {
  Serial.begin(9600);
  Serial.println(F("Testando GSM Shield SIM900"));

  if (gsm.begin(2400)) {
    Serial.println(F("\nstatus=READY"));
    started = true;
  } else {
    Serial.println(F("\nstatus=IDLE"));
  }
}

void loop() {
  if (started) {
    envia_GSM("teste");
    delay(2000);
  }
}

void envia_GSM(String texto) {
char temp_string[55];
  char msg[10];
  int numdata;
  if (inet.attachGPRS("timbrasil.br", "tim", "tim"))
    Serial.println(F("status=Conectado..."));
  else Serial.println(F("status=Nao conectado !!"));
  delay(100);
  String valor = "MSG_Texto1=" + texto;
  valor.toCharArray(temp_string, 55);
  numdata = inet.httpPOST("localhost.com", 80, "/add.php", temp_string, msg, 50);
  delay(5000);
}
