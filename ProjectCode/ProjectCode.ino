#include "Plant.h"
#include "Waterer.h"
#include "OLEDDisplayer.h"
#define numOfPlants 2

Plant plants[numOfPlants];
Waterer waterer;
OLEDDisplayer displayer;

const int soilPower = 5;
const int soilMoisturePins[numOfPlants] = {A0, A3}; // was A0
const int lightSensorPins[numOfPlants] = {A1, A1};
const int tempSensorPins[numOfPlants] = {A2, A2};

const int pumpPin = 3;
const int rotatePin = 2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  waterer = Waterer(pumpPin, rotatePin);
  //Serial.print("right here");
  displayer = OLEDDisplayer(14);
  //Serial.print("right here");
  //displayer->displayData(1, 1, 1, 1, 1);
  for (int i = 0; i < numOfPlants; i++) {
    plants[i] = Plant("default", i, soilMoisturePins[i], soilPower,
                      lightSensorPins[i],tempSensorPins[i]);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < numOfPlants; i++) {
    //displayer.displayData(plants[i]);
    //delay(1000);
    if (plants[i].needsWater()) {
      //Serial.print("plant address: ");
      //Serial.println(int(plants)+i);
      Serial.print("Give water: ");
      Serial.print(i);
      waterer.giveWater(plants[i]);
    }
  }
  //displayer.displayData(plants, numOfPlants);

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
