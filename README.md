# 328PStopwatch
A Stopwatch Built with the Atmel328P Microprocessor

### Description
The Atmel328P is a microprocessor with a lot of power. In this laboratory activity I was tasked with wiring up an 8-bit register in tandem with the 238P to create a stop watch capable of counting time to a tenth of a second. The code presented in here takes advantage of the chips CTC Counting Mode, SPI Peripheral device, and several input and output pins on PORT B and C of the device.

### Hardware
The Hardware in this lab included:
 
  - Atmel328P Microprocessor
  - Shift Register
  - 16 mH Crystal
  - Timer Display
  - Several LEDs w/ resistors
  - 8 390 Ohm Resistors
  - Connecting Wire
  - Breadboard
  
### Software Integration
Developed in C, the code takes advantage of several operations handled swiftly by the processor of the Atmel328P. Most importantly, the code utilizes the SREG Global interrupt feature and the Interrupt Service Routine (ISR) to properly handle certain features of the code such as the CTC Timer and the Serial Peripheral Interface (SPI).

The code also creates several number 'identities' that translate a number into a binary representation of the number which is then passed and store into the 595 Register. For example, let us take the number 4:

```C
// Lets set the number 4 as an identity
#define four 0b0110111
/*    
     __ a
  f |  | b    Where we turn on every bit that we want display such that it looks like:    |  |
   g --                                                                                    --
  e |  | c                                                                                   |
     -- 
      d
*/
```
