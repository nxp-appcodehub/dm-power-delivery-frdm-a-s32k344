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

#ifndef CLOCK_CLOCK_H_
#define CLOCK_CLOCK_H_

#include "S32K344.h"

#define CLOCK_CORE_PLL_AUX	8
#define CLOCK_CORE_FIRC		0

#define CLOCK_CLOCKOUT_GPDO_PTB5	37
#define CLOCK_CLOCKOUT_GPDO_PTD10	106
#define CLOCK_CLOCKOUT_GPDO_PTD14	110

#define CLOCK_CLOCKOUT_MUX_FIRC			0x00
#define CLOCK_CLOCKOUT_MUX_SIRC			0x01
#define CLOCK_CLOCKOUT_MUX_FXOSC		0x02
#define CLOCK_CLOCKOUT_MUX_SXOSC		0x04
#define CLOCK_CLOCKOUT_MUX_PLL_PHI0		0x08
#define CLOCK_CLOCKOUT_MUX_PLL_PHI1		0x09
#define CLOCK_CLOCKOUT_MUX_AUX_PLL_PHI0	0x0C
#define CLOCK_CLOCKOUT_MUX_AUX_PLL_PHI1	0x0D
#define CLOCK_CLOCKOUT_MUX_AUX_PLL_PHI2	0x0E
#define CLOCK_CLOCKOUT_MUX_CORE			0x10
#define CLOCK_CLOCKOUT_MUX_HSE			0x13
#define CLOCK_CLOCKOUT_MUX_AIPS_PLAT	0x16
#define CLOCK_CLOCKOUT_MUX_AIPS_SLOW	0x17
#define CLOCK_CLOCKOUT_MUX_EMAC_RMII_TX	0x18
#define CLOCK_CLOCKOUT_MUX_EMAC_RX		0x19

typedef enum clock_source
{
	FIRC,
	SIRC,
	PLL,
#ifdef IP_PLL_AUX
	AUX_PLL,
#endif
	FXOSC,
	SXOSC
}clock_source_e;
//Error code for config functions
typedef enum clock_config_error
{
	CLOCK_NO_ERROR = 0,
	CLOCK_ERROR,
	MODULATION_ERROR,
	NOT_IMPLEMENTED
} clock_config_error_e;

/*
 * enum clock_pll_mode
 * Mode of operation of PLL.
 * For AUX_PLL only PLL_INTEGER_ONLY is available.
 */
typedef enum clock_pll_mode
{
	PLL_INTEGER_ONLY,
	PLL_FRACTIONAL_NO_MODULATION,
	PLL_FRACTIONAL_MODULATION
} clock_pll_mode_e;

// FXOSC mode enumerator
typedef enum clock_fxosc_mode
{
	FXOSC_XTAL_MODE,		//XTAL is used
	FXOSC_SINGLE_IN_MODE	//Other Oscillator source is used
} clock_fxosc_mode_e;

//PLL modulation config struct
typedef struct clock_pll_mod
{
	uint8_t MD;		//Modulation depth in percentage
	uint32_t f_mod;	//Modulation frequency in Hz
} clock_pll_mod_t;

//PLL config struct
typedef struct clock_pll_cfg
{
	uint32_t fxosc_freq;		//PLL source frequency (FXOSC)
	clock_pll_mode_e mode;		//one of @ref clock_pll_mode_e
	uint8_t ref_div;			//PLL reference divider value
	uint8_t vco_div;			//VCO output divider value
	uint8_t MFN;				//Loop Division Factor for fractional mode
	uint8_t phi0_div;			//PLL_PHI0 Output divider
	uint8_t phi1_div;			//PLL_PHI0 Output divider
	uint8_t phi2_div;			//PLL_PHI0 Output divider (only for AUX_PLL)
	uint8_t spread_en;			//Enables spread spectrum
	clock_pll_mod_t mod_cfg;	//modulation config @ref clock_pll_mod_t
} clock_pll_cfg_t;

//FXOSC config struct
typedef struct clock_fxosc_cfg
{
	uint32_t freq;
	clock_fxosc_mode_e mode;	//One of @ref clock_fxosc_mode_e
	uint8_t gm_sel;				//XTAL transconductance selector. Set to 0x0000 when FXOSC_SINGLE_IN_MODE is selected
	uint32_t stab_time;			//Stabilization time in ns
} clock_fxosc_cfg_t;

//Core clock source enumerator
typedef enum clock_core_source
{
	CORE_PLL,
	CORE_FIRC
} clock_core_source_e;

//System clock dividers structure
typedef struct clock_sys_div
{
	uint8_t core_div;
	uint8_t aips_plat_div;
	uint8_t aips_slow_div;
	uint8_t hse_div;
	uint8_t dcm_div;
	uint8_t lbist_div;
	uint8_t qspi_mem_div;
#ifdef MC_CGM_MUX_0_DC_7_DE_MASK
	uint8_t cm7_core_clk;
#endif
} clock_sys_div_t;

/*
 * clock_init_fxosc
 * @brief	Configuration and initialization sequence of FXOSC
 * @param	Configuration structure pointer
 * @return	Error message
 */
clock_config_error_e clock_init_fxosc(const clock_fxosc_cfg_t * cfg);

/*
 * clock_init_sxosc
 * @brief	Configuration and initialization sequence of SXOSC
 * @param	Configuration structure pointer
 * @return	Error message
 */
clock_config_error_e clock_init_sxosc(void);

/*
 * clock_init_pll
 * @brief	Configuration and initialization sequence of PLL
 * @param	Configuration structure pointer
 * @param 	desire output freq
 * @return	Error message
 * @note 	For PLL initialization, FXOSC must be initialized first calling clock_init_fxosc function.
 */
clock_config_error_e clock_init_pll (clock_pll_cfg_t * pll_cfg, uint32_t output_freq);

#ifdef IP_PLL_AUX
/*
 * clock_init_pll_aux
 * @brief	Configuration and initialization sequence of AUX PLL
 * @param	Configuration structure pointer
 * @param 	desire output freq
 * @return	Error message
 * @note 	For AUX PLL initialization, FXOSC must be initialized first calling clock_init_fxosc function.
 */
clock_config_error_e clock_init_pll_aux (clock_pll_cfg_t * pll_cfg, uint32_t output_freq);
#endif
/*
 * clock_set_core_clock
 * @brief	Sets the core clock source
 * @param	One of @ref clock_core_source_e
 * @param	Core clock divider value
 * @return	Error message
 * @note	If CORE_PLL is selected, PLL must have been initialized calling clock_init_pll function.
 */
clock_config_error_e clock_set_core_clock(clock_core_source_e source, clock_sys_div_t * sys_div);

/*
 * clock_set_clockout
 * @brief	Sets the clockout source and output to monitore clock behaviour
 * @param	Source selector for MUX_6
 * @param	MSCR value of desired GPDO
 * @param	Output divider value
 * @note	Output division results on f/(div + 1)
 */
void clock_set_clockout(uint8_t src, uint8_t gpdo, uint8_t div);

uint8_t clock_pll_get_lol_status(uint8_t pll_instance);
#endif /* CLOCK_CLOCK_H_ */


