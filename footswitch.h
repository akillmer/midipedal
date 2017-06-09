#ifndef H_FOOTSWITCH
#define H_FOOTSWITCH

#include "button.h"

class Footswitch {
  Button *fswBtn;     // the footswitch
  Button *modeBtn;    // mode button to toggle footswitch's behavior
  uint8_t ledPin;     // led indicator
  uint8_t cc;         // midi control channel

  void save ();       // save mode type (momentary/toggle) to EEPROM
  void load ();       // load mode type from EEPROM
  uint8_t mem_addr(); // memory adddress in EEPROM

  public:
    Footswitch (uint8_t fsw_pin, uint8_t mode_pin, uint8_t led_pin, uint8_t midi_control);
    void update ();
    void led (bool on);
};

#endif