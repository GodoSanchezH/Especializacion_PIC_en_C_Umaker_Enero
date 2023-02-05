#include "Interrupt.h"
#include <xc.h>
#include "Config.h"


void Interrupt_Config(void){

    //DEFINIMOS COMO ENTRADA AL RB0 ,RB1 
    TRISB |= (1<<0) |(1<<1); //definido como ENTRADA
    ANSELB &= ~((1<<0) |(1<<1));// pin digital
    WPUB |= (1<<0) |(1<<1);//pull-up ON
    INLVLB &= ~((1<<0) |(1<<1));//ttl
    SLRCONB |= (1<<0) |(1<<1);//limit
    ODCONB &= ~((1<<0) |(1<<1));//pushpull
    
//CONFIGURAR INT0
  PIE1bits.INT0IE =1;//INT0 ENABLE
  PIR1bits.INT0IF =0;//Clear flag
  IPR1bits.INT0IP = 1;//High Priority  
    
//CONFIGURAR INT1
  PIE6bits.INT1IE =1;//INT1 ENABLE
  PIR6bits.INT1IF =0;//Clear flag
  IPR6bits.INT1IP = 0;//Low Priority  
  
  
  INTCON0bits.IPEN = 1;
  INTCON0bits.GIEH = 1;
  INTCON0bits.GIEL = 1;
  
  
  /*UBICACION DEL VECTOR DE INTERRUPCION*/
   //0x400
  //IVTBASE= IVTBASEu+IVTBASEh+IVTBASEl
  di();//disable interrupt
  IVTBASEU= 0x00;//5bit
  IVTBASEH= 0x04;//8bit
  IVTBASEL= 0x00;//8bit
  ei();//enable interrup
  
  
  
}

volatile uint8_t j,k;
void __interrupt(irq(IRQ_INT0),base(0x400),high_priority) InterrupExtern(void){

    if (PIR1bits.INT0IF) {
        
        
        for (j = 0; j < 20; j++) {
            LATF ^= (1<<3);
            __delay_ms(2);
        }

        
        PIR1bits.INT0IF=0;
    }


}


void __interrupt(irq(IRQ_INT1),base(0x400),low_priority) DEFAULT_ISR(void){
    if (PIR6bits.INT1IF) {

        for (k = 0; k < 20; k++) {
            LATF ^= (1<<3);
            __delay_ms(10);

        }

        
        PIR6bits.INT1IF=0;
    }


}

