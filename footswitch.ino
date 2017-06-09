#include <EEPROM.h>
#include "footswitch.h"
#include "midi.h"

Footswitch::Footswitch (uint8_t fsw_pin, uint8_t mode_pin, uint8_t led_pin, uint8_t midi_control){
  this->fswBtn = new Button(fsw_pin, false);
  this->modeBtn = new Button(mode_pin, false);
  this->ledPin = led_pin;
  this->cc = midi_control;

  pinMode(this->ledPin, OUTPUT);

  this->load();
}

void Footswitch::save () {
  EEPROM.write(this->mem_addr(), this->fswBtn->momentary);
}

void Footswitch::load () {
  this->fswBtn->momentary = EEPROM.read(this->mem_addr());
  Serial.println(this->fswBtn->momentary);
}

// the led pin number seems like a good fixed value to use
uint8_t Footswitch::mem_addr() {
  return this->ledPin;
}

void Footswitch::update () {
  // essentially only one of the two following updates can happen at a time
  if (this->fswBtn->update()) {
    // the led always matches the footswitch's state
    this->led(this->fswBtn->state);
    // write the midi message
    Serial.write(MIDI_CHANNEL);
    Serial.write(this->cc);                   // control command
    Serial.write(this->fswBtn->state * 127);  // control's on/off value (0 or 127)

    // mode button was pushed, so toggle the footswitch's behavior
  } else if(this->modeBtn->update()) {
    this->fswBtn->momentary = !this->fswBtn->momentary;
    this->save();
  }
}

void Footswitch::led (bool on) {
  digitalWrite(this->ledPin, on);
}