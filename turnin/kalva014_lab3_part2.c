/*	Author: kennethalvarez
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #3  Exercise #1
 *	Exercise Description: Count the number of 1s on ports A and B and output that number on port C.
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

unsigned char GetBit(unsigned char x, unsigned char k) { //USED FROM ZYBOOKS
   return ((x & (0x01 << k)) != 0);
}

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0x00;
	DDRB = 0x00; PORTB = 0x00;
	DDRC = 0xFF; PORTC = 0x00;
	unsigned char cntA = 0;
	unsigned char cntB = 0;
    /* Insert your solution below */
    while (1) {
	for(unsigned char i = 0; i < 8; i++) {
		if(GetBit(PINA, i)) {
			++cntA;
		}
		if(GetBit(PINB, i)) {
			++cntB;
		} 
	}

	PORTC = cntA + cntB;
    }
    return 1;
}
