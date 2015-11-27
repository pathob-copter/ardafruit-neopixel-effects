#pragma once

#ifndef ADAFRUITNEOPIXELEFFECTS_DEFINITIONS_H
#define ADAFRUITNEOPIXELEFFECTS_DEFINITIONS_H

#include <Adafruit_NeoPixel.h>
#include <StandardCplusplus.h>
#include <boost_1_51_0.h>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <boost/throw_exception.hpp>

// FIXME
void boost::throw_exception(std::exception const & e) {}
std::exception::~exception() {}

namespace AdafruitNeopixelEffects
{

  // Base classes
  
  template<typename N>
  class _Node;
  
  template<typename T>
  class _List;

  typedef boost::shared_ptr<_List<uint8_t> > Uint8List;
  typedef boost::shared_ptr<_List<uint32_t> > Uint32List;
  
  class _Color;
  typedef boost::shared_ptr<_Color> Color;
  typedef boost::shared_ptr<_List<Color> > ColorList;
  
  class _ColorGenerator;
  typedef boost::shared_ptr<_ColorGenerator> ColorGenerator;
  typedef boost::shared_ptr<_List<ColorGenerator> > ColorGeneratorList;

  // Effect classes

  class _LightEffect;
  typedef boost::shared_ptr<_LightEffect> LightEffect;

  class _DurableLight;
  typedef boost::shared_ptr<_DurableLight> DurableLight;

  class _FlashLight;
  typedef boost::shared_ptr<_FlashLight> FlashLight;

  class _RunningLight;
  typedef boost::shared_ptr<_RunningLight> RunningLight;

}

#endif
