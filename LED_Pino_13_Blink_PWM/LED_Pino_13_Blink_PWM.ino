int led = 3;

void setup() {
  // Ajustado pino 3 (analogico) para saída
  pinMode(led, OUTPUT);
}

void loop() {
  int i;
  int n;

  // Acende a luz lentamente
  for(i=0;i<255;i++){
    analogWrite(led,i);
    delay(10);
  }

  // Apaga a luz lentamente
  for(n=255;n>0;n--){
    analogWrite(led,n);
    delay(10);
  }
}
