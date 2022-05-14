# AtTinyKeyer
Simulates a keystroke on a keyboard when pin pulled down.


This little program can help you use a straight key or paddle keyer output with 
Morse code learning apps that support keying via the PC/phone keyboard, like Morse Mania, Morse-x
or PCW Fistcheck. You can also use Morserino as a keyer, and practice letter and word timing.

Program is intended to be flashed to a $2 Digispark Attiny85 microcontroller module. 
Other (optional) component is a stereo jack to connect it to your paddle. 
USB OTG adapter is needed for phone connection.

---

You need to connect pin PB0 to tip and GND to ground of your key connector, and connect 
Attiny to your PC/phone. Polarity is important if connecting to a keyer or Morserino. 
Please make sure your keyer has proper (opto) isolation on its radio connector. 

The controller will emulate a keyboard and send the needed character to the app once 
you key down. There shouldn't be any noticeable delay on Windows, Android, native Linux,
while Wine on Linux is also usable.

****** UPDATE v2.0 *******
This version has two keying options, selectable by wire connection, or a switch.
Wire for other character(s) should be connected to pin PB2 (we skip PB1 as it is connected
to builtin LED). You can add switch or move the wire manually when you want to use
a different program. DO NOT connect both at the same time!!! 

---

For setting up Arduino IDE in order to program Attiny use this tutorial:

http://digistump.com/wiki/digispark/tutorials/connecting

Or in broad strokes:

Open Preferences, and in the box labeled "Additional Boards Manager URLs" enter:
http://digistump.com/package_digistump_index.json

Go to Boards Manager and add Digispark

If Arduino IDE reports it won't run the last .bat file that installs the Windows driver,
find it and run it manually.


For programming select the settings:

Board- Digispark Default 16.5mhz

Programmer - micronucleus

---

Sometimes the flashing does not go through on the first run. It either hangs at 60% or finishes
but the device is not working. Try again and again, possibly changing USB ports. This happened
many times on Windows 10 for me, but rarely on Linux.


![alt text](https://github.com/batica81/AtTinyKeyer/blob/master/schematic.jpg?raw=true)

![alt text](https://github.com/batica81/AtTinyKeyer/blob/master/device.jpg?raw=true)

---

Short video tutorial (in Serbian) https://www.youtube.com/watch?v=BuLn2ZkDHes 

---

The program is created by YU4HAK, based on code snippets found here and there, 
and is free in every possible sense, no attribution needed.
73
