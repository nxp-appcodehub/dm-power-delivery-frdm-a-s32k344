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

#ifndef APP_INC_SYS_H_
#define APP_INC_SYS_H_

#include "clock.h"

#define SYS_FXOSC_FREQ 16000000

typedef enum
{
	SYS_CLK_CORE,
	SYS_CLK_AIPS_PLAT,
	SYS_CLK_HSE,
	SYS_CLK_AIPS_SLOW,
	SYS_CLK_DCM,
	SYS_CLK_LBIST,
	SYS_CLK_QSPI,
#ifdef S32K388
	SYS_CLK_CM7_CORE
#endif
}sys_clk_e;

typedef enum
{
#ifdef S32K388
	SYS_CLOCK_OPT_A_PLUS_PLUS,
#endif
	SYS_CLOCK_OPT_A_PLUS,
	SYS_CLOCK_OPT_A,
	SYS_CLOCK_OPT_B,
	SYS_CLOCK_OPT_C,
	SYS_CLOCK_OPT_D,
	SYS_CLOCK_OPT_E,
	SYS_CLOCK_OPT_F,
	SYS_CLOCK_OPT_E2
} sys_clk_opt_e;

typedef enum
{
	SYS_CLOCK_FIRC_DIV_2 = 1,
	SYS_CLOCK_FIRC_DIV_16 = 2
} sys_clk_firc_div;

typedef enum
{
#ifndef S32K388
	SYS_PMC_V15_BJT,
#endif
	SYS_PMC_V15_SMPS,
	SYS_PMC_V15_SBC
} sys_pmc_opt;

int8_t sys_cfg_clock_opt(sys_clk_opt_e opt);

int8_t sys_cfg_pmc(sys_pmc_opt opt);

uint32_t sys_get_clock(sys_clk_e sys_clk);

void sys_wake_core(uint8_t core, uint32_t boot_add);

void sys_firc_div(sys_clk_firc_div div);

#endif /* APP_INC_SYS_H_ */
