#pragma once
#include <Arduino.h>
#include "../Filter/MedianFilter.h"

class SoundSensor {
  private:
    uint8_t _analogPin;
    int _smoothedValue = 0;
    MedianFilter<> _medianFilter;

  public:
    explicit SoundSensor(uint8_t analogPin);

    void begin();
    void update();

    int getAnalogValue() const;
    int getSmoothedValue() const;
};
