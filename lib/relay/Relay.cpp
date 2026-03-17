#include "Relay.h"

Relay::Relay(uint8_t relayPin, uint8_t buttonPin)
  : _relayPin(relayPin),
  _buttonPin(buttonPin),
  _state(false) {}

void Relay::begin() {
  pinMode(_relayPin, OUTPUT);
  pinMode(_buttonPin, INPUT_PULLUP);
	off();
}

void Relay::on() {
  _state = true;
  digitalWrite(_relayPin, HIGH);
}

void Relay::off() {
  _state = false;
  digitalWrite(_relayPin, LOW);
}

void Relay::toggle() {
  _state ? off() : on();
}

bool Relay::getState() const {
  return _state;
}