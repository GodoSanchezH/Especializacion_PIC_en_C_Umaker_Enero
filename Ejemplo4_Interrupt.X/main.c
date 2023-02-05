/* 
 * File:   main.c
 * Author: gssan
 *
 * Created on 5 de febrero de 2023, 04:56 PM
 */

#include <stdio.h>
#include <stdlib.h>

#include "Config.h"
#include "Interrupt.h"
#include <xc.h>
/*
 * 
 */
void config_gpio(void);
int main(int argc, char** argv) {

    ConfigClock();
    config_gpio();
    Interrupt_Config();
    
    for(;;){
    
    
    }
    
    
    return (EXIT_SUCCESS);
}

void config_gpio(void){
   //Configuracion LED  RF3
    TRISF &= ~(1<<3); //definido como salida
    ANSELF &= ~(1<<3);// pin digital
    WPUF &= ~(1<<3);//pull-up desactivado
    INLVLF &= ~(1<<3);//ttl
    SLRCONF |= (1<<3);//limit
    ODCONF &= ~(1<<3);//pushpull
    
    
    //Configuracion Button RB4
    TRISB |= (1<<4); //definido como ENTRADA
    ANSELB &= ~(1<<4);// pin digital
    WPUB |= (1<<4);//pull-up ON
    INLVLB &= ~(1<<4);//ttl
    SLRCONB |= (1<<4);//limit
}