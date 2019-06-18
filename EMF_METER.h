#ifndef EMF_METER_h
#define EMF_METER_h

#include "Arduino.h"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <Adafruit_ADS1015.h>

class EMF_METER
{
  private:
    const static int maxIter = 80;
    Adafruit_ADS1115 ads1;
    Adafruit_ILI9341& tft1;
    int16_t _results;
    int16_t _results2;
    float _emf;  //library class-function-return type
    float _emf2;//library class-function-return type
    float _maxEMF, _minEMF; //library class-function-return type
    float _maxEMF2, _minEMF2; //library class-function-return type
    int count;

    float scaleFactor = tft1.height()/ 2048.00; //library class- constructor
    int xStep = 2; //library class- constructor

    uint16_t ox;
    uint16_t oy;
    uint16_t oy2;

    uint16_t newox;
    uint16_t newoy=tft1.height()/2;
    uint16_t newoy2=tft1.height()/2;

    int iteration = 0;


  public:
    const static int CHAN_ONE=1;
    const static int CHAN_TWO=2;
    EMF_METER(Adafruit_ADS1115 ads3, Adafruit_ILI9341& tft3);
    void ADSsetup();
    void runmaxmin();
    double getMax(int i);
    double getMin(int i);
    float getEMF(int i);
    void makeGrid();
    void plotData(uint16_t color1,uint16_t color2, float scale);
};
#endif