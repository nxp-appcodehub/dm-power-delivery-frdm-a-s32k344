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

#include "fs26.h"
#include "fs26_map.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* Assert macro does nothing */
#define FS_ASSERT(x) ((void)0)

/* This macro updates value of bits specified by the mask. It is assumed      *
 * that value is already shifted.                                             */
#define FS26_BO_SETVAL(data, val, mask)   (((data) & ~(mask)) | (val))

/* This macro updates value of bits specified by the mask. Additionally range *
 * check on the value is performed. It is assumed that value is not shifted.  */
#define FS26_BO_SETVAL_EXT(data, value, mask, shift) \
    (((data) & ~(mask << shift)) | (((value) & (mask)) << (shift)))

/* Data frame (SPI or I2C).                                                    */
#define FS26_COMM_FRAME_SIZE 0x04U  /* Length of the communication frame       */
#define FS26_REG_ADDR_MASK 0x3FU    /* Register address mask                   */
#define FS26_REG_ADDR_SHIFT 0x01U   /* SPI register address shift              */

/* CRC polynomial used for SPI communication.                                  */
#define FS26_CRC_TBL_SIZE 256U      /* Size of CRC table.                      */
#define FS26_COM_CRC_POLYNOM 0x1DU  /* CRC polynom.                            */
#define FS26_COM_CRC_INIT 0xFFU     /* CRC initial value.                      */

typedef enum {
  /* Command type                 */
  fs26RegRead,  /* Register Read  */
  fs26RegWrite  /* Register Write */
} fs26_command_type_t;

typedef struct {
  /* Structure representing transmit data frame.                                            */
  bool isFailSafe;                 /* Main/Fail Safe register selection.                    */
  uint8_t registerAddress;         /* Register address.                                     */
  fs26_command_type_t commandType; /* Command type (R/W).                                   */
  uint16_t writeData;              /* Data to be written to the register                    */
                                   /* If commandType is "read", this value will be ignored. */
} fs26_tx_frame_t;

/*******************************************************************************
 * Constants
 ******************************************************************************/
/* CRC lookup table. */
static const uint8_t FS26_CRC_TABLE[FS26_CRC_TBL_SIZE] = {
  0x00U, 0x1DU, 0x3AU, 0x27U, 0x74U, 0x69U, 0x4EU, 0x53U, 0xE8U, 0xF5U, 0xD2U, 0xCFU, 0x9CU,
  0x81U, 0xA6U, 0xBBU, 0xCDU, 0xD0U, 0xF7U, 0xEAU, 0xB9U, 0xA4U, 0x83U, 0x9EU, 0x25U, 0x38U,
  0x1FU, 0x02U, 0x51U, 0x4CU, 0x6BU, 0x76U, 0x87U, 0x9AU, 0xBDU, 0xA0U, 0xF3U, 0xEEU, 0xC9U,
  0xD4U, 0x6FU, 0x72U, 0x55U, 0x48U, 0x1BU, 0x06U, 0x21U, 0x3CU, 0x4AU, 0x57U, 0x70U, 0x6DU,
  0x3EU, 0x23U, 0x04U, 0x19U, 0xA2U, 0xBFU, 0x98U, 0x85U, 0xD6U, 0xCBU, 0xECU, 0xF1U, 0x13U,
  0x0EU, 0x29U, 0x34U, 0x67U, 0x7AU, 0x5DU, 0x40U, 0xFBU, 0xE6U, 0xC1U, 0xDCU, 0x8FU, 0x92U,
  0xB5U, 0xA8U, 0xDEU, 0xC3U, 0xE4U, 0xF9U, 0xAAU, 0xB7U, 0x90U, 0x8DU, 0x36U, 0x2BU, 0x0CU,
  0x11U, 0x42U, 0x5FU, 0x78U, 0x65U, 0x94U, 0x89U, 0xAEU, 0xB3U, 0xE0U, 0xFDU, 0xDAU, 0xC7U,
  0x7CU, 0x61U, 0x46U, 0x5BU, 0x08U, 0x15U, 0x32U, 0x2FU, 0x59U, 0x44U, 0x63U, 0x7EU, 0x2DU,
  0x30U, 0x17U, 0x0AU, 0xB1U, 0xACU, 0x8BU, 0x96U, 0xC5U, 0xD8U, 0xFFU, 0xE2U, 0x26U, 0x3BU,
  0x1CU, 0x01U, 0x52U, 0x4FU, 0x68U, 0x75U, 0xCEU, 0xD3U, 0xF4U, 0xE9U, 0xBAU, 0xA7U, 0x80U,
  0x9DU, 0xEBU, 0xF6U, 0xD1U, 0xCCU, 0x9FU, 0x82U, 0xA5U, 0xB8U, 0x03U, 0x1EU, 0x39U, 0x24U,
  0x77U, 0x6AU, 0x4DU, 0x50U, 0xA1U, 0xBCU, 0x9BU, 0x86U, 0xD5U, 0xC8U, 0xEFU, 0xF2U, 0x49U,
  0x54U, 0x73U, 0x6EU, 0x3DU, 0x20U, 0x07U, 0x1AU, 0x6CU, 0x71U, 0x56U, 0x4BU, 0x18U, 0x05U,
  0x22U, 0x3FU, 0x84U, 0x99U, 0xBEU, 0xA3U, 0xF0U, 0xEDU, 0xCAU, 0xD7U, 0x35U, 0x28U, 0x0FU,
  0x12U, 0x41U, 0x5CU, 0x7BU, 0x66U, 0xDDU, 0xC0U, 0xE7U, 0xFAU, 0xA9U, 0xB4U, 0x93U, 0x8EU,
  0xF8U, 0xE5U, 0xC2U, 0xDFU, 0x8CU, 0x91U, 0xB6U, 0xABU, 0x10U, 0x0DU, 0x2AU, 0x37U, 0x64U,
  0x79U, 0x5EU, 0x43U, 0xB2U, 0xAFU, 0x88U, 0x95U, 0xC6U, 0xDBU, 0xFCU, 0xE1U, 0x5AU, 0x47U,
  0x60U, 0x7DU, 0x2EU, 0x33U, 0x14U, 0x09U, 0x7FU, 0x62U, 0x45U, 0x58U, 0x0BU, 0x16U, 0x31U,
  0x2CU, 0x97U, 0x8AU, 0xADU, 0xB0U, 0xE3U, 0xFEU, 0xD9U, 0xC4U
};

/*******************************************************************************
 * Private Functions Prototypes
 ******************************************************************************/
/* This function calculates CRC value of passed data array.
 * Takes bytes in inverted order due to frame format.
 * @param [in] data     Data array.
 * @param [in] dataLen  Length of the data array.
 * @return CRC8
 */
static uint8_t FS26_CalcCRC(const uint8_t* data, uint8_t dataLen);

/* Performs CRC check of the data array.
 * CRC is expected in the first array item (index 0).
 * @param [in] data     Data array.
 * @param [in] dataLen  Length of the data array.
 * @return Returns @ref fs26StatusOk if CRC is correct.
 */
static fs26_status_t FS26_CheckCRC(const uint8_t* data, uint8_t dataLen);

/* Performs SPI transfer of the txData. Received frame is saved into rxData structure.
 * @param [in]  txData  TX data.
 * @param [out] rxData  RX data. Can be NULL in case of write-only command.
 * @return @ref fs26_status_t "Status return code."
 */
static fs26_status_t FS26_TransferData(fs26_tx_frame_t* txData, fs26_rx_frame_t* rxData);

/* Creates a raw frame for SPI transfer.
 * @param [in]  txData   TX data.
 * @param [out] txFrame  TX frame for SPI transfer.
 */
static void FS26_CreateSendFrame(fs26_tx_frame_t* txData, uint8_t* txFrame);

/* Reads challenge token (next generated LFSR state) from the SBC. */
static fs26_status_t FS26_WD_ReadChallengeToken(fs26_drv_data_t* drvData, uint16_t* wdToken);

/* Compute Challenger Watchdog answer. */
static uint16_t FS26_WD_ComputeAnswer(uint16_t token);

/*******************************************************************************
 * Private Functions - Implementation
 ******************************************************************************/
/* This function calculates CRC value of passed data array.
 * Takes bytes in inverted order due to frame format. */
static uint8_t FS26_CalcCRC(const uint8_t* data, uint8_t dataLen)
{
uint8_t crc;      /* Result. */
uint8_t tableIdx; /* Index to the CRC table. */
uint8_t dataIdx;  /* Index to the data array (memory). */

  FS_ASSERT(data != NULL);
  FS_ASSERT(dataLen > 0);

  /* Set CRC token value. */
  crc = FS26_COM_CRC_INIT;

  for (dataIdx = dataLen - 1; dataIdx > 0; dataIdx--)
  {
    tableIdx = crc ^ data[dataIdx];
    crc = FS26_CRC_TABLE[tableIdx];
  }

return crc;
}

/* Performs CRC check of the data array. */
static fs26_status_t FS26_CheckCRC(const uint8_t* data, uint8_t dataLen)
{
uint8_t frameCrc;  /* CRC value from resp. */
uint8_t compCrc;   /* Computed CRC value. */

  FS_ASSERT(data != NULL);
  FS_ASSERT(dataLen > 0);

  /* Check CRC. */
  frameCrc = data[0];
  compCrc = FS26_CalcCRC(data, dataLen);

return (compCrc != frameCrc) ? fs26StatusError : fs26StatusOk;
}

/* Performs SPI transfer of the txData. Received frame is saved into
 * rxData structure. */
static fs26_status_t FS26_TransferData(fs26_tx_frame_t* txData, fs26_rx_frame_t* rxData)
{
fs26_status_t status = fs26StatusOk;
uint8_t txFrame[FS26_COMM_FRAME_SIZE] = {0};
uint8_t rxFrame[FS26_COMM_FRAME_SIZE] = {0};

  FS_ASSERT(txData != NULL);

  FS26_CreateSendFrame(txData, txFrame);
  status = MCU_SPI_TransferData(txFrame, FS26_COMM_FRAME_SIZE, rxFrame);
  if (status != fs26StatusOk)
  {
    return status;
  }

  status = FS26_CheckCRC(rxFrame, FS26_COMM_FRAME_SIZE);
  if (status != fs26StatusOk)
  {
    return status;
  }

  if (rxData != NULL)
  {
    rxData->deviceStatus = rxFrame[3];
    rxData->readData = (uint16_t)(rxFrame[2] << 8U | rxFrame[1]);
  }

return status;
}

/* Creates a raw frame for SPI transfer. */
static void FS26_CreateSendFrame(fs26_tx_frame_t* txData, uint8_t* txFrame)
{
  FS_ASSERT(txData != NULL);
  FS_ASSERT(txFrame != NULL);

  /* Selects register set (main x fail-safe). */
  txFrame[3] |= txData->isFailSafe ? 0x80U : 0x00U;

  /* Sets address of the register. */
  txFrame[3] |= FS26_BO_SETVAL_EXT(txFrame[3], txData->registerAddress, \
                FS26_REG_ADDR_MASK, FS26_REG_ADDR_SHIFT);

  /* check if register is r or w */
  switch (txData->commandType)
  {
    case fs26RegRead:
    /* Creates read command. */
    txFrame[3] = FS26_BO_SETVAL(txFrame[3], 0x00U, 0x01U);
    /* No data to be sent. */
    txFrame[2] = 0x00;
    txFrame[1] = 0x00;
    break;

    case fs26RegWrite:
    /* Creates write command. */
    txFrame[3] = FS26_BO_SETVAL(txFrame[3], 0x01U, 0x01U);
    /* Sets data - MSB first. */
    txFrame[2] = (uint8_t)(txData->writeData >> 8);
    txFrame[1] = (uint8_t)(txData->writeData);
    break;
  }

  /* Sets CRC. */
  txFrame[0] = FS26_CalcCRC(txFrame, FS26_COMM_FRAME_SIZE);
}

/* Reads challenge token from the SBC and stores it into the driver data structure. */
static fs26_status_t FS26_WD_ReadChallengeToken(fs26_drv_data_t* drvData, uint16_t* wdToken)
{
  fs26_status_t status = fs26StatusOk;    /* Status variable. */
  fs26_rx_frame_t response;               /* Response to the command. */

  FS_ASSERT(drvData != NULL);

  status = FS26_ReadRegister(drvData, true, FS26_FS_WD_TOKEN_ADDR, &response);
  if (status != fs26StatusOk)
  {
    return status;
  }

  /* Store the watchdog token from the SBC device. */
  *wdToken = response.readData;

return status;
}

/* Compute Challenger Watchdog answer. */
static uint16_t FS26_WD_ComputeAnswer(uint16_t token)
{
  uint32_t mr = token; /* Monitoring result. */

  /* Simulates ALU Checker on the MCU side. */
  mr *= 4U;
  mr += 6U;
  mr -= 4U;
  mr = ~mr;
  mr /= 4U;

return (uint16_t)mr;
}

/*******************************************************************************
 * API - Implementation
 ******************************************************************************/
/** @brief Initializes the FS26 device. */
fs26_status_t FS26_Init(fs26_drv_data_t* drvData, fs26_init_config_t* initConfig, bool changeToken)
{
    fs26_rx_frame_t rxData; /* Response to the command. */
    uint16_t checkMask;     /* Mask for reading of value. */
    uint16_t checkValue;    /* Expected value of the masked bits. */
    uint16_t writeData;     /* Register value to write. */
    fs26_status_t status;

    FS_ASSERT(drvData != NULL);
    FS_ASSERT(initConfig != NULL);

    /* Check LBIST and ABIST1 pass. */
    status = FS26_ReadRegister(drvData, true, FS26_FS_DIAG_SAFETY1_ADDR, &rxData);
    if (status != fs26StatusOk)
    {
        return status;
    }
    checkMask = (FS26_FS_LBIST_STATUS_MASK | FS26_FS_ABIST1_PASS_MASK);
    checkValue = (FS26_FS_LBIST_STATUS_OK | FS26_FS_ABIST1_PASS_PASS);
    if ((rxData.readData & checkMask) != checkValue)
    {
        return fs26StatusError;
    }

    /* Write INIT_FS registers. */
    writeData = (uint16_t) (initConfig->ovuvSafe1Reg.vmonPreOvFs |
            initConfig->ovuvSafe1Reg.vmonPreUvFs |
            initConfig->ovuvSafe1Reg.vmonCoreOvFs |
            initConfig->ovuvSafe1Reg.vmonCoreUvFs |
            initConfig->ovuvSafe1Reg.vmonLdo1OvFs |
            initConfig->ovuvSafe1Reg.vmonLdo1UvFs |
            initConfig->ovuvSafe1Reg.vmonLdo2OvFs |
            initConfig->ovuvSafe1Reg.vmonLdo2UvFs);
    status = FS26_WriteRegisterInit(drvData, FS26_FS_I_OVUV_SAFE_REACTION1_ADDR, writeData);
    if (status != fs26StatusOk)
    {
        return status;
    }

    writeData = (uint16_t) (initConfig->ovuvSafe2Reg.vmonExtOvFs |
            initConfig->ovuvSafe2Reg.vmonExtUvFs |
            initConfig->ovuvSafe2Reg.vmonRefOvFs |
            initConfig->ovuvSafe2Reg.vmonRefUvFs |
            initConfig->ovuvSafe2Reg.vmonTrk2OvFs |
            initConfig->ovuvSafe2Reg.vmonTrk2UvFs |
            initConfig->ovuvSafe2Reg.vmonTrk1OvFs |
            initConfig->ovuvSafe2Reg.vmonTrk1UvFs);
    status = FS26_WriteRegisterInit(drvData, FS26_FS_I_OVUV_SAFE_REACTION2_ADDR, writeData);
    if (status != fs26StatusOk)
    {
        return status;
    }

    writeData = (uint16_t) (initConfig->wdCfgReg.wdErrLimit |
            initConfig->wdCfgReg.wdRfrLimit |
            initConfig->wdCfgReg.wdFs);
    status = FS26_WriteRegisterInit(drvData, FS26_FS_I_WD_CFG_ADDR, writeData);
    if (status != fs26StatusOk)
    {
        return status;
    }

    writeData = (uint16_t) (initConfig->safeInputsReg.fccuCfg |
            initConfig->safeInputsReg.fccu12FltPol |
            initConfig->safeInputsReg.fccu1FltPol |
            initConfig->safeInputsReg.fccu2FltPol |
            initConfig->safeInputsReg.fccu12Fs |
            initConfig->safeInputsReg.fccu1Fs |
            initConfig->safeInputsReg.fccu2Fs |
            initConfig->safeInputsReg.wake2LpPol |
            initConfig->safeInputsReg.errmonFaultPol |
            initConfig->safeInputsReg.errmonAckTime |
            initConfig->safeInputsReg.errmonFs |
            initConfig->safeInputsReg.fccu12Filt);
    status = FS26_WriteRegisterInit(drvData, FS26_FS_I_SAFE_INPUTS_ADDR, writeData);
    if (status != fs26StatusOk)
    {
        return status;
    }

    writeData = (uint16_t) (initConfig->fssmReg.fltErrCntLimit |
            initConfig->fssmReg.fltErrFs |
            initConfig->fssmReg.rstbDur |
            initConfig->fssmReg.backupFs0b |
            initConfig->fssmReg.backupFs1b |
            initConfig->fssmReg.clkMonDis |
            initConfig->fssmReg.dis8s);
    status = FS26_WriteRegisterInit(drvData, FS26_FS_I_FSSM_ADDR, writeData);
    if (status != fs26StatusOk)
    {
        return status;
    }

    writeData = (uint16_t) (initConfig->wdwDurationReg.wdwPeriod |
            initConfig->wdwDurationReg.wdwDc |
            initConfig->wdwDurationReg.wdwRecovery);
    status = FS26_WriteRegisterInit(drvData, FS26_FS_WDW_DURATION_ADDR, writeData);
    if (status != fs26StatusOk)
    {
        return status;
    }

    /* Change watchdog token if requested (during INIT_FS phase for challenger,
     * during open window for simple). */
    if (changeToken == true)
    {
        status = FS26_WD_ChangeToken(drvData, drvData->watchdogToken);
        if (status != fs26StatusOk)
        {
            return status;
        }
    }

    /* Close initialization phase by sending first watchdog refresh. */
    return FS26_WD_Refresh(drvData, NULL);
}

/** @brief Populates default INIT_FS registers configuration. */
void FS26_GetDefaultInitConfig(fs26_init_config_t* initConfig)
{
    FS_ASSERT(initConfig != NULL);

    /* FS_I_OVUV_SAFE_REACTION1 register. */
    initConfig->ovuvSafe1Reg.vmonPreOvFs = FS26_FS_VMON_PRE_OV_FS_REACTION_RSTB_FS0B;
    initConfig->ovuvSafe1Reg.vmonPreUvFs = FS26_FS_VMON_PRE_UV_FS_REACTION_FS0B;
    initConfig->ovuvSafe1Reg.vmonCoreOvFs = FS26_FS_VMON_CORE_OV_FS_REACTION_RSTB_FS0B;
    initConfig->ovuvSafe1Reg.vmonCoreUvFs = FS26_FS_VMON_CORE_UV_FS_REACTION_FS0B;
    initConfig->ovuvSafe1Reg.vmonLdo1OvFs = FS26_FS_VMON_LDO1_OV_FS_REACTION_RSTB_FS0B;
    initConfig->ovuvSafe1Reg.vmonLdo1UvFs = FS26_FS_VMON_LDO1_UV_FS_REACTION_FS0B;
    initConfig->ovuvSafe1Reg.vmonLdo2OvFs = FS26_FS_VMON_LDO2_OV_FS_REACTION_RSTB_FS0B;
    initConfig->ovuvSafe1Reg.vmonLdo2UvFs = FS26_FS_VMON_LDO2_UV_FS_REACTION_FS0B;

    /* FS_I_OVUV_SAFE_REACTION2 register. */
    initConfig->ovuvSafe2Reg.vmonExtOvFs = FS26_FS_VMON_EXT_OV_FS_REACTION_RSTB_FS0B;
    initConfig->ovuvSafe2Reg.vmonExtUvFs = FS26_FS_VMON_EXT_UV_FS_REACTION_FS0B;
    initConfig->ovuvSafe2Reg.vmonRefOvFs = FS26_FS_VMON_REF_OV_FS_REACTION_RSTB_FS0B;
    initConfig->ovuvSafe2Reg.vmonRefUvFs = FS26_FS_VMON_REF_UV_FS_REACTION_FS0B;
    initConfig->ovuvSafe2Reg.vmonTrk2OvFs = FS26_FS_VMON_TRK2_OV_FS_REACTION_RSTB_FS0B;
    initConfig->ovuvSafe2Reg.vmonTrk2UvFs = FS26_FS_VMON_TRK2_UV_FS_REACTION_FS0B;
    initConfig->ovuvSafe2Reg.vmonTrk1OvFs = FS26_FS_VMON_TRK1_OV_FS_REACTION_RSTB_FS0B;
    initConfig->ovuvSafe2Reg.vmonTrk1UvFs = FS26_FS_VMON_TRK1_UV_FS_REACTION_FS0B;

    /* FS_I_WD_CFG register. */
    initConfig->wdCfgReg.wdErrLimit = FS26_FS_WD_ERR_LIMIT_6;
    initConfig->wdCfgReg.wdRfrLimit = FS26_FS_WD_RFR_LIMIT_1;
    initConfig->wdCfgReg.wdFs = FS26_FS_WD_FS_REACTION_RSTB_FS0B;

    /* FS_I_SAFE_INPUTS register. */
    initConfig->safeInputsReg.fccuCfg = FS26_FS_FCCU_CFG_PAIR;
    initConfig->safeInputsReg.fccu12FltPol = FS26_FS_FCCU12_FLT_POL_0_1;
    initConfig->safeInputsReg.fccu1FltPol = FS26_FS_FCCU1_FLT_POL_LOW;
    initConfig->safeInputsReg.fccu2FltPol = FS26_FS_FCCU2_FLT_POL_LOW;
    initConfig->safeInputsReg.fccu12Fs = FS26_FS_FCCU12_FS_REACTION_RSTB_FS0B;
    initConfig->safeInputsReg.fccu1Fs = FS26_FS_FCCU1_FS_REACTION_RSTB_FS0B;
    initConfig->safeInputsReg.fccu2Fs = FS26_FS_FCCU2_FS_REACTION_RSTB_FS0B;
    initConfig->safeInputsReg.wake2LpPol = FS26_FS_WAKE2_LP_POLARITY_LOW;
    initConfig->safeInputsReg.errmonFaultPol = FS26_FS_ERRMON_FLT_POLARITY_LOW;
    initConfig->safeInputsReg.errmonAckTime = FS26_FS_ERRMON_ACK_TIME_8MS;
    initConfig->safeInputsReg.errmonFs = FS26_FS_ERRMON_FS_REACTION_RSTB_FS0B;
    initConfig->safeInputsReg.fccu12Filt = FS26_FS_FCCU12_FILT_6US;

    /* FS_I_FSSM register. */
    initConfig->fssmReg.fltErrCntLimit = FS26_FS_FLT_ERR_CNT_LIMIT_6;
    initConfig->fssmReg.fltErrFs = FS26_FS_FLT_ERR_REACTION_RSTB_FS0B;
    initConfig->fssmReg.rstbDur = FS26_FS_RSTB_DUR_10MS;
    initConfig->fssmReg.backupFs0b = FS26_FS_BACKUP_SAFETY_PATH_FS0B_RSTB;
    initConfig->fssmReg.backupFs1b = FS26_FS_BACKUP_SAFETY_PATH_FS1B_RSTB;
    initConfig->fssmReg.clkMonDis = FS26_FS_CLK_MON_DIS_ACTIVE;
    initConfig->fssmReg.dis8s = FS26_FS_DIS8S_ENABLED;

    /* FS_WDW_DURATION register. */
    initConfig->wdwDurationReg.wdwPeriod = FS26_FS_WDW_PERIOD_3MS;
    initConfig->wdwDurationReg.wdwDc = FS26_FS_WDW_DC_62C_37O;
    initConfig->wdwDurationReg.wdwRecovery = FS26_FS_WDW_RECOVERY_64MS;
}

/* Performs a single read register based on provided address.
 * The response is returned in @ref fs26_rx_frame_t structure. */
fs26_status_t FS26_ReadRegister(fs26_drv_data_t* drvData, bool isFailSafe, uint8_t address,
                                fs26_rx_frame_t* rxData)
{
    fs26_tx_frame_t txData = {
        .registerAddress = address,
        .commandType = fs26RegRead,
        .isFailSafe = isFailSafe };

    FS_ASSERT(drvData != NULL);
    FS_ASSERT(rxData != NULL);

    (void)drvData;

    return FS26_TransferData(&txData, rxData);
}

/* Sends write command to the FS26. */
fs26_status_t FS26_WriteRegister(fs26_drv_data_t* drvData, bool isFailSafe, uint8_t address,
                                 uint16_t writeData)
{
    fs26_tx_frame_t txData = {
        .registerAddress = address,
        .writeData = writeData,
        .commandType = fs26RegWrite,
        .isFailSafe = isFailSafe };

    FS_ASSERT(drvData != NULL);

    (void)drvData;

    return FS26_TransferData(&txData, NULL);
}

/* Performs a write to a single FS26 FS init register (during the INIT_FS phase only). */
fs26_status_t FS26_WriteRegisterInit(fs26_drv_data_t* drvData, uint8_t address,
                                     uint16_t writeData)
{
    fs26_status_t status = fs26StatusOk;
    uint16_t writeDataInv;  /* Inverted register data. */
    uint8_t addressNot;     /* Address of _NOT_ register. */

    FS_ASSERT(drvData != NULL);

    status = FS26_WriteRegister(drvData, true, address, writeData);

    /* _NOT_ registers has address +1 from normal register. */
    addressNot = (uint8_t)(address + 1);
    /* Inverted value should be written to _NOT_ register. */
    writeDataInv = (uint16_t)~writeData;

    status |= FS26_WriteRegister(drvData, true, addressNot, writeDataInv);

    return status;
}

/* Changes token of LFSR used for watchdog. */
fs26_status_t FS26_WD_ChangeToken(fs26_drv_data_t* drvData, uint16_t wdToken)
{
    fs26_status_t status = fs26StatusOk;   /* Status variable. */
    fs26_rx_frame_t rxData;

    FS_ASSERT(drvData != NULL);

    /* Token 0x0000U not allowed, for simple watchdog also 0xFFFFU. */
    if (((drvData->watchdogType == fs26WdSimple) && (wdToken == 0xFFFFU)) || (wdToken == 0x0000U))
    {
        return fs26StatusError;
    }

    status = FS26_WriteRegister(drvData, true, FS26_FS_WD_TOKEN_ADDR, wdToken);
    status |= FS26_ReadRegister(drvData, true, FS26_FS_WD_TOKEN_ADDR, &rxData);
    if (wdToken != rxData.readData)
    {
        status = fs26StatusError;
    }
    else
    {
        drvData->watchdogToken = wdToken;
    }
    return status;
}

/* Performs the watchdog refresh. */
fs26_status_t FS26_WD_Refresh(fs26_drv_data_t* drvData, uint16_t* grlFlags)
{
    fs26_status_t status = fs26StatusError; /* Status variable. */
    uint16_t answer;        /* Calculated monitoring result. */
    fs26_rx_frame_t rxData; /* Register received data. */

    FS_ASSERT(drvData != NULL);

    if (drvData->watchdogType == fs26WdDisabled)
    {
        /* No need to refresh watchdog. */
        status = fs26StatusOk;
    }
    else if (drvData->watchdogType == fs26WdSimple)
    {
        /* Simple watchdog refresh. */
        status = FS26_WriteRegister(drvData, true, FS26_FS_WD_ANSWER_ADDR,
                drvData->watchdogToken);
    }
    else if (drvData->watchdogType == fs26WdChallenger)
    {
        /* Synchronize with LFSR generator on the device. */
        status = FS26_WD_ReadChallengeToken(drvData, &(drvData->watchdogToken));
        if (status != fs26StatusOk)
        {
            return status;
        }
        answer = FS26_WD_ComputeAnswer(drvData->watchdogToken);
        status = FS26_WriteRegister(drvData, true, FS26_FS_WD_ANSWER_ADDR, answer);
    }

    if ((status == fs26StatusOk) && (grlFlags != NULL))
    {

        status = FS26_ReadRegister(drvData, true, FS26_FS_GRL_FLAGS_ADDR, &rxData);
        *grlFlags = rxData.readData;
    }

    return status;
}

/* Reads actual Fault Error Counter value. */
fs26_status_t FS26_GetFaultErrorCounterValue(fs26_drv_data_t* drvData, uint8_t* faultErrorCounterValue)
{
    fs26_status_t status;   /* Status value. */
    fs26_rx_frame_t rxData; /* Register received data. */

    FS_ASSERT(drvData != NULL);
    FS_ASSERT(faultErrorCounterValue != NULL);

    status = FS26_ReadRegister(drvData, true, FS26_FS_I_FSSM_ADDR, &rxData);
    if (status != fs26StatusOk)
    {
        return status;
    }

    *faultErrorCounterValue = (rxData.readData & FS26_FS_FLT_ERR_CNT_MASK) >> FS26_FS_FLT_ERR_CNT_SHIFT;

    return fs26StatusOk;
}

fs26_status_t FS26_FSxB_Release(fs26_drv_data_t* drvData, fs26_fs_output_t fsOutput)
{
    fs26_status_t status;       /* Status variable. */
    fs26_rx_frame_t rxData;     /* Response to the command. */
    uint16_t release_write = 0; /* Value to be written to the FS_RELEASE_FS0B_FS1B register. */
    uint8_t i = 0;              /* Counter. */
    uint16_t diagSafetyMask;    /* Mask for reading of value from the FS_DIAG_SAFETY register. */
    uint16_t diagSafetyValue;   /* FS_DIAG_SAFETY bits defined by the former mask should have this value. */
    uint8_t errorCounter;       /* Fault Error Counter value. */

    FS_ASSERT(drvData != NULL);

    /* Fault Error Counter = 0 */
    status = FS26_GetFaultErrorCounterValue(drvData, &errorCounter);
    if (status != fs26StatusOk)
    {
        return status;
    }
    if (errorCounter > 0)
    {
        return fs26StatusError;
    }

    /* LBIST_OK = ABIST1_OK = ABIST2_OK = 1 */
    status = FS26_ReadRegister(drvData, true, FS26_FS_DIAG_SAFETY1_ADDR, &rxData);
    if (status != fs26StatusOk)
    {
        return status;
    }
    diagSafetyMask = (FS26_FS_LBIST_STATUS_MASK | FS26_FS_ABIST2_PASS_MASK | FS26_FS_ABIST1_PASS_MASK);
    diagSafetyValue = (FS26_FS_LBIST_STATUS_OK | FS26_FS_ABIST2_PASS_PASS | FS26_FS_ABIST1_PASS_PASS);
    if ((rxData.readData & diagSafetyMask) != diagSafetyValue)
    {
        return fs26StatusError;
    }

    /* RELEASE_FS0B_FS1B register filled with ongoing WD_TOKEN reversed and complemented */
    status = FS26_ReadRegister(drvData, true, FS26_FS_WD_TOKEN_ADDR, &rxData);
    if (status != fs26StatusOk)
    {
        return status;
    }

    for (i = 0; i < 16; i++)
    {
        release_write |= (uint16_t)(((rxData.readData >> (15 - i)) & 1U) << i);
    }
    release_write = ~release_write;

    /* Replace bits 15 to 13 with FS outputs code. */
    release_write = (fsOutput & FS26_FS_RELEASE_FS_OUTPUT_MASK) | (release_write & FS26_FS_RELEASE_WD_TOKEN_MASK);

    return FS26_WriteRegister(drvData, true, FS26_FS_RELEASE_FS0B_FS1B_ADDR, release_write);
}

/* Sets state (enable/disable) of the selected voltage regulator. */
fs26_status_t FS26_SetRegulatorState(fs26_drv_data_t* drvData, fs26_reg_output_t vreg, bool enable)
{
    uint16_t shift = (uint16_t)vreg;          /* Shift of the mask for disable value. */
    uint16_t address = FS26_M_REG_CTRL1_ADDR; /* M_REG_CTRL1 register address. */

    FS_ASSERT(drvData != NULL);

    if (!enable)
    {
        address++; /* Disable value is in M_REG_CTRL2 register. */
    }

    /* Register read is not necessary here as a bit value of 0 is ignored anyway. */
    return FS26_WriteRegister(drvData, false, address, (uint16_t)(1U << shift));
}
/******************************************************************************
 * End of module                                                              *
 ******************************************************************************/
