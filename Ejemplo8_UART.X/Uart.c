
#include "Uart.h"
#include "Config.h"
#include <xc.h>

void UART_Init(uint32_t Baud){

    /*Definimos el baud rate*/
    U1CON0bits.BRGS = 0;
    U1BRG = 416;//9600 a 64MHz
    
    /*MODO DE TRABAJO*/
    U1CON0bits.MODE = 0b0000 ;
    U1CON0bits.TXEN = 1;
    U1CON0bits.RXEN = 1;
    U1CON1bits.ON = 1;
    
    /*DIRECCIONAMIENTO DE BITS*/
    //TX -RF0
    RF0PPS = 0x20;
    TRISF &= ~(1<<0); //definido como salida
    ANSELF &= ~(1<<0);// pin digital
    WPUF &= ~(1<<0);//pull-up desactivado
    INLVLF &= ~(1<<0);//ttl
    SLRCONF |= (1<<0);//limit
    ODCONF &= ~(1<<0);//pushpull
  
    
    //Rx -RF1
    U1RXPPSbits.PIN = 0B001;
    U1RXPPSbits.PORT = 0B101;
    
}
void UART_PutC(char ch){

    while(U1ERRIRbits.TXMTIF == 0);
    U1TXB = ch;

}
void UART_PutS(char *ch){

    while(*ch)
        UART_PutC(*ch++);

}


