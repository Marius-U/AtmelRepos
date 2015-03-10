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
		uart_print("Periodical de 2 secunde!\r\n");
		_delay_ms(2000);
	
	}
}