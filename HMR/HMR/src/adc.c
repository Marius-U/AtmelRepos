/*
 * adc.c
 *
 * Created: 2/8/2015 4:22:34 PM
 *  Author: Marius
 */ 
#include <avr/io.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


void ADC_init(){
	
	ADMUX |= (1 << REFS0) | (1 << REFS1); //Foloseste referinta
	ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1<<ADPS0); //Prescaler pentru 16Mhz
	ACSR |= (1 << ACD);

}

uint16_t ADC_read()//unsigned int adc_in)
{
	uint16_t x;
	
	ADMUX  = 4;
	ADCSRA |= (1 << ADEN);
	ADCSRA |= (1 << ADSC); //Start the ADC conversion
	while (ADCSRA & (1 <<ADSC))
	;
	
	x= ADC;

	return x;
}