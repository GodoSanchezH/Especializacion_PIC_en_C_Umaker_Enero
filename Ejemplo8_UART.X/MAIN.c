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



int main(int argc, char** argv) {
    
    ConfigClock();
    Interrupt_Config();
    UART_Init(9600);
    
    TRISF &= ~(1<<3); //definido como salida
    ANSELF &= ~(1<<3);// pin digital
    WPUF &= ~(1<<3);//pull-up desactivado
    INLVLF &= ~(1<<3);//ttl
    SLRCONF |= (1<<3);//limit
    ODCONF &= ~(1<<3);//pushpull
    LATFbits.LATF3=1;
    for(;;){
    
        uint8_t i,j;
        for (i = 0; i < 50; i++) {
            j = ~i;
            printf("%c%c%c%c",0x00,i,j,0xff);
            __delay_ms(200);

        }

        
    
    }
    
    
    
    
    return (EXIT_SUCCESS);
}

