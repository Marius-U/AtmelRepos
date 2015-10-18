/*
 * init.c
 *
 * Created: 10/18/2015 2:05:38 PM
 *  Author: Marius
 */ 
#include <avr/io.h>
#include <D:/Atmel Toolchain/AVR8 GCC/Native/3.4.1061/avr8-gnu-toolchain/avr/include/avr/interrupt.h>
#include "D:\AtmelRepos\PS1\PS1\Header\init.h"

void initDisplay()
{
	/* Initialize the Data Direction Registers as outputs for the 7 segments display*/
	DDRB |= (1 << DDB0) | (1 << DDB1) | (1 << DDB2) | (1 << DDB3) | (1 << DDB4) | (1 << DDB5);
	DDRD |= (1 << DDD6) | (1 << DDD7);
	
}
void initLeds()
{
	  DDRD |= (1 << DDD5) | (1 << DDD3) | (1 << DDD2);
	  PORTD |= (1 << 2) | (1 << 3) | (1 << 5);
}
void initButton()
{
	/*Initializing PC1 as input for the SW button with pull down resistor.*/
	DDRC &= ~(1 << DDC1);
	PORTC &= ~(1 << PORTC1);
}
void initTimer()
{
	cli();
	TCCR1B |= (1 << WGM12);
	TCCR1B |= (1 << CS12);
	OCR1A   = 0xF424u;
	TIMSK1 |= (1 << OCIE1A);
	sei(); 
}
void initButtonISR()
{
	cli();
	PCICR |= (1 << PCIE1);
	PCMSK1 |= (1 << PCINT9);
	sei();
}