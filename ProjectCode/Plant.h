#ifndef Plant_h
#define Plant_h

// the #include statment and code go here...
#include "Arduino.h"

class Plant
{
public:
  Plant();
  Plant(String type,
	int position,
	int actuatorPin,
	int rotatePin,
	int soilMoisturePin,
  int soilPower);

  boolean needsWater();
  void giveWater();
  void hourPassed();
private:
  String type;
  int position;
  int actuatorPin;
  int rotatePin;
  int soilMoisturePin;
  int soilPower;
  unsigned long hoursSinceWater;
  unsigned long minimumWaterHours;
  //void rotateToPosition();
  //void returnToDefaultPosition();
  int readSoil();
};

#endif
