#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
 
const int pinCE = 9;
const int pinCSN = 10;
RF24 radio(pinCE, pinCSN);

const uint64_t pipe = 0xE8E8F0F0E1LL;
 
int mensaje[2];

int valorX = 0;
int valorY = 0;
int pinJX = A0;
int pinJY = A1;

int grados1 = 90;
int grados2 = 90;
 
void setup()
{
   Serial.begin(9600);
   radio.begin();
   radio.openWritingPipe(pipe);
}
 
void loop()
{
  valorX = analogRead ( pinJX);
  valorY = analogRead ( pinJY);

  if ( (valorX > 550 ) && (valorX <= 1023) )
  {
    grados1 = grados1 + 5;
  }
  
  if ( (valorX >= 0 ) && (valorX < 480 ))
  {
    grados1 = grados1 - 5;
  }
 
  if ( grados1 >= 180)
  {
    grados1 = 180;
  }

  if ( grados1 <= 0)
  {
    grados1 = 0;
  }
 
 
  if ( (valorY > 550 ) && (valorY <= 1023) )
  {
    grados2 = grados2 + 5;
  }
 
 
  if ( (valorY >= 0 ) && (valorY < 480) )
  {
    grados2 = grados2 - 5;
  }
 
  if ( grados2 >= 180)
  {
    grados2 = 180;
  }

  if ( grados2 <= 0)
  {
    grados2 = 0;
  }

  Serial.println(grados1);
  Serial.println(grados2);
  
  mensaje[0]= grados1;
  mensaje[1] = grados2; 
  radio.write(mensaje, sizeof(mensaje));

  delay(20);
}
