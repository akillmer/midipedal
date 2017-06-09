#include "footswitch.h"
#include "pedal.h"

#define DEBOUNCE 20

Footswitch * fsw[4];
Pedal * pedal;

void setup () {
  Serial.begin(115200); // for use with hairless-midiserial
  
  // a footswitch connects to two physical switches, an LED,
  // and an assigned midi control channel
  fsw[0] = new Footswitch(9, 14, 5, 80);
  fsw[1] = new Footswitch(8, 12, 4, 81);
  fsw[2] = new Footswitch(7, 11, 3, 82);
  fsw[3] = new Footswitch(6, 10, 2, 83);
  
  // expression pedal has a single analog input and an 
  // assigned midi control channel
  pedal = new Pedal(A6, 11);

  // indicate that the midi pedal is ready to go
  for (uint8_t i = 0; i < 4; i++) {
    fsw[i]->led(HIGH);
    delay(200);
  }
  for (uint8_t i = 0; i < 4; i++) {
    fsw[i]->led(LOW);
  }
}

void loop () {
  fsw[0]->update();
  fsw[1]->update();
  fsw[2]->update();
  fsw[3]->update();

  pedal->update();

  delay(DEBOUNCE);
}