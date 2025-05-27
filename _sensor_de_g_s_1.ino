int led = 12;
int buzzer = 13;
int sensor = A5;

void setup() {
  pinMode(sensor, INPUT);
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  int valor = analogRead(sensor);

  if (valor > 250) {
    digitalWrite(led, HIGH);
    tone(buzzer, 1500);
    delay(500);
    noTone(buzzer);
    delay(500);
  } else {
    digitalWrite(led, LOW);
  }
}
