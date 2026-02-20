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

#include "clock.h"

#define E9	1000000000

/*	clock_fxosc_wait_stability
 * 	@brief	Waits until Stability flag is set or timeout is passed
 * 	@return	-1 if timeout has passed, 0 otherwise.
 */
static int8_t clock_fxosc_wait_stability(void)
{
	uint32_t timeout = 100000;
	while(!(IP_FXOSC -> STAT & FXOSC_STAT_OSC_STAT_MASK))
	{
		if(--timeout == 0)
		{
			break;
		}
	}
	return (timeout == 0) ? -1 : 0;
}

/*	clock_gate_source
 * 	@brief	Enables clock gating for clock modules on partition 1
 * 	@param	one of @ref clock_source_e to select clock module to be enabled.
 */
static void clock_gate_source(clock_source_e clk_src)
{
	IP_MC_ME->PRTN1_PCONF |= MC_ME_PRTN1_PCONF_PCE(1); 	/*Enables clock on partition 1*/
	IP_MC_ME->PRTN1_PUPD |= MC_ME_PRTN1_PUPD_PCUD(1);	/*Trigger the hardware process*/

	switch(clk_src)
	{
	case FIRC:
		/*FIRC is enabled by default and cannot be changed*/
		break;
	case SIRC:
		/*SIRC is enabled by default and cannot be changed*/
		break;
	case PLL:
		IP_MC_ME->PRTN1_COFB1_CLKEN |= MC_ME_PRTN1_COFB1_CLKEN_REQ56(1);				/* REQ56: Frequency Modulated Phase-Locked Loop */
		IP_MC_ME->CTL_KEY = 0x5AF0;
		IP_MC_ME->CTL_KEY = 0xA50F;
		while (!(IP_MC_ME->PRTN1_COFB1_STAT & MC_ME_PRTN1_COFB1_STAT_BLOCK56_MASK));	/* Wait until PLL clock is running */
		break;
#ifdef IP_PLL_AUX
	case AUX_PLL:
		IP_MC_ME->PRTN1_COFB1_CLKEN |= MC_ME_PRTN1_COFB1_CLKEN_REQ57(1);				/* REQ57: Auxilliar Frequency Modulated Phase-Locked Loop */
		IP_MC_ME->CTL_KEY = 0x5AF0;
		IP_MC_ME->CTL_KEY = 0xA50F;
		while (!(IP_MC_ME->PRTN1_COFB1_STAT & MC_ME_PRTN1_COFB1_STAT_BLOCK57_MASK));	/* Wait until Aux-PLL clock is running */
		break;
#endif
	case FXOSC:
		IP_MC_ME->PRTN1_COFB1_CLKEN |= MC_ME_PRTN1_COFB1_CLKEN_REQ53(1);				/* REQ53: Fast External Oscillator */
		IP_MC_ME->CTL_KEY = 0x5AF0;
		IP_MC_ME->CTL_KEY = 0xA50F;
		while (!(IP_MC_ME->PRTN1_COFB1_STAT & MC_ME_PRTN1_COFB1_STAT_BLOCK53_MASK));	/* Wait until FXOSC clock is running */
		break;
	case SXOSC:
		IP_MC_ME->PRTN1_COFB1_CLKEN |= MC_ME_PRTN1_COFB1_CLKEN_REQ51(1);				/* REQ51: Slow External Oscillator */
		IP_MC_ME->CTL_KEY = 0x5AF0;
		IP_MC_ME->CTL_KEY = 0xA50F;
		while (!(IP_MC_ME->PRTN1_COFB1_STAT & MC_ME_PRTN1_COFB1_STAT_BLOCK51_MASK));	/* Wait until SXOSC clock is running */
		break;
	}
}

clock_config_error_e clock_init_fxosc(const clock_fxosc_cfg_t * cfg)
{

	/*Enables FXOSC clock gating*/
	clock_gate_source(FXOSC);

	//Powers down FXOSC
	IP_FXOSC -> CTRL &= ~FXOSC_CTRL_OSCON_MASK;

	uint8_t fxosc_ns = 1*E9/cfg->freq;
	uint32_t eocv = 0x9D;

	switch(cfg->mode)
	{
	case FXOSC_XTAL_MODE:
		//Sets xtal mode
		IP_FXOSC -> CTRL |= FXOSC_CTRL_COMP_EN_MASK;
		IP_FXOSC -> CTRL &= ~FXOSC_CTRL_OSC_BYP_MASK;
		//sets gm (transconductance)
		if(cfg->gm_sel == 0)
		{
			return CLOCK_ERROR;
		}
		IP_FXOSC -> CTRL &= ~FXOSC_CTRL_GM_SEL_MASK;
		IP_FXOSC -> CTRL |= FXOSC_CTRL_GM_SEL(cfg->gm_sel);
		break;
	case FXOSC_SINGLE_IN_MODE:
		//Sets Single-input Bypass mode
		IP_FXOSC -> CTRL |= FXOSC_CTRL_OSC_BYP_MASK;
		IP_FXOSC -> CTRL &= ~FXOSC_CTRL_COMP_EN_MASK;
		//clears gm (transconductance)
		IP_FXOSC -> CTRL &= ~FXOSC_CTRL_GM_SEL_MASK;
		break;
	}

	//Sets EOCV fos stabilizing the FXOSC
	eocv = cfg->stab_time/(4*128*fxosc_ns); 	/*Calculates EOCV: stabilization_time / ( 4 * 128 * FXOSC_PERIOD)*/
	IP_FXOSC -> CTRL &= ~FXOSC_CTRL_EOCV_MASK; 	/*Clears EOCV*/
	IP_FXOSC -> CTRL |= FXOSC_CTRL_EOCV(eocv); 	/*Sets EOCV*/

	//Powers on FXOSC
	IP_FXOSC -> CTRL |= FXOSC_CTRL_OSCON_MASK;

	/*Checks if FXOSC is on and stable*/
	if(clock_fxosc_wait_stability())
	{
		return CLOCK_ERROR;
	}
	return CLOCK_NO_ERROR;
}

#ifdef IP_SXOSC
clock_config_error_e clock_init_sxosc(void)
{
	/*Enables SXOSC clock gating*/
	clock_gate_source(SXOSC);

	//Powers up SXOSC
	IP_SXOSC->SXOSC_CTRL |= SXOSC_SXOSC_CTRL_OSCON_MASK;

	uint32_t timeout = 100000;
	while(!(IP_SXOSC->SXOSC_STAT & SXOSC_SXOSC_STAT_OSC_STAT_MASK))
	{
		if(--timeout == 0)
		{
			return CLOCK_ERROR;
		}
	}
	return CLOCK_NO_ERROR;
}
#endif

clock_config_error_e clock_init_pll (clock_pll_cfg_t * pll_cfg, uint32_t vco_freq)
{

	uint32_t mfi = 0x32;

	/*Variables for modulation mode*/
	uint16_t ldf = 0;
	uint16_t stepno = 0;
	uint16_t stepsize = 0;

	//Checks dividers values
	if(pll_cfg->ref_div > 0x07 || pll_cfg->vco_div > 0x3F)
	{
		return CLOCK_ERROR;
	}

	if(pll_cfg->mode == PLL_FRACTIONAL_MODULATION && pll_cfg->MFN > 18432)
	{
		return CLOCK_ERROR;
	}
	else if (pll_cfg->mode == PLL_FRACTIONAL_NO_MODULATION && pll_cfg->MFN > 18432)
	{
		return CLOCK_ERROR;
	}

	/*Enables PLL clock gating*/
	clock_gate_source(PLL);

	//Disable output dividers
	IP_PLL -> PLLODIV[0] &= ~PLL_PLLODIV_DE_MASK;
	IP_PLL -> PLLODIV[1] &= ~PLL_PLLODIV_DE_MASK;

	//Powers down PLL
	IP_PLL -> PLLCR |= PLL_PLLCR_PLLPD_MASK;

	//Calculates MFI
	switch (pll_cfg->mode)
	{
	case PLL_INTEGER_ONLY:
		if(pll_cfg->ref_div == 0)
		{
			mfi = vco_freq / pll_cfg->fxosc_freq;
		}
		else
		{
			mfi = (vco_freq * pll_cfg->ref_div) / pll_cfg->fxosc_freq;
		}
		break;
	case PLL_FRACTIONAL_NO_MODULATION:
		if(pll_cfg->ref_div == 0)
		{
			mfi = (vco_freq / pll_cfg->fxosc_freq) - (pll_cfg->MFN / 18432);
		}
		else
		{
			mfi = (vco_freq * pll_cfg->ref_div / pll_cfg->fxosc_freq) - (pll_cfg->MFN / 18432);
		}
		break;
	case PLL_FRACTIONAL_MODULATION:
		if(pll_cfg->ref_div == 0)
		{
			mfi = (vco_freq / pll_cfg->fxosc_freq) - (pll_cfg->MFN / 18432);
		}
		else
		{
			mfi = (vco_freq * pll_cfg->ref_div / pll_cfg->fxosc_freq) - (pll_cfg->MFN / 18432);
		}
		/* For Modulation some values are required to be calculated/provided
		 * LDF is the Loop Division Factor and is equal to the MFI + MFN/18432
		 * STEPNO and STEPSIze provide the step characteristics on the modulation
		 */
		ldf = mfi + (pll_cfg->MFN/18432);
		stepno = pll_cfg->fxosc_freq/(2 * pll_cfg->mod_cfg.f_mod * pll_cfg->ref_div);
		stepsize = ((pll_cfg->mod_cfg.MD * ldf)/(100 * stepno)) * 18432;
		if((stepsize * stepno) > 18432)
		{
			return MODULATION_ERROR;
		}
		break;
	}
	//Configures divider
	IP_PLL -> PLLDV &= ~(PLL_PLLDV_ODIV2_MASK | PLL_PLLDV_RDIV_MASK | PLL_PLLDV_MFI_MASK);
	IP_PLL -> PLLDV |= PLL_PLLDV_ODIV2(pll_cfg->vco_div) | PLL_PLLDV_RDIV(pll_cfg->ref_div) | PLL_PLLDV_MFI(mfi);

	if(pll_cfg->mode == PLL_INTEGER_ONLY)
	{
		IP_PLL -> PLLFD = 0;
	}

	if(pll_cfg->mode == PLL_FRACTIONAL_MODULATION)
	{
		IP_PLL -> PLLFM &= ~(PLL_PLLFM_STEPSIZE_MASK | PLL_PLLFM_STEPNO_MASK);
		IP_PLL -> PLLFM |= PLL_PLLFM_STEPSIZE(stepsize) | PLL_PLLFM_STEPNO(stepno);
		IP_PLL -> PLLFD |= PLL_PLLFD_SDMEN(1) | PLL_PLLFD_SDM2(1) | PLL_PLLFD_SDM3(1) | PLL_PLLFD_MFN(pll_cfg->MFN);
	}

	if(pll_cfg->mode == PLL_FRACTIONAL_NO_MODULATION)
	{
		IP_PLL -> PLLFD |= PLL_PLLFD_SDMEN(1) | PLL_PLLFD_SDM2(1) | PLL_PLLFD_SDM3(1) | PLL_PLLFD_MFN(pll_cfg->MFN);
	}

	//Sets Divisors for PHI outputs
	IP_PLL -> PLLODIV[0] |= PLL_PLLODIV_DE(1) | PLL_PLLODIV_DIV(pll_cfg->phi0_div) ;
	IP_PLL -> PLLODIV[1] |= PLL_PLLODIV_DE(1) | PLL_PLLODIV_DIV(pll_cfg->phi1_div) ;
	IP_PLL -> PLLFM |= PLL_PLLFM_SPREADCTL(1);

	//Waits for FXOSC to be stable
	if(clock_fxosc_wait_stability())
	{
		return CLOCK_ERROR;
	}

	//Powers up PLL
	IP_PLL -> PLLCR &= ~PLL_PLLCR_PLLPD_MASK;

	//Waits for PLL LOCK
	while(!(IP_PLL -> PLLSR & PLL_PLLSR_LOCK_MASK));

	//Enable output dividers
	IP_PLL -> PLLODIV[0] |= PLL_PLLODIV_DE_MASK;
	IP_PLL -> PLLODIV[1] |= PLL_PLLODIV_DE_MASK;

	return CLOCK_NO_ERROR;
}

#ifdef IP_PLL_AUX
clock_config_error_e clock_init_pll_aux (clock_pll_cfg_t * pll_cfg, uint32_t vco_freq)
{

	uint32_t mfi = 0x32;

	//Checks dividers values
	if(pll_cfg->ref_div > 0x07 || pll_cfg->vco_div > 0x3F)
	{
		return CLOCK_ERROR;
	}

	/*Enables AUX_PLL clock gating*/
	clock_gate_source(AUX_PLL);

	//Disable output dividers
	IP_PLL_AUX -> PLLODIV[0] &= ~PLL_PLLODIV_DE_MASK;
	IP_PLL_AUX -> PLLODIV[1] &= ~PLL_PLLODIV_DE_MASK;

	//Powers down PLL
	IP_PLL_AUX -> PLLCR |= PLL_PLLCR_PLLPD_MASK;

	//Calculates MFI
	switch (pll_cfg->mode)
	{
	case PLL_INTEGER_ONLY:
		if(pll_cfg->ref_div == 0)
		{
			mfi = vco_freq / pll_cfg->fxosc_freq;
		}
		else
		{
			mfi = vco_freq * pll_cfg->ref_div / pll_cfg->fxosc_freq;
		}
		break;
	case PLL_FRACTIONAL_NO_MODULATION:
		return CLOCK_ERROR;
		break;
	case PLL_FRACTIONAL_MODULATION:
		return CLOCK_ERROR;
		break;
	}
	//Configures divider
	IP_PLL_AUX -> PLLDV &= ~(PLL_PLLDV_ODIV2_MASK | PLL_PLLDV_RDIV_MASK | PLL_PLLDV_MFI_MASK);
	IP_PLL_AUX -> PLLDV |= PLL_PLLDV_ODIV2(pll_cfg->vco_div) | PLL_PLLDV_RDIV(pll_cfg->ref_div) | PLL_PLLDV_MFI(mfi);

	//Sets Divisors for PHI outputs
	IP_PLL_AUX -> PLLODIV[0] |= PLL_PLLODIV_DE(1) | PLL_PLLODIV_DIV(pll_cfg->phi0_div) ;
	IP_PLL_AUX -> PLLODIV[1] |= PLL_PLLODIV_DE(1) | PLL_PLLODIV_DIV(pll_cfg->phi1_div) ;
#if (PLL_PLLODIV_COUNT >= 3)
	IP_PLL_AUX -> PLLODIV[2] |= PLL_PLLODIV_DE(1) | PLL_PLLODIV_DIV(pll_cfg->phi2_div) ;
#endif

	//Waits for FXOSC to be stable
	if(clock_fxosc_wait_stability())
	{
		return CLOCK_ERROR;
	}

	//Powers up PLL
	IP_PLL_AUX -> PLLCR &= ~PLL_PLLCR_PLLPD_MASK;

	//Waits for PLL LOCK
	while(!(IP_PLL_AUX -> PLLSR & PLL_PLLSR_LOCK_MASK));

	//Enable output dividers
	IP_PLL_AUX -> PLLODIV[0] |= PLL_PLLODIV_DE_MASK;
	IP_PLL_AUX -> PLLODIV[1] |= PLL_PLLODIV_DE_MASK;
#if (PLL_PLLODIV_COUNT >= 3)
	IP_PLL_AUX -> PLLODIV[2] |= PLL_PLLODIV_DE_MASK;
#endif

	return CLOCK_NO_ERROR;
}
#endif
clock_config_error_e clock_set_core_clock(clock_core_source_e source, clock_sys_div_t * sys_div)
{
	IP_MC_CGM->MUX_0_DIV_TRIG_CTRL |= MC_CGM_MUX_0_DIV_TRIG_CTRL_TCTL_MASK; /* TCTL=1: Switch to common trigger divider update */
	IP_MC_CGM->MUX_0_DIV_TRIG_CTRL |= MC_CGM_MUX_0_DIV_TRIG_CTRL_HHEN_MASK; /* HHEN=1: Halt handshake protocol with AXBS is initiated */

	IP_MC_CGM->MUX_0_DC_0 = MC_CGM_MUX_0_DC_0_DIV(sys_div -> core_div);  	/* CORE_CLK		*/
	IP_MC_CGM->MUX_0_DC_1 = MC_CGM_MUX_0_DC_1_DIV(sys_div->aips_plat_div);  /* AIPS_PLAT_CLK*/
	IP_MC_CGM->MUX_0_DC_2 = MC_CGM_MUX_0_DC_2_DIV(sys_div->aips_slow_div);  /* AIPS_SLOW_CLK*/
	IP_MC_CGM->MUX_0_DC_3 = MC_CGM_MUX_0_DC_3_DIV(sys_div->hse_div);  		/* HSE_CLK		*/
	IP_MC_CGM->MUX_0_DC_4 = MC_CGM_MUX_0_DC_4_DIV(sys_div->dcm_div);  		/* DCM_CLK 		*/
	IP_MC_CGM->MUX_0_DC_5 = MC_CGM_MUX_0_DC_5_DIV(sys_div->lbist_div);  	/* LBIST_CLK	*/
	IP_MC_CGM->MUX_0_DC_6 = MC_CGM_MUX_0_DC_6_DIV(sys_div->qspi_mem_div);  	/* QSPI_MEM_CLK	*/

    IP_MC_CGM->MUX_0_DC_0 |= MC_CGM_MUX_0_DC_0_DE_MASK; /* Enable divider 0 */
    IP_MC_CGM->MUX_0_DC_1 |= MC_CGM_MUX_0_DC_1_DE_MASK; /* Enable divider 1 */
    IP_MC_CGM->MUX_0_DC_2 |= MC_CGM_MUX_0_DC_2_DE_MASK; /* Enable divider 2 */
    IP_MC_CGM->MUX_0_DC_3 |= MC_CGM_MUX_0_DC_3_DE_MASK; /* Enable divider 3 */
    IP_MC_CGM->MUX_0_DC_4 |= MC_CGM_MUX_0_DC_4_DE_MASK; /* Enable divider 4 */
    IP_MC_CGM->MUX_0_DC_5 |= MC_CGM_MUX_0_DC_5_DE_MASK; /* Enable divider 5 */
    IP_MC_CGM->MUX_0_DC_6 |= MC_CGM_MUX_0_DC_6_DE_MASK; /* Enable divider 6 */

    /* Writing any value to this register provides a trigger to the dividers */
    IP_MC_CGM->MUX_0_DIV_TRIG = 0xFFFFFFFF;
    /* Make sure the divider has sampled the new divider configuration */
    while ((IP_MC_CGM->MUX_0_DIV_UPD_STAT & MC_CGM_MUX_0_DIV_UPD_STAT_DIV_STAT_MASK) != 0) { }

	/* Verify that we don't have switching in progress */
    while ((IP_MC_CGM->MUX_0_CSS & MC_CGM_MUX_0_CSS_SWIP_MASK) != 0) { }

	switch(source)
	{
	case CORE_PLL:
		//Checks that PLL is running
		if(!(IP_PLL -> PLLSR & PLL_PLLSR_LOCK_MASK))
		{
			return CLOCK_ERROR;
		}
		IP_MC_CGM->MUX_0_CSC  = MC_CGM_MUX_0_CSC_SELCTL(8);   				/* SELCTL=8: PLL_PHI0_CLK */
    	IP_MC_CGM->MUX_0_CSC |= MC_CGM_MUX_0_CSC_CLK_SW_MASK; 				/* Request clock switch */
    	while(!(IP_MC_CGM->MUX_0_CSS & MC_CGM_MUX_0_CSS_CLK_SW_MASK)) { }  	/* Wait for completion of clock switching */
		break;
	case CORE_FIRC:
		IP_MC_CGM->MUX_0_CSC  = MC_CGM_MUX_0_CSC_SELCTL(0);   				/* SELCTL=0: FIRC */
    	IP_MC_CGM->MUX_0_CSC |= MC_CGM_MUX_0_CSC_CLK_SW_MASK; 				/* Request clock switch */
    	while(!(IP_MC_CGM->MUX_0_CSS & MC_CGM_MUX_0_CSS_CLK_SW_MASK)) { }  	/* Wait for completion of clock switching */
		break;
	}

	return CLOCK_NO_ERROR;
}

void clock_set_clockout(uint8_t src, uint8_t gpdo, uint8_t div)
{
	uint8_t sss = 0;
	while ((IP_MC_CGM->MUX_6_CSS & MC_CGM_MUX_6_CSS_GRIP_MASK) != 0);

	//Selects CORE_CLOCK as CLOCK_OUT source
	IP_MC_CGM -> MUX_6_DC_0 &= ~MC_CGM_MUX_6_DC_0_DE_MASK;		/*Disables Divider of MUX 6		*/
	IP_MC_CGM -> MUX_6_CSC &= ~MC_CGM_MUX_6_CSC_SELCTL_MASK;	/*Clears Selector of MUX 6		*/
	IP_MC_CGM -> MUX_6_CSC |= MC_CGM_MUX_6_CSC_SELCTL(src);		/*Sets Selector of MUX 6		*/
	IP_MC_CGM -> MUX_6_DC_0 &= ~MC_CGM_MUX_6_DC_0_DIV_MASK;		/*Clears divider value of MUX 6	*/
	IP_MC_CGM -> MUX_6_DC_0 |= MC_CGM_MUX_6_DC_0_DIV(div);		/*Sets divider value of MUX 6	*/
	IP_MC_CGM -> MUX_6_DC_0 |= MC_CGM_MUX_6_DC_0_DE(1);			/*Enables divider of MUX 6		*/

	while ((IP_MC_CGM->MUX_6_DIV_UPD_STAT & MC_CGM_MUX_6_DIV_UPD_STAT_DIV_STAT_MASK) != 0); /* Wait for clock divider update completed */
	while ((IP_MC_CGM->MUX_6_CSS & MC_CGM_MUX_6_CSS_GRIP_MASK) != 0); /* Verify that clock switch completed */

	/*Selects proper value of SSS according to selected GPIO*/
	switch(gpdo)
	{
	case CLOCK_CLOCKOUT_GPDO_PTB5:
		sss |= SIUL2_MSCR_SSS_0(1) | SIUL2_MSCR_SSS_2(1); // SSS = 0x0101
		break;
	case CLOCK_CLOCKOUT_GPDO_PTD10:
		sss |= SIUL2_MSCR_SSS_1(1) | SIUL2_MSCR_SSS_2(1); // SSS = 0x0110
		break;
	case CLOCK_CLOCKOUT_GPDO_PTD14:
		sss |= SIUL2_MSCR_SSS_0(1) | SIUL2_MSCR_SSS_1(1) | SIUL2_MSCR_SSS_2(1); // SSS = 0x0111
		break;
	}

	IP_SIUL2 -> MSCR[gpdo] = sss; /*Writes SSS on selected GPDO*/
}

uint8_t clock_pll_get_lol_status(uint8_t pll_instance)
{
	if(!pll_instance)
	{
		return (IP_PLL->PLLSR & PLL_PLLSR_LOL_MASK) >> PLL_PLLSR_LOL_SHIFT;
	}
#ifdef IP_PLL_AUX
	else
	{
		return (IP_PLL_AUX->PLLSR & PLL_PLLSR_LOL_MASK) >> PLL_PLLSR_LOL_SHIFT;
	}
#endif
	return 0;
}
