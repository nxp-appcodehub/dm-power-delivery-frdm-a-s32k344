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

#include "ptn5110_i2c.h"

#if (USE_BAREMETAL_I2C == 0U)

uint8_t array_PTN5110_i2c_Tx[LIMIT_PTN5110] = {0x00, 0x00, 0x00, 0x00, 0x00};

void PD_I2cWriteBlocking(uint8_t instance,
                                uint16_t slave,
                                uint8_t registerAddr,
                                uint8_t *data,
                                uint8_t num) {
	uint8_t index = 0;
	array_PTN5110_i2c_Tx[0] = registerAddr;
	for(index = 0; index < num; index++){
		array_PTN5110_i2c_Tx[1 + index] = *(data + index);
	}

	Lpi2c_Ip_MasterSetSlaveAddr(instance, slave, 0);
	Lpi2c_Ip_MasterSendDataBlocking(instance, array_PTN5110_i2c_Tx, num + 1, 1, TIMEOUT_PTN5110);
}

void PD_I2cReadBlocking(uint8_t instance,
                                uint16_t slave,
                                uint8_t registerAddr,
                                uint8_t *data,
                                uint8_t num) {
	array_PTN5110_i2c_Tx[0] = registerAddr;

	Lpi2c_Ip_MasterSetSlaveAddr(instance, slave, 0);
	Lpi2c_Ip_MasterSendDataBlocking(instance, array_PTN5110_i2c_Tx, 1, 1, TIMEOUT_PTN5110);

	Lpi2c_Ip_MasterReceiveDataBlocking(instance, data, num, 1, TIMEOUT_PTN5110);
}

#endif
