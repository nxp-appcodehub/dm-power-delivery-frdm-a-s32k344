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

#ifndef NX20P3483_H_
#define NX20P3483_H_

#include "ptn5110_i2c.h"

#if (USE_BAREMETAL_I2C == 0U)
#include "Lpi2c_Ip.h"
#endif

#define TIMEOUT_nx20p3483			(0xFFFFFFFF)
#define NX20P3483_DEVICE_ID_REG_VALUE (0x0Au)

typedef struct _info_NX20P3483
{
	uint8_t instance_i2c;
	uint16_t address;
} info_NX20P3483_t;

void nx20p3483_init(info_NX20P3483_t info);
void nx20p3483_Set5VSourceOCP(uint16_t current);
void nx20p3483_SetSinkOVP(uint16_t voltage);
void nx20p3483_Read_Interrupts(uint8_t* dst);

#endif /* NX20P3483_H_ */
