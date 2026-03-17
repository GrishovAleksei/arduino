#include "SoundSensor.h"

SoundSensor::SoundSensor(uint8_t analogPin)
  : _analogPin(analogPin) {}

void SoundSensor::begin() {
  int initial = analogRead(_analogPin);
  _smoothedValue = initial;
}

void SoundSensor::update() {
  int raw = analogRead(_analogPin);
  _smoothedValue = _medianFilter.update(raw);
}

int SoundSensor::getAnalogValue() const {
  return analogRead(_analogPin);
}

int SoundSensor::getSmoothedValue() const {
  return _smoothedValue;
}