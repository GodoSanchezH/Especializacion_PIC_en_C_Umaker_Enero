/* 
 * File:   Uart.h
 * Author: gssan
 *
 * Created on 18 de febrero de 2023, 04:09 PM
 */

#ifndef UART_H
#define	UART_H

#include <stdint.h>

void UART_Init(uint32_t Baud);
void UART_PutC(char ch);
void UART_PutS(char *ch);

#endif	/* UART_H */

