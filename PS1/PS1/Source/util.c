/*
 * util.c
 *
 * Created: 10/19/2015 8:58:35 PM
 *  Author: Marius
 */ 

#include <avr/io.h>
#include "D:\Repos\AtmelRepos\PS1\PS1\Header\util.h"

volatile uint8_t led3 ;

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

void check_Led3(void)
{
	if(led3 == 0x41 || led3 == 0x61)
	{
		led_ON(LED_3);
		//led3 = 0x00;
	}
	if(led3 == 0x53 || led3 == 0x73)
	{
		led_OFF(LED_3);
		//led3 = 0x00;
	}
}
uint8_t getLedState(void)
{
	return led3;
}