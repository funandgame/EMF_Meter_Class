
#include<EMF_METER.h>

 void EMF_METER :: ADSsetup()

{
  Serial.println("Hello!");

  Serial.println("Getting differential reading from AIN0 (P) and AIN1 (N)");
  Serial.println("ADC Range: +/- 6.144V (1 bit = 3mV/ADS1015, 0.1875mV/ADS1115)");

  ads1.begin();
  ads1.setGain(GAIN_FOUR);

}
EMF_METER::EMF_METER(Adafruit_ADS1115 ads3, Adafruit_ILI9341& tft3): ads1(ads3), tft1(tft3) {
  _emf = 0;
  _emf2 = 0;
};


float EMF_METER :: getEMF(int i)
{

  // Be sure to update this value based on the IC and the gain settings!  

  float   multiplier = 0.03125F; // for GAIN_FOUR, F=floating point


  _results =  ads1.readADC_Differential_0_1();
  _results2 =  ads1.readADC_Differential_2_3();
  _emf = (float)(_results * multiplier);
  _emf2 = (float)(_results2 * multiplier);
  if (i == CHAN_ONE)return _emf;
  else if (i == CHAN_TWO) return _emf2;
}

void EMF_METER :: runmaxmin()
{
  if (count < maxIter) {
    count++;
    if (_emf > _maxEMF) {
      _maxEMF = _emf;
    };
    if (_emf < _minEMF) {
      _minEMF = _emf;
    };

    if (_emf2 > _maxEMF2) {
      _maxEMF2 = _emf2;
    };
    if (_emf2 < _minEMF2) {
      _minEMF2 = _emf2;
    };
    Serial.println();
  }
  else {
    count = 0;
    _minEMF = 0.0;
    _maxEMF = 0.0;
    _minEMF2 = 0.0;
    _maxEMF2 = 0.0;
  }
}

double EMF_METER :: getMax(int i){
  if (i == CHAN_ONE)return _maxEMF;
  else if (i == CHAN_TWO) return _maxEMF2;
}

double EMF_METER :: getMin(int i){
  if (i == CHAN_ONE)return _minEMF;
  else if (i == CHAN_TWO) return _minEMF2;
}


void EMF_METER :: makeGrid(){
  tft1.drawLine(0,0,0,tft1.height(),ILI9341_WHITE);
  tft1.drawLine(0,tft1.height()/2,tft1.width(),tft1.height()/2, ILI9341_WHITE);
  for(uint16_t j=0;j<9;j++){
    for(uint16_t i=0;i<tft1.width();i+=5){
      tft1.drawPixel(i,j*40,ILI9341_WHITE);
    }
  }
  for(uint16_t i=0;i<8;i++){
      for(uint16_t j=0;j<tft1.height();j+=5){
        tft1.drawPixel(i*30,j,ILI9341_WHITE);
      }
    }
}

void EMF_METER :: plotData(uint16_t color1,uint16_t color2)
{
  ox = newox;
  oy = newoy;
  oy2 = newoy2;
  
  newoy = (uint16_t)(160 + scaleFactor *_emf);
  newoy2 = (uint16_t)(160 + scaleFactor *_emf2);
  newox+=xStep;
  tft1.drawLine(ox, oy, newox, newoy, color1);
  tft1.drawLine(ox, oy2, newox, newoy2, color2);
  if(ox>tft1.width()){
    tft1.fillScreen(ILI9341_BLACK);
    ox=0;
    oy=tft1.height()/2;
    oy2=tft1.height()/2;
    newox=0;
    newoy=tft1.height()/2;
    newoy2=tft1.height()/2;
  }
}