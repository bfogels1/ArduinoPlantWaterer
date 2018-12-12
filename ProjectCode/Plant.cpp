#include "Plant.h"

Plant::Plant() { }

Plant::Plant(String type, int plantNum, int soilMoisturePin, int soilPower,
	     int lightSensorPin, int tempSensorPin) {
  
  // Check type of plant and use it to calculate minimumWaterTime
  if (type == "cactus") {
    // 1 Week Minimum Water Time
    this->minimumWaterHours = 24 * 7;
  } else if (type == "flower") {
    // 1 Day Minimum Water Time                              
    this->minimumWaterHours = 24;
  } else {
    // 3 Day Minimum Water Time                       
    this->minimumWaterHours = 24 * 3;
    type = "default";  // Otherwise ensure that the type is default
  }
  // Set private fields
  this->type = type;
  this->plantNum = plantNum;
  this->soilMoisturePin = soilMoisturePin;
  this->soilPower = soilPower;
  this->lightSensorPin = lightSensorPin;
  this->tempSensorPin = tempSensorPin;
  this->hoursSinceWater = 0;
  this->soilSensorValue = 0;
  this->lightSensorValue = 0;
  this->tempSensorValue = 0;

  // Set pin modes
  pinMode(soilMoisturePin, INPUT);
  pinMode(lightSensorPin, INPUT);
  pinMode(tempSensorPin, INPUT);
  pinMode(soilPower, OUTPUT);
}

boolean Plant::needsWater() {
  // Read Sensor Values
  soilSensorValue = readSoil();
  lightSensorValue = readLight();;
  tempSensorValue = readTemp();

  //Determine if soil is too dry based on threshold
  boolean soilTooDry = (soilSensorValue < 600);
  //Determine if hour threshold passed
  boolean hourThresholdPassed = (hoursSinceWater > minimumWaterHours);

  // If soil is too dry or hour threshold passed then the plant needs water
  if(soilTooDry){
    return true;
  }
  if (hourThresholdPassed) {
    return true;
  }
  // Otherwise the plant does not need water
  return false;
}

// Reset the number of hours since water to 0
void Plant::resetHours() {
  hoursSinceWater = 0;
}

// Increment the number of hours since water because an hour passed
void Plant::hourPassed() {
  hoursSinceWater++;
}

// Custom function for reading soil value from sensor
int Plant::readSoil() {
  int val = analogRead(soilMoisturePin);
  return 1023 - val;
}

// Custom function for reading light value from sensor
int Plant::readLight() {
  int val = analogRead(lightSensorPin) * 100 / 1023;
  return val;
}

// Custom function for reading temp value from sensor
int Plant::readTemp() {
  int val = ((analogRead(tempSensorPin) * 5000 / 1023) - 500) / 10;
  val = (((val * 1.8) + 32) * -1) + 25;
  return val;
}

// Getters
int Plant::getPlantNum() {
  return plantNum;
}
int Plant::getSoilSensorValue() {
  return soilSensorValue;
}
int Plant::getLightSensorValue() {
  return lightSensorValue;
}
int Plant::getTempSensorValue() {
  return tempSensorValue;
}
unsigned long Plant::getHoursSinceWater() {
  return hoursSinceWater;
}






/* OLD
int Plant::readSoil(){
  digitalWrite(soilPower, HIGH);
  delay(10);
  int val = analogRead(soilMoisturePin);
  digitalWrite(soilPower, LOW);
  return val;
}
*/
