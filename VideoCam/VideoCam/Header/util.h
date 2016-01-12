/*
 * util.h
 *
 * Created: 10/19/2015 8:58:11 PM
 *  Author: Marius
 */ 


#ifndef UTIL_H_
#define UTIL_H_

#define LED_1 PORTD5
#define LED_2 PORTD2
#define LED_3 PORTD3

void led_ON(void);
void led_OFF(void);
void led_Toggle(void);
void motorsSt(uint8_t value);
void motorsDr(uint8_t value);
void motorsStop(void);

extern volatile uint8_t led2;

#endif /* UTIL_H_ */