#ifndef Waterer_h
#define Waterer_h

// the #include statment and code go here...
#include "Arduino.h"
#include "Plant.h"

class Waterer
{
public:
    Waterer();
    Waterer(int actuatorPin, int rotatePin);

    void giveWater(Plant p);
private:
    int actuatorPin;
    int rotatePin;
    
    void moveToPosition(Plant p);
    void returnToDefaultPosition();
};

#endif
