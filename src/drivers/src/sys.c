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

#include "sys.h"
//#include "pmc.h"
#include <string.h>
#include <stdio.h>


#define FXOSC_ERR 	0x01
#define PLL_ERR 	0x02
#define AUX_PLL_ERR 0x03

#define LOL_ERR		0x11
#define CORE_CLK_ERR	0x12
#define PWR_ERR		0x20


/*********************************************
 * Static Variables                          *
 *********************************************/

static uint32_t mux_0_clk = 48000000;

/* System clock dividers for Specific option.
 * The following structures consider Option
 * specific parameters for clock source in MUX1
 * according to RM*/

/* System clock dividers for Clock Opt A++
 * Clock Source: PLL_PHI0 = 320MHz */
static clock_sys_div_t sys_div_cfg_a_plus_plus = //5M
{
	1, /*CORE CLK 		= 160MHz*/
	3, /*AIPS_PLAT CLK 	= 80MHz*/
	7, /*AIPS_SLOW CLK 	= 40MHz*/
	1, /*HSE CLK 		= 160MHz*/
	7, /*DCM CLK 		= 40MHz*/
	7, /*LBIST CLK 		= 40MHz*/
	1, /*QSPI_MEM CLK 	= 160MHz*/
#ifdef MC_CGM_MUX_0_DC_7_DE_MASK
	0  /*CM7 CORE CLK 	= 320MHz*/
#endif
};

/* System clock dividers for Clock Opt A+
 * Clock Source: PLL_PHI0 = 240MHz */
static clock_sys_div_t sys_div_cfg_a_plus =//1.875M
{
	1, /*CORE CLK 		= 120MHz*/
	3, /*AIPS_PLAT CLK 	= 60MHz*/
	7, /*AIPS_SLOW CLK 	= 30MHz*/
	1, /*HSE CLK 		= 120MHz*/
	7, /*DCM CLK 		= 30MHz*/
	7, /*LBIST CLK 		= 30MHz*/
	1, /*QSPI_MEM CLK 	= 120MHz*/
#ifdef MC_CGM_MUX_0_DC_7_DE_MASK
	0  /*CM7 CORE CLK 	= 240MHz*/
#endif
};

/* System clock dividers for Clock Opt A
 * Clock Source: PLL_PHI0 = 320MHz */
static clock_sys_div_t sys_div_cfg_a = //2.5M
{
	1, /*CORE CLK 		= 160MHz*/
	3, /*AIPS_PLAT CLK 	= 80MHz*/
	7, /*AIPS_SLOW CLK 	= 40MHz*/
	1, /*HSE CLK 		= 160MHz*/
	7, /*DCM CLK 		= 40MHz*/
	7, /*LBIST CLK 		= 40MHz*/
	1, /*QSPI_MEM CLK 	= 160MHz*/
#ifdef MC_CGM_MUX_0_DC_7_DE_MASK
	1  /*CM7 CORE CLK 	= 160MHz*/
#endif
};

/* System clock dividers for Clock Opt B
 * Clock Source: PLL_PHI0 = 120MHz */
static clock_sys_div_t sys_div_cfg_b = //1.887M :)
{
	0, /*CORE CLK 		= 120MHz*/
	1, /*AIPS_PLAT CLK 	= 60MHz*/
	3, /*AIPS_SLOW CLK 	= 30MHz*/
	0, /*HSE CLK 		= 120MHz*/
	3, /*DCM CLK 		= 30MHz*/
	3, /*LBIST CLK 		= 30MHz*/
	0, /*QSPI_MEM CLK 	= 120MHz*/
#ifdef MC_CGM_MUX_0_DC_7_DE_MASK
	0  /*CM7 CORE CLK 	= 120MHz*/
#endif
};

/* System clock dividers for Clock Opt C
 * Clock Source: FIRC = 24MHz */
static clock_sys_div_t sys_div_cfg_c = //
{
	0, /*CORE CLK 		= 24MHz*/
	0, /*AIPS_PLAT CLK 	= 24MHz*/
	1, /*AIPS_SLOW CLK 	= 12MHz*/
	0, /*HSE CLK 		= 24MHz*/
	0, /*DCM CLK 		= 24MHz*/
	1, /*LBIST CLK 		= 12MHz*/
	0,  /*QSPI_MEM CLK 	= 24MHz*/
#ifdef MC_CGM_MUX_0_DC_7_DE_MASK
	0  /*CM7 CORE CLK 	= 24MHz*/
#endif
};

/* System clock dividers for Clock Opt D
 * Clock Source: FIRC = 48MHz */
static clock_sys_div_t sys_div_cfg_d =
{
	0, /*CORE CLK 		= 48MHz*/
	0, /*AIPS_PLAT CLK 	= 48MHz*/
	1, /*AIPS_SLOW CLK 	= 24MHz*/
	0, /*HSE CLK 		= 48MHz*/
	0, /*DCM CLK 		= 48MHz*/
	0, /*LBIST CLK 		= 40MHz  Not used in this configuration*/
	0,  /*QSPI_MEM CLK 	= 160MHz Not used in this configuration*/
#ifdef MC_CGM_MUX_0_DC_7_DE_MASK
	0  /*CM7 CORE CLK 	= 48MHz*/
#endif
};

/* System clock dividers for Clock Opt E
 * Clock Source: FIRC = 3MHz */
static clock_sys_div_t sys_div_cfg_e =
{
	0, /*CORE CLK 		= 3MHz*/
	0, /*AIPS_PLAT CLK 	= 3MHz*/
	1, /*AIPS_SLOW CLK 	= 1.5MHz*/
	0, /*HSE CLK 		= 3MHz*/
	0, /*DCM CLK 		= 3MHz*/
	0, /*LBIST CLK 		= 3MHz*/
	0,  /*QSPI_MEM CLK 	= 3MHz*/
#ifdef MC_CGM_MUX_0_DC_7_DE_MASK
	0  /*CM7 CORE CLK 	= 3MHz*/
#endif
};

/* System clock dividers for Clock Opt E2
 * Clock Source: FIRC = 750kHz */
static clock_sys_div_t sys_div_cfg_e2 =
{
	3, /*CORE CLK 		= 750kHz*/
	3, /*AIPS_PLAT CLK 	= 750kHz*/
	7, /*AIPS_SLOW CLK 	= 375kHz*/
	3, /*HSE CLK 		= 750kHz*/
	3, /*DCM CLK 		= 750kHz*/
	3, /*LBIST CLK 		= 750kHz*/
	3,  /*QSPI_MEM CLK 	= 750kHz*/
#ifdef MC_CGM_MUX_0_DC_7_DE_MASK
	3  /*CM7 CORE CLK 	= 750kHz*/
#endif
};

/* System clock dividers for Clock Opt F
 * Clock Source: PLL_PHI0 = 160MHz */
/*TODO: Implement. Not required in EMC Test Plan*/
static clock_sys_div_t sys_div_cfg_f =
{
	0, /*CORE CLK 		= 750kHz*/
	1, /*AIPS_PLAT CLK 	= 750kHz*/
	3, /*AIPS_SLOW CLK 	= 375kHz*/
	0, /*HSE CLK 		= 750kHz*/
	3, /*DCM CLK 		= 750kHz*/
	3, /*LBIST CLK 		= 750kHz*/
	0,  /*QSPI_MEM CLK 	= 750kHz*/
#ifdef MC_CGM_MUX_0_DC_7_DE_MASK
	0  /*CM7 CORE CLK 	= 750kHz*/
#endif
};

/* Current system clock dividers*/
static clock_sys_div_t * sys_div_cfg_current = &sys_div_cfg_d;

/* PLL General configuration Spread Spectrum disabled*/
static clock_pll_cfg_t sys_pll_config =
{
		SYS_FXOSC_FREQ, 	/*FXOSC FREQ: Needs to be reconfigured with FXOSC frequency*/
		PLL_INTEGER_ONLY, 	/*PLL Mode: Needs to be reconfigured if SS feature enabled*/
		1,					/*PLL reference divider = 0 (0 + 1)*/
		2,					/*VCO Output divider. Considering VCO = 960MHz, VCO Div = 960/2 = 480MHz*/
		0, 					/*MFN: Needs to be reconfigured if SS feature enabled*/
		2,					/*PHI0: Needs to be reconfigured according to selected option*/
		1,					/*PHI1*/
		0,					/*PHI2: Not used*/
		0,					/*Spread Spectrum Enable: Needs to be reconfigured if SS feature enabled*/
		{
			0, 				/*Modulation Depth*/
			0				/*Modulation Frequency in MHz*/
		} /*Modulation config: Needs to be reconfigured if SS feature enabled*/
};
#ifdef IP_PLL_AUX
static clock_pll_cfg_t aux_pll_cfg =
{
	SYS_FXOSC_FREQ, 	/*FXOSC FREQ: Needs to be reconfigured with FXOSC frequency*/
	PLL_INTEGER_ONLY, 	/*PLL Mode: Needs to be reconfigured if SS feature enabled*/
	1,					/*PLL reference divider = 0 (0 + 1)*/
	2,					/*VCO Output divider. Considering VCO = 1000MHz, VCO Div = 1000/2 = 500MHz*/
	0, 					/*MFN: Needs to be reconfigured if SS feature enabled*/
	1,					/*PHI0: Needs to be reconfigured according to selected option*/
	1,					/*PHI1*/ //250MHz
	1,					/*PHI2*/ //250MHz
	0,					/*Spread Spectrum Enable. Not available in AUX PLL*/
	{
		0, 				/*Modulation Depth. Not available in AUX PLL*/
		0				/*Modulation Frequency in MHz. Not available in AUX PLL*/
	} /*Modulation config: Not available in AUX PLL*/
};
#endif
static const clock_fxosc_cfg_t fxosc_config =
{
	SYS_FXOSC_FREQ, 	/*FXOSC FREQ: Needs to be reconfigured with FXOSC frequency*/
	FXOSC_XTAL_MODE, 	/*FXOSC mode*/
	0x0C,				/*Transconductance selected GM_SEL = 12 (0.7016x)*/
	5000000				/*5 ms of stabilization time (5000000 ns)*/
};

/*Configures the PLL and PLL_AUX.
 * Parameters:
 * PLL VCO
 * PLL_AUX VCO
 * PLL_PHI_0 DIV
 * PLL_PHI_1 DIV
 *
 * Return -1 if an error occurred during FXOSC configuration
 * Return -2 if an error occurred during PLL configuration
 * Return -3 if an error occurred during PLL_AUX configuration
 *
 * PLL_AUX configuration is fixed for QSPI and ETH GMAC usage
 * */
static int8_t sys_cfg_pll_opt(uint32_t vco, uint8_t div0, uint8_t div1)
{
	int8_t error = 0;
	/*Configure FXOSC*/
	if(clock_init_fxosc(&fxosc_config) != CLOCK_NO_ERROR)
	{
		/* If there is an error in FXOSC initialization,
		 * the function breaks and returns an error.
		 * PLL is not configured.*/
		error = -1;
		return error;

	}

	/*Configures dividers of PLL outputs*/
	sys_pll_config.phi0_div = div0;
	sys_pll_config.phi1_div = div1;

	/*Configures PLL*/
	if(clock_init_pll(&sys_pll_config,vco) != CLOCK_NO_ERROR)
	{
		/* If there is an error setting the PLL,
		 * an error will be returned*/
		error = -2;
		return error;
	}
#ifdef IP_PLL_AUX
	if(clock_init_pll_aux(&aux_pll_cfg,1000000000) != CLOCK_NO_ERROR)
	{
		/* If there is an error setting the PLL,
		 * an error will be returned*/
		error = -3;
		return error;
	}
#endif
	return error;
}

int8_t sys_cfg_clock_opt(sys_clk_opt_e opt)
{
	int8_t error = 0;

	clock_sys_div_t * sys_div = &sys_div_cfg_a_plus;
	clock_core_source_e sys_clock_src = CORE_PLL;

	/*Consider VCO_OUT = VCO/2. Fixed divider in sys_pll_config variable*/
	if(opt == SYS_CLOCK_OPT_A_PLUS)
	{
		error = sys_cfg_pll_opt(960000000,1,2);
		sys_div = &sys_div_cfg_a_plus;
		sys_div_cfg_current = &sys_div_cfg_a_plus;
		sys_clock_src = CORE_PLL;
		mux_0_clk = 240000000;
	}
#ifdef S32K388
	else if(opt == SYS_CLOCK_OPT_A_PLUS_PLUS)
	{
		error = sys_cfg_pll_opt(640000000,0,1);
		sys_div = &sys_div_cfg_a_plus_plus;
		sys_div_cfg_current = &sys_div_cfg_a_plus_plus;
		sys_clock_src = CORE_PLL;
		mux_0_clk = 320000000;
	}
#endif
	else if(opt == SYS_CLOCK_OPT_A)
	{
		error = sys_cfg_pll_opt(640000000,0,0);
		sys_div = &sys_div_cfg_a;
		sys_div_cfg_current = &sys_div_cfg_a;
		sys_clock_src = CORE_PLL;
		mux_0_clk = 320000000;
	}
	else if(opt == SYS_CLOCK_OPT_B)
	{
		error = sys_cfg_pll_opt(960000000,3,1);
		sys_div = &sys_div_cfg_b;
		sys_div_cfg_current = &sys_div_cfg_b;
		sys_clock_src = CORE_PLL;
		mux_0_clk = 120000000;
	}
	else if(opt == SYS_CLOCK_OPT_C) //**
	{
		sys_firc_div(SYS_CLOCK_FIRC_DIV_2);
		sys_div = &sys_div_cfg_c;
		sys_clock_src = CORE_FIRC;
		sys_div_cfg_current = &sys_div_cfg_c;
		mux_0_clk = 24000000;

	}
	else if(opt == SYS_CLOCK_OPT_D)
	{
		sys_div = &sys_div_cfg_d;
		sys_clock_src = CORE_FIRC;
		sys_div_cfg_current = &sys_div_cfg_d;
		mux_0_clk = 48000000;
	}
	else if(opt == SYS_CLOCK_OPT_E)
	{

		sys_firc_div(SYS_CLOCK_FIRC_DIV_16);
		sys_div = &sys_div_cfg_e;
		sys_clock_src = CORE_FIRC;//<---
		sys_div_cfg_current = &sys_div_cfg_e;
		mux_0_clk = 3000000;

	}
	else if(opt == SYS_CLOCK_OPT_F)
	{
		error = sys_cfg_pll_opt(960000000,2,4);
		sys_div = &sys_div_cfg_a_plus;
		sys_div_cfg_current = &sys_div_cfg_f;
		sys_clock_src = CORE_PLL;
		mux_0_clk = 80000000;
	}
	else if(opt == SYS_CLOCK_OPT_E2)
	{
		sys_firc_div(SYS_CLOCK_FIRC_DIV_16);
		sys_div = &sys_div_cfg_e2;
		sys_clock_src = CORE_FIRC;//<---
		sys_div_cfg_current = &sys_div_cfg_e2;
		mux_0_clk = 3000000;

	}
	if(clock_set_core_clock(sys_clock_src,sys_div) != CLOCK_NO_ERROR)
	{
		/* If there is an error setting core clock,
		 * an error will be returned*/
		error = -1;
	}
	//clock_set_clockout(CLOCK_CLOCKOUT_MUX_AIPS_PLAT,CLOCK_CLOCKOUT_GPDO_PTD14,63);

	return error;
}
void sys_firc_div(sys_clk_firc_div div)
{
	while(((IP_CONFIGURATION_GPR->CONFIG_REG_GPR & CONFIGURATION_GPR_CONFIG_REG_GPR_APP_CORE_ACC_MASK) >> CONFIGURATION_GPR_CONFIG_REG_GPR_APP_CORE_ACC_SHIFT) != 5u);
	IP_CONFIGURATION_GPR->CONFIG_REG_GPR = CONFIGURATION_GPR_CONFIG_REG_GPR_APP_CORE_ACC(5) | CONFIGURATION_GPR_CONFIG_REG_GPR_FIRC_DIV_SEL(div);  /* FIRC_DIV_SEL=2: divided/16 */


}
int8_t sys_cfg_pmc(sys_pmc_opt opt);

uint32_t sys_get_clock(sys_clk_e sys_clk)
{
	switch (sys_clk)
	{
	case SYS_CLK_CORE:
		return mux_0_clk / (sys_div_cfg_current->core_div + 1);
		break;
	case SYS_CLK_AIPS_PLAT:
		return mux_0_clk / (sys_div_cfg_current->aips_plat_div + 1);
		break;
	case SYS_CLK_AIPS_SLOW:
		return mux_0_clk / (sys_div_cfg_current->aips_slow_div + 1);
		break;
	case SYS_CLK_HSE:
		return mux_0_clk / (sys_div_cfg_current->hse_div + 1);
		break;
	case SYS_CLK_DCM:
		return mux_0_clk / (sys_div_cfg_current->dcm_div + 1);
		break;
	case SYS_CLK_LBIST:
		return mux_0_clk / (sys_div_cfg_current->lbist_div + 1);
		break;
	case SYS_CLK_QSPI:
		return mux_0_clk / (sys_div_cfg_current->qspi_mem_div + 1);
		break;
	}
	return 0;
}

void sys_wake_core(uint8_t core, uint32_t boot_add)
{

}
