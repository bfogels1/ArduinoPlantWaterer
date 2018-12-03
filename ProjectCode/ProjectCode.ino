#include "Plant.h"
#include "Waterer.h"
#define numOfPlants 1

Plant plants[numOfPlants];
Waterer waterer;

const int soilPower = 5;
const int soilMoisturePins[numOfPlants] = {A0}; // was A0
const int lightSensorPins[numOfPlants] = {A1};
const int tempSensorPins[numOfPlants] = {A2};

const int actuatorPin = 3;
const int rotatePin = 4;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  waterer = Waterer(rotatePin,actuatorPin);
  pinMode(soilPower, OUTPUT);
  for (int i = 0; i < numOfPlants; i++) {
    plants[i] = Plant("default", i, soilMoisturePins[i], soilPower,
                      lightSensorPins[i],tempSensorPins[i]);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < numOfPlants; i++) {
    if (plants[i].needsWater()) {
      waterer.giveWater(plants[i]);
    }
  }

  // Delay 60 minutes to save Arduino battery
  delayHour();
}

void delayMin(int minutes) {
  // Delay for number of minutes
  for (int i = 0; i < minutes; i++) {
    // Delay 1 minute
    for (int j = 0; j < 60; j++) {
      // Delay 1 second
      delay(1000);
    }
  }
}

void delayHour() {
  //delayMin(60);
  delay(1000);
  for (int i=0; i < numOfPlants; i++) {
    plants[i].hourPassed();
  } 
}
