/*
 * eeprom.c
 *
 * Created: 10/19/2015 8:30:58 PM
 *  Author: Marius
 */ 
#include <avr/io.h>
#include "D:/AtmelRepos/PS1/PS1/Header/eeprom.h"

void eeprom_write(unsigned int address, unsigned char data)
{
	/* Wait for completion of previous write */
	while(EECR & (1<<EEPE))
	;
	/* Set up address and Data Registers */
	EEAR = address;
	EEDR = data;
	/* Write logical one to EEMPE */
	EECR |= (1<<EEMPE);
	/* Start eeprom write by setting EEPE */
	EECR |= (1<<EEPE);
}

uint8_t eeprom_read(unsigned int address)
{
	/* Wait for completion of previous write */
	while(EECR & (1<<EEPE))
	;
	/* Set up address register */
	EEAR = address;
	/* Start eeprom read by writing EERE */
	EECR |= (1<<EERE);
	/* Return data from Data Register */
	return EEDR;
}