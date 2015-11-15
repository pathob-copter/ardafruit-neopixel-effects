#pragma once
#include "AbstractLedEffect.h"

AbstractLedEffect::AbstractLedEffect(Adafruit_NeoPixel stripe) :
  _stripe(stripe), _color(0)
{
  _ledIndexStart = 0;
  _ledIndexEnd = stripe.numPixels() - 1;
  _activeStep = 0;
  
  _primaryColors[AbstractLedEffect::Red]   = 255;
  _primaryColors[AbstractLedEffect::Green] = 0;
  _primaryColors[AbstractLedEffect::Blue]  = 0;
}

void AbstractLedEffect::setColor(uint8_t r, uint8_t g, uint8_t b)
{
  _color = _stripe.Color(r,g,b);
}

void AbstractLedEffect::setColor(uint32_t color)
{
  _color = color;
}

void AbstractLedEffect::logColors(uint8_t red, uint8_t green, uint8_t blue)
{
  Serial.print("Color - R:G:B");
  Serial.print(red);
  Serial.print(":");
  Serial.print(green);
  Serial.print(":");
  Serial.print(blue);
  Serial.print("\r\n\r\n");
}

uint32_t AbstractLedEffect::colorGenerator() {
  _primaryColors[_activePrimaryColor]--;
  _primaryColors[(_activePrimaryColor + 1) % NumPrimColors]++;
  
  if (_primaryColors[_activePrimaryColor] == 0) {
    _activePrimaryColor = (_activePrimaryColor + 1) % NumPrimColors;
  }

  uint8_t newRed   = _primaryColors[Red]   / _divisor[_activeStep];
  uint8_t newGreen = _primaryColors[Green] / _divisor[_activeStep];
  uint8_t newBlue  = _primaryColors[Blue]  / _divisor[_activeStep];
  
  _color = _stripe.Color(newRed, newGreen, newBlue);
  _activeStep = (_activeStep + 1) % sizeof(_divisor);
}

