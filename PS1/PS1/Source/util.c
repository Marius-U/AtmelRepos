/*
 * util.c
 *
 * Created: 10/19/2015 8:58:35 PM
 *  Author: Marius
 */ 

#include <avr/io.h>
#include "D:\AtmelRepos\PS1\PS1\Header\util.h"

volatile uint8_t led2 = 0x00;

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

void check_Led2(void)
{
	if(led2 == 0x41 || led2 == 0x61)
	{
		led_ON(LED_2);
		led2 = 0x00;
	}
	if(led2 == 0x53 || led2 == 0x73)
	{
		led_OFF(LED_2);
		led2 = 0x00;
	}
}