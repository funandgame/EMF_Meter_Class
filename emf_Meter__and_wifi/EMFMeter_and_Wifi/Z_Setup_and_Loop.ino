Adafruit_ADS1115 ads; //Sets up the Analog to Digital converter
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC); //Sets up the TFT screen

//Declaring the EMF_METER object
EMF_METER EMF (ads, tft);

double instEMF,minEMF,maxEMF;


WiFiClient espClient;
PubSubClient client(espClient);
//PI TOP INFO
//HOME WIFI
char* ssid = "kvlan2017";
char* password = "covada6164";
char* mqtt_server = "192.168.1.107";

//ANNAPURNA HOTSPOT
/*char* ssid = "Greybae";
char* password = "aphotspotpass";
char* mqtt_server = "172.20.10.6";*/

//KUMAR HOTSPOT
/*char* ssid = "KV HotspotX";
char* password = "kvpass123";
char* mqtt_server = "172.20.10.6";*/

//SID HOTSPOT
/*
char* ssid = "SidMobHotspot";
char* password = "sid12345";
char* mqtt_server = "192.168.43.213";*/

//RPI2July2019 INFO
//HOME WIFI
/*char* ssid = "kvlan2017";
char* password = "covada6164";
char* mqtt_server = "192.168.1.130";*/
//SID HOTSPOT
/*char* ssid = "SidMobHotspot";
char* password = "sid12345";
char* mqtt_server = "192.168.43.176";
*/
//RPI4 (RPIZeroJuly2019)
//HOME WIFI
/*char* ssid = "kvlan2017";
char* password = "covada6164";
char* mqtt_server = "192.168.1.122";
*/

//HOME WIFI
/*char* ssid = "kvlan2017";
char* password = "covada6164";
char* mqtt_server = "192.168.1.130";
*/

//INSTANTIATE
gngWiFi WIFI_ONE(espClient,client,ssid,password,mqtt_server);


void setup() {
  Serial.begin(115200);
  WIFI_ONE.wifiSetup();
  EMF.ADSsetup();
  tft.begin();
  tft.fillScreen(ILI9341_WHITE);
  tft.fillScreen(ILI9341_BLACK);
}

void loop() {
  instEMF=EMF.getEMF(EMF_METER::CHAN_ONE);
  
  EMF.runmaxmin();
  
  minEMF=EMF.getMin(EMF_METER::CHAN_ONE);
  maxEMF=EMF.getMax(EMF_METER::CHAN_ONE);
  Serial.print("Min: ");Serial.println(minEMF);
  Serial.print("Max: ");Serial.println(maxEMF);
  EMF.makeGrid();
  EMF.plotData(ILI9341_RED,ILI9341_BLUE,512.00); //Graph function with parameters of two colors
  
  String DATA = (String)instEMF+","+(String)minEMF+","+(String)maxEMF;
  //WIFI_ONE.publishDataString(DATA, gngWiFi::D_SET4);
  WIFI_ONE.publishDataString(DATA,"/test6");//
  //WIFI_ONE.publishDataString(DATA,"/test7");//
  delay(10);
}
