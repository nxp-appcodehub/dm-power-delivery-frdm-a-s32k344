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

#include "ADC_Driver.h"


static ADCx_INITIALIZED_INSTANCES_t ADCx_instances[ADC_INSTANCES] = {0};

//extern char* ADC_ERROR_CODES_STR[] = {
//    "ADC_SUCCESS",
//    "INSTANCE_ALREADY_INITIALIZED",
//    "INSTANCE_ALREADY_UNINITIALIZED",
//    "INSTANCE_UNITIALIZED",
//    "CHANNEL_ALREADY_INITIALIZED",
//    "CHANNEL_UNITIALIZED",
//    "CHANNEL_INVALID",
//    "READING_TIMEOUT",
//    "CALIBRATION_FAILED",
//    "UNKNOWN_ERROR"
//};

uint8_t initADCx(ADCx_t adcNum)
{
	uint8_t status = INSTANCE_ALREADY_INITIALIZED;
	if(ADCx_instances[adcNum].instanceInitialized == 0x00)
	{
		ADCx_instances[adcNum].instanceInitialized = 0x1;
		uint8_t (*initADCfuncs[ADC_INSTANCES])(void) =  {initADC0, initADC1, initADC2};
		status = initADCfuncs[adcNum]();

	}
	return status;
}

uint8_t initADC0(void)
{
	  /* ADC0 Clocking */
	IP_MC_ME->PRTN0_COFB1_CLKEN |= MC_ME_PRTN0_COFB1_CLKEN_REQ40(1); /* REQ40: Analog-to-digital converter 0 */
	IP_MC_ME->PRTN0_PUPD        |= MC_ME_PRTN0_PUPD_PCUD_MASK;       /* PCUD=1: Trigger the hardware process */
	IP_MC_ME->CTL_KEY = 0x5AF0; /* Enter key */
	IP_MC_ME->CTL_KEY = 0xA50F; /* Enter inverted key */
	while(!(IP_MC_ME->PRTN0_COFB1_STAT & MC_ME_PRTN0_COFB1_STAT_BLOCK40_MASK)) { }  /* Wait until ADC_0 clock is running */



	    /* Perform Calibration */
	    /* 1. Select the conversion clock frequency to be within the allowed limits for the calibration.                                                   */
	  IP_ADC_0->MCR &= ~ADC_MCR_ADCLKSEL_MASK;
	  IP_ADC_0->MCR |= ADC_MCR_ADCLKSEL(1);  /* ADCLKSEL=1: Module clock frequency / 2 */

	    /* 3. Configure the Calibration BIST Control and status register (CALBISTREG).
	     *    The default values are set for maximum accuracy (recommended). */
	    /*    The reserved fields should be not be modified */
	  IP_ADC_0->CALBISTREG &= (~ADC_CALBISTREG_RESN_MASK);     /* 14 bit result */
	  IP_ADC_0->CALBISTREG |= ADC_CALBISTREG_TSAMP(3);     /* TSAMP=3: 32 conversion clock cycles */
	  IP_ADC_0->CALBISTREG |= ADC_CALBISTREG_CALSTFUL(1);  /* CALSTFUL=1: All 15 bits are compared */
	  IP_ADC_0->CALBISTREG |= ADC_CALBISTREG_NR_SMPL(3);   /* NR_SMPL=3: 32 samples */
	  IP_ADC_0->CALBISTREG |= ADC_CALBISTREG_AVG_EN(1);    /* AVG_EN=1: Enables averaging during calibration */

	    /* 2. Bring ADC from Power-Down state to active conversion (program PWDN=0b) */
	  IP_ADC_0->MCR &= ~ADC_MCR_PWDN_MASK;  /* Resetting this bit will start ADC transition to IDLE mode */

	    /* 4. Start calibration (program TEST_EN=1b), calibration start immediately. */
	  IP_ADC_0->CALBISTREG |= ADC_CALBISTREG_TEST_EN_MASK;  /* Enable the Calibration (self clearing) */

	    /* 5. Poll the status of C_T_BUSY for 0. (wait until it becomes '0') */
	    while ((IP_ADC_0->CALBISTREG & ADC_CALBISTREG_C_T_BUSY_MASK) != 0 ) { }

	    /* 6. Check the TEST_FAIL to know the final status. If '1' then calibration failed. */
	    if (( IP_ADC_0->CALBISTREG & ADC_CALBISTREG_TEST_FAIL_MASK) != 0 )
	    {
	        return CALIBRATION_FAILED;
	    }

	    /* 7. Check the status of CALIBRTD field. If calibration is successful this field is '1'. */
	    if (( IP_ADC_0->MSR & ADC_MSR_CALIBRTD_MASK) == 0 )
	    {
	        return CALIBRATION_FAILED;
	    }


	  /* ADC0 Set-up */
	  IP_ADC_0->MCR |= ADC_MCR_PWDN_MASK;     /* Power down before initialization */
	  IP_ADC_0->MCR |= ADC_MCR_OWREN_MASK;    /* Enable overwriting older conversion */
	  IP_ADC_0->MCR &= ~ADC_MCR_ADCLKSEL_MASK;
	  IP_ADC_0->MCR |= ADC_MCR_ADCLKSEL(1);  /* ADCLKSEL=1: Module clock frequency / 2 */
	  IP_ADC_0->MCR |= ADC_MCR_MODE_MASK; /* Select Continuous mode */
	  IP_ADC_0->MCR &= ~ADC_MCR_PWDN_MASK; /* Power up */
	  IP_ADC_0->MCR |= ADC_MCR_NSTART_MASK;

	  return ADC_SUCCESS;
}
uint8_t initADC1(void)
{
	  /* ADC1 Clocking */
	IP_MC_ME->PRTN0_COFB1_CLKEN |= MC_ME_PRTN0_COFB1_CLKEN_REQ41(1); /* REQ41: Analog-to-digital converter 1 */
	IP_MC_ME->PRTN0_PUPD        |= MC_ME_PRTN0_PUPD_PCUD_MASK;       /* PCUD=1: Trigger the hardware process */
	IP_MC_ME->CTL_KEY = 0x5AF0; /* Enter key */
	IP_MC_ME->CTL_KEY = 0xA50F; /* Enter inverted key */
	while(!(IP_MC_ME->PRTN0_COFB1_STAT & MC_ME_PRTN0_COFB1_STAT_BLOCK41_MASK)) { }  /* Wait until ADC_1 clock is running */

	    /* Perform Calibration */
	    /* 1. Select the conversion clock frequency to be within the allowed limits for the calibration.                                                   */
	  IP_ADC_1->MCR &= ~ADC_MCR_ADCLKSEL_MASK;
	  IP_ADC_1->MCR |= ADC_MCR_ADCLKSEL(1);  /* ADCLKSEL=1: Module clock frequency / 2 */



	    /* 3. Configure the Calibration BIST Control and status register (CALBISTREG).
	     *    The default values are set for maximum accuracy (recommended). */
	    /*    The reserved fields should be not be modified */
	  IP_ADC_1->CALBISTREG &= (~ADC_CALBISTREG_RESN_MASK);     /* 14 bit result */
	  IP_ADC_1->CALBISTREG |= ADC_CALBISTREG_TSAMP(3);     /* TSAMP=3: 32 conversion clock cycles */
	  IP_ADC_1->CALBISTREG |= ADC_CALBISTREG_CALSTFUL(1);  /* CALSTFUL=1: All 15 bits are compared */
	  IP_ADC_1->CALBISTREG |= ADC_CALBISTREG_NR_SMPL(3);   /* NR_SMPL=3: 32 samples */
	  IP_ADC_1->CALBISTREG |= ADC_CALBISTREG_AVG_EN(1);    /* AVG_EN=1: Enables averaging during calibration */

	    /* 2. Bring ADC from Power-Down state to active conversion (program PWDN=0b) */
	  IP_ADC_1->MCR &= ~ADC_MCR_PWDN_MASK;  /* Resetting this bit will start ADC transition to IDLE mode */
	    /* 4. Start calibration (program TEST_EN=1b), calibration start immediately. */
	  IP_ADC_1->CALBISTREG |= ADC_CALBISTREG_TEST_EN_MASK;  /* Enable the Calibration (self clearing) */

	    /* 5. Poll the status of C_T_BUSY for 0. (wait until it becomes '0') */
	    while ((IP_ADC_1->CALBISTREG & ADC_CALBISTREG_C_T_BUSY_MASK) != 0 ) { }

	    /* 6. Check the TEST_FAIL to know the final status. If '1' then calibration failed. */
	    if (( IP_ADC_1->CALBISTREG & ADC_CALBISTREG_TEST_FAIL_MASK) != 0 )
	    {
	        return CALIBRATION_FAILED;
	    }

	    /* 7. Check the status of CALIBRTD field. If calibration is successful this field is '1'. */
	    if (( IP_ADC_1->MSR & ADC_MSR_CALIBRTD_MASK) == 0 )
	    {
	        return CALIBRATION_FAILED;
	    }


	  /* ADC1 Set-up */
	  IP_ADC_1->MCR |= ADC_MCR_PWDN_MASK;     /* Power down before initialization */
	  IP_ADC_1->MCR |= ADC_MCR_OWREN_MASK;    /* Enable overwriting older conversion */
	  IP_ADC_1->MCR &= ~ADC_MCR_ADCLKSEL_MASK;
	  IP_ADC_1->MCR |= ADC_MCR_ADCLKSEL(1);  /* ADCLKSEL=1: Module clock frequency / 2 */
	  IP_ADC_1->MCR |= ADC_MCR_MODE_MASK; /* Select Continuous mode */

	  return ADC_SUCCESS;
}
uint8_t initADC2(void)
{
	  /* ADC2 Clocking */
	IP_MC_ME->PRTN0_COFB1_CLKEN |= MC_ME_PRTN0_COFB1_CLKEN_REQ42(1); /* REQ42: Analog-to-digital converter 2 */
	IP_MC_ME->PRTN0_PUPD        |= MC_ME_PRTN0_PUPD_PCUD_MASK;       /* PCUD=1: Trigger the hardware process */
	IP_MC_ME->CTL_KEY = 0x5AF0; /* Enter key */
	IP_MC_ME->CTL_KEY = 0xA50F; /* Enter inverted key */
	while(!(IP_MC_ME->PRTN0_COFB1_STAT & MC_ME_PRTN0_COFB1_STAT_BLOCK42_MASK)) { }  /* Wait until ADC_2 clock is running */



	    /* Perform Calibration */
	    /* 1. Select the conversion clock frequency to be within the allowed limits for the calibration.                                                   */
	  IP_ADC_2->MCR &= ~ADC_MCR_ADCLKSEL_MASK;
	  IP_ADC_2->MCR |= ADC_MCR_ADCLKSEL(1);  /* ADCLKSEL=1: Module clock frequency / 2 */



	    /* 3. Configure the Calibration BIST Control and status register (CALBISTREG).
	     *    The default values are set for maximum accuracy (recommended). */
	    /*    The reserved fields should be not be modified */
	  IP_ADC_2->CALBISTREG &= (~ADC_CALBISTREG_RESN_MASK);     /* 14 bit result */
	  IP_ADC_2->CALBISTREG |= ADC_CALBISTREG_TSAMP(3);     /* TSAMP=3: 32 conversion clock cycles */
	  IP_ADC_2->CALBISTREG |= ADC_CALBISTREG_CALSTFUL(1);  /* CALSTFUL=1: All 15 bits are compared */
	  IP_ADC_2->CALBISTREG |= ADC_CALBISTREG_NR_SMPL(3);   /* NR_SMPL=3: 32 samples */
	  IP_ADC_2->CALBISTREG |= ADC_CALBISTREG_AVG_EN(1);    /* AVG_EN=1: Enables averaging during calibration */
	    /* 2. Bring ADC from Power-Down state to active conversion (program PWDN=0b) */
	  IP_ADC_2->MCR &= ~ADC_MCR_PWDN_MASK;  /* Resetting this bit will start ADC transition to IDLE mode */

	    /* 4. Start calibration (program TEST_EN=1b), calibration start immediately. */
	  IP_ADC_2->CALBISTREG |= ADC_CALBISTREG_TEST_EN_MASK;  /* Enable the Calibration (self clearing) */

	    /* 5. Poll the status of C_T_BUSY for 0. (wait until it becomes '0') */
	    while ((IP_ADC_2->CALBISTREG & ADC_CALBISTREG_C_T_BUSY_MASK) != 0 ) { }

	    /* 6. Check the TEST_FAIL to know the final status. If '1' then calibration failed. */
	    if (( IP_ADC_2->CALBISTREG & ADC_CALBISTREG_TEST_FAIL_MASK) != 0 )
	    {
	        return CALIBRATION_FAILED;
	    }

	    /* 7. Check the status of CALIBRTD field. If calibration is successful this field is '1'. */
	    if (( IP_ADC_2->MSR & ADC_MSR_CALIBRTD_MASK) == 0 )
	    {
	        return CALIBRATION_FAILED;
	    }


	  /* ADC2 Set-up */
	  IP_ADC_2->MCR |= ADC_MCR_PWDN_MASK;     /* Power down before initialization */
	  IP_ADC_2->MCR |= ADC_MCR_OWREN_MASK;    /* Enable overwriting older conversion */
	  IP_ADC_2->MCR &= ~ADC_MCR_ADCLKSEL_MASK;
	  IP_ADC_2->MCR |= ADC_MCR_ADCLKSEL(1);  /* ADCLKSEL=1: Module clock frequency / 2 */
	  IP_ADC_2->MCR |= ADC_MCR_MODE_MASK; /* Select Continuous mode */
	  IP_ADC_2->MCR &= ~ADC_MCR_PWDN_MASK; /* Power up */
	  IP_ADC_2->MCR |= ADC_MCR_NSTART_MASK;

	  return ADC_SUCCESS;
}


uint8_t deinitADCx(ADCx_t adcNum)
{
	uint8_t status = INSTANCE_ALREADY_UNINITIALIZED;
	if(ADCx_instances[adcNum].instanceInitialized == 0x01)
	{
		ADCx_instances[adcNum].instanceInitialized = 0x00;
		uint8_t (*deinitADCfuncs[ADC_INSTANCES])(void) =  {deinitADC0, deinitADC1, deinitADC2};
		status = deinitADCfuncs[adcNum]();

	}
	return status;
}

uint8_t deinitADC0(void)
{

	IP_ADC_0->NCMR0 = 0;
	IP_ADC_0->NCMR1 = 0;
	IP_ADC_0->NCMR2 = 0;
	IP_ADC_0->MCR |= ADC_MCR_PWDN_MASK;
	IP_MC_ME->PRTN0_COFB1_CLKEN &= ~MC_ME_PRTN0_COFB1_CLKEN_REQ40(1); /* REQ40: Analog-to-digital converter 0 */
	IP_MC_ME->PRTN0_PUPD        |= MC_ME_PRTN0_PUPD_PCUD_MASK;       /* PCUD=1: Trigger the hardware process */
	IP_MC_ME->CTL_KEY = 0x5AF0; /* Enter key */
	IP_MC_ME->CTL_KEY = 0xA50F; /* Enter inverted key */

	return ADC_SUCCESS;
}
uint8_t deinitADC1(void)
{
	IP_ADC_1->NCMR0 = 0;
	IP_ADC_1->NCMR1 = 0;
	IP_ADC_1->NCMR2 = 0;
	IP_ADC_1->MCR |= ADC_MCR_PWDN_MASK;
	IP_MC_ME->PRTN0_COFB1_CLKEN &= ~MC_ME_PRTN0_COFB1_CLKEN_REQ41(1); /* REQ41: Analog-to-digital converter 1 */
	IP_MC_ME->PRTN0_PUPD        |= MC_ME_PRTN0_PUPD_PCUD_MASK;       /* PCUD=1: Trigger the hardware process */
	IP_MC_ME->CTL_KEY = 0x5AF0; /* Enter key */
	IP_MC_ME->CTL_KEY = 0xA50F; /* Enter inverted key */

	return ADC_SUCCESS;
}
uint8_t deinitADC2(void)
{
	IP_ADC_2->NCMR0 = 0;
	IP_ADC_2->NCMR1 = 0;
	IP_ADC_2->MCR |= ADC_MCR_PWDN_MASK;
	IP_MC_ME->PRTN0_COFB1_CLKEN &= ~MC_ME_PRTN0_COFB1_CLKEN_REQ42(1); /* REQ42: Analog-to-digital converter 2 */
	IP_MC_ME->PRTN0_PUPD        |= MC_ME_PRTN0_PUPD_PCUD_MASK;       /* PCUD=1: Trigger the hardware process */
	IP_MC_ME->CTL_KEY = 0x5AF0; /* Enter key */
	IP_MC_ME->CTL_KEY = 0xA50F; /* Enter inverted key */

	return ADC_SUCCESS;
}


uint8_t initADCx_channels(ADCx_t adcNum, uint8_t channelNum)
{
	uint8_t status = INSTANCE_UNITIALIZED;
	if(ADCx_instances[adcNum].instanceInitialized == 0x1)
	{
		uint8_t (*initADCChannelsFuncs[ADC_INSTANCES])(uint8_t) =  {initADC0_channels, initADC1_channels, initADC2_channels};
		status = initADCChannelsFuncs[adcNum](channelNum);
	}
	return status;
}

uint8_t initADC0_channels(uint8_t channelNum)
{
	IP_ADC_0->MCR |= ADC_MCR_PWDN_MASK;

	uint8_t status = CHANNEL_ALREADY_INITIALIZED;
	if(channelNum <= ADC_PRECISION_CHANNEL_MAX)
	{
		if(	ADCx_instances[0].precisionChannelsInitialized[channelNum] == 0x0)
		{
			//Precision channel
			IP_ADC_0->NCMR0 |= (BIT_1 << channelNum);
			ADCx_instances[0].precisionChannelsInitialized[channelNum] = 0x1;
			status = ADC_SUCCESS;
		}
	}
	else if(ADC_STANDARD_CHANNEL_MIN <= channelNum && channelNum <= ADC_STANDARD_CHANNEL_MAX)
	{
		if(ADCx_instances[0].standardChannelsInitialized[channelNum-ADC_STANDARD_CHANNEL_MIN] == 0x0)
		{
			//Standard channel
			IP_ADC_0->NCMR1 |= (BIT_1 << (channelNum - ADC_STANDARD_CHANNEL_MIN));
			ADCx_instances[0].standardChannelsInitialized[channelNum-ADC_STANDARD_CHANNEL_MIN] = 0x1;
			status = ADC_SUCCESS;
		}
	}
	else if(ADC_EXTERNAL_CHANNEL_MIN <= channelNum && channelNum <= ADC_EXTERNAL_CHANNEL_MAX)
	{
		if(ADCx_instances[0].externalChannelsInitialized[channelNum-ADC_EXTERNAL_CHANNEL_MIN] == 0x0)
		{
			//External channel
			IP_ADC_0->NCMR2 |= (BIT_1 << (channelNum - ADC_EXTERNAL_CHANNEL_MIN));
			ADCx_instances[0].externalChannelsInitialized[channelNum-ADC_EXTERNAL_CHANNEL_MIN] = 0x1;
			status = ADC_SUCCESS;
		}
	}
	else if(IS_SPECIAL_ADC_CHANNEL(channelNum) || channelNum == ADC_ANAMUX_CHANNEL)
	{
		if(ADCx_instances[0].specialChannelsInitialized[channelNum-ADC_STANDARD_CHANNEL_MAX] == 0x0)
		{
			//Standard channel
			IP_ADC_0->NCMR1 |= (BIT_1 << (channelNum - ADC_STANDARD_CHANNEL_MIN));
			ADCx_instances[0].specialChannelsInitialized[channelNum-ADC_STANDARD_CHANNEL_MAX] = 0x1;
			status = ADC_SUCCESS;
		}
	}
	else
	{
		//Channel not supported
		status = CHANNEL_INVALID;
	}
	  IP_ADC_0->MCR &= ~ADC_MCR_PWDN_MASK; /* Power up */
	  IP_ADC_0->MCR |= ADC_MCR_NSTART_MASK;
	return status;

}
uint8_t initADC1_channels(uint8_t channelNum)
{
	IP_ADC_1->MCR |= ADC_MCR_PWDN_MASK;
	uint8_t status = CHANNEL_ALREADY_INITIALIZED;
	if(channelNum <= ADC_PRECISION_CHANNEL_MAX)
	{
		if(	ADCx_instances[1].precisionChannelsInitialized[channelNum] == 0x0)
		{
			//Precision channel
			IP_ADC_1->NCMR0 |= (BIT_1 << channelNum);
			ADCx_instances[1].precisionChannelsInitialized[channelNum] = 0x1;
			status = ADC_SUCCESS;
		}
	}
	else if(ADC_STANDARD_CHANNEL_MIN <= channelNum && channelNum <= ADC_STANDARD_CHANNEL_MAX)
	{
		if(ADCx_instances[1].standardChannelsInitialized[channelNum-ADC_STANDARD_CHANNEL_MIN] == 0x0)
		{
			//Standard channel
			IP_ADC_1->NCMR1 |= (BIT_1 << (channelNum - ADC_STANDARD_CHANNEL_MIN));
			ADCx_instances[1].standardChannelsInitialized[channelNum-ADC_STANDARD_CHANNEL_MIN] = 0x1;
			status = ADC_SUCCESS;
		}
	}
	else if(ADC_EXTERNAL_CHANNEL_MIN <= channelNum && channelNum <= ADC_EXTERNAL_CHANNEL_MAX)
	{
		if(ADCx_instances[1].externalChannelsInitialized[channelNum-ADC_EXTERNAL_CHANNEL_MIN] == 0x0)
		{
			//External channel
			IP_ADC_1->NCMR2 |= (BIT_1 << (channelNum - ADC_EXTERNAL_CHANNEL_MIN));
			ADCx_instances[1].externalChannelsInitialized[channelNum-ADC_EXTERNAL_CHANNEL_MIN] = 0x1;
			status = ADC_SUCCESS;
		}
	}
	else if(IS_SPECIAL_ADC_CHANNEL(channelNum) || channelNum == ADC_ANAMUX_CHANNEL)
	{
		if(ADCx_instances[1].specialChannelsInitialized[channelNum-ADC_STANDARD_CHANNEL_MAX] == 0x0)
		{
			//Standard channel
			IP_ADC_1->NCMR1 |= (BIT_1 << (channelNum - ADC_STANDARD_CHANNEL_MIN));
			ADCx_instances[1].specialChannelsInitialized[channelNum-ADC_STANDARD_CHANNEL_MAX] = 0x1;
			status = ADC_SUCCESS;
		}
	}
	else
	{
		//Channel not supported
		status = CHANNEL_INVALID;
	}
	  IP_ADC_1->MCR &= ~ADC_MCR_PWDN_MASK; /* Power up */
	  IP_ADC_1->MCR |= ADC_MCR_NSTART_MASK;
	return status;
}
uint8_t initADC2_channels(uint8_t channelNum)
{
	IP_ADC_2->MCR |= ADC_MCR_PWDN_MASK;

	uint8_t status = CHANNEL_ALREADY_INITIALIZED;
	if(channelNum <= ADC_PRECISION_CHANNEL_MAX)
	{
		if(	ADCx_instances[2].precisionChannelsInitialized[channelNum] == 0x0)
		{
			//Precision channel
			IP_ADC_2->NCMR0 |= (BIT_1 << channelNum);
			ADCx_instances[2].precisionChannelsInitialized[channelNum] = 0x1;
			status = ADC_SUCCESS;
		}
	}
	else if(ADC_STANDARD_CHANNEL_MIN <= channelNum && channelNum <= ADC_STANDARD_CHANNEL_MAX)
	{
		if(ADCx_instances[2].standardChannelsInitialized[channelNum-ADC_STANDARD_CHANNEL_MIN] == 0x0)
		{
			//Standard channel
			IP_ADC_2->NCMR1 |= (BIT_1 << (channelNum - ADC_STANDARD_CHANNEL_MIN));
			ADCx_instances[2].standardChannelsInitialized[channelNum-ADC_STANDARD_CHANNEL_MIN] = 0x1;
			status = ADC_SUCCESS;
		}
	}
	else if(IS_SPECIAL_ADC_CHANNEL(channelNum) || channelNum == ADC_ANAMUX_CHANNEL)
	{
		if(ADCx_instances[2].specialChannelsInitialized[channelNum-ADC_STANDARD_CHANNEL_MAX] == 0x0)
		{
			//Standard channel
			IP_ADC_2->NCMR1 |= (BIT_1 << (channelNum - ADC_STANDARD_CHANNEL_MIN));
			ADCx_instances[2].specialChannelsInitialized[channelNum-ADC_STANDARD_CHANNEL_MAX] = 0x1;
			status = ADC_SUCCESS;
		}
	}
	else
	{
		//Channel not supported
		status = CHANNEL_INVALID;
	}
	  IP_ADC_2->MCR &= ~ADC_MCR_PWDN_MASK; /* Power up */
	  IP_ADC_2->MCR |= ADC_MCR_NSTART_MASK;
	return status;

}


uint8_t readADCx_channelx(ADCx_t adcNum, uint8_t channelNum, uint16_t *readData)
{
	uint8_t status = INSTANCE_UNITIALIZED;
	if(ADCx_instances[adcNum].instanceInitialized == 0x1)
	{
	uint8_t (*readADCChannelsFuncs[ADC_INSTANCES])(uint8_t, uint16_t*) =  {readADC0_channelx, readADC1_channelx, readADC2_channelx};
	status = readADCChannelsFuncs[adcNum](channelNum, readData);
	}
	return status;
}

uint8_t readADC0_channelx(uint8_t channelNum, uint16_t *readData)
{
    uint8_t status = CHANNEL_UNITIALIZED;

    if (channelNum <= ADC_PRECISION_CHANNEL_MAX)
    {
        // Precision channel
        if (ADCx_instances[0].precisionChannelsInitialized[channelNum] == 0x1)
        {
            uint32_t timeout = 0;
            while (!(IP_ADC_0->CEOCFR0 & (BIT_1 << channelNum)))
            {
                if (++timeout >= TIMEOUT_LIMIT)
                    return READING_TIMEOUT;
            }

            IP_ADC_0->CEOCFR0 |= (BIT_1 << channelNum);
            *readData = ((uint16_t)IP_ADC_0->PCDR[channelNum] & 0x7FFF);
            status = ADC_SUCCESS;
        }
    }
    else if (ADC_STANDARD_CHANNEL_MIN <= channelNum && channelNum <= ADC_STANDARD_CHANNEL_MAX)
    {
        // Standard channel
        uint8_t index = channelNum - ADC_STANDARD_CHANNEL_MIN;
        if (ADCx_instances[0].standardChannelsInitialized[index] == 0x1)
        {
            uint32_t timeout = 0;
            while (!(IP_ADC_0->CEOCFR1 & (BIT_1 << index)))
            {
                if (++timeout >= TIMEOUT_LIMIT)
                    return READING_TIMEOUT;
            }

            IP_ADC_0->CEOCFR1 |= (BIT_1 << channelNum);
            *readData = ((uint16_t)IP_ADC_0->ICDR[index] & 0x7FFF);
            status = ADC_SUCCESS;
        }
    }
    else if (ADC_EXTERNAL_CHANNEL_MIN <= channelNum && channelNum <= ADC_EXTERNAL_CHANNEL_MAX)
    {
        // External channel
        uint8_t index = channelNum - ADC_EXTERNAL_CHANNEL_MIN;
        if (ADCx_instances[0].externalChannelsInitialized[index] == 0x1)
        {
            uint32_t timeout = 0;
            while (!(IP_ADC_0->CEOCFR2 & (BIT_1 << index)))
            {
                if (++timeout >= TIMEOUT_LIMIT)
                    return READING_TIMEOUT;
            }

            IP_ADC_0->CEOCFR2 |= (BIT_1 << channelNum);
            *readData = ((uint16_t)IP_ADC_0->ECDR[index] & 0x7FFF);
            status = ADC_SUCCESS;
        }
    }
    else if (IS_SPECIAL_ADC_CHANNEL(channelNum) || channelNum == ADC_ANAMUX_CHANNEL)
    {
        // Special channel
        uint8_t index = channelNum - ADC_STANDARD_CHANNEL_MAX;
        if (ADCx_instances[0].specialChannelsInitialized[index] == 0x1)
        {
            uint32_t timeout = 0;
            while (!(IP_ADC_0->CEOCFR1 & (BIT_1 << (channelNum - ADC_STANDARD_CHANNEL_MIN))))
            {
                if (++timeout >= TIMEOUT_LIMIT)
                    return READING_TIMEOUT;
            }

            IP_ADC_0->CEOCFR1 |= (BIT_1 << (channelNum - ADC_STANDARD_CHANNEL_MIN));
            *readData = ((uint16_t)IP_ADC_0->ICDR[channelNum - ADC_STANDARD_CHANNEL_MIN] & 0x7FFF);
            status = ADC_SUCCESS;
        }
    }
    else
    {
        // Channel not supported
        status = CHANNEL_INVALID;
    }

    return status;
}
uint8_t readADC1_channelx(uint8_t channelNum, uint16_t *readData)
{
    uint8_t status = CHANNEL_UNITIALIZED;

    if (channelNum <= ADC_PRECISION_CHANNEL_MAX)
    {
        if (ADCx_instances[1].precisionChannelsInitialized[channelNum] == 0x1)
        {
            uint32_t timeout = 0;
            while (!(IP_ADC_1->CEOCFR0 & (BIT_1 << channelNum)))
            {
                if (++timeout >= TIMEOUT_LIMIT)
                    return READING_TIMEOUT;
            }

            IP_ADC_1->CEOCFR0 |= (BIT_1 << channelNum);
            *readData = ((uint16_t)IP_ADC_1->PCDR[channelNum] & 0x7FFF);
            status = ADC_SUCCESS;
        }
    }
    else if (ADC_STANDARD_CHANNEL_MIN <= channelNum && channelNum <= ADC_STANDARD_CHANNEL_MAX)
    {
        uint8_t index = channelNum - ADC_STANDARD_CHANNEL_MIN;
        if (ADCx_instances[1].standardChannelsInitialized[index] == 0x1)
        {
            uint32_t timeout = 0;
            while (!(IP_ADC_1->CEOCFR1 & (BIT_1 << index)))
            {
                if (++timeout >= TIMEOUT_LIMIT)
                    return READING_TIMEOUT;
            }

            IP_ADC_1->CEOCFR1 |= (BIT_1 << channelNum);
            *readData = ((uint16_t)IP_ADC_1->ICDR[index] & 0x7FFF);
            status = ADC_SUCCESS;
        }
    }
    else if (ADC_EXTERNAL_CHANNEL_MIN <= channelNum && channelNum <= ADC_EXTERNAL_CHANNEL_MAX)
    {
        uint8_t index = channelNum - ADC_EXTERNAL_CHANNEL_MIN;
        if (ADCx_instances[1].externalChannelsInitialized[index] == 0x1)
        {
            uint32_t timeout = 0;
            while (!(IP_ADC_1->CEOCFR2 & (BIT_1 << index)))
            {
                if (++timeout >= TIMEOUT_LIMIT)
                    return READING_TIMEOUT;
            }

            IP_ADC_1->CEOCFR2 |= (BIT_1 << channelNum);
            *readData = ((uint16_t)IP_ADC_1->ECDR[index] & 0x7FFF);
            status = ADC_SUCCESS;
        }
    }
    else if (IS_SPECIAL_ADC_CHANNEL(channelNum))
    {
        uint8_t index = channelNum - ADC_STANDARD_CHANNEL_MAX;
        if (ADCx_instances[1].specialChannelsInitialized[index] == 0x1)
        {
            uint32_t timeout = 0;
            while (!(IP_ADC_1->CEOCFR1 & (BIT_1 << (channelNum - ADC_STANDARD_CHANNEL_MIN))))
            {
                if (++timeout >= TIMEOUT_LIMIT)
                    return READING_TIMEOUT;
            }

            IP_ADC_1->CEOCFR1 |= (BIT_1 << (channelNum - ADC_STANDARD_CHANNEL_MIN));
            *readData = ((uint16_t)IP_ADC_1->ICDR[channelNum - ADC_STANDARD_CHANNEL_MIN] & 0x7FFF);
            status = ADC_SUCCESS;
        }
    }
    else
    {
        status = CHANNEL_INVALID;
    }

    return status;
}
uint8_t readADC2_channelx(uint8_t channelNum, uint16_t *readData)
{
    uint8_t status = CHANNEL_UNITIALIZED;

    if (channelNum <= ADC_PRECISION_CHANNEL_MAX)
    {
        if (ADCx_instances[2].precisionChannelsInitialized[channelNum] == 0x1)
        {
            uint32_t timeout = 0;
            while (!(IP_ADC_2->CEOCFR0 & (BIT_1 << channelNum)))
            {
                if (++timeout >= TIMEOUT_LIMIT)
                    return READING_TIMEOUT;
            }

            IP_ADC_2->CEOCFR0 |= (BIT_1 << channelNum);
            *readData = ((uint16_t)IP_ADC_2->PCDR[channelNum] & 0x7FFF);
            status = ADC_SUCCESS;
        }
    }
    else if (ADC_STANDARD_CHANNEL_MIN <= channelNum && channelNum <= ADC_STANDARD_CHANNEL_MAX)
    {
        uint8_t index = channelNum - ADC_STANDARD_CHANNEL_MIN;
        if (ADCx_instances[2].standardChannelsInitialized[index] == 0x1)
        {
            uint32_t timeout = 0;
            while (!(IP_ADC_2->CEOCFR1 & (BIT_1 << index)))
            {
                if (++timeout >= TIMEOUT_LIMIT)
                    return READING_TIMEOUT;
            }

            IP_ADC_2->CEOCFR1 |= (BIT_1 << channelNum);
            *readData = ((uint16_t)IP_ADC_2->ICDR[index] & 0x7FFF);
            status = ADC_SUCCESS;
        }
    }
    else if (IS_SPECIAL_ADC_CHANNEL(channelNum))
    {
        uint8_t index = channelNum - ADC_STANDARD_CHANNEL_MAX;
        if (ADCx_instances[2].specialChannelsInitialized[index] == 0x1)
        {
            uint32_t timeout = 0;
            while (!(IP_ADC_2->CEOCFR1 & (BIT_1 << (channelNum - ADC_STANDARD_CHANNEL_MIN))))
            {
                if (++timeout >= TIMEOUT_LIMIT)
                    return READING_TIMEOUT;
            }

            IP_ADC_2->CEOCFR1 |= (BIT_1 << (channelNum - ADC_STANDARD_CHANNEL_MIN));
            *readData = ((uint16_t)IP_ADC_2->ICDR[channelNum - ADC_STANDARD_CHANNEL_MIN] & 0x7FFF);
            status = ADC_SUCCESS;
        }
    }
    else
    {
        status = CHANNEL_INVALID;
    }

    return status;
}

