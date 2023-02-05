
#include "DIS_7SEG.h"
#include <xc.h>

void Write_Display7seg(Display7Seg *D7S,uint8_t val){

    const uint8_t Display_7Seg_C[] = {0x3F, 0X06 ,0X5B ,0x4f,0X66 ,0X6D, 0X7D, 0X07 ,0X7F, 0X67};
                                              
    uint8_t data=Display_7Seg_C[val];
    Reset_Display7seg();
    if(data & 0x1)  LATA |= 1<<D7S->a;
    if(data & 1<<1) LATA |= 1<<D7S->b;
    if(data & 1<<2) LATE |= 1<<D7S->c;
    if(data & 1<<3) LATC |= 1<<D7S->d;
    if(data & 1<<4) LATD |= 1<<D7S->e;
    if(data & 1<<5) LATD |= 1<<D7S->f;
    if(data & 1<<6) LATD |= 1<<D7S->g;
   
    return;
    
}

void Reset_Display7seg(void){

    LATAbits.LATA3 =0;
    LATAbits.LATA4 =0;
    LATEbits.LATE2 =0;
    LATCbits.LATC7 =0;
    LATDbits.LATD0 =0;
    LATDbits.LATD1 =0;
    LATDbits.LATD2 =0;
    
}
