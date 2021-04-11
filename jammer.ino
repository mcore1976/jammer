/*
 * 433 MHz key fob jammer based on ATTINY13A and FS1000A RF transmitting module
 * PIN B2 of ATTINY13A is connected to DATA IN of FS1000A transmitter board
 * both ATTINY13 and FS1000A are connected to 5V power supply
 * internal clock 9.6MHz with division by 8 = 1.2MHz effective clock
 * 
 */

#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>

//0 is P0, 1 is P1, 2 is P2, etc. - unlike the analog inputs, for digital outputs the pin number matches.
#define	FS1000A_DATA_PIN    2

int main(void)
{
        uint8_t widthsize;
        uint8_t sequence;
        uint8_t duration;

        // SET OUTPUT PIN TO STEER FS1000A DATA IN
         pinMode(FS1000A_DATA_PIN, OUTPUT);

        digitalWrite(FS1000A_DATA_PIN, LOW);

    /* neverending loop */
    while (1) {

        widthsize = 0;
        sequence = 0;
        duration = 0;

        // generating SQUARE WAVE for FS1000A DATA INPUT
        // we send 50 sequences of 3 pulses different width ( from 50us to 2.5 ms )
        // to generate enough distortion on 433 MHz frequency
	// and get widest possible bandwith covered on spectrum
        
        for(sequence=1; sequence<50; sequence++)
            {
         
        // only 10 pulses for each width
            for(duration=1; duration<=3; duration++)
                {  

                   digitalWrite(FS1000A_DATA_PIN, HIGH);     // bring DATA PIN up

                   // starting from 50usec width Pulses
                   for(widthsize=1; widthsize<=(1+sequence); widthsize++)      _delay_us (50);

                   digitalWrite(FS1000A_DATA_PIN, LOW);     // drag DATA PIN down

                    // starting from 50usec Pulses
                   for(widthsize=1; widthsize<=(1+sequence); widthsize++)     _delay_us (50);
  
                }; // end of DURATION loop

            }; // end of SEQUENCE variable loop

      }; // neverending loop 

};  // end of MAIN
