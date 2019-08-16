/*
 * 433 MHz key fob jammer based on ATTINY13A and FS1000A RF transmitting module
 * PIN B2 of ATTINY13A is connected to DATA IN of FS1000A transmitter board
 * both ATTINY13 and FS1000A are connected to 5V power supply
 * 
 */

#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>

#define	FS1000A_DATA_HIGH()		(PORTB |= _BV(FS1000A_DATA_PIN))
#define	FS1000A_DATA_LOW()		(PORTB &= ~_BV(FS1000A_DATA_PIN))
#define	FS1000A_DATA_OUTPUT()		(DDRB |= _BV(FS1000A_DATA_PIN))

// Main Settings
#define	FS1000A_DATA_PIN			PB2

int main(void)
{
        uint8_t widthsize;
        uint8_t sequence;
        uint8_t duration;

        // SET OUTPUT PIN TO STEER FS1000A DATA IN
        FS1000A_DATA_OUTPUT();
        FS1000A_DATA_LOW();

	/* neverending loop */
    while (1) {

        widthsize = 0;
        sequence = 0;
        duration = 0;

        // generating SQUARE WAVE for FS1000A DATA INPUT
        // we send 20 sequences of 50 pulses different width ( from 50us to 1 ms )
        // to generate enough distortion on 433 MHz frequency
        
        for(sequence=1; sequence<20; sequence++)
        {


        for(duration=1; duration<50; duration++)
          {  

            FS1000A_DATA_HIGH();  // bring DATA PIN up
   
           for(widthsize=1; widthsize<=sequence; widthsize++)
             {
               // now delay for pulse width
               // generated at  http://www.bretmulvey.com/avrdelay.html
               // Delay 50 cycles
               // 50us at 1 MHz
               asm volatile (
                "    ldi  r18, 16"	"\n"
                "1:  dec  r18"	"\n"
                "    brne 1b"	"\n"
                "    rjmp 1f"	"\n"
                "1:"	"\n"
                );
              };  // end of widthsize for loop

            FS1000A_DATA_LOW();  // drag DATA PIN down

           for(widthsize=1; widthsize<=sequence; widthsize++)
             {
               // now delay for pulse width
               // generated at  http://www.bretmulvey.com/avrdelay.html
               // Delay 50 cycles
               // 50us at 1 MHz
               asm volatile (
                "    ldi  r18, 16"	"\n"
                "1:  dec  r18"	"\n"
                "    brne 1b"	"\n"
                "    rjmp 1f"	"\n"
                "1:"	"\n"
                );
              };  // end of WIDTHSIZE variable for loop

           }; // end of DURATION loop

         }; // end of SEQUENCE variable loop

      }; // neverending loop 

};  // end of MAIN



