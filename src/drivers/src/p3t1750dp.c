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

#include "p3t1750dp.h"

info_P3T1750DP_t config_P3T1750;

volatile uint8_t data_temp_sensor[2] = {0,0};
volatile uint16_t data_temp_sensor_16 = 0;

/*
 *	0x01	Configuration register: contains a single 8-bit data
 *			byte; to set the device operating condition
 *
 *	0x00	Temperature register: contains two 8-bit data bytes; to
 *			store the measured Temp data.
 *
 *	0x03	Overtemperature shutdown threshold register:
 *			contains two 8-bit data bytes; to store the
 *			overtemperature shutdown Tots limit
 *
 *	0x02	Hysteresis register: contains two 8-bit data bytes; to
 *			store the hysteresis Thys limit
 *
 */
void p3t1750dp_init(info_P3T1750DP_t info){
	config_P3T1750.instance_i2c = info.instance_i2c;
	config_P3T1750.address = info.address;

	i2cReadBlocking(config_P3T1750.instance_i2c,
			config_P3T1750.address,
	        0x03,
			(uint8_t*)data_temp_sensor,
	        2);

	uint16_t aux = (uint16_t) data_temp_sensor[0];
	data_temp_sensor_16 = (uint16_t) data_temp_sensor[1];

	data_temp_sensor_16 = (aux << 8) | data_temp_sensor_16;
}

int32_t p3t1750dp_read_temp(void){
	i2cReadBlocking(config_P3T1750.instance_i2c,
			config_P3T1750.address,
	        0x00,
			(uint8_t*)data_temp_sensor,
	        2);

	uint16_t aux = (uint16_t) data_temp_sensor[0];
	data_temp_sensor_16 = (uint16_t) data_temp_sensor[1];

	data_temp_sensor_16 = (aux << 8) | data_temp_sensor_16;

	int32_t temp_read = (int32_t)data_temp_sensor_16;

	temp_read = (temp_read * 100) >> 8;
	return temp_read;
}
