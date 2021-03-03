#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#include <Servo.h>

Servo servoMotor1;
Servo servoMotor2;

const int pinCE = 9;
const int pinCSN = 10;
RF24 radio(pinCE, pinCSN);

const uint64_t pipe = 0xE8E8F0F0E1LL;
 
int mensaje[2];

void setup()
{
   radio.begin();
   Serial.begin(9600);
   radio.openReadingPipe(1, pipe);
   radio.startListening();
   servoMotor1.attach(3);
   servoMotor2.attach(4);
}
 
void loop()
{
   if (radio.available() > 0)
   {    
      radio.read(mensaje, sizeof mensaje);
      Serial.print("Dato0= " );
      Serial.print(mensaje[0]);
      Serial.print("Dato1= " );
      Serial.print(mensaje[1]);
      Serial.println("");
      if(mensaje[0] != ' ' || mensaje[1] != ' '){
        servoMotor1.write(mensaje[0]);
        servoMotor2.write(mensaje[1]);
      }
   }
}
