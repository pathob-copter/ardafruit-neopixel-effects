#pragma once

#ifndef ADAFRUITNEOPIXELEFFECTS_COLOR_H
#define ADAFRUITNEOPIXELEFFECTS_COLOR_H

#include "Definitions.h"

namespace AdafruitNeopixelEffects
{
  class _Color {
  
    public:
  
      _Color();
      _Color(uint32_t color);
      _Color(uint8_t r, uint8_t g, uint8_t b);
      _Color(const _Color& other);
  
  	  ~_Color() {};
  	
      uint32_t toInt();
      
      uint8_t red();
      uint8_t green();
      uint8_t blue();
  
      void applyBrightness(uint8_t brightness);
  
    private:
  
      uint32_t _color;
      
  };
  
  typedef boost::shared_ptr<_Color> Color;

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
  _color = other._color;
}

uint32_t _Color::toInt()
{
  return _color;
}

uint8_t _Color::red()
{
  return (_color >> 16) & 255;
}

uint8_t _Color::green()
{
  return (_color >> 8) & 255;
}

uint8_t _Color::blue()
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
  Color color = boost::make_shared<_Color>(r, g, b);
  _color = color->toInt();
}

#endif
