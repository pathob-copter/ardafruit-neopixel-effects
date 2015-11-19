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
