#pragma once
#include <Arduino.h>

template <size_t N>
class LedBar {
  private:
    const uint8_t (&_pins)[N];

  public:
    LedBar(const uint8_t (&pins)[N]) : _pins(pins) {}

    void begin() {
      for (size_t i = 0; i < N; i++) {
        pinMode(_pins[i], OUTPUT);
        digitalWrite(_pins[i], LOW);
      }
    }

    void showLevel(size_t level) {
      if (level > N) {
        level = N;
      }

      for (size_t i = 0; i < N; i++) {
        digitalWrite(_pins[i], i < level ? HIGH : LOW);
      }
    }

    constexpr size_t size() const {
      return N;
    }
};