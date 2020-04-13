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
	DDRA = 0x00; PORTA = 0x00;
	DDRB = 0xFF; PORTB = 0x00;
	DDRC = 0xFF; PORTC = 0x00;

    /* Insert your solution below */
    while (1) {
	unsigned char tmpA_upperNibble = 0x00;
	unsigned char tmpA_lowerNibble = 0x00;
	
	tmpA_upperNibble =  PINA & 0xF0;
	tmpA_lowerNibble = PINA  & 0x0F;

	PORTB = tmpA_upperNibble >> 4;
	PORTC = tmpA_lowerNibble << 4;
    }
    return 1;
}
