/*
 * adc.c
 *
 * Created: 11/1/2015 3:59:03 PM
 *  Author: Marius
 */ 

#include <avr/io.h>
#include "D:\AtmelRepos\PS1\PS1\Header\uart.h"
#include "D:\AtmelRepos\PS1\PS1\Header\adc.h"

uint16_t adcRead(uint8_t input)
{
	uint16_t value;
	if(input == TEMP_SENZOR)
	{
		ADMUX &= ~(0x02);
		ADMUX |= input;
	}
	else if(input == REF_TEMP)
	{
		ADMUX |= input;
	}

	ADCSRA |= (1 << ADSC);    // Start the ADC conversion

	while(ADCSRA & (1 << ADSC));      // Thanks T, this line waits for the ADC to finish


	value = ADCL;
	value |= (ADCH << 8);    // ADCH is read so ADC can be updated again

	return value;
}
float adcToCelsius(uint16_t rawADC)
{
	return (rawADC * 0.488f); // 5V resolution, LM35 Linear + 10-mV/°C 
}
float adcGetPrescription(uint16_t rawADC)
{
	return (rawADC * 0.145f);
}
void adc_printValue(float temp)
{
	uint16_t value = (uint16_t)adcToCelsius(temp * 100);
	
	uint8_t uartData[5];
	uartData[4] = value%10;
	value /= 10;
	uartData[3] = value%10;
	value /= 10;
	uartData[2] = value%10;
	value /= 10;
	uartData[1] = value%10;
	value /= 10;
	uartData[0] = value%10;
	
	if(uartData[0])
	{
		uart_transmit(uartData[0]+48);
		uart_transmit(uartData[1]+48);
		uart_transmit(uartData[2]+48);
		uart_transmit(',');
		uart_transmit(uartData[3]+48);
		uart_transmit(uartData[4]+48);
		uart_transmit('\r');
		uart_transmit('\n');
	}
	else
	{
		uart_transmit(uartData[1]+48);
		uart_transmit(uartData[2]+48);
		uart_transmit(',');
		uart_transmit(uartData[3]+48);
		uart_transmit(uartData[4]+48);
		uart_transmit('\r');
		uart_transmit('\n');
	}
}