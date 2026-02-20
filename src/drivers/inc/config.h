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

#ifndef DRIVERS_CONFIG_H_
#define DRIVERS_CONFIG_H_

#include "rgb.h"
#include "buttons.h"
#include "pit.h"

#include "lpuart.h"
#include "ADC_Driver.h"
#include "lpspi.h"
#include "flexcan.h"

#include "fs26.h"
#include "ptn5110.h"
#include "nx20p3483.h"
#include "p3t1750dp.h"

#define ADD_PTN5110			(0x50)
#define ADD_NX20P3483		(0x71)
#define ADD_P3T1750DP		(0x48)
#define ADD_FXLS8961AF		(0x18)

#define ENABLE_TEST_PD				(0)
#define ENABLE_TEST_FS26			(1)
#define ENABLE_TEST_TMP				(1)
#define ENABLE_TEST_ACC				(1)
#define ENABLE_TEST_LIN				(1)
#define ENABLE_TEST_CAN				(1)
#define ENABLE_TEST_HRAM			(1)
#define ENABLE_TEST_ETH				(1)

/********************************************
 * MAIN APPLICATION							*
 ********************************************/

/* UART */
//TX	PTB10
//RX	PTB9
#define UART9_TX_MSCR	42
#define UART9_TX_SSS	5
#define UART9_RX_MSCR	41
#define UART9_RX_IMCR	708
#define UART9_RX_SSS	1

//TX	PTE4
//RX	PTE5
#define UART12_TX_MSCR	132
#define UART12_TX_SSS	5
#define UART12_RX_MSCR	133
#define UART12_RX_IMCR	711
#define UART12_RX_SSS	1

//TX	PTH4
//RX	PTH5
#define UART4_TX_MSCR	228
#define UART4_TX_SSS	1
#define UART4_RX_MSCR	229
#define UART4_RX_IMCR	703
#define UART4_RX_SSS	5

//TX	PTH6
//RX	PTH7
#define UART8_TX_MSCR	230
#define UART8_TX_SSS	1
#define UART8_RX_MSCR	231
#define UART8_RX_IMCR	707
#define UART8_RX_SSS	4

/* I2C */
#define I2C1_SDA_PIN		70	//PTC6
#define I2C1_SCL_PIN		71	//PTC7
#define I2C1_SDA_MSCR_SSS	1
#define I2C1_SCL_MSCR_SSS	3
#define I2C1_SDA_IMCR		(731 - 512)
#define I2C1_SCL_IMCR		(729 - 512)
#define I2C1_SDA_IMCR_SSS	2
#define I2C1_SCL_IMCR_SSS	1

typedef enum status
{
	TEST_PASSED,
	TEST_FAILED
} status_test_t;

#endif /* DRIVERS_CONFIG_H_ */
