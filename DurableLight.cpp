#pragma once
#include "DurableLight.h"

DurableLight::DurableLight(Adafruit_NeoPixel stripe) :
  AbstractLedEffect(stripe)
{
  /*
  _ledIndexStart = 0;
  _ledIndexEnd = _stripe.numPixels() - 1;
  _activeStep = 0;
  
  _primaryColors[AbstractLedEffect::Red]   = 255;
  _primaryColors[AbstractLedEffect::Green] = 0;
  _primaryColors[AbstractLedEffect::Blue]  = 0;
  */

  uint8_t divisor[7] = {1, 1, 1, 1, 1, 1, 1};
  //memcpy(_divisor, divisor, sizeof(divisor));
}

void DurableLight::run()
{
  for(int i = _ledIndexStart; i <= _ledIndexEnd; i++) {
    _stripe.setPixelColor(i, _color);
  }
  _stripe.show();
}

void DurableLight::setRange(uint16_t indexStart, uint16_t indexEnd)
{
  if (indexStart <= indexEnd) {
    _ledIndexStart = indexStart;
    _ledIndexEnd = indexEnd;
  }
}

