// COVID was hard, we missed a lot of hugs
// Hugfields is a project that uses a flex sensor.
// When the person is squeezed, they light-up.
// The longer and harder the hug, the brighter it gets.
// Additional Easter Eggs can be found on them in person. 
// Enjoy.

#include <FastLED.h>
#define LED_PIN 13
#define NUM_LEDS 100
#define FLEX_PIN 15
#define BRIGHTNESS_MAX 100
#define BRIGHTNESS_MIN 5

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  pinMode(FLEX_PIN, INPUT);
  Serial.begin(115200);
}

void loop() {
  int flexValue = analogRead(FLEX_PIN);
  Serial.println("Flex sensor value: " + String(flexValue));
  int brightness = map(flexValue, 0, 1023, BRIGHTNESS_MIN, BRIGHTNESS_MAX);
  for (int i = 0; i < NUM_LEDS; i++) {
    if (i % 2 == 0) {
      leds[i] = CHSV(100, 0, brightness);
    } else {
      leds[i] = CHSV(322, 13, brightness);
    }
  }
  FastLED.show();
    delay(500);
}
