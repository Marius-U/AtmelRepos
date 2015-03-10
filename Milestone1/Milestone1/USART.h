/*
 * USART.h
 *
 * Created: 3/10/2015 11:42:09 PM
 *  Author: Marius
 */ 


#ifndef USART_H_
#define USART_H_

void uart_transmit( unsigned char data );
void uart_print( char data[] );
void uart_int_transmit(unsigned int data);
void uart_int(unsigned int data);
unsigned char uart_receive(void);
void uart_init(uint8_t baud);
int uart_dataAvailable(void);
void uart_flush(void);




#endif /* USART_H_ */