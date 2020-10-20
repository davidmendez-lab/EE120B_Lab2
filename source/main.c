/*	Author: David MEndez
 *  Partner(s) Name: 
 *	Lab Section: 022
 *	Assignment: Lab 2  Exercise 4
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
int main(void)
{
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF; //all 8 pins as inputs for seat 1  
	DDRB = 0x00; PORTB = 0xFF; //all 8 pins as inputs for seat 2
	DDRC = 0x00; PORTC = 0xFF; //all 8 pins as inputs for seat 3
	DDRD = 0xFF; PORTD = 0x00; //all 8 ports as outputs 

	unsigned char tmpA = 0x00; 
	unsigned char tmpB = 0x00; 
	unsigned char tmpC = 0x00;

	unsigned char total = 0x00;
	unsigned char overweight = 0x00;
	unsigned char unbalanced = 0x00;
    	while (1)
	{
		tmpA = PINA;
		tmpB = PINB;
		tmpC = PINC;

		total = (tmpA + tmpB + tmpC);
		//if all three passengers weight combined exceeds 140 kg then PD0 = 1
		if(total > 0x8C) 
		{
			overweight = 0x01;
		}
		else
		{
			overweight = 0x00;
		}
		//if the difference in weight between the two side seats exceeds 80 PD1 = 1.
		if (tmpC > tmpA)
		{
			if((tmpC - tmpA) > 0x50)
			{
				unbalanced = 0x02;
			}
		}
		else if (tmpA > tmpC)
		{
			if((tmpA - tmpC) > 0x50)
			{
				unbalanced = 0x02;
			}
		}
		else 
		{
			if ((tmpA == tmpC) || (tmpC == tmpA))
			{
				unbalanced =0x00;
			}
		}
		PORTD = ((total << 2) & 0xFC) | (overweight + unbalanced);
	}
   return 1;    
}
