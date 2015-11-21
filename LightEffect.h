#pragma once
#include <Adafruit_NeoPixel.h>
#include "Base.h"

class LightEffect
  : AbstractBase
{

  public:

    using AbstractBase::Red;
    using AbstractBase::Green;
    using AbstractBase::Blue;
    using AbstractBase::NumPrimColors;

    LightEffect(Adafruit_NeoPixel stripe)
    {
      _stripe = stripe;
      _ledIndexStart = 0;
      _ledIndexEnd = stripe.numPixels() - 1;
    };

    LightEffect(Adafruit_NeoPixel stripe, Color color)
      : LightEffect(stripe)
    {
      _colorGenerator.addColor(color);
    };

    LightEffect(Adafruit_NeoPixel stripe, ColorGenerator colorGenerator)
      : LightEffect(stripe)
    {
      _colorGenerator = colorGenerator;
    };

    ~LightEffect(){};

    void setColor(uint8_t r, uint8_t g, uint8_t b)
    {
      // Todo: Should not use a (specific) neopixel instance to get color from it
      // _color = _stripe.Color(r,g,b);
    };
    
    void setColor(uint32_t color)
    {
      // _color = color;
    };
    
    void setRange(uint16_t indexStart, uint16_t indexEnd)
    {
      if (indexStart <= indexEnd) {
        _ledIndexStart = indexStart;
        _ledIndexEnd = indexEnd;
      }
    };
    
    virtual void run() = 0;
  
  protected:

    void logColors(uint8_t red, uint8_t green, uint8_t blue)
    {
      // Todo: Dumb function - modify or remove
      Serial.print("Color - R:G:B");
      Serial.print(red);
      Serial.print(":");
      Serial.print(green);
      Serial.print(":");
      Serial.print(blue);
      Serial.print("\r\n\r\n");
    };
    
    // stripe attributes
    Adafruit_NeoPixel _stripe;
    uint16_t _ledIndexStart;
    uint16_t _ledIndexEnd;

    // light effect attributes
    ColorGenerator _colorGenerator;
    List<uint8_t>* _brightness = new List<uint8_t>();

};

