/*
 * adc.h
 *
 * Created: 11/1/2015 3:58:49 PM
 *  Author: Marius
 */ 


#ifndef ADC_H_
#define ADC_H_

#define TEMP_SENZOR 0x01u
#define REF_TEMP    0x03u

extern uint16_t prescTemp;

uint16_t adcRead(uint8_t adctouse);
void adcInit();
void adc_printValue(uint16_t rawAdc);
uint16_t adcToCelsius(uint16_t rawADC);

#endif /* ADC_H_ */