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

/******************************************************************************
 * Includes
 ******************************************************************************/
#include "mc_me.h"
#include "lpuart.h"
#include "S32K344_LPUART.h"

#define UART_PROCESS_TIMEOUT	100000

static volatile LPUART_Type * const instance_array[] = IP_LPUART_BASE_PTRS;

static const mc_me_clock_ip_name_t uart_clk_en_array[] = {kMCMEclock_Lpuart0, kMCMEclock_Lpuart1, kMCMEclock_Lpuart2,	\
														kMCMEclock_Lpuart3, kMCMEclock_Lpuart4, kMCMEclock_Lpuart5,		\
														kMCMEclock_Lpuart6, kMCMEclock_Lpuart7, kMCMEclock_Lpuart8,		\
														kMCMEclock_Lpuart9, kMCMEclock_Lpuart10, kMCMEclock_Lpuart11,	\
														kMCMEclock_Lpuart12, kMCMEclock_Lpuart13, kMCMEclock_Lpuart14,	\
														kMCMEclock_Lpuart15};

const IRQn_Type uart_irq_array[] = {LPUART0_IRQn, LPUART1_IRQn, LPUART2_IRQn, LPUART3_IRQn, LPUART4_IRQn,		\
									LPUART5_IRQn, LPUART6_IRQn, LPUART7_IRQn, LPUART8_IRQn, LPUART9_IRQn,		\
									LPUART10_IRQn, LPUART11_IRQn, LPUART12_IRQn, LPUART13_IRQn, LPUART14_IRQn, LPUART15_IRQn};

static uart_callback uart_cb[LPUART_INSTANCE_COUNT];

#define UART_INSTANCE_IS_VALID(x) (x < LPUART_INSTANCE_COUNT)

void LPUART_generalHandler(void)
{
	uint8_t i;
	uart_cb_type_t cb_params;
	for(i = 0; i < LPUART_INSTANCE_COUNT; i++)
	{
		if(instance_array[i]->STAT & 0XC01FC000)
		{
			cb_params.status = instance_array[i]->STAT;
			instance_array[i]->STAT |= cb_params.status;
			cb_params.instance = i;
			if(uart_cb[i])
			{
				uart_cb[i](&cb_params);
			}
		}
	}
}

static void uart_calc_div(uint32_t src_freq, uint32_t baudrate, uint8_t *osr_ptr, uint16_t * sbr_ptr)
{
	/*Auxiliar variables to calculate the dividers*/
	uint16_t  osr_min = 0;
	uint16_t osr_max = 0;
	uint16_t sbr = 0;
	uint16_t osr = 0;
	uint16_t osr_r = 0;
	uint16_t sbr_r = 0;
	uint32_t tmp, max_tmp_f = 0;
	osr_min = 8;
	osr_max = 32;

	/* Approximates the SD clock frequency select (SDCLKFS) to the target frequency by doing
	 * iterations on value*/
	for(osr = osr_min; osr <= osr_max; osr++)
	{
		/* Approximates the SD clock divisor (DVS) to the target frequency by doing
		 * iterations on value*/
		for (sbr = 1; sbr <= 8191; sbr++)
		{
			/* Calculates the output frequency in each iteration*/
			tmp = src_freq / (osr * sbr);

			/* Compares the calculated output frequency in each iteration
			 * vs the target frequency*/
			if(tmp <= baudrate)
			{
				/* Stores the values if calculated frequency is over the
				 * last iteration*/
				if(max_tmp_f <= tmp)
				{
					max_tmp_f = tmp;
					osr_r = osr - 1;
					sbr_r = sbr;
				}/*End if(max_tmp_f <= tmp)*/
			}/*End (tmp <= baudrate))*/
		}/*End for (sbr = 1; sbr <= 8191; sbr++)*/
	} /*End for(osr = osr_min; osr <= osr_max; osr++)*/

	*osr_ptr = osr_r;
	*sbr_ptr = sbr_r;
}

uart_tx_status_t uart_get_tx_status(uart_instance_t inst)
{
//	return (uart_tx_status_t)instance_array[inst]->STAT.B.TC;
	return (uart_tx_status_t)((instance_array[inst]->STAT & LPUART_STAT_TC_MASK) >> LPUART_STAT_TC_SHIFT);
}

uart_rx_status_t uart_get_rx_status(uart_instance_t inst)
{
//	return (uart_rx_status_t)instance_array[inst]->STAT.B.RDRF;
	return (uart_rx_status_t)((instance_array[inst]->STAT & LPUART_STAT_RDRF_MASK) >> LPUART_STAT_RDRF_SHIFT);
}

void uart_send_byte(uart_instance_t inst, uint8_t byte)
{
//	instance_array[inst]->DATA.R = byte;
	instance_array[inst]->DATA = byte;
}

status_t uart_get_byte(uart_instance_t inst, uint8_t * byte)
{
//	if(!(instance_array[inst]->STAT.B.RDRF))
//	{
//		return DRIVER_NOT_AVAILABLE;
//	}
//	*byte = (uint8_t)instance_array[inst]->DATA.R;
	if(!((instance_array[inst]->STAT & LPUART_STAT_RDRF_MASK) >> LPUART_STAT_RDRF_SHIFT))
	{
		return kStatus_UART_RxIdle;
	}
	*byte = (uint8_t)instance_array[inst]->DATA;
	return kStatus_Success;
}

void uart_send_byte_blocking(uart_instance_t inst, uint8_t byte)
{
	instance_array[inst]->DATA = byte;
	while(!((instance_array[inst]->STAT & LPUART_STAT_TC_MASK) >> LPUART_STAT_TC_SHIFT));
}

status_t uart_get_byte_blocking(uart_instance_t inst, uint8_t * byte)
{
	uint32_t timeout = UART_PROCESS_TIMEOUT;
	while((!((instance_array[inst]->STAT & LPUART_STAT_RDRF_MASK) >> LPUART_STAT_RDRF_SHIFT)) && (--timeout));
	if(!timeout)
	{
		return kStatus_UART_Timeout;
	}
	*byte = (uint8_t)instance_array[inst]->DATA;
	return kStatus_Success;
}

//void uart_get_dat(uart_instance_t inst, int * byte, uint16_t bit_msk)
//{
//	uint32_t timeout = UART_PROCESS_TIMEOUT;
//	uint8_t test = 0;
//	volatile struct LPUART_tag * module;
//
//	if(!UART_INSTANCE_IS_VALID(inst))
//		return DRIVER_MODULE_NOT_AVAILABLE;
//	module = instance_array[inst];
//	//while(((module->STAT & LPUART_STAT_OR_MASK) == 0) && (--timeout != 0) && ((module->CTRL & LPUART_CTRL_ORIE_MASK) == 0));
//	while((module->FIFO.B.RXEMPT) && (--timeout != 0) && (!(module->STAT.B.OR)));
//	//instance_array[module]->STAT.B.OR = SET;
//	if(timeout == 0)
//	{
//		return -1;
//	}
//	else
//	{
//		test = module->DATA.R & bit_msk;
//		*byte = test;
//		return 0;
//	}
//}

status_t uart_put_string_blocking(uart_instance_t inst, char * str)
{
	if(!str)
	{
		return kStatus_InvalidArgument;
	}

	while(TX_STAT_BUSY == uart_get_tx_status(inst));

	do
	{
		uart_send_byte_blocking(inst,(uint8_t)(*str));
	}while(*str++);

	return kStatus_Success;
}

status_t uart_put_data_blocking(uart_instance_t inst, uint8_t * buff, uint16_t size)
{
	uint16_t i;

	if(!buff)
	{
		return kStatus_InvalidArgument;
	}

	while(TX_STAT_BUSY == uart_get_tx_status(inst));

	for(i = 0; i < size; i++)
	{
		uart_send_byte_blocking(inst,buff[i]);
	}

	return kStatus_Success;
}



status_t uart_read_string_blocking(uart_instance_t inst, char * str, uint16_t size)
{
	char byte;
	uint16_t i = 0;

	do
	{
		if(kStatus_UART_Timeout == uart_get_byte_blocking(inst, (uint8_t*)&byte))
		{
			return kStatus_UART_Timeout;
		}
		str[i] = byte;
		i++;
	}while((byte) && (i<size));

	return kStatus_Success;
}

status_t uart_read_data_blocking(uart_instance_t inst, uint8_t * buff, uint16_t size)
{
	uint16_t i = 0;
	for(i = 0; i < size; i++)
	{
		if(kStatus_UART_Timeout == uart_get_byte_blocking(inst,buff + i))
		{
			return kStatus_UART_Timeout;
		}
	}
	return kStatus_Success;
}

status_t uart_init(uart_instance_t inst, uart_cfg_t *cfg)
{
	uint8_t osr;
	uint16_t sbr;
	volatile LPUART_Type * module;

	if(!UART_INSTANCE_IS_VALID(inst))
		return kStatus_ModuleNotAvailable;

	module = instance_array[inst];
	mcme_clock_enb(uart_clk_en_array[inst]);

	/* Poll for valid clock gating */
	while(!(mcme_poll_clk_gate_status(uart_clk_en_array[inst])));

	//uart_init_pins(cfg->pin_cfg);
	//osr = module->BAUD.B.OSR;
	//sbr = cfg->clk_freq / ((osr + 1) * cfg->baudrate);
	uart_calc_div(cfg->clk_freq,  cfg->baudrate, &osr, &sbr);

//	module->FIFO.B.RXFE 		= SET;
//	module->FIFO.B.RXFIFOSIZE 	= (4U);	// 32 words
//	module->BAUD.B.OSR 			= osr;
//	module->BAUD.B.SBR 			= sbr;
//	module->BAUD.B.SBNS 		= cfg->stop_bits;
//
//	module->BAUD.B.M10 	= ((cfg->d_width == 10) ? 1 : 0);
//	module->CTRL.B.M7 	= ((cfg->d_width == 7) ? 1 : 0);
//	module->CTRL.B.M 	= ((cfg->d_width == 9) ? 1 : 0);
//
//	module->CTRL.R |= (uint32_t) cfg->parity;
//
//	module->CTRL.B.TE = SET;
//	module->CTRL.B.RE = SET;
	uint32_t baud = module->BAUD;
	baud &= ~LPUART_BAUD_SBR_MASK;
	baud |= LPUART_BAUD_SBR(sbr) | LPUART_BAUD_SBNS(cfg->stop_bits);
	baud &= ~LPUART_BAUD_OSR_MASK;
	baud |= LPUART_BAUD_OSR(osr);
	baud |= LPUART_BAUD_M10((cfg->d_width == 10) ? 1 : 0);
	module->BAUD = baud;
	module->FIFO |= LPUART_FIFO_RXFE_MASK;

	module->CTRL |= LPUART_CTRL_M7((cfg->d_width == 7) ? 1 : 0);
	module->CTRL |= LPUART_CTRL_M((cfg->d_width == 9) ? 1 : 0);
	module->CTRL |= (uint32_t) cfg->parity;
	module->CTRL |= LPUART_CTRL_TE_MASK | LPUART_CTRL_RE_MASK;

	return kStatus_Success;
}

status_t uart_enable_interrupt(uart_instance_t inst, uint32_t int_msk, uart_callback cb)
{
	volatile LPUART_Type * module;
	if(!UART_INSTANCE_IS_VALID(inst))
		return kStatus_ModuleNotAvailable;
	module = instance_array[inst];

	NVIC_SetPriority(uart_irq_array[inst], 2);
	NVIC_EnableIRQ(uart_irq_array[inst]);
	uart_cb[inst] = cb;

	if(int_msk == UART_LB_INT_MSK || int_msk == UART_REDGE_INT_MSK)
	{
		module->BAUD |= (int_msk)?LPUART_BAUD_RXEDGIE_MASK:LPUART_BAUD_LBKDIE_MASK;
	}
	else
	{
		module->CTRL |= int_msk;
	}
	return kStatus_Success;
}

