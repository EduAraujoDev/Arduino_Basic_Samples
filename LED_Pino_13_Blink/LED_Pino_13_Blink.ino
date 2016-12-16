void setup() {
  // Ajustado pino 13 para saída
  // LED_BUILTIN - Outra forma de identificar o led integrado no pino 13
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // Acende o led integrado e aguarda 1 segundo
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);

  // Apada o led integrado e aguarda 1 segundo
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}
