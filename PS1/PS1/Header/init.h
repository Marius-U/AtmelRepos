/*
 * init.h
 *
 * Created: 10/18/2015 2:50:40 PM
 *  Author: Marius
 */ 


#ifndef INIT_H_
#define INIT_H_

void initDisplay();
void initButton();
void initTimerA(uint8_t countValue);
void initTimerB(uint16_t countValue);
void initLeds();
void initButtonISR();
void uart_init(void);



#endif /* INIT_H_ */