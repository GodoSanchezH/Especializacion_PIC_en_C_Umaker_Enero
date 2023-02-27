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
#include "mcc_generated_files/examples/i2c1_master_example.h"

/*
                         Main application
 */
void rtc_init(void);
void write_init(void);
void read_init(void);
#define AM
#define PM
uint8_t segundos=0,minutos =58,hora=17;
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global Interrupts
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();
    
    uint8_t dac_data[2] = {20,20};
             uint8_t lectura_data[8];
    uint8_t respuesta=0,i;
    
    while(boton_GetValue());
//        for (i = 0; i < 128; i++) {
//            respuesta = I2C1_Open(i);
//            if (respuesta!=I2C1_FAIL) {
//               
//                printf("0x%X\n\r",i);
//                respuesta= 0;
//            }
//           else printf("-\n\r");
//            
//       }

    write_init();
    
    while (1)
    {
        // Add your application code
        
    
        
        
        read_init();
        //I2C1_ReadNBytes(0x68,lectura_data,8);
        led_Toggle();
        __delay_ms(1000);
        
        
    }
}
/**
 End of File
*/

void rtc_init(void){
 I2C1_WriteNBytes(0x68,0x0,1);
}
void write_init(void){
    uint8_t segundo_rtc,minuto_rtc,hora_rtc;
    segundo_rtc = ((segundos/10)<<4) | (segundos%10);
    minuto_rtc = ((minutos/10)<<4) | (minutos%10);
    hora_rtc = ((hora/10)<<4) | (hora%10);
    
    uint8_t buffer_send[4] = {0x00,segundo_rtc,minuto_rtc,hora_rtc};
     I2C1_WriteNBytes(0x68,buffer_send,4);
    
}
void read_init(void){

    uint8_t segundo_rtc,minuto_rtc,hora_rtc;
    uint8_t  *buffer_rx[3];
    I2C1_WriteNBytes(0x68,0x0,1);
    I2C1_ReadNBytes(0x68,buffer_rx,3);
    
    
    *buffer_rx[0] = ((*buffer_rx[0] & 0xF0)>>4)*10+(*buffer_rx[0] & 0x0F);
    *buffer_rx[1] = ((*buffer_rx[1] & 0xF0)>>4)*10+(*buffer_rx[1] & 0x0F);
    *buffer_rx[2] = ((*buffer_rx[2] & 0xF0)>>4)*10+(*buffer_rx[2] & 0x0F);
    
    printf("Segundos = %u Minutos= %u hora %u\n\r ",buffer_rx[0],buffer_rx[1],buffer_rx[2]);
}