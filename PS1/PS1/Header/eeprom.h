/*
 * eeprom.h
 *
 * Created: 10/19/2015 8:33:59 PM
 *  Author: Marius
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_


void eeprom_write(unsigned int address, unsigned char data);
uint8_t eeprom_read(unsigned int address);


#endif /* EEPROM_H_ */