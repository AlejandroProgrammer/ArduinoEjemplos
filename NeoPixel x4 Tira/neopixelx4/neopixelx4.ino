#include <Adafruit_NeoPixel.h>
#define conector 6

Adafruit_NeoPixel neoP = Adafruit_NeoPixel(16, conector, NEO_GRB + NEO_KHZ800);
 
void setup() {
  neoP.begin();
  neoP.setBrightness(30);
  neoP.show();
}
 
void loop() {
  colorWipe();
  cambiarColorLoop(); //No tiene fín.
}

void colorWipe() {
  for(uint16_t i=0; i< neoP.numPixels(); i++) {
      neoP.setPixelColor(i, neoP.Color(random(0, 255),random(0, 255),random(0, 255)));
      neoP.show();
  }
}

void cambiarColorLoop(){
  for(int i = 0; i < 10; i--){
    uint16_t x = random(0, 16);
    neoP.setPixelColor(x, neoP.Color(random(0, 255),random(0, 255),random(0, 255)));
    neoP.show();
  }
}
