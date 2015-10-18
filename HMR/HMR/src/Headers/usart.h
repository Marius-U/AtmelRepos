/*
 * usart.h
 *
 * Created: 2/8/2015 4:24:03 PM
 *  Author: Marius
 */ 


#ifndef USART_H_
#define USART_H_

void uart_transmit( unsigned char data );
void uart_print( char data[] );
void uart_int_transmit(unsigned int data);
void uart_int(unsigned int data);
unsigned char uart_receive(void);
void uart_init(void);
int uart_dataAvailable(void);
void uart_flush(void);

#endif /* USART_H_ */