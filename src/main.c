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

/**
 *   @file main.c
 *
 *   @addtogroup main_module main module documentation
 *   @{
 */

/* Including necessary configuration files. */
#include "S32K344.h"
#include <stdio.h>
#include "Clock_Ip.h"
#include "Siul2_Port_Ip.h"
#include "Adc_Sar_Ip.h"
#include "Lpspi_Ip.h"
#include "Lpi2c_Ip.h"
#include "fs26.h"
#include "sys.h"
#include "config.h"
#include "common.h"

/* Port Configuration Macros */
#define PORT_PIN_COUNT NUM_OF_CONFIGURED_PINS_PortContainer_0_BOARD_InitPeripherals
#define PORT_CFG_ARRAY g_pin_mux_InitConfigArr_PortContainer_0_BOARD_InitPeripherals

/* Bus Voltage */
#define BUS_VOLTAGE 		(9000U)

/* Initialize I2C pins */
void init_pins_I2C1(void);

/* Initialize the Peripherals */
void Peripherals_Init(void);

/* Initialize the Power Delivery Driver */
uint8_t nx20_interrupts[2];
void Power_Delivery_Init(void);

/* Initialize FS26 interface */
void FS26_Test_init(void);

/* Execute FS26 test */
StatusType FS26_Test_work(uint8_t vSup);

/* ADC Variables */
#define ADC_SAR_USED_CH           (43U) 	/* Channel S19 */
volatile boolean notif_triggered = FALSE;
volatile uint16 ADC_data;


/* ADC Callback function */
void AdcEndOfChainNotif(void)
{
	notif_triggered = TRUE;
	ADC_data = Adc_Sar_Ip_GetConvData(ADCHWUNIT_0_INSTANCE, ADC_SAR_USED_CH);
}


/*!
  \brief The main function for the project.
  \details The startup initialization sequence is the following:
 * - startup asm routine
 * - main()
 */
int main(void)
{
	Clock_Ip_StatusType clockStatus = CLOCK_IP_ERROR;
	uint16_t busVoltage = 0U;

	/* Initialize Clock */
	Clock_Ip_Init(&Clock_Ip_aClockConfig[0]);
	while (clockStatus != CLOCK_IP_SUCCESS)
	{
		clockStatus = Clock_Ip_Init(&Clock_Ip_aClockConfig[0]);
	}

	/* Initialize the Peripherals */
	Peripherals_Init();

	/* Initialize the Power Delivery Driver */
	Power_Delivery_Init();

	/* Initialize FS26 interface */
	FS26_Test_init();

	/* Initialize RGB */
	rgb_init_leds();

	/* Set RGB Cyan as indicator */
	rgb_set_color(COLOR_CYAN);


	for(;;)
	{
		busVoltage = ptn5110_get_vbus_voltage();

		if((busVoltage >= (BUS_VOLTAGE - 500U)) && (busVoltage <= BUS_VOLTAGE + 500U))
		{
			/* Bus Voltage was set correctly */
			rgb_set_color(COLOR_GREEN);
		}
		else
		{
			/* Bus Voltage was not set correctly */
			rgb_set_color(COLOR_RED);
		}

	}
	return 0;
}

/* Initialize the Power Delivery Driver */
void Power_Delivery_Init(void){
	info_PTN5110_t info;
	info_NX20P3483_t info_nx20;

	/*---------------------------------------------------------------------------------------------------------------------*/
	/* Device PTN5 */
	info.address = ADD_PTN5110;
	info.instance_i2c = 1U;
	ptn5110_init(info);

	/*-----------------------------------------MOSFETS - NX20-----------------------------------------*/
	info_nx20.address = ADD_NX20P3483;
	info_nx20.instance_i2c = 1U;

	nx20p3483_init(info_nx20);

	/* 2400 mA */
	nx20p3483_Set5VSourceOCP(2400);

	/* 23 V */
	nx20p3483_SetSinkOVP(23000U);

	nx20p3483_Read_Interrupts(nx20_interrupts);
	/*-----------------------------------------MOSFETS - NX20-----------------------------------------*/
	/* Device PTN5 */
	ptn5110_receive_source_capabilities();

	pd_rdo_fixed_variable_t request;

	request.GiveBack_flag = 0;
	request.maximum_operating_current = 2000;
	request.operating_current = 2000;
	request.voltage_request = BUS_VOLTAGE;

	ptn5110_request_sink(request);

	/* MOSFETS - NX20 */
	nx20p3483_Read_Interrupts(nx20_interrupts);
}

/* Initialize the Peripherals */
void Peripherals_Init(void)
{
	/* Initialize Port Driver (pin Mux) */
	StatusType status = (StatusType) Siul2_Port_Ip_Init(PORT_PIN_COUNT, PORT_CFG_ARRAY);
	while(status != E_OK);

	/* Init I2C Peripheral */
	Lpi2c_Ip_MasterInit(1U, &I2c_Lpi2cMaster_HwChannel1_Channel0);
}

/* Initialize FS26 interface */
void FS26_Test_init()
{
	/* Initialize ADC Driver (pin Mux) */
	StatusType status = (StatusType) Adc_Sar_Ip_Init(ADCHWUNIT_0_INSTANCE, &AdcHwUnit_0);
	while (status != E_OK);

	/* Call Calibration function multiple times, to mitigate instability of board source */
	for(uint8_t Index = 0; Index <= 5; Index++)
	{
		status = (StatusType) Adc_Sar_Ip_DoCalibration(ADCHWUNIT_0_INSTANCE);
		if(status == E_OK)
		{
			break;
		}
	}

	/* Initialize SPI Driver */
	status = (StatusType) Lpspi_Ip_Init(&Lpspi_Ip_PhyUnitConfig_SpiPhyUnit_0_Instance_0);
	while (status != E_OK);

}

/* Execute FS26 test */
StatusType FS26_Test_work(uint8_t vSup)
{
	volatile fs26_status_t status __attribute__((unused));
	fs26_drv_data_t gfs26_drvdata;

	uint16_t AmuxVal = 0;
	double Vsup_voltage = 0.0F;
	double tempVal = 0.0F;
	double ADCrefVoltage = 3.3F;

	//Configure AMUX del FS26
	/* W1C any pending flag in FS_DIAG_SAFETY1/2 registers. */
	status = FS26_WriteRegister((fs26_drv_data_t *) &gfs26_drvdata, true, FS26_FS_DIAG_SAFETY1_ADDR, 0x07FFu);
	status = FS26_WriteRegister((fs26_drv_data_t *) &gfs26_drvdata, true, FS26_FS_DIAG_SAFETY2_ADDR, 0x00FFu);

	/* W1C all OV and UV flags that took place during startup */
	status = FS26_WriteRegister((fs26_drv_data_t *) &gfs26_drvdata, true, FS26_FS_OVUV_REG_STATUS_ADDR, 0xFFFFu);

	/* Disable FCCU monitoring */
	status = FS26_WriteRegister((fs26_drv_data_t *)0UL, true, FS26_FS_I_SAFE_INPUTS_ADDR, 0x0000u);

	/* Configuring AMUX Control*/
	status = FS26_WriteRegister((fs26_drv_data_t *)0UL, false, FS26_M_AMUX_CTRL_ADDR, 0x0051u);
	//51 for VSUP
	//49 for LDO1

	if(status == fs26StatusError)
	{
		return E_NOT_OK;
	}

	for(uint8_t i = 0; i< 100; i++)
	{
		/* Start a SW triggered normal conversion on ADC_SAR */
		Adc_Sar_Ip_StartConversion(ADCHWUNIT_0_INSTANCE, ADC_SAR_IP_CONV_CHAIN_NORMAL);

		/* Wait for the notification to be triggered and read the data */
		while (notif_triggered != TRUE);
		notif_triggered = FALSE;

		AmuxVal = ADC_data;
	}
	tempVal = AmuxVal * ADCrefVoltage;
	Vsup_voltage = ((tempVal)/32768) * (double)2.5F;
	//2.5 for LDO1
	//7.5 for VSUP

	if((Vsup_voltage >= (vSup - (double)0.5F)) && (Vsup_voltage <= vSup + (double)0.5F))
	{
		return E_OK;
	}
	else
	{
		return E_NOT_OK;
	}
}

/* Implementation of the MCU SPI function */
fs26_status_t MCU_SPI_TransferData(uint8_t* txFrame,
		uint16_t frameLengthBytes,
		uint8_t* rxFrame)
{
	static uint32_t txData, rxData;

	while(frameLengthBytes)
	{
		/* Prepare data to be sent */
		txData = *txFrame++;
		txData |= (*txFrame++) << 8u;
		txData |= (*txFrame++) << 16u;
		txData |= (*txFrame++) << 24u;

		/* Transmit data over SPI */
		Lpspi_Ip_SyncTransmit(&Lpspi_Ip_DeviceAttributes_SpiExternalDevice_0_Instance_0, txFrame, rxFrame, frameLengthBytes, 0xFFFF);

		*rxFrame++ = rxData & 0xFFu;
		*rxFrame++ = (rxData >> 8u) & 0xFFu;
		*rxFrame++ = (rxData >> 16u) & 0xFFu;
		*rxFrame++ = (rxData >> 24u) & 0xFFu;

		frameLengthBytes -= 4;
	}

	return fs26StatusOk;
}

/** @} */
