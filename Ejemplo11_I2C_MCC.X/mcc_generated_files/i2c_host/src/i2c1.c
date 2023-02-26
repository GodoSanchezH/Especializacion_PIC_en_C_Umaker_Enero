/**
 * I2C1 Generated Driver File
 *
 * @file i2c1.c
 *
 * @ingroup i2c_host
 *
 * @brief This file contains the driver code for the I2C1 module.
 *
 * @version I2C1 Driver Version 2.1.0
 */

/*
� [2023] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

#include <xc.h>
#include "../../system/config_bits.h"
#include "../i2c1.h"

/* I2C1 event system interfaces */
static void I2C1_ReadStart(void);
static void I2C1_WriteStart(void);
static void I2C1_Close(void);
static void I2C1_DefaultCallback(void);

/* I2C1 interfaces */
static void I2C1_StartSend(void);
static void I2C1_AddrTransmit(uint8_t addr);
static void I2C1_DataTransmit(uint8_t data);
static uint8_t I2C1_DataReceive(void);
static void I2C1_CounterSet(uint8_t counter);
static uint8_t I2C1_CounterGet(void);
static inline void I2C1_BusReset(void);
static inline void I2C1_RestartEnable(void);
static inline void I2C1_RestartDisable(void);
static void I2C1_StopSend(void);
static bool I2C1_IsNack(void);
static bool I2C1_IsBusCol(void);
static bool I2C1_IsBusTimeOut(void);
static bool I2C1_IsData(void);
static bool I2C1_IsAddr(void);
static inline void I2C1_InterruptsClear(void);
static inline void I2C1_ErrorFlagsClear(void);
static inline void I2C1_BufferClear(void);

/**
  Section: Driver Interface
 */
const i2c_host_interface_t I2C1_Host = {
    .Initialize = I2C1_Initialize,
    .Deinitialize = I2C1_Deinitialize,
    .Write = I2C1_Write,
    .Read = I2C1_Read,
    .WriteRead = I2C1_WriteRead,
    .TransferSetup = NULL,
    .ErrorGet = I2C1_ErrorGet,
    .IsBusy = I2C1_IsBusy,
    .CallbackRegister = I2C1_CallbackRegister,
    .Tasks = I2C1_Tasks
};

/**
 Section: Private Variable Definitions
 */
static void (*I2C1_Callback)(void) = NULL;
volatile i2c_host_event_status_t i2c1Status = {0};

/**
 Section: Public Interfaces
 */
void I2C1_Initialize(void)
{
    /* CSTR Enable clocking; S Cleared by hardware after Start; MODE 7-bit address; EN disabled; RSEN disabled;  */
    I2C1CON0 = 0x4;
    /* TXU No underflow; CSD Clock Stretching enabled; ACKT No Acknowledge sequence; RXO No overflow; ACKDT Acknowledge; ACKSTAT ACK received; ACKCNT Not Acknowledge;  */
    I2C1CON1 = 0x80;
    /* ABD enabled; GCEN disabled; ACNT disabled; SDAHT 30 ns hold time; BFRET 8 I2C Clock pulses; FME disabled;  */
    I2C1CON2 = 0x8;
    /* CLK MFINTOSC;  */
    I2C1CLK = 0x3;
    /* WRIF Data byte not detected; CNTIF Byte count is not zero; RSCIF Restart condition not detected; PCIF Stop condition not detected; ACKTIF Acknowledge sequence not detected; ADRIF Address not detected; SCIF Start condition not detected;  */
    I2C1PIR = 0x0;
    /* CNTIE disabled; RSCIE disabled; ACKTIE disabled; SCIE disabled; PCIE disabled; ADRIE disabled; WRIE disabled;  */
    I2C1PIE = 0x0;
    /* BTOIE disabled; BTOIF No bus timeout; NACKIF No NACK/Error detected; BCLIE disabled; BCLIF No bus collision detected; NACKIE disabled;  */
    I2C1ERR = 0x0;
    /* Count register */
    I2C1CNT = 0x0;
    /* Clock PadReg Configuration */
    RB1I2C = 0x51;
    /* Data PadReg Configuration */
    RB2I2C = 0x51;

    /* Silicon-Errata: Section: 1.3.2 */
    #warning "Refer to erratum DS80000870F: https://www.microchip.com/content/dam/mchp/documents/MCU08/ProductDocuments/Errata/PIC18F27-47-57Q43-Silicon-Errata-and-Datasheet-Clarifications-80000870J.pdf"
    I2C1CON0bits.EN = 1;
    __delay_us(1);
    __nop();
    __nop();
    __nop();
    __nop();
    __nop();
    __nop();
    I2C1PIRbits.SCIF = 0;
    I2C1PIRbits.PCIF = 0;
    I2C1_CallbackRegister(I2C1_DefaultCallback);
}

void I2C1_Deinitialize(void)
{
    I2C1CON0 = 0x00;
    I2C1CON1 = 0x00;
    I2C1CON2 = 0x00;
    I2C1CLK = 0x00;
    I2C1PIR = 0x00;
    I2C1PIE = 0x00;
    I2C1ERR = 0x00;
    I2C1CNT = 0x00;
    I2C1_CallbackRegister(I2C1_DefaultCallback);
}

bool I2C1_Write(uint16_t address, uint8_t *data, size_t dataLength)
{
    bool retStatus = false;
    if (!I2C1_IsBusy())
    {
        i2c1Status.busy = true;
        i2c1Status.address = address;
        i2c1Status.switchToRead = false;
        i2c1Status.writePtr = data;
        i2c1Status.writeLength = dataLength;
        i2c1Status.readPtr = NULL;
        i2c1Status.readLength = 0;
        i2c1Status.errorState = I2C_ERROR_NONE;
        I2C1_WriteStart();
        retStatus = true;
    }
    return retStatus;
}

bool I2C1_Read(uint16_t address, uint8_t *data, size_t dataLength)
{
    bool retStatus = false;
    if (!I2C1_IsBusy())
    {
        i2c1Status.busy = true;
        i2c1Status.address = address;
        i2c1Status.switchToRead = false;
        i2c1Status.readPtr = data;
        i2c1Status.readLength = dataLength;
        i2c1Status.writePtr = NULL;
        i2c1Status.writeLength = 0;
        i2c1Status.errorState = I2C_ERROR_NONE;
        I2C1_ReadStart();
        retStatus = true;
    }
    return retStatus;
}

bool I2C1_WriteRead(uint16_t address, uint8_t *writeData, size_t writeLength, uint8_t *readData, size_t readLength)
{
    bool retStatus = false;
    if (!I2C1_IsBusy())
    {
        i2c1Status.busy = true;
        i2c1Status.address = address;
        i2c1Status.switchToRead = true;
        i2c1Status.writePtr = writeData;
        i2c1Status.writeLength = writeLength;
        i2c1Status.readPtr = readData;
        i2c1Status.readLength = readLength;
        i2c1Status.errorState = I2C_ERROR_NONE;
        I2C1_WriteStart();
        retStatus = true;
    }
    return retStatus;
}

i2c_host_error_t I2C1_ErrorGet(void)
{
    i2c_host_error_t retErrorState = i2c1Status.errorState;
    i2c1Status.errorState = I2C_ERROR_NONE;
    return retErrorState;
}

bool I2C1_IsBusy(void)
{
    return i2c1Status.busy || !I2C1STAT0bits.BFRE;
}

void I2C1_CallbackRegister(void (*callbackHandler)(void))
{
    if (callbackHandler != NULL)
    {
        I2C1_Callback = callbackHandler;
    }
}

void I2C1_Tasks(void)
{
    if (I2C1ERRbits.NACKIF || I2C1ERRbits.BCLIF || I2C1ERRbits.BTOIF)
    {
        if (I2C1_IsBusCol())
        {
            i2c1Status.errorState = I2C_ERROR_BUS_COLLISION;
            I2C1ERRbits.BCLIF = 0;
            I2C1_BusReset();
        }
        else if (I2C1_IsAddr() && I2C1_IsNack())
        {
            i2c1Status.errorState = I2C_ERROR_ADDR_NACK;
            I2C1ERRbits.NACKIF = 0;
            I2C1_StopSend();
        }
        else if (I2C1_IsData() && I2C1_IsNack())
        {
            i2c1Status.errorState = I2C_ERROR_DATA_NACK;
            I2C1ERRbits.NACKIF = 0;
            I2C1_StopSend();
        }
        else if (I2C1_IsBusTimeOut())
        {
            i2c1Status.errorState = I2C_ERROR_BUS_COLLISION;
            I2C1ERRbits.BTOIF = 0;
            I2C1_Close();
        }
        else
        {
            I2C1ERRbits.NACKIF = 0;
        }

        if (i2c1Status.errorState != I2C_ERROR_NONE)
        {
            I2C1_Callback();
        }
    }
    else if (I2C1PIRbits.PCIF || I2C1PIRbits.CNTIF || I2C1PIRbits.RSCIF)
    {
        if (PIR7bits.I2C1RXIF)
        {
            *i2c1Status.readPtr++ = I2C1_DataReceive();
        }

        if (I2C1PIRbits.PCIF)
        {
            I2C1_Close();
        }
        else if (I2C1PIRbits.CNTIF)
        {
            /*Check if restart is required*/
            if (i2c1Status.switchToRead)
            {
                i2c1Status.switchToRead = false;
                I2C1PIRbits.SCIF = 0;
                I2C1PIRbits.CNTIF = 0;
                I2C1_ReadStart();
            }
            else 
            {
                I2C1_StopSend();
                I2C1_Close();
            }
        }
        else if (I2C1PIRbits.RSCIF)
        {
            I2C1_RestartDisable();
            I2C1PIRbits.RSCIF = 0;
        }
    }
    else if (PIR7bits.I2C1RXIF)
    {
        *i2c1Status.readPtr++ = I2C1_DataReceive();
    }
    else if (PIR7bits.I2C1TXIF)
    {
        I2C1_DataTransmit(*i2c1Status.writePtr++);
    }
}

/**
 Section: Private Interfaces
 */
static void I2C1_ReadStart(void)
{
    if (i2c1Status.readLength)
    {
        I2C1_CounterSet((uint8_t) i2c1Status.readLength);
    }

    I2C1_AddrTransmit((uint8_t) (i2c1Status.address << 1 | 1));
    I2C1_StartSend();
}

static void I2C1_WriteStart(void)
{
    if (i2c1Status.writeLength)
    {
        I2C1_CounterSet((uint8_t) i2c1Status.writeLength);
        if (i2c1Status.switchToRead)
        {
            I2C1_RestartEnable();
        }
    }

    I2C1_AddrTransmit((uint8_t) (i2c1Status.address << 1));
    I2C1_StartSend();
}

static void I2C1_Close(void)
{
    i2c1Status.busy = false;
    i2c1Status.address = 0xFF;
    i2c1Status.writePtr = NULL;
    i2c1Status.readPtr = NULL;
    I2C1_InterruptsClear();
    I2C1_ErrorFlagsClear();
    I2C1_BufferClear();
}

static void I2C1_DefaultCallback(void)
{
    // Default Callback for Error Indication
}

/**
 Section: Register Level Interfaces
 */
static void I2C1_StartSend(void)
{
    I2C1CON0bits.S = 1;
}

static void I2C1_AddrTransmit(uint8_t addr)
{
    I2C1ADB1 = addr;
}

static void I2C1_DataTransmit(uint8_t data)
{
    I2C1TXB = data;
}

static uint8_t I2C1_DataReceive(void)
{
    return I2C1RXB;
}

static void I2C1_CounterSet(uint8_t counter)
{
    I2C1CNT = counter;
}

static uint8_t I2C1_CounterGet(void)
{
    return (uint8_t) I2C1CNT;
}

static inline void I2C1_BusReset(void)
{
    I2C1_InterruptsClear();
    I2C1_ErrorFlagsClear();
    I2C1_BufferClear();
    I2C1CON0bits.EN = 0;

    /* Silicon-Errata: Section: 1.3.2 */
    #warning "Refer to erratum DS80000870F: https://www.microchip.com/content/dam/mchp/documents/MCU08/ProductDocuments/Errata/PIC18F27-47-57Q43-Silicon-Errata-and-Datasheet-Clarifications-80000870J.pdf"
    I2C1CON0bits.EN = 1;
    __delay_us(1);
    __nop();
    __nop();
    __nop();
    __nop();
    __nop();
    __nop();
    I2C1PIRbits.SCIF = 0;
    I2C1PIRbits.PCIF = 0;
}

static inline void I2C1_RestartEnable(void)
{
    I2C1CON0bits.RSEN = 1;
}

static inline void I2C1_RestartDisable(void)
{
    I2C1CON0bits.RSEN = 0;
}

static void I2C1_StopSend(void)
{
    I2C1_RestartDisable();
    if (I2C1_CounterGet())
    {
        I2C1_CounterSet(0);
        I2C1_DataTransmit(0);
    }
}

static bool I2C1_IsNack(void)
{
    return I2C1CON1bits.ACKSTAT;
}

static bool I2C1_IsBusCol(void)
{
    return I2C1ERRbits.BCLIF;
}

static bool I2C1_IsBusTimeOut(void)
{
    return I2C1ERRbits.BTOIF;
}

static bool I2C1_IsData(void)
{
    return I2C1STAT0bits.D;
}

static bool I2C1_IsAddr(void)
{
    return !I2C1STAT0bits.D;
}

static inline void I2C1_InterruptsClear(void)
{
    I2C1PIR = 0x00;
}

static inline void I2C1_ErrorFlagsClear(void)
{
    I2C1ERRbits.BCLIF = 0;
    I2C1ERRbits.BTOIF = 0;
    I2C1ERRbits.NACKIF = 0;
}

static inline void I2C1_BufferClear(void)
{
    I2C1STAT1 = 0x00;
    I2C1STAT1bits.CLRBF = 1;
}