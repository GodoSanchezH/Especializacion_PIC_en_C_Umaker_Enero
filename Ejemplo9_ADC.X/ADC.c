#include "ADC.h"
#include <xc.h>

void ADC_Init(void){
/*configuracion de los pines*/
    TRISAbits.TRISA0 = 1;
    TRISAbits.TRISA2 = 1;
    ANSELAbits.ANSELA0 = 1;
    ANSELAbits.ANSELA2 = 1;

    
    ADCON0bits.CS = 0;//Fosc
    ADCON0bits.FM = 1;
    ADCON2bits.MD = 0b000;
    ADREFbits.NREF= 0;//AVSS
    ADREFbits.PREF = 0B00;
    ADCLK = 0b001111;//500nS
    ADCON0bits.ON = 1;//habilitamos el adc
    
}


uint16_t AnalogRead(ADC_CHANEL Anx){

ADPCH = Anx;
ADCON0bits.GO = 1;//iniciamos la conversion

while(ADCON0bits.GO == 1);

return ((uint16_t) ((ADRESH<<8)+ADRESL));
}

