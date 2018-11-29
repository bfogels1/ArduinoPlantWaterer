#ifndef OLEDDisplayer_h
#define OLEDDisplayer_h

// the #include statment and code go here...
#include "Arduino.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_SPITFT_Macros.h>
#include <gfxfont.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h> 


class OLEDDisplayer
{
public:
  OLEDDisplayer();
  OLEDDisplayer(int OLEDPin);

  void displayData(int, int, int, int, int);
private:
  int OLEDPin;
  Adafruit_SSD1306 *display;
};

#endif
