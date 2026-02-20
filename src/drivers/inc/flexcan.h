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

#ifndef DRIVERS_FLEXCAN_H_
#define DRIVERS_FLEXCAN_H_

#include "stdint.h"
#include "S32K344.h"


typedef struct{
	struct {
	  __IO uint32_t TIMESTAMP  : 16;
	  __IO uint32_t DLC        : 4;
	  __IO uint32_t RTR        : 1;
	  __IO uint32_t IDE        : 1;
	  __IO uint32_t SRR        : 1;
			uint32_t           : 1;
	  __IO uint32_t CODE       : 4;
			uint32_t           : 1;
	  __IO uint32_t ESI        : 1;
	  __IO uint32_t BRS        : 1;
	  __IO uint32_t EDL        : 1;
	  __IO uint32_t EXT_ID     : 29;
	  __IO uint32_t PRIO       : 3;
	  __IO uint32_t PAYLOAD[16];
	} FD_MessageBuffer[7];
} CAN_MB_FD_t;

typedef struct{
	struct {
	  __IO uint32_t TIMESTAMP  : 16;
	  __IO uint32_t DLC        : 4;
	  __IO uint32_t RTR        : 1;
	  __IO uint32_t IDE        : 1;
	  __IO uint32_t SRR        : 1;
			uint32_t           : 1;
	  __IO uint32_t CODE       : 4;
			uint32_t           : 1;
	  __IO uint32_t ESI        : 1;
	  __IO uint32_t BRS        : 1;
	  __IO uint32_t EDL        : 1;
	  __IO uint32_t EXT_ID     : 29;
	  __IO uint32_t PRIO       : 3;
	  __IO uint32_t PAYLOAD[2];
	} Classic_MessageBuffer[32];
} CAN_MB_Classic_t;

typedef struct flexcan_frame{
	uint32_t ID;
	uint32_t HIGH_RES_TIMESTAMP;
    volatile uint32_t PAYLOAD[16];
} flexcan_frame_t;

typedef enum flexcan_mode
{
	CAN_CLASSIC,
	CAN_FD
}flexcan_mode_e;

typedef enum err_poll_e
{
	TIMEOUT,
	NO_ERROR,
} err_poll_e;

typedef enum flexcan_bitrate_fd{
	CAN_FD_1MHz,
	CAN_FD_2MHz,
	CAN_FD_4MHz,
	CAN_FD_NONE
} flexcan_bitrate_fd_t;

typedef enum flexcan_config_pins{
	RX_MSCR,
	RX_IMCR,
	RX_IMCR_SSS,
	TX_MSCR,
	TX_MSCR_SSS
} flexcan_config_pins_t;

typedef struct flexcan_status{
	uint16_t status;
	uint16_t active_rx;
	flexcan_mode_e mode[FLEXCAN_INSTANCE_COUNT];
} flexcan_status_t;

typedef struct flexcan_bit_timming_classic{
	__IO uint32_t EPRESDIV  : 10;
	__IO uint32_t ERJW  	: 5;
	__IO uint32_t EPROPSEG  : 6;
	__IO uint32_t EPSEG1	: 5;
	__IO uint32_t EPSEG2	: 5;
} flexcan_bit_timming_classic_t;

typedef struct flexcan_bit_timming_fd{
	__IO uint32_t FPRESDIV  : 10;
	__IO uint32_t FRJW  	: 3;
	__IO uint32_t FPROPSEG  : 5;
	__IO uint32_t FPSEG1	: 3;
	__IO uint32_t FPSEG2	: 3;
} flexcan_bit_timming_fd_t;

/*Structure for pin configuration*/
typedef struct can_pin_cfg
{
	uint8_t can_n; 	/*UART instance for pin configuration*/
	uint16_t tx_gpio; 	/*GPIO number for TX*/
	uint16_t tx_sss;	/*SIUL selector for TX pin*/
	uint16_t rx_gpio;	/*GPIO number for RX*/
	uint16_t rx_sss;	/*SIUL selector for RX pin*/
} can_pin_cfg_t;

uint16_t flexcan_status_instance(uint8_t instance);
uint16_t flexcan_rx_status_instance(uint8_t instance);
flexcan_mode_e flexcan_mode_instance(uint8_t instance);

void flexcan_init(uint8_t instance, flexcan_mode_e mode, flexcan_bitrate_fd_t bit_rate_fd, uint8_t enable_loopback);
void flexcan_install_rx_id(uint8_t instance, uint32_t id);
err_poll_e flexcan_read_frame(uint8_t instance, flexcan_frame_t * frame, flexcan_mode_e *mode_flexcan);
void flexcan_send_frame(uint8_t instance, flexcan_frame_t * frame);

#endif /* DRIVERS_FLEXCAN_H_ */
