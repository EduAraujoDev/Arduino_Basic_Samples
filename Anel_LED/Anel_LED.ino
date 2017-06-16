#include <Adafruit_NeoPixel.h>

#define PIN 7
#define NUMPIXELS 24

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin();
  pixels.setBrightness(100);
}

void loop() {
  ledOn(255, 0, 0);
  ledOff();

  ledOn(0, 0, 255);
  ledOff();

  ledOn(0, 128, 0);
  ledOff();

  ledOn(255, 165, 0);
  ledOff();
}

void ledOn(int num1, int num2, int num3) {
  for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, num1, num2, num3);
    pixels.show();

    delay(10);
  }  
}

void ledOff() {
  for(int n=NUMPIXELS;n>=0;n--){
    pixels.setPixelColor(n, 0, 0, 0);
    pixels.show();

    delay(50);
  }
}
