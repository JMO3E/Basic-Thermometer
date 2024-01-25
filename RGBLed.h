/*
  RGBLed_h - Library for Changing RGB Led.
  Created by Joseph Marrero Ocasio, January 25, 2024.
  Released into the public domain.
*/

#ifndef RGBLed_h
#define RGBLed_h

#include "Arduino.h"

class RGBLed
{
  public:
    RGBLed(int redPin, int greenPin, int bluePin);
    int redColor[3] = {255,0,0};
    int greenColor[3] = {0,255,0};
    int blueColor[3] = {0,0,255};

    void begin();
    void changeLedColor(int color[3]);
    void setCustomLedColor(int redColor, int greenColor, int blueColor);

  private:
    int _redPin;
    int _greenPin;
    int _bluePin;
};

#endif