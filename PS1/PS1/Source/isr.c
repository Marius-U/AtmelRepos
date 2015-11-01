/*
 * isr.c
 *
 * Created: 11/1/2015 7:35:21 PM
 *  Author: Marius
 */ 
#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/interrupt.h>
#include "D:/AtmelRepos/PS1/PS1/Header/init.h"
#include "D:/AtmelRepos/PS1/PS1/Header/segDisplay.h"
#include "D:/AtmelRepos/PS1/PS1/Header/util.h"
#include "D:/AtmelRepos/PS1/PS1/Header/uart.h"
#include "D:/AtmelRepos/PS1/PS1/Header/adc.h"
#include "D:/AtmelRepos/PS1/PS1/Header/eeprom.h"
#include "D:/AtmelRepos/PS1/PS1/Header/scheduler.h"

volatile uint16_t count = 0x00u;
volatile uint8_t led3;

ISR (USART_RX_vect)
{
	led3 = UDR0;
}

ISR (TIMER1_COMPA_vect)
{
	PORTD ^= (1 << PORTD7);
}

ISR (TIMER0_COMPA_vect)
{
	count++;
	scheduler();
}

ISR(PCINT1_vect) {
	_delay_ms(100); //debounce
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