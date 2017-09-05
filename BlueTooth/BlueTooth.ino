void setup() {
  Serial.begin(9600);

  pinMode(13, OUTPUT);
}
void loop() {
  if (Serial.available() >= 2) {
    int key = Serial.read();
    int val = Serial.read();

    digitalWrite(key, val);
  }
}
