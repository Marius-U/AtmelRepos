/*
 * segDisplay.c
 *
 * Created: 10/18/2015 2:53:13 PM
 *  Author: Marius
 */ 
#include <avr/io.h>
#include "D:\AtmelRepos\PS1\PS1\Header\segDisplay.h"

const uint8_t segDisplay[10] = {0x3Fu, 0x06u, 0x1Bu, 0x0Fu, 0x26u, 0x2Du, 0x3D, 0x07u, 0x3F, 0x2F};

void display(uint8_t value)
{
	clear();
	if((value != 0x00) & (value != 0x01) & (value != 0x07))
	{
		PORTD |= (1 << PORTD6);
	}
	PORTB |= segDisplay[value];
}
void clear()
{
	PORTB &= ~(1 << PORTB0) & ~(1 << PORTB1) & ~(1 << PORTB2) & ~(1 << PORTB3) & ~(1 << PORTB4) & ~(1 << PORTB5);
	PORTD &= ~(1 << PORTD6) & ~(1 << PORTD7);
}