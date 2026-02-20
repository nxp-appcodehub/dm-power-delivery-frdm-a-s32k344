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

#include "I2C.h"

#define MC_ME_LPI2C_MASK (MC_ME_PRTN1_COFB2_CLKEN_REQ84_MASK | \
						  MC_ME_PRTN1_COFB2_CLKEN_REQ85_MASK)

/*Used to select the LPI2C instance*/
LPI2C_Type * volatile i2c_instance_arr[] = IP_LPI2C_BASE_PTRS;

uint8_t i2c_status_instances = 0;

uint8_t int_en_flag = 0;
uint8_t rcv_data = 0;

i2c_cfg_t i2c_cfg;

static void i2c_init_clk(uint8_t instance)
{
	IP_MC_ME->PRTN1_COFB2_CLKEN |= (MC_ME_PRTN1_COFB2_CLKEN_REQ84_MASK << instance);

	IP_MC_ME->PRTN1_PCONF |= MC_ME_PRTN1_PCONF_PCE_MASK;
	IP_MC_ME->PRTN1_PUPD  |= MC_ME_PRTN1_PUPD_PCUD_MASK;

	IP_MC_ME->CTL_KEY = 0x5AF0;
	IP_MC_ME->CTL_KEY = 0xA50F;

	/*Waits until Update process is finished*/
	while(IP_MC_ME->PRTN1_PUPD & MC_ME_PRTN1_PUPD_PCUD_MASK);
	while(!(IP_MC_ME->PRTN1_STAT & MC_ME_PRTN1_STAT_PCS_MASK));

}
static void i2c_Ip_BaudRateConfig(LPI2C_Type *BaseAddr,
                                    i2c_Ip_BaudRateType * BaudRate)
{
	/* Set prescaler */
    uint32_t Tmp = BaseAddr->MCFGR1;
    Tmp &= ~(LPI2C_MCFGR1_PRESCALE_MASK);
    Tmp |= LPI2C_MCFGR1_PRESCALE(BaudRate->Prescaler);
    BaseAddr->MCFGR1 = Tmp;

    /* Set hold delay */
    Tmp = BaseAddr->MCCR0;
    Tmp &= ~(LPI2C_MCCR0_SETHOLD_MASK);
    Tmp |= LPI2C_MCCR0_SETHOLD(BaudRate->SetHold);
    BaseAddr->MCCR0 = Tmp;

    /* Set data valid delay */
    Tmp = BaseAddr->MCCR0;
    Tmp &= ~(LPI2C_MCCR0_DATAVD_MASK);
    Tmp |= LPI2C_MCCR0_DATAVD(BaudRate->DataValid);
    BaseAddr->MCCR0 = Tmp;

    /* Set clock HIGH period */
    Tmp = BaseAddr->MCCR0;
    Tmp &= ~(LPI2C_MCCR0_CLKHI_MASK);
    Tmp |= LPI2C_MCCR0_CLKHI(BaudRate->ClkHI);
    BaseAddr->MCCR0 = Tmp;

    /* Set clock low period */
    Tmp = BaseAddr->MCCR0;
    Tmp &= ~(LPI2C_MCCR0_CLKLO_MASK);
    Tmp |= LPI2C_MCCR0_CLKLO(BaudRate->ClkLO);
    BaseAddr->MCCR0 = Tmp;
}

static void i2c_Ip_MasterSetBaudRate(uint8_t instance,
        uint32_t Baudrate,
        uint32_t InputClock){
	uint32_t MinPrescaler = 0U;
	uint32_t Prescaler;
	uint32_t ClkTotal;
	uint32_t ClkLo;
	uint32_t ClkHi;
	uint32_t SetHold;
	uint32_t DataVd;

	i2c_Ip_BaudRateType BaudRateParams;

	const i2c_clk_div PrescalerArr[8U] =
	{
			I2C_CLK_DIV_1,
			I2C_CLK_DIV_2,
			I2C_CLK_DIV_4,
			I2C_CLK_DIV_8,
			I2C_CLK_DIV_16,
			I2C_CLK_DIV_32,
			I2C_CLK_DIV_64,
			I2C_CLK_DIV_128,
	};

	LPI2C_Type *BaseAddr = i2c_instance_arr[instance];

	/* Disable master */
	uint32_t RegValue = (uint32_t)BaseAddr->MCR;
	RegValue &= (~(LPI2C_MCR_MEN_MASK));
	RegValue |= LPI2C_MCR_MEN(0);
	BaseAddr->MCR = (uint32_t)RegValue;

	/* Ignoring the glitch filter, the baud rate formula is:
            SCL_freq = Input_freq / (2^PRESCALER * (CLKLO + CLKHI + 2))
            Assume CLKLO = CLKHI, SETHOLD = CLKHI, DATAVD = CLKHI/2
	 */
	if (Baudrate != 0U)
	{
		/* Compute minimum Prescaler for which CLKLO and CLKHI values are in valid range. Always round up. */
		MinPrescaler = ((InputClock - 1U) / ((Baudrate) * (CLKHI_MAX_VALUE + CLKLO_MAX_VALUE + 2U))) + (uint32_t)1U;
		for (Prescaler = 0U; Prescaler < 7U; Prescaler++)
		{
			if (((uint32_t)1U << Prescaler) >= MinPrescaler)
			{
				break;
			}
		}
		/* Compute CLKLO and CLKHI values for this Prescaler. Round to nearest integer. */
		ClkTotal = (InputClock + ((Baudrate << Prescaler) >> 1U)) / (Baudrate << Prescaler);
	}
	else
	{
		Prescaler = 7U;
		ClkTotal = (CLKHI_MAX_VALUE + CLKLO_MAX_VALUE + 2U);
	}

	if (ClkTotal > (CLKHI_MAX_VALUE + CLKLO_MAX_VALUE + 2U))
	{
		ClkTotal = (CLKHI_MAX_VALUE + CLKLO_MAX_VALUE + 2U);
	}

	/*
	 * If we try to compute clk high and low values using ClkTotal equal with 0
	 * (this is the case when the baudrate is 0), we will get negative values for
	 * them, so we set them to 0 for this case.
	 */
	if (ClkTotal <= 1U)
	{
		ClkHi = 0U;
		ClkLo = 0U;
	}
	else
	{
		ClkHi = (ClkTotal - 2U) / 2U;
		ClkLo = ClkTotal - 2U - ClkHi;
	}

	if (ClkHi < CLKHI_MIN_VALUE)
	{
		ClkHi = CLKHI_MIN_VALUE;
	}
	if (ClkLo < CLKLO_MIN_VALUE)
	{
		ClkLo = CLKLO_MIN_VALUE;
	}

	/* Compute DATAVD and SETHOLD */
	SetHold = ClkHi;
	DataVd = ClkHi >> 1U;
	if (SetHold < SETHOLD_MIN_VALUE)
	{
		SetHold = SETHOLD_MIN_VALUE;
	}
	if (DataVd < DATAVD_MIN_VALUE)
	{
		DataVd = DATAVD_MIN_VALUE;
	}

    /* Init baud rate params */
    BaudRateParams.Prescaler = PrescalerArr[Prescaler];
    BaudRateParams.DataValid = DataVd;
    BaudRateParams.SetHold = SetHold;
    BaudRateParams.ClkHI = ClkHi;
    BaudRateParams.ClkLO = ClkLo;

    /* Apply settings */
    i2c_Ip_BaudRateConfig(BaseAddr, &BaudRateParams);

    /* LPI2C_CFG_2PIN_OPEN_DRAIN */
    uint32_t Tmp = BaseAddr->MCFGR1;
    Tmp &= ~(LPI2C_MCFGR1_PINCFG_MASK);
    Tmp |= LPI2C_MCFGR1_PINCFG(0);
    BaseAddr->MCFGR1 = (uint32_t) Tmp;

    /* LPI2C_NACK_RECEIVE */
    RegValue = (uint32_t)BaseAddr->MCFGR1;
    RegValue &= (~(LPI2C_MCFGR1_IGNACK_MASK));
    RegValue |= LPI2C_MCFGR1_IGNACK(0);
    BaseAddr->MCFGR1 = (uint32_t)RegValue;

    RegValue = (uint32_t)BaseAddr->MCR;
    RegValue &= (~(LPI2C_MCR_MEN_MASK));
    RegValue |= LPI2C_MCR_MEN(1);
    BaseAddr->MCR = (uint32_t)RegValue;
}

uint8_t i2c_status_instance(uint8_t instance)
{
	uint8_t status = (i2c_status_instances >> instance) & 1U;
	return status;
}

void i2c_instance_init(uint8_t instance, uint32_t baudrate){
	if(instance == 0){
		I2C0_Init(baudrate);
	}else if(instance == 1){
		I2C1_Init(baudrate);
	}

	i2c_status_instances |= (1 << instance);
}

int8_t i2c_init(uint8_t instance, i2c_cfg_t *cfg)
{
	i2c_init_clk(instance);

	/* AIPS_SLOW_CLK */
	//uint32_t aips_slow_clk = sys_get_clock(SYS_CLK_AIPS_SLOW);
	uint32_t aips_slow_clk = 40000000;

	if (cfg->mode == I2C_CONTROLLER_MODE)
	{
		/*NOT IMPLEMENTED YET*/
		i2c_instance_arr[instance]->MCR |= LPI2C_MCR_RST_MASK;
		i2c_instance_arr[instance]->MCR = 0x0;
		i2c_instance_arr[instance]->MCFGR1 &= ~LPI2C_MCFGR1_PINCFG_MASK; 	// Choose normal 2 pin mode
		i2c_instance_arr[instance]->MCFGR1 |= LPI2C_MCFGR1_IGNACK_MASK;		// Choose prescaler Divide by 16
//		i2c_instance_arr[instance]->MCCR0 |= LPI2C_MCCR0_DATAVD(9);
//		i2c_instance_arr[instance]->MCCR0 |= LPI2C_MCCR0_SETHOLD(1);
//		i2c_instance_arr[instance]->MCCR0 |= LPI2C_MCCR0_CLKHI(10);
//		i2c_instance_arr[instance]->MCCR0 |= LPI2C_MCCR0_CLKLO(12);
		i2c_instance_arr[instance]->MFCR &= ~LPI2C_MFCR_TXWATER_MASK;
		i2c_instance_arr[instance]->MCR |= LPI2C_MCR_DBGEN_MASK;

		i2c_Ip_MasterSetBaudRate(instance, cfg->baudrate, aips_slow_clk);
		return 0;
	}
	else
	{
		i2c_instance_arr[instance]->SCR &= ~LPI2C_SCR_SEN_MASK;
		i2c_instance_arr[instance]->SCFGR1 |= LPI2C_SCFGR1_ADDRCFG(0)  // Address match 0 (7-bit)
		                  |  LPI2C_SCFGR1_IGNACK(1);      // Slave will end transfer when NACK is detected
		i2c_instance_arr[instance]->SCFGR2  = 0xC0F;
		i2c_instance_arr[instance]->SAMR  = cfg->slave_add << 1;
		i2c_instance_arr[instance]->SIER = 0;
		i2c_instance_arr[instance]->SDER = 0;
		i2c_instance_arr[instance]->SCR |= LPI2C_SCR_SEN_MASK;
		return 0;
	}
	return -1;
}

int8_t i2c_send_data(uint8_t instance, uint8_t add, uint8_t size, uint8_t * data)
{
	/*NOT IMPLEMENTED YET*/
	i2c_instance_arr[instance]->MTDR = (uint32_t)(LPI2C_MTDR_CMD(5) | LPI2C_MTDR_DATA(0x32));
	i2c_instance_arr[instance]->MTDR = (uint32_t)(LPI2C_MTDR_CMD(2) | LPI2C_MTDR_DATA(0x32));
	i2c_instance_arr[instance]->MSR |= (1 << 11);
	return 0;
}

uint8_t i2c_read_data(uint8_t instance)
{

		return i2c_instance_arr[instance] -> SRDR & 0x00FF;
}

void i2c_enable_interrupt(uint8_t instance, i2c_mode_e mode, uint32_t int_flag)
{
	NVIC_SetPriority(LPI2C0_IRQn + instance, 3);
	NVIC_EnableIRQ(LPI2C0_IRQn + instance);

	if (mode == I2C_CONTROLLER_MODE)
	{
		/*NOT IMPLEMENTED YET*/
		return;
	}
	else
	{
		i2c_instance_arr[instance]->SIER = int_flag;
	}
	int_en_flag = 1;
}

uint8_t i2c_receive (uint8_t instance)
{
	int Timeout;
	Timeout=10000;
	while(!(i2c_instance_arr[instance] -> SSR & (1<<1)) && Timeout--) { }

	return i2c_instance_arr[instance] -> SRDR;
}

void I2C0_Init(uint32_t baudrate)
{
#if I2C_PERIPHERAL_PINS_CONFIG_ENABLE == 1
	//PTC9
	IP_SIUL2->MSCR[I2C0_SDA_PIN] |= SIUL2_MSCR_OBE_MASK | SIUL2_MSCR_IBE_MASK
						| SIUL2_MSCR_PUE_MASK | SIUL2_MSCR_PUS_MASK
						| SIUL2_MSCR_SSS_2((I2C0_SDA_MSCR_SSS >> 2) & 1) | SIUL2_MSCR_SSS_1((I2C0_SDA_MSCR_SSS >> 1) & 1) | SIUL2_MSCR_SSS_0((I2C0_SDA_MSCR_SSS >> 0) & 1);		// LPI2C0_SDA
	//PTC8
	IP_SIUL2->MSCR[I2C0_SCL_PIN] |= SIUL2_MSCR_OBE_MASK | SIUL2_MSCR_IBE_MASK
						| SIUL2_MSCR_PUE_MASK | SIUL2_MSCR_PUS_MASK
						| SIUL2_MSCR_SSS_2((I2C0_SCL_MSCR_SSS >> 2) & 1) | SIUL2_MSCR_SSS_1((I2C0_SCL_MSCR_SSS >> 1) & 1) | SIUL2_MSCR_SSS_0((I2C0_SCL_MSCR_SSS >> 0) & 1);		// LPI2C1_SCL

	IP_SIUL2->IMCR[I2C0_SDA_IMCR] |= SIUL2_IMCR_SSS(I2C0_SDA_IMCR_SSS);		// LPI2C0_SDA
	IP_SIUL2->IMCR[I2C0_SCL_IMCR] |= SIUL2_IMCR_SSS(I2C0_SCL_IMCR_SSS);		// LPI2C0_SCL
#endif

	i2c_cfg.mode = I2C_CONTROLLER_MODE;
	i2c_cfg.baudrate = baudrate;
	i2c_init(0, &i2c_cfg);
}

void I2C1_Init(uint32_t baudrate)
{
#if I2C_PERIPHERAL_PINS_CONFIG_ENABLE == 1
	IP_SIUL2->MSCR[I2C1_SDA_PIN] |= SIUL2_MSCR_OBE_MASK | SIUL2_MSCR_IBE_MASK
						| SIUL2_MSCR_PUE_MASK | SIUL2_MSCR_PUS_MASK
						| SIUL2_MSCR_SSS_2((I2C1_SDA_MSCR_SSS >> 2) & 1) | SIUL2_MSCR_SSS_1((I2C1_SDA_MSCR_SSS >> 1) & 1) | SIUL2_MSCR_SSS_0((I2C1_SDA_MSCR_SSS >> 0) & 1);		// LPI2C1_SDA

	IP_SIUL2->MSCR[I2C1_SCL_PIN] |= SIUL2_MSCR_OBE_MASK | SIUL2_MSCR_IBE_MASK
						| SIUL2_MSCR_PUE_MASK | SIUL2_MSCR_PUS_MASK
						| SIUL2_MSCR_SSS_2((I2C1_SCL_MSCR_SSS >> 2) & 1) | SIUL2_MSCR_SSS_1((I2C1_SCL_MSCR_SSS >> 1) & 1) | SIUL2_MSCR_SSS_0((I2C1_SCL_MSCR_SSS >> 0) & 1);		// LPI2C1_SCL

	IP_SIUL2->IMCR[I2C1_SDA_IMCR] |= SIUL2_IMCR_SSS(I2C1_SDA_IMCR_SSS);		// LPI2C1_SDA
	IP_SIUL2->IMCR[I2C1_SCL_IMCR] |= SIUL2_IMCR_SSS(I2C1_SCL_IMCR_SSS);		// LPI2C1_SCL
#endif

	i2c_cfg.mode = I2C_CONTROLLER_MODE;
	i2c_cfg.baudrate = baudrate;
	i2c_init(1, &i2c_cfg);
}

static void LpI2c_ResetFIFOS(uint8_t instance){
	uint32_t aux_32;

	/* Reset Receive and Transmit FIFO */

    aux_32 = i2c_instance_arr[instance]->MCR;
    aux_32 &= (~(LPI2C_MCR_RTF_MASK));
    aux_32 |= LPI2C_MCR_RTF(1U);
    i2c_instance_arr[instance]->MCR = aux_32;

    aux_32 = i2c_instance_arr[instance]->MCR;
    aux_32 &= (~(LPI2C_MCR_RRF_MASK));
    aux_32 |= LPI2C_MCR_RRF(1U);
    i2c_instance_arr[instance]->MCR = aux_32;

}

Lpi2c_StatusType i2cWriteBlocking(uint8_t instance,
								uint16_t slave,
                                uint8_t registerAddr,
                                uint8_t *data,
                                uint8_t num) {
    uint32_t aux_32;
    uint8_t index = 0;
    uint32_t Timeout_I2C = TIMEOUT_I2C;

    /* Transmission */
    i2c_instance_arr[instance]->MTDR = (uint32_t)(LPI2C_MTDR_CMD(4) | LPI2C_MTDR_DATA(slave << 1));
    aux_32 = (i2c_instance_arr[instance]->MFCR & ~(LPI2C_MFCR_TXWATER_MASK));
    aux_32 |= LPI2C_MFCR_TXWATER(0);
    i2c_instance_arr[instance]->MFCR = aux_32;

    while((0 == (i2c_instance_arr[instance]->MSR & LPI2C_MSR_TDF_MASK)) & (Timeout_I2C > 0)){
    	Timeout_I2C--;
    }
    if(0 == Timeout_I2C){
    	i2c_instance_arr[instance]->MTDR = (uint32_t)(LPI2C_MTDR_CMD(2) | LPI2C_MTDR_DATA(0));

    	LpI2c_ResetFIFOS(instance);

        /* Read Status */
        aux_32 = i2c_instance_arr[instance]->MSR;
        i2c_instance_arr[instance]->MSR = aux_32;

    	return LPI2C_STATUS_TIMEOUT;
    }

    i2c_instance_arr[instance]->MTDR = (uint32_t)(LPI2C_MTDR_CMD(0) | LPI2C_MTDR_DATA(registerAddr));

    Timeout_I2C = TIMEOUT_I2C;
    while((0 == (i2c_instance_arr[instance]->MSR & LPI2C_MSR_TDF_MASK)) & (Timeout_I2C > 0)){
    	Timeout_I2C--;
    }
    if(0 == Timeout_I2C){
    	i2c_instance_arr[instance]->MTDR = (uint32_t)(LPI2C_MTDR_CMD(2) | LPI2C_MTDR_DATA(0));

    	LpI2c_ResetFIFOS(instance);

        /* Read Status */
        aux_32 = i2c_instance_arr[instance]->MSR;
        i2c_instance_arr[instance]->MSR = aux_32;

    	return LPI2C_STATUS_TIMEOUT;
    }

    for(index = 0; index < num; index++){
    	i2c_instance_arr[instance]->MTDR = (uint32_t)(LPI2C_MTDR_CMD(0) | LPI2C_MTDR_DATA(*(data + index)));

        while((0 == (i2c_instance_arr[instance]->MSR & LPI2C_MSR_TDF_MASK)) & (Timeout_I2C > 0)){
        	Timeout_I2C--;
        }
        if(0 == Timeout_I2C){
        	i2c_instance_arr[instance]->MTDR = (uint32_t)(LPI2C_MTDR_CMD(2) | LPI2C_MTDR_DATA(0));

        	LpI2c_ResetFIFOS(instance);

            /* Read Status */
            aux_32 = i2c_instance_arr[instance]->MSR;
            i2c_instance_arr[instance]->MSR = aux_32;

        	return LPI2C_STATUS_TIMEOUT;
        }
    }

    i2c_instance_arr[instance]->MTDR = (uint32_t)(LPI2C_MTDR_CMD(2) | LPI2C_MTDR_DATA(0));

    return LPI2C_STATUS_SUCCESS;
}

Lpi2c_StatusType i2cReadBlocking(uint8_t instance,
        						uint16_t slave,
								uint8_t registerAddr,
								uint8_t *data,
								uint8_t num){

	uint8_t number_of_receive = num;
    uint32_t aux_32;
    uint8_t aux_8 = 0;
    uint8_t index = 0;
    uint8_t index_aux = 0;
    uint8_t flag_exit_loop = 0;
    uint32_t Timeout_I2C = TIMEOUT_I2C;
    uint8_t change_RXFIFO = 0;

    /* Transmission */
    i2c_instance_arr[instance]->MTDR = (uint32_t)(LPI2C_MTDR_CMD(4) | LPI2C_MTDR_DATA(slave << 1));
    aux_32 = (i2c_instance_arr[instance]->MFCR & ~(LPI2C_MFCR_TXWATER_MASK));
    aux_32 |= LPI2C_MFCR_TXWATER(0);
    i2c_instance_arr[instance]->MFCR = aux_32;

    Timeout_I2C = TIMEOUT_I2C;
    while((0 == (i2c_instance_arr[instance]->MSR & LPI2C_MSR_TDF_MASK)) & (Timeout_I2C > 0)){
    	Timeout_I2C--;
    }
    if(0 == Timeout_I2C){
    	i2c_instance_arr[instance]->MTDR = (uint32_t)(LPI2C_MTDR_CMD(2) | LPI2C_MTDR_DATA(0));

    	LpI2c_ResetFIFOS(instance);

        /* Read Status */
        aux_32 = i2c_instance_arr[instance]->MSR;
        i2c_instance_arr[instance]->MSR = aux_32;

    	return LPI2C_STATUS_TIMEOUT;
    }

    i2c_instance_arr[instance]->MTDR = (uint32_t)(LPI2C_MTDR_CMD(0) | LPI2C_MTDR_DATA(registerAddr));

    Timeout_I2C = TIMEOUT_I2C;
    while((0 == (i2c_instance_arr[instance]->MSR & LPI2C_MSR_TDF_MASK)) & (Timeout_I2C > 0)){
    	Timeout_I2C--;
    }
    if(0 == Timeout_I2C){
    	i2c_instance_arr[instance]->MTDR = (uint32_t)(LPI2C_MTDR_CMD(2) | LPI2C_MTDR_DATA(0));

    	LpI2c_ResetFIFOS(instance);

        /* Read Status */
        aux_32 = i2c_instance_arr[instance]->MSR;
        i2c_instance_arr[instance]->MSR = aux_32;

    	return LPI2C_STATUS_TIMEOUT;
    }

    i2c_instance_arr[instance]->MTDR = (uint32_t)(LPI2C_MTDR_CMD(2) | LPI2C_MTDR_DATA(0));

    /* Reception */
    i2c_instance_arr[instance]->MTDR = (uint32_t)(LPI2C_MTDR_CMD(4) | LPI2C_MTDR_DATA((slave << 1) | 1));
    aux_32 = (i2c_instance_arr[instance]->MFCR & ~(LPI2C_MFCR_TXWATER_MASK));
    aux_32 |= LPI2C_MFCR_TXWATER(0);
    i2c_instance_arr[instance]->MFCR = aux_32;

    index_aux = 0;

    flag_exit_loop = 0;
    change_RXFIFO = 0;
    while(0 == flag_exit_loop){
    	// We need to check if data of we want to receive is minor of the PARAM of I2C (4 bytes)
    	if(LIMIT_FIFO_RECEIVE >= number_of_receive){

    		aux_32 = i2c_instance_arr[instance]->MFCR & ~(LPI2C_MFCR_RXWATER_MASK);
    		aux_32 |= LPI2C_MFCR_RXWATER(number_of_receive - 1); //Size - 1
    		i2c_instance_arr[instance]->MFCR = aux_32;

    		if(0 == change_RXFIFO){
    			i2c_instance_arr[instance]->MTDR = (uint32_t)(LPI2C_MTDR_CMD(1) | LPI2C_MTDR_DATA(num - 1)); // Size - 1
    			change_RXFIFO = 1;
    		}

    		/* Init reception */
    		Timeout_I2C = TIMEOUT_I2C;
    		while((0 == (i2c_instance_arr[instance]->MSR & LPI2C_MSR_RDF_MASK)) & (Timeout_I2C > 0)){
    			Timeout_I2C--;
    		}
    		if(0 == Timeout_I2C){
    			i2c_instance_arr[instance]->MTDR = (uint32_t)(LPI2C_MTDR_CMD(2) | LPI2C_MTDR_DATA(0));

    			LpI2c_ResetFIFOS(instance);

    			/* Read Status */
    			aux_32 = i2c_instance_arr[instance]->MSR;
    			i2c_instance_arr[instance]->MSR = aux_32;

    			return LPI2C_STATUS_TIMEOUT;
    		}

    		for(index = 0; index < number_of_receive; index++){	// Receive size bytes
    			aux_32 = i2c_instance_arr[instance]->MRDR;
    			aux_32 = LPI2C_MRDR_DATA(aux_32);
    			aux_8 = (uint8_t) aux_32;
    			*(data + index_aux) = aux_8;
    			index_aux++;
    		}

    		flag_exit_loop = 1;
    	}
    	else{
    		aux_32 = i2c_instance_arr[instance]->MFCR & ~(LPI2C_MFCR_RXWATER_MASK);
    		aux_32 |= LPI2C_MFCR_RXWATER(3); //Size - 1
    		i2c_instance_arr[instance]->MFCR = aux_32;

    		if(0 == change_RXFIFO){
    			i2c_instance_arr[instance]->MTDR = (uint32_t)(LPI2C_MTDR_CMD(1) | LPI2C_MTDR_DATA(num - 1)); // Size - 1
    			change_RXFIFO = 1;
    		}

    		/* Init reception */
    		Timeout_I2C = TIMEOUT_I2C;
    		while((0 == (i2c_instance_arr[instance]->MSR & LPI2C_MSR_RDF_MASK)) & (Timeout_I2C > 0)){
    			Timeout_I2C--;
    		}
    		if(0 == Timeout_I2C){
    			i2c_instance_arr[instance]->MTDR = (uint32_t)(LPI2C_MTDR_CMD(2) | LPI2C_MTDR_DATA(0));

    			LpI2c_ResetFIFOS(instance);

    			/* Read Status */
    			aux_32 = i2c_instance_arr[instance]->MSR;
    			i2c_instance_arr[instance]->MSR = aux_32;

    			return LPI2C_STATUS_TIMEOUT;
    		}

    		for(index = 0; index < LIMIT_FIFO_RECEIVE; index++){	// Receive size bytes
    			aux_32 = i2c_instance_arr[instance]->MRDR;
    			aux_32 = LPI2C_MRDR_DATA(aux_32);
    			aux_8 = (uint8_t) aux_32;
    			*(data + index_aux) = aux_8;
    			index_aux++;
    		}

    		number_of_receive = number_of_receive - LIMIT_FIFO_RECEIVE;
    	}
    }

    aux_32 = i2c_instance_arr[instance]->MRDR;

    i2c_instance_arr[instance]->MTDR = (uint32_t)(LPI2C_MTDR_CMD(2) | LPI2C_MTDR_DATA(0));

    return LPI2C_STATUS_SUCCESS;
}
