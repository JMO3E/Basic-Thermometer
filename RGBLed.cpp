/*
  RGBLed.cpp - Library for Changing RGB Led.
  Created by Joseph Marrero Ocasio, January 25, 2024.
  Released into the public domain.
*/

#include "Arduino.h"
#include "RGBLed.h"

RGBLed::RGBLed(int redPin, int greenPin, int bluePin) {
    _redPin = redPin;
    _greenPin = greenPin;
    _bluePin = bluePin;
}

void RGBLed::begin() {
    pinMode(_redPin, OUTPUT);
    pinMode(_greenPin, OUTPUT);
    pinMode(_bluePin, OUTPUT);
}

void RGBLed::changeLedColor(int color[3]) {
    analogWrite(_redPin, color[0]);
    analogWrite(_greenPin, color[1]);
    analogWrite(_bluePin, color[2]);
}

void RGBLed::setCustomLedColor(int redColor, int greenColor, int blueColor) {
    analogWrite(_redPin, redColor);
    analogWrite(_greenPin, greenColor);
    analogWrite(_bluePin, blueColor);
}