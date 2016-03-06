/*
 * Sonerie.c
 *
 * Created: 1/24/2016 12:07:34 PM
 *  Author: Marius
 */ 


#include <avr/io.h>
#define F_CPU 9600000UL
#include <util/delay.h>

int main(void)
{
	DDRB |= (1 << DDB3) | (1 << DDB4);
	
    while(1)
    {
        PORTB |= (1 << PORTB4);
		PORTB &= ~(1 << PORTB3);
		_delay_ms(10);
		PORTB |= (1 << PORTB3);
		PORTB &= ~(1 << PORTB4);
		_delay_ms(10);
    }
}