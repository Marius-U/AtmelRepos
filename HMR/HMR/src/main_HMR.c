/*
 * HMR.c
 *
 * Created: 2/8/2015 4:20:49 PM
 *  Author: Marius
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "usart.h"
#include "pwm.h"


int main(void)
{
	cli();
	uart_init();
	pwm_init();
	sei();
	
	while(1)
	{
		
		//uint16_t ADC_read();
		//uart_print("Fata!\r\n");
		//_delay_ms(1000);
		//uart_print("Spate!\r\n");
		//_delay_ms(1000);
		
	}
}