/*
 * segDisplay.h
 *
 * Created: 10/18/2015 2:54:10 PM
 *  Author: Marius
 */ 


#ifndef SEGDISPLAY_H_
#define SEGDISPLAY_H_

extern volatile uint8_t buttonCount;

void display(uint8_t value);
void clear();

#endif /* SEGDISPLAY_H_ */