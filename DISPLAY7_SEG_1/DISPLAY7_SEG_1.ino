void setup() {
  // Ajustado o pino digitais 2 como saida
  pinMode(2, OUTPUT);
}

void loop() {
  // Irá acender e apagar o segmento A 
  digitalWrite(2,HIGH);
  delay(1000);
  
  digitalWrite(2,LOW);
  delay(1000);
}
