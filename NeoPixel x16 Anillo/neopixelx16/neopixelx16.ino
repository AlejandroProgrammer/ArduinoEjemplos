#include <Adafruit_NeoPixel.h>
#define conector 6

Adafruit_NeoPixel neoP = Adafruit_NeoPixel(16, conector, NEO_GRB + NEO_KHZ800);
 
void setup() {
  neoP.begin();
  neoP.setBrightness(30);
  neoP.show();
}
 
void loop() {
  colorWipe(1000);
}

void colorWipe(uint8_t wait) {
  for(uint16_t i=0; i<neoP.numPixels(); i++) {
      neoP.setPixelColor(i, neoP.Color(random(0, 255),random(0, 255),random(0, 255)));
      neoP.show();
      delay(wait);
  }
}
