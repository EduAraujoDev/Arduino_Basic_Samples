int a = 3, b = 4, c = 5, d = 6, e = 7, f = 8, g = 9;

int num[10][7] = {
  {a, b, c, d, e, f},
  {b, c,},
  {a, b, e, d, g},
  {a, b, c, d, g},
  {b, c, f, g},
  {a, c, d, f, g},
  {a, c, d, e, f, g},
  {a, b, c},
  {a, b, c, d, e, f, g},
  {a, b, c, f, g},
};

void setup() {
  // Ajustado os pinos digitais 3, 4, 5, 6, 7, 8 e 9 como saida
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
}

void loop() {
  // Irá acender os segmentos criando números de zero até nove
  for (int i = 0; i < 10; i++) {
    apaga();
    numero(i);
    delay(1000);
  }
}

void apaga() {
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void numero(int n) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(num[n][i], LOW);
  }
}

