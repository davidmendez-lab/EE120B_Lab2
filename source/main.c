/*	Author: David MEndez
 *  Partner(s) Name: 
 *	Lab Section: 022
 *	Assignment: Lab 1  Exercise 1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif


//inputs = pin outputs = port
int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF; //all 8 pins as inputs  
	DDRB = 0xFF; PORTB = 0x00; //all 8 pins as outputs
	
	
    	while (1) 
	{
		if(PINA == 0x01)
		{
			PORTB = 0x01;
		}
		else 
		{
			PORTB = 0x00;
		}
	}
   return 1;    
}
