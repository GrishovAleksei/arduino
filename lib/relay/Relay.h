#pragma once
#include <Arduino.h>

class Relay {
  private:
    uint8_t _pin;
    bool _state;

  public:
    Relay(uint8_t relayPin, uint8_t buttonPin);

    void begin();

    void on();
    void off();
    void toggle();
    bool getState() const;
};
