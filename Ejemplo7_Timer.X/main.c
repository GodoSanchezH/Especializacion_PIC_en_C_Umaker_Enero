/* 
 * File:   main.c
 * Author: gssan
 *
 * Created on 12 de febrero de 2023, 04:16 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "Config.h"
#include "Interrupt.h"
#include "TIMER.h"
#include <xc.h>
/*
 * 
 */
void ConfiGPIO(void);
int main(int argc, char** argv) {
    ConfigClock();
    ConfiGPIO();
    Interrupt_Config();
    TimerInit(Timer_16bit);
    for(;;){
      
        //__delay_ms(200);

    }

    
    
    return (EXIT_SUCCESS);
}
void ConfiGPIO(void){

    //Configuracion F  RF3
    TRISF &= ~(1<<3); //definido como salida
    ANSELF &= ~(1<<3);// pin digital
    WPUF &= ~(1<<3);//pull-up desactivado
    INLVLF &= ~(1<<3);//ttl
    SLRCONF |= (1<<3);//limit
    ODCONF &= ~(1<<3);//pushpull
    LATFbits.LATF3 =0;
    
  

  
}


