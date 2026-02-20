/*==================================================================================================
 * Project : RTD AUTOSAR 4.9
 * Platform : CORTEXM
 * Peripheral : S32K3XX
 * Dependencies : none
 *
 * Autosar Version : 4.9.0
 * Autosar Revision : ASR_REL_4_9_REV_0000
 * Autosar Conf.Variant :
 * SW Version : 7.0.0
 * Build Version : S32K3_RTD_7_0_0_QLP03_D2512_ASR_REL_4_9_REV_0000_20251210
 *
 * Copyright 2020 - 2026 NXP
 *
 *   NXP Proprietary. This software is owned or controlled by NXP and may only be
 *   used strictly in accordance with the applicable license terms. By expressly
 *   accepting such terms or by downloading, installing, activating and/or otherwise
 *   using the software, you are agreeing that you have read, and that you agree to
 *   comply with and are bound by, such license terms. If you do not agree to be
 *   bound by the applicable license terms, then you may not retain, install,
 *   activate or otherwise use the software.
==================================================================================================*/

#ifndef ADC_DRIVER_H_
#define ADC_DRIVER_H_

#include "S32K344.h"

#define ADC_INSTANCES 3

#define ADC_PRECISION_CHANNEL_MIN 0
#define ADC_PRECISION_CHANNEL_MAX 7
#define ADC_PRECISION_CHANNEL_INSTANCES 8

#define ADC_STANDARD_CHANNEL_MIN 32
#define ADC_STANDARD_CHANNEL_MAX 47
#define ADC_STANDARD_CHANNEL_INSTANCES 16

#define ADC_EXTERNAL_CHANNEL_MIN 64
#define ADC_EXTERNAL_CHANNEL_MAX 95
#define ADC_EXTERNAL_CHANNEL_INSTANCES 32

#define ADC_BANDGAP_CHANNEL 48
#define ADC_TEMPSENSOR_CHANNEL 49
#define ADC_ANAMUX_CHANNEL 50
#define ADC_VREFL_CHANNEL 54
#define ADC_VREFH_CHANNEL 55
#define ADC_SPECIAL_CHANNEL_INSTANCES 5

typedef enum
{
	ADC_SUCCESS,
	INSTANCE_ALREADY_INITIALIZED,
	INSTANCE_ALREADY_UNINITIALIZED,
	INSTANCE_UNITIALIZED,
	CHANNEL_ALREADY_INITIALIZED,
	CHANNEL_UNITIALIZED,
	CHANNEL_INVALID,
	READING_TIMEOUT,
	CALIBRATION_FAILED,
	UNKNOWN_ERROR
}ERROR_CODES_t;


extern char* ADC_ERROR_CODES_STR[];

typedef struct
{
	uint8_t instanceInitialized;
	uint8_t precisionChannelsInitialized[ADC_PRECISION_CHANNEL_INSTANCES];
	uint8_t standardChannelsInitialized[ADC_STANDARD_CHANNEL_INSTANCES];
	uint8_t externalChannelsInitialized[ADC_EXTERNAL_CHANNEL_INSTANCES];
	uint8_t specialChannelsInitialized[ADC_SPECIAL_CHANNEL_INSTANCES];
}ADCx_INITIALIZED_INSTANCES_t;

typedef enum
{
	ADC0,
	ADC1,
	ADC2
}ADCx_t;

#define IS_SPECIAL_ADC_CHANNEL(ch) \
    ((ch) == ADC_BANDGAP_CHANNEL || \
     (ch) == ADC_TEMPSENSOR_CHANNEL || \
     (ch) == ADC_VREFL_CHANNEL || \
     (ch) == ADC_VREFH_CHANNEL)


#define BIT_1 0x1
#define TIMEOUT_LIMIT 1000000


uint8_t initADCx(ADCx_t adcNum);
uint8_t initADC0(void);
uint8_t initADC1(void);
uint8_t initADC2(void);

uint8_t deinitADCx(ADCx_t adcNum);
uint8_t deinitADC0(void);
uint8_t deinitADC1(void);
uint8_t deinitADC2(void);

uint8_t initADCx_channels(ADCx_t adcNum, uint8_t channelNum);
uint8_t initADC0_channels(uint8_t channelNum);
uint8_t initADC1_channels(uint8_t channelNum);
uint8_t initADC2_channels(uint8_t channelNum);

uint8_t readADCx_channelx(ADCx_t adcNum, uint8_t channelNum, uint16_t *readData);
uint8_t readADC0_channelx(uint8_t channelNum, uint16_t *readData);
uint8_t readADC1_channelx(uint8_t channelNum, uint16_t *readData);
uint8_t readADC2_channelx(uint8_t channelNum, uint16_t *readData);



#endif /* ADC_DRIVER_H_ */
