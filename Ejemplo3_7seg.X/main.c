/* 
 * File:   main.c
 * Author: gssan
 *
 * Created on 5 de febrero de 2023, 03:40 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "Config.h"
#include "DIS_7SEG.h"
#include <xc.h>

void ConfiGPIO(void);
Display7Seg Display1 = {3,4,2,7,0,1,2};
int main(int argc, char** argv) {

    ConfigClock();
    ConfiGPIO();
    int i;
    for (;;) {
        
        for (i = 0; i < 10; i++) {
            Write_Display7seg(&Display1,i);
            __delay_ms(800);

        }


    }

    
    return (EXIT_SUCCESS);
}

void ConfiGPIO(void){

    //Configuracion A  RA3
    TRISA &= ~(1<<3); //definido como salida
    ANSELA &= ~(1<<3);// pin digital
    WPUA &= ~(1<<3);//pull-up desactivado
    INLVLA &= ~(1<<3);//ttl
    SLRCONA |= (1<<3);//limit
    ODCONA &= ~(1<<3);//pushpull
    LATAbits.LATA3 =0;
    
    //Configuracion A  RA4
    TRISA &= ~(1<<4); //definido como salida
    ANSELA &= ~(1<<4);// pin digital
    WPUA &= ~(1<<4);//pull-up desactivado
    INLVLA &= ~(1<<4);//ttl
    SLRCONA |= (1<<4);//limit
    ODCONA &= ~(1<<4);//pushpull
    LATAbits.LATA4 =0;
    
    //Configuracion A  RE2
    TRISE &= ~(1<<2); //definido como salida
    ANSELE &= ~(1<<2);// pin digital
    WPUE &= ~(1<<2);//pull-up desactivado
    INLVLE &= ~(1<<2);//ttl
    SLRCONE |= (1<<2);//limit
    ODCONE &= ~(1<<2);//pushpull
    LATEbits.LATE2 =0;
    
    //Configuracion A  RC7
    TRISC &= ~(1<<7); //definido como salida
    ANSELC &= ~(1<<7);// pin digital
    WPUC &= ~(1<<7);//pull-up desactivado
    INLVLC &= ~(1<<7);//ttl
    SLRCONC |= (1<<7);//limit
    ODCONC &= ~(1<<7);//pushpull
    LATCbits.LATC7 =0;
    
    //Configuracion A  RD0
    TRISD &= ~(1<<0); //definido como salida
    ANSELD &= ~(1<<0);// pin digital
    WPUD &= ~(1<<0);//pull-up desactivado
    INLVLD &= ~(1<<0);//ttl
    SLRCOND |= (1<<0);//limit
    ODCOND &= ~(1<<0);//pushpull
    LATDbits.LATD0 =0;
    
    //Configuracion A  RD1
    TRISD &= ~(1<<1); //definido como salida
    ANSELD &= ~(1<<1);// pin digital
    WPUD &= ~(1<<1);//pull-up desactivado
    INLVLD &= ~(1<<1);//ttl
    SLRCOND |= (1<<1);//limit
    ODCOND &= ~(1<<1);//pushpull
    LATDbits.LATD1 =0;
    
//Configuracion A  RD2
    TRISD &= ~(1<<2); //definido como salida
    ANSELD &= ~(1<<2);// pin digital
    WPUD &= ~(1<<2);//pull-up desactivado
    INLVLD &= ~(1<<2);//ttl
    SLRCOND |= (1<<2);//limit
    ODCOND &= ~(1<<2);//pushpull
    LATDbits.LATD2 =0;
}

