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

#ifndef LPUART_H_
#define LPUART_H_
/******************************************************************************
 * Includes
******************************************************************************/
#include "common.h"
#include "PlatformTypes.h"


#define UART_1_STOP_BIT	0
#define UART_2_STOP_BIT	1

#define LPUART_BAUD_RXEDGIE_MASK                 (0x4000U)
#define LPUART_BAUD_LBKDIE_MASK                  (0x8000U)

/*Interrupt mask*/
#define UART_LB_INT_MSK		0					/*LIN Break Detect Interrupt Flag*/
#define UART_REDGE_INT_MSK	1					/*RXD Pin Active Edge Interrupt Flag*/
#define UART_IDLE_INT_MSK	(0x100000U)			/*IDLE Line FLag*/
#define UART_OVR_INT_MSK	(0x8000000U)		/*Receiver Overrun Flag*/
#define UART_NOISE_INT_MSK  (0x4000000U)		/*Noise Flag*/
#define UART_FRM_INT_MSK	(0x2000000U)		/*Framing Error*/
#define UART_PARE_INT_MSK	(0x1000000U)		/*Parity Error Flag*/
#define UART_TX_INT_MSK		(0x400000U)			/*Transmit Complete Flag*/
#define UART_MA1_INT_MSK	(0x8000U)			/*Match1 Flag*/
#define UART_MA2_INT_MSK	(0x4000U)			/*Match2 Flag*/

/*! @brief Error codes for the UART driver. */
enum
{
    kStatus_UART_TxBusy              = MAKE_STATUS(kStatusGroup_UART, 0), /*!< Transmitter is busy. */
    kStatus_UART_RxBusy              = MAKE_STATUS(kStatusGroup_UART, 1), /*!< Receiver is busy. */
    kStatus_UART_TxIdle              = MAKE_STATUS(kStatusGroup_UART, 2), /*!< UART transmitter is idle. */
    kStatus_UART_RxIdle              = MAKE_STATUS(kStatusGroup_UART, 3), /*!< UART receiver is idle. */
    kStatus_UART_TxWatermarkTooLarge = MAKE_STATUS(kStatusGroup_UART, 4), /*!< TX FIFO watermark too large  */
    kStatus_UART_RxWatermarkTooLarge = MAKE_STATUS(kStatusGroup_UART, 5), /*!< RX FIFO watermark too large  */
    kStatus_UART_FlagCannotClearManually =
        MAKE_STATUS(kStatusGroup_UART, 6),                                 /*!< UART flag can't be manually cleared. */
    kStatus_UART_Error               = MAKE_STATUS(kStatusGroup_UART, 7),  /*!< Error happens on UART. */
    kStatus_UART_RxRingBufferOverrun = MAKE_STATUS(kStatusGroup_UART, 8),  /*!< UART RX software ring buffer overrun. */
    kStatus_UART_RxHardwareOverrun   = MAKE_STATUS(kStatusGroup_UART, 9),  /*!< UART RX receiver overrun. */
    kStatus_UART_NoiseError          = MAKE_STATUS(kStatusGroup_UART, 10), /*!< UART noise error. */
    kStatus_UART_FramingError        = MAKE_STATUS(kStatusGroup_UART, 11), /*!< UART framing error. */
    kStatus_UART_ParityError         = MAKE_STATUS(kStatusGroup_UART, 12), /*!< UART parity error. */
    kStatus_UART_BaudrateNotSupport =
        MAKE_STATUS(kStatusGroup_UART, 13), /*!< Baudrate is not support in current clock source */
    kStatus_UART_IdleLineDetected = MAKE_STATUS(kStatusGroup_UART, 14), /*!< UART IDLE line detected. */
    kStatus_UART_Timeout          = MAKE_STATUS(kStatusGroup_UART, 15), /*!< UART times out. */
};

/*Structure for callback function for interrupt*/
typedef struct uart_cb_type
{
	uint8_t instance; 	/*Instance which caused the interruption*/
	uint32_t status;	/*Interrupt flags causing the interrupt*/
} uart_cb_type_t;

/*Typedef for callback function pointer*/
typedef void (* uart_callback)(uart_cb_type_t * type);

/*Structure for pin configuration*/
//typedef struct uart_pin_cfg
//{
//	uint8_t uart_n; 	/*UART instance for pin configuration*/
//	uint16_t tx_gpio; 	/*GPIO number for TX*/
//	uint16_t tx_sss;	/*SIUL selector for TX pin*/
//	uint16_t rx_gpio;	/*GPIO number for RX*/
//	uint16_t rx_sss;	/*SIUL selector for RX pin*/
//} uart_pin_cfg_t;

typedef enum _uart_instance
{
	kLpuart0	= 0,
	kLpuart1	= 1,
	kLpuart2	= 2,
	kLpuart3	= 3,
	kLpuart4	= 4,
	kLpuart5	= 5,
	kLpuart6	= 6,
	kLpuart7	= 7,
	kLpuart8	= 8,
	kLpuart9	= 9,
	kLpuart10	= 10,
	kLpuart11	= 11,
	kLpuart12	= 12,
	kLpuart13	= 13,
	kLpuart14	= 14,
	kLpuart15	= 15
}uart_instance_t;

/*Parity type for UART configuration*/
typedef enum uart_parity
{
	NO_PARITY = 0, 	/*No parity check in frame*/
	RESERVED,	   	/*RESERVED*/
	EVEN_PARITY,	/*Parity check enabled. Parity EVEN*/
	ODD_PARITY		/*Parity check enabled, Parity ODD*/
} uart_parity_e;

typedef enum uart_tx_status
{
	TX_STAT_BUSY = 0,
	TX_STAT_COMPLETE
}uart_tx_status_t;

typedef enum uart_rx_status
{
	RX_STAT_NO_RECEPTION = 0,
	RX_STAT_RECEPTION_COMPLETE
}uart_rx_status_t;

/*UART configuration structure*/
typedef struct uart_cfg
{
	//uart_pin_cfg_t * pin_cfg;	/*GPIO configuration structure pointer*/
	uint32_t clk_freq;			/*Clock frequency reference for baudrate calculation*/
	uint32_t baudrate;			/*Desired baudrate*/
	uint8_t	stop_bits		:1; /*Number of stop bits. 0: 1 stop bit. 1: 2 stop bits*/
	uart_parity_e parity	:2; /*Parity check. one of @ref uart_parity_e */
	uint8_t d_width			:4;	/*Data width (7-10 bits). If set other data width will be set to 8*/
} uart_cfg_t;

extern void NVIC_SetPriority(uint8 IRQn, uint8 priority);
extern void NVIC_EnableIRQ(uint8 IRQn);
uart_tx_status_t uart_get_tx_status(uart_instance_t inst);
uart_rx_status_t uart_get_rx_status(uart_instance_t inst);
void uart_send_byte(uart_instance_t inst, uint8_t byte);
status_t uart_get_byte(uart_instance_t inst, uint8_t * byte);
void uart_send_byte_blocking(uart_instance_t inst, uint8_t byte);
status_t uart_get_byte_blocking(uart_instance_t inst, uint8_t * byte);
status_t uart_put_string_blocking(uart_instance_t inst, char * str);
status_t uart_put_data_blocking(uart_instance_t inst, uint8_t * buff, uint16_t size);
status_t uart_read_string_blocking(uart_instance_t inst, char * str, uint16_t size);
status_t uart_read_data_blocking(uart_instance_t inst, uint8_t * buff, uint16_t size);
status_t uart_init(uart_instance_t inst, uart_cfg_t *cfg);
status_t uart_enable_interrupt(uart_instance_t inst, uint32_t int_msk, uart_callback cb);


#endif /* LPUART_H_ */
