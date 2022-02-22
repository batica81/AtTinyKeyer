# AtTinyKeyer
Simulates a keystroke on a keyboard when pin pulled down.


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
