#include "MyBlinker.h"

#define PIXEL_PIN 2
#define NUM_PIXELS 2

PixelBlinker pixel(PIXEL_PIN, NUM_PIXELS);

PixelColor blue(0, 0, 255);
PixelColor green(0, 255, 0);
PixelColor red(255, 0, 0);

void finished(){
  pixel.setPixel(1);
  pixel.setPixelColor(blue);
  pixel.blink(500, 500, 3, 1000, 2, NULL);
}

void setup(){
  pixel.setPixelColor(green);
  pixel.blink(200, 500, 3, 1000, 2, finished);
}

void loop(){
  pixel.update();
}