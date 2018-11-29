#include "Arduino.h"
#include "Plant.h"

Plant::Plant() { }

Plant::Plant(String type, int position, int actuatorPin,
	     int rotatePin, int soilMoisturePin, int soilPower,
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

  this->position = position;
  this->actuatorPin = actuatorPin;
  this->rotatePin = rotatePin;
  this->soilMoisturePin = soilMoisturePin;
  this->soilPower = soilPower;
  this->lightSensorPin = lightSensorPin;
  this->tempSensorPin = tempSensorPin;
  this->hoursSinceWater = 0;
  pinMode(soilMoisturePin, INPUT);
}

boolean Plant::needsWater() {
  int soilSensorValue = readSoil();
  boolean soilTooDry = (soilSensorValue < 600);
  boolean hourThresholdPassed = (hoursSinceWater > minimumWaterHours);
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

void Plant::giveWater() {
    hoursSinceWater = 0;
    Serial.println("Watered");
}

// for rotating table
//void Plant::rotateToPosition()  {
//    Serial.println("Rotated");
//}
//
//void Plant::returnToDefaultPosition() {
//    Serial.println("Default Pos");
//}

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
