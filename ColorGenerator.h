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
  
      _Color getNextColor();
  
      /** 
       * All colors that has to be gone through 
       */
      _ColorList _colors;
    
    private:

      void copy(const _ColorGenerator& other);
  
      /**
       * Current (intermediate) color in color generating process
       */
      _Color _currentColor;
  
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
  _currentColor = color;
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
