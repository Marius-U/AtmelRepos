/*
 * uart.c
 *
 * Created: 10/24/2015 10:30:47 AM
 *  Author: Marius
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>
#include "D:\AtmelRepos\VideoCam\VideoCam\Header\uart.h"
#include <stdlib.h>
#include <string.h>


// transmit a char to uart
void uart_transmit( unsigned char data )
{
	// wait for empty transmit buffer
	while ( ! ( UCSR0A & ( 1 << UDRE0 ) ) )
	;
	// put data into buffer, sends data
	UDR0 = data;
}
// write a string to the uart
void uart_print( char data[] )
{
	uint8_t count = 0;
	uint8_t length = strlen(data);
	
	for ( count = 0; count < length; count++ )
	uart_transmit(data[count]);
}
// read a char from uart
unsigned char uart_receive(void)
{
	while (!( UCSR0A & ( 1 << RXC0) ))
	;
	return UDR0;
}
// check if there are any chars to be read
int uart_dataAvailable(void)
{
	if ( UCSR0A & ( 1 << RXC0) )
	return 1;
	
	return 0;
}

uint8_t uart_flush(void)
{
	while(UCSR0A & (1 << RXC0))
	return UDR0;
	return UDR0;
}