#pragma once
#include <Adafruit_NeoPixel.h>
//#include "RunningLight.h"
#include "FlashLight.h"
#include "DurableLight.h"

#define LED_01_PIN      3
#define LED_01_NUM      13

Adafruit_NeoPixel led_01 = Adafruit_NeoPixel(LED_01_NUM, LED_01_PIN, NEO_GRB + NEO_KHZ800);
FlashLight flashLight = FlashLight(led_01);
DurableLight durableLight = DurableLight(led_01);

int delayTime = 80;

void setup() {
  Serial.begin(9600);
  
  led_01.begin();

  flashLight.setRange(0, 8);
  flashLight.setColor(100,100,100);
  
  durableLight.setRange(9, 12);
  durableLight.setColor(255,0,0);
}

void loop() {
  flashLight.run();
  durableLight.run();
  led_01.show();
  delay(delayTime);
}

