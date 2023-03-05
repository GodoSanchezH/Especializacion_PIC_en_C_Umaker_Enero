/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18F57Q43
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"
#include "stdint.h"
/*
                         Main application
 */

#define N_MUESTRAS 11


/*Coeficientes FIR*/
#define a0 0
#define a1 0.018938484976377
#define a2 0.068837449192955
#define a3 0.130838003854186
#define a4 0.181171174234027
#define a5 0.200429775484910
#define a6 0.181171174234027
#define a7 0.130838003854186
#define a8 0.068837449192955
#define a9 0.018938484976377
#define a10 0


typedef struct{
    uint16_t n[N_MUESTRAS];
    uint16_t adc;
}Entradas;

typedef struct{

    float n[N_MUESTRAS];
}Salidas;


#define InicioTrama 0X00
#define FintTrama 0xFF
uint16_t adc_read[2];
  uint8_t i;

Entradas X;
Salidas Y;

void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

  
    for (i = 0; i < N_MUESTRAS; i++) {
        X.n[i] = 0;
    }
    for (i = 0; i < N_MUESTRAS; i++) {
        Y.n[i] = 0;
    }
    uint16_t value;
    while (1)
    {
        // Add your application code
        X.adc = ADCC_GetSingleConversion(Input);
       
        /*Actualizamos las entradas*/
        X.n[10] =  X.n[9]
        X.n[9] =  X.n[8]
        X.n[8] =  X.n[7]
        X.n[7] =  X.n[6]
        X.n[6] =  X.n[5]
        X.n[5] =  X.n[4]
        X.n[4] =  X.n[3]
        X.n[3] =  X.n[2]
        X.n[2] =  X.n[1]
        X.n[1] =  X.n[0]
        X.n[0] = X.adc;
        
        /**actualizar la salida*/
        Y.n[0] = a0*X.n[0]+a1*X.n[1]+a2*X.n[2]+a3*X.n[3]+a4*X.n[4]+a5*X.n[5]+a6*X.n[6]+a7*X.n[7]+a8*X.n[8]+a9*X.n[9]+a10*X.n[10];
        
      
        __delay_ms(100);
    }
}
/**
 End of File
*/