/*
 * isr.c
 *
 * Created: 11/1/2015 7:35:21 PM
 *  Author: Marius
 */ 
#include <avr/io.h>
#define F_CPU 16000000UL
#include <avr/interrupt.h>
#include "D:\AtmelRepos\VideoCam\VideoCam\Header\init.h"
#include "D:\AtmelRepos\VideoCam\VideoCam\Header\segDisplay.h"
#include "D:\AtmelRepos\VideoCam\VideoCam\Header\util.h"
#include "D:\AtmelRepos\VideoCam\VideoCam\Header\uart.h"
#include "D:\AtmelRepos\VideoCam\VideoCam\Header\adc.h"
#include "D:\AtmelRepos\VideoCam\VideoCam\Header\eeprom.h"
#include "D:\AtmelRepos\VideoCam\VideoCam\Header\scheduler.h"
#include "D:\AtmelRepos\VideoCam\VideoCam\Header\virtualTimers.h"

volatile uint16_t count = 0x00u;
volatile uint8_t led3;
uint8_t flags[10];

ISR (USART_RX_vect)
{
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
	
	if (PINC & 0x04u) // FW Dreapta
	{
		flags[BUTTON_FW_DR_SHORT_PRESS_FLAG] = FLAG_SET;
	}
}
ISR(PCINT0_vect) {
	
	if (PINB & 0x01u) // FILMARE
	{
		flags[BUTTON_REC_SHORT_PRESS_FLAG] = FLAG_SET;
	}
	if(PINB & 0x02u) // FW Stanga
	{
		flags[BUTTON_FW_ST_SHORT_PRESS_FLAG] = FLAG_SET;
	}
}
