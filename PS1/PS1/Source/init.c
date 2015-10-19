/*
 * init.c
 *
 * Created: 10/18/2015 2:05:38 PM
 *  Author: Marius
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>
#include "D:\AtmelRepos\PS1\PS1\Header\init.h"
#include "D:\AtmelRepos\PS1\PS1\Header/segDisplay.h"
#include "D:/AtmelRepos/PS1/PS1/Header/eeprom.h"

void initDisplay()
{
	/* Initialize the Data Direction Registers as outputs for the 7 segments display*/
	DDRB |= (1 << DDB0) | (1 << DDB1) | (1 << DDB2) | (1 << DDB3) | (1 << DDB4) | (1 << DDB5);
	DDRD |= (1 << DDD6) | (1 << DDD7);
	display(eeprom_read(0x00u));
	
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
void initTimerB(uint16_t countValue)
{
	cli();
	TCCR1B |= (1 << WGM12);
	TCCR1B |= (1 << CS12);
	OCR1A   = countValue;
	TIMSK1 |= (1 << OCIE1A);
	sei(); 
}
void initTimerA(uint8_t countValue)
{
	cli();
	TCCR0A |= (1 << WGM01);		// Set the Timer Mode to CTC
	TCCR0B |= (1 << CS02) | (1 << CS00); 		// set prescaler to 1024 and start the timer
	OCR0A = countValue;			// Set the value that you want to count to
	TIMSK0 |= (1 << OCIE0A);    //Set the ISR COMPA vect
	sei();
}
void initButtonISR()
{
	cli();
	/*Initializing PC1 as input for the SW button with pull down resistor.*/
	DDRC |= (1 << DDC0);
	PORTC &= ~(1 << PORTC0);
	
	PCICR  |= (1 << PCIE1);
	PCMSK1 |= (1 << PCINT8);
	sei();
}