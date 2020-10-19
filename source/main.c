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
int main(void)
{
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0x0F; //all 8 pins as inputs  
	DDRC = 0xFF; PORTC = 0x00; //all 8 pins as outputs
	
	unsigned char cntavail;
    	while (1)
		{
		if(PINA == 0x00)
			{
			cntavail = 0x04;
			}
		else if((PINA == 0x01) || (PINA == 0x02) || (PINA == 0x04) || (PINA == 0x08))
			{
			cntavail = 0x03;
			}
		else if((PINA == 0x07) || (PINA == 0x0B) || (PINA == 0x0D) || (PINA == 0x0E))
			{
			cntavail = 0x01;
			}
		else if(PINA == 0x0F)
			{
			cntavail = 0x00;
			}
		else
			{
			cntavail = 0x02;
			}
		PORTC = cntavail;
		}
		
   return 1;    

}
