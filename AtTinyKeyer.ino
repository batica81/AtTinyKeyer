/* 
This little program can help you use a straight key or paddle keyer output with 
Morse code learning apps that support keying via the PC/phone keyboard, like Morse Mania
or PCW Fistcheck. You can also use Morseino as a keyer, and practice letter and word timing.

Program is intended to be flashed to a $2 Digispark Attiny85 microcontroler module. 
Other (optional) component is a stereo jack to connect it to your paddle. 
OTG USB adapter would be needed for phone connetion.

You need to connect pin PB0 to tip and GND to ground of your key connector, and connect 
Attiny to your PC/phone. Polarity is important if connecting to a keyer or Morserino. 
Please make sure your keyer has proper (opto) isolation on its radio connector. 

The controller will emulate a keyboard and send the needed character to the app once 
you key down. There shouldn't be too much delay.

The program is created by YU4HAK, based on code snippets found here and there, 
and is free in every possible sense, no attribution needed. 
More detailed build instructions will hopefully come soon. 

73
*/


#include "DigiKeyboard.h" // The other one does not work.

void setup() {
    // Setting up input pin to PB0
    pinMode(0, INPUT_PULLUP);
    digitalWrite(0, HIGH);
}

void loop() {
    if (digitalRead(0) == LOW)
    {
      digitalWrite(1, HIGH); // Blink led
      // Choose one character to send on key down, leave others commented out.
      
      // If you need some other character, look at the list here: https://www.usb.org/sites/default/files/documents/hut1_12v2.pdf 
      // or rummage through DigiKeyboard.h file.
      
      // DigiKeyboard.sendKeyPress(79); // "Right Arrow" key, used for PCW Fistcheck 
      // DigiKeyboard.sendKeyPress(0, MOD_CONTROL_RIGHT); // "Right Control" key, used for Vband 
      DigiKeyboard.sendKeyPress(44); // "Space" key, used for Morse Mania

      // DigiKeyboard.sendKeyPress(79, 44 | MOD_CONTROL_RIGHT); // or try all three at once! (may not work on Android)
     
    } else {
      digitalWrite(1, LOW); // Blink led
      DigiKeyboard.sendKeyPress(0); // Unpress the key.
    }
    DigiKeyboard.delay(2); // Not sure about the optimal value, but this seems to work.
}
