void setup() {
  // Ajustado pino 9 para saída
  pinMode(9, OUTPUT);
}

void loop() {
  // Emitir som
  digitalWrite(9, HIGH);
  delay(150);

  // Para de emitir som
  digitalWrite(9, LOW);
  delay(3000);
}
