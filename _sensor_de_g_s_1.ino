byte led = 12;
byte som = 13;
int sensorGas = A5; 		 
int valorSensorGas = 0;

void setup() {
  Serial.begin(9600);	
  pinMode (sensorGas, INPUT);
  pinMode (led, OUTPUT);
}
  void loop() 
{	
  valorSensorGas = analogRead(sensorGas);

  if (valorSensorGas >250) 					
  {				
    
    digitalWrite(led, HIGH);							
    tone(som, 1500);
    delay(500);
    noTone (som);
    delay(500);
  }
  else 	
  {
    digitalWrite(led, LOW);		
  }
}
