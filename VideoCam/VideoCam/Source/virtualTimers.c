/*
 * virtualTimers.c
 *
 * Created: 11/1/2015 7:52:03 PM
 *  Author: Marius
 */ 
#include <avr/io.h>
#include "D:\AtmelRepos\VideoCam\VideoCam\Header\virtualTimers.h"
#include "D:\AtmelRepos\VideoCam\VideoCam\Header\scheduler.h"
#include "D:\AtmelRepos\VideoCam\VideoCam\Header\util.h"

virtualTimer_T timers[10];

void initVirtualTimers()
{
	uint8_t index = 0x00u;
	for(index = 0x00u; index < 0x0Bu; index++)
	{
		timers[index].period = TIMER_EXPIRED;
		timers[index].module = SHEDULER_MODULE;
		timers[index].f		 = 0x00u;
		timers[index].timerStarted = FLAG_CLEAR;
		timers[index].msg   = FLAG_CLEAR;
	}
}
uint8_t startNewVirtualTimer(uint16_t time, uint8_t module, callback fnc, uint8_t msg)
{
	uint8_t index = 0;
	uint8_t timerStarted = 0x00u;
	while(index < 11)
	{
		if(TIMER_EMPTY == timers[index].timerStarted)
		{
			timerStarted = 0x01u;
			timers[index].timerStarted = 0x01u;
			timers[index].msg = msg;
			timers[index].period = time;
			timers[index].module = module;
			timers[index].f = fnc;
			index = 0x0Cu;
		}
		else
		{
			index++;
		}
	}
	if(timerStarted)
	{
		return 0x01u;
	}
	else
	{
		return 0x00u;
	}
}

uint8_t stopVirtualTimer(uint8_t module, callback fcn, uint8_t flag)
{
	uint8_t index = 0;
	while(index < 11)
	{index++;
	}
	return index;
}