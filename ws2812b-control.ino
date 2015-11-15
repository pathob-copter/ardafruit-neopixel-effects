#include <Adafruit_NeoPixel.h>
#include "RunningLight.h"

#define LED_01_PIN      3
#define LED_01_NUM      13

Adafruit_NeoPixel led_01 = Adafruit_NeoPixel(LED_01_NUM, LED_01_PIN, NEO_GRB + NEO_KHZ800);
RunningLight runningLight = RunningLight(led_01);

int delayTime = 60;

void setup() {
  Serial.begin(9600);
  
  led_01.begin();
  
  // led_01.setBrightness(255);
  // led_01.show();
}

void loop() {
  
  runningLight.run();
  delay(delayTime);
}
