/*
 * PE6_test.c
 *
 * Created: 11/22/2015 3:55:05 PM
 *  Author: Marius
 */ 


#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>

int main(void)
{
	DDRE |= (1 << DDE6);
	
    while(1)
    {
        PORTE ^= (1 << PORTE6);
		_delay_ms(1000);
    }
}