/*
 * scheduler.h
 *
 * Created: 11/1/2015 7:52:55 PM
 *  Author: Marius
 */ 


#ifndef SCHEDULER_H_
#define SCHEDULER_H_

#define LED_MODE_STOP				 0x00u
#define LED_MODE_INCREMENT			 0x01u
#define LED_MODE_HIGH				 0x02u
#define LED_MODE_DECREMENT			 0x03u

#define SHEDULER_MODULE				 0x00u
#define BUTTON_MODULE				 0x01u
#define LED1_MODULE					 0x02u
#define LED2_MODULE					 0x03u
#define LED3_MODULE					 0x04u
#define SENZOR_MODULE				 0x05u

#define FLAG_SET					 0x01u
#define FLAG_CLEAR					 0x00u
#define BUTTON_FW_DR_SHORT_PRESS_FLAG      0x00u
#define BUTTON_FW_ST_SHORT_PRESS_FLAG      0x01u
#define BUTTON_REC_SHORT_PRESS_FLAG        0x02u
#define BUTTON_FW_DR_LONG_PRESS_FLAG   	   0x03u
#define BUTTON_FW_ST_LONG_PRESS_FLAG   	   0x04u
#define BUTTON_REC_LONG_PRESS_FLAG   	   0x05u

extern uint8_t flags[10];		

void scheduler(void);
void incrementDisplay();
void checkVirtualTimers();
void resetDisplay();

#endif /* SCHEDULER_H_ */