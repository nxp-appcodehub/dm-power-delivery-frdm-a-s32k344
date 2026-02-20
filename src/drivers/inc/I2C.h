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

#ifndef DRIVERS_I2C_H_
#define DRIVERS_I2C_H_

#include "S32K344.h"
#include "PlatformTypes.h"

#include "sys.h"

#define I2C_TARGET_INT_FLAG_SMABUS 			LPI2C_SIER_SARIE_MASK
#define I2C_TARGET_INT_FLAG_GEN_CALL 		LPI2C_SIER_GCIE_MASK
#define I2C_TARGET_INT_FLAG_MATCH_ADD_1 	LPI2C_SIER_AMIE_MASK
#define I2C_TARGET_INT_FLAG_MATCH_ADD_0 	LPI2C_SIER_AM0IE_MASK
#define I2C_TARGET_INT_FLAG_FIFO_ERR 		LPI2C_SIER_FEIE_MASK
#define I2C_TARGET_INT_FLAG_BIT_ERR 		LPI2C_SIER_BEIE_MASK
#define I2C_TARGET_INT_FLAG_STOP_DET 		LPI2C_SIER_SDIE_MASK
#define I2C_TARGET_INT_FLAG_START_REPEATED	LPI2C_SIER_RSIE_MASK
#define I2C_TARGET_INT_FLAG_ACK_TRAN 		LPI2C_SIER_TAIE_MASK
#define I2C_TARGET_INT_FLAG_ADD_VALID 		LPI2C_SIER_AVIE_MASK
#define I2C_TARGET_INT_FLAG_RCV_DAT 		LPI2C_SIER_RDIE_MASK
#define I2C_TARGET_INT_FLAG_TRAN_DAT 		LPI2C_SIER_TDIE_MASK

/* Constraints used for baud rate computation */
#define CLKHI_MIN_VALUE 1U
#define CLKLO_MIN_VALUE 3U
#define CLKHI_MAX_VALUE ((1U << LPI2C_MCCR0_CLKHI_WIDTH) - 1U)
#define CLKLO_MAX_VALUE CLKHI_MAX_VALUE
#define DATAVD_MIN_VALUE 1U
#define SETHOLD_MIN_VALUE 2U

#define LIMIT_FIFO_RECEIVE		(4U)

#define TIMEOUT_I2C			(0xFFFF)

typedef enum
{
    LPI2C_STATUS_SUCCESS,
	LPI2C_STATUS_TIMEOUT
}Lpi2c_StatusType;

typedef enum
{
	I2C_CONTROLLER_MODE,
	I2C_TARGET_MODE
} i2c_mode_e;

typedef enum
{
	I2C_CLK_DIV_1 = 0,
	I2C_CLK_DIV_2,
	I2C_CLK_DIV_4,
	I2C_CLK_DIV_8,
	I2C_CLK_DIV_16,
	I2C_CLK_DIV_32,
	I2C_CLK_DIV_64,
	I2C_CLK_DIV_128,
} i2c_clk_div;

typedef struct
{
	i2c_clk_div Prescaler;
	uint32_t ClkHI;
	uint32_t ClkLO;
	uint32_t SetHold;
	uint32_t DataValid;
} i2c_Ip_BaudRateType;

typedef struct
{
	uint32_t in_clk;
	uint32_t baudrate;
	i2c_mode_e mode;
	i2c_clk_div div;
	uint8_t slave_add;
} i2c_cfg_t;

extern void NVIC_SetPriority(uint8 IRQn, uint8 priority);
extern void NVIC_EnableIRQ(uint8 IRQn);

uint8_t i2c_status_instance(uint8_t instance);
void i2c_instance_init(uint8_t instance, uint32_t baudrate);
int8_t i2c_init(uint8_t instance, i2c_cfg_t *cfg);

int8_t i2c_send_data(uint8_t instance, uint8_t add, uint8_t size, uint8_t * data);

uint8_t i2c_read_data(uint8_t instance);

void i2c_enable_interrupt(uint8_t instance, i2c_mode_e mode, uint32_t int_flag);

uint8_t i2c_receive (uint8_t instance);

void I2C0_Init(uint32_t baudrate);
void I2C1_Init(uint32_t baudrate);

Lpi2c_StatusType i2cWriteBlocking(uint8_t instance,
                                uint16_t slave,
                                uint8_t registerAddr,
                                uint8_t *data,
                                uint8_t num);

Lpi2c_StatusType i2cReadBlocking(uint8_t instance,
        						uint16_t slave,
								uint8_t registerAddr,
								uint8_t *data,
								uint8_t num);

#endif /* DRIVERS_I2C_H_ */
