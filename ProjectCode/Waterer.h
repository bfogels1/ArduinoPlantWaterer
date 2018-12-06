#ifndef Waterer_h
#define Waterer_h

// the #include statment and code go here...
#include "Arduino.h"
#include "Plant.h"
#include <Servo.h>

class Waterer
{
public:
    Waterer();
    Waterer(int pumpPin, int rotatePin);

    void giveWater(Plant& p);
private:
    Servo servo;
    int pumpPin;
    int rotatePin;
    Plant currentPlantPosition;
    
    void moveToPosition(Plant &p);
    void returnToDefaultPosition();
};

#endif
