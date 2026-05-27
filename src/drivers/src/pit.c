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

#include "S32K344.h"

#include "pit.h"

/*Calback function for interrupt*/
pit_cb pit_callback;

/******************Interrupt Handlers*******************/
void PIT0_Handler(void)
{
	/*Stores the interrupt source on msk*/
	pit_cb_type_t msk =
	{
		0,
		IP_PIT_0->RTI_TFLG,
		IP_PIT_0->TIMER[0].TFLG,
		IP_PIT_0->TIMER[1].TFLG,
		IP_PIT_0->TIMER[2].TFLG,
		IP_PIT_0->TIMER[3].TFLG
	};

	/*Clears interrupt flags*/
	IP_PIT_0->RTI_TFLG |= PIT_RTI_TFLG_TIF_MASK;
	IP_PIT_0->TIMER[0].TFLG |= PIT_TFLG_TIF_MASK;
	IP_PIT_0->TIMER[1].TFLG |= PIT_TFLG_TIF_MASK;
	IP_PIT_0->TIMER[2].TFLG |= PIT_TFLG_TIF_MASK;
	IP_PIT_0->TIMER[3].TFLG |= PIT_TFLG_TIF_MASK;

	/*Calls callback function sending the Interrupt mask as a parameter*/
	pit_callback(&msk);
}

void PIT1_Handler(void)
{
	/*Stores the interrupt source on msk*/
	pit_cb_type_t msk =
	{
		1,
		0,
		IP_PIT_1->TIMER[0].TFLG,
		IP_PIT_1->TIMER[1].TFLG,
		IP_PIT_1->TIMER[2].TFLG,
		IP_PIT_1->TIMER[3].TFLG
	};

	/*Clears interrupt flags*/
	IP_PIT_1->RTI_TFLG |= PIT_RTI_TFLG_TIF_MASK;
	IP_PIT_1->TIMER[0].TFLG |= PIT_TFLG_TIF_MASK;
	IP_PIT_1->TIMER[1].TFLG |= PIT_TFLG_TIF_MASK;
	IP_PIT_1->TIMER[2].TFLG |= PIT_TFLG_TIF_MASK;
	IP_PIT_1->TIMER[3].TFLG |= PIT_TFLG_TIF_MASK;

	/*Calls callback function sending the Interrupt mask as a parameter*/
	pit_callback(&msk);
}

#ifdef IP_PIT_2
void PIT2_Handler(void)
{
	/*Stores the interrupt source on msk*/
	pit_cb_type_t msk =
	{
		2,
		0,
		IP_PIT_2->TIMER[0].TFLG,
		IP_PIT_2->TIMER[1].TFLG,
		IP_PIT_2->TIMER[2].TFLG,
		IP_PIT_2->TIMER[3].TFLG
	};

	/*Clears interrupt flags*/
	IP_PIT_2->RTI_TFLG |= PIT_RTI_TFLG_TIF_MASK;
	IP_PIT_2->TIMER[0].TFLG |= PIT_TFLG_TIF_MASK;
	IP_PIT_2->TIMER[1].TFLG |= PIT_TFLG_TIF_MASK;
	IP_PIT_2->TIMER[2].TFLG |= PIT_TFLG_TIF_MASK;
	IP_PIT_2->TIMER[3].TFLG |= PIT_TFLG_TIF_MASK;

	/*Calls callback function sending the Interrupt mask as a parameter*/
	pit_callback(&msk);
}
#endif

#ifdef IP_PIT_3
void PIT3_Handler(void)
{
	/*Stores the interrupt source on msk*/
	pit_cb_type_t msk =
	{
		3,
		0,
		IP_PIT_3->TIMER[0].TFLG,
		IP_PIT_3->TIMER[1].TFLG,
		IP_PIT_3->TIMER[2].TFLG,
		IP_PIT_3->TIMER[3].TFLG
	};

	/*Clears interrupt flags*/
	IP_PIT_3->RTI_TFLG |= PIT_RTI_TFLG_TIF_MASK;
	IP_PIT_3->TIMER[0].TFLG |= PIT_TFLG_TIF_MASK;
	IP_PIT_3->TIMER[1].TFLG |= PIT_TFLG_TIF_MASK;
	IP_PIT_3->TIMER[2].TFLG |= PIT_TFLG_TIF_MASK;
	IP_PIT_3->TIMER[3].TFLG |= PIT_TFLG_TIF_MASK;

	/*Calls callback function sending the Interrupt mask as a parameter*/
	pit_callback(&msk);
}
#endif

/*
 * pit_clock_init
 * @brief	Enables clock gating to peripheral
 * */
static void pit_clock_init(void)
{
	IP_MC_ME->PRTN0_COFB1_CLKEN |= MC_ME_PRTN0_COFB1_CLKEN_REQ44_MASK | MC_ME_PRTN0_COFB1_CLKEN_REQ45_MASK;
#ifdef IP_PIT_2
	IP_MC_ME->PRTN1_COFB1_CLKEN |= MC_ME_PRTN1_COFB1_CLKEN_REQ63_MASK;
#endif
	IP_MC_ME->PRTN0_PCONF |= MC_ME_PRTN0_PCONF_PCE_MASK;
	IP_MC_ME->PRTN0_PUPD  |= MC_ME_PRTN0_PUPD_PCUD_MASK;

	IP_MC_ME->PRTN1_PCONF |= MC_ME_PRTN1_PCONF_PCE_MASK;
	IP_MC_ME->PRTN1_PUPD  |= MC_ME_PRTN1_PUPD_PCUD_MASK;

	IP_MC_ME->CTL_KEY = 0x5AF0;
	IP_MC_ME->CTL_KEY = 0xA50F;

	/*Waits until Update process is finished*/
	while(IP_MC_ME->PRTN0_PUPD & MC_ME_PRTN0_PUPD_PCUD_MASK);
	while(IP_MC_ME->PRTN1_PUPD & MC_ME_PRTN1_PUPD_PCUD_MASK);

	while(!(IP_MC_ME->PRTN0_STAT & MC_ME_PRTN0_STAT_PCS_MASK));
	while(!(IP_MC_ME->PRTN1_STAT & MC_ME_PRTN1_STAT_PCS_MASK));
}

/*
 * pit_clock_init
 * @brief	Enables clock gating to peripheral
 */
void pit_init(volatile PIT_Type * module)
{
	/*Initializes clocks*/
	pit_clock_init();
	/*Unfreezes and enables timers*/
	module->MCR &= ~(PIT_MCR_FRZ_MASK | PIT_MCR_MDIS_RTI_MASK | PIT_MCR_MDIS_MASK);
	/*Enables IRQn*/
	if(module == IP_PIT_0)
	{
		NVIC_SetPriority(PIT0_IRQn, 2);
		NVIC_EnableIRQ(PIT0_IRQn);
	}
	else if(module == IP_PIT_1)
	{
		NVIC_SetPriority(PIT1_IRQn, 2);
		NVIC_EnableIRQ(PIT1_IRQn);
	}
#ifdef IP_PIT_2
	else if(module == IP_PIT_2)
	{
		NVIC_SetPriority(PIT2_IRQn, 2);
		NVIC_EnableIRQ(PIT2_IRQn);
	}
#endif
#ifdef IP_PIT_3
	else if(module == IP_PIT_3)
	{
		NVIC_SetPriority(PIT3_IRQn, 2);
		NVIC_EnableIRQ(PIT3_IRQn);
	}
#endif
}

void pit_config_tmr(volatile PIT_Type * module, pit_tmr_cfg_t * cfg)
{
	uint8_t tmr_n = (uint8_t)cfg->tmr;
	/*IF RTI is selected*/
	if(tmr_n == 0)
	{
		module->RTI_LDVAL = cfg->init_value;									/*Sets initial value*/
		while(!(module->RTI_LDVAL_STAT & PIT_RTI_LDVAL_STAT_RT_STAT_MASK));		/*Waits until value is asserted*/
		module->RTI_TFLG |= PIT_RTI_TFLG_TIF_MASK;								/*Clears interrupt on RTI*/
		module->RTI_TCTRL |= PIT_RTI_TCTRL_TEN_MASK | PIT_RTI_TCTRL_TIE_MASK;	/*Enables Timer and Interrupt*/
	}
	/*IF Standard timer is selected*/
	else
	{
		tmr_n--;
		module->TIMER[tmr_n].LDVAL = cfg->init_value;							/*Sets initial value*/
		module->TIMER[tmr_n].TFLG |= PIT_TFLG_TIF_MASK;							/*Clears interrupt*/
		module->TIMER[tmr_n].TCTRL |= PIT_TCTRL_CHN(cfg->chain) | PIT_TCTRL_TEN_MASK | PIT_TCTRL_TIE_MASK; /*Enables Timer and Interrupt and chain if configures*/
	}
	pit_callback = cfg->cb;
}

void pit_disable_tmr(volatile PIT_Type * module, pit_tmr_e type)
{
	uint8_t tmr_n = (uint8_t) type;
	/*IF RTI is selected*/
	if(tmr_n == 0)
	{
		/*Disables timer and interrupt*/
		module->RTI_TCTRL &= ~(PIT_RTI_TCTRL_TEN_MASK | PIT_TCTRL_TIE_MASK);
	}
	/*IF Standard timer is selected*/
	else
	{
		tmr_n--;
		/*Disables timer and interrupt*/
		module->TIMER[tmr_n].TCTRL &= ~(PIT_TCTRL_CHN(1) | PIT_TCTRL_TEN_MASK | PIT_TCTRL_TIE_MASK);
	}
}

uint32_t pit_get_current_value(volatile PIT_Type * module, pit_tmr_e type)
{
	uint8_t tmr_n = (uint8_t) type;
	/*Temp storage for timer value*/
	uint32_t tmr_v = 0;
	/*IF RTI is selected*/
	if(tmr_n == 0)
	{
		/*reads timer register*/
		tmr_v = module->RTI_CVAL;
	}
	/*IF Standard timer is selected*/
	else
	{
		tmr_n--;
		/*reads timer register*/
		tmr_v = module->TIMER[tmr_n].CVAL;
	}
	/*Returns timer value*/
	return tmr_v;
}
