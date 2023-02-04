/* 
 * File:   main.c
 * Author: gssan
 *
 * Created on 4 de febrero de 2023, 04:09 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <pic18f57q43.h>
#include <builtins.h>

#include "Config.h"

/*
 * 
 */
int main(int argc, char** argv) {

    ConfigClock();
    //Configuracion LED  RF3
    TRISF &= ~(1<<3); //definido como salida
    ANSELF &= ~(1<<3);// pin digital
    WPUF &= ~(1<<3);//pull-up desactivado
    INLVLF &= ~(1<<3);//ttl
    SLRCONF |= (1<<3);//limit
    ODCONF &= ~(1<<3);//pushpull
    
//    101101001 -> (1<<0)
//    000000001 -> ~
//    111111110->&
//    101101000        
   // TRISA &= ~(1<<2); ATACANDO EL BIT
    //TRISA = 0xF; ATACANDO EL BYTE
    //TRISAbits.TRISA0 = 1; MEDIANTE ESTRUCTURAS
    for(;;){
    
        LATF ^=(1<<3);
        __delay_ms(200);
    }
    
    return (EXIT_SUCCESS);
}

