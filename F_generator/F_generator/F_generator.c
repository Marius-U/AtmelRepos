/*
 * F_generator.c
 *
 * Created: 3/7/2015 9:22:10 PM
 *  Author: Marius
 */ 


#include <avr/io.h>
#define F_CPU 2000000UL
#include <util/delay.h>

int main(void)
{
	DDRD |= (1 << DDD2);
    while(1)
    {
		PORTD = ~PORTD;
	//	asm("nop");
	//	asm("nop");
    }
}