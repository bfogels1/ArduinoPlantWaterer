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
  	int actuatorPin,
  	int rotatePin,
  	int soilMoisturePin,
    int soilPower,
    int lightSensorPin,
    int tempSensorPin);

  boolean needsWater();
  void giveWater();
  void hourPassed();
private:
  OLEDDisplayer displayer;
  String type;
  int plantNum;
  int soilSensorValue;
  int lightSensorValue;
  int tempSensorValue;
  int actuatorPin;
  int rotatePin;
  int soilMoisturePin;
  int soilPower;
  int lightSensorPin;
  int tempSensorPin;
  unsigned long hoursSinceWater;
  unsigned long minimumWaterHours;
  //void rotateToPosition();
  //void returnToDefaultPosition();
  int readSoil();
  int readLight();
  int readTemp();
};

#endif
