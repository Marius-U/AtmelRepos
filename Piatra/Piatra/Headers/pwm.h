/*
 * pwm.h
 *
 * Created: 2/8/2015 4:23:31 PM
 *  Author: Marius
 */ 


#ifndef INCFILE1_H_
#define INCFILE1_H_

void pwm_init();
void backwords(uint8_t value);
void forward(uint8_t value);
void left_f(uint8_t value, uint8_t direction);
void right(uint8_t value, uint8_t direction);
void setOC1A(uint8_t value);
void setOOC1B(uint8_t value);

#endif /* INCFILE1_H_ */