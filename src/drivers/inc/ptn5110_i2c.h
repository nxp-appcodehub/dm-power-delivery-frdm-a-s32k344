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

#ifndef PTN5110_I2C_H_
#define PTN5110_I2C_H_

#include "I2C.h"

#define USE_BAREMETAL_I2C		(0U)

#if (USE_BAREMETAL_I2C == 0U)
#include "Lpi2c_Ip.h"
#endif

#define LIMIT_PTN5110			(25U)
#define TIMEOUT_PTN5110			(0xFFFFFFFF)

#define TIMEOUT_TEST			(0xFFFF)

void PD_I2cWriteBlocking(uint8_t instance,
                                uint16_t slave,
                                uint8_t registerAddr,
                                uint8_t *data,
                                uint8_t num);

void PD_I2cReadBlocking(uint8_t instance,
                                uint16_t slave,
                                uint8_t registerAddr,
                                uint8_t *data,
                                uint8_t num);

#endif /* PTN5110_I2C_H_ */
