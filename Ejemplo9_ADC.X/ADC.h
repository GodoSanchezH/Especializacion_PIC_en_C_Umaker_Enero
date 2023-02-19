/* 
 * File:   ADC.h
 * Author: gssan
 *
 * Created on 19 de febrero de 2023, 04:19 PM
 */

#ifndef ADC_H
#define	ADC_H


#include <stdint.h>


typedef enum{
    AN0=0,
            AN1,
            AN2,
            AN3,
            AN4,
            AN5,
            AN6,
            AN7

}ADC_CHANEL;

void ADC_Init(void);
uint16_t AnalogRead(ADC_CHANEL Anx);





#endif	/* ADC_H */

