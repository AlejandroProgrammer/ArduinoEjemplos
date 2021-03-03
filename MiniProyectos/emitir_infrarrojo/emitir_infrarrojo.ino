#include <IRremote.h>
#include <IRremoteInt.h>
 
IRsend irsend;
int botonPrender = 4;
int botonApagar = 5;
 
void setup() {
  Serial.begin(9600);
  pinMode(botonPrender,INPUT);
  pinMode(botonApagar,INPUT);
}
 
void loop() {
  if(digitalRead(botonPrender) == HIGH)
  {
    irsend.sendNEC(0xF7C03F,32);
    Serial.println("Encendiendo Tira LED");
    delay(100);
  }else if(digitalRead(botonApagar) == HIGH){
    irsend.sendNEC(0xF740BF,32);
    Serial.println("Apagando Tira LED");
    delay(100);
  }
}
