#pragma once
#include "DurableLight.h"

DurableLight::DurableLight(Adafruit_NeoPixel stripe) :
  AbstractLedEffect(stripe)
{
  // ...
}

void DurableLight::run()
{
  for(int i = _ledIndexStart; i <= _ledIndexEnd; i++) {
    _stripe.setPixelColor(i, getEffectColor());
  }
}

uint32_t DurableLight::getEffectColor() {
  return _color;
}

void DurableLight::setRange(uint16_t indexStart, uint16_t indexEnd)
{
  if (indexStart <= indexEnd) {
    _ledIndexStart = indexStart;
    _ledIndexEnd = indexEnd;
  }
}

