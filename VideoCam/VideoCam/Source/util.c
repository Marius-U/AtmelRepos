/*
 * util.c
 *
 * Created: 10/19/2015 8:58:35 PM
 *  Author: Marius
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include "D:\AtmelRepos\VideoCam\VideoCam\Header\util.h"

volatile uint8_t led3 ;

void led_ON()
{
	PORTC |= (1 << PORTC5);
}

void led_OFF()
{
	PORTC &= ~(1 << PORTC5);
}

void led_Toggle(void)
{
	PORTC ^= (1 << PORTC5);
}
void motorsSt(uint8_t value)
{
	OCR0B = value;
	PORTD |= (1 << PORTD0) | (1 << PORTD2);
	PORTD &= ~(1 << PORTD1) & ~(1 << PORTD3);
}
void motorsDr(uint8_t value)
{
	OCR0B = value;
	PORTD |= (1 << PORTD1) | (1 << PORTD3);
	PORTD &= ~(1 << PORTD0) & ~(1 << PORTD2);
}
void motorsStop(void)
{
	PORTD &= 0xE0u;
}