#include "Plant.h"

Plant::Plant() { }

Plant::Plant(String type, int plantNum, int soilMoisturePin, int soilPower,
	     int lightSensorPin, int tempSensorPin) {
  
  // Check type of plant and use it to calculate minimumWaterTime
  if (type == "cactus") {
    this->type = "cactus";
    // 1 Week Minimum Water Time
    this->minimumWaterHours = 24 * 7;
  } else if (type == "flower") {
    this->type = "flower";
    // 1 Day Minimum Water Time                              
    this->minimumWaterHours = 24;
  } else {
    this->type = "default";
    // 3 Day Minimum Water Time                              
    this->minimumWaterHours = 24 * 3;
  }
  this->displayer = OLEDDisplayer(14);
  this->plantNum = plantNum;
  this->soilMoisturePin = soilMoisturePin;
  this->soilPower = soilPower;
  this->lightSensorPin = lightSensorPin;
  this->tempSensorPin = tempSensorPin;
  this->hoursSinceWater = 0;
  this->soilSensorValue = 0;
  this->lightSensorValue = 0;
  this->tempSensorValue = 0;
  pinMode(soilMoisturePin, INPUT);
}

boolean Plant::needsWater() {
  soilSensorValue = readSoil();
  lightSensorValue = readLight();;
  tempSensorValue = readTemp();
  boolean soilTooDry = (soilSensorValue < 600);
  boolean hourThresholdPassed = (hoursSinceWater > minimumWaterHours);
  displayInfo();
  //need to test this value
  if(soilTooDry){
    Serial.println("Soil Too Dry!");
    return true;
  }
  if (hourThresholdPassed) {
    Serial.println("Hour Threshold Passed!");
    return true;
  }
  return false;
}

void Plant::displayInfo() {
    displayer.displayData(plantNum, soilSensorValue, lightSensorValue, tempSensorValue, hoursSinceWater);
}

void Plant::resetHours() {
  hoursSinceWater = 0;
}

void Plant::hourPassed() {
  hoursSinceWater++;
}

int Plant::readSoil(){
  digitalWrite(soilPower, HIGH);
  delay(10);
  int val = analogRead(soilMoisturePin);
  digitalWrite(soilPower, LOW);
  return val;
}

int Plant::readLight() {
  int val = analogRead(lightSensorPin) * 100 / 1023;
  return val;
}

int Plant::readTemp() {
  int val = ((analogRead(tempSensorPin) * 5000 / 1023) - 500) / 10;
  val = (((val * 1.8) + 32) * -1) + 25;
  return val;
}
