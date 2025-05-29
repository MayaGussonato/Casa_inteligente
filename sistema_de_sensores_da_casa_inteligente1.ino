#include <Servo.h>

Servo motor1;

const byte botao1 = 3;
const byte botao2 = 4;
const byte led = 12;                  
const byte som = 13;               
const int pinoSensorGas = A5;
const byte pinoSensorMovimento = 10;
const byte ledMovimento = 8;

void setup() {
  motor1.attach(6);
  motor1.write(0);

  pinMode(botao1, INPUT);
  pinMode(botao2, INPUT);
  pinMode(pinoSensorGas, INPUT);
  pinMode(led, OUTPUT);
  pinMode(som, OUTPUT);
  pinMode(pinoSensorMovimento, INPUT);
  pinMode(ledMovimento, OUTPUT);

  Serial.begin(9600);

  digitalWrite(led, HIGH);
  delay(2000);
  digitalWrite(led, LOW);
}
//funcionamento do motor servo com botão
void loop() {
  if (digitalRead(botao1) == HIGH) {
    motor1.write(90);
    delay(50);
  }

  if (digitalRead(botao2) == HIGH) {
    motor1.write(0);
    delay(50);
  }

  verificarGas();
  sensorMovimento();
}

// funcionamento do sensor de gás
void verificarGas() {
  int valorSensorGas = analogRead(pinoSensorGas);
  Serial.print("Valor do sensor de gás: ");
  Serial.println(valorSensorGas);

  if (valorSensorGas > 250) {
    digitalWrite(led, HIGH);     
    tone(som, 1500);             
    delay(500);
    noTone(som);
    delay(500);
  } else {
    digitalWrite(led, LOW);     
    noTone(som);
  }
}

//Funcionamento do sensor de movimento
void sensorMovimento() {
  if (digitalRead(pinoSensorMovimento) == HIGH) {
    digitalWrite(ledMovimento, HIGH);
  } else {
    digitalWrite(ledMovimento, LOW);
  }
}
