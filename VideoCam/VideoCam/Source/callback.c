/*
 * callback.c
 *
 * Created: 12/21/2015 4:08:30 PM
 *  Author: Marius
 */ 
#include <avr/io.h>
#define F_CPU 16000000UL
#include "D:\AtmelRepos\VideoCam\VideoCam\Header\callback.h"
#include "D:\AtmelRepos\VideoCam\VideoCam\Header\util.h"

void fw_dr_shortPress_callback(void)
{
	if(PINC & 0x04u)
	{
		led_Toggle();
	}
}
void fw_st_shortPress_callback(void)
{
	if(PINB & 0x02u)
	{
		led_OFF();
	}
}
void rec_shortPress_callback(void)
{
	if(PINB & 0x01u)
	{
		led_ON();
	}
}
void fw_dr_longPress_callback(void)
{
	
}
void fw_st_longPress_callback(void)
{
	
}
void rec_longPress_callback(void)
{
	
}