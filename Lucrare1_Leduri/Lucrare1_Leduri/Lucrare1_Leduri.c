/*
 * Lucrare1_Leduri.c
 *
 * Created: 2/26/2015 5:07:46 PM
 *  Author: Marius
 */ 


#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>

void pinInit(void)
{
	DDRB |= (1 << DDB4) | (1 << DDB5) | (1 << DDB6) | (1 << DDB7);
	DDRC |= (1 << DDC6) | (1 << DDC7);
	DDRF |= (1 << DDF7);
}
void shiftLed500ms(void)
{
	uint8_t i = 0x00u;
	PORTB = 0x08u;
	while(i < 4)
	{
		
		PORTB = (PORTB << 1);
		i++;
		_delay_ms(500);
		
	}
	PORTB = 0x00u;
	PORTC |= (1 << PORTC6);
	_delay_ms(500);
	PORTC &= ~(1 << PORTC6);
	PORTC |= (1 << PORTC7);
	_delay_ms(500);
	PORTC &= ~(1 << PORTC7);
	PORTF |= (1 << PORTF7);
	_delay_ms(500);
	PORTF &= ~(1 << PORTF7);
}

int main(void)
{
	pinInit();
	
    while(1)
    {
		shiftLed500ms();
		
    }
}