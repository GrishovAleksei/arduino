#include <Arduino.h>
#include "heart.h"
#include "SoundSensor.h"

SoundSensor soundSensor(A0);

void setup() {
  Serial.begin(115200);
  heart();
}

void loop() {
  soundSensor.update();
  int soundValue = soundSensor.getSmoothedValue();

  Serial.println(soundValue); //print the value of sound sensor
}
