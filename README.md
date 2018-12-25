# EMF_METER Class

## Purpose:
This class is meant to use Adafruit's ADS_1x15, GFX, and other visual libraries to enable the EMF Meter to measure the voltage in a coil induced by moving magnets and graph the data on a TFT screen.

## Necessary preparations:
To ensure that this class is successful, make sure you have installed the Wire.h, Adafruit_ADS1015.h, Adafruit_GFX.h, and Adafruit_ILI9341.h libraries.
Due to a lack of a "god" command in the ADS library, the code will NOT work if you re-include its library in addition to including the EMF_METER library in your test-code (see example code in repository).
