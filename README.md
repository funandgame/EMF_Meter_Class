# EMF_METER Class

## Purpose:
This class is meant to enable users to measure and graph the voltage induced in wire coils due to moving magnetic fields.

## What it provides:
With the EMF_METER class, you can measure the instantaneous, minimum, and maximum voltages over time. You can also select which channel you take data from (channel 1 or channel 2). You can also customize the colors that each graph on the TFT screen appears as.

## Necessary preparations:
To ensure that this class is successful, make sure you have installed the Wire.h, Adafruit_ADS1015.h, Adafruit_GFX.h, and Adafruit_ILI9341.h libraries.
Due to a lack of a "god" command in the ADS library, the code will NOT work if you re-include its library in addition to including the EMF_METER library in your test-code (see example code in repository).
