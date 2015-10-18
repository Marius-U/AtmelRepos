/*
 * PS1.c
 *
 * Created: 10/12/2015 7:19:35 PM
 *  Author: Marius
 */ 


#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include <D:/Atmel Toolchain/AVR8 GCC/Native/3.4.1061/avr8-gnu-toolchain/avr/include/avr/interrupt.h>
#include "Header/init.h"
#include "Header/segDisplay.h"

volatile uint8_t blink = 0x00u;
int main(void)
{	
	initDisplay();
	initButtonISR();
	initLeds();
	initTimer();
	
	uint8_t i = 0;
	
	 while(1)
    {
		if(i < 10)
		{
			_delay_ms(500);
			display(i);
			i++;
		}
		else
		{
			i = 0x00;
		}
		
    }
}
ISR (TIMER1_COMPA_vect)
{
		PORTD ^= (1 << PORTD5);
}
ISR(PCINT0_vect) {
	if (PINC & _BV(PC1)) 
	{
		PORTD ^= (1 << 3);
	}
	_delay_ms(40); 
}