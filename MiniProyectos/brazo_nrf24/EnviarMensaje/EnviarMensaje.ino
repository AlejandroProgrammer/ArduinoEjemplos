#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
 
const int pinCE = 9;
const int pinCSN = 10;
RF24 radio(pinCE, pinCSN);

const uint64_t pipe = 0xE8E8F0F0E1LL;
 
int mensaje[2];

int valor1 = 0;
int valor2 = 0;
int valorIngresado = 0;
 
void setup()
{
   Serial.begin(9600);
   radio.begin();
   radio.openWritingPipe(pipe);
}
 
void loop()
{
  
   if(Serial.available() > 0){
     valorIngresado = Serial.parseInt();
     if(valorIngresado > 0){
      if(valorIngresado > 1000 && valorIngresado < 2000){
        valor1 = valorIngresado - 1000;
        Serial.println(valor1); 
      }else if(valorIngresado > 2000){
        valor2 = valorIngresado - 2000;
        Serial.println(valor2);
      }
     }
   }
      
   mensaje[0]= valor1;
   mensaje[1] = valor2;
   
   radio.write(mensaje, sizeof(mensaje));
   delay(1000);
}
