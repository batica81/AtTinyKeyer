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

If you need some other character, look at the list here: https://www.usb.org/sites/default/files/documents/hut1_12v2.pdf
or rummage through DigiKeyboard.h file.

The program is created by YU4HAK, based on code snippets found here and there, 
and is free in every possible sense, no attribution needed. 
More detailed build instructions will hopefully come soon. 

73


****** UPDATE v3.0 *******
This version has iambic emulation. It works on vBand, but something is not right on MorseMania. Straightkey option is wotking fine everywhere.
**************************

*/

#include "DigiKeyboard.h"  // The other one does not work.

boolean readValueLeft;
boolean readValueRight;

int inputLeft = 0;   // Setting up input pin to PB0
int inputRight = 2;  // Setting up input pin to PB2
int ledTonePin = 1;

void setup() {
  pinMode(inputLeft, INPUT_PULLUP);
  digitalWrite(inputLeft, HIGH);

  pinMode(inputRight, INPUT_PULLUP);
  digitalWrite(inputRight, HIGH);
}

void loop() {
  readValueLeft = !digitalRead(inputLeft);
  readValueRight = !digitalRead(inputRight);

  if (readValueLeft == true) {
    tone(ledTonePin, 700);  // Play tone

    // DigiKeyboard.sendKeyPress(KEY_A, MOD_CONTROL_LEFT);   // MorseMania (iambic mode possibly broken), vBand (straightKey and paddle)
    DigiKeyboard.sendKeyPress(79, MOD_CONTROL_LEFT);  // PCW FistCheck (79 - rightArrow, straightKey only), vBand (straightKey and paddle), MorseMania (straightKey only)
  }

  if (readValueRight == true) {
    tone(ledTonePin, 700);  // Play tone

    // DigiKeyboard.sendKeyPress(KEY_S);              // MorseMania (iambic mode possibly broken), do not combine S and Ctrl, it causes issues in Windows
    DigiKeyboard.sendKeyPress(79, MOD_CONTROL_RIGHT);  // PCW FistCheck (79 - rightArrow, straightKey only), vBand (straightKey and paddle)
  }

  // else {
  if (readValueLeft == false && readValueRight == false) {
    noTone(ledTonePin);            //Stop tone
    DigiKeyboard.sendKeyPress(0);  // Unpress the key.
  }

  DigiKeyboard.delay(2);  // Not sure about the optimal value, but 2 seems to work.
}
