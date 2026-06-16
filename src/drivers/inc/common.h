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

#ifndef COMMON_H_
#define COMMON_H_

#include <stdint.h>
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

/******************************************************************************
 * List of the basic configuration structure macros
 *
 *//*! @addtogroup config_struct_macros
 * @{
 ******************************************************************************/
/***************************************************************************//*!
 * @brief   Sets register field in peripheral configuration structure.
 * @details This macro sets register field <c>mask</c> in the peripheral
 *          configuration structure.
 * @param   mask  Register field to be set.
 * @note    Implemented as a macro.
 ******************************************************************************/
#define SET(mask)   (mask)

/***************************************************************************//*!
 * @brief   Clears register field in peripheral configuration structure.
 * @details This macro clears register field <c>mask</c> in the peripheral
 *          configuration structure.
 * @param   mask  Register field to be cleared.
 * @note    Implemented as a macro.
 ******************************************************************************/
#define CLR(mask)   0
/*! @} End of config_struct_macros  										*/

typedef int8_t driver_error_t;

typedef enum {
    MCU_DOMAIN_PLATFORM,
    MCU_DOMAIN_LPE,
    MCU_DOMAIN_CPE
} mcu_domain_e;


/*	ERROR status definitions and MACROS*/

enum _status_groups
{
	kStatusGroup_Generic			= 0,
	kStatusGroup_SPI				= 1,
	kStatusGroup_UART				= 2,
	kStatusGroup_I2C				= 3
};

#define MAKE_STATUS(group, code)	(((group)*100L) + (code))

enum
{
	kStatus_Success						= MAKE_STATUS(kStatusGroup_Generic, 0),
	kStatus_Fail						= MAKE_STATUS(kStatusGroup_Generic, 1),
	kStatus_ReadOnly					= MAKE_STATUS(kStatusGroup_Generic, 2),
	kStatus_OutOfRange					= MAKE_STATUS(kStatusGroup_Generic, 3),
	kStatus_InvalidArgument				= MAKE_STATUS(kStatusGroup_Generic, 4),
	kStatus_Timeout						= MAKE_STATUS(kStatusGroup_Generic, 5),
	kStatus_NoTransferInProgress		= MAKE_STATUS(kStatusGroup_Generic, 6),
	kStatus_Busy						= MAKE_STATUS(kStatusGroup_Generic, 7),
	kStatus_NoData						= MAKE_STATUS(kStatusGroup_Generic, 8),
	kStatus_ConfNotPossible				= MAKE_STATUS(kStatusGroup_Generic, 9),
	kStatus_ModuleNotAvailable			= MAKE_STATUS(kStatusGroup_Generic, 10)
};

typedef int32_t status_t;


#endif /* COMMON_H_ */
