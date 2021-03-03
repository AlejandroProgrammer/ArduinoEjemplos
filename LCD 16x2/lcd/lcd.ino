#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  
  lcd.begin(16, 2);
  
}

void loop() {
  
  for(int i = 1; i<=10; i++){
    
    lcd.print(i); 
    delay(500);
    lcd.clear();
    
  }
}