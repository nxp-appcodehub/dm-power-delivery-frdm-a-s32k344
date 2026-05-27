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

#include "mc_me.h"

uint32_t mcme_poll_clk_gate_status(mc_me_clock_ip_name_t name)
{
	uint32_t mc_me_addr, prtn_offset, prtn_cofb_stat_offset;
	uint16_t prtn_num;
	uint16_t req_shift;
	// Get clock enable data from mc_me_clock_ip_name_t
	//	mc_me_type	= CLK_GATE_ABSTRACT_MCME_TYPE((uint32_t)name);
	prtn_num	= CLK_GATE_ABSTRACT_PRTN_NUM((uint32_t)name);
	req_shift	= CLK_GATE_ABSTRACT_REQ_SHIFT((uint32_t)name);
	// Get register addresses
	mc_me_addr  = MCME_BASE;
	prtn_offset = (prtn_num != 0) ? 0x200U*(prtn_num - 1) + 0x300U : 0x100U;
	prtn_offset += mc_me_addr;
	prtn_cofb_stat_offset = prtn_offset + 0x10U + (req_shift/32)*4;
	req_shift %= 32;
	// Enable the clock in PRTNX_COFBX_CLKEN
	return ((*(volatile uint32_t *)(prtn_cofb_stat_offset)) & (1 << req_shift));
}

void mcme_clock_enb(mc_me_clock_ip_name_t name)
{
	uint32_t mc_me_addr, prtn_offset, prtn_cofb_clken_offset;
	uint16_t prtn_num;
	uint16_t req_shift;
	// Get clock enable data from mc_me_clock_ip_name_t
	//	mc_me_type	= CLK_GATE_ABSTRACT_MCME_TYPE((uint32_t)name);
	prtn_num	= CLK_GATE_ABSTRACT_PRTN_NUM((uint32_t)name);
	req_shift	= CLK_GATE_ABSTRACT_REQ_SHIFT((uint32_t)name);
	// Get register addresses
	mc_me_addr  = MCME_BASE;
	prtn_offset = (prtn_num != 0) ? 0x200U*(prtn_num - 1) + 0x300U : 0x100U;
	prtn_offset += mc_me_addr;
	prtn_cofb_clken_offset = prtn_offset + 0x30U + (req_shift/32)*4;
	req_shift %= 32;
	// Enable the clock in PRTNX_COFBX_CLKEN
	(*(volatile uint32_t *)prtn_cofb_clken_offset) |= (1UL << req_shift);
	// Set partition pce and pcud
	(*(volatile uint32_t *)(prtn_offset + PRTN_PCONF_OFFSET)) 	|= (1UL << PCONF_PCE_SHIFT);
	(*(volatile uint32_t *)(prtn_offset + PRTN_PUPD_OFFSET)) 	|= (1UL << PUPD_PCUD_SHIFT);
	// Write valid key to mcme
	//	(*(volatile struct MC_ME_tag *)mc_me_addr).CTL_KEY.B.KEY = 0x5AF0;
	//	(*(volatile struct MC_ME_tag *)mc_me_addr).CTL_KEY.B.KEY = 0xA50F;
	IP_MC_ME->CTL_KEY = MC_ME_CTL_KEY_KEY(0x5AF0);
	IP_MC_ME->CTL_KEY = MC_ME_CTL_KEY_KEY(0xA50F);
	// Wait for pcud to be cleared and pcs to be set
	while((*(volatile uint32_t *)(prtn_offset + PRTN_PUPD_OFFSET)) & (1UL << PUPD_PCUD_SHIFT));
	while(!((*(volatile uint32_t *)(prtn_offset + PRTN_STAT_OFFSET)) & (1UL << STAT_PCS_SHIFT)));
}

void mcme_clock_dis(mc_me_clock_ip_name_t name)
{
	uint32_t mc_me_addr, prtn_offset, prtn_cofb_clken_offset;
	uint16_t prtn_num;
	uint16_t req_shift;
	// Get clock enable data from mc_me_clock_ip_name_t
	prtn_num	= CLK_GATE_ABSTRACT_PRTN_NUM((uint32_t)name);
	req_shift	= CLK_GATE_ABSTRACT_REQ_SHIFT((uint32_t)name);
	// Get register addresses
	mc_me_addr  = MCME_BASE;
	prtn_offset = (prtn_num != 0) ? 0x200U*(prtn_num - 1) + 0x300U : 0x100U;
	prtn_offset += mc_me_addr;
	prtn_cofb_clken_offset = prtn_offset + 0x30U + (req_shift/32)*4;
	req_shift %= 32;
	// Enable the clock in PRTNX_COFBX_CLKEN
	(*(volatile uint32_t *)prtn_cofb_clken_offset) &= ~(1UL << req_shift);
	// Set partition pce and pcud
	(*(volatile uint32_t *)(prtn_offset + PRTN_PUPD_OFFSET)) 	|= (1UL << PUPD_PCUD_SHIFT);
	// Write valid key to mcme
	//	(*(volatile struct MC_ME_tag *)mc_me_addr).CTL_KEY.B.KEY = 0x5AF0;
	//	(*(volatile struct MC_ME_tag *)mc_me_addr).CTL_KEY.B.KEY = 0xA50F;
	IP_MC_ME->CTL_KEY = MC_ME_CTL_KEY_KEY(0x5AF0);
	IP_MC_ME->CTL_KEY = MC_ME_CTL_KEY_KEY(0xA50F);
	// Wait for pcud to be cleared and pcs to be set
	while((*(volatile uint32_t *)(prtn_offset + PRTN_PUPD_OFFSET)) & (1UL << PUPD_PCUD_SHIFT));
}
