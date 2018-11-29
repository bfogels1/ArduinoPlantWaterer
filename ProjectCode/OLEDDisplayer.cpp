#include "OLEDDisplayer.h"

OLEDDisplayer::OLEDDisplayer() {}

OLEDDisplayer::OLEDDisplayer(int OLEDPin) {
  this->OLEDPin = OLEDPin;

  // Check Dimensions of OLED in Library, if incorrect edit file
  #if (SSD1306_LCDHEIGHT != 64)
  #error("Height incorrect; edit the screen height in Adafruit_SSD1306.h file");
  #endif

  // initialize display
  this->display = new Adafruit_SSD1306(OLEDPin);  
  display->begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display->clearDisplay(); 
  display->setTextSize(1);
  display->setTextColor(WHITE);
}

void OLEDDisplayer::displayData(int plantNumber, int soilMoistureReading, int lightReading, int tempReading, int hoursPassed) {
  display->clearDisplay();
  display->setCursor(0,0);
  display->print("Plant: ");
  display->println(plantNumber);
  display->print("Moisture: ");
  display->println(soilMoistureReading);
  display->print("Light Percent: ");
  display->print(lightReading);
  display->println("%");
  display->print("Degrees F: ");
  display->println(tempReading);
  display->print("Hours Passed: ");
  display->println(hoursPassed);
  display->display();
}
