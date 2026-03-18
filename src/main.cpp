#include <Arduino.h>
#include "heart.h"
#include "SoundSensor.h"
#include "LedBar.h"

const uint8_t ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9};

SoundSensor soundSensor(A0);
LedBar ledBar(ledPins);

void setup() {
  Serial.begin(115200);
  heart();
  ledBar.begin();
}

void loop() {
  soundSensor.update();
  int soundValue = soundSensor.getSmoothedValue();

  int size = ledBar.size();
  int activeCount = map(soundValue, 0, 200, 0, size);
  activeCount = constrain(activeCount, 0, size);

  ledBar.showLevel(activeCount);
}
