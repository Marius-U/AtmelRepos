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

#endif /* INCFILE1_H_ */