#include <Adafruit_NeoPixel.h>

#define LED_01_PIN      3
#define LED_01_NUM      13

#define STEPS_NUM       7

#define RED   0
#define GREEN 1
#define BLUE  2

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(LED_01_NUM, LED_01_PIN, NEO_GRB + NEO_KHZ800);

int delayval = 60; // delay for half a second

bool increase = true;
int index = 0;

int step = 0;

int color[3];
int offset;

int divisor[STEPS_NUM] = {20, 1, 3, 8, 20, 100, 255};

void setup() {
  Serial.begin(9600);
  
  pixels.begin();
  pixels.setBrightness(255);
  pixels.show();
  
  offset = 0;
  
  color[RED]   = 255;
  color[GREEN] = 0;
  color[BLUE]  = 0;
}

void loop() {
  
  for(int i = LED_01_NUM; i > 0; i--) {
    uint32_t nextLedColor = pixels.getPixelColor(i - 1);
    pixels.setPixelColor(i, nextLedColor);
  }

  color[offset]--;
  color[(offset+1)%3]++;
  
  if (color[offset] == 0) {
    offset = (offset + 1) % 3;
  }
  
  pixels.setPixelColor(0, pixels.Color(color[RED] / divisor[step], color[GREEN] / divisor[step], color[BLUE] / divisor[step]));
  
  Serial.print(color[RED]);
  Serial.print(" - ");
  Serial.print(color[GREEN]);
  Serial.print(" - ");
  Serial.println(color[BLUE]);
  
  step = (step + 1) % STEPS_NUM;
  index = (index + 1) % LED_01_NUM;
  
  pixels.show();
  delay(delayval);
}
