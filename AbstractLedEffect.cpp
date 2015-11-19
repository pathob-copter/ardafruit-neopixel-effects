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

void AbstractLedEffect::setRange(uint16_t indexStart, uint16_t indexEnd)
{
  if (indexStart <= indexEnd) {
    _ledIndexStart = indexStart;
    _ledIndexEnd = indexEnd;
  }
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
