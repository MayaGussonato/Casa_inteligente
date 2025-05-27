byte led = 10, pir = 11, buzzer = 2;

 

void setup()
{
  pinMode(led, OUTPUT);
  pinMode(led, INPUT);
  pinMode(buzzer, OUTPUT);
}

void loop()
{
  
  byte movimento = digitalRead(pir);
  
  if(movimento){
        tone (buzzer, 261, 250);
        delay(250);
        noTone(buzzer);
        digitalWrite(led, HIGH);
        delay(500);
        
  }else{   
      digitalWrite(led, LOW);
  }

}