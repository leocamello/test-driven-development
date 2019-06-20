# Test-Driven Development for Embedded C

Test-driving an LED driver.

## Requirements

Our system uses LEDs to communicate status to the users or developers of the system.

What is the LED driver supposed to do?

- The LED driver controls 16 two-state LEDs.
- The driver can turn on or off an individual LED without affecting the others.
- The driver can turn all LEDs on or off with a single interface call.
- The user of the driver can query the state of any LED.

How will the driver interact with the hardware?

- At power-on, the hardware default is for LEDs to be latched on. They must be turned off by the software.
- The LEDs are memory-mapped to a 16-bit word (at an address to be determined).
- A 1 in a bit position lights the corresponding LED. 0 turns it off.
- The least significant bit corresponds to LED 1. The most significant bit corresponds to LED 16.

## Test List

LED Driver Tests:

- All LEDs are off after the driver is initialized.
- A single LED can be turned on.
- A single LED can be turned off.
- Multiple LEDs can be turned on/off.
- Turn on all LEDs.
- Turn off all LEDs.
- Query LED state.
- Check boundary values.
- Check out-of-bounds values.

## Book

| | |
|-----|-----|
| ![](https://github.com/leocamello/test-driven-development/raw/master/images/tdd_embeddedc.png "Test-Driven Development for Embedded C") | Test-Driven Development for Embedded C |
| | |
