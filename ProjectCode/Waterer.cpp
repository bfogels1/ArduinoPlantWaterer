#include "Waterer.h"

Waterer::Waterer() { }

Waterer::Waterer(int actuatorPin, int rotatePin) {
  this->actuatorPin = actuatorPin;
  this->rotatePin = rotatePin;
  this->currentPlantPosition = Plant();
  
  pinMode(actuatorPin, OUTPUT);
  pinMode(rotatePin, OUTPUT);
}

void Waterer::giveWater(Plant p) {
    p.resetHours();
    p.displayInfo();
    // TO-DO: ACTUALLY WATER
    moveToPosition(p);
    
    Serial.println("Watered");
    returnToDefaultPosition();
}

void Waterer::moveToPosition(Plant p) {
    Serial.println("Moved to Position");
    currentPlantPosition = p;
}

void Waterer::returnToDefaultPosition() {
  Serial.println("Returned to Default Position");
  currentPlantPosition = Plant();
}
