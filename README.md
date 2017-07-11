MyBlinker
===================
[![License](http://img.shields.io/:license-mit-blue.svg)](http://doge.mit-license.org)

A LED blinker library for  **Arduino** platform.
> **New:**  Now supports **NeoPixel** LEDs.


----------
Introduction
-------------

This library allows you to perform blinking operations with LEDs. Since it also operates with the NeoPixel LEDs, it depends on [Adafruit_NeoPixel Library](https://github.com/adafruit/Adafruit_NeoPixel), so you must have it installed in your environment in order for it to compile.

The library provides three classes:

#### LedBlinker
This class allows you to blink a regular LED.


#### PixelBlinker
This class allows you to blink a **NeoPixel** LED.

#### PixelColor
This class allows you to create a color object for the **PixelBlinker** class.


----------
LedBlinker
-------------------
#### The Class
The **LedBlinker** class allows you to create an instance of the LED you want to operate. The class constructor takes two values as arguments. The first argument is the number of the pin where the LED is connected. The second argument is optional and is used to set the polarity of the LED.

    LedBlinker myBlueLed(13);
    
    LedBlinker myBlueLed(13, COMMON_NEGATIVE);
    
    LedBlinker myBlueLed(13, COMMON_POSITIVE);

####  Methods
    
    /* Set at any time, the pin where the LED is connected. */
    myBlueLed.setPin(pin);

    /* Set at any time, the LED polarity. */
    /* Valid values: COMMON_NEGATIVE, COMMON_POSITIVE */
    myBlueLed.setPolarity(COMMON_NEGATIVE);

    /* Turn on the led. */
    myBlueLed.on();

    /* Turn off the led. */
    myBlueLed.off();

    /* Turn on the led for the time of (onDuration) then call the onFinished method. */
    myBlueLed.onUntil(onDuration, onFinished);

    /* Turn off the led for the time of (offDuration) then call the onFinished method. */
    myBlueLed.offUntil(offDuration, onFinished);

    /* Blink the LED */
    /* The LED will be on for the time of (onDuration). 
     * The LED will be off for the time of (offDuration). 
     * That blink will be repeated the number of times defined by (blinks).
     * Then a pause define by (pauseDuration). 
     * That sequency will repeat as many time as defined by (sequences).
     * At the end of all secuences the (onFinished) method will be called.
     */
     myBlueLed.blink(onDuration, offDuration, blinks, pauseDuration, sequences, onFinished);

     /* It is necessary to call this method in the program loop. */ 
     myBlueLed.update();

----------
PixelBlinker
-------------------
#### The Class
The **PixelBlinker** class allows you to create an instance of the **NeoPixel** LED you want to operate. The class constructor takes two values as arguments. The first argument is number of the pin where the **NeoPixel** LED is connected. The second argument is the amount of NeoPixels connected together.


    // Pin where a NeoPixel LED is connected.
    #define PIXEL_LED_PIN 2 
    // Number of NeoPixel LEDs connected.  
    #define PIXEL_LEDS    2   
    
    PixelBlinker myPixelLed(PIXEL_LED_PIN, PIXEL_LEDS);
    
    
####  Methods

    /* Set at any time, the pin where the LED is connected. */
    myPixelLed.setPin(pin);

    /* Set at any time, the amount of NeoPixel LEDs connected. */
    myPixelLed.setNumPixels(numPixels);


    /* Set at any time, the NeoPixel LED that you want to operate. */
    myPixelLed.setPixel(pixelId);

    /* Set at any time, the color of the NeoPixel LED. */
    /* The argument must be a PixelColor object. */
    myPixelLed.setPixelColor(pixelColor);

    /* Set at any time the NeoPixel LED brightness, 0 - 255 value. */
    myPixelLed.setPixelBrightness(pixelBrightness);
    
    /* Set at any time the NeoPixel LED brightness using percent value. */
    myPixelLed.setPixelBrightnessPercent(pixelBrightnessPercent);

    /* Turn on the NeoPixel LED. */
    myPixelLed.on();

    /* Turn on the NeoPixel LED by it's Id. */
    myPixelLed.on(pixelId);

    /* Turn on the NeoPixel LED by it's Id and set the color. */
    myPixelLed.on(pixelId, pixelColor);

    /* Turn on the NeoPixel LED by it's Id and set the color and brightness. */
    myPixelLed.on(pixelId, pixelColor, pixelBrightness);

    /* Turn off the NeoPixel LED. */
    myPixelLed.off();

    /* Turn off the NeoPixel LED by it's Id. */
    myPixelLed.off(pixelId);

    /* Turn on the NeoPixel LED for the time of (onDuration) then call the onFinished method. */
    myPixelLed.onUntil(onDuration, onFinished);

    /* Turn on the NeoPixel LED by it's Id, for the time of (onDuration) then call the onFinished method. */
    myPixelLed.onUntil(pixelId, onDuration, onFinished);

    /* Turn on the NeoPixel LED by it's Id, specifying the color, for the time of (onDuration) then call the onFinished method. */
    myPixelLed.onUntil(pixelId, pixelColor, onDuration, onFinished);

    /* Turn on the NeoPixel LED by it's Id, specifying the color and brightness, for the time of (onDuration) then call the onFinished method. */
    myPixelLed.onUntil(pixelId, pixelColor, pixelBrightness, onDuration, onFinished);

    /* Turn off the led for the time of (offDuration) then call the onFinished method. */
    myPixelLed.offUntil(offDuration, onFinished);

    /* Turn off the NeoPixel LED by it's Id, for the time of (onDuration) then call the onFinished method. */
    myPixelLed.offUntil(pixelId, offDuration, onFinished);

    /* Blink the LED */
    /* The LED will be on for the time of (onDuration). 
     * The LED will be off for the time of (offDuration). 
     * That blink will be repeated the number of times defined by (blinks).
     * Then a pause define by (pauseDuration). 
     * That sequency will repeat as many time as defined by (sequences).
     * At the end of all secuences the (onFinished) method will be called.
     */
     myPixelLed.blink(onDuration, offDuration, blinks, pauseDuration, sequences, onFinished);

     /* It is always necessary to call this method in the program loop. */ 
     myPixelLed.update();


----------
PixelColor
-------------------
#### The Class
The **PixelColor** class allows you to create a color object for the PixelBlinker.
    
    /* Red color object to be used by PixelBlinker */
    PixelColor red(255, 0, 0);
    
    /* Green color object to be used by PixelBlinker */
    PixelColor green(0, 255, 0);
   
    /* Blue color object to be used by PixelBlinker */
    PixelColor blue(0, 0, 255);

    /* Custom color object to be used by PixelBlinker */
    PixelColor myCustomColor(100, 100, 255);

> You may create as many color objects as you need with your custom color values.
    
####  Methods

> Normal use of this class does not require using any of these methods. 
    
    /* Returns the red value of the color. */
    myCustomColor.r();

    /* Returns the green value of the color. */
    myCustomColor.g();

    /* Returns the blue value of the color. */
    myCustomColor.b();

    /* Returns the packed value of the color in RGB format. */
    myCustomColor.getPackedRGB();

    /* Returns the packed value of the color in GRB format. */
    myCustomColor.getPackedGRB();

----------
Copyright
-------------------

MyBlinker is provided Copyright © 2017 under MIT License.