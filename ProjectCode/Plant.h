#ifndef Plant_h
#define Plant_h

// the #include statment and code go here...
#include "Arduino.h"
#include "OLEDDisplayer.h"

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
private:
  OLEDDisplayer displayer;
  String type;
  int plantNum;
  int soilSensorValue;
  int lightSensorValue;
  int tempSensorValue;
  int soilMoisturePin;
  int soilPower;
  int lightSensorPin;
  int tempSensorPin;
  unsigned long hoursSinceWater;
  unsigned long minimumWaterHours;
  int readSoil();
  int readLight();
  int readTemp();
};

#endif
