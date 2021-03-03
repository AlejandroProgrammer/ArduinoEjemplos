int led1 = 10;
int estadoBoton = 0;

void setup()
{
  pinMode(2, INPUT);
  pinMode(10, OUTPUT);
}

void loop()
{
  estadoBoton = digitalRead(2);
  if (estadoBoton == HIGH) {
    
    digitalWrite(led1, HIGH);
    
  } else {
    
    digitalWrite(led1, LOW);  
    
  }
  delay(10);
}
