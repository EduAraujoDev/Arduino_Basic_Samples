#include <SoftwareSerial.h>
#include <TinyGPS.h>

TinyGPS gps;
SoftwareSerial pin_gps(3, 4);

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  
  Serial.begin(9600);
  pin_gps.begin(9600);

  Serial.print("TinyGPS library v. "); Serial.println(TinyGPS::library_version());
  Serial.println("-------------------------------------------------------------------------------------");
}

void loop() {
  float flat, flon;
  bool newData = false;
  unsigned long chars;
  unsigned short sentences, failed;
  unsigned long age;

  digitalWrite(LED_BUILTIN, HIGH);

  for (unsigned long start = millis(); millis() - start < 1000;) {
    while (pin_gps.available()) {
      char c = pin_gps.read();

      if (gps.encode(c))
        newData = true;
    }
  }
  
  gps.stats(&chars, &sentences, &failed);
  Serial.print("    CHARS=");
  Serial.print(chars);
  Serial.print(" SENTENCES=");
  Serial.print(sentences);
  Serial.print(" CSUM ERR=");
  Serial.println(failed);

  if (newData) {
    gps.f_get_position(&flat, &flon, &age);
    Serial.print("    LAT=");
    Serial.print(flat == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flat, 6);
    Serial.print(" LON=");
    Serial.print(flon == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flon, 6);
    Serial.print(" SAT=");
    Serial.print(gps.satellites() == TinyGPS::GPS_INVALID_SATELLITES ? 0 : gps.satellites());
    Serial.print(" PREC=");
    Serial.println(gps.hdop() == TinyGPS::GPS_INVALID_HDOP ? 0 : gps.hdop());

    Serial.print("    URL: https://www.google.com.br/maps/@");
    Serial.print(flat == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flat, 6);
    Serial.print(",");
    Serial.print(flon == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flon, 6);
    Serial.println("15z");
  } else {
    Serial.println("ERRO");
  }

  Serial.println("-------------------------------------------------------------------------------------");

  digitalWrite(LED_BUILTIN, LOW);
  delay(5000);
}
