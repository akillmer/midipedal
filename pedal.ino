#include "pedal.h"

Pedal::Pedal (uint8_t pin, uint8_t midi_control) {
  this->pin = pin;
  this->cc = midi_control;
  pinMode(this->pin, INPUT);
}

void Pedal::update () {
  int v = analogRead(this->pin);
  uint8_t value = map(v, 0, 1023, 0, 127);
  // the loss in resolution from map() helps filter out most jitters

  if (this->value != value) {
    this->value = value;
    Serial.write(MIDI_CHANNEL); 
    Serial.write(this->cc);     // control change command
    Serial.write(this->value);  // control's value (0 - 127)
  }
}