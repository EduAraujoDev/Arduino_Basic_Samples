int led = 13;
int botao = 2;
int press = 0;

void setup() {
  // Ajustado os pinos digitais: 13 como saida e 2 como entrada
  pinMode(led, OUTPUT);
  pinMode(botao, INPUT);
}

void loop() {
  // Ao apertar o botão o led ira acender
  press = digitalRead(botao);

  if( press == HIGH ) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
}
