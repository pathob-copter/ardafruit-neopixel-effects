#include "AbstractLedEffect.h"

AbstractLedEffect::AbstractLedEffect(Adafruit_NeoPixel stripe) :
  _stripe(stripe)
{
  //uint16_t numLEDs
  _numLEDs = _stripe.numPixels();
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

