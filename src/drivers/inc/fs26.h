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

#ifndef DRIVERS_FS26_FS26_H_
#define DRIVERS_FS26_FS26_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "common.h"
#include "fs26_map.h"
#include "Lpspi_Ip.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
typedef enum {
/**  Status return codes.                                 */
  fs26StatusOk    = 0U, /**< No error.                    */
  fs26StatusError = 1U  /**< Error.                       */
} fs26_status_t;

typedef enum {
/**  Watchdog type.                                       */
  fs26WdDisabled   = 0U, /**< Watchdog refresh disabled   */
  fs26WdSimple     = 1U, /**< Simple watchdog refresh     */
  fs26WdChallenger = 2U  /**< Challenger watchdog refresh */
} fs26_watchdog_type_t;

typedef enum {
/**  FS output to release.                                                        *
 *  Can be used with function @ref FS26_FSxB_Release().                           */
  fs26FS0b   = FS26_FS_RELEASE_OUTPUT_FS0B,       /**< FS0b output                */
  fs26FS1b   = FS26_FS_RELEASE_OUTPUT_FS1B,       /**< FS1b output                */
  fs26FSboth = FS26_FS_RELEASE_OUTPUT_FS0B_FS1B   /**< Both FS0b and FS1b outputs */
} fs26_fs_output_t;

typedef enum {
/**  Voltage outputs.                                       *
 * Can be used with function @ref FS26_SetRegulatorState(). */
  fs26Ldo1  = 0U, /**< LDO1                                 */
  fs26Ldo2  = 1U, /**< LDO2                                 */
  fs26Vcore = 2U, /**< VCORE                                */
  fs26Trk1  = 3U, /**< TRK1                                 */
  fs26Trk2  = 4U, /**< TRK2                                 */
  fs26Vbst  = 6U, /**< VBST                                 */
  fs26Vref  = 7U  /**< VREF                                 */
} fs26_reg_output_t;

typedef struct {
/**  Structure representing received data frame.                                                     */
  uint8_t deviceStatus;  /** A device status is returned into this byte after a successful transfer. */
  uint16_t readData;     /** Content of a read register.                                             */
} fs26_rx_frame_t;

typedef struct {
/**  This data structure is used by the FS26 driver (this is the first parameter  *
 *  of most the FS26 functions). It contains a configuration of the FS26 device.  */
  fs26_watchdog_type_t watchdogType;  /** Watchdog type - simple or challenger.   */
  uint16_t watchdogToken;             /** Actual watchdog token value             */
} fs26_drv_data_t;

typedef struct {
  /**  Initialization structure with FS_I_OVUV_SAFE_REACTION1 content. Use register map values.          */
  uint16_t vmonPreOvFs;  /**  Reaction on RSTB or FAIL SAFE outputs in case of OV detection on VMON_PRE. */
  uint16_t vmonPreUvFs;  /**  Reaction on RSTB or FAIL SAFE outputs in case of UV detection on VMON_PRE. */
  uint16_t vmonCoreOvFs; /**  Reaction on RSTB or FAIL SAFE outputs in case of OV detection on VMON_CORE.*/
  uint16_t vmonCoreUvFs; /**  Reaction on RSTB or FAIL SAFE outputs in case of UV detection on VMON_CORE.*/
  uint16_t vmonLdo1OvFs; /**  Reaction on RSTB or FAIL SAFE outputs in case of OV detection on VMON_LDO1.*/
  uint16_t vmonLdo1UvFs; /**  Reaction on RSTB or FAIL SAFE outputs in case of UV detection on VMON_LDO1.*/
  uint16_t vmonLdo2OvFs; /**  Reaction on RSTB or FAIL SAFE outputs in case of OV detection on VMON_LDO2.*/
  uint16_t vmonLdo2UvFs; /**  Reaction on RSTB or FAIL SAFE outputs in case of UV detection on VMON_LDO2.*/
} fs26_ovuv_safe1_reg_t;

typedef struct {
  /**  Initialization structure with FS_I_OVUV_SAFE_REACTION2 content. Use register map values.           */
  uint16_t vmonExtOvFs;  /**  Reaction on RSTB or FAIL SAFE outputs in case of OV detection on VMON_EXT.  */
  uint16_t vmonExtUvFs;  /**  Reaction on RSTB or FAIL SAFE outputs in case of UV detection on VMON_EXT.  */
  uint16_t vmonRefOvFs;  /**  Reaction on RSTB or FAIL SAFE outputs in case of OV detection on VMON_REF.  */
  uint16_t vmonRefUvFs;  /**  Reaction on RSTB or FAIL SAFE outputs in case of UV detection on VMON_REF.  */
  uint16_t vmonTrk2OvFs;  /**  Reaction on RSTB or FAIL SAFE outputs in case of OV detection on VMON_TRK2.*/
  uint16_t vmonTrk2UvFs;  /**  Reaction on RSTB or FAIL SAFE outputs in case of UV detection on VMON_TRK2.*/
  uint16_t vmonTrk1OvFs;  /**  Reaction on RSTB or FAIL SAFE outputs in case of OV detection on VMON_TRK1.*/
  uint16_t vmonTrk1UvFs;  /**  Reaction on RSTB or FAIL SAFE outputs in case of UV detection on VMON_TRK1.*/
} fs26_ovuv_safe2_reg_t;

typedef struct {
  /**  Initialization structure with FS_I_WD_CFG content. Use register map values.                        */
  uint16_t wdErrLimit; /** Watchdog error counter configuration.                                          */
  uint16_t wdRfrLimit; /** Watchdog refresh counter configuration.                                        */
  uint16_t wdFs;       /** Reaction on RSTB or FAIL SAFE output in case of BAD Watchdog (data or timing). */
} fs26_wd_cfg_reg_t;

typedef struct {
  /**  Initialization structure with FS_I_SAFE_INPUTS content. Use register map values.                    */
  uint16_t fccuCfg;        /**  FCCU monitoring configuration.                                             */
  uint16_t fccu12FltPol;   /**  FCCU12 fault polarity.                                                     */
  uint16_t fccu1FltPol;    /**  FCCU1 fault polarity.                                                      */
  uint16_t fccu2FltPol;    /**  FCCU2 fault polarity.                                                      */
  uint16_t fccu12Fs;       /**  Reaction on RSTB or FAIL SAFE output in case of fault detection on FCCU12. */
  uint16_t fccu1Fs;        /**  Reaction on RSTB or FAIL SAFE output in case of fault detection on FCCU1.  */
  uint16_t fccu2Fs;        /**  Reaction on RSTB or FAIL SAFE output in case of fault detection on FCCU2.  */
  uint16_t wake2LpPol;     /**  WAKE2 Low Power mode request polarity.                                     */
  uint16_t errmonFaultPol; /**  ERRORMON Fault Polarity.                                                   */
  uint16_t errmonAckTime;  /**  Acknowledge timing following a fault detection on ERRMON.                  */
  uint16_t errmonFs;       /**  Reaction on RSTb or Fail Safe output in case of fault detection on ERRMON. */
  uint16_t fccu12Filt;     /**  FCCU pin filtering time settings.                                          */
} fs26_safe_inputs_reg_t;

typedef struct {
  /**  Initialization structure with FS_I_FSSM content. Use register map values.                                                        */
  uint16_t fltErrCntLimit; /**  Configure the maximum level of the fault counter.                                                       */
  uint16_t fltErrFs;       /**  Configure the RSTB and FS0b behavior when fault error counter is higher than/equals intermediate value. */
  uint16_t rstbDur;        /**  Reset duration configuration.                                                                           */
  uint16_t backupFs0b;     /**  Assert RSTB in case a short to high is detected on FS0b.                                                */
  uint16_t backupFs1b;     /**  Assert RSTb in case a short to high is detected on FS1b.                                                */
  uint16_t clkMonDis;      /**  Disable CLK Monitoring.                                                                                 */
  uint16_t dis8s;          /**  Disable 8s RSTb timer.                                                                                  */
} fs26_fssm_reg_t;

typedef struct {
  /**  Initialization structure with FS_WDW_DURATION content. Use register map values. */
  uint16_t wdwPeriod;   /** Watchdog window period configuration.                      */
  uint16_t wdwDc;       /** Watchdog Window Duty cycle.                                */
  uint16_t wdwRecovery; /** Watchdog window period configuration.                      */
} fs26_wdw_duration_reg_t;

typedef struct {
  /** Structure for FS26 initialization.
    * This structure is used as a parameter for @ref FS26_Init() function.
    * Configuration values for fail-safe logic registers written during INIT_FS phase.
    * Following registers can be configured:
    *  - FS_I_OVUV_SAFE_REACTION1
    *  - FS_I_OVUV_SAFE_REACTION2
    *  - FS_I_WD_CFG
    *  - FS_I_SAFE_INPUTS
    *  - FS_I_FSSM
    *  - FS_WDW_DURATION
    */
  fs26_ovuv_safe1_reg_t ovuvSafe1Reg;      /**  FS_I_OVUV_SAFE_REACTION1 register. */
  fs26_ovuv_safe2_reg_t ovuvSafe2Reg;      /**  FS_I_OVUV_SAFE_REACTION2 register. */
  fs26_wd_cfg_reg_t wdCfgReg;              /**  FS_I_WD_CFG register.              */
  fs26_safe_inputs_reg_t safeInputsReg;    /**  FS_I_SAFE_INPUTS register.         */
  fs26_fssm_reg_t fssmReg;                 /**  FS_I_FSSM register.                */
  fs26_wdw_duration_reg_t wdwDurationReg;  /**  FS_WDW_DURATION register.          */
} fs26_init_config_t;

/*******************************************************************************
 * Prototypes of extern functions
 ******************************************************************************/
/* MCU specific functions
 * This function transfers single frame through blocking SPI communication
 *  in both directions. MCU specific.
 *
 * This function must be implemented if SPI communication is used. The txFrame must be
 * sent to the SPI bus from the last byte to the first (e.g. txFrame[0] will be sent
 * last). The FS26 driver expects incoming data in reversed order, e.g. rxFrame[0] = CRC,
 * rxFrame[1] = LSB ...
 * @warning This function must be implemented as blocking as there is not synchronization
 * mechanism implemented in the driver.
 * @param [in]  txFrame           Frame to be send.
 * @param [in]  frameLengthBytes  Bytes Length of the frame in bytes.
 * @param [out] rxFrame           Received frame.
 * @return @ref fs26_status_t "Status return code."
 */
extern fs26_status_t MCU_SPI_TransferData(uint8_t* txFrame, uint16_t frameLengthBytes, uint8_t* rxFrame);

/*******************************************************************************
 * API
 ******************************************************************************/
/* Initializes the FS26 device.
 * Performs initialization checks (LBIST, ABIST1 are pass)
 * and writes all INIT_FS registers and watchdog configuration. Closes initialization
 * phase by sending first watchdog refresh.
 * @param [in]  drvData      Driver run-time data.
 * @param [in]  initConfig   Configuration of INIT_FS registers.
 * @param [in]  changeToken  If true watchdog token from drvData will be written to device.
 * @return @ref fs26_status_t "Status return code."
 */
fs26_status_t FS26_Init(fs26_drv_data_t* drvData, fs26_init_config_t* initConfig, bool changeToken);

/* Populates default INIT_FS registers configuration.
 * Returns default values of INIT_FS registers configuration.
 * The response is returned in @ref fs26_init_config_t structure.
 * @param [out] initConfig  Default configuration of INIT_FS registers.
 */
void FS26_GetDefaultInitConfig(fs26_init_config_t* initConfig);

/** Performs a read from a single FS26 register.
 * Performs a single read register based on provided address.
 * The response is returned in @ref fs26_rx_frame_t structure.
 * @param [in]  drvData     Driver run-time data.
 * @param [in]  isFailSafe  true if the register is Fail Safe.
 * @param [in]  address     Register address.
 * @param [out] rxData      Structure holding the response from SBC.
 * @return @ref fs26_status_t "Status return code."
 */
fs26_status_t FS26_ReadRegister(fs26_drv_data_t* drvData, bool isFailSafe, uint8_t address,
                                fs26_rx_frame_t* rxData);

/** Sends write command to the FS26.
 * @param [in] drvData     Driver run-time data.
 * @param [in] isFailSafe  true: Reading from FS register, false: Reading from Main register.
 * @param [in] address     Register address.
 * @param [in] writeData   Register write value.
 * @return @ref fs26_status_t "Status return code."
 */
fs26_status_t FS26_WriteRegister(fs26_drv_data_t* drvData, bool isFailSafe, uint8_t address,
                                 uint16_t writeData);

/** Performs a write to a single FS26 FS init register (during the INIT_FS phase only).
 * @param [in] drvData    Driver run-time data.
 * @param [in] address    Register address.
 * @param [in] writeData  Register write value.
 * @return @ref fs26_status_t "Status return code."
 */
fs26_status_t FS26_WriteRegisterInit(fs26_drv_data_t* drvData, uint8_t address,
                                     uint16_t writeData);

/** Changes token of LFSR used for watchdog.
 * The watchdog token can be changed just during the INIT_FS phase (for challenger WD)
 * or during the OPEN watchdog window (for simple WD). Timing is up to the application!
 * @param [in] drvData  Driver run-time data, containing current watchdog token.
 * @param [in] wdToken  New watchdog token, stored to drvData if change was successful.
 * @return @ref fs26_status_t "Status return code."
 */
fs26_status_t FS26_WD_ChangeToken(fs26_drv_data_t* drvData, uint16_t wdToken);

/** Performs the watchdog refresh.
 * @param [in]  drvData   Driver run-time data.
 * @param [out] grlFlags  Pointer to FS_GRL_FLAGS register content storage. If NULL, will be skipped.
 * @return @ref fs26_status_t "Status return code."
 */
fs26_status_t FS26_WD_Refresh(fs26_drv_data_t* drvData, uint16_t* grlFlags);

/** Reads actual Fault Error Counter value.
 * @param [in]  drvData                 Driver run-time data.
 * @param [out] faultErrorCounterValue  Fault Error counter value storage.
 * @return @ref fs26_status_t "Status return code."
 */
fs26_status_t FS26_GetFaultErrorCounterValue(fs26_drv_data_t* drvData, uint8_t* faultErrorCounterValue);

/** FSxB release routine.
 * This function also checks all preconditions before
 * it sends the register write command (LBIST_OK = ABIST1_OK = ABIST2_OK = 1,
 * Fault Error Counter = 0). If any precondition is not met, the function returns
 * @ref fs26StatusError.
 * @param [in] drvData   Driver run-time data.
 * @param [in] fsOutput  FS output to release.
 * @return @ref fs26_status_t "Status return code."
 */
fs26_status_t FS26_FSxB_Release(fs26_drv_data_t* drvData, fs26_fs_output_t fsOutput);

/** Sets state (enable/disable) of the selected voltage regulator.
 * @param [in] drvData Driver run-time data.
 * @param [in] vreg    Voltage regulator.
 * @param [in] enable  State (enable = true / disable = false).
 * @return @ref fs26_status_t "Status return code."
 */
fs26_status_t FS26_SetRegulatorState(fs26_drv_data_t* drvData, fs26_reg_output_t vreg, bool enable);

#endif /* DRIVERS_FS26_FS26_H_ */
