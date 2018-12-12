#include "Waterer.h"

Waterer::Waterer() { }

Waterer::Waterer(int pumpPin, int rotatePin) {
  // Set pins
  this->pumpPin = pumpPin;
  this->rotatePin = rotatePin;
  // Set default initial position
  this->currentPlantPosition = Plant();
  // Attach Servo Pin
  this->servo.attach(rotatePin);
  //Set pump to output pin mode
  pinMode(pumpPin, OUTPUT);
}

void Waterer::giveWater(Plant& p) {
    // Reset number of hours since last water back to zero
    p.resetHours();

    // Move to the position of the plant
    moveToPosition(p);
    
    // Turn the pump on, wait one second and turn it off
    digitalWrite(pumpPin, HIGH);
    delay(1000);
    digitalWrite(pumpPin, LOW);
    // Wait four seconds to account for drip after the pump  stops
    delay(4000);

    // Move back to default position
    returnToDefaultPosition();
    
}

void Waterer::moveToPosition(Plant& p) {
    // Use a switch statement to move to the correct position based on the plant number
    switch (p.getPlantNum()){
      case 0:
        Serial.println(0);
        servo.write(45);
        delay(2000);
        break;
      case 1:
        Serial.println(1);
        servo.write(135);
        delay(2000);
        break;
     default:
        Serial.println("default");
        servo.write(90);
        delay(2000);
        break;
    }
}

void Waterer::returnToDefaultPosition() {
  // Return to default position
  servo.write(90);
  currentPlantPosition = Plant();
}
