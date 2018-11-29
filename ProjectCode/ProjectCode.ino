#include "Plant.h"
#define numOfPlants 1

Plant plants[numOfPlants];
const int soilPower = 5;
const int soilMoisturePins[numOfPlants] = {0}; // was A0
const int lightSensorPins[numOfPlants] = {1};
const int tempSensorPins[numOfPlants] = {2};

int actuatorPin = 3;
int rotatePin = 4;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  //plants = new plants[numOfPlants];
  pinMode(soilPower, OUTPUT);
  for (int i = 0; i < numOfPlants; i++) {
    plants[i] = Plant("default", i, actuatorPin, 
                          rotatePin, soilMoisturePins[i], soilPower,
                          lightSensorPins[i],tempSensorPins[i]);
  }

//  pinMode(actuatorPin, OUTPUT);
//  pinMode(rotatePin, OUTPUT);



}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < numOfPlants; i++) {
    if (plants[i].needsWater()) {
      plants[i].giveWater();
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
  delayMin(60);
  for (int i=0; i < numOfPlants; i++) {
    plants[i].hourPassed();
  } 
}
