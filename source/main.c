/*	Author: kennethalvarez
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #3  Exercise #2
 *	Exercise Description: A car has a fuel-level sensor that sets PA3..PA0 to a value between 0 (empty) and 15 (full).
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
	DDRC = 0xFF; PORTC = 0x00;
	
    /* Insert your solution below */
    while (1) {
	if(PINA <= 2) {
		PORTC = 0x60; //0110 0000
	}
	else if((PINA <= 4) && (PINA > 2)) {
		PORTC = 0x70; //0111 0000
	}
	else if((PINA <= 6) && (PINA >= 5)) {
		PORTC = 0x38; //0011 1000
	}
	else if((PINA <= 9) && (PINA >= 7)) {
		PORTC = 0x3C; //0011 1100
	}
	else if((PINA <= 12) && (PINA >= 10)) {
		PORTC = 0x3E; //0011 1110
	}
	else if((PINA <= 15) && (PINA >= 13)) {
		PORTC = 0x3F ; //0011 1111
	}
    }
    return 1;
}
