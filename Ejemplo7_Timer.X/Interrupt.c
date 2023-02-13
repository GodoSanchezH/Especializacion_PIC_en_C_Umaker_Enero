#include "Interrupt.h"
#include <xc.h>
#include "Config.h"


void Interrupt_Config(void){

    
  INTCON0bits.IPEN = 1;
  INTCON0bits.GIEH = 1;
  INTCON0bits.GIEL = 1;
  
  PIE3bits.TMR0IE = 1;
  PIR3bits.TMR0IF = 0;
  IPR3bits.TMR0IP = 1;
  
  
  
  /*UBICACION DEL VECTOR DE INTERRUPCION*/
   //0x400
  //IVTBASE= IVTBASEu+IVTBASEh+IVTBASEl
  di();//disable interrupt
  IVTBASEU= 0x00;//5bit
  IVTBASEH= 0x04;//8bit
  IVTBASEL= 0x00;//8bit
  ei();//enable interrup
  
  
  
}

void __interrupt(irq(IRQ_TMR0),base(0x400),high_priority) InterrupExtern(void){

  LATF ^= (1<<3);
 
  PIR3bits.TMR0IF = 0;
 TMR0H =  0X6D;
            TMR0L = 0X83;
}


void __interrupt(irq(IRQ_INT1),base(0x400),low_priority) DEFAULT_ISR(void){


}

