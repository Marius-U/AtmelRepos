/*
 * Termo.c
 *
 * Created: 2/17/2016 9:14:49 PM
 *  Author: Marius
 */ 


#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>

int main(void)
{
	DDRB = 0x3fu;
	PORTB  = 0x0Fu;
	DDRC |= (1 << DDC1) | ( 1 << DDC0) | (1 << DDC2);
	PORTC = 0x06u;
    while(1)
    {
        //TODO:: Please write your application code 
    }
}