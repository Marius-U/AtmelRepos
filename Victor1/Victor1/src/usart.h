/*
 * usart.h
 *
 * Created: 1/6/2015 7:30:04 PM
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