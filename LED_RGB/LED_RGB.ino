void setup() {
  // Ajustado as portas digitais 3, 5 e 6 como saída
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop() {
  // Acendera cada cor do led rgb por vez
  analogWrite(3, 255);
  delay(1000);
  analogWrite(3, 0);
  
  analogWrite(5, 255);
  delay(1000);
  analogWrite(5, 0);
  
  analogWrite(6, 255);
  delay(1000);
  analogWrite(6, 0);  
}
