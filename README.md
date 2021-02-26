
# DC Motor

This is a library for running a DC Motor with an Arduino and a L293D motor controller.
It relies on the bidirectional circuit in the following document: https://www.ti.com/lit/ds/symlink/l293d.pdf?ts=1614037260430&ref_url=https%253A%252F%252Fwww.ti.com%252Fproduct%252FL293D

Currently, the library only allows for modest control of the motors and still requires much testing to ensure the motor runs correctly.

More functionality needs to be added.

The library also lacks some safeguards to ensure code that should throw errors does, and that users can't forget to initialize aspects of the motor object.

Things to do:
- [ ] Add a safeguard to ensure all pins are initialized before the motor can be run.
- [ ] Add functions that can change which pins are being used after initialization.
- [ ] Add a safeguard to prevent two outputs being assigned to the same pin.
- [ ] Create a function that swaps directionality instead of having right and left directions being hard coded.