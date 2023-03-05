/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18F57Q43
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.36 and above
        MPLAB 	          :  MPLAB X 6.00	
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set Input aliases
#define Input_TRIS                 TRISAbits.TRISA0
#define Input_LAT                  LATAbits.LATA0
#define Input_PORT                 PORTAbits.RA0
#define Input_WPU                  WPUAbits.WPUA0
#define Input_OD                   ODCONAbits.ODCA0
#define Input_ANS                  ANSELAbits.ANSELA0
#define Input_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define Input_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define Input_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define Input_GetValue()           PORTAbits.RA0
#define Input_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define Input_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define Input_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define Input_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define Input_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define Input_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define Input_SetAnalogMode()      do { ANSELAbits.ANSELA0 = 1; } while(0)
#define Input_SetDigitalMode()     do { ANSELAbits.ANSELA0 = 0; } while(0)

// get/set IO_RB4bton aliases
#define IO_RB4bton_TRIS                 TRISBbits.TRISB4
#define IO_RB4bton_LAT                  LATBbits.LATB4
#define IO_RB4bton_PORT                 PORTBbits.RB4
#define IO_RB4bton_WPU                  WPUBbits.WPUB4
#define IO_RB4bton_OD                   ODCONBbits.ODCB4
#define IO_RB4bton_ANS                  ANSELBbits.ANSELB4
#define IO_RB4bton_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define IO_RB4bton_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define IO_RB4bton_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define IO_RB4bton_GetValue()           PORTBbits.RB4
#define IO_RB4bton_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define IO_RB4bton_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define IO_RB4bton_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define IO_RB4bton_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define IO_RB4bton_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define IO_RB4bton_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define IO_RB4bton_SetAnalogMode()      do { ANSELBbits.ANSELB4 = 1; } while(0)
#define IO_RB4bton_SetDigitalMode()     do { ANSELBbits.ANSELB4 = 0; } while(0)

// get/set RF0 procedures
#define RF0_SetHigh()            do { LATFbits.LATF0 = 1; } while(0)
#define RF0_SetLow()             do { LATFbits.LATF0 = 0; } while(0)
#define RF0_Toggle()             do { LATFbits.LATF0 = ~LATFbits.LATF0; } while(0)
#define RF0_GetValue()              PORTFbits.RF0
#define RF0_SetDigitalInput()    do { TRISFbits.TRISF0 = 1; } while(0)
#define RF0_SetDigitalOutput()   do { TRISFbits.TRISF0 = 0; } while(0)
#define RF0_SetPullup()             do { WPUFbits.WPUF0 = 1; } while(0)
#define RF0_ResetPullup()           do { WPUFbits.WPUF0 = 0; } while(0)
#define RF0_SetAnalogMode()         do { ANSELFbits.ANSELF0 = 1; } while(0)
#define RF0_SetDigitalMode()        do { ANSELFbits.ANSELF0 = 0; } while(0)

// get/set RF1 procedures
#define RF1_SetHigh()            do { LATFbits.LATF1 = 1; } while(0)
#define RF1_SetLow()             do { LATFbits.LATF1 = 0; } while(0)
#define RF1_Toggle()             do { LATFbits.LATF1 = ~LATFbits.LATF1; } while(0)
#define RF1_GetValue()              PORTFbits.RF1
#define RF1_SetDigitalInput()    do { TRISFbits.TRISF1 = 1; } while(0)
#define RF1_SetDigitalOutput()   do { TRISFbits.TRISF1 = 0; } while(0)
#define RF1_SetPullup()             do { WPUFbits.WPUF1 = 1; } while(0)
#define RF1_ResetPullup()           do { WPUFbits.WPUF1 = 0; } while(0)
#define RF1_SetAnalogMode()         do { ANSELFbits.ANSELF1 = 1; } while(0)
#define RF1_SetDigitalMode()        do { ANSELFbits.ANSELF1 = 0; } while(0)

// get/set led aliases
#define led_TRIS                 TRISFbits.TRISF3
#define led_LAT                  LATFbits.LATF3
#define led_PORT                 PORTFbits.RF3
#define led_WPU                  WPUFbits.WPUF3
#define led_OD                   ODCONFbits.ODCF3
#define led_ANS                  ANSELFbits.ANSELF3
#define led_SetHigh()            do { LATFbits.LATF3 = 1; } while(0)
#define led_SetLow()             do { LATFbits.LATF3 = 0; } while(0)
#define led_Toggle()             do { LATFbits.LATF3 = ~LATFbits.LATF3; } while(0)
#define led_GetValue()           PORTFbits.RF3
#define led_SetDigitalInput()    do { TRISFbits.TRISF3 = 1; } while(0)
#define led_SetDigitalOutput()   do { TRISFbits.TRISF3 = 0; } while(0)
#define led_SetPullup()          do { WPUFbits.WPUF3 = 1; } while(0)
#define led_ResetPullup()        do { WPUFbits.WPUF3 = 0; } while(0)
#define led_SetPushPull()        do { ODCONFbits.ODCF3 = 0; } while(0)
#define led_SetOpenDrain()       do { ODCONFbits.ODCF3 = 1; } while(0)
#define led_SetAnalogMode()      do { ANSELFbits.ANSELF3 = 1; } while(0)
#define led_SetDigitalMode()     do { ANSELFbits.ANSELF3 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/