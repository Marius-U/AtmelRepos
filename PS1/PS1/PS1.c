/*
 * PS1.c
 *
 * Created: 10/12/2015 7:19:35 PM
 *  Author: Marius
 */ 


#include <avr/io.h>
#define F_CPU 16000000UL
#include <avr/interrupt.h>
#include "Header/init.h"
#include "Header/segDisplay.h"
#include "Header/util.h"
#include "Header/uart.h"
#include "Header/adc.h"
#include "Header/virtualTimers.h"
#include "D:\Repos\AtmelRepos\PS1\PS1\Header\eeprom.h"


int main(void)
{	
	initVirtualTimers();
	initDisplay();
	initButtonISR();
	initLeds();
	adcInit();
	uart_init();
	initPWM();
	initPeriodical();
	
	 while(1)
    {	
    }
}

