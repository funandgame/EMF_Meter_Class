# EMF_METER Class

## Purpose:
This class is meant to enable users to measure and graph the voltage induced in wire coils due to moving magnetic fields.

## What it provides:
With the EMF_METER class, you can measure the instantaneous, minimum, and maximum voltages over time. You can also select which channel you take data from (channel 1 or channel 2). You can also customize the colors that each graph on the TFT screen appears as.

## Necessary preparations:
To ensure that this class is successful, make sure you have installed the Wire.h, Adafruit_ADS1015.h, Adafruit_GFX.h, and Adafruit_ILI9341.h libraries.

Due to a lack of a "Include Guard" the Adafruit ADS library, the code will NOT work if you re-include its library in addition to including the EMF_METER library in your test-code (see example code in repository).

## Hardware
For the main micro controller, you can use the [Adafruit Feather 32u4](https://learn.adafruit.com/adafruit-feather-32u4-basic-proto). To make it WiFi compatible, you can also use the [Adafruit HUZZAH esp8266](https://learn.adafruit.com/adafruit-feather-huzzah-esp8266).

The chip used to measure and amplify the induced voltage is the [ADS1015/ADS1115](https://learn.adafruit.com/adafruit-4-channel-adc-breakouts?view=all) breakout board (12 bit vs 16 bit).

As for the screen, they use a [TFT 2.4" feather wing screen](https://learn.adafruit.com/adafruit-2-4-tft-touch-screen-featherwing).
