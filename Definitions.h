#pragma once

#ifndef ADAFRUITNEOPIXELEFFECTS_DEFINITIONS_H
#define ADAFRUITNEOPIXELEFFECTS_DEFINITIONS_H

#include <Adafruit_NeoPixel.h>
#include <StandardCplusplus.h>

namespace AdafruitNeopixelEffects
{

  // Base classes
  
  template<typename N>
  class _Node;
  
  template<typename T>
  class _List;

  typedef _List<uint8_t>* Uint8List;
  typedef _List<uint32_t>* Uint32List;
  
  class _Color;
  typedef _Color* Color;
  typedef _List<_Color> _ColorList;
  typedef _List<_Color>* ColorList;
  
  class _ColorGenerator;
  typedef _ColorGenerator* ColorGenerator;
  typedef _List<ColorGenerator>* ColorGeneratorList;

  // Effect classes

  class _LightEffect;
  typedef _LightEffect* LightEffect;

  class _DurableLight;
  typedef _DurableLight* DurableLight;

  class _FlashLight;
  typedef _FlashLight* FlashLight;

  class _RunningLight;
  typedef _RunningLight* RunningLight;

}

#endif
