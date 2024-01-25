/*
  RGBLed.cpp - Library for Changing RGB Led.
  Created by Joseph Marrero Ocasio, January 25, 2024.
  Released into the public domain.
*/

#include "Arduino.h"
#include "RGBLed.h"

RGBLed::RGBLed(int _redPin, int _greenPin, int _bluePin) {
    redPin = _redPin;
    greenPin = _greenPin;
    bluePin = _bluePin;
}

void RGBLed::begin() {
    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);
}

void RGBLed::changeLedColor(int color[3]) {
    analogWrite(redPin, color[0]);
    analogWrite(greenPin, color[1]);
    analogWrite(bluePin, color[2]);
}

void RGBLed::setCustomLedColor(int redColor, int greenColor, int blueColor) {
    analogWrite(redPin, redColor);
    analogWrite(greenPin, greenColor);
    analogWrite(bluePin, blueColor);
}