
#include "TIMER.h"
#include <xc.h>
/*Timer0 Configuration:
? Timer0 mode = 16-bit
? Clock Source = FOSC/4 (250 kHz)
? Synchronous operation
? Prescaler = 1:1
? Postscaler = 1:2 (T0OUTPS = 1)
In this case, the TMR0_out toggles every two rollovers of TMR0H:TMR0L.
i.e., (0xFFFF)*2*(1/250 kHz) = 524.28
 */
void TimerInit(timerMod MT){

    switch(MT){
    
        case Timer_8bit:
            
            break;
        case Timer_16bit:
            T0CON0bits.EN = 0;//iniciamos con el timer apagad
            T0CON0bits.MD16 = 1;//modo 16 bits
            T0CON0bits.OUT = 0b0000;//1:1
            T0CON1bits.CS = 0b010;//FOSC/4
            T0CON1bits.ASYNC = 0;
            T0CON1bits.CKPS = 0b0110;//1:64
            TMR0H =  0X6D;
            TMR0L = 0X83;
          
            T0CON0bits.EN = 1;//timer encendido
            break;
  
    
    }


}

