/*
 * scheduler.c
 *
 * Created: 11/1/2015 7:46:33 PM
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

float prescTemp ;
volatile uint16_t count;
uint8_t ledMode;
uint8_t flags[10] = {0,0,0,0,0,0,0,0,0,0};
float sum = 0x00;
float temp = 0x0000f;
uint8_t  tempCount;
	
volatile uint8_t buttonCount;

void scheduler(void)
{
	if(count == 1000)
	{			
		//set mode for LED_1
		count = 0x0000u;
		if(ledMode < 3)
		{
			ledMode += 0x01u;
		}
		else
		{
			ledMode = 0x00u;
		}
		uart_print("VALUE: ");
		adc_printValue(temp);
		
		uart_print("PRECS: ");
		adc_printValue(prescTemp);
	}
	if((count % 4) &&(count >=4))
	{	
		if((LED_MODE_INCREMENT == ledMode) && (OCR0B < 255))
		{
			OCR0B += 0x01u;
		}
		else if((LED_MODE_DECREMENT == ledMode) && (OCR0B > 0))
		{
			OCR0B -= 0x01u;
		}
		else if(LED_MODE_HIGH == ledMode)
		{
			OCR0B = 0xFFu;
		}
		else if(LED_MODE_STOP == ledMode)
		{
			OCR0B = 0x00u;
		}
		if(flags[BUTTON_SHORT_PRESS_FLAG])
		{
			startNewVirtualTimer(30,BUTTON_MODULE,incrementDisplay,1);
			startNewVirtualTimer(3000,BUTTON_MODULE,resetDisplay,1);
			flags[BUTTON_SHORT_PRESS_FLAG] = FLAG_CLEAR;
		}
	}
	if((count % 5 == 0) && (count >= 5))
	{
		if(tempCount < 25)
		{
			sum += adcRead(TEMP_SENZOR);
			tempCount +=1;
		}
		else
		{
			temp = adcToCelsius(sum / 24);
			sum = 0x00u;
			tempCount = 0x00u;
		}
	}
	 if((count % 10 == 0) && (count >= 10)) // every 10 ms check temperature
	{
		prescTemp = adcGetPrescription(adcRead(REF_TEMP)+25); // +25  = + 5 grade C
		
		if(temp > prescTemp)
		{
			led_ON(LED_2);
		}
		else if(temp < prescTemp)
		{
			led_OFF(LED_2);
		}
	}
	 if(count % 20 == 0) // every 20 ms check if A or S was pressed
	{
		check_Led3();
	}
	if((count % 100 == 0) && (count > 100))
	{

	}

		checkVirtualTimers();
		
}
void checkVirtualTimers()
{
	uint8_t index = 0x00u;
	
	while(10 > index)
	{
		if(timers[index].timerStarted)
		{
			if (timers[index].period)
			{
				timers[index].period -= 0x01u;
			}
			else if((TIMER_EXPIRED == timers[index].period) && (0x00u != timers[index].f))
			{
				//if timer expired call the callback function
				timers[index].f();
				timers[index].timerStarted = TIMER_EXPIRED;
			}
			else if(TIMER_EXPIRED == timers[index].period)
			{
				//if timer expired and there is no callback function, set action flag
				flags[timers[index].module] = FLAG_SET;
				timers[index].timerStarted = TIMER_EXPIRED;
			}
		}
		index += 0x01u;
	}
}
void incrementDisplay()
{
	if (PINC & (0x01u))
	{
		//Button was pressed!
		buttonCount = eeprom_read(0x00u);
		if(buttonCount < 10)
		{
			buttonCount++;
			eeprom_write(0x00u,buttonCount);
			display(buttonCount);
		}
		else
		{
			buttonCount = 0x00;
			eeprom_write(0x00u, buttonCount);
			display(buttonCount);
		}
	}
}
void resetDisplay()
{
		if (PINC & (0x01u))
		{
			buttonCount = 0x00u;
			eeprom_write(0x00u,buttonCount);
			display(buttonCount);
		}
}