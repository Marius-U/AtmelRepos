/*
 * scheduler.c
 *
 * Created: 11/1/2015 7:46:33 PM
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
#include "D:\AtmelRepos\VideoCam\VideoCam\Header\callback.h"

volatile uint16_t count;
uint8_t ledMode;
uint8_t flags[10] = {0,0,0,0,0,0,0,0,0,0};
float sum = 0x00;
float temp = 0x0000f;
	
volatile uint8_t buttonCount;

void scheduler(void)
{
	if((count % 1000 == 0) && (count >= 1000))
	{		
	
	}
	if((count % 4 == 0) &&(count >=4))
	{	
		if(flags[BUTTON_FW_DR_SHORT_PRESS_FLAG])
		{
			startNewVirtualTimer(30,BUTTON_MODULE,fw_dr_shortPress_callback,1);
			startNewVirtualTimer(3000,BUTTON_MODULE,fw_dr_longPress_callback,1);
			flags[BUTTON_FW_DR_SHORT_PRESS_FLAG] = FLAG_CLEAR;
		}
		if(flags[BUTTON_FW_ST_LONG_PRESS_FLAG])
		{
			startNewVirtualTimer(30,BUTTON_MODULE,fw_st_shortPress_callback,1);
			startNewVirtualTimer(3000,BUTTON_MODULE,fw_st_longPress_callback,1);
			flags[BUTTON_FW_DR_SHORT_PRESS_FLAG] = FLAG_CLEAR;
		}
		if(flags[BUTTON_REC_SHORT_PRESS_FLAG])
		{
			startNewVirtualTimer(30,BUTTON_MODULE,rec_shortPress_callback,1);
			startNewVirtualTimer(3000,BUTTON_MODULE,rec_longPress_callback,1);
			flags[BUTTON_FW_DR_SHORT_PRESS_FLAG] = FLAG_CLEAR;
		}
	}
	if((count % 5 == 0) && (count >= 5))
	{
		
	}
	 if((count % 10 == 0) && (count >= 10))
	{
		
	}
	 if(count % 20 == 0)
	{
			//if (PINC & 0x04u) // FW Dreapta
			//{
				//flags[BUTTON_FW_DR_SHORT_PRESS_FLAG] = FLAG_SET;
			//}
			//if (PINB & 0x01u) // FILMARE
			//{
				//flags[BUTTON_REC_SHORT_PRESS_FLAG] = FLAG_SET;
			//}
			//if(PINB & 0x02u) // FW Stanga
			//{
				//flags[BUTTON_FW_ST_SHORT_PRESS_FLAG] = FLAG_SET;
			//}
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
