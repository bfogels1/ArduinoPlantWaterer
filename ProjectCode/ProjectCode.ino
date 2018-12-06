#include "Plant.h"
#include "Waterer.h"
#include "OLEDDisplayer.h"
#define numOfPlants 2

Plant plants[numOfPlants];
Waterer waterer;
OLEDDisplayer displayer;

const int soilPowerPins[numOfPlants] = {5, 5};
const int soilMoisturePins[numOfPlants] = {A0, A3}; // was A0
const int lightSensorPins[numOfPlants] = {A1, A1};
const int tempSensorPins[numOfPlants] = {A2, A2};

const int pumpPin = 3;
const int rotatePin = 2;

void setup() {
  // put your setup code here, to run once:
  //Serial.begin(9600);
  waterer = Waterer(pumpPin, rotatePin);
  displayer = OLEDDisplayer(14);
  for (int i = 0; i < numOfPlants; i++) {
    plants[i] = Plant("default", i, soilMoisturePins[i], soilPowerPins[i],
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
  displayer.displayData(plants, numOfPlants);

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
