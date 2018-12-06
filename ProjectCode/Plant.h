#ifndef Plant_h
#define Plant_h

// the #include statment and code go here...
#include "Arduino.h"
//#include "OLEDDisplayer.h"

class Plant
{
public:
  Plant();
  Plant(String type,
  	int plantNum,
  	int soilMoisturePin,
    int soilPower,
    int lightSensorPin,
    int tempSensorPin);

  boolean needsWater();
  void giveWater();
  void hourPassed();
  void resetHours();
  void displayInfo();
  void clearDisplay();
  int getPlantNum();
  int getSoilSensorValue();
  int getLightSensorValue();
  int getTempSensorValue();
  unsigned long getHoursSinceWater();
private:
  //OLEDDisplayer *displayer;
  String type;
  int plantNum;
  int soilSensorValue;
  int lightSensorValue;
  int tempSensorValue;
  unsigned long hoursSinceWater;
  int soilMoisturePin;
  int soilPower;
  int lightSensorPin;
  int tempSensorPin;
  unsigned long minimumWaterHours;
  int readSoil();
  int readLight();
  int readTemp();
};

#endif
