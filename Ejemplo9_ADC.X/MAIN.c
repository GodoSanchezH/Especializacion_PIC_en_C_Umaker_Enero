/* 
 * File:   MAIN.c
 * Author: gssan
 *
 * Created on 19 de febrero de 2023, 04:18 PM
 */

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
#include "ADC.h"

#define InicioTrama 0X00
#define FintTrama 0xFF
uint16_t adc_read[2];
int main(int argc, char** argv) {
    
    ConfigClock();
    Interrupt_Config();
    UART_Init(9600);
    ADC_Init();
    TRISF &= ~(1<<3); //definido como salida
    ANSELF &= ~(1<<3);// pin digital
    WPUF &= ~(1<<3);//pull-up desactivado
    INLVLF &= ~(1<<3);//ttl
    SLRCONF |= (1<<3);//limit
    ODCONF &= ~(1<<3);//pushpull
    LATFbits.LATF3=1;
    
    
    for(;;){
    
        adc_read[0] = AnalogRead(AN0);
        adc_read[1] = AnalogRead(AN2);
        
       // printf("ADC0:%u --- ADC2:%u\n\r",adc_read[0],adc_read[1]);
        printf("%c%c%c%c%c%c",InicioTrama,adc_read[1]& 0x00ff,adc_read[1]>>8,adc_read[0]& 0x00ff,adc_read[0]>>8,FintTrama);
        
        __delay_ms(100);
    }
    
    
    
    
    return (EXIT_SUCCESS);
}


