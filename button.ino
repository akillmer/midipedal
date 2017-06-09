#include "button.h"

Button::Button (uint8_t pin, bool momentary) {
  this->pin = pin;
  this->momentary = momentary;
  pinMode(this->pin, INPUT);
}

bool Button::update () {
  bool state = digitalRead(this->pin);
  bool dirty = false;   // whether the button's state has changed

  if (state != this->prevState) {
    if (this->momentary) {
      this->state = state;
      dirty = true;
    } else if (state == HIGH) {   // only toggle when switch is HIGH
      this->state = !this->state;
      dirty = true;
    }
  }

  this->prevState = state;
  return dirty;
}