//Prints the date and file
void printtimedatefile()
{
  Serial.println(__DATE__);
  Serial.println(__TIME__);
  Serial.println(__FILE__);
}


// --- ADS Libraries and Declarations
#include <Wire.h>
#include <EMF_METER.h> //ADS library is inside the EMF_METER library


// --- TFT Libraries and Declarations
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#ifdef ESP8266
#define STMPE_CS 16
#define TFT_CS   0
#define TFT_DC   15
#define SD_CS    2
#endif
#if defined (__AVR_ATmega32U4__) || defined(ARDUINO_SAMD_FEATHER_M0) || defined (__AVR_ATmega328P__) || defined(ARDUINO_SAMD_ZERO) || defined(__SAMD51__) || defined(__SAM3X8E__)
#define STMPE_CS 6
#define TFT_CS   9
#define TFT_DC   10
#define SD_CS    5
#endif
