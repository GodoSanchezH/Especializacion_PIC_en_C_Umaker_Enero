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
void ejemplo1(void);

int main(int argc, char** argv) {

    ConfigClock();
 
    ODCONB &= ~(1<<4);//pushpull
    
    
    
//    101101001 -> (1<<0)
//    000000001 -> ~
//    111111110->&
//    101101000        
   // TRISA &= ~(1<<2); ATACANDO EL BIT
    //TRISA = 0xF; ATACANDO EL BYTE
    //TRISAbits.TRISA0 = 1; MEDIANTE ESTRUCTURAS
    for(;;){
    
        if (!(PORTB & (1<<4))) LATF &= ~(1<<3);
        else LATF |=(1<<3); 

        
      
    }
    
    return (EXIT_SUCCESS);
}

void ejemplo1(void){
  LATF ^=(1<<3);
        __delay_ms(200);

}

