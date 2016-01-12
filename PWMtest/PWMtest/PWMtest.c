/*
 * PWMtest.c
 *
 * Created: 12/21/2015 7:20:48 PM
 *  Author: Marius
 */ 


#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>

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
	PORTD &= ~(1 << PORTD1) & ~(1 << PORTD3);
	PORTD &= ~(1 << PORTD0) & ~(1 << PORTD2);
}
void initMotors(void)
{
	DDRD |= 0x0Fu;
	//PORTD &= 0xF0u;
}

int main(void)
{
	OCR0B = 0x7f;
	// set PWM for 00% duty cycle

	TCCR0A |= (1 << COM0B1);
	// set none-inverting mode

	TCCR0A |= (1 << WGM01) | (1 << WGM00);
	// set fast PWM Mode

	TCCR0B |= (1 << CS01);
	// set prescaler to 8 and starts PWM
	//initMotors();
	DDRD |= 0x2Fu;
	PORTD = 0x0fu;
    while(1)
    {
         motorsSt(0xffu);
         _delay_ms(1000);
         motorsStop();
         _delay_ms(1000);
    }
}
