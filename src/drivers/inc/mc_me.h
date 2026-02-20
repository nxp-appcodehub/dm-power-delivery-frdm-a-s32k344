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

#ifndef MC_ME_H_
#define MC_ME_H_
/******************************************************************************
 * Includes
 ******************************************************************************/
#include "S32K344_MC_ME.h"

/*-----------MC_ME clock gate definitions-----------*/

#define CLK_GATE_PRTN_NUM_SHIFT 	16U
#define CLK_GATE_PRTN_NUM_MASK		0xFFFF0000U
#define CLK_GATE_REQ_SHIFT_SHIFT 	0U
#define CLK_GATE_REQ_SHIFT_MASK		0x0000FFFFU

#define CLK_GATE_DEFINE(prtn_num, req_shift)											\
		(((prtn_num) << CLK_GATE_PRTN_NUM_SHIFT) & CLK_GATE_PRTN_NUM_MASK)		|		\
		(((req_shift) << CLK_GATE_REQ_SHIFT_SHIFT) & CLK_GATE_REQ_SHIFT_MASK)

typedef enum _mc_me_clock_ip_name
{
	kMCMEclock_IpInvalid 	= 0,
	/* LPUART */
	kMCMEclock_Lpuart0 		= CLK_GATE_DEFINE(1U, 74U),
	kMCMEclock_Lpuart1 		= CLK_GATE_DEFINE(1U, 75U),
	kMCMEclock_Lpuart2 		= CLK_GATE_DEFINE(1U, 76U),
	kMCMEclock_Lpuart3 		= CLK_GATE_DEFINE(1U, 77U),
	kMCMEclock_Lpuart4 		= CLK_GATE_DEFINE(1U, 78U),
	kMCMEclock_Lpuart5 		= CLK_GATE_DEFINE(1U, 79U),
	kMCMEclock_Lpuart6 		= CLK_GATE_DEFINE(1U, 80U),
	kMCMEclock_Lpuart7 		= CLK_GATE_DEFINE(1U, 81U),
	kMCMEclock_Lpuart8 		= CLK_GATE_DEFINE(2U, 35U),
	kMCMEclock_Lpuart9 		= CLK_GATE_DEFINE(2U, 36U),
	kMCMEclock_Lpuart10 	= CLK_GATE_DEFINE(2U, 37U),
	kMCMEclock_Lpuart11 	= CLK_GATE_DEFINE(2U, 38U),
	kMCMEclock_Lpuart12 	= CLK_GATE_DEFINE(2U, 39U),
	kMCMEclock_Lpuart13 	= CLK_GATE_DEFINE(2U, 40U),
	kMCMEclock_Lpuart14 	= CLK_GATE_DEFINE(2U, 41U),
	kMCMEclock_Lpuart15 	= CLK_GATE_DEFINE(2U, 42U),

	/* LPI2C */
	kMCMEclock_Lpi2c0		= CLK_GATE_DEFINE(1U, 84U),
	kMCMEclock_Lpi2c1		= CLK_GATE_DEFINE(1U, 85U),

	/* LPSPI */
	kMCMEclock_Lpspi0		= CLK_GATE_DEFINE(1U, 86U),
	kMCMEclock_Lpspi1		= CLK_GATE_DEFINE(1U, 87U),
	kMCMEclock_Lpspi2		= CLK_GATE_DEFINE(1U, 88U),
	kMCMEclock_Lpspi3		= CLK_GATE_DEFINE(1U, 89U),
	/* PIT */
	kMCMEclock_Pit0			= CLK_GATE_DEFINE(0U, 44U),
	kMCMEclock_Pit1			= CLK_GATE_DEFINE(0U, 45U),

	/* FLEXCAN */
	kMCMEclock_FlexCAN0		= CLK_GATE_DEFINE(1U, 65U),
	kMCMEclock_FlexCAN1		= CLK_GATE_DEFINE(1U, 66U),
	kMCMEclock_FlexCAN2		= CLK_GATE_DEFINE(1U, 67U),
	kMCMEclock_FlexCAN3		= CLK_GATE_DEFINE(1U, 68U),
	kMCMEclock_FlexCAN4		= CLK_GATE_DEFINE(1U, 69U),
	kMCMEclock_FlexCAN5		= CLK_GATE_DEFINE(1U, 70U),

	/* EMIOS */
	kMCMEclock_Emios0		= CLK_GATE_DEFINE(0U, 34U),
	kMCMEclock_Emios1		= CLK_GATE_DEFINE(0U, 35U)

}mc_me_clock_ip_name_t;

#define CLK_GATE_ABSTRACT_PRTN_NUM(x)		(((x) & CLK_GATE_PRTN_NUM_MASK) >> CLK_GATE_PRTN_NUM_SHIFT)
#define CLK_GATE_ABSTRACT_REQ_SHIFT(x)		(((x) & CLK_GATE_REQ_SHIFT_MASK) >> CLK_GATE_REQ_SHIFT_SHIFT)

#define MCME_BASE 			IP_MC_ME_BASE

#define PRTN_PCONF_OFFSET	0U
#define PRTN_PUPD_OFFSET	4U
#define PRTN_STAT_OFFSET	8U

#define PCONF_PCE_SHIFT		0U
#define PUPD_PCUD_SHIFT		0U
#define STAT_PCS_SHIFT		0U

uint32_t mcme_poll_clk_gate_status(mc_me_clock_ip_name_t name);

void mcme_clock_enb(mc_me_clock_ip_name_t name);

void mcme_clock_dis(mc_me_clock_ip_name_t name);

#endif /* MC_ME_H_ */
