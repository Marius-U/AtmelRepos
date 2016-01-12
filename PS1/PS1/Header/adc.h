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


uint16_t adcRead(uint8_t adctouse);
void adcInit(void);
void adc_printValue(float rawAdc);
float adcToCelsius(uint16_t rawADC);
float adcGetPrescription(uint16_t rawADC);

#endif /* ADC_H_ */