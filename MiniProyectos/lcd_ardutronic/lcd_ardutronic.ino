#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);



void setup() {
  // put your setup code here, to run once:
  lcd.init();
  lcd.backlight();
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 1; i=9999; i++){
  lcd.print("Ingresa a ---->");  
  lcd.setCursor(1, 1);
  lcd.print("a");
  delay(500);
  lcd.print("r");
  delay(500);
  lcd.print("d");
  delay(500);
  lcd.print("u");
  delay(500);
  lcd.print("t");
  delay(500);
  lcd.print("r");
  delay(500);
  lcd.print("o");
  delay(500);
  lcd.print("n");
  delay(500);
  lcd.print("i");
  delay(500);
  lcd.print("c");
  delay(500);
  lcd.print(".");
  delay(500);
  lcd.print("x");
  delay(500);
  lcd.print("y");
  delay(500);
  lcd.print("z");
  delay(1000);
  lcd.clear();
  }
}
