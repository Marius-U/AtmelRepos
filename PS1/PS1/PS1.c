/*
 * PS1.c
 *
 * Created: 10/12/2015 7:19:35 PM
 *  Author: Marius
 */ 


#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/interrupt.h>
#include "Header/init.h"
#include "Header/segDisplay.h"
#include "Header/util.h"
#include "D:/AtmelRepos/PS1/PS1/Header/eeprom.h"

volatile uint8_t count = 0x00u;

int main(void)
{	
	initDisplay();
	initButtonISR();
	initLeds();
	initTimerB(0xF424u);
	initTimerA(0xFFu);	

	 while(1)
    {	
    }
}

ISR (TIMER1_COMPA_vect)
{
		PORTD ^= (1 << PORTD7);
}

ISR (TIMER0_COMPA_vect)  
{
	count++;
	if(count >= 100)
	{
			togle_Led(LED_1);
			count = 0;
	}
}

ISR(PCINT1_vect) {
	_delay_ms(80); //debounce
	if (PINC & (0x01u)) 
	{
		//Button was pressed!
		buttonCount = eeprom_read(0x00u);
		if(buttonCount < 10)
		{	
			buttonCount++;
			eeprom_write(0x00u,buttonCount);
			display(buttonCount);
		}
		else
		{
			buttonCount = 0x00;
			eeprom_write(0x00u, buttonCount);
			display(buttonCount);
		}
	} 
}