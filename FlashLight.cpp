#pragma once
#include "FlashLight.h"

FlashLight::FlashLight(Adafruit_NeoPixel stripe) :
  AbstractLedEffect(stripe)
{
  _ledIndexStart = 0;
  _ledIndexEnd = _stripe.numPixels() - 1;
  _activeStep = 0;
  
  _primaryColors[AbstractLedEffect::Red]   = 255;
  _primaryColors[AbstractLedEffect::Green] = 0;
  _primaryColors[AbstractLedEffect::Blue]  = 0;
}

void FlashLight::run()
{

  _primaryColors[_activePrimaryColor]--;
  _primaryColors[(_activePrimaryColor + 1) % NumPrimColors]++;
  
  if (_primaryColors[_activePrimaryColor] == 0) {
    _activePrimaryColor = (_activePrimaryColor + 1) % NumPrimColors;
  }

  uint8_t newRed   = _primaryColors[Red]   / _divisor[_activeStep];
  uint8_t newGreen = _primaryColors[Green] / _divisor[_activeStep];
  uint8_t newBlue  = _primaryColors[Blue]  / _divisor[_activeStep];
  
  uint32_t newColor = _stripe.Color(newRed, newGreen, newBlue);

  for(int i = _ledIndexStart; i <= _ledIndexEnd; i++) {
    _stripe.setPixelColor(i, newColor);
  }
  
  _activeStep = (_activeStep + 1) % sizeof(_divisor);
  
  _stripe.show();
  logColors(newRed, newGreen, newBlue);
}

void FlashLight::setRange(uint16_t indexStart, uint16_t indexEnd)
{
  if (indexStart <= indexEnd) {
    _ledIndexStart = indexStart;
    _ledIndexEnd = indexEnd;
  }
}

