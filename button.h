#ifndef H_BUTTON
#define H_BUTTON

class Button {
  bool prevState;     // button's state (LOW/HIGH) from the previous loop
  uint8_t pin;        // digital input pin

  public:
    bool state;       // button's current state (LOW/HIGH)
    bool momentary;   // momentary or toggle behavior

    Button (uint8_t pin, bool momentary);
    bool update ();   // returns true if the button's state has changed
};

#endif