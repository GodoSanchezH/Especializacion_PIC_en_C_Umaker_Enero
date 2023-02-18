/* 
 * File:   MAIN.c
 * Author: gssan
 *
 * Created on 18 de febrero de 2023, 04:08 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "Config.h"
#include "Interrupt.h"
#include "Uart.h"
/*
 * 
 */
int main(int argc, char** argv) {
    
    ConfigClock();
    Interrupt_Config();
    UART_Init(9600);
    
    
    for(;;){
    
        UART_PutS("Hola mundo pic\n\r");
       __delay_ms(500);
    
    }
    
    
    
    
    return (EXIT_SUCCESS);
}

