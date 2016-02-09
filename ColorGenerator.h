#pragma once

#ifndef ADAFRUITNEOPIXELEFFECTS_COLORGENERATOR_H
#define ADAFRUITNEOPIXELEFFECTS_COLORGENERATOR_H

#include "Adafruit_NeoPixel_Effects.h"

namespace AdafruitNeopixelEffects
{
  typedef _List<_Color> _ColorList;

  class _ColorGenerator
  {
  
    public:
  
      _ColorGenerator();
      _ColorGenerator(const _Color& color);
      _ColorGenerator(const _ColorGenerator& other);
      ~_ColorGenerator();

      _ColorGenerator& operator=(const _ColorGenerator& other);
  
      void addColor(const _Color& color);
      void addColorFade(const _Color& color, uint16_t steps);
  
      _Color getColor();
  
      /** 
       * All colors that has to be gone through 
       */
      _ColorList _colors;
    
    private:
    
      _Color getNextColor();
      
      _Color _colorFadeFrom;
      _Color _colorFadeTo;
      uint16_t _fadeSteps = 100;
      uint16_t _fadeStepsDone = 0;

      void copy(const _ColorGenerator& other);
  
  };
  
  typedef _ColorGenerator* ColorGenerator;
}


using namespace AdafruitNeopixelEffects;

_ColorGenerator::_ColorGenerator()
{
  _colors = _ColorList();
}

_ColorGenerator::_ColorGenerator(const _Color& color)
{
  _colors = _ColorList();
  Serial.print("_ColorGenerator: ");
  Serial.println(color.toInt());
  _colors.add(color);
}

_ColorGenerator::_ColorGenerator(const _ColorGenerator& other)
{
  copy(other);
}

_ColorGenerator::~_ColorGenerator()
{
  // TODO
}

_ColorGenerator& _ColorGenerator::operator=(const _ColorGenerator& other)
{
  copy(other);
}

void _ColorGenerator::addColor(const _Color& color)
{
  _colors.add(color);
}

_Color _ColorGenerator::getColor()
{
    if (_fadeStepsDone == _fadeSteps) {
        _colorFadeFrom = _colorFadeTo;
        _colorFadeTo = _colors.iterate();
        _fadeStepsDone = 0;
        return _colorFadeFrom;
    }
    
    float stepWidth = (float) _fadeStepsDone / _fadeSteps;
    _fadeStepsDone++;

    return _Color(
        _colorFadeFrom.red()   + (_colorFadeTo.red()   - _colorFadeFrom.red())   * stepWidth,
        _colorFadeFrom.green() + (_colorFadeTo.green() - _colorFadeFrom.green()) * stepWidth,
        _colorFadeFrom.blue()  + (_colorFadeTo.blue()  - _colorFadeFrom.blue())  * stepWidth
    );
}

_Color _ColorGenerator::getNextColor()
{
  _Color color = _colors.iterate();
  Serial.print("getNextColor: ");
  Serial.println(color.toInt());
  return color;
}

void _ColorGenerator::copy(const _ColorGenerator& other)
{
  //TODO
}

#endif
