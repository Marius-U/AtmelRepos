/*
 * isr.c
 *
 * Created: 11/1/2015 7:35:21 PM
 *  Author: Marius
 */ 
#include <avr/io.h>
#define F_CPU 16000000UL
#include <avr/interrupt.h>
#include "D:/AtmelRepos/PS1/PS1/Header/init.h"
#include "D:/AtmelRepos/PS1/PS1/Header/segDisplay.h"
#include "D:/AtmelRepos/PS1/PS1/Header/util.h"
#include "D:/AtmelRepos/PS1/PS1/Header/uart.h"
#include "D:/AtmelRepos/PS1/PS1/Header/adc.h"
#include "D:/AtmelRepos/PS1/PS1/Header/eeprom.h"
#include "D:/AtmelRepos/PS1/PS1/Header/scheduler.h"
#include "D:\AtmelRepos\PS1\PS1\Header\virtualTimers.h"

volatile uint16_t count = 0x00u;
volatile uint8_t led3;
uint8_t flags[10];

ISR (USART_RX_vect)
{
	led3 = UDR0;
}

ISR (TIMER1_COMPA_vect)
{
	count++;
	scheduler();
}

ISR (TIMER0_COMPA_vect)
{
	//count++;
	//scheduler();
}

ISR(PCINT1_vect) {
	
	if (PINC & (0x01u))
	{
		flags[BUTTON_SHORT_PRESS_FLAG] = FLAG_SET;
	}
}