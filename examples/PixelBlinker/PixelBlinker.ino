#include "MyBlinker.h"

#define PIXEL_PIN 2
#define NUM_PIXELS 1

PixelBlinker pixel(PIXEL_PIN, NUM_PIXELS);

PixelColor blue(0, 0, 255);
PixelColor green(0, 255, 0);
PixelColor red(255, 0, 0);

void setup(){
  pixel.setPixelColor(red);
  pixel.blink(500, 100, 3, 1000, 2, NULL);
}

void loop(){
  pixel.update();
}
