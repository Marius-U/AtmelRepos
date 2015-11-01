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

void led_ON(uint8_t led);
void led_OFF(uint8_t led);
void togle_Led(uint8_t led);
void check_Led3(void);

extern volatile uint8_t led2;

#endif /* UTIL_H_ */