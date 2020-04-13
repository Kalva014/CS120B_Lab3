/*	Author: kennethalvarez
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #3  Exercise #4
 *	Exercise Description: Read an 8-bit value on PA7..PA0 and write that value on PB3..PB0PC7..PC4
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif



int main(void) {
    /* Insert DDR and PORT initializations */
	DDRB = 0xFE; PORTB = 0x00; //Output except on lower nibble PB0 is input
	DDRD = 0x00; PORTD = 0x00; //Input
		
    /* Insert your solution below */
    while (1) {
	unsigned short totalWeight = PIND + (PINB & 0x01);
	unsigned char tmpB = 0x00;

	if((totalWeight > 70) || (totalWeight == 70)) { //airbag enabled
		tmpB = 0x02;		
	}
	else if((totalWeight > 5) && (totalWeight < 70)) {
		tmpB = 0x04;
	}
	else if(totalWeight < 5) {
		tmpB = 0x00;
	}
	
	PORTB = tmpB;
	
    }
    return 1;
}
