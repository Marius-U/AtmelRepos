/*
 * Milestone1.c
 *
 * Created: 3/10/2015 11:40:59 PM
 *  Author: Marius
 */ 


#include <avr/io.h>
#include "USART.h"
#define F_CPU 16000000UL
#include <util/delay.h>

int main(void)
{
	uint8_t flag = 0;
	DDRD |= (1 << DDD6) | (1 << DDD7);
	
   DDRB &= ~(1 << DDB5);              // Clear the PB5 pin
   // PB5 is now an input

  // PORTB |= (1 << PORTB5);             // turn On the Pull-up enabled
   // PB5 is now an input with pull-up enabled
   
	PORTD |= (1 << PORTD6);
	uart_init(207);
   while (1)
   {
	   if( (PINB & (1 << PINB5)) == 0)    //is the pin set
	   {
		   _delay_ms(30); //wait a 30ms
			 while((PINB & (1 << PINB5)) == 0);
			   if(flag)
			   {
				   //Send with baud = 9600
				   uart_init(207);
				   PORTD |= (1 << PORTD6);
				   PORTD &= ~(1 << PORTD7);
				   flag = 0;
			   }
			   else
			   {
				   //Send with baud = 115200
				   uart_init(16);
				   PORTD |= (1 << PORTD7);
				   PORTD &= ~(1 << PORTD6);
				   flag = 1;
			   }
	   }
	   uart_print("A");
   }
}