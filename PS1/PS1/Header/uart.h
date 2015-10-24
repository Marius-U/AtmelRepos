/*
 * uart.h
 *
 * Created: 10/24/2015 10:31:11 AM
 *  Author: Marius
 */ 


#ifndef UART_H_
#define UART_H_


# define USART_BAUDRATE 115200
# define BAUD_PRESCALE ((( F_CPU / ( USART_BAUDRATE * 16UL))) - 1)

void uart_transmit( unsigned char data );
void uart_print( char data[] );
unsigned char uart_receive(void);
int uart_dataAvailable(void);
uint8_t uart_flush(void);

#endif /* UART_H_ */