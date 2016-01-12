/*
 * init.h
 *
 * Created: 10/18/2015 2:50:40 PM
 *  Author: Marius
 */ 


#ifndef INIT_H_
#define INIT_H_

void initDisplay(void);
void initButton(void);
void initTimerA(void);
void initTimerB(uint16_t countValue);
void initLeds(void);
void initButtonISR(void);
void uart_init(void);
void adcInit(void);
void initPeriodical(void);
void initPWM(void);

#endif /* INIT_H_ */