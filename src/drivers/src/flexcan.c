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

#include "flexcan.h"

#define __IO volatile

/*Used to select the LPI2C instance*/
FLEXCAN_Type * volatile flexcan_instance_arr[] = IP_FLEXCAN_BASE_PTRS;

flexcan_status_t flexcan_status_instances = {0, 0, {}};

static flexcan_bit_timming_classic_t bit_timming_500k = {
		5,	/* PRESDIV */
		3,	/* RJW */
		4,	/* PROPSEG */
		5,	/* PSEG1 */
		3	/* PSEG2 */
};

static flexcan_bit_timming_fd_t bit_timming_1M = {
		2,	/* PRESDIV */
		3,	/* RJW */
		4,	/* PROPSEG */
		6,	/* PSEG1 */
		3	/* PSEG2 */
};

static flexcan_bit_timming_fd_t bit_timming_2M = {
		1,	/* PRESDIV */
		2,	/* RJW */
		6,	/* PROPSEG */
		1,	/* PSEG1 */
		2	/* PSEG2 */
};

static flexcan_bit_timming_fd_t bit_timming_4M = {
		1,	/* PRESDIV */
		1,	/* RJW */
		1,	/* PROPSEG */
		1,	/* PSEG1 */
		1	/* PSEG2 */
};

static void flexcan_init_clocks(uint8_t instance)
{
    /* FIRC @48Mhz divider enable for FlexCAN[0:2] */
    IP_MC_CGM -> MUX_3_DC_0 |= MC_CGM_MUX_3_DC_0_DE(1);
    /* FIRC @48Mhz divider enable for FlexCAN[3:7] */
    IP_MC_CGM -> MUX_4_DC_0 |= MC_CGM_MUX_4_DC_0_DE(1);

    if(7 >= instance){
        /*Enables Clock for FlexCan in partition 1*/
        IP_MC_ME->PRTN1_COFB2_CLKEN |= (MC_ME_PRTN1_COFB2_CLKEN_REQ65_MASK << instance);

    	IP_MC_ME->PRTN1_PCONF |= MC_ME_PRTN1_PCONF_PCE(1);				 //Enables clock for IPs in partition 1
    	IP_MC_ME->PRTN1_PUPD |= MC_ME_PRTN1_PUPD_PCUD(1);			     //Triggers HW process for enabling IP clocking in partition 1
    	IP_MC_ME->CTL_KEY = 0x5AF0;										 //Writes KEY
    	IP_MC_ME->CTL_KEY = 0xA50F;										 //Writes ~KEY
    	/* Poll for valid clock gatings FlexCAN0 */
    	while(!(IP_MC_ME -> PRTN1_COFB2_STAT & (MC_ME_PRTN1_COFB2_CLKEN_REQ65_MASK << instance))){}
    }
}

static void flexcan_init_EDE_memory(volatile FLEXCAN_Type *base)
{
    /* Unlock FlexCAN memory for writing */
    base -> CTRL2 |= FLEXCAN_CTRL2_WRMFRZ(1);
    uint32_t addr = (uint32_t)base;
    /* Initialize memory address 0x80 to 0xADF */
    for(uint32_t i = 0x80; i < 0xADF+1; i+=4)
    {
    	*(uint32_t*)(addr + i) = 0;
    }

    /* Initialize memory address 0xC20 to 0x31FF */
    for(uint32_t i = 0xC20; i < 0x31FF + 1; i+=4)
    {
        *(uint32_t*)(addr + i) = 0;
    }

    /* Initialize other required registers */
    base -> RXMGMASK = 0;
    base -> RX14MASK = 0;
    base -> RX15MASK = 0;
    base -> RXFGMASK = 0;

    /* Clear any pending memory error flags */
    base -> ERRSR = 0xFFFFFFFF;
}

uint16_t flexcan_status_instance(uint8_t instance)
{
	uint8_t status = (flexcan_status_instances.status >> instance) & 1U;
	return status;
}

uint16_t flexcan_rx_status_instance(uint8_t instance)
{
	uint16_t status = (flexcan_status_instances.active_rx >> instance) & 1U;
	return status;
}

flexcan_mode_e flexcan_mode_instance(uint8_t instance)
{
	return flexcan_status_instances.mode[instance];
}

void flexcan_init(uint8_t instance, flexcan_mode_e mode, flexcan_bitrate_fd_t bit_rate_fd, uint8_t enable_loopback)
{
	volatile FLEXCAN_Type *base = flexcan_instance_arr[instance];

	flexcan_init_clocks(instance);

	flexcan_status_instances.status |= (1 << instance);

	/*Enables module and transitions to freeze mode*/
	base -> MCR &= ~FLEXCAN_MCR_MDIS_MASK;
	/* Waits to enter freeze mode */
	while(!(base -> MCR & FLEXCAN_MCR_FRZACK_MASK));

	/* Initializes memory*/
	flexcan_init_EDE_memory(base);

	/*CAN_Classic*/
	if(mode == CAN_CLASSIC)
	{
	    /* Enable CAN operation mode */
		base -> MCR |= FLEXCAN_MCR_FDEN(0)		/*Disables CAN FD Operation*/
					|  FLEXCAN_MCR_IRMQ(1)		/*Enables Individual Rx Masking and Queue*/
					|  FLEXCAN_MCR_MAXMB(31)	/*31 Last Message Buffers*/
					|  FLEXCAN_MCR_SRXDIS(0);	/*Enables self-reception*/

	    /* Set baudrate at 500 Kbits/s */
		base -> CTRL1 |= FLEXCAN_CTRL1_PRESDIV(bit_timming_500k.EPRESDIV)
					  |  FLEXCAN_CTRL1_PROPSEG(bit_timming_500k.EPROPSEG)
					  |  FLEXCAN_CTRL1_PSEG1(bit_timming_500k.EPSEG1)
					  |  FLEXCAN_CTRL1_PSEG2(bit_timming_500k.EPSEG2)
					  |  FLEXCAN_CTRL1_RJW(bit_timming_500k.ERJW)
					  |  FLEXCAN_CTRL1_LPB(enable_loopback);

		flexcan_status_instances.mode[instance] = CAN_CLASSIC;
	}
	else if(mode == CAN_FD)
	{
		base->MCR |= FLEXCAN_MCR_FDEN(1) | FLEXCAN_MCR_SRXDIS(0); /*Enables CAN FD Operation and self-reception*/

		/* Enable ISO-11898-1 CAN-FD operation */
		base->CTRL2 |= FLEXCAN_CTRL2_ISOCANFDEN(1);
		/* Setup bit rate switch in data phase for transmission */
		/* Configure 64-bytes of payload per message buffer */
		base->FDCTRL |= FLEXCAN_FDCTRL_FDRATE(1) | FLEXCAN_FDCTRL_MBDSR0(3) | FLEXCAN_FDCTRL_TDCEN(0);
		/* Setup CAN bit timings for 1Mb/s */
		base->CBT |= 	FLEXCAN_CBT_BTF(1)      | 	/*Extended bit time definition enabled*/
					 	FLEXCAN_CBT_EPRESDIV(bit_timming_500k.EPRESDIV) | 	/*Extended Prescaler division factor = 2*/
						FLEXCAN_CBT_EPROPSEG(bit_timming_500k.EPROPSEG) | 	/*Extended propagation segment = 4*/
						FLEXCAN_CBT_EPSEG1(bit_timming_500k.EPSEG1)   | 	/*Extended phase segment 1 = 4*/
						FLEXCAN_CBT_EPSEG2(bit_timming_500k.EPSEG2)   | 	/*Extended phase segment 2 = 4*/
						FLEXCAN_CBT_ERJW(bit_timming_500k.ERJW);		/*Extended Resync Jump Width = 3 + 1*/

		base -> CTRL1 |= FLEXCAN_CTRL1_LPB(enable_loopback);

		if(CAN_FD_1MHz == bit_rate_fd){
			/* Setup CAN bit timings data phase for 1Mb/s */
			base->FDCBT |= 	FLEXCAN_FDCBT_FPRESDIV(bit_timming_1M.FPRESDIV) |
							FLEXCAN_FDCBT_FPROPSEG(bit_timming_1M.FPROPSEG) | /* Doesn't add 1 */
							FLEXCAN_FDCBT_FPSEG1(bit_timming_1M.FPSEG1)   |
							FLEXCAN_FDCBT_FPSEG2(bit_timming_1M.FPSEG2)   |
							FLEXCAN_FDCBT_FRJW(bit_timming_1M.FRJW);
		}
		else if(CAN_FD_2MHz == bit_rate_fd){
			/* Setup CAN bit timings data phase for 2Mb/s */
			base->FDCBT |= 	FLEXCAN_FDCBT_FPRESDIV(bit_timming_2M.FPRESDIV) |
							FLEXCAN_FDCBT_FPROPSEG(bit_timming_2M.FPROPSEG) | /* Doesn't add 1 */
							FLEXCAN_FDCBT_FPSEG1(bit_timming_2M.FPSEG1)   |
							FLEXCAN_FDCBT_FPSEG2(bit_timming_2M.FPSEG2)   |
							FLEXCAN_FDCBT_FRJW(bit_timming_2M.FRJW);
		}
		else if(CAN_FD_4MHz == bit_rate_fd){
			/* Setup CAN bit timings data phase for 2Mb/s */
			base->FDCBT |= 	FLEXCAN_FDCBT_FPRESDIV(bit_timming_4M.FPRESDIV) |
							FLEXCAN_FDCBT_FPROPSEG(bit_timming_4M.FPROPSEG) | /* Doesn't add 1 */
							FLEXCAN_FDCBT_FPSEG1(bit_timming_4M.FPSEG1)   |
							FLEXCAN_FDCBT_FPSEG2(bit_timming_4M.FPSEG2)   |
							FLEXCAN_FDCBT_FRJW(bit_timming_4M.FRJW);
		}

		flexcan_status_instances.mode[instance] = CAN_FD;
	}

    /* Request exit from freeze mode */
	base -> MCR &= ~FLEXCAN_MCR_FRZ_MASK;

    /* Poll for freeze mode exit */
    while(base -> MCR & FLEXCAN_MCR_FRZACK_MASK);
}

void flexcan_install_rx_id(uint8_t instance, uint32_t id)
{
	volatile FLEXCAN_Type *base = flexcan_instance_arr[instance];

	flexcan_mode_e mode = flexcan_status_instances.mode[instance];

	flexcan_status_instances.active_rx |= (1 << instance);

	CAN_MB_Classic_t* mb_classic = (CAN_MB_Classic_t *)((uint32_t)base + 0x80);
	CAN_MB_FD_t * mb_fd = (CAN_MB_FD_t *)((uint32_t)base + 0x80);

    /* Request freeze mode entry for FlexCAN0 */
	base -> MCR |= FLEXCAN_MCR_HALT(1) | FLEXCAN_MCR_FRZ(1);

    /* Poll for freeze mode entry */
    while(!(base -> MCR & FLEXCAN_MCR_FRZACK_MASK)){}

    /* Setup reception mask to all-care bits of 29-bit extended ID */
	base -> RXIMR[1] = 0x1FFFFFFF;

	if(mode == CAN_CLASSIC)
	{
	    /* Setup Message Buffer 1 for reception of frames with the parameter extended ID */
		mb_classic -> Classic_MessageBuffer[1].EDL = 0;
		mb_classic -> Classic_MessageBuffer[1].BRS = 0;
		mb_classic -> Classic_MessageBuffer[1].ESI = 0;
		mb_classic -> Classic_MessageBuffer[1].CODE = 4;
		mb_classic -> Classic_MessageBuffer[1].SRR = 0;
		mb_classic -> Classic_MessageBuffer[1].IDE = 1;
		mb_classic -> Classic_MessageBuffer[1].RTR = 0;
		mb_classic -> Classic_MessageBuffer[1].EXT_ID = id;
	}
	else if(mode == CAN_FD)
	{
	    /* Setup Message Buffer 1 for reception of frames with the parameter extended ID */
		mb_fd->FD_MessageBuffer[1].EDL = 1;
		mb_fd->FD_MessageBuffer[1].BRS = 1;
		mb_fd->FD_MessageBuffer[1].ESI = 0;
		mb_fd->FD_MessageBuffer[1].CODE = 4;
		mb_fd->FD_MessageBuffer[1].SRR = 0;
		mb_fd->FD_MessageBuffer[1].IDE = 1;
		mb_fd->FD_MessageBuffer[1].RTR = 0;
		mb_fd->FD_MessageBuffer[1].DLC = 0xF;
		mb_fd->FD_MessageBuffer[1].EXT_ID = id;
	}

    /* Request exit from freeze mode */
    base -> MCR &= ~FLEXCAN_MCR_FRZ_MASK;

    /* Poll for freeze mode exit */
    while(base -> MCR & FLEXCAN_MCR_FRZACK_MASK);
}

err_poll_e flexcan_read_frame(uint8_t instance, flexcan_frame_t * frame, flexcan_mode_e *mode_flexcan)
{
	volatile FLEXCAN_Type *base = flexcan_instance_arr[instance];

	flexcan_mode_e mode = flexcan_status_instances.mode[instance];
	*mode_flexcan = mode;

	CAN_MB_Classic_t* mb_classic = (CAN_MB_Classic_t *)((uint32_t)base + 0x80);
	CAN_MB_FD_t * mb_fd = (CAN_MB_FD_t *)((uint32_t)base + 0x80);
	uint32_t timeout = 100;
    /* Poll Message Buffer 0 reception flag */
    while(((base -> IFLAG1 & FLEXCAN_IFLAG1_BUF4TO1I_MASK) == 0) && (--timeout != 0)){};
    if(timeout == 0)
    {
    	return TIMEOUT;
    }

    if(mode == CAN_CLASSIC)
    {
        /* Harvest the ID field of the received frame */
    	frame -> ID = mb_classic -> Classic_MessageBuffer[1].EXT_ID;

        /* Harvest the 32-bit high resolution time-stamp */
    	frame -> HIGH_RES_TIMESTAMP = base -> HR_TIME_STAMP[1];

        /* Harvest the payload of the received frame */
    	frame -> PAYLOAD[0] = mb_classic -> Classic_MessageBuffer[1].PAYLOAD[0];
    	frame -> PAYLOAD[1] = mb_classic -> Classic_MessageBuffer[1].PAYLOAD[1];
    }
    else if(mode == CAN_FD)
    {
        /* Harvest the ID field of the received frame */
    	frame -> ID = mb_fd -> FD_MessageBuffer[1].EXT_ID;

        /* Harvest the 32-bit high resolution time-stamp */
    	frame -> HIGH_RES_TIMESTAMP = base -> HR_TIME_STAMP[1];

        /* Harvest the payload of the received frame */
        for(uint8_t i = 0; i<16; i++)
        {
        	frame -> PAYLOAD[i] = mb_fd -> FD_MessageBuffer[1].PAYLOAD[i];
        }
    }
    /* Clear IFLAG1 flag for message buffer 0 (W1C) */
    base -> IFLAG1 = FLEXCAN_IFLAG1_BUF4TO1I(1);

    return NO_ERROR;
}

void flexcan_send_frame(uint8_t instance, flexcan_frame_t * frame)
{
	volatile FLEXCAN_Type *base = flexcan_instance_arr[instance];

	flexcan_mode_e mode = flexcan_status_instances.mode[instance];

	CAN_MB_Classic_t* mb_classic = (CAN_MB_Classic_t *)((uint32_t)base + 0x80);
	CAN_MB_FD_t * mb_fd = (CAN_MB_FD_t *)((uint32_t)base + 0x80);

    if(mode == CAN_CLASSIC)
    {
        /* Fill the frame's payload for transmission */
    	mb_classic -> Classic_MessageBuffer[0].PAYLOAD[0] = frame -> PAYLOAD[0];
    	mb_classic -> Classic_MessageBuffer[0].PAYLOAD[1] = frame -> PAYLOAD[1];

        /* Fill the ID field and other setup bits */
    	mb_classic -> Classic_MessageBuffer[0].EXT_ID = frame->ID;
    	mb_classic -> Classic_MessageBuffer[0].EDL =  0;
    	mb_classic -> Classic_MessageBuffer[0].BRS =  0;
    	mb_classic -> Classic_MessageBuffer[0].ESI =  0;
    	mb_classic -> Classic_MessageBuffer[0].SRR =  0;
    	mb_classic -> Classic_MessageBuffer[0].IDE =  1;
    	mb_classic -> Classic_MessageBuffer[0].RTR =  0;
    	mb_classic -> Classic_MessageBuffer[0].DLC = 0x8;
    	mb_classic -> Classic_MessageBuffer[0].CODE = 0xC; /* Frame is sent when this field is written */
    }
    else if(mode == CAN_FD)
    {
        /* Fill the frame's payload for transmission */
        for(uint8_t i = 0; i<16; i++)
        {
        	mb_fd->FD_MessageBuffer[0].PAYLOAD[i] = frame->PAYLOAD[i];
        }

        /* Fill the ID field and other setup bits */
        mb_fd->FD_MessageBuffer[0].EXT_ID = frame->ID ;
        mb_fd->FD_MessageBuffer[0].EDL =  1;
        mb_fd->FD_MessageBuffer[0].BRS =  1;
        mb_fd->FD_MessageBuffer[0].ESI =  0;
        mb_fd->FD_MessageBuffer[0].SRR =  0;
        mb_fd->FD_MessageBuffer[0].IDE =  1;
        mb_fd->FD_MessageBuffer[0].RTR =  0;
        mb_fd->FD_MessageBuffer[0].DLC = 0xF;
        mb_fd->FD_MessageBuffer[0].CODE = 0xC; /* Frame is sent when this field is written */
    }
	uint32_t timeout = 100000;
    /* After a successful transmission the interrupt flag of the corresponding message buffer is set */
    while(!(base->IFLAG1 & FLEXCAN_IFLAG1_BUF0I_MASK) && (--timeout != 0)){};
    if(timeout == 0)
    {
    	return;
    }
    /* Write 1 to clear the previously set bit flag */
    base->IFLAG1 = FLEXCAN_IFLAG1_BUF0I(1);
}
