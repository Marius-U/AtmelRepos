/*
 * virtualTimers.h
 *
 * Created: 11/1/2015 7:52:39 PM
 *  Author: Marius
 */ 


#ifndef VIRTUALTIMERS_H_
#define VIRTUALTIMERS_H_

#define TIMER_EMPTY     0x00u
#define TIMER_OCCUPIED	0x01u
#define TIMER_EXPIRED   0x00u

typedef void(*callback)(void);

typedef struct {
	uint16_t period;
	uint8_t	 module;
	callback f;
	uint8_t flag;
	}virtualTimer_T;

extern virtualTimer_T timers[10];


uint8_t startNewVirtualTimer(uint16_t time, uint8_t module, callback fnc, uint8_t flag);
void initVirtualTimers();

#endif /* VIRTUALTIMERS_H_ */