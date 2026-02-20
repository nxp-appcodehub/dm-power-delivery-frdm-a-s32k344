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

#include "nx20p3483.h"

uint8_t array_ADD_NX20P3483_Tx[2];
uint8_t array_ADD_NX20P3483_Rx[2];

info_NX20P3483_t config_NX20P3483;

static void nx20p3483_I2cWrite(uint8_t reg, uint8_t data){
#if (USE_BAREMETAL_I2C == 0U)
	Lpi2c_Ip_MasterSetSlaveAddr(config_NX20P3483.instance_i2c, config_NX20P3483.address, 0);

	array_ADD_NX20P3483_Tx[0] = reg;
	array_ADD_NX20P3483_Tx[1] = data;



	Lpi2c_Ip_MasterSendDataBlocking(config_NX20P3483.instance_i2c, array_ADD_NX20P3483_Tx, 2, 1, TIMEOUT_nx20p3483);
#else
	array_ADD_NX20P3483_Tx[0] = data;
	i2cWriteBlocking(config_NX20P3483.instance_i2c, config_NX20P3483.address, reg, array_ADD_NX20P3483_Tx, 1U);
#endif
}

static uint8_t nx20p3483_I2cRead(uint8_t reg){
#if (USE_BAREMETAL_I2C == 0U)
	Lpi2c_Ip_MasterSetSlaveAddr(config_NX20P3483.instance_i2c, config_NX20P3483.address, 0);

	array_ADD_NX20P3483_Tx[0] = reg;
	Lpi2c_Ip_MasterSendDataBlocking(config_NX20P3483.instance_i2c, array_ADD_NX20P3483_Tx, 1, 1, TIMEOUT_nx20p3483);

	Lpi2c_Ip_MasterReceiveDataBlocking(config_NX20P3483.instance_i2c, array_ADD_NX20P3483_Rx, 1, 1, TIMEOUT_nx20p3483);
#else
	i2cReadBlocking(config_NX20P3483.instance_i2c, config_NX20P3483.address, reg, array_ADD_NX20P3483_Rx, 1);
#endif

	return array_ADD_NX20P3483_Rx[0];
}

void nx20p3483_init(info_NX20P3483_t info){
	config_NX20P3483 = info;
	uint8_t data_byte = 0;

	/* Device ID NX20 */
	/* We expected 0x0A */
	data_byte = nx20p3483_I2cRead(0x00);

	/* Device control Register */
	nx20p3483_I2cWrite(0x0B, 0x04);

	/* Interrupt Mask Register */
	nx20p3483_I2cWrite(0x06, 0x00);
	nx20p3483_I2cWrite(0x07, 0x00);

}

void nx20p3483_Set5VSourceOCP(uint16_t current){
	uint8_t value_current_register = 0;
    /* Set OCP */
    if (current <= 400U) {
    	value_current_register = 0x00U;
    } else if (current >= 3400U) {
    	value_current_register = 0x00U;
    } else
    {
    	current = (current - 400U) / 200U;
    	value_current_register = (uint8_t) current;
    }

    nx20p3483_I2cWrite(0x0A, value_current_register);
}

void nx20p3483_SetSinkOVP(uint16_t voltage){
	uint8_t value_voltage_register = 0;
	uint8_t data_byte = 0;

    /* Set OVLO */
    if (voltage <= 6000U)
    	value_voltage_register = 0x00U;
    else if (voltage <= 6800U)
    	value_voltage_register = 0x01U;
    else if (voltage <= 10000U)
    	value_voltage_register = 0x02U;
    else if (voltage <= 11500U)
    	value_voltage_register = 0x03U;
    else if (voltage <= 14000U)
    	value_voltage_register = 0x04U;
    else if (voltage <= 17000U)
    	value_voltage_register = 0x05U;
    else
    	value_voltage_register = 0x06U;

    nx20p3483_I2cWrite(0x08, value_voltage_register);
    data_byte = nx20p3483_I2cRead(0x08);
}

void nx20p3483_Read_Interrupts(uint8_t* dst){
	*dst = nx20p3483_I2cRead(0x04);
	*(dst + 1) = nx20p3483_I2cRead(0x05);
}
