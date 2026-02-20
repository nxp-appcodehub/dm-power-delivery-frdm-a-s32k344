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

#ifndef USB_PD_H_
#define USB_PD_H_

#include "stdint.h"

#define PD_MSG_HEADER_NUMBER_OF_DATA_OBJECTS_POS  (12U)
#define PD_MSG_HEADER_NUMBER_OF_DATA_OBJECTS_MASK (0x7000u)
#define PD_MSG_HEADER_PORT_POWER_ROLE_POS         (8U)
#define PD_MSG_HEADER_PORT_POWER_ROLE_MASK        (0x0100u)
#define PD_MSG_HEADER_SPEC_REV_POS                (6U)
#define PD_MSG_HEADER_PORT_DATA_ROLE_POS          (5U)
#define PD_MSG_HEADER_PORT_DATA_ROLE_MASK         (0x0020u)
#define PD_MSG_HEADER_MESSAGE_TYPE_POS            (0U)
#define PD_MSG_HEADER_MESSAGE_TYPE_MASK           (0x001Fu)
#define PD_MSG_HEADER_EXTENDED_MASK               (0x8000u)
#define PD_MSG_HEADER_EXTENDED_POS                (15U)

#define PD_MSG_EXT_HEADER_CHUNKED_MASK       (0x8000u)
#define PD_MSG_EXT_HEADER_CHUNKED_POS        (15U)
#define PD_MSG_EXT_HEADER_CHUNK_NUMBER_MASK  (0x7800u)
#define PD_MSG_EXT_HEADER_CHUNK_NUMBER_POS   (11U)
#define PD_MSG_EXT_HEADER_REQUEST_CHUNK_MASK (0x0400u)
#define PD_MSG_EXT_HEADER_REQUEST_CHUNK_POS  (10U)
#define PD_MSG_EXT_HEADER_DATA_SIZE_MASK     (0x01FFu)
#define PD_MSG_EXT_HEADER_DATA_SIZE_POS      (0U)

#define PD_MSG_CONTROL_TYPE_MASK (0x00u)
#define PD_MSG_DATA_TYPE_MASK    (0x80u)
#define PD_MSG_EXT_TYPE_MASK     (0xC0u)
#define PD_MSG_TYPE_BITS_MASK    (0xC0u)
#define PD_MSG_TYPE_VALUE_MASK   (0x3Fu)

/*! @brief source/sink capability's voltage unit is 50mV */
#define PD_PDO_VOLTAGE_UNIT (50U)
/*! @brief source/sink capability's current unit is 10mA */
#define PD_PDO_CURRENT_UNIT (10U)
/*! @brief source/sink capability's power unit is 250mW */
#define PD_PDO_POWER_UNIT (250U)
/*! @brief source/sink APDO capability's voltage unit is 100mV */
#define PD_APDO_VOLTAGE_UNIT (100U)
/*! @brief source/sink APDO capability's current unit is 50mA */
#define PD_APDO_CURRENT_UNIT (50U)
/*! @brief Programmable Request Data Object's voltage unit is 20mV */
#define PD_PRDO_VOLTAGE_UNIT (20U)
/*! @brief Programmable Request Data Object's current unit is 50mA */
#define PD_PRDO_CURRENT_UNIT (50U)

/*! @brief minimum voltage capability is 1mV */
#define PD_MIN_VOLTAGE		(5000U)

typedef enum _pd_message_type
{
	kControl_Message,
	kData_Message
} pd_message_type_t;

typedef enum _message_type
{
    kPD_MsgInvalid              = 0x00u,
    kPD_MsgGoodCRC              = 0x01u,
    kPD_MsgGotoMin              = 0x02u,
    kPD_MsgAccept               = 0x03u,
    kPD_MsgReject               = 0x04u,
    kPD_MsgPing                 = 0x05u,
    kPD_MsgPsRdy                = 0x06u,
    kPD_MsgGetSourceCap         = 0x07u,
    kPD_MsgGetSinkCap           = 0x08u,
    kPD_MsgDrSwap               = 0x09u,
    kPD_MsgPrSwap               = 0x0Au,
    kPD_MsgVconnSwap            = 0x0Bu,
    kPD_MsgWait                 = 0x0Cu,
    kPD_MsgSoftReset            = 0x0Du,
    kPD_MsgReserved1            = 0x0Eu,
    kPD_MsgReserved2            = 0x0Fu,
    kPD_MsgNotSupported         = 0x10u,
    kPD_MsgGetSourceCapExtended = 0x11u,
    kPD_MsgGetStatus            = 0x12u,
    kPD_MsgFrSwap               = 0x13u,
    kPD_MsgGetPpsStatus         = 0x14u,
    kPD_MsgSourceCapabilities   = (PD_MSG_DATA_TYPE_MASK | 0x01u),
    kPD_MsgRequest              = (PD_MSG_DATA_TYPE_MASK | 0x02u),
    kPD_MsgBIST                 = (PD_MSG_DATA_TYPE_MASK | 0x03u),
    kPD_MsgSinkCapabilities     = (PD_MSG_DATA_TYPE_MASK | 0x04u),
    kPD_MsgBatteryStatus        = (PD_MSG_DATA_TYPE_MASK | 0x05u),
    kPD_MsgAlert                = (PD_MSG_DATA_TYPE_MASK | 0x06u),
    kPD_MsgVendorDefined        = (PD_MSG_DATA_TYPE_MASK | 0x0Fu),

    kPD_MsgSourceCapExtended      = (PD_MSG_EXT_TYPE_MASK | 0x01u),
    kPD_MsgStatus                 = (PD_MSG_EXT_TYPE_MASK | 0x02u),
    kPD_MsgGetBatteryCap          = (PD_MSG_EXT_TYPE_MASK | 0x03u),
    kPD_MsgGetBatteryStatus       = (PD_MSG_EXT_TYPE_MASK | 0x04u),
    kPD_MsgBatteryCapabilities    = (PD_MSG_EXT_TYPE_MASK | 0x05u),
    kPD_MsgGetManufacturerInfo    = (PD_MSG_EXT_TYPE_MASK | 0x06u),
    kPD_MsgManufacturerInfo       = (PD_MSG_EXT_TYPE_MASK | 0x07u),
    kPD_MsgSecurityRequest        = (PD_MSG_EXT_TYPE_MASK | 0x08u),
    kPD_MsgSecurityResponse       = (PD_MSG_EXT_TYPE_MASK | 0x09u),
    kPD_MsgFirmwareUpdateRequest  = (PD_MSG_EXT_TYPE_MASK | 0x0Au),
    kPD_MsgFirmwareUpdaetResponse = (PD_MSG_EXT_TYPE_MASK | 0x0Bu),
    kPD_MsgPpsStatus              = (PD_MSG_EXT_TYPE_MASK | 0x0Cu),

	kPD_MsgNotMessage			= 0xFFu,
} message_type_t;

/**
 * @brief pdo type
 */
typedef enum _pd_pdo_type
{
    /*! Fixed pdo */
    kPDO_Fixed = 0x00u,
    /*! Battery pdo */
    kPDO_Battery = 0x01u,
    /*! Variable pdo */
    kPDO_Variable = 0x02u,
    /*! Augmented Power Data Object pdo */
    kPDO_APDO = 0x03u
} pd_pdo_type_t;

typedef enum _pd_plug_orientation
{
	kPlug_Orientation_CC1		= 0x00u,
	kPlug_Orientation_CC2		= 0x01u,
	kPlus_Orientation_Nothing	= 0x02u,
} pd_plug_orientation_t;

/**
 * @brief fixed source PDO
 */
typedef struct _pd_source_fixed_pdo
{
    uint16_t maxCurrent : 10;              /*!< max current, unit is 10mA */
    uint16_t voltage : 10;                 /*!< voltage value, unit is 50mV */
    uint16_t peakCurrent : 2;              /*!< peak current */
    uint16_t reserved : 3;                 /*!< reserved field */
    //uint16_t unchunkedSupported : 1;       /*!< unchunked is supported or not */
    uint16_t dualRoleData : 1;             /*!< dual data role */
    uint16_t usbCommunicationsCapable : 1; /*!< usb communication capable or not */
    //uint16_t externalPowered : 1;          /*!< external powered */
    uint16_t unconstrainedPower : 1;          /*!< unconstrained Power */
    uint16_t usbSuspendSupported : 1;      /*!< usb suspend supported or not */
    uint16_t dualRolePower : 1;            /*!< dual power role */
    pd_pdo_type_t fixedSupply : 2;              /*!< pdo type */
} pd_source_fixed_pdo_t;

/**
 * @brief variable source PDO
 */
typedef struct _pd_source_variable_pdo
{
    uint16_t maxCurrent : 10;    /*!< max current */
    uint16_t minVoltage : 10;    /*!< min voltage */
    uint16_t maxVoltage : 10;    /*!< max voltage */
    pd_pdo_type_t variableSupply : 2; /*!< pdo type */
} pd_source_variable_pdo_t;

/**
 * @brief battery source PDO
 */
typedef struct _pd_source_battery_pdo
{
    uint16_t maxAllowPower : 10; /*!< max power */
    uint16_t minVoltage : 10;    /*!< min voltage */
    uint16_t maxVoltage : 10;    /*!< max voltage */
    pd_pdo_type_t battery : 2;        /*!< pdo type */
} pd_source_battery_pdo_t;

/**
 * @brief APDO PDO
 */
typedef struct _pd_source_apdo_pdo
{
    uint16_t maxCurrent : 7; /*!< max current (50mA increments) */
    uint16_t reserved1 : 1;
    uint16_t minVoltage : 8; /*!< min voltage (100mV increments) */
    uint16_t reserved2 : 1;
    uint16_t maxVoltage : 8; /*!< max voltage (100mV increments) */
    uint16_t reserved3 : 3;
    uint16_t APDOType : 2;   /*!< APDO type */
    pd_pdo_type_t APDOSupply : 2; /*!< pdo type */
} pd_source_apdo_pdo_t;

/**
 * @brief source PDO union
 */
typedef struct _pd_source_pdo
{
    union
    {
        //pd_pdo_common_t commonPDO;            /*!< union, common pdo */
        pd_source_fixed_pdo_t fixedPDO;       /*!< union, fixed pdo */
        pd_source_variable_pdo_t variablePDO; /*!< union, variable pdo */
        pd_source_battery_pdo_t batteryPDO;   /*!< union, battery pdo */
        pd_source_apdo_pdo_t apdoPDO;         /*!< union, APDO pdo */
    }_pd_source_pdo_union;
} pd_source_pdo_t;

/**
 * @brief fixed sink PDO
 */
typedef struct _pd_sink_fixed_pdo
{
    uint32_t operateCurrent : 10;          /*!< operate current */
    uint32_t voltage : 10;                 /*!< voltage */
    uint32_t reserved : 3;                 /*!< reserved */
    uint32_t frSwapRequiredCurrent : 2;    /*!< The value is #pd_fr_swap_current_t value */
    uint32_t dualRoleData : 1;             /*!< dual data role */
    uint32_t usbCommunicationsCapable : 1; /*!< usb communication capable or not */
    uint32_t externalPowered : 1;          /*!< external powered */
    uint32_t higherCapability : 1;         /*!< higher capability */
    uint32_t dualRolePower : 1;            /*!< dual power role */
    uint32_t fixedSupply : 2;              /*!< pdo type */
} pd_sink_fixed_pdo_t;




typedef struct _pd_rdo_fixed_variable
{
	uint8_t GiveBack_flag;
	uint16_t operating_current;
	uint16_t maximum_operating_current;
	uint16_t voltage_request;
} pd_rdo_fixed_variable_t;

#endif /* USB_PD_H_ */
