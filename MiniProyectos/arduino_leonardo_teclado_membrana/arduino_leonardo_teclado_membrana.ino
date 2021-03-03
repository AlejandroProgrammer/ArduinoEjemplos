#include <Keypad.h>
#include <Keyboard.h>

const byte ROWS = 4;
const byte COLS = 3;
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

byte rowPins[ROWS] = {2, 3, 4, 5};
byte colPins[COLS] = {6,7,8};

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
  
  Serial.begin(9600);
  Keyboard.begin();
}
  
void loop(){
  char key = keypad.getKey();
   if (key){
    Serial.println(key);
    Keyboard.press(key);
    Keyboard.release(key);
  }
}
     
