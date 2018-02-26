#ifndef UART_H_
#define UART_H_

#define F_CPU 16000000UL //16 MHz
#include <avr/io.h>

void UART_init(int baud);
void UARD_send_char(char data);
char UARD_receive_char();


#endif