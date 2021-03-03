//---------Librería------------

#include <Keyboard.h>

//-----------------------------


//-----------Joystick----------

const int x = A0;
const int y = A1;

//-----------------------------


//---------Botones-------------

const int boton_joystick_pin = 8;
const int boton_derecha_pin = 3;
const int boton_arriba_pin = 2;
const int boton_izquierda_pin = 5;
const int boton_abajo_pin = 4;

//-----------------------------


//-------Estado-Botones--------

int boton_joystick_estado = HIGH;
int boton_derecha_estado = HIGH;
int boton_arriba_estado = HIGH;
int boton_izquierda_estado = HIGH;
int boton_abajo_estado = HIGH;

//-----------------------------


//-------Estado-Joystick--------

int joystick_x_estado = 0;
int joystick_y_estado = 0;

//------------------------------


void setup() {
  
  Keyboard.begin();
  Serial.begin(9600);
  pinMode(x, INPUT);
  pinMode(y, INPUT);
  pinMode(boton_joystick_pin, INPUT_PULLUP);
  pinMode(boton_derecha_pin, INPUT_PULLUP);
  pinMode(boton_arriba_pin, INPUT_PULLUP);
  pinMode(boton_izquierda_pin, INPUT_PULLUP);
  pinMode(boton_abajo_pin, INPUT_PULLUP);
  
}

void loop() {
  
  static unsigned long tiempo = 0;
  if(millis() - tiempo > 50)
  {
    int status;

    status = digitalRead(boton_joystick_pin);
    if(status != boton_joystick_estado)
    {
      if(status == LOW)
      {
        Keyboard.press('p');
        Keyboard.release('p');
      }
      boton_joystick_estado = status;
    }

    status = digitalRead(boton_derecha_pin);
    if(status != boton_derecha_estado)
    {
      if(status == LOW)
      {
        Keyboard.press('5');
        Keyboard.release('5');
      }
      boton_derecha_estado = status;
    }
    
    status = digitalRead(boton_arriba_pin);
    if(status != boton_arriba_estado)
    {
      if(status == LOW)
      {
        Keyboard.press('a');
        Keyboard.release('a');
      }
      boton_arriba_estado = status;
    }
    
    status = digitalRead(boton_izquierda_pin);
    if(status != boton_izquierda_estado)
    {
      if(status == LOW)
      {
        //do something
        Keyboard.press('1');
        Keyboard.release('1');
      }
      boton_izquierda_estado = status;
    }
    
    status = digitalRead(boton_abajo_pin);
    if(status != boton_abajo_estado)
    {
      if(status == LOW)
      {
        Keyboard.press(' ');
        Keyboard.release(' ');
      }
      boton_abajo_estado = status;
    }

    //--------------------------------------

    
    int analog_estado;

    //Joystick eje x -----------------------
    
    analog_estado = obtener_joystick_estado(x);
    if(analog_estado != joystick_x_estado)
    {
      if(joystick_x_estado == 0)
      {
        if(analog_estado == 1)
        {
          Keyboard.release(KEY_LEFT_ARROW);
          Keyboard.press(KEY_RIGHT_ARROW);
        }
        else
        {
          Keyboard.press(KEY_LEFT_ARROW);
          Keyboard.release(KEY_RIGHT_ARROW);
        }
      }
      else
      {
        Keyboard.release(KEY_LEFT_ARROW);
        Keyboard.release(KEY_RIGHT_ARROW);
      }
      joystick_x_estado = analog_estado;
    }

    //--------------------------------------


    //Joystick eje Y -----------------------
 
    analog_estado = obtener_joystick_estado(y);
  
    if(analog_estado != joystick_y_estado)
    {
      if(joystick_y_estado == 0)
      {
        if(analog_estado == 1)
        {
          Keyboard.release(KEY_DOWN_ARROW);
          Keyboard.press(KEY_UP_ARROW);
        }
        else
        {
          Keyboard.press(KEY_DOWN_ARROW);
          Keyboard.release(KEY_UP_ARROW);
        }
      }
      else
      {
        Keyboard.release(KEY_UP_ARROW);
        Keyboard.release(KEY_DOWN_ARROW);
      }
      joystick_y_estado = analog_estado;
    }

    //--------------------------------------

  
  }
}

int obtener_joystick_estado(int pin)
{
  
  int joystick_estado = analogRead(pin);
  if(joystick_estado > 1000)
    joystick_estado = 1;
  else if(joystick_estado < 50)
    joystick_estado = -1;
  else
    joystick_estado = 0;
  return joystick_estado;
  
}
