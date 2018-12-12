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
  // Waterer controls pump location and when to pump
  waterer = Waterer(pumpPin, rotatePin);
  
  // Displayer displays data on the OLED Display
  displayer = OLEDDisplayer(14);

  // Declare a Plant object for each plant and store in plants array
  for (int i = 0; i < numOfPlants; i++) {
    plants[i] = Plant("default", i, soilMoisturePins[i], soilPowerPins[i],
                      lightSensorPins[i],tempSensorPins[i]);
  }
}

void loop() {
  // Loop through each of the plants
  for (int i = 0; i < numOfPlants; i++) {
    // Check if each plant needs water
    if (plants[i].needsWater()) {
      // If so, instruct the waterer to give water to that plant
      waterer.giveWater(plants[i]);
    }
  }

  //Display the data obtained from reading sensors on the OLED Display
  displayer.displayData(plants, numOfPlants);

  // Delay 60 minutes to save Arduino battery
  delayHour();
}

// Use Loops to delay for the given number of hours
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
  // Delay for an hour
  delayMin(60);
  //delay(1000);  // For testing update every second instead of every hour

  // For  each of the plants, inform the plant that an hour has passed
  for (int i=0; i < numOfPlants; i++) {
    plants[i].hourPassed();
  } 
}
