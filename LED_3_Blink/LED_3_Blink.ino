void setup() {
  // Ajustado as portas digitais 2, 3 e 4 como saída
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop() {
  // Acende o led conectado na porta 2 e apaga
  digitalWrite(2, HIGH);
  delay(1000);
  digitalWrite(2, LOW);

  // Acende o led conectado na porta 3 e apaga
  digitalWrite(3, HIGH);
  delay(1000);
  digitalWrite(3, LOW);

  // Acende o led conectado na porta 4 e apaga
  digitalWrite(4, HIGH);
  delay(1000);
  digitalWrite(4, LOW);
}
