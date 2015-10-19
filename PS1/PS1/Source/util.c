/*
 * util.c
 *
 * Created: 10/19/2015 8:58:35 PM
 *  Author: Marius
 */ 

#include <avr/io.h>

void led_ON(uint8_t led)
{
	PORTD &= ~(1 << led);
}

void led_OFF(uint8_t led)
{
	PORTD |= (1 << led);
}

void togle_Led(uint8_t led)
{
	PORTD ^= (1 << led);
}