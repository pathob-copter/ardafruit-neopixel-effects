#pragma once

#ifndef ADAFRUITNEOPIXELEFFECTS_COLORGENERATOR_H
#define ADAFRUITNEOPIXELEFFECTS_COLORGENERATOR_H

#include "Color.h"
#include "List.h"

namespace AdafruitNeopixelEffects
{
  class _ColorGenerator
  {
  
    public:
  
      _ColorGenerator();
      _ColorGenerator(Color color);
      _ColorGenerator(uint32_t color);
      _ColorGenerator(const _ColorGenerator& other);
      ~_ColorGenerator() {};
  
      void addColor(Color color);
  
      Color getNextColor();
  
      /** 
       * All colors that has to be gone through 
       */
      ColorList _colors;
    
    private:
  
      /**
       * Current (intermediate) color in color generating process
       */
      Color _currentColor;
  
  };
  
  typedef boost::shared_ptr<_ColorGenerator> ColorGenerator;
}


using namespace AdafruitNeopixelEffects;

_ColorGenerator::_ColorGenerator()
{
  _colors = boost::make_shared<_List<Color> >();
}

_ColorGenerator::_ColorGenerator(Color color)
  : _ColorGenerator()
{
  _colors->add(color);
  _currentColor = color;
}

_ColorGenerator::_ColorGenerator(uint32_t colorInt)
//  : _ColorGenerator()
{
  Color color = boost::make_shared<_Color>(colorInt);
  _colors->add(color);
  _currentColor = color;
}

_ColorGenerator::_ColorGenerator(const _ColorGenerator& other)
{
  // TODO
}

void AdafruitNeopixelEffects::_ColorGenerator::addColor(Color color)
{
  _colors->add(color);
}

Color AdafruitNeopixelEffects::_ColorGenerator::getNextColor()
{
  
  // Todo:
  // calculate next color of two generator colors
  // using the actual step between these colors

  Color color = boost::make_shared<_Color>(_colors->iterate()->toInt());

  return color;
}

#endif
