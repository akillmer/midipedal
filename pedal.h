#ifndef H_PEDAL
#define H_PEDAL

class Pedal {
  uint8_t pin;    // analog input
  uint8_t value;  // pedal's current analog reading (0 - 127)
  uint8_t cc;     // midi control change command
  public:
    Pedal (uint8_t pin, uint8_t midi_control);
    void update ();
};

#endif