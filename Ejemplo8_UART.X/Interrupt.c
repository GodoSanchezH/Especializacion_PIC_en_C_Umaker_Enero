#include "Interrupt.h"
#include <xc.h>
#include "Config.h"


void Interrupt_Config(void){

    
  INTCON0bits.IPEN = 1;
  INTCON0bits.GIEH = 1;
  INTCON0bits.GIEL = 1;
 
  
  PIE4bits.U1RXIE = 1;
  PIR4bits.U1RXIF = 0;
  IPR4bits.U1RXIP = 1;
  
  /*UBICACION DEL VECTOR DE INTERRUPCION*/
   //0x400
  //IVTBASE= IVTBASEu+IVTBASEh+IVTBASEl
  di();//disable interrupt
  IVTBASEU= 0x00;//5bit
  IVTBASEH= 0x04;//8bit
  IVTBASEL= 0x00;//8bit
  ei();//enable interrup
  
  
  
}

void __interrupt(irq(IRQ_U1RX),base(0x400),high_priority) HP_ISR(void){

    
    
     PIR4bits.U1RXIF = 0;
}





void __interrupt(irq(IRQ_INT1),base(0x400),low_priority) DEFAULT_ISR(void){


}

