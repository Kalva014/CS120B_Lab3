/*	Author: kennethalvarez
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #3  Exercise #3
 *	Exercise Description: PC7 should light a "Fasten seatbelt" icon
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
	unsigned char tmpC = 0x00;

	if ((PINA & 0x0F) == 0) {
		tmpC = 0x40;
	}
	else if((PINA & 0x0F) <= 2) {
		tmpC = 0x60; //0110 0000
	}
	else if(((PINA & 0x0F) <= 4) && ((PINA & 0x0F) > 2)) {
		tmpC = 0x70; //0111 0000
	}
	else if(((PINA & 0x0F) <= 6) && ((PINA & 0x0F) >= 5)) {
		tmpC = 0x38; //0011 1000
	}
	else if(((PINA & 0x0F) <= 9) && ((PINA & 0x0F) >= 7)) {
		tmpC = 0x3C; //0011 1100
	}
	else if(((PINA & 0x0F) <= 12) && ((PINA & 0x0F) >= 10)) {
		tmpC = 0x3E; //0011 1110
	}
	else if(((PINA & 0x0F) <= 15) && ((PINA & 0x0F ) >= 13)) {
		tmpC = 0x3F ; //0011 1111
	}

	if(((PINA & 0x10) == 0x10) && ((PINA & 0x20) == 0x20) && ((PINA & 0x40) != 0x40)) { // set PC7 to 1
		PORTC = 0x80 | tmpC; 
	}
	else {
		PORTC = tmpC;
	}
    }
    return 1;
}
