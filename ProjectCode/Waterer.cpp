#include "Waterer.h"

Waterer::Waterer() { }

Waterer::Waterer(int pumpPin, int rotatePin) {
  this->pumpPin = pumpPin;
  this->rotatePin = rotatePin;
  this->currentPlantPosition = Plant();
  this->servo.attach(rotatePin);
  pinMode(pumpPin, OUTPUT);
  //pinMode(rotatePin, OUTPUT);
}

void Waterer::giveWater(Plant& p) {
    //p.hoursSinceWater = 0;
    p.resetHours();
    p.clearDisplay();
    p.displayInfo();
    delay(1000);
    //Serial.print("address in waterer:");
    //Serial.println(int(&p));
    // TO-DO: ACTUALLY WATER
    moveToPosition(p);
    digitalWrite(pumpPin, HIGH);
    delay(1000);
    digitalWrite(pumpPin, LOW);
    //Serial.println("Watered");
    delay(4000);
    returnToDefaultPosition();
    
}

void Waterer::moveToPosition(Plant& p) {
    Serial.print("Moved to Position:");
    Serial.println(p.getPlantNum());
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
  //Serial.println("Returned to Default Position");
  servo.write(90);
  currentPlantPosition = Plant();
}
