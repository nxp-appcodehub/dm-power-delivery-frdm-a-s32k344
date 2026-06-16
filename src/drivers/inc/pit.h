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

#ifndef DRIVERS_PIT_PIT_H_
#define DRIVERS_PIT_PIT_H_

#include "PlatformTypes.h"

/*Structure for callback function with interrupt sources*/
typedef struct
{
	uint8_t  pit_instance; /*PIT instance*/
	uint32_t rti_tif;		/*TIF register or RTI*/
	uint32_t tmr0_tif;		/*TIF register or Timer0*/
	uint32_t tmr1_tif;		/*TIF register or Timer1*/
	uint32_t tmr2_tif;		/*TIF register or Timer2*/
	uint32_t tmr3_tif;		/*TIF register or Timer3*/
} pit_cb_type_t;

/*Callback function type*/
typedef void (*pit_cb)(pit_cb_type_t * type);

/*Timer type enum*/
typedef enum pit_tmr
{
	RTI = 0,
	TMR0,
	TMR1,
	TMR2,
	TMR3
} pit_tmr_e;

/*timer configuration structure*/
typedef struct pit_tmr_cfg
{
	uint32_t init_value;	/*Initial value*/
	uint8_t chain 		:1;	/*Chain enable*/
	pit_tmr_e tmr 		:3;	/*Timer selection*/
	pit_cb cb;				/*Callback function*/
} pit_tmr_cfg_t;
/* @note Timer will count down from init_value to 0 and generate the interrupt */

extern void NVIC_SetPriority(uint8 IRQn, uint8 priority);
extern void NVIC_EnableIRQ(uint8 IRQn);

/*
 * pit_init
 * @brief	Initializes the PIT module
 * @param	Instance of PIT
 */
void pit_init(volatile PIT_Type * module);

/*
 * pit_config_tmr
 * @brief	Enables and configure a timer
 * @param	Instance of PIT
 * @param	Configuration structure
 */
void pit_config_tmr(volatile PIT_Type * module, pit_tmr_cfg_t * cfg);

/*
 * pit_disable_tmr
 * @brief	Disables a timer
 * @param	Instance of PIT
 * @param	One of @ref pit_tmr_e
 */
void pit_disable_tmr(volatile PIT_Type * module, pit_tmr_e type);

/*
 * pit_get_current_value
 * @brief	Returns the current value of the selected timer
 * @param	Instance of PIT
 * @param	One of @ref pit_tmr_e
 * @return	Timer value
 */
uint32_t pit_get_current_value(volatile PIT_Type * module, pit_tmr_e type);

#endif /* DRIVERS_PIT_PIT_H_ */
