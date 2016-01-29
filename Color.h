#ifndef ADAFRUITNEOPIXELEFFECTS_COLOR_H
#define ADAFRUITNEOPIXELEFFECTS_COLOR_H

#include "Adafruit_NeoPixel_Effects.h"

namespace AdafruitNeopixelEffects
{
  class _Color {
  
    public:
  
      _Color();
      _Color(uint32_t color);
      _Color(uint8_t r, uint8_t g, uint8_t b);
      _Color(const _Color& other);
  	  ~_Color();

      _Color& operator=(const _Color& other);
  	
      uint32_t toInt() const;
      
      uint8_t red() const;
      uint8_t green() const;
      uint8_t blue() const;
  
      void applyBrightness(uint8_t brightness);
  
    private:
    
      void copy(const _Color& other);

      uint32_t _color;
      
  };
  
  typedef _Color* Color;

}


using namespace AdafruitNeopixelEffects;

_Color::_Color()
{
  _color = 0;
}

_Color::_Color(uint32_t color)
{
  _color = color;
}

_Color::_Color(uint8_t r, uint8_t g, uint8_t b)
{
  _color = ((uint32_t)r << 16) | ((uint32_t)g << 8) | b;
}

_Color::_Color(const _Color& other)
{
  copy(other);
}

_Color::~_Color()
{
  //TODO
}

_Color& _Color::operator=(const _Color& other)
{
  copy(other);
}

uint32_t _Color::toInt() const
{
  return _color;
}

uint8_t _Color::red() const
{
  return (_color >> 16) & 255;
}

uint8_t _Color::green() const
{
  return (_color >> 8) & 255;
}

uint8_t _Color::blue() const
{
  return _color & 255;
}

void _Color::applyBrightness(uint8_t brightness)
{
  uint8_t r = (red() * brightness) >> 8;
  uint8_t g = (green() * brightness) >> 8;
  uint8_t b = (blue() * brightness) >> 8;

  // Todo: Should use a static function instead
  // Todo: unprecise result
  _Color color = _Color(r, g, b);
  _color = color.toInt();
}

void _Color::copy(const _Color& other)
{
  _color = other._color;
}

#endif
