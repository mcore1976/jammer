# jammer
Very simple 433MHz (EUROPE/ASIA) or 315MHz (USA) RF jammer for keyless cars and garage keys

433/315 MHz key fob jammer based on ATTINY13A and FS1000A RF transmitting module. 
PIN B2 of ATTINY13A is connected to DATA IN of FS1000A transmitter board.
Both ATTINY13 and FS1000A are connected to 5V power supply.  You can attach several FS1000A to the same ATTINY13 for better results as well as modify FS1000A board by adding regulated capacitor 5pF-30pF for fine tuning jammed frequiencies (see videos below)
Please notice that SAW Oscillator used in FS1000A modules has 433.92MHz and has to be fine tuned to jamm particular frequency.

The source code for ATTINY13 is generating set of square waves - 50 sequences of 3 pulses each with different width to put enough noise on 433/315Mhz frequency. The device can effectively jam all wireless keys in 100 meter range f.ex. in underground garage.

Remember to buy appropriate FS1000A version for your location (check frequency).

To see how it works look here : https://www.youtube.com/watch?v=C7fyKEQMs7c    an here - modified version  https://www.youtube.com/watch?v=F10x1WN3X4Q

-------------------------------------------------------------------------------------------------------------------------------

COMPILATION ON LINUX PC :

Link to video how to program the chip : https://www.youtube.com/watch?v=7klgyNzZ2TI

The script attached in repository ( "compileattiny" ) can be used to upload data to the chip if you have Linux machine with following packages : "gcc-avr", "binutils-avr" (or sometimes just "binutils"), "avr-libc", "avrdude" and optionally "gdb-avr"(debugger only if you really need it) . For example in Ubuntu download these packages using command : "sudo apt-get install gcc-avr binutils-avr avr-libc gdb-avr avrdude". After this is done you can run from directory you downloaded the github files appropriate compilation script by commands

    "sudo chmod +rx compileattiny" and "sudo ./compileattiny"

-------------------------------------------------------------------------------------------------------------------------------

COMPILATION ON WINDOWS PC :

If you have Windows 10 machine please follow this tutorial to download and install full AVR-GCC environment for Windows : http://fab.cba.mit.edu/classes/863.16/doc/projects/ftsmin/windows_avr.html with latest compiler from Microchip/Atmel.

After it is done please use "compileattiny.bat"  for compilation inside directory where you have downloaded "main.c" file. You have to be logged as Windows Administrator to use avrdude software.

PROGRAMMING THE ATTINY / ATMEGA / ARDUINO - connecting cables to the chip :

To upload program code to the chip using cheapest USBASP programmer (less than 2 USD on eBay/Aliexpress) look at this page : http://www.learningaboutelectronics.com/Articles/Program-AVR-chip-using-a-USBASP-with-10-pin-cable.php , because we are not using ARDUINO bootloader here (especially for chips like ATTINY)
