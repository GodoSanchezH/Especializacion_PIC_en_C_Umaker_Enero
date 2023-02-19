/**
 * ADCC Generated Driver API Header File
 * 
 * @file adcc.h
 * 
 * @defgroup  adcc ADCC
 * 
 * @brief API Prototypes for the ADCC driver.
 *
 * @version ADCC Driver Version 2.1.4
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

#ifndef ADCC_H
#define ADCC_H

/**
  Section: Included Files
*/

#include <stdint.h>
#include <stdbool.h>

/**
 @ingroup adcc
 @typedef adc_result_t
 @brief Used for the result of A/D conversion.
*/
typedef uint16_t adc_result_t;
#ifndef uint24_t
typedef __uint24 uint24_t;
#endif

/**
 * @ingroup adcc
 * @enum adcc_channel_t
 * @brief Contains available ADC channels.
*/
typedef enum
{
    channel_VSS =  0x3b,
    channel_Temp =  0x3c,
    channel_DAC1 =  0x3d,
    channel_FVR_Buffer1 =  0x3e,
    channel_FVR_Buffer2 =  0x3f,
    channel_ANA0 =  0x0,
    channel_ANA2 =  0x2
} adcc_channel_t;

/**
  Section: ADCC Module APIs
*/

/**
 * @ingroup adcc
 * @brief Initializes the ADC module. This routine must be called before any other ADC routine.
 * @param none
 * @return none
*/
void ADCC_Initialize(void);

/**
 * @ingroup adcc
 * @brief Starts A/D conversion on the selected channel.
 * @param channel - Analog channel number on which A/D conversion has to be applied.
 *                  Refer adcc_channel_t for available list of channels
 * @return none
*/
void ADCC_StartConversion(adcc_channel_t channel);

/**
 * @ingroup adcc
 * @brief Checks if ongoing A/D conversion is complete.
 * @pre ADCC_StartConversion() should be called before calling this function.
 * @param none
 * @retval true - if conversion is complete
 * @retval false - if conversion is ongoing
*/
bool ADCC_IsConversionDone(void);


/**
 * @ingroup adcc
 * @brief Retrieves the result of latest A/D conversion.
 * @pre ADCC_StartConversion() should be called before calling this function and completion status should be checked using ADCC_IsConversionDone() routine.
 * @param none
 * @return The result of A/D conversion. Refer adc_result_t
*/
adc_result_t ADCC_GetConversionResult(void);

/**
 * @ingroup adcc
 * @brief Retrieves the result of single A/D conversion on given channel.
 * @pre ADCC_DisableContinuousConversion() function should have been called before calling this function
 * @param channel - Analog channel number on which A/D conversion has to be applied.
 *                  Refer adcc_channel_t  for available channels
 * @return The result of A/D conversion. Refer adc_result_t
*/
adc_result_t ADCC_GetSingleConversion(adcc_channel_t channel);

/**
 * @ingroup adcc
 * @brief Stops ongoing A/D conversion.
 * @pre ADCC_StartConversion() function should have been called before calling this function.
 * @param none
 * @return none
*/
inline void ADCC_StopConversion(void);

/**
 * @ingroup adcc
 * @brief Enables Stop On Interrupt bit.
 * @pre ADCC_EnableContinuousConversion() function should have been called before calling this function.
 * @param none
 * @return none
*/
inline void ADCC_SetStopOnInterrupt(void);

/**
 * @ingroup adcc
 * @brief Discharges input sample capacitor by setting the channel to AVss.
 * @param none
 * @return none
*/
inline void ADCC_DischargeSampleCapacitor(void); 

/**
 * @ingroup adcc
 * @brief Loads ADC Acquisition Time Control register with specified value.
 * @param acquisitionValue - Value to be loaded in the acquisition time control register.
 * @return none
*/
void ADCC_LoadAcquisitionRegister(uint16_t acquisitionValue);

/**
 * @ingroup adcc
 * @brief Loads ADC Precharge Time Control register with specified value.
 * @param prechargeTime - Value to be loaded in the precharge time control register.
 * @return none
*/
void ADCC_SetPrechargeTime(uint16_t prechargeTime);

/**
 * @ingroup adcc
 * @brief Loads repeat counter with specified value.
 * @param repeatCount - Value to be loaded to repeat counter.
 * @return none
*/
void ADCC_SetRepeatCount(uint8_t repeatCount);

/**
 * @ingroup adcc
 * @brief Retrieves the current value of ADC Repeat Count register.
 * @pre ADCC_StartConversion() should be called before calling this function.
 * @param none
 * @return Current value of ADC Repeat Count register
*/
uint8_t ADCC_GetCurrentCountofConversions(void);

/**
 * @ingroup adcc
 * @brief Clears the accumulator.
 * @param none
 * @return none
*/
inline void ADCC_ClearAccumulator(void);

/**
 * @ingroup adcc
 * @brief Retrieves 18-bit value of ADC accumulator.
 * @param none
 * @return Value of ADC accumulator.
*/
uint24_t ADCC_GetAccumulatorValue(void);

/**
 * @ingroup adcc
 * @brief Determines whether ADC accumulator has overflowed.
 * @pre ADCC_StartConversion() should be called before calling this function.
 * @param none
 * @retval true - ADC accumulator has overflowed
 * @retval false - ADC accumulator has not overflowed
*/
bool ADCC_HasAccumulatorOverflowed(void);

/**
 * @ingroup adcc
 * @brief Retrieves the value of ADC Filter register.
 * @param none
 * @return 16-bit value obtained from ADFLTRH and ADFLTRL registers.
*/
uint16_t ADCC_GetFilterValue(void);

/**
 * @ingroup adcc
 * @brief Retrieves the value of ADC Previous register.
 * @pre ADCC_StartConversion() should be called before calling this function.
 * @param none
 * @return 16-bit value obtained from ADPREVH and ADPREVL registers.
*/
uint16_t ADCC_GetPreviousResult(void);

/**
 * @ingroup adcc
 * @brief Sets value of ADC Threshold Set-point.
 * @param setPoint - 16-bit value for set point.
 * @return none
*/
void ADCC_DefineSetPoint(uint16_t setPoint);

/**
 * @ingroup adcc
 * @brief Sets value of ADC Upper Threshold register.
 * @param upperThreshold - 16-bit value for upper threshold.
 * @return none
*/
void ADCC_SetUpperThreshold(uint16_t upperThreshold);

/**
 * @ingroup adcc
 * @brief Sets value of ADC Lower Threshold register.
 * @param lowerThreshold - 16-bit value for lower threshold.
 * @return none
*/
void ADCC_SetLowerThreshold(uint16_t lowerThreshold);

/**
 * @ingroup adcc
 * @brief Retrieves the value of ADC Set-point Error register.
 * @pre ADCC_StartConversion() should be called before calling this function.
 * @param none
 * @return 16-bit value obtained from ADERRH and ADERRL registers.
*/
uint16_t ADCC_GetErrorCalculation(void);

/**
 * @ingroup adcc
 * @brief Enables double-sampling bit.
 * @param none
 * @return none
*/
inline void ADCC_EnableDoubleSampling(void);

/**
 * @ingroup adcc
 * @brief Enables continuous conversion.
 * @param none
 * @return none
*/
inline void ADCC_EnableContinuousConversion(void);

/**
 * @ingroup adcc
 * @brief Disables continuous conversion.
 * @param none
 * @return none
*/
inline void ADCC_DisableContinuousConversion(void);

/**
 * @ingroup adcc
 * @brief Determines if ADC error has crossed the upper threshold.
 * @pre ADCC_StartConversion() should be called before calling this function.
 * @param none
 * @retval true - if ERR > UTH
 * @retval false - if ERR <= UTH
*/
bool ADCC_HasErrorCrossedUpperThreshold(void);

/**
 * @ingroup adcc
 * @brief Determines if ADC error is less than the lower threshold.
 * @pre ADCC_StartConversion() should be called before calling this function.
 * @param none
 * @retval true - if ERR < LTH
 * @retval false - if ERR >= LTH
*/
bool ADCC_HasErrorCrossedLowerThreshold(void);

/**
 * @ingroup adcc
 * @brief Retrieves the multi-stage status.
 * @pre ADCC_StartConversion() should be called before calling this function.
 * @param none
 * @return Contents of ADC STATUS register.
*/
uint8_t ADCC_GetConversionStageStatus(void);



#endif//ADCC_H
