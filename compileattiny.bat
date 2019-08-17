del *.elf
del *.o
del *.hex
avr-gcc -mmcu=attiny13 -std=gnu99 -Wall -Os -o main.elf main.c -w
avr-objcopy -j .text -j .data -O ihex main.elf main.hex
avr-size --mcu=attiny13 --format=avr main.elf
avrdude -c usbasp -p attiny13  -U flash:w:"main.hex":a
