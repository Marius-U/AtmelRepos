/*
 * init.c
 *
 * Created: 10/18/2015 2:05:38 PM
 *  Author: Marius
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>
#include "D:\AtmelRepos\PS1\PS1\Header\init.h"
#include "D:\AtmelRepos\PS1\PS1\Header/segDisplay.h"
#include "D:/AtmelRepos/PS1/PS1/Header/eeprom.h"

void initDisplay()
{
	/* Initialize the Data Direction Registers as outputs for the 7 segments display*/
	DDRB |= (1 << DDB0) | (1 << DDB1) | (1 << DDB2) | (1 << DDB3) | (1 << DDB4) | (1 << DDB5);
	DDRD |= (1 << DDD6) | (1 << DDD7);
	display(eeprom_read(0x00u));
	
}
void initLeds()
{
	  DDRD |= (1 << DDD5) | (1 << DDD3) | (1 << DDD2);
	  PORTD |= (1 << 2) | (1 << 3) | (1 << 5);
}
void initButton()
{
	/*Initializing PC1 as input for the SW button with pull down resistor.*/
	DDRC &= ~(1 << DDC1);
	PORTC &= ~(1 << PORTC1);
}
void initTimerB(uint16_t countValue)
{
	cli();
	TCCR1B |= (1 << WGM12);
	TCCR1B |= (1 << CS12);
	OCR1A   = countValue;
	TIMSK1 |= (1 << OCIE1A);
	sei(); 
}
void initPWM()
{
	OCR0B = 0x00;
	// set PWM for 00% duty cycle

	TCCR0A |= (1 << COM0B1);
	// set none-inverting mode

	TCCR0A |= (1 << WGM01) | (1 << WGM00);
	// set fast PWM Mode

	TCCR0B |= (1 << CS01);
	// set prescaler to 8 and starts PWM
}
void initPeriodical()
{
		cli();
		TCCR1B |= (1 << WGM12);
		TCCR1B |= (1 << CS12);
		OCR1A   = 0x3F;
		TIMSK1 |= (1 << OCIE1A);
		sei();
}
void initTimerA()
{
	cli();
	TCCR0A |= (1 << WGM01);						// Set the Timer Mode to CTC
	TCCR0B |= (1 << CS02);						// set prescaler to 256 and start the timer (0.016 ms => 62.5 incremts = 1ms) 
	OCR0A   = 0x3F;								// Count to 1.008 ms
	TIMSK0 |= (1 << OCIE0A);					//Set the ISR COMPA vect
	sei();
}
void initButtonISR()
{
	cli();
	/*Initializing PC1 as input for the SW button with pull down resistor.*/
	DDRC |= (1 << DDC0);
	PORTC &= ~(1 << PORTC0);
	
	PCICR  |= (1 << PCIE1);
	PCMSK1 |= (1 << PCINT8);
	sei();
}

void adcInit()
{
	ADMUX |= (1 << REFS0);    // use AVcc as the reference
	ADMUX &= ~(1 << ADLAR);   // clear for 10 bit resolution
	ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);    // 128 prescale for 8Mhz
	ADCSRA |= (1 << ADEN);    // Enable the ADC
}

void uart_init(void)
{
	cli();
	// set baud rate
	unsigned int baud = 207u;//BAUD_PRESCALE;
	
	UBRR0H = (unsigned char) (baud >> 8 );
	UBRR0L = (unsigned char)baud;
	UCSR0A |= (1 << U2X0);
	// set frame format ( 8data, 1stop )
	UCSR0C |= (1 << UCSZ00) | (1 << UCSZ01);
	// Enable reciever interrupt
	UCSR0B |= (1 << RXCIE0);                    
	// enable received and transmitter
	UCSR0B |= ( 1 << RXEN0 ) | ( 1 << TXEN0 );
	
	sei();
}