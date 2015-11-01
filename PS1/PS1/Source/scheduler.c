/*
 * scheduler.c
 *
 * Created: 11/1/2015 7:46:33 PM
 *  Author: Marius
 */ 
#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/interrupt.h>
#include "D:/AtmelRepos/PS1/PS1/Header/init.h"
#include "D:/AtmelRepos/PS1/PS1/Header/segDisplay.h"
#include "D:/AtmelRepos/PS1/PS1/Header/util.h"
#include "D:/AtmelRepos/PS1/PS1/Header/uart.h"
#include "D:/AtmelRepos/PS1/PS1/Header/adc.h"
#include "D:/AtmelRepos/PS1/PS1/Header/eeprom.h"
#include "D:/AtmelRepos/PS1/PS1/Header/scheduler.h"
#include "D:\AtmelRepos\PS1\PS1\Header\virtualTimers.h"

uint16_t prescTemp ;
volatile uint16_t count;

void scheduler(void)
{
	if(count == 1000)
	{			
		//set mode for LED_1
		count = 0x0000u;
		togle_Led(LED_1);
	}
	 if(count % 10 == 0) // every 10 ms check temperature
	{
		prescTemp = adcRead(REF_TEMP);
		if(adcRead(TEMP_SENZOR) > prescTemp)
		{
			led_ON(LED_2);
		}
		else
		{
			led_OFF(LED_2);
		}
	}
	 if(count % 20 == 0) // every 20 ms check if A or S was pressed
	{
		check_Led3();
	}
	
		//check virtual timers 
}
