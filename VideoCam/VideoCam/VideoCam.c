/*
 * VideoCam.c
 *
 * Created: 12/21/2015 3:05:34 PM
 *  Author: Marius
 */ 


#include <avr/io.h>
#define F_CPU 16000000UL
#include <avr/interrupt.h>
#include <util/delay.h>
#include "Header/init.h"
#include "Header/segDisplay.h"
#include "Header/util.h"
#include "Header/uart.h"
#include "Header/adc.h"
#include "Header/virtualTimers.h"
#include "D:\AtmelRepos\VideoCam\VideoCam\Header\eeprom.h"

int main(void)
{
	initLeds();
	initButtons();
	initBuzzer();
	initMotors();
	initPWM();
	motorsSt(0x10u);
	initPeriodical();
	
    while(1)
    {	
		motorsSt(0x00u);
		_delay_ms(1000);
		motorsStop();
		_delay_ms(1000);
    }
}