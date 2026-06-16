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

#ifndef PTN5110_H_
#define PTN5110_H_

#include "usb_pd.h"
#include "ptn5110_register.h"

#include "ptn5110_i2c.h"

#define MAX_OBJECTS_PTN5110		(5U)
#define TRANSFER_SIZE_PTN5110	(8U)
#define SHIFT_8_BITS_PTN5110	(8U)

// Static values
/*! @brief NXP's USB vendor id */
#define PD_VENDOR_ID_NXP	(0x1FC9U)

#define PRODUCT_ID_PTN5110     (0x5110U)

#define DEVICE_ID_PTN5110_A0R1 (0x0000U)
#define DEVICE_ID_PTN5110_A0R2 (0x0001U)
/* DEVICE_ID value 2 is intentionally skipped to align nomenclature */
#define DEVICE_ID_PTN5110_A1R3 (0x0003U)
#define DEVICE_ID_PTN5110_A1R4 (0x0004U)

/* VBus definition */
/* Unit: 25mV, Real value is 800mV as per USBPD R3 V0.91 Table 7-18 Common Source/Sink Electrical Parameters */
/* To pass Ellisys compliance test TD.PD.PC.E2, use 775mv as vSafe0V threshold here. */
#define VBUS_VSAFE0V_MAX_THRESHOLD (31U)
/* Unit: 25mV, Real value is 400mV as per USBPD R3 V0.91 Table 7-18 Common Source/Sink Electrical Parameters */
#define VBUS_VSAFE0V_MIN_THRESHOLD (16U)
/* Unit: 25mV, Real value is 4000mV as per USB3.1 Table 11-2. DC Electrical Characteristics when working as a  upstream
 * connector */
#define VBUS_VSAFE5V_MIN_THRESHOLD (160U)
/* 5.5V */
#define VBUS_VSAFE5V_MAX_THRESHOLD (220U)
/* 3.5V */
#define VBUS_SINK_DISCONNECT_THRESHOLD (140U)
/* 0.6V */
#define VBUS_STOP_DISCHARGE_THRESHOLD (24U)

typedef struct _info_PTN5110
{
	uint8_t instance_i2c;
	uint16_t address;
	uint8_t pd_orientation;
} info_PTN5110_t;

typedef enum _error_init_ptn5110
{
	error_init_nothing,
	error_init_power_status,
} error_init_ptn5110_t;

void ptn5110_init(info_PTN5110_t info);
message_type_t ptn5110_check_received_message(uint8_t* number_bytes_received);
void ptn5110_pdo_identification(uint8_t* array, uint8_t number_objects);
message_type_t ptn5110_message_header(uint8_t* array);
void ptn5110_receive_source_capabilities(void);
void ptn5110_request_data_object(pd_rdo_fixed_variable_t request);
void ptn5110_accept_data_object(void);
void ptn5110_ready_data_object(void);

void ptn5110_request_sink(pd_rdo_fixed_variable_t request);

uint16_t ptn5110_get_vbus_voltage(void);

#endif /* PTN5110_H_ */
