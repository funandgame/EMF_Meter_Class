Adafruit_ADS1115 ads; //Sets up the Analog to Digital converter
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC); //Sets up the TFT screen

//Declaring the EMF_METER object
EMF_METER EMF (ads, tft);



void setup() {
  Serial.begin(115200);
  printtimedatefile();
  delay(10);
  
  Serial.println("FeatherWing TFT Test!");
  
  //set up the device
  EMF.ADSsetup(); 
  tft.begin();
  tft.fillScreen(ILI9341_WHITE);
  tft.fillScreen(ILI9341_BLACK);
  
  Serial.println();
  Serial.print("width: "); Serial.print (tft.width());
  Serial.print("height: "); Serial.print (tft.height());
}


void loop(void) {
  //Get the values of the instantaneous EMFs on both channels
  Serial.print("EMF 1: "); Serial.println(EMF.getEMF(EMF_METER::CHAN_ONE));
  Serial.print("EMF 2: "); Serial.println(EMF.getEMF(EMF_METER::CHAN_TWO));

  //Get the min and max values of the voltages on both channels
  EMF.runmaxmin();
  Serial.print("Max EMF 1: "); Serial.println(EMF.getMax(EMF_METER::CHAN_ONE));
  Serial.print("Max EMF 2: "); Serial.println(EMF.getMax(EMF_METER::CHAN_TWO));
  Serial.print("Min EMF 1: "); Serial.println(EMF.getMin(EMF_METER::CHAN_ONE));
  Serial.print("Min EMF 2: "); Serial.println(EMF.getMin(EMF_METER::CHAN_TWO));
  Serial.println();

  //Graph the data on the TFT
  EMF.makeGrid();
  EMF.plotData(ILI9341_RED,ILI9341_BLUE); //Graph function with parameters of two colors
}
