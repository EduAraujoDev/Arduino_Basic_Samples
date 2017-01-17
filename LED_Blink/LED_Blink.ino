void setup() {
  // Ajustado porta digital 2 como saída
  pinMode(2, OUTPUT);
}

void loop() {
  // Acende o led conectado na porta 2
  digitalWrite(2, HIGH);
  delay(1000);

  // Apaga o led conectado na porta 2
  digitalWrite(2, LOW);
  delay(1000);
}
