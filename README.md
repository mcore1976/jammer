# jammer
Very simple 433MHz RF jammer for wireless car and garage keys

433 MHz key fob jammer based on ATTINY13A and FS1000A RF transmitting module
PIN B2 of ATTINY13A is connected to DATA IN of FS1000A transmitter board
both ATTINY13 and FS1000A are connected to 5V power supply. 

The source code for ATTINY13 is generating set of square waves - 20 sequences of 100 pulses with different width to put enough noise on 433 frequency. The device can affectively jam all wireless key fobs in 100 meter range f.ex. in underground garage.


