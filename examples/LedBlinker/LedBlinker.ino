#include "MyBlinker.h"

#define LED_PIN 3

LedBlinker led(LED_PIN);

void setup(){
  led.blink(500, 100, 3, 1000, 2, NULL);
}

void loop(){
  led.update();
}
