# midipedal #
A simple MIDI pedal board with expression pedal support, designed for ~~guitarists~~ myself in mind. My particular build uses an Arduino Nano that has a CH340G driver. As a result I need to use [hairless-midiserial](http://projectgus.github.io/hairless-midiserial/) to convert the serial messages to MIDI.

## Hardware ##
The hardware build itself is very simple. There are four footswitches and four mode buttons with an integrated LED light ring, all hooked up as usual.

The expression pedal input is a 1/4" TRS jack. A 5V signal is sent through the ring and is returned through the tip to an analog input. The sleeve is connected to ground. Between the analog input and ground is a 0.1uf capacitor and a pull down resistor.

## Mode Toggling ##
The footswitches are momentary type buttons. To change a footswitch's behavior from momentary to toggle you press its dedicated mode button. This also saves the footswitch's behavior to EEPROM.

## Expression Pedal ##
At first I thought I would have to write code for calibrating the expression pedal but this wasn't the case. The readings are also jitter free, meaning there's no additional code needed for smoothing out the values. This is because the analog input's reading gets mapped from a 10 bit value (0 - 1023) to an 8 bit value (0 to 127, effectively). The loss in resolution helps stabilize the values.

### If I were to build this again ###
I would probably pick an Arduino module that could operate as a class compliant MIDI device (the Uno or even the Micro comes to mind). Or I would design and build a PCB with an ATTiny84 using V-USB. It would also be really cool to integrate Bluetooth connectivity but since it's powered through USB then what's the point? But you know, everything's better with Bluetooth.