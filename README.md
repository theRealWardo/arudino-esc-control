Arduino ESC Control
===================

This sketch uses an Arduino to control an ESC (Electronic Speed Controller) using serial input or a potentiometer.


Plug a potentiometer into analog pin 0.

Plug an ESC into digital pin 9.
You will need to ground your ESC controller as well.
You can optionally take power from your ESC, but be sure that the voltage is acceptable for your Arduino.  It should be about 5v.


Note that sending 0 does not work for most ESCs that expect some signal to equal the minumum throttle position.
