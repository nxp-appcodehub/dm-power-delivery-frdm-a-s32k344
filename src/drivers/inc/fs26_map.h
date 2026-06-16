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

#ifndef DRIVERS_FS26_FS26_MAP_H_
#define DRIVERS_FS26_FS26_MAP_H_

/******************************************************************************/
/* M_DEVICEID - Type: R                                                       */
/******************************************************************************/
#define FS26_M_DEVICEID_ADDR             0x00U
#define FS26_M_DEVICEID_DEFAULT          0x01C0U

/* Device ID */
#define FS26_M_DEV_ID_MASK               0x003FU
#define FS26_M_DEV_ID_SHIFT              0x0000U
/* Device Family Identification */
#define FS26_M_FAM_ID_MASK               0x03C0U
#define FS26_M_FAM_ID_SHIFT              0x0006U
/* Metal Mask revision */
#define FS26_M_METAL_LAYER_REV_MASK      0x1C00U
#define FS26_M_METAL_LAYER_REV_SHIFT     0x0010U
/* Full Layer Mask revision */
#define FS26_M_FULL_LAYER_REV_MASK       0xE000U
#define FS26_M_FULL_LAYER_REV_SHIFT      0x0013U

/* Reserved */
#define FS26_M_FAM_ID_RES_0              (0x0000U << FS26_M_FAM_ID_SHIFT)
/* Reserved */
#define FS26_M_FAM_ID_RES_1              (0x0001U << FS26_M_FAM_ID_SHIFT)
/* Reserved */
#define FS26_M_FAM_ID_RES_2              (0x0002U << FS26_M_FAM_ID_SHIFT)
/* Reserved */
#define FS26_M_FAM_ID_RES_3              (0x0003U << FS26_M_FAM_ID_SHIFT)
/* Reserved */
#define FS26_M_FAM_ID_RES_4              (0x0004U << FS26_M_FAM_ID_SHIFT)
/* Reserved */
#define FS26_M_FAM_ID_RES_5              (0x0005U << FS26_M_FAM_ID_SHIFT)
/* Reserved */
#define FS26_M_FAM_ID_RES_6              (0x0006U << FS26_M_FAM_ID_SHIFT)
/* FS26 family */
#define FS26_M_FAM_ID_FS26               (0x0007U << FS26_M_FAM_ID_SHIFT)
/* Reserved */
#define FS26_M_FAM_ID_RES_8              (0x0008U << FS26_M_FAM_ID_SHIFT)
/* Reserved */
#define FS26_M_FAM_ID_RES_9              (0x0009U << FS26_M_FAM_ID_SHIFT)
/* Reserved */
#define FS26_M_FAM_ID_RES_10             (0x000AU << FS26_M_FAM_ID_SHIFT)
/* Reserved */
#define FS26_M_FAM_ID_RES_11             (0x000BU << FS26_M_FAM_ID_SHIFT)
/* Reserved */
#define FS26_M_FAM_ID_RES_12             (0x000CU << FS26_M_FAM_ID_SHIFT)
/* Reserved */
#define FS26_M_FAM_ID_RES_13             (0x000DU << FS26_M_FAM_ID_SHIFT)
/* Reserved */
#define FS26_M_FAM_ID_RES_14             (0x000EU << FS26_M_FAM_ID_SHIFT)
/* Reserved */
#define FS26_M_FAM_ID_RES_15             (0x000FU << FS26_M_FAM_ID_SHIFT)

/* Rev X.0 ( Default full Layer revision) */
#define FS26_M_METAL_LAYER_REV_0         (0x0000U << FS26_M_METAL_LAYER_REV_SHIFT)
/* Rev X.1 */
#define FS26_M_METAL_LAYER_REV_1         (0x0001U << FS26_M_METAL_LAYER_REV_SHIFT)
/* Rev X.2 */
#define FS26_M_METAL_LAYER_REV_2         (0x0002U << FS26_M_METAL_LAYER_REV_SHIFT)
/* Rev X.3 */
#define FS26_M_METAL_LAYER_REV_3         (0x0003U << FS26_M_METAL_LAYER_REV_SHIFT)
/* Rev X.4 */
#define FS26_M_METAL_LAYER_REV_4         (0x0004U << FS26_M_METAL_LAYER_REV_SHIFT)
/* Rev X.5 */
#define FS26_M_METAL_LAYER_REV_5         (0x0005U << FS26_M_METAL_LAYER_REV_SHIFT)
/* Rev X.6 */
#define FS26_M_METAL_LAYER_REV_6         (0x0006U << FS26_M_METAL_LAYER_REV_SHIFT)
/* Rev X.7 */
#define FS26_M_METAL_LAYER_REV_7         (0x0007U << FS26_M_METAL_LAYER_REV_SHIFT)

/* Unused */
#define FS26_M_FULL_LAYER_REV_UNUSED     (0x0000U << FS26_M_FULL_LAYER_REV_SHIFT)
/* Pass A silicon */
#define FS26_M_FULL_LAYER_REV_A          (0x0001U << FS26_M_FULL_LAYER_REV_SHIFT)
/* Pass B silicon */
#define FS26_M_FULL_LAYER_REV_B          (0x0002U << FS26_M_FULL_LAYER_REV_SHIFT)
/* Pass C silicon */
#define FS26_M_FULL_LAYER_REV_C          (0x0003U << FS26_M_FULL_LAYER_REV_SHIFT)
/* Pass D silicon */
#define FS26_M_FULL_LAYER_REV_D          (0x0004U << FS26_M_FULL_LAYER_REV_SHIFT)
/* Pass E silicon */
#define FS26_M_FULL_LAYER_REV_E          (0x0005U << FS26_M_FULL_LAYER_REV_SHIFT)
/* Pass F silicon */
#define FS26_M_FULL_LAYER_REV_F          (0x0006U << FS26_M_FULL_LAYER_REV_SHIFT)
/* Pass G silicon */
#define FS26_M_FULL_LAYER_REV_G          (0x0007U << FS26_M_FULL_LAYER_REV_SHIFT)

/******************************************************************************/
/* M_PROGID - Type: R                                                         */
/******************************************************************************/
#define FS26_M_PROGID_ADDR               0x01U
#define FS26_M_PROGID_DEFAULT            0x00C0U

/* Lower byte to set the second letter for OTP ID code (A-Z) */
#define FS26_M_PROG_IDL_MASK             0x00FFU
#define FS26_M_PROG_IDL_SHIFT            0x0000U
/* Higher byte to set the first letter for the OTP ID code (A-Z) */
#define FS26_M_PROG_IDH_MASK             0xFF00U
#define FS26_M_PROG_IDH_SHIFT            0x0008U

/******************************************************************************/
/* M_STATUS - Type: R                                                         */
/******************************************************************************/
#define FS26_M_STATUS_ADDR               0x02U
#define FS26_M_STATUS_DEFAULT            0x0000U

/* Real time Status of LDO1 Regulator */
#define FS26_M_LDO1_S_MASK               0x0001U
#define FS26_M_LDO1_S_SHIFT              0x0000U
/* Real time status of LDO2 Regulator */
#define FS26_M_LDO2_S_MASK               0x0002U
#define FS26_M_LDO2_S_SHIFT              0x0001U
/* Real time status of VCORE Regulator */
#define FS26_M_CORE_S_MASK               0x0004U
#define FS26_M_CORE_S_SHIFT              0x0002U
/* Real time status of TRK1 Regulator */
#define FS26_M_TRK1_S_MASK               0x0008U
#define FS26_M_TRK1_S_SHIFT              0x0003U
/* Real time status of TRK2 Regulator */
#define FS26_M_TRK2_S_MASK               0x0010U
#define FS26_M_TRK2_S_SHIFT              0x0004U
/* Real time status of VPRE Regulator */
#define FS26_M_VPRE_S_MASK               0x0020U
#define FS26_M_VPRE_S_SHIFT              0x0005U
/* Real time status of VBST Regulator */
#define FS26_M_VBST_S_MASK               0x0040U
#define FS26_M_VBST_S_SHIFT              0x0006U
/* Real time status of VREF Regulator */
#define FS26_M_VREF_S_MASK               0x0080U
#define FS26_M_VREF_S_SHIFT              0x0007U
/* GPIO1 pin status */
#define FS26_M_IO1_S_MASK                0x0100U
#define FS26_M_IO1_S_SHIFT               0x0008U
/* GPIO2 pin status */
#define FS26_M_IO2_S_MASK                0x0200U
#define FS26_M_IO2_S_SHIFT               0x0009U
/* Real time status of WAKE1 pin */
#define FS26_M_WK1_S_MASK                0x0400U
#define FS26_M_WK1_S_SHIFT               0x000AU
/* Real time status of WAKE2 pin */
#define FS26_M_WK2_S_MASK                0x0800U
#define FS26_M_WK2_S_SHIFT               0x000BU
/* Real time status of VBST FB pin */
#define FS26_M_VBSTFB_UV_S_MASK          0x1000U
#define FS26_M_VBSTFB_UV_S_SHIFT         0x000CU
/* Real time status of VBST switching status */
#define FS26_M_VBSTFB_ACTIVE_S_MASK      0x2000U
#define FS26_M_VBSTFB_ACTIVE_S_SHIFT     0x000DU
/* Real time status of Thermal Warning flag */
#define FS26_M_TWARN_S_MASK              0x8000U
#define FS26_M_TWARN_S_SHIFT             0x000FU

/* LDO1 is Disabled */
#define FS26_M_LDO1_S_DISABLED           (0x0000U << FS26_M_LDO1_S_SHIFT)
/* LDO1 is Enabled */
#define FS26_M_LDO1_S_ENABLED            (0x0001U << FS26_M_LDO1_S_SHIFT)

/* LDO2 is Disabled */
#define FS26_M_LDO2_S_DISABLED           (0x0000U << FS26_M_LDO2_S_SHIFT)
/* LDO2 is Enabled */
#define FS26_M_LDO2_S_ENABLED            (0x0001U << FS26_M_LDO2_S_SHIFT)

/* VCORE is Disabled */
#define FS26_M_CORE_S_DISABLED           (0x0000U << FS26_M_CORE_S_SHIFT)
/* VCORE is Enabled */
#define FS26_M_CORE_S_ENABLED            (0x0001U << FS26_M_CORE_S_SHIFT)

/* TRK1 is Disabled */
#define FS26_M_TRK1_S_DISABLED           (0x0000U << FS26_M_TRK1_S_SHIFT)
/* TRK1 is Enabled */
#define FS26_M_TRK1_S_ENABLED            (0x0001U << FS26_M_TRK1_S_SHIFT)

/* TRK2 is Disabled */
#define FS26_M_TRK2_S_DISABLED           (0x0000U << FS26_M_TRK2_S_SHIFT)
/* TRK2 is Enabled */
#define FS26_M_TRK2_S_ENABLED            (0x0001U << FS26_M_TRK2_S_SHIFT)

/* VPRE is Disabled */
#define FS26_M_VPRE_S_DISABLED           (0x0000U << FS26_M_VPRE_S_SHIFT)
/* VPRE is Enabled */
#define FS26_M_VPRE_S_ENABLED            (0x0001U << FS26_M_VPRE_S_SHIFT)

/* VBST is Disabled or not switching (Pass through mode) */
#define FS26_M_VBST_S_DISABLED           (0x0000U << FS26_M_VBST_S_SHIFT)
/* VBST is Enabled */
#define FS26_M_VBST_S_ENABLED            (0x0001U << FS26_M_VBST_S_SHIFT)

/* VREF is Disabled */
#define FS26_M_VREF_S_DISABLED           (0x0000U << FS26_M_VREF_S_SHIFT)
/* VREF is Enabled */
#define FS26_M_VREF_S_ENABLED            (0x0001U << FS26_M_VREF_S_SHIFT)

/* GPIO1 is low */
#define FS26_M_IO1_S_LOW                 (0x0000U << FS26_M_IO1_S_SHIFT)
/* GPIO1 is high */
#define FS26_M_IO1_S_HIGH                (0x0001U << FS26_M_IO1_S_SHIFT)

/* GPIO2 is low */
#define FS26_M_IO2_S_LOW                 (0x0000U << FS26_M_IO2_S_SHIFT)
/* GPIO2 is high */
#define FS26_M_IO2_S_HIGH                (0x0001U << FS26_M_IO2_S_SHIFT)

/* WAKE1 is low */
#define FS26_M_WK1_S_LOW                 (0x0000U << FS26_M_WK1_S_SHIFT)
/* WAKE1 is high */
#define FS26_M_WK1_S_HIGH                (0x0001U << FS26_M_WK1_S_SHIFT)

/* WAKE2 is low */
#define FS26_M_WK2_S_LOW                 (0x0000U << FS26_M_WK2_S_SHIFT)
/* WAKE2 is high */
#define FS26_M_WK2_S_HIGH                (0x0001U << FS26_M_WK2_S_SHIFT)

/* VSBT_FB below VBST_UV_TH */
#define FS26_M_VBSTFB_UV_S_BELOW         (0x0000U << FS26_M_VBSTFB_UV_S_SHIFT)
/* VSBT_FB above VBST_UV_TH */
#define FS26_M_VBSTFB_UV_S_ABOVE         (0x0001U << FS26_M_VBSTFB_UV_S_SHIFT)

/* VBST LX node is not switching */
#define FS26_M_VBSTFB_ACTIVE_S_BELOW     (0x0000U << FS26_M_VBSTFB_ACTIVE_S_SHIFT)
/* VBST LX node is switching */
#define FS26_M_VBSTFB_ACTIVE_S_ABOVE     (0x0001U << FS26_M_VBSTFB_ACTIVE_S_SHIFT)

/* TJ is below TWARN threshold */
#define FS26_M_TWARN_S_BELOW             (0x0000U << FS26_M_TWARN_S_SHIFT)
/* TJ is above TWARN threshold */
#define FS26_M_TWARN_S_ABOVE             (0x0001U << FS26_M_TWARN_S_SHIFT)

/******************************************************************************/
/* M_TSD_FLG - Type: RW                                                       */
/******************************************************************************/
#define FS26_M_TSD_FLG_ADDR              0x03U
#define FS26_M_TSD_FLG_DEFAULT           0x0000U

/* Interrupt flag when LDO1 Thermal shutdown event occurs */
#define FS26_M_LDO1TSD_I_MASK            0x0001U
#define FS26_M_LDO1TSD_I_SHIFT           0x0000U
/* Interrupt flag when LDO2 Thermal shutdown event occurs */
#define FS26_M_LDO2TSD_I_MASK            0x0002U
#define FS26_M_LDO2TSD_I_SHIFT           0x0001U
/* Interrupt flag when VCORE Thermal shutdown event occurs */
#define FS26_M_CORETSD_I_MASK            0x0004U
#define FS26_M_CORETSD_I_SHIFT           0x0002U
/* Interrupt flag when TRK1 Thermal shutdown event occurs */
#define FS26_M_TRK1TSD_I_MASK            0x0008U
#define FS26_M_TRK1TSD_I_SHIFT           0x0003U
/* Interrupt flag when TRK2 Thermal shutdown event occurs */
#define FS26_M_TRK2TSD_I_MASK            0x0010U
#define FS26_M_TRK2TSD_I_SHIFT           0x0004U
/* Interrupt flag when VPRE Thermal shutdown event occurs */
#define FS26_M_VPRETSD_I_MASK            0x0020U
#define FS26_M_VPRETSD_I_SHIFT           0x0005U
/* Interrupt flag when GPIO1 Thermal shutdown event occurs */
#define FS26_M_IO1TSD_I_MASK             0x0040U
#define FS26_M_IO1TSD_I_SHIFT            0x0006U
/* Central Temp sensor has crossed the Thermal warning threshold on the rising edge */
#define FS26_M_TWARN_I_MASK              0x8000U
#define FS26_M_TWARN_I_SHIFT             0x000FU

/* No Thermal Shutdown event detected */
#define FS26_M_LDO1TSD_I_NO_EVENT        (0x0000U << FS26_M_LDO1TSD_I_SHIFT)
/* Thermal Shutdown event occurred */
#define FS26_M_LDO1TSD_I_EVENT           (0x0001U << FS26_M_LDO1TSD_I_SHIFT)

/* No Thermal Shutdown event detected */
#define FS26_M_LDO2TSD_I_NO_EVENT        (0x0000U << FS26_M_LDO2TSD_I_SHIFT)
/* Thermal Shutdown event occurred */
#define FS26_M_LDO2TSD_I_EVENT           (0x0001U << FS26_M_LDO2TSD_I_SHIFT)

/* No Thermal Shutdown event detected */
#define FS26_M_CORETSD_I_NO_EVENT        (0x0000U << FS26_M_CORETSD_I_SHIFT)
/* Thermal Shutdown event occurred */
#define FS26_M_CORETSD_I_EVENT           (0x0001U << FS26_M_CORETSD_I_SHIFT)

/* No Thermal Shutdown event detected */
#define FS26_M_TRK1TSD_I_NO_EVENT        (0x0000U << FS26_M_TRK1TSD_I_SHIFT)
/* Thermal Shutdown event occurred */
#define FS26_M_TRK1TSD_I_EVENT           (0x0001U << FS26_M_TRK1TSD_I_SHIFT)

/* No Thermal Shutdown event detected */
#define FS26_M_TRK2TSD_I_NO_EVENT        (0x0000U << FS26_M_TRK2TSD_I_SHIFT)
/* Thermal Shutdown event occurred */
#define FS26_M_TRK2TSD_I_EVENT           (0x0001U << FS26_M_TRK2TSD_I_SHIFT)

/* No Thermal Shutdown event detected */
#define FS26_M_VPRETSD_I_NO_EVENT        (0x0000U << FS26_M_VPRETSD_I_SHIFT)
/* Thermal Shutdown event occurred */
#define FS26_M_VPRETSD_I_EVENT           (0x0001U << FS26_M_VPRETSD_I_SHIFT)

/* No Thermal Shutdown event detected */
#define FS26_M_IO1TSD_I_NO_EVENT         (0x0000U << FS26_M_IO1TSD_I_SHIFT)
/* Thermal Shutdown event occurred */
#define FS26_M_IO1TSD_I_EVENT            (0x0001U << FS26_M_IO1TSD_I_SHIFT)

/* No Thermal warning detected */
#define FS26_M_TWARN_I_NO_WARNING        (0x0000U << FS26_M_TWARN_I_SHIFT)
/* Thermal warning occurred */
#define FS26_M_TWARN_I_WARNING           (0x0001U << FS26_M_TWARN_I_SHIFT)

/******************************************************************************/
/* M_TSD_MSK - Type: RW                                                       */
/******************************************************************************/
#define FS26_M_TSD_MSK_ADDR              0x04U
#define FS26_M_TSD_MSK_DEFAULT           0x0000U

/* Inhibit Interrupt when LDO1 Thermal Shutdown occurs */
#define FS26_M_LDO1TSD_M_MASK            0x0001U
#define FS26_M_LDO1TSD_M_SHIFT           0x0000U
/* Inhibit Interrupt when LDO2 Thermal Shutdown occurs */
#define FS26_M_LDO2TSD_M_MASK            0x0002U
#define FS26_M_LDO2TSD_M_SHIFT           0x0001U
/* Inhibit Interrupt when VCORE Thermal Shutdown occurs */
#define FS26_M_CORETSD_M_MASK            0x0004U
#define FS26_M_CORETSD_M_SHIFT           0x0002U
/* Inhibit Interrupt when TRK1 Thermal Shutdown occurs */
#define FS26_M_TRK1TSD_M_MASK            0x0008U
#define FS26_M_TRK1TSD_M_SHIFT           0x0003U
/* Inhibit Interrupt when TRK2 Thermal Shutdown occurs */
#define FS26_M_TRK2TSD_M_MASK            0x0010U
#define FS26_M_TRK2TSD_M_SHIFT           0x0004U
/* Inhibit Interrupt when VPRE Thermal Shutdown occurs */
#define FS26_M_VPRETSD_M_MASK            0x0020U
#define FS26_M_VPRETSD_M_SHIFT           0x0005U
/* Inhibit Interrupt when GPIO1 Thermal Shutdown occurs */
#define FS26_M_IO1TSD_M_MASK             0x0040U
#define FS26_M_IO1TSD_M_SHIFT            0x0006U
/* Inhibit Interrupt when a Thermal warning occurs */
#define FS26_M_TWARN_M_MASK              0x8000U
#define FS26_M_TWARN_M_SHIFT             0x000FU

/* Interrupt MASKED */
#define FS26_M_LDO1TSD_M_MASKED          (0x0000U << FS26_M_LDO1TSD_M_SHIFT)
/* Interrupt NOT MASKED */
#define FS26_M_LDO1TSD_M_NOT_MASKED      (0x0001U << FS26_M_LDO1TSD_M_SHIFT)

/* Interrupt MASKED */
#define FS26_M_LDO2TSD_M_MASKED          (0x0000U << FS26_M_LDO2TSD_M_SHIFT)
/* Interrupt NOT MASKED */
#define FS26_M_LDO2TSD_M_NOT_MASKED      (0x0001U << FS26_M_LDO2TSD_M_SHIFT)

/* Interrupt MASKED */
#define FS26_M_CORETSD_M_MASKED          (0x0000U << FS26_M_CORETSD_M_SHIFT)
/* Interrupt NOT MASKED */
#define FS26_M_CORETSD_M_NOT_MASKED      (0x0001U << FS26_M_CORETSD_M_SHIFT)

/* Interrupt MASKED */
#define FS26_M_TRK1TSD_M_MASKED          (0x0000U << FS26_M_TRK1TSD_M_SHIFT)
/* Interrupt NOT MASKED */
#define FS26_M_TRK1TSD_M_NOT_MASKED      (0x0001U << FS26_M_TRK1TSD_M_SHIFT)

/* Interrupt MASKED */
#define FS26_M_TRK2TSD_M_MASKED          (0x0000U << FS26_M_TRK2TSD_M_SHIFT)
/* Interrupt NOT MASKED */
#define FS26_M_TRK2TSD_M_NOT_MASKED      (0x0001U << FS26_M_TRK2TSD_M_SHIFT)

/* Interrupt MASKED */
#define FS26_M_VPRETSD_M_MASKED          (0x0000U << FS26_M_VPRETSD_M_SHIFT)
/* Interrupt NOT MASKED */
#define FS26_M_VPRETSD_M_NOT_MASKED      (0x0001U << FS26_M_VPRETSD_M_SHIFT)

/* Interrupt MASKED */
#define FS26_M_IO1TSD_M_MASKED           (0x0000U << FS26_M_IO1TSD_M_SHIFT)
/* Interrupt NOT MASKED */
#define FS26_M_IO1TSD_M_NOT_MASKED       (0x0001U << FS26_M_IO1TSD_M_SHIFT)

/* Interrupt MASKED */
#define FS26_M_TWARN_M_MASKED            (0x0000U << FS26_M_TWARN_M_SHIFT)
/* Interrupt NOT MASKED */
#define FS26_M_TWARN_M_NOT_MASKED        (0x0001U << FS26_M_TWARN_M_SHIFT)

/******************************************************************************/
/* M_REG_FLG - Type: RW                                                       */
/******************************************************************************/
#define FS26_M_REG_FLG_ADDR              0x05U
#define FS26_M_REG_FLG_DEFAULT           0x0000U

/* Interrupt flag when LDO1 Over Current event occurs */
#define FS26_M_LDO1OC_I_MASK             0x0001U
#define FS26_M_LDO1OC_I_SHIFT            0x0000U
/* Interrupt flag when LDO2 Over Current event occurs */
#define FS26_M_LDO2OC_I_MASK             0x0002U
#define FS26_M_LDO2OC_I_SHIFT            0x0001U
/* Interrupt flag when VCORE Over Current event occurs */
#define FS26_M_COREOC_I_MASK             0x0004U
#define FS26_M_COREOC_I_SHIFT            0x0002U
/* Interrupt flag when TRK1 Over Current event occurs */
#define FS26_M_TRK1OC_I_MASK             0x0008U
#define FS26_M_TRK1OC_I_SHIFT            0x0003U
/* Interrupt flag when TRK2 Over Current event occurs */
#define FS26_M_TRK2OC_I_MASK             0x0010U
#define FS26_M_TRK2OC_I_SHIFT            0x0004U
/* Interrupt flag when VPRE Over Current event occurs */
#define FS26_M_VPREOC_I_MASK             0x0020U
#define FS26_M_VPREOC_I_SHIFT            0x0005U
/* Interrupt flag when VBST Over Current event occurs */
#define FS26_M_VBSTOC_I_MASK             0x0040U
#define FS26_M_VBSTOC_I_SHIFT            0x0006U
/* Interrupt flag when VPRE crosses it UVH threshold on the falling edge */
#define FS26_M_VPREUVH_I_MASK            0x0080U
#define FS26_M_VPREUVH_I_SHIFT           0x0007U
/* Interrupt flag when VBST_FB has crossed Over Voltage Threshold */
#define FS26_M_VBSTOV_I_MASK             0x0100U
#define FS26_M_VBSTOV_I_SHIFT            0x0008U

/* No Over current event detected */
#define FS26_M_LDO1OC_I_NO_EVENT         (0x0000U << FS26_M_LDO1OC_I_SHIFT)
/* Over current event occurred */
#define FS26_M_LDO1OC_I_EVENT            (0x0001U << FS26_M_LDO1OC_I_SHIFT)

/* No Over current event detected */
#define FS26_M_LDO2OC_I_NO_EVENT         (0x0000U << FS26_M_LDO2OC_I_SHIFT)
/* Over current event occurred */
#define FS26_M_LDO2OC_I_EVENT            (0x0001U << FS26_M_LDO2OC_I_SHIFT)

/* No Over current event detected */
#define FS26_M_COREOC_I_NO_EVENT         (0x0000U << FS26_M_COREOC_I_SHIFT)
/* Over current event occurred */
#define FS26_M_COREOC_I_EVENT            (0x0001U << FS26_M_COREOC_I_SHIFT)

/* No Over current event detected */
#define FS26_M_TRK1OC_I_NO_EVENT         (0x0000U << FS26_M_TRK1OC_I_SHIFT)
/* Over current event occurred */
#define FS26_M_TRK1OC_I_EVENT            (0x0001U << FS26_M_TRK1OC_I_SHIFT)

/* No Over current event detected */
#define FS26_M_TRK2OC_I_NO_EVENT         (0x0000U << FS26_M_TRK2OC_I_SHIFT)
/* Over current event occurred */
#define FS26_M_TRK2OC_I_EVENT            (0x0001U << FS26_M_TRK2OC_I_SHIFT)

/* No Over current event detected */
#define FS26_M_VPREOC_I_NO_EVENT         (0x0000U << FS26_M_VPREOC_I_SHIFT)
/* Over current event occurred */
#define FS26_M_VPREOC_I_EVENT            (0x0001U << FS26_M_VPREOC_I_SHIFT)

/* No Over current event detected */
#define FS26_M_VBSTOC_I_NO_EVENT         (0x0000U << FS26_M_VBSTOC_I_SHIFT)
/* Over current event occurred */
#define FS26_M_VBSTOC_I_EVENT            (0x0001U << FS26_M_VBSTOC_I_SHIFT)

/* VPRE has not cross VPRE_UVH threshold */
#define FS26_M_VPREUVH_I_NOT_CROSSED     (0x0000U << FS26_M_VPREUVH_I_SHIFT)
/* VPRE crossed VPRE_UVH threshold */
#define FS26_M_VPREUVH_I_CROSSED         (0x0001U << FS26_M_VPREUVH_I_SHIFT)

/* VBST has not cross VBST_OV_TH threshold */
#define FS26_M_VBSTOV_I_NOT_CROSSED      (0x0000U << FS26_M_VBSTOV_I_SHIFT)
/* VBST crossed VBST_OV_TH threshold */
#define FS26_M_VBSTOV_I_CROSSED          (0x0001U << FS26_M_VBSTOV_I_SHIFT)

/******************************************************************************/
/* M_REG_MSK - Type: RW                                                       */
/******************************************************************************/
#define FS26_M_REG_MSK_ADDR              0x06U
#define FS26_M_REG_MSK_DEFAULT           0x0000U

/* Inhibit Interrupt when LDO1 Over Current event occurs */
#define FS26_M_LDO1OC_M_MASK             0x0001U
#define FS26_M_LDO1OC_M_SHIFT            0x0000U
/* Inhibit Interrupt when LDO2 Over Current event occurs */
#define FS26_M_LDO2OC_M_MASK             0x0002U
#define FS26_M_LDO2OC_M_SHIFT            0x0001U
/* Inhibit Interrupt when VCORE Over Current event occurs */
#define FS26_M_COREOC_M_MASK             0x0004U
#define FS26_M_COREOC_M_SHIFT            0x0002U
/* Inhibit Interrupt when TRK1 Over Current event occurs */
#define FS26_M_TRK1OC_M_MASK             0x0008U
#define FS26_M_TRK1OC_M_SHIFT            0x0003U
/* Inhibit Interrupt when TRK2 Over Current event occurs */
#define FS26_M_TRK2OC_M_MASK             0x0010U
#define FS26_M_TRK2OC_M_SHIFT            0x0004U
/* Inhibit Interrupt when VPRE Over Current event occurs */
#define FS26_M_VPREOC_M_MASK             0x0020U
#define FS26_M_VPREOC_M_SHIFT            0x0005U
/* Inhibit Interrupt when VBST Over Current event occurs */
#define FS26_M_VBSTOC_M_MASK             0x0040U
#define FS26_M_VBSTOC_M_SHIFT            0x0006U
/* Inhibit Interrupt when VPRE Under Voltage event occurs */
#define FS26_M_VPREUVH_M_MASK            0x0080U
#define FS26_M_VPREUVH_M_SHIFT           0x0007U
/* Inhibit Interrupt when VBST Over Voltage event occurs */
#define FS26_M_VBSTOV_M_MASK             0x0100U
#define FS26_M_VBSTOV_M_SHIFT            0x0008U

/* Interrupt MASKED */
#define FS26_M_LDO1OC_M_MASKED           (0x0000U << FS26_M_LDO1OC_M_SHIFT)
/* Interrupt NOT MASKED */
#define FS26_M_LDO1OC_M_NOT_MASKED       (0x0001U << FS26_M_LDO1OC_M_SHIFT)

/* Interrupt MASKED */
#define FS26_M_LDO2OC_M_MASKED           (0x0000U << FS26_M_LDO2OC_M_SHIFT)
/* Interrupt NOT MASKED */
#define FS26_M_LDO2OC_M_NOT_MASKED       (0x0001U << FS26_M_LDO2OC_M_SHIFT)

/* Interrupt MASKED */
#define FS26_M_COREOC_M_MASKED           (0x0000U << FS26_M_COREOC_M_SHIFT)
/* Interrupt NOT MASKED */
#define FS26_M_COREOC_M_NOT_MASKED       (0x0001U << FS26_M_COREOC_M_SHIFT)

/* Interrupt MASKED */
#define FS26_M_TRK1OC_M_MASKED           (0x0000U << FS26_M_TRK1OC_M_SHIFT)
/* Interrupt NOT MASKED */
#define FS26_M_TRK1OC_M_NOT_MASKED       (0x0001U << FS26_M_TRK1OC_M_SHIFT)

/* Interrupt MASKED */
#define FS26_M_TRK2OC_M_MASKED           (0x0000U << FS26_M_TRK2OC_M_SHIFT)
/* Interrupt NOT MASKED */
#define FS26_M_TRK2OC_M_NOT_MASKED       (0x0001U << FS26_M_TRK2OC_M_SHIFT)

/* Interrupt MASKED */
#define FS26_M_VPREOC_M_MASKED           (0x0000U << FS26_M_VPREOC_M_SHIFT)
/* Interrupt NOT MASKED */
#define FS26_M_VPREOC_M_NOT_MASKED       (0x0001U << FS26_M_VPREOC_M_SHIFT)

/* Interrupt MASKED */
#define FS26_M_VBSTOC_M_MASKED           (0x0000U << FS26_M_VBSTOC_M_SHIFT)
/* Interrupt NOT MASKED */
#define FS26_M_VBSTOC_M_NOT_MASKED       (0x0001U << FS26_M_VBSTOC_M_SHIFT)

/* Interrupt MASKED */
#define FS26_M_VPREUVH_M_MASKED          (0x0000U << FS26_M_VPREUVH_M_SHIFT)
/* Interrupt NOT MASKED */
#define FS26_M_VPREUVH_M_NOT_MASKED      (0x0001U << FS26_M_VPREUVH_M_SHIFT)

/* Interrupt MASKED */
#define FS26_M_VBSTOV_M_MASKED           (0x0000U << FS26_M_VBSTOV_M_SHIFT)
/* Interrupt NOT MASKED */
#define FS26_M_VBSTOV_M_NOT_MASKED       (0x0001U << FS26_M_VBSTOV_M_SHIFT)

/******************************************************************************/
/* M_VSUP_FLG - Type: RW                                                      */
/******************************************************************************/
#define FS26_M_VSUP_FLG_ADDR             0x07U
#define FS26_M_VSUP_FLG_DEFAULT          0x0000U

/* Interrupt flag when VSUP has crossed its UVH threshold on the falling edge */
#define FS26_M_VSUPUVH_I_MASK            0x0001U
#define FS26_M_VSUPUVH_I_SHIFT           0x0000U
/* Interrupt flag when VSUP has crossed its UV6 threshold on the falling edge */
#define FS26_M_VSUPUV6_I_MASK            0x0002U
#define FS26_M_VSUPUV6_I_SHIFT           0x0001U
/* Interrupt flag when VSUP has crossed its OV threshold on the rising edge */
#define FS26_M_VSUPOV_I_MASK             0x0004U
#define FS26_M_VSUPOV_I_SHIFT            0x0002U
/* Interrupt flag when VBOS has crossed its UVH threshold on the falling edge */
#define FS26_M_VBOSUVH_I_MASK            0x0008U
#define FS26_M_VBOSUVH_I_SHIFT           0x0003U

/* No VSUP UVH event detected */
#define FS26_M_VSUPUVH_I_NO_EVENT        (0x0000U << FS26_M_VSUPUVH_I_SHIFT)
/* VSUP UVH event occurred */
#define FS26_M_VSUPUVH_I_EVENT           (0x0001U << FS26_M_VSUPUVH_I_SHIFT)

/* No VSUP UV6 event detected */
#define FS26_M_VSUPUV6_I_NO_EVENT        (0x0000U << FS26_M_VSUPUV6_I_SHIFT)
/* VSUP UV6 event occurred */
#define FS26_M_VSUPUV6_I_EVENT           (0x0001U << FS26_M_VSUPUV6_I_SHIFT)

/* No VSUP OV event detected */
#define FS26_M_VSUPOV_I_NO_EVENT         (0x0000U << FS26_M_VSUPOV_I_SHIFT)
/* VSUP OV event occurred */
#define FS26_M_VSUPOV_I_EVENT            (0x0001U << FS26_M_VSUPOV_I_SHIFT)

/* No VBOS UVH event detected */
#define FS26_M_VBOSUVH_I_NO_EVENT        (0x0000U << FS26_M_VBOSUVH_I_SHIFT)
/* VBOS UVH event occurred */
#define FS26_M_VBOSUVH_I_EVENT           (0x0001U << FS26_M_VBOSUVH_I_SHIFT)

/******************************************************************************/
/* M_VSUP_MSK - Type: RW                                                      */
/******************************************************************************/
#define FS26_M_VSUP_MSK_ADDR             0x08U
#define FS26_M_VSUP_MSK_DEFAULT          0x0000U

/* Inhibit Interrupt when VSUP UVH event occurs */
#define FS26_M_VSUPUVH_M_MASK            0x0001U
#define FS26_M_VSUPUVH_M_SHIFT           0x0000U
/* Inhibit Interrupt when VSUP UV6 event occurs */
#define FS26_M_VSUPUV6_M_MASK            0x0002U
#define FS26_M_VSUPUV6_M_SHIFT           0x0001U
/* Inhibit Interrupt when VSUP Over Voltage event occurs */
#define FS26_M_VSUPOV_M_MASK             0x0004U
#define FS26_M_VSUPOV_M_SHIFT            0x0002U
/* Inhibit Interrupt when VBOS UVH event occurs */
#define FS26_M_VBOSUVH_M_MASK            0x0008U
#define FS26_M_VBOSUVH_M_SHIFT           0x0003U

/* Interrupt MASKED */
#define FS26_M_VSUPUVH_M_MASKED          (0x0000U << FS26_M_VSUPUVH_M_SHIFT)
/* Interrupt NOT MASKED */
#define FS26_M_VSUPUVH_M_NOT_MASKED      (0x0001U << FS26_M_VSUPUVH_M_SHIFT)

/* Interrupt MASKED */
#define FS26_M_VSUPUV6_M_MASKED          (0x0000U << FS26_M_VSUPUV6_M_SHIFT)
/* Interrupt NOT MASKED */
#define FS26_M_VSUPUV6_M_NOT_MASKED      (0x0001U << FS26_M_VSUPUV6_M_SHIFT)

/* Interrupt MASKED */
#define FS26_M_VSUPOV_M_MASKED           (0x0000U << FS26_M_VSUPOV_M_SHIFT)
/* Interrupt NOT MASKED */
#define FS26_M_VSUPOV_M_NOT_MASKED       (0x0001U << FS26_M_VSUPOV_M_SHIFT)

/* Interrupt MASKED */
#define FS26_M_VBOSUVH_M_MASKED          (0x0000U << FS26_M_VBOSUVH_M_SHIFT)
/* Interrupt NOT MASKED */
#define FS26_M_VBOSUVH_M_NOT_MASKED      (0x0001U << FS26_M_VBOSUVH_M_SHIFT)

/******************************************************************************/
/* M_WIO_FLG - Type: RW                                                       */
/******************************************************************************/
#define FS26_M_WIO_FLG_ADDR              0x09U
#define FS26_M_WIO_FLG_DEFAULT           0x0000U

/* WAKE1 event Flag */
#define FS26_M_WK1_I_MASK                0x0001U
#define FS26_M_WK1_I_SHIFT               0x0000U
/* WAKE2 event Flag */
#define FS26_M_WK2_I_MASK                0x0002U
#define FS26_M_WK2_I_SHIFT               0x0001U
/* GPIO1 event Flag */
#define FS26_M_IO1_I_MASK                0x0004U
#define FS26_M_IO1_I_SHIFT               0x0002U
/* GPIO2 event Flag */
#define FS26_M_IO2_I_MASK                0x0008U
#define FS26_M_IO2_I_SHIFT               0x0003U
/* LDT event Flag */
#define FS26_M_LDT_I_MASK                0x0010U
#define FS26_M_LDT_I_SHIFT               0x0004U
/* Wake-up Event Source */
#define FS26_M_WUEVENT_MASK              0x0F00U
#define FS26_M_WUEVENT_SHIFT             0x0008U
/* Clear Wake up Flags */
#define FS26_M_WU_CLR_MASK               0x8000U
#define FS26_M_WU_CLR_SHIFT              0x000FU

/* No event on WAKE1 */
#define FS26_M_WK1_I_NO_EVENT            (0x0000U << FS26_M_WK1_I_SHIFT)
/* Event on WAKE1 has occurred */
#define FS26_M_WK1_I_EVENT               (0x0001U << FS26_M_WK1_I_SHIFT)

/* No event on WAKE2 */
#define FS26_M_WK2_I_NO_EVENT            (0x0000U << FS26_M_WK2_I_SHIFT)
/* Event on WAKE2 has occurred */
#define FS26_M_WK2_I_EVENT               (0x0001U << FS26_M_WK2_I_SHIFT)

/* No event on GPIO1 */
#define FS26_M_IO1_I_NO_EVENT            (0x0000U << FS26_M_IO1_I_SHIFT)
/* Event on GPIO1 has occurred */
#define FS26_M_IO1_I_EVENT               (0x0001U << FS26_M_IO1_I_SHIFT)

/* No event on GPIO2 */
#define FS26_M_IO2_I_NO_EVENT            (0x0000U << FS26_M_IO2_I_SHIFT)
/* Event on GPIO2 has occurred */
#define FS26_M_IO2_I_EVENT               (0x0001U << FS26_M_IO2_I_SHIFT)

/* No event on LDT */
#define FS26_M_LDT_I_NO_EVENT            (0x0000U << FS26_M_LDT_I_SHIFT)
/* LDT Expire Event has occurred */
#define FS26_M_LDT_I_EVENT               (0x0001U << FS26_M_LDT_I_SHIFT)

/* No Wake up detected */
#define FS26_M_WUEVENT_NO_WAKE           (0x0000U << FS26_M_WUEVENT_SHIFT)
/* WAKE1 */
#define FS26_M_WUEVENT_WAKE1             (0x0001U << FS26_M_WUEVENT_SHIFT)
/* WAKE2 */
#define FS26_M_WUEVENT_WAKE2             (0x0002U << FS26_M_WUEVENT_SHIFT)
/* GPIO1 */
#define FS26_M_WUEVENT_GPIO1             (0x0003U << FS26_M_WUEVENT_SHIFT)
/* GPIO2 */
#define FS26_M_WUEVENT_GPIO2             (0x0004U << FS26_M_WUEVENT_SHIFT)
/* LDT expired */
#define FS26_M_WUEVENT_LDT_EXP           (0x0005U << FS26_M_WUEVENT_SHIFT)
/* SPI activity */
#define FS26_M_WUEVENT_SPI_ACTIVE        (0x0006U << FS26_M_WUEVENT_SHIFT)
/* Reserved */
#define FS26_M_WUEVENT_RES_7             (0x0007U << FS26_M_WUEVENT_SHIFT)
/* DFS Recovery */
#define FS26_M_WUEVENT_DFS_REC           (0x0008U << FS26_M_WUEVENT_SHIFT)
/* Reserved */
#define FS26_M_WUEVENT_RES_9             (0x0009U << FS26_M_WUEVENT_SHIFT)
/* Reserved */
#define FS26_M_WUEVENT_RES_10            (0x000AU << FS26_M_WUEVENT_SHIFT)
/* Reserved */
#define FS26_M_WUEVENT_RES_11            (0x000BU << FS26_M_WUEVENT_SHIFT)
/* Reserved */
#define FS26_M_WUEVENT_RES_12            (0x000CU << FS26_M_WUEVENT_SHIFT)
/* Reserved */
#define FS26_M_WUEVENT_RES_13            (0x000DU << FS26_M_WUEVENT_SHIFT)
/* Reserved */
#define FS26_M_WUEVENT_RES_14            (0x000EU << FS26_M_WUEVENT_SHIFT)
/* BATTERY fail */
#define FS26_M_WUEVENT_BATT_FAIL         (0x000FU << FS26_M_WUEVENT_SHIFT)

/* Do nothing */
#define FS26_M_WU_CLR_NOTHING            (0x0000U << FS26_M_WU_CLR_SHIFT)
/* Clear all Wakeup Flags */
#define FS26_M_WU_CLR_CLEAR_ALL          (0x0001U << FS26_M_WU_CLR_SHIFT)

/******************************************************************************/
/* M_WIO_MSK - Type: RW                                                       */
/******************************************************************************/
#define FS26_M_WIO_MSK_ADDR              0x0AU
#define FS26_M_WIO_MSK_DEFAULT           0x0000U

/* Inhibit interrupt when WAKE1 event occurs */
#define FS26_M_WK1_M_MASK                0x0001U
#define FS26_M_WK1_M_SHIFT               0x0000U
/* Inhibit Interrupt when WAKE2 event occurs */
#define FS26_M_WK2_M_MASK                0x0002U
#define FS26_M_WK2_M_SHIFT               0x0001U
/* Inhibit Interrupt when GPIO1 event occurs */
#define FS26_M_IO1_M_MASK                0x0004U
#define FS26_M_IO1_M_SHIFT               0x0002U
/* Inhibit Interrupt when GPIO2 event occurs */
#define FS26_M_IO2_M_MASK                0x0008U
#define FS26_M_IO2_M_SHIFT               0x0003U
/* Inhibit Interrupt if LDT event occurs */
#define FS26_M_LDT_M_MASK                0x0010U
#define FS26_M_LDT_M_SHIFT               0x0004U

/* Interrupt NOT MASKED */
#define FS26_M_WK1_M_NOT_MASKED          (0x0000U << FS26_M_WK1_M_SHIFT)
/* Interrupt MASKED */
#define FS26_M_WK1_M_MASKED              (0x0001U << FS26_M_WK1_M_SHIFT)

/* Interrupt NOT MASKED */
#define FS26_M_WK2_M_NOT_MASKED          (0x0000U << FS26_M_WK2_M_SHIFT)
/* Interrupt MASKED */
#define FS26_M_WK2_M_MASKED              (0x0001U << FS26_M_WK2_M_SHIFT)

/* Interrupt NOT MASKED */
#define FS26_M_IO1_M_NOT_MASKED          (0x0000U << FS26_M_IO1_M_SHIFT)
/* Interrupt MASKED */
#define FS26_M_IO1_M_MASKED              (0x0001U << FS26_M_IO1_M_SHIFT)

/* Interrupt NOT MASKED */
#define FS26_M_IO2_M_NOT_MASKED          (0x0000U << FS26_M_IO2_M_SHIFT)
/* Interrupt MASKED */
#define FS26_M_IO2_M_MASKED              (0x0001U << FS26_M_IO2_M_SHIFT)

/* Interrupt NOT MASKED */
#define FS26_M_LDT_M_NOT_MASKED          (0x0000U << FS26_M_LDT_M_SHIFT)
/* Interrupt MASKED */
#define FS26_M_LDT_M_MASKED              (0x0001U << FS26_M_LDT_M_SHIFT)

/******************************************************************************/
/* M_COM_FLG - Type: RW                                                       */
/******************************************************************************/
#define FS26_M_COM_FLG_ADDR              0x0BU
#define FS26_M_COM_FLG_DEFAULT           0x0000U

/* Interrupt flag when the MCU writes to an invalid register in the Main domain */
#define FS26_M_MSPI_REQ_I_MASK           0x0001U
#define FS26_M_MSPI_REQ_I_SHIFT          0x0000U
/* Interrupt flag when the Main SPI clock provides wrong number of clock pulses */
#define FS26_M_MSPI_CLK_I_MASK           0x0002U
#define FS26_M_MSPI_CLK_I_SHIFT          0x0001U
/* Interrupt flag when the Main SPI CRC calculation is incorrect */
#define FS26_M_MSPI_CRC_I_MASK           0x0004U
#define FS26_M_MSPI_CRC_I_SHIFT          0x0002U

/* Interrupt detected */
#define FS26_M_MSPI_REQ_I_DETECTED       (0x0000U << FS26_M_MSPI_REQ_I_SHIFT)
/* Interrupt not detected */
#define FS26_M_MSPI_REQ_I_NOT_DETECTED   (0x0001U << FS26_M_MSPI_REQ_I_SHIFT)

/* Interrupt detected */
#define FS26_M_MSPI_CLK_I_DETECTED       (0x0000U << FS26_M_MSPI_CLK_I_SHIFT)
/* Interrupt not detected */
#define FS26_M_MSPI_CLK_I_NOT_DETECTED   (0x0001U << FS26_M_MSPI_CLK_I_SHIFT)

/* Interrupt detected */
#define FS26_M_MSPI_CRC_I_DETECTED       (0x0000U << FS26_M_MSPI_CRC_I_SHIFT)
/* Interrupt not detected */
#define FS26_M_MSPI_CRC_I_NOT_DETECTED   (0x0001U << FS26_M_MSPI_CRC_I_SHIFT)

/******************************************************************************/
/* M_COM_MSK - Type: RW                                                       */
/******************************************************************************/
#define FS26_M_COM_MSK_ADDR              0x0CU
#define FS26_M_COM_MSK_DEFAULT           0x0000U

/* Inhibit Interrupt when the MCU writes to invalid register */
#define FS26_M_MSPI_REQ_M_MASK           0x0001U
#define FS26_M_MSPI_REQ_M_SHIFT          0x0000U
/* Inhibit Interrupt when the SPI clock provides wrong number of clock pulses */
#define FS26_M_MSPI_CLK_M_MASK           0x0002U
#define FS26_M_MSPI_CLK_M_SHIFT          0x0001U
/* Inhibit Interrupt when the Main calculation is incorrect */
#define FS26_M_MSPI_CRC_M_MASK           0x0004U
#define FS26_M_MSPI_CRC_M_SHIFT          0x0002U

/* Interrupt NOT MASKED */
#define FS26_M_MSPI_REQ_M_NOT_MASKED     (0x0000U << FS26_M_MSPI_REQ_M_SHIFT)
/* Interrupt MASKED */
#define FS26_M_MSPI_REQ_M_MASKED         (0x0001U << FS26_M_MSPI_REQ_M_SHIFT)

/* Interrupt NOT MASKED */
#define FS26_M_MSPI_CLK_M_NOT_MASKED     (0x0000U << FS26_M_MSPI_CLK_M_SHIFT)
/* Interrupt MASKED */
#define FS26_M_MSPI_CLK_M_MASKED         (0x0001U << FS26_M_MSPI_CLK_M_SHIFT)

/* Interrupt NOT MASKED */
#define FS26_M_MSPI_CRC_M_NOT_MASKED     (0x0000U << FS26_M_MSPI_CRC_M_SHIFT)
/* Interrupt MASKED */
#define FS26_M_MSPI_CRC_M_MASKED         (0x0001U << FS26_M_MSPI_CRC_M_SHIFT)

/******************************************************************************/
/* M_SYS_CFG - Type: RW                                                       */
/******************************************************************************/
#define FS26_M_SYS_CFG_ADDR              0x0DU
#define FS26_M_SYS_CFG_DEFAULT           0x0000U

/* Frequency Spread Spectrum enable */
#define FS26_M_FSS_EN_MASK               0x0001U
#define FS26_M_FSS_EN_SHIFT              0x0000U
/* Frequency modulation during FSS Operation */
#define FS26_M_FSS_FMOD_MASK             0x0004U
#define FS26_M_FSS_FMOD_SHIFT            0x0002U
/* INTB Test pulse width */
#define FS26_M_INT_PWIDTH_MASK           0x0008U
#define FS26_M_INT_PWIDTH_SHIFT          0x0003U
/* Manual Test of INTB pin */
#define FS26_M_INTB_TEST_MASK            0x0010U
#define FS26_M_INTB_TEST_SHIFT           0x0004U
/* Clear Retry Counter */
#define FS26_M_RETRY_CLR_MASK            0x0080U
#define FS26_M_RETRY_CLR_SHIFT           0x0007U
/* Retry counter time (ms) */
#define FS26_M_RETRY_CNT_MASK            0xFF00U
#define FS26_M_RETRY_CNT_SHIFT           0x0008U

/* FSS is Disabled */
#define FS26_M_FSS_EN_DISABLED           (0x0000U << FS26_M_FSS_EN_SHIFT)
/* FSS is Enabled */
#define FS26_M_FSS_EN_ENABLED            (0x0001U << FS26_M_FSS_EN_SHIFT)

/* High Frequency Oscillator divided by 896 */
#define FS26_M_FSS_FMOD_DIV_896          (0x0000U << FS26_M_FSS_FMOD_SHIFT)
/* High Frequency Oscillator divided by 224 */
#define FS26_M_FSS_FMOD_DIV_224          (0x0001U << FS26_M_FSS_FMOD_SHIFT)

/* 25us */
#define FS26_M_INT_PWIDTH_25US           (0x0000U << FS26_M_INT_PWIDTH_SHIFT)
/* 100us */
#define FS26_M_INT_PWIDTH_100US          (0x0001U << FS26_M_INT_PWIDTH_SHIFT)

/* No effect */
#define FS26_M_INTB_TEST_NO_EFFECT       (0x0000U << FS26_M_INTB_TEST_SHIFT)
/* Enable manual test */
#define FS26_M_INTB_TEST_MANUAL          (0x0001U << FS26_M_INTB_TEST_SHIFT)

/* No effect */
#define FS26_M_RETRY_CLR_NO_EFFECT       (0x0000U << FS26_M_RETRY_CLR_SHIFT)
/* Clear Retry Counter */
#define FS26_M_RETRY_CLR_CLEAR           (0x0001U << FS26_M_RETRY_CLR_SHIFT)

/* 100 */
#define FS26_M_RETRY_CNT_100             (0x0000U << FS26_M_RETRY_CNT_SHIFT)
/* 200 */
#define FS26_M_RETRY_CNT_200             (0x0001U << FS26_M_RETRY_CNT_SHIFT)
/* 400 */
#define FS26_M_RETRY_CNT_400             (0x0002U << FS26_M_RETRY_CNT_SHIFT)
/* 800 */
#define FS26_M_RETRY_CNT_800             (0x0003U << FS26_M_RETRY_CNT_SHIFT)
/* 1600 */
#define FS26_M_RETRY_CNT_1600            (0x0004U << FS26_M_RETRY_CNT_SHIFT)
/* 3200 */
#define FS26_M_RETRY_CNT_3200            (0x0005U << FS26_M_RETRY_CNT_SHIFT)
/* 6400 */
#define FS26_M_RETRY_CNT_6400            (0x0006U << FS26_M_RETRY_CNT_SHIFT)
/* 12800 */
#define FS26_M_RETRY_CNT_12800           (0x0007U << FS26_M_RETRY_CNT_SHIFT)
/* 25600 */
#define FS26_M_RETRY_CNT_25600           (0x0008U << FS26_M_RETRY_CNT_SHIFT)
/* 51200 */
#define FS26_M_RETRY_CNT_51200           (0x0009U << FS26_M_RETRY_CNT_SHIFT)
/* 102400 */
#define FS26_M_RETRY_CNT_102400          (0x000AU << FS26_M_RETRY_CNT_SHIFT)
/* 204800 */
#define FS26_M_RETRY_CNT_204800          (0x000BU << FS26_M_RETRY_CNT_SHIFT)
/* 409600 */
#define FS26_M_RETRY_CNT_409600          (0x000CU << FS26_M_RETRY_CNT_SHIFT)
/* 819200 */
#define FS26_M_RETRY_CNT_819200          (0x000DU << FS26_M_RETRY_CNT_SHIFT)
/* 1638400 */
#define FS26_M_RETRY_CNT_1638400         (0x000EU << FS26_M_RETRY_CNT_SHIFT)

/******************************************************************************/
/* M_TSD_CFG - Type: RW                                                       */
/******************************************************************************/
#define FS26_M_TSD_CFG_ADDR              0x0EU
#define FS26_M_TSD_CFG_DEFAULT           0x0000U

/* Deep Fail-Safe request in case of LDO1 Thermal Shutdown */
#define FS26_M_LDO1TDFS_MASK             0x0001U
#define FS26_M_LDO1TDFS_SHIFT            0x0000U
/* Deep Fail-Safe request in case of LDO2 Thermal Shutdown */
#define FS26_M_LDO2TDFS_MASK             0x0002U
#define FS26_M_LDO2TDFS_SHIFT            0x0001U
/* Deep Fail-Safe request in case of VCORE Thermal Shutdown */
#define FS26_M_CORETDFS_MASK             0x0004U
#define FS26_M_CORETDFS_SHIFT            0x0002U
/* Deep Fail-Safe request in case of TRK1 Thermal Shutdown */
#define FS26_M_TRK1TDFS_MASK             0x0008U
#define FS26_M_TRK1TDFS_SHIFT            0x0003U
/* Deep Fail-Safe request in case of TRK2 Thermal Shutdown */
#define FS26_M_TRK2TDFS_MASK             0x0010U
#define FS26_M_TRK2TDFS_SHIFT            0x0004U
/* Deep Fail-Safe request in case of VPRE Thermal Shutdown */
#define FS26_M_VPRETDFS_MASK             0x0020U
#define FS26_M_VPRETDFS_SHIFT            0x0005U

/* No effect */
#define FS26_M_LDO1TDFS_NO_EFFECT        (0x0000U << FS26_M_LDO1TDFS_SHIFT)
/* Request Transition */
#define FS26_M_LDO1TDFS_REQ_TRANSITION   (0x0001U << FS26_M_LDO1TDFS_SHIFT)

/* No effect */
#define FS26_M_LDO2TDFS_NO_EFFECT        (0x0000U << FS26_M_LDO2TDFS_SHIFT)
/* Request Transition */
#define FS26_M_LDO2TDFS_REQ_TRANSITION   (0x0001U << FS26_M_LDO2TDFS_SHIFT)

/* No effect */
#define FS26_M_CORETDFS_NO_EFFECT        (0x0000U << FS26_M_CORETDFS_SHIFT)
/* Request Transition */
#define FS26_M_CORETDFS_REQ_TRANSITION   (0x0001U << FS26_M_CORETDFS_SHIFT)

/* No effect */
#define FS26_M_TRK1TDFS_NO_EFFECT        (0x0000U << FS26_M_TRK1TDFS_SHIFT)
/* Request Transition */
#define FS26_M_TRK1TDFS_REQ_TRANSITION   (0x0001U << FS26_M_TRK1TDFS_SHIFT)

/* No effect */
#define FS26_M_TRK2TDFS_NO_EFFECT        (0x0000U << FS26_M_TRK2TDFS_SHIFT)
/* Request Transition */
#define FS26_M_TRK2TDFS_REQ_TRANSITION   (0x0001U << FS26_M_TRK2TDFS_SHIFT)

/* No effect */
#define FS26_M_VPRETDFS_NO_EFFECT        (0x0000U << FS26_M_VPRETDFS_SHIFT)
/* Request Transition */
#define FS26_M_VPRETDFS_REQ_TRANSITION   (0x0001U << FS26_M_VPRETDFS_SHIFT)

/******************************************************************************/
/* M_REG_CFG - Type: RW                                                       */
/******************************************************************************/
#define FS26_M_REG_CFG_ADDR              0x0FU
#define FS26_M_REG_CFG_DEFAULT           0x0000U

/* VBST output verification mode */
#define FS26_M_VBST_TMD_MASK             0x0001U
#define FS26_M_VBST_TMD_SHIFT            0x0000U
/* VREF Internal pulldown configuration */
#define FS26_M_VREF_PD_MASK              0x0002U
#define FS26_M_VREF_PD_SHIFT             0x0001U

/* VBST output is regulated to the configured voltage set by OTP */
#define FS26_M_VBST_TMD_OTP              (0x0000U << FS26_M_VBST_TMD_SHIFT)
/* VBST regulate to 17V to verify availability */
#define FS26_M_VBST_TMD_17V              (0x0001U << FS26_M_VBST_TMD_SHIFT)

/* Disable internal pulldown when VREF output is disabled */
#define FS26_M_VREF_PD_DISABLED          (0x0000U << FS26_M_VREF_PD_SHIFT)
/* Enable internal pulldown when VREF output is disabled */
#define FS26_M_VREF_PD_ENABLED           (0x0001U << FS26_M_VREF_PD_SHIFT)

/******************************************************************************/
/* M_WIO_CFG - Type: RW                                                       */
/******************************************************************************/
#define FS26_M_WIO_CFG_ADDR              0x10U
#define FS26_M_WIO_CFG_DEFAULT           0x0000U

/* WAKE1 wake-up enabled */
#define FS26_M_WK1WUEN_MASK              0x0001U
#define FS26_M_WK1WUEN_SHIFT             0x0000U
/* WAKE2 wake-up enabled */
#define FS26_M_WK2WUEN_MASK              0x0002U
#define FS26_M_WK2WUEN_SHIFT             0x0001U
/* GPIO1 wake-up enabled */
#define FS26_M_IO1WUEN_MASK              0x0004U
#define FS26_M_IO1WUEN_SHIFT             0x0002U
/* GPIO2 wake-up enabled */
#define FS26_M_IO2WUEN_MASK              0x0008U
#define FS26_M_IO2WUEN_SHIFT             0x0003U
/* Long Duration Timer wake-up enabled */
#define FS26_M_LDTWUEN_MASK              0x0010U
#define FS26_M_LDTWUEN_SHIFT             0x0004U
/* CSB Transition wake-up enabled */
#define FS26_M_CSBWUEN_MASK              0x0020U
#define FS26_M_CSBWUEN_SHIFT             0x0005U
/* WAKE1 event detection polarity */
#define FS26_M_WAKE1POL_MASK             0x0100U
#define FS26_M_WAKE1POL_SHIFT            0x0008U
/* WAKE2 event detection polarity */
#define FS26_M_WAKE2POL_MASK             0x0200U
#define FS26_M_WAKE2POL_SHIFT            0x0009U
/* GPIO1 event detection polarity */
#define FS26_M_IO1WUPOL_MASK             0x0400U
#define FS26_M_IO1WUPOL_SHIFT            0x000AU
/* GPIO2 event detection polarity */
#define FS26_M_IO2WUPOL_MASK             0x0800U
#define FS26_M_IO2WUPOL_SHIFT            0x000BU

/* Enabled */
#define FS26_M_WK1WUEN_ENABLED           (0x0000U << FS26_M_WK1WUEN_SHIFT)
/* Disabled */
#define FS26_M_WK1WUEN_DISABLED          (0x0001U << FS26_M_WK1WUEN_SHIFT)

/* Enabled */
#define FS26_M_WK2WUEN_ENABLED           (0x0000U << FS26_M_WK2WUEN_SHIFT)
/* Disabled */
#define FS26_M_WK2WUEN_DISABLED          (0x0001U << FS26_M_WK2WUEN_SHIFT)

/* Enabled */
#define FS26_M_IO1WUEN_ENABLED           (0x0000U << FS26_M_IO1WUEN_SHIFT)
/* Disabled */
#define FS26_M_IO1WUEN_DISABLED          (0x0001U << FS26_M_IO1WUEN_SHIFT)

/* Enabled */
#define FS26_M_IO2WUEN_ENABLED           (0x0000U << FS26_M_IO2WUEN_SHIFT)
/* Disabled */
#define FS26_M_IO2WUEN_DISABLED          (0x0001U << FS26_M_IO2WUEN_SHIFT)

/* Enabled */
#define FS26_M_LDTWUEN_ENABLED           (0x0000U << FS26_M_LDTWUEN_SHIFT)
/* Disabled */
#define FS26_M_LDTWUEN_DISABLED          (0x0001U << FS26_M_LDTWUEN_SHIFT)

/* Enabled */
#define FS26_M_CSBWUEN_ENABLED           (0x0000U << FS26_M_CSBWUEN_SHIFT)
/* Disabled */
#define FS26_M_CSBWUEN_DISABLED          (0x0001U << FS26_M_CSBWUEN_SHIFT)

/* High */
#define FS26_M_WAKE1POL_HIGH             (0x0000U << FS26_M_WAKE1POL_SHIFT)
/* Low */
#define FS26_M_WAKE1POL_LOW              (0x0001U << FS26_M_WAKE1POL_SHIFT)

/* High */
#define FS26_M_WAKE2POL_HIGH             (0x0000U << FS26_M_WAKE2POL_SHIFT)
/* Low */
#define FS26_M_WAKE2POL_LOW              (0x0001U << FS26_M_WAKE2POL_SHIFT)

/* High */
#define FS26_M_IO1WUPOL_HIGH             (0x0000U << FS26_M_IO1WUPOL_SHIFT)
/* Low */
#define FS26_M_IO1WUPOL_LOW              (0x0001U << FS26_M_IO1WUPOL_SHIFT)

/* High */
#define FS26_M_IO2WUPOL_HIGH             (0x0000U << FS26_M_IO2WUPOL_SHIFT)
/* Low */
#define FS26_M_IO2WUPOL_LOW              (0x0001U << FS26_M_IO2WUPOL_SHIFT)

/******************************************************************************/
/* M_REG_CTRL1 - Type: RW                                                     */
/******************************************************************************/
#define FS26_M_REG_CTRL1_ADDR            0x11U
#define FS26_M_REG_CTRL1_DEFAULT         0x0000U

/* LDO1 Enable request */
#define FS26_M_LDO1EN_MASK               0x0001U
#define FS26_M_LDO1EN_SHIFT              0x0000U
/* LDO2 Enable request */
#define FS26_M_LDO2EN_MASK               0x0002U
#define FS26_M_LDO2EN_SHIFT              0x0001U
/* VCORE Enable request */
#define FS26_M_COREEN_MASK               0x0004U
#define FS26_M_COREEN_SHIFT              0x0002U
/* TRK1 Enable request */
#define FS26_M_TRK1EN_MASK               0x0008U
#define FS26_M_TRK1EN_SHIFT              0x0003U
/* TRK2 Enable request */
#define FS26_M_TRK2EN_MASK               0x0010U
#define FS26_M_TRK2EN_SHIFT              0x0004U
/* VBST Enable request */
#define FS26_M_VBSTEN_MASK               0x0040U
#define FS26_M_VBSTEN_SHIFT              0x0006U
/* VREF Enable request */
#define FS26_M_VREFEN_MASK               0x0080U
#define FS26_M_VREFEN_SHIFT              0x0007U
/* Request GPIO1 pin High */
#define FS26_M_IO1HI_MASK                0x0100U
#define FS26_M_IO1HI_SHIFT               0x0008U
/* Request GPIO2 pin High */
#define FS26_M_IO2HI_MASK                0x0200U
#define FS26_M_IO2HI_SHIFT               0x0009U
/* Request GPIO2 keep on */
#define FS26_M_IO2ON_MASK                0x2000U
#define FS26_M_IO2ON_SHIFT               0x0012U

/* No effect (Regulator remain in its current state) */
#define FS26_M_LDO1EN_NO_EFFECT          (0x0000U << FS26_M_LDO1EN_SHIFT)
/* LDO1 Enable request */
#define FS26_M_LDO1EN_REQ                (0x0001U << FS26_M_LDO1EN_SHIFT)

/* No effect (Regulator remain in its current state) */
#define FS26_M_LDO2EN_NO_EFFECT          (0x0000U << FS26_M_LDO2EN_SHIFT)
/* LDO2 Enable request */
#define FS26_M_LDO2EN_REQ                (0x0001U << FS26_M_LDO2EN_SHIFT)

/* No effect (Regulator remain in its current state) */
#define FS26_M_COREEN_NO_EFFECT          (0x0000U << FS26_M_COREEN_SHIFT)
/* VCORE Enable request */
#define FS26_M_COREEN_REQ                (0x0001U << FS26_M_COREEN_SHIFT)

/* No effect (Regulator remain in its current state) */
#define FS26_M_TRK1EN_NO_EFFECT          (0x0000U << FS26_M_TRK1EN_SHIFT)
/* TRK1 Enable request */
#define FS26_M_TRK1EN_REQ                (0x0001U << FS26_M_TRK1EN_SHIFT)

/* No effect (Regulator remain in its current state) */
#define FS26_M_TRK2EN_NO_EFFECT          (0x0000U << FS26_M_TRK2EN_SHIFT)
/* TRK2 Enable request */
#define FS26_M_TRK2EN_REQ                (0x0001U << FS26_M_TRK2EN_SHIFT)

/* No effect (Regulator remain in its current state) */
#define FS26_M_VBSTEN_NO_EFFECT          (0x0000U << FS26_M_VBSTEN_SHIFT)
/* VBST Enable request */
#define FS26_M_VBSTEN_REQ                (0x0001U << FS26_M_VBSTEN_SHIFT)

/* No effect (Regulator remain in its current state) */
#define FS26_M_VREFEN_NO_EFFECT          (0x0000U << FS26_M_VREFEN_SHIFT)
/* VREF Enable request */
#define FS26_M_VREFEN_REQ                (0x0001U << FS26_M_VREFEN_SHIFT)

/* No effect (GPIO1 remains in current state) */
#define FS26_M_IO1HI_NO_EFFECT           (0x0000U << FS26_M_IO1HI_SHIFT)
/* GPIO1 set high */
#define FS26_M_IO1HI_REQ                 (0x0001U << FS26_M_IO1HI_SHIFT)

/* No effect (GPIO2 remains in current state) */
#define FS26_M_IO2HI_NO_EFFECT           (0x0000U << FS26_M_IO2HI_SHIFT)
/* GPIO2 set high */
#define FS26_M_IO2HI_REQ                 (0x0001U << FS26_M_IO2HI_SHIFT)

/******************************************************************************/
/* M_REG_CTRL2 - Type: RW                                                     */
/******************************************************************************/
#define FS26_M_REG_CTRL2_ADDR            0x12U
#define FS26_M_REG_CTRL2_DEFAULT         0x0000U

/* LDO1 Disable request */
#define FS26_M_LDO1DIS_MASK              0x0001U
#define FS26_M_LDO1DIS_SHIFT             0x0000U
/* LDO2 Disable request */
#define FS26_M_LDO2DIS_MASK              0x0002U
#define FS26_M_LDO2DIS_SHIFT             0x0001U
/* VCORE Disable request */
#define FS26_M_COREDIS_MASK              0x0004U
#define FS26_M_COREDIS_SHIFT             0x0002U
/* TRK1 Disable request */
#define FS26_M_TRK1DIS_MASK              0x0008U
#define FS26_M_TRK1DIS_SHIFT             0x0003U
/* TRK2 Disable request */
#define FS26_M_TRK2DIS_MASK              0x0010U
#define FS26_M_TRK2DIS_SHIFT             0x0004U
/* VBST Disable request */
#define FS26_M_VBSTDIS_MASK              0x0040U
#define FS26_M_VBSTDIS_SHIFT             0x0006U
/* VREF Disable request */
#define FS26_M_VREFDIS_MASK              0x0080U
#define FS26_M_VREFDIS_SHIFT             0x0007U
/* Request GPIO1 pin Low */
#define FS26_M_IO1LO_MASK                0x0100U
#define FS26_M_IO1LO_SHIFT               0x0008U
/* Request GPIO2 pin Low */
#define FS26_M_IO2LO_MASK                0x0200U
#define FS26_M_IO2LO_SHIFT               0x0009U

/* No effect (Regulator remain in its current state) */
#define FS26_M_LDO1DIS_NO_EFFECT         (0x0000U << FS26_M_LDO1DIS_SHIFT)
/* LDO1 Disable request */
#define FS26_M_LDO1DIS_REQ               (0x0001U << FS26_M_LDO1DIS_SHIFT)

/* No effect (Regulator remain in its current state) */
#define FS26_M_LDO2DIS_NO_EFFECT         (0x0000U << FS26_M_LDO2DIS_SHIFT)
/* LDO2 Disable request */
#define FS26_M_LDO2DIS_REQ               (0x0001U << FS26_M_LDO2DIS_SHIFT)

/* No effect (Regulator remain in its current state) */
#define FS26_M_COREDIS_NO_EFFECT         (0x0000U << FS26_M_COREDIS_SHIFT)
/* VCORE Disable request */
#define FS26_M_COREDIS_REQ               (0x0001U << FS26_M_COREDIS_SHIFT)

/* No effect (Regulator remain in its current state) */
#define FS26_M_TRK1DIS_NO_EFFECT         (0x0000U << FS26_M_TRK1DIS_SHIFT)
/* TRK1 Disable request */
#define FS26_M_TRK1DIS_REQ               (0x0001U << FS26_M_TRK1DIS_SHIFT)

/* No effect (Regulator remain in its current state) */
#define FS26_M_TRK2DIS_NO_EFFECT         (0x0000U << FS26_M_TRK2DIS_SHIFT)
/* TRK2 Disable request */
#define FS26_M_TRK2DIS_REQ               (0x0001U << FS26_M_TRK2DIS_SHIFT)

/* No effect (Regulator remain in its current state) */
#define FS26_M_VBSTDIS_NO_EFFECT         (0x0000U << FS26_M_VBSTDIS_SHIFT)
/* VBST Disable request */
#define FS26_M_VBSTDIS_REQ               (0x0001U << FS26_M_VBSTDIS_SHIFT)

/* No effect (Regulator remain in its current state) */
#define FS26_M_VREFDIS_NO_EFFECT         (0x0000U << FS26_M_VREFDIS_SHIFT)
/* VREF Disable request */
#define FS26_M_VREFDIS_REQ               (0x0001U << FS26_M_VREFDIS_SHIFT)

/* No effect (GPIO1 remains in current state) */
#define FS26_M_IO1LO_NO_EFFECT           (0x0000U << FS26_M_IO1LO_SHIFT)
/* GPIO1 set low */
#define FS26_M_IO1LO_REQ                 (0x0001U << FS26_M_IO1LO_SHIFT)

/* No effect (GPIO2 remains in current state) */
#define FS26_M_IO2LO_NO_EFFECT           (0x0000U << FS26_M_IO2LO_SHIFT)
/* GPIO2 set low */
#define FS26_M_IO2LO_REQ                 (0x0001U << FS26_M_IO2LO_SHIFT)

/******************************************************************************/
/* M_AMUX_CTRL - Type: RW                                                     */
/******************************************************************************/
#define FS26_M_AMUX_CTRL_ADDR            0x13U
#define FS26_M_AMUX_CTRL_DEFAULT         0x0000U

/* AMUX Input Channel Selection */
#define FS26_M_AMUX_MASK                 0x001FU
#define FS26_M_AMUX_SHIFT                0x0000U
/* Selection of divider ratio */
#define FS26_M_AMUX_DIV_MASK             0x0020U
#define FS26_M_AMUX_DIV_SHIFT            0x0005U
/* Enable AMUX block */
#define FS26_M_AMUX_EN_MASK              0x0040U
#define FS26_M_AMUX_EN_SHIFT             0x0006U

/* Disabled with AMUX pin in Hi-Z */
#define FS26_M_AMUX_DISABLED             (0x0000U << FS26_M_AMUX_SHIFT)
/* Low Power Bangap1 */
#define FS26_M_AMUX_LP_BANDGAP           (0x0001U << FS26_M_AMUX_SHIFT)
/* Main Bandgap2 */
#define FS26_M_AMUX_MAIN_BANDGAP         (0x0002U << FS26_M_AMUX_SHIFT)
/* Fail Safe Bandgap */
#define FS26_M_AMUX_FS_BANDGAP           (0x0003U << FS26_M_AMUX_SHIFT)
/* Vana: Internal Main analog voltage supply */
#define FS26_M_AMUX_VANA                 (0x0004U << FS26_M_AMUX_SHIFT)
/* Vdig: internal Main digital voltage supply */
#define FS26_M_AMUX_VDIG                 (0x0005U << FS26_M_AMUX_SHIFT)
/* Vdig_fs: internal Fail Safe digital voltage supply */
#define FS26_M_AMUX_VDIG_FS              (0x0006U << FS26_M_AMUX_SHIFT)
/* VCORE Voltage */
#define FS26_M_AMUX_VCORE                (0x0007U << FS26_M_AMUX_SHIFT)
/* VPRE voltage */
#define FS26_M_AMUX_VPRE                 (0x0008U << FS26_M_AMUX_SHIFT)
/* LDO1 voltage */
#define FS26_M_AMUX_LDO1                 (0x0009U << FS26_M_AMUX_SHIFT)
/* LDO2 voltage */
#define FS26_M_AMUX_LDO2                 (0x000AU << FS26_M_AMUX_SHIFT)
/* VREF voltage */
#define FS26_M_AMUX_VREF                 (0x000BU << FS26_M_AMUX_SHIFT)
/* TRK1 voltage */
#define FS26_M_AMUX_TRK1                 (0x000CU << FS26_M_AMUX_SHIFT)
/* TRK2 voltage */
#define FS26_M_AMUX_TRK2                 (0x000DU << FS26_M_AMUX_SHIFT)
/* VDDIO voltage */
#define FS26_M_AMUX_VDDIO                (0x000EU << FS26_M_AMUX_SHIFT)
/* VBOS internal voltage */
#define FS26_M_AMUX_VBOS                 (0x000FU << FS26_M_AMUX_SHIFT)
/* VBST voltage (divider ratio configurable by SPI) */
#define FS26_M_AMUX_VBST                 (0x0010U << FS26_M_AMUX_SHIFT)
/* VSUP voltage (divider ratio configurable by SPI) */
#define FS26_M_AMUX_VSUP                 (0x0011U << FS26_M_AMUX_SHIFT)
/* WAKE1 voltage (divider ratio configurable by SPI) */
#define FS26_M_AMUX_WAKE1                (0x0012U << FS26_M_AMUX_SHIFT)
/* WAKE2 voltage (divider ratio configurable by SPI) */
#define FS26_M_AMUX_WAKE2                (0x0013U << FS26_M_AMUX_SHIFT)
/* GPIO1 voltage (divider ratio configurable by SPI) */
#define FS26_M_AMUX_GPIO1                (0x0014U << FS26_M_AMUX_SHIFT)
/* GPIO2 voltage (divider ratio configurable by SPI) */
#define FS26_M_AMUX_GPIO2                (0x0015U << FS26_M_AMUX_SHIFT)
/* BATSENSE voltage (divider ratio configurable by SPI) */
#define FS26_M_AMUX_BATSENSE             (0x0016U << FS26_M_AMUX_SHIFT)
/* Die Temperature Sensor T(�C) = [(VAMUX � VTEMP25) / VTEMP_COEFF ] + 25 */
#define FS26_M_AMUX_DIE_TEMP             (0x0017U << FS26_M_AMUX_SHIFT)
/* VCORE Temperature sensor */
#define FS26_M_AMUX_VCORE_TEMP           (0x0018U << FS26_M_AMUX_SHIFT)
/* VPRE Temperature sensor */
#define FS26_M_AMUX_VPRE_TEMP            (0x0019U << FS26_M_AMUX_SHIFT)
/* LDO1 Temperature sensor */
#define FS26_M_AMUX_LDO1_TEMP            (0x001AU << FS26_M_AMUX_SHIFT)
/* LDO2 Temperature sensor */
#define FS26_M_AMUX_LDO2_TEMP            (0x001BU << FS26_M_AMUX_SHIFT)
/* TRK1 Temperature sensor */
#define FS26_M_AMUX_TRK1_TEMP            (0x001CU << FS26_M_AMUX_SHIFT)
/* TRK2 Temperature sensor */
#define FS26_M_AMUX_TRK2_TEMP            (0x001DU << FS26_M_AMUX_SHIFT)
/* GPIO1 Temperature sensor */
#define FS26_M_AMUX_GPIO1_TEMP           (0x001EU << FS26_M_AMUX_SHIFT)
/* Reserved */
#define FS26_M_AMUX_RES                  (0x001FU << FS26_M_AMUX_SHIFT)

/* Divider ratio option 0 */
#define FS26_M_AMUX_DIV_0                (0x0000U << FS26_M_AMUX_DIV_SHIFT)
/* Divider ratio option 1 */
#define FS26_M_AMUX_DIV_1                (0x0001U << FS26_M_AMUX_DIV_SHIFT)

/* Enable AMUX block */
#define FS26_M_AMUX_EN_ENABLED           (0x0000U << FS26_M_AMUX_EN_SHIFT)
/* Disable AMUX block and pin is pulled-down to ground */
#define FS26_M_AMUX_EN_DISABLED          (0x0001U << FS26_M_AMUX_EN_SHIFT)

/******************************************************************************/
/* M_LDT_CFG1 - Type: RW                                                      */
/******************************************************************************/
#define FS26_M_LDT_CFG1_ADDR             0x14U
#define FS26_M_LDT_CFG1_DEFAULT          0x0000U

/* After running LDT timer value in NORMAL mode */
#define FS26_M_LDT_AFTER_RUN_MASK        0xFFFFU
#define FS26_M_LDT_AFTER_RUN_SHIFT       0x0000U

/******************************************************************************/
/* M_LDT_CFG2 - Type: RW                                                      */
/******************************************************************************/
#define FS26_M_LDT_CFG2_ADDR             0x15U
#define FS26_M_LDT_CFG2_DEFAULT          0x0000U

/* 16 less significant bits for the wake up with the Long Duration Timer */
#define FS26_M_LDT_WUP_L_MASK            0xFFFFU
#define FS26_M_LDT_WUP_L_SHIFT           0x0000U

/******************************************************************************/
/* M_LDT_CFG3 - Type: RW                                                      */
/******************************************************************************/
#define FS26_M_LDT_CFG3_ADDR             0x16U
#define FS26_M_LDT_CFG3_DEFAULT          0x0000U

/* 8 most significant bit for the wake up with the Long Duration Timer */
#define FS26_M_LDT_WUP_H_MASK            0x00FFU
#define FS26_M_LDT_WUP_H_SHIFT           0x0000U

/******************************************************************************/
/* M_LDT_CTRL - Type: RW                                                      */
/******************************************************************************/
#define FS26_M_LDT_CTRL_ADDR             0x17U
#define FS26_M_LDT_CTRL_DEFAULT          0x0000U

/* LDT Status */
#define FS26_M_LDT_RUN_MASK              0x0001U
#define FS26_M_LDT_RUN_SHIFT             0x0000U
/* Start LDT Timer operation */
#define FS26_M_LDT_EN_MASK               0x0002U
#define FS26_M_LDT_EN_SHIFT              0x0001U
/* Set operation mode */
#define FS26_M_LDT_MODE_MASK             0x0004U
#define FS26_M_LDT_MODE_SHIFT            0x0002U
/* LDT timer read selection */
#define FS26_M_LDT_SEL_MASK              0x0008U
#define FS26_M_LDT_SEL_SHIFT             0x0003U
/* LDT function selection */
#define FS26_M_LDT_FNCT_MASK             0x0070U
#define FS26_M_LDT_FNCT_SHIFT            0x0004U

/* LDT is disabled or not counting */
#define FS26_M_LDT_RUN_DISABLED          (0x0000U << FS26_M_LDT_RUN_SHIFT)
/* LDT is Enabled and count is in progress */
#define FS26_M_LDT_RUN_ENABLED           (0x0001U << FS26_M_LDT_RUN_SHIFT)

/* Disable LDT */
#define FS26_M_LDT_EN_DISABLED           (0x0000U << FS26_M_LDT_EN_SHIFT)
/* LDT starts counting */
#define FS26_M_LDT_EN_ENABLED            (0x0001U << FS26_M_LDT_EN_SHIFT)

/* Set LDT to long count */
#define FS26_M_LDT_MODE_LONG             (0x0000U << FS26_M_LDT_MODE_SHIFT)
/* Set LDT to short count */
#define FS26_M_LDT_MODE_SHORT            (0x0001U << FS26_M_LDT_MODE_SHIFT)

/* Read/Sets Target value of Wake-up LDT timer */
#define FS26_M_LDT_SEL_TARGET            (0x0000U << FS26_M_LDT_SEL_SHIFT)
/* Read real time value of 24-bit Timer */
#define FS26_M_LDT_SEL_REALTIME          (0x0001U << FS26_M_LDT_SEL_SHIFT)

/* Function 1 */
#define FS26_M_LDT_FNCT_1                (0x0000U << FS26_M_LDT_FNCT_SHIFT)
/* Function 2 */
#define FS26_M_LDT_FNCT_2                (0x0001U << FS26_M_LDT_FNCT_SHIFT)
/* Function 3 */
#define FS26_M_LDT_FNCT_3                (0x0002U << FS26_M_LDT_FNCT_SHIFT)
/* Function 4 */
#define FS26_M_LDT_FNCT_4                (0x0003U << FS26_M_LDT_FNCT_SHIFT)
/* Function 5 */
#define FS26_M_LDT_FNCT_5                (0x0004U << FS26_M_LDT_FNCT_SHIFT)
/* Reserved */
#define FS26_M_LDT_FNCT_RES_5            (0x0005U << FS26_M_LDT_FNCT_SHIFT)
/* Reserved */
#define FS26_M_LDT_FNCT_RES_6            (0x0006U << FS26_M_LDT_FNCT_SHIFT)
/* Reserved */
#define FS26_M_LDT_FNCT_RES_7            (0x0007U << FS26_M_LDT_FNCT_SHIFT)

/******************************************************************************/
/* M_MEMORY0 - Type: RW                                                       */
/******************************************************************************/
#define FS26_M_MEMORY0_ADDR              0x18U
#define FS26_M_MEMORY0_DEFAULT           0x0000U

/* Free 16 bits for application data storage, MEM0 stored data */
#define FS26_M_MEM0_MASK                 0xFFFFU
#define FS26_M_MEM0_SHIFT                0x0000U

/******************************************************************************/
/* M_MEMORY1 - Type: RW                                                       */
/******************************************************************************/
#define FS26_M_MEMORY1_ADDR              0x19U
#define FS26_M_MEMORY1_DEFAULT           0x0000U

/* Free 16 bits for application data storage, MEM1 stored data */
#define FS26_M_MEM1_MASK                 0xFFFFU
#define FS26_M_MEM1_SHIFT                0x0000U

/******************************************************************************/
/* FS_GRL_FLAGS - Type: R                                                     */
/******************************************************************************/
#define FS26_FS_GRL_FLAGS_ADDR           0x00U
#define FS26_FS_GRL_FLAGS_DEFAULT        0x0000U

/* Report an issue on BIST (Logical or Analog) */
#define FS26_FS_FS_BIST_G_MASK           0x0800U
#define FS26_FS_FS_BIST_G_SHIFT          0x000BU
/* Report an issue in one of the voltage monitoring (OV or UV) */
#define FS26_FS_FS_REG_OVUV_G_MASK       0x1000U
#define FS26_FS_FS_REG_OVUV_G_SHIFT      0x000CU
/* Report an issue in one of the Fail Safe IOs */
#define FS26_FS_FS_IO_G_MASK             0x2000U
#define FS26_FS_FS_IO_G_SHIFT            0x000DU
/* Report an issue on the Watchdog Refresh */
#define FS26_FS_FS_WD_G_MASK             0x4000U
#define FS26_FS_FS_WD_G_SHIFT            0x000EU
/* Report an issue in the communication (SPI) */
#define FS26_FS_FS_COM_G_MASK            0x8000U
#define FS26_FS_FS_COM_G_SHIFT           0x000FU

/* No Failure */
#define FS26_FS_FS_BIST_G_NO_FAILURE     (0x0000U << FS26_FS_FS_BIST_G_SHIFT)
/* Failure */
#define FS26_FS_FS_BIST_G_FAILURE        (0x0001U << FS26_FS_FS_BIST_G_SHIFT)

/* No Failure */
#define FS26_FS_FS_REG_OVUV_G_NO_FAILURE (0x0000U << FS26_FS_FS_REG_OVUV_G_SHIFT)
/* Failure */
#define FS26_FS_FS_REG_OVUV_G_FAILURE    (0x0001U << FS26_FS_FS_REG_OVUV_G_SHIFT)

/* No Failure */
#define FS26_FS_FS_IO_G_NO_FAILURE       (0x0000U << FS26_FS_FS_IO_G_SHIFT)
/* Failure */
#define FS26_FS_FS_IO_G_FAILURE          (0x0001U << FS26_FS_FS_IO_G_SHIFT)

/* Good WD Refresh */
#define FS26_FS_FS_WD_G_GOOD_REFRESH     (0x0000U << FS26_FS_FS_WD_G_SHIFT)
/* Bad WD Refresh */
#define FS26_FS_FS_WD_G_BAD_REFRESH      (0x0001U << FS26_FS_FS_WD_G_SHIFT)

/* No Failure */
#define FS26_FS_FS_COM_G_NO_FAILURE      (0x0000U << FS26_FS_FS_COM_G_SHIFT)
/* Failure */
#define FS26_FS_FS_COM_G_FAILURE         (0x0001U << FS26_FS_FS_COM_G_SHIFT)

/******************************************************************************/
/* FS_I_OVUV_SAFE_REACTION1 - Type: RW                                        */
/******************************************************************************/
#define FS26_FS_I_OVUV_SAFE_REACTION1_ADDR    0x01U
#define FS26_FS_I_OVUV_SAFE_REACTION1_DEFAULT 0x9999U

/* Reaction on RSTB or FAIL SAFE outputs in case of UV detection on VMON_LDO2 */
#define FS26_FS_VMON_LDO2_UV_FS_REACTION_MASK  0x0003U
#define FS26_FS_VMON_LDO2_UV_FS_REACTION_SHIFT 0x0000U
/* Reaction on RSTB or FAIL SAFE outputs in case of OV detection on VMON_LDO2 */
#define FS26_FS_VMON_LDO2_OV_FS_REACTION_MASK  0x000CU
#define FS26_FS_VMON_LDO2_OV_FS_REACTION_SHIFT 0x0002U
/* Reaction on RSTB or FAIL SAFE outputs in case of UV detection on VMON_LDO1 */
#define FS26_FS_VMON_LDO1_UV_FS_REACTION_MASK  0x0030U
#define FS26_FS_VMON_LDO1_UV_FS_REACTION_SHIFT 0x0004U
/* Reaction on RSTB or FAIL SAFE outputs in case of OV detection on VMON_LDO1 */
#define FS26_FS_VMON_LDO1_OV_FS_REACTION_MASK  0x00C0U
#define FS26_FS_VMON_LDO1_OV_FS_REACTION_SHIFT 0x0006U
/* Reaction on RSTB or FAIL SAFE outputs in case of UV detection on VMON_CORE */
#define FS26_FS_VMON_CORE_UV_FS_REACTION_MASK  0x0300U
#define FS26_FS_VMON_CORE_UV_FS_REACTION_SHIFT 0x0008U
/* Reaction on RSTB or FAIL SAFE outputs in case of OV detection on VMON_CORE */
#define FS26_FS_VMON_CORE_OV_FS_REACTION_MASK  0x0C00U
#define FS26_FS_VMON_CORE_OV_FS_REACTION_SHIFT 0x000AU
/* Reaction on RSTB or FAIL SAFE outputs in case of UV detection on VMON_PRE */
#define FS26_FS_VMON_PRE_UV_FS_REACTION_MASK   0x3000U
#define FS26_FS_VMON_PRE_UV_FS_REACTION_SHIFT  0x000CU
/* Reaction on RSTB or FAIL SAFE outputs in case of OV detection on VMON_PRE */
#define FS26_FS_VMON_PRE_OV_FS_REACTION_MASK   0xC000U
#define FS26_FS_VMON_PRE_OV_FS_REACTION_SHIFT  0x000EU

/* No effect on RSTb and FS0b */
#define FS26_FS_VMON_LDO2_UV_FS_REACTION_NO_EFFECT (0x0000U << FS26_FS_VMON_LDO2_UV_FS_REACTION_SHIFT)
/* VMON_LDO2 UV asserts FS0b only */
#define FS26_FS_VMON_LDO2_UV_FS_REACTION_FS0B      (0x0001U << FS26_FS_VMON_LDO2_UV_FS_REACTION_SHIFT)
/* VMON_LDO2 UV asserts RSTb and FS0b */
#define FS26_FS_VMON_LDO2_UV_FS_REACTION_RSTB_FS0B (0x0002U << FS26_FS_VMON_LDO2_UV_FS_REACTION_SHIFT)

/* No effect on RSTb and FS0b */
#define FS26_FS_VMON_LDO2_OV_FS_REACTION_NO_EFFECT (0x0000U << FS26_FS_VMON_LDO2_OV_FS_REACTION_SHIFT)
/* VMON_LDO2 OV asserts FS0b only */
#define FS26_FS_VMON_LDO2_OV_FS_REACTION_FS0B      (0x0001U << FS26_FS_VMON_LDO2_OV_FS_REACTION_SHIFT)
/* VMON_LDO2 OV asserts RSTb and FS0b */
#define FS26_FS_VMON_LDO2_OV_FS_REACTION_RSTB_FS0B (0x0002U << FS26_FS_VMON_LDO2_OV_FS_REACTION_SHIFT)

/* No effect on RSTb and FS0b */
#define FS26_FS_VMON_LDO1_UV_FS_REACTION_NO_EFFECT (0x0000U << FS26_FS_VMON_LDO1_UV_FS_REACTION_SHIFT)
/* VMON_LDO1 UV asserts FS0b only */
#define FS26_FS_VMON_LDO1_UV_FS_REACTION_FS0B      (0x0001U << FS26_FS_VMON_LDO1_UV_FS_REACTION_SHIFT)
/* VMON_LDO1 UV asserts RSTb and FS0b */
#define FS26_FS_VMON_LDO1_UV_FS_REACTION_RSTB_FS0B (0x0002U << FS26_FS_VMON_LDO1_UV_FS_REACTION_SHIFT)

/* No effect on RSTb and FS0b */
#define FS26_FS_VMON_LDO1_OV_FS_REACTION_NO_EFFECT (0x0000U << FS26_FS_VMON_LDO1_OV_FS_REACTION_SHIFT)
/* VMON_LDO1 OV asserts FS0b only */
#define FS26_FS_VMON_LDO1_OV_FS_REACTION_FS0B      (0x0001U << FS26_FS_VMON_LDO1_OV_FS_REACTION_SHIFT)
/* VMON_LDO1 OV asserts RSTb and FS0b */
#define FS26_FS_VMON_LDO1_OV_FS_REACTION_RSTB_FS0B (0x0002U << FS26_FS_VMON_LDO1_OV_FS_REACTION_SHIFT)

/* No effect on RSTb and FS0b */
#define FS26_FS_VMON_CORE_UV_FS_REACTION_NO_EFFECT (0x0000U << FS26_FS_VMON_CORE_UV_FS_REACTION_SHIFT)
/* VMON_CORE UV asserts FS0b only */
#define FS26_FS_VMON_CORE_UV_FS_REACTION_FS0B      (0x0001U << FS26_FS_VMON_CORE_UV_FS_REACTION_SHIFT)
/* VMON_CORE UV asserts RSTb and FS0b */
#define FS26_FS_VMON_CORE_UV_FS_REACTION_RSTB_FS0B (0x0002U << FS26_FS_VMON_CORE_UV_FS_REACTION_SHIFT)

/* No effect on RSTb and FS0b */
#define FS26_FS_VMON_CORE_OV_FS_REACTION_NO_EFFECT (0x0000U << FS26_FS_VMON_CORE_OV_FS_REACTION_SHIFT)
/* VMON_CORE OV asserts FS0b only */
#define FS26_FS_VMON_CORE_OV_FS_REACTION_FS0B      (0x0001U << FS26_FS_VMON_CORE_OV_FS_REACTION_SHIFT)
/* VMON_CORE OV asserts RSTb and FS0b */
#define FS26_FS_VMON_CORE_OV_FS_REACTION_RSTB_FS0B (0x0002U << FS26_FS_VMON_CORE_OV_FS_REACTION_SHIFT)

/* No effect on RSTb and FS0b */
#define FS26_FS_VMON_PRE_UV_FS_REACTION_NO_EFFECT  (0x0000U << FS26_FS_VMON_PRE_UV_FS_REACTION_SHIFT)
/* VMON_PRE UV asserts FS0b only */
#define FS26_FS_VMON_PRE_UV_FS_REACTION_FS0B       (0x0001U << FS26_FS_VMON_PRE_UV_FS_REACTION_SHIFT)
/* VMON_PRE UV asserts RSTb and FS0b */
#define FS26_FS_VMON_PRE_UV_FS_REACTION_RSTB_FS0B  (0x0002U << FS26_FS_VMON_PRE_UV_FS_REACTION_SHIFT)

/* No effect on RSTb and FS0b */
#define FS26_FS_VMON_PRE_OV_FS_REACTION_NO_EFFECT  (0x0000U << FS26_FS_VMON_PRE_OV_FS_REACTION_SHIFT)
/* VMON_PRE OV asserts FS0b only */
#define FS26_FS_VMON_PRE_OV_FS_REACTION_FS0B       (0x0001U << FS26_FS_VMON_PRE_OV_FS_REACTION_SHIFT)
/* VMON_PRE OV asserts RSTb and FS0b */
#define FS26_FS_VMON_PRE_OV_FS_REACTION_RSTB_FS0B  (0x0002U << FS26_FS_VMON_PRE_OV_FS_REACTION_SHIFT)

/******************************************************************************/
/* FS_I_OVUV_SAFE_REACTION2 - Type: RW                                        */
/******************************************************************************/
#define FS26_FS_I_OVUV_SAFE_REACTION2_ADDR    0x03U
#define FS26_FS_I_OVUV_SAFE_REACTION2_DEFAULT 0x9999U

/* Reaction on RSTB or FAIL SAFE outputs in case of UV detection on VMON_TRK1 */
#define FS26_FS_VMON_TRK1_UV_FS_REACTION_MASK  0x0003U
#define FS26_FS_VMON_TRK1_UV_FS_REACTION_SHIFT 0x0000U
/* Reaction on RSTB or FAIL SAFE outputs in case of OV detection on VMON_TRK1 */
#define FS26_FS_VMON_TRK1_OV_FS_REACTION_MASK  0x000CU
#define FS26_FS_VMON_TRK1_OV_FS_REACTION_SHIFT 0x0002U
/* Reaction on RSTB or FAIL SAFE outputs in case of UV detection on VMON_TRK2 */
#define FS26_FS_VMON_TRK2_UV_FS_REACTION_MASK  0x0030U
#define FS26_FS_VMON_TRK2_UV_FS_REACTION_SHIFT 0x0004U
/* Reaction on RSTB or FAIL SAFE outputs in case of OV detection on VMON_TRK2 */
#define FS26_FS_VMON_TRK2_OV_FS_REACTION_MASK  0x00C0U
#define FS26_FS_VMON_TRK2_OV_FS_REACTION_SHIFT 0x0006U
/* Reaction on RSTB or FAIL SAFE outputs in case of UV detection on VMON_REF */
#define FS26_FS_VMON_REF_UV_FS_REACTION_MASK   0x0300U
#define FS26_FS_VMON_REF_UV_FS_REACTION_SHIFT  0x0008U
/* Reaction on RSTB or FAIL SAFE outputs in case of OV detection on VMON_REF */
#define FS26_FS_VMON_REF_OV_FS_REACTION_MASK   0x0C00U
#define FS26_FS_VMON_REF_OV_FS_REACTION_SHIFT  0x000AU
/* Reaction on RSTB or FAIL SAFE outputs in case of UV detection on VMON_EXT */
#define FS26_FS_VMON_EXT_UV_FS_REACTION_MASK   0x3000U
#define FS26_FS_VMON_EXT_UV_FS_REACTION_SHIFT  0x000CU
/* Reaction on RSTB or FAIL SAFE outputs in case of OV detection on VMON_EXT */
#define FS26_FS_VMON_EXT_OV_FS_REACTION_MASK   0xC000U
#define FS26_FS_VMON_EXT_OV_FS_REACTION_SHIFT  0x000EU

/* No effect on RSTb and FS0b */
#define FS26_FS_VMON_TRK1_UV_FS_REACTION_NO_EFFECT (0x0000U << FS26_FS_VMON_TRK1_UV_FS_REACTION_SHIFT)
/* VMON_TRK1 UV asserts FS0b only */
#define FS26_FS_VMON_TRK1_UV_FS_REACTION_FS0B      (0x0001U << FS26_FS_VMON_TRK1_UV_FS_REACTION_SHIFT)
/* VMON_TRK1 UV asserts RSTb and FS0b */
#define FS26_FS_VMON_TRK1_UV_FS_REACTION_RSTB_FS0B (0x0002U << FS26_FS_VMON_TRK1_UV_FS_REACTION_SHIFT)

/* No effect on RSTb and FS0b */
#define FS26_FS_VMON_TRK1_OV_FS_REACTION_NO_EFFECT (0x0000U << FS26_FS_VMON_TRK1_OV_FS_REACTION_SHIFT)
/* VMON_TRK1 OV asserts FS0b only */
#define FS26_FS_VMON_TRK1_OV_FS_REACTION_FS0B      (0x0001U << FS26_FS_VMON_TRK1_OV_FS_REACTION_SHIFT)
/* VMON_TRK1 OV asserts RSTb and FS0b */
#define FS26_FS_VMON_TRK1_OV_FS_REACTION_RSTB_FS0B (0x0002U << FS26_FS_VMON_TRK1_OV_FS_REACTION_SHIFT)

/* No effect on RSTb and FS0b */
#define FS26_FS_VMON_TRK2_UV_FS_REACTION_NO_EFFECT (0x0000U << FS26_FS_VMON_TRK2_UV_FS_REACTION_SHIFT)
/* VMON_TRK2 UV asserts FS0b only */
#define FS26_FS_VMON_TRK2_UV_FS_REACTION_FS0B      (0x0001U << FS26_FS_VMON_TRK2_UV_FS_REACTION_SHIFT)
/* VMON_TRK2 UV asserts RSTb and FS0b */
#define FS26_FS_VMON_TRK2_UV_FS_REACTION_RSTB_FS0B (0x0002U << FS26_FS_VMON_TRK2_UV_FS_REACTION_SHIFT)

/* No effect on RSTb and FS0b */
#define FS26_FS_VMON_TRK2_OV_FS_REACTION_NO_EFFECT (0x0000U << FS26_FS_VMON_TRK2_OV_FS_REACTION_SHIFT)
/* VMON_TRK2 OV asserts FS0b only */
#define FS26_FS_VMON_TRK2_OV_FS_REACTION_FS0B      (0x0001U << FS26_FS_VMON_TRK2_OV_FS_REACTION_SHIFT)
/* VMON_TRK2 OV asserts RSTb and FS0b */
#define FS26_FS_VMON_TRK2_OV_FS_REACTION_RSTB_FS0B (0x0002U << FS26_FS_VMON_TRK2_OV_FS_REACTION_SHIFT)

/* No effect on RSTb and FS0b */
#define FS26_FS_VMON_REF_UV_FS_REACTION_NO_EFFECT  (0x0000U << FS26_FS_VMON_REF_UV_FS_REACTION_SHIFT)
/* VMON_REF UV asserts FS0b only */
#define FS26_FS_VMON_REF_UV_FS_REACTION_FS0B       (0x0001U << FS26_FS_VMON_REF_UV_FS_REACTION_SHIFT)
/* VMON_REF UV asserts RSTb and FS0b */
#define FS26_FS_VMON_REF_UV_FS_REACTION_RSTB_FS0B  (0x0002U << FS26_FS_VMON_REF_UV_FS_REACTION_SHIFT)

/* No effect on RSTb and FS0b */
#define FS26_FS_VMON_REF_OV_FS_REACTION_NO_EFFECT  (0x0000U << FS26_FS_VMON_REF_OV_FS_REACTION_SHIFT)
/* VMON_REF OV asserts FS0b only */
#define FS26_FS_VMON_REF_OV_FS_REACTION_FS0B       (0x0001U << FS26_FS_VMON_REF_OV_FS_REACTION_SHIFT)
/* VMON_REF OV asserts RSTb and FS0b */
#define FS26_FS_VMON_REF_OV_FS_REACTION_RSTB_FS0B  (0x0002U << FS26_FS_VMON_REF_OV_FS_REACTION_SHIFT)

/* No effect on RSTb and FS0b */
#define FS26_FS_VMON_EXT_UV_FS_REACTION_NO_EFFECT  (0x0000U << FS26_FS_VMON_EXT_UV_FS_REACTION_SHIFT)
/* VMON_EXT UV asserts FS0b only */
#define FS26_FS_VMON_EXT_UV_FS_REACTION_FS0B       (0x0001U << FS26_FS_VMON_EXT_UV_FS_REACTION_SHIFT)
/* VMON_EXT UV asserts RSTb and FS0b */
#define FS26_FS_VMON_EXT_UV_FS_REACTION_RSTB_FS0B  (0x0002U << FS26_FS_VMON_EXT_UV_FS_REACTION_SHIFT)

/* No effect on RSTb and FS0b */
#define FS26_FS_VMON_EXT_OV_FS_REACTION_NO_EFFECT  (0x0000U << FS26_FS_VMON_EXT_OV_FS_REACTION_SHIFT)
/* VMON_EXT OV asserts FS0b only */
#define FS26_FS_VMON_EXT_OV_FS_REACTION_FS0B       (0x0001U << FS26_FS_VMON_EXT_OV_FS_REACTION_SHIFT)
/* VMON_EXT OV asserts RSTb and FS0b */
#define FS26_FS_VMON_EXT_OV_FS_REACTION_RSTB_FS0B  (0x0002U << FS26_FS_VMON_EXT_OV_FS_REACTION_SHIFT)

/******************************************************************************/
/* FS_I_WD_CFG - Type: RW                                                     */
/******************************************************************************/
#define FS26_FS_I_WD_CFG_ADDR            0x05U
#define FS26_FS_I_WD_CFG_DEFAULT         0x4200U

/* Reflect the value of the Watchdog Error Counter */
#define FS26_FS_WD_ERR_CNT_MASK          0x000FU
#define FS26_FS_WD_ERR_CNT_SHIFT         0x0000U
/* Reflect the value of the Watchdog Refresh Counter */
#define FS26_FS_WD_RFR_CNT_MASK          0x0070U
#define FS26_FS_WD_RFR_CNT_SHIFT         0x0004U
/* Reaction on RSTB or FAIL SAFE output in case of BAD Watchdog (data or timing) */
#define FS26_FS_WD_FS_REACTION_MASK      0x0300U
#define FS26_FS_WD_FS_REACTION_SHIFT     0x0008U
/* Watchdog refresh counter configuration */
#define FS26_FS_WD_RFR_LIMIT_MASK        0x1800U
#define FS26_FS_WD_RFR_LIMIT_SHIFT       0x000BU
/* Watchdog error counter configuration */
#define FS26_FS_WD_ERR_LIMIT_MASK        0xC000U
#define FS26_FS_WD_ERR_LIMIT_SHIFT       0x000EU

/* 0 */
#define FS26_FS_WD_ERR_CNT_0             (0x0000U << FS26_FS_WD_ERR_CNT_SHIFT)
/* 1 */
#define FS26_FS_WD_ERR_CNT_1             (0x0001U << FS26_FS_WD_ERR_CNT_SHIFT)
/* 2 */
#define FS26_FS_WD_ERR_CNT_2             (0x0002U << FS26_FS_WD_ERR_CNT_SHIFT)
/* 3 */
#define FS26_FS_WD_ERR_CNT_3             (0x0003U << FS26_FS_WD_ERR_CNT_SHIFT)
/* 4 */
#define FS26_FS_WD_ERR_CNT_4             (0x0004U << FS26_FS_WD_ERR_CNT_SHIFT)
/* 5 */
#define FS26_FS_WD_ERR_CNT_5             (0x0005U << FS26_FS_WD_ERR_CNT_SHIFT)
/* 6 */
#define FS26_FS_WD_ERR_CNT_6             (0x0006U << FS26_FS_WD_ERR_CNT_SHIFT)
/* 7 */
#define FS26_FS_WD_ERR_CNT_7             (0x0007U << FS26_FS_WD_ERR_CNT_SHIFT)
/* 8 */
#define FS26_FS_WD_ERR_CNT_8             (0x0008U << FS26_FS_WD_ERR_CNT_SHIFT)
/* 9 */
#define FS26_FS_WD_ERR_CNT_9             (0x0009U << FS26_FS_WD_ERR_CNT_SHIFT)
/* 10 */
#define FS26_FS_WD_ERR_CNT_10            (0x000AU << FS26_FS_WD_ERR_CNT_SHIFT)
/* 11 */
#define FS26_FS_WD_ERR_CNT_11            (0x000BU << FS26_FS_WD_ERR_CNT_SHIFT)
/* 12 */
#define FS26_FS_WD_ERR_CNT_12            (0x000CU << FS26_FS_WD_ERR_CNT_SHIFT)

/* 0 */
#define FS26_FS_WD_RFR_CNT_0             (0x0000U << FS26_FS_WD_RFR_CNT_SHIFT)
/* 1 */
#define FS26_FS_WD_RFR_CNT_1             (0x0001U << FS26_FS_WD_RFR_CNT_SHIFT)
/* 2 */
#define FS26_FS_WD_RFR_CNT_2             (0x0002U << FS26_FS_WD_RFR_CNT_SHIFT)
/* 3 */
#define FS26_FS_WD_RFR_CNT_3             (0x0003U << FS26_FS_WD_RFR_CNT_SHIFT)
/* 4 */
#define FS26_FS_WD_RFR_CNT_4             (0x0004U << FS26_FS_WD_RFR_CNT_SHIFT)
/* 5 */
#define FS26_FS_WD_RFR_CNT_5             (0x0005U << FS26_FS_WD_RFR_CNT_SHIFT)
/* 6 */
#define FS26_FS_WD_RFR_CNT_6             (0x0006U << FS26_FS_WD_RFR_CNT_SHIFT)
/* 7 */
#define FS26_FS_WD_RFR_CNT_7             (0x0007U << FS26_FS_WD_RFR_CNT_SHIFT)

/* No action on RSTb and FS0b */
#define FS26_FS_WD_FS_REACTION_NO_EFFECT (0x0000U << FS26_FS_WD_FS_REACTION_SHIFT)
/* FS0b only is asserted low */
#define FS26_FS_WD_FS_REACTION_FS0B      (0x0001U << FS26_FS_WD_FS_REACTION_SHIFT)
/* RSTb and FS0b are asserted low */
#define FS26_FS_WD_FS_REACTION_RSTB_FS0B (0x0002U << FS26_FS_WD_FS_REACTION_SHIFT)

/* 6 */
#define FS26_FS_WD_RFR_LIMIT_6           (0x0000U << FS26_FS_WD_RFR_LIMIT_SHIFT)
/* 4 */
#define FS26_FS_WD_RFR_LIMIT_4           (0x0001U << FS26_FS_WD_RFR_LIMIT_SHIFT)
/* 2 */
#define FS26_FS_WD_RFR_LIMIT_2           (0x0002U << FS26_FS_WD_RFR_LIMIT_SHIFT)
/* 1 */
#define FS26_FS_WD_RFR_LIMIT_1           (0x0003U << FS26_FS_WD_RFR_LIMIT_SHIFT)

/* 8 */
#define FS26_FS_WD_ERR_LIMIT_8           (0x0000U << FS26_FS_WD_ERR_LIMIT_SHIFT)
/* 6 */
#define FS26_FS_WD_ERR_LIMIT_6           (0x0001U << FS26_FS_WD_ERR_LIMIT_SHIFT)
/* 4 */
#define FS26_FS_WD_ERR_LIMIT_4           (0x0002U << FS26_FS_WD_ERR_LIMIT_SHIFT)
/* 2 */
#define FS26_FS_WD_ERR_LIMIT_2           (0x0003U << FS26_FS_WD_ERR_LIMIT_SHIFT)

/******************************************************************************/
/* FS_I_SAFE_INPUTS - Type: RW                                                */
/******************************************************************************/
#define FS26_FS_I_SAFE_INPUTS_ADDR       0x07U
#define FS26_FS_I_SAFE_INPUTS_DEFAULT    0x238DU

/* FCCU pin filtering time settings */
#define FS26_FS_FCCU12_FILT_MASK          0x0003U
#define FS26_FS_FCCU12_FILT_SHIFT         0x0000U
/* Reaction on RSTb or Fail Safe output in case of fault detection on ERRMON */
#define FS26_FS_ERRMON_FS_REACTION_MASK   0x0004U
#define FS26_FS_ERRMON_FS_REACTION_SHIFT  0x0002U
/* Acknowledge timing following a fault detection on ERRMON */
#define FS26_FS_ERRMON_ACK_TIME_MASK      0x0018U
#define FS26_FS_ERRMON_ACK_TIME_SHIFT     0x0003U
/* ERRMON Fault Polarity */
#define FS26_FS_ERRMON_FLT_POLARITY_MASK  0x0020U
#define FS26_FS_ERRMON_FLT_POLARITY_SHIFT 0x0005U
/* WAKE2 Low Power mode request polarity */
#define FS26_FS_WAKE2_LP_POLARITY_MASK    0x0040U
#define FS26_FS_WAKE2_LP_POLARITY_SHIFT   0x0006U
/* Reaction on RSTB or FAIL SAFE output in case of fault detection on FCCU2 */
#define FS26_FS_FCCU2_FS_REACTION_MASK    0x0080U
#define FS26_FS_FCCU2_FS_REACTION_SHIFT   0x0007U
/* Reaction on RSTB or FAIL SAFE output in case of fault detection on FCCU1 */
#define FS26_FS_FCCU1_FS_REACTION_MASK    0x0100U
#define FS26_FS_FCCU1_FS_REACTION_SHIFT   0x0008U
/* Reaction on RSTB or FAIL SAFE output in case of fault detection on FCCU12 */
#define FS26_FS_FCCU12_FS_REACTION_MASK   0x0200U
#define FS26_FS_FCCU12_FS_REACTION_SHIFT  0x0009U
/* FCCU2 fault polarity */
#define FS26_FS_FCCU2_FLT_POL_MASK        0x0400U
#define FS26_FS_FCCU2_FLT_POL_SHIFT       0x000AU
/* FCCU1 fault polarity */
#define FS26_FS_FCCU1_FLT_POL_MASK        0x0800U
#define FS26_FS_FCCU1_FLT_POL_SHIFT       0x000BU
/* FCCU12 fault polarity */
#define FS26_FS_FCCU12_FLT_POL_MASK       0x1000U
#define FS26_FS_FCCU12_FLT_POL_SHIFT      0x000CU
/* FCCU monitoring configuration */
#define FS26_FS_FCCU_CFG_MASK             0xE000U
#define FS26_FS_FCCU_CFG_SHIFT            0x000DU

/* 3us */
#define FS26_FS_FCCU12_FILT_3US          (0x0000U << FS26_FS_FCCU12_FILT_SHIFT)
/* 6us */
#define FS26_FS_FCCU12_FILT_6US          (0x0001U << FS26_FS_FCCU12_FILT_SHIFT)
/* 10us */
#define FS26_FS_FCCU12_FILT_10US         (0x0002U << FS26_FS_FCCU12_FILT_SHIFT)
/* 20us */
#define FS26_FS_FCCU12_FILT_20US         (0x0003U << FS26_FS_FCCU12_FILT_SHIFT)

/* FS0b only is asserted low in case of fault detection on ERMRON */
#define FS26_FS_ERRMON_FS_REACTION_FS0B      (0x0000U << FS26_FS_ERRMON_FS_REACTION_SHIFT)
/* RSTb and FS0b only is asserted low in case of fault detected on ERRMON */
#define FS26_FS_ERRMON_FS_REACTION_RSTB_FS0B (0x0001U << FS26_FS_ERRMON_FS_REACTION_SHIFT)

/* 1 ms */
#define FS26_FS_ERRMON_ACK_TIME_1MS      (0x0000U << FS26_FS_ERRMON_ACK_TIME_SHIFT)
/* 8 ms */
#define FS26_FS_ERRMON_ACK_TIME_8MS      (0x0001U << FS26_FS_ERRMON_ACK_TIME_SHIFT)
/* 16 ms */
#define FS26_FS_ERRMON_ACK_TIME_16MS     (0x0002U << FS26_FS_ERRMON_ACK_TIME_SHIFT)
/* 32 ms */
#define FS26_FS_ERRMON_ACK_TIME_32MS     (0x0003U << FS26_FS_ERRMON_ACK_TIME_SHIFT)

/* Low level is a fault after a negative edge transition */
#define FS26_FS_ERRMON_FLT_POLARITY_LOW  (0x0000U << FS26_FS_ERRMON_FLT_POLARITY_SHIFT)
/* High level is a fault after a positive edge transition */
#define FS26_FS_ERRMON_FLT_POLARITY_HIGH (0x0001U << FS26_FS_ERRMON_FLT_POLARITY_SHIFT)

/* Go to LP modes when WAKE2 goes low */
#define FS26_FS_WAKE2_LP_POLARITY_LOW    (0x0000U << FS26_FS_WAKE2_LP_POLARITY_SHIFT)
/* Go to LP modes when WAKE2 goes high */
#define FS26_FS_WAKE2_LP_POLARITY_HIGH   (0x0001U << FS26_FS_WAKE2_LP_POLARITY_SHIFT)

/* FS0b only is asserted low in case of fault on FCCU2 */
#define FS26_FS_FCCU2_FS_REACTION_FS0B      (0x0000U << FS26_FS_FCCU2_FS_REACTION_SHIFT)
/* RSTB and FS0b only is asserted low in case of fault on FCCU2 */
#define FS26_FS_FCCU2_FS_REACTION_RSTB_FS0B (0x0001U << FS26_FS_FCCU2_FS_REACTION_SHIFT)

/* FS0b only is asserted low in case of fault on FCCU1 */
#define FS26_FS_FCCU1_FS_REACTION_FS0B      (0x0000U << FS26_FS_FCCU1_FS_REACTION_SHIFT)
/* RSTB and FS0b only is asserted low in case of fault on FCCU1 */
#define FS26_FS_FCCU1_FS_REACTION_RSTB_FS0B (0x0001U << FS26_FS_FCCU1_FS_REACTION_SHIFT)

/* FS0b only is asserted low in case of fault on FCCU1 and FCCU2 */
#define FS26_FS_FCCU12_FS_REACTION_FS0B      (0x0000U << FS26_FS_FCCU12_FS_REACTION_SHIFT)
/* RSTB and FS0b only is asserted low in case of fault on FCCU1 and FCCU2 */
#define FS26_FS_FCCU12_FS_REACTION_RSTB_FS0B (0x0001U << FS26_FS_FCCU12_FS_REACTION_SHIFT)

/* Low level is a fault */
#define FS26_FS_FCCU2_FLT_POL_LOW        (0x0000U << FS26_FS_FCCU2_FLT_POL_SHIFT)
/* High level is a fault */
#define FS26_FS_FCCU2_FLT_POL_HIGH       (0x0001U << FS26_FS_FCCU2_FLT_POL_SHIFT)

/* Low level is a fault */
#define FS26_FS_FCCU1_FLT_POL_LOW        (0x0000U << FS26_FS_FCCU1_FLT_POL_SHIFT)
/* High level is a fault */
#define FS26_FS_FCCU1_FLT_POL_HIGH       (0x0001U << FS26_FS_FCCU1_FLT_POL_SHIFT)

/* FCCU1=0 or FCCU2=1 level is a fault */
#define FS26_FS_FCCU12_FLT_POL_0_1       (0x0000U << FS26_FS_FCCU12_FLT_POL_SHIFT)
/* FCCU1=1 or FCCU2=0 level is a fault */
#define FS26_FS_FCCU12_FLT_POL_1_0       (0x0001U << FS26_FS_FCCU12_FLT_POL_SHIFT)

/* No monitoring */
#define FS26_FS_FCCU_CFG_NO              (0x0000U << FS26_FS_FCCU_CFG_SHIFT)
/* FCCU1 and FCCU2 inputs monitoring activated by pair (Bi-Stable protocol) */
#define FS26_FS_FCCU_CFG_PAIR            (0x0001U << FS26_FS_FCCU_CFG_SHIFT)
/* FCCU1 or FCCU2 single input monitoring activated */
#define FS26_FS_FCCU_CFG_SINGLE          (0x0002U << FS26_FS_FCCU_CFG_SHIFT)
/* FCCU1 input monitoring only, FCCU2 input not used */
#define FS26_FS_FCCU_CFG_FCCU1           (0x0003U << FS26_FS_FCCU_CFG_SHIFT)
/* FCCU2 input monitoring only, FCCU1 input not used */
#define FS26_FS_FCCU_CFG_FCCU2           (0x0004U << FS26_FS_FCCU_CFG_SHIFT)
/* FCCU1 or FCCU2 single input PWM monitoring activated */
#define FS26_FS_FCCU_CFG_SINGLE_PWM      (0x0005U << FS26_FS_FCCU_CFG_SHIFT)
/* FCCU1 input PWM monitoring only, FCCU1 input level monitoring */
#define FS26_FS_FCCU_CFG_FCCU1_PWM       (0x0006U << FS26_FS_FCCU_CFG_SHIFT)
/* FCCU2 input PWM monitoring only, FCCU2 input level monitoring */
#define FS26_FS_FCCU_CFG_FCCU2_PWM       (0x0007U << FS26_FS_FCCU_CFG_SHIFT)

/******************************************************************************/
/* FS_I_FSSM - Type: RW                                                       */
/******************************************************************************/
#define FS26_FS_I_FSSM_ADDR              0x09U
#define FS26_FS_I_FSSM_DEFAULT           0x50C1U

/* Reflect the value of the Fault Error Counter */
#define FS26_FS_FLT_ERR_CNT_MASK         0x000FU
#define FS26_FS_FLT_ERR_CNT_SHIFT        0x0000U
/* Disable 8s RSTb timer */
#define FS26_FS_DIS8S_MASK               0x0010U
#define FS26_FS_DIS8S_SHIFT              0x0004U
/* Disable CLK Monitoring */
#define FS26_FS_CLK_MON_DIS_MASK         0x0020U
#define FS26_FS_CLK_MON_DIS_SHIFT        0x0005U
/* Assert RSTb in case a short to high is detected on FS1b */
#define FS26_FS_BACKUP_SAFETY_PATH_FS1B_MASK  0x0040U
#define FS26_FS_BACKUP_SAFETY_PATH_FS1B_SHIFT 0x0006U
/* Assert RSTB in case a short to high is detected on FS0b */
#define FS26_FS_BACKUP_SAFETY_PATH_FS0B_MASK  0x0080U
#define FS26_FS_BACKUP_SAFETY_PATH_FS0B_SHIFT 0x0007U
/* Reset duration configuration */
#define FS26_FS_RSTB_DUR_MASK            0x0200U
#define FS26_FS_RSTB_DUR_SHIFT           0x0009U
/* Configure the RSTB and FS0b behavior when fault error counter is higher than/equals intermediate value */
#define FS26_FS_FLT_ERR_REACTION_MASK    0x1800U
#define FS26_FS_FLT_ERR_REACTION_SHIFT   0x000BU
/* Configure the maximum level of the fault counter */
#define FS26_FS_FLT_ERR_CNT_LIMIT_MASK   0xC000U
#define FS26_FS_FLT_ERR_CNT_LIMIT_SHIFT  0x000EU

/* 0 */
#define FS26_FS_FLT_ERR_CNT_0            (0x0000U << FS26_FS_FLT_ERR_CNT_SHIFT)
/* 1 */
#define FS26_FS_FLT_ERR_CNT_1            (0x0001U << FS26_FS_FLT_ERR_CNT_SHIFT)
/* 2 */
#define FS26_FS_FLT_ERR_CNT_2            (0x0002U << FS26_FS_FLT_ERR_CNT_SHIFT)
/* 3 */
#define FS26_FS_FLT_ERR_CNT_3            (0x0003U << FS26_FS_FLT_ERR_CNT_SHIFT)
/* 4 */
#define FS26_FS_FLT_ERR_CNT_4            (0x0004U << FS26_FS_FLT_ERR_CNT_SHIFT)
/* 5 */
#define FS26_FS_FLT_ERR_CNT_5            (0x0005U << FS26_FS_FLT_ERR_CNT_SHIFT)
/* 6 */
#define FS26_FS_FLT_ERR_CNT_6            (0x0006U << FS26_FS_FLT_ERR_CNT_SHIFT)
/* 7 */
#define FS26_FS_FLT_ERR_CNT_7            (0x0007U << FS26_FS_FLT_ERR_CNT_SHIFT)
/* 8 */
#define FS26_FS_FLT_ERR_CNT_8            (0x0008U << FS26_FS_FLT_ERR_CNT_SHIFT)
/* 9 */
#define FS26_FS_FLT_ERR_CNT_9            (0x0009U << FS26_FS_FLT_ERR_CNT_SHIFT)
/* 10 */
#define FS26_FS_FLT_ERR_CNT_10           (0x000AU << FS26_FS_FLT_ERR_CNT_SHIFT)
/* 11 */
#define FS26_FS_FLT_ERR_CNT_11           (0x000BU << FS26_FS_FLT_ERR_CNT_SHIFT)
/* 12 */
#define FS26_FS_FLT_ERR_CNT_12           (0x000CU << FS26_FS_FLT_ERR_CNT_SHIFT)

/* RSTb LOW 8s Counter enabled */
#define FS26_FS_DIS8S_ENABLED            (0x0000U << FS26_FS_DIS8S_SHIFT)
/* RSTb LOW 8s Counter disabled */
#define FS26_FS_DIS8S_DISABLED           (0x0001U << FS26_FS_DIS8S_SHIFT)

/* CLK Monitoring active */
#define FS26_FS_CLK_MON_DIS_ACTIVE       (0x0000U << FS26_FS_CLK_MON_DIS_SHIFT)
/* CLK Monitoring disabled */
#define FS26_FS_CLK_MON_DIS_DISABLED     (0x0001U << FS26_FS_CLK_MON_DIS_SHIFT)

/* No assertion of the RSTb */
#define FS26_FS_BACKUP_SAFETY_PATH_FS1B_NO   (0x0000U << FS26_FS_BACKUP_SAFETY_PATH_FS1B_SHIFT)
/* RSTb assertion */
#define FS26_FS_BACKUP_SAFETY_PATH_FS1B_RSTB (0x0001U << FS26_FS_BACKUP_SAFETY_PATH_FS1B_SHIFT)

/* No assertion of the RSTb */
#define FS26_FS_BACKUP_SAFETY_PATH_FS0B_NO   (0x0000U << FS26_FS_BACKUP_SAFETY_PATH_FS0B_SHIFT)
/* RSTb assertion */
#define FS26_FS_BACKUP_SAFETY_PATH_FS0B_RSTB (0x0001U << FS26_FS_BACKUP_SAFETY_PATH_FS0B_SHIFT)

/* 10 ms */
#define FS26_FS_RSTB_DUR_10MS            (0x0000U << FS26_FS_RSTB_DUR_SHIFT)
/* 1 ms */
#define FS26_FS_RSTB_DUR_1MS             (0x0001U << FS26_FS_RSTB_DUR_SHIFT)

/* No effect on RSTb and FS0b */
#define FS26_FS_FLT_ERR_REACTION_NO_EFFECT (0x0000U << FS26_FS_FLT_ERR_REACTION_SHIFT)
/* FS0b is asserted low if FLTERRCNT is higher than/equals intermediate value */
#define FS26_FS_FLT_ERR_REACTION_FS0B      (0x0001U << FS26_FS_FLT_ERR_REACTION_SHIFT)
/* RSTb and FS0b are asserted low if FLTERRCNT is higher than/equals intermediate value */
#define FS26_FS_FLT_ERR_REACTION_RSTB_FS0B (0x0002U << FS26_FS_FLT_ERR_REACTION_SHIFT)

/* Max Value = 2 */
#define FS26_FS_FLT_ERR_CNT_LIMIT_2      (0x0000U << FS26_FS_FLT_ERR_CNT_LIMIT_SHIFT)
/* Max Value = 6 */
#define FS26_FS_FLT_ERR_CNT_LIMIT_6      (0x0001U << FS26_FS_FLT_ERR_CNT_LIMIT_SHIFT)
/* Max Value = 8 */
#define FS26_FS_FLT_ERR_CNT_LIMIT_8      (0x0002U << FS26_FS_FLT_ERR_CNT_LIMIT_SHIFT)
/* Max Value = 12 */
#define FS26_FS_FLT_ERR_CNT_LIMIT_12     (0x0003U << FS26_FS_FLT_ERR_CNT_LIMIT_SHIFT)

/******************************************************************************/
/* FS_WDW_DURATION - Type: RW                                                 */
/******************************************************************************/
#define FS26_FS_WDW_DURATION_ADDR        0x0BU
#define FS26_FS_WDW_DURATION_DEFAULT     0x0000U

/* Watchdog window period configuration */
#define FS26_FS_WDW_RECOVERY_MASK        0x000FU
#define FS26_FS_WDW_RECOVERY_SHIFT       0x0000U
/* Watchdog window Duty cycle */
#define FS26_FS_WDW_DC_MASK              0x01C0U
#define FS26_FS_WDW_DC_SHIFT             0x0006U
/* Watchdog window period configuration */
#define FS26_FS_WDW_PERIOD_MASK          0xF000U
#define FS26_FS_WDW_PERIOD_SHIFT         0x000CU

/* Disabled (infinite open window) */
#define FS26_FS_WDW_RECOVERY_INFINITE    (0x0000U << FS26_FS_WDW_RECOVERY_SHIFT)
/* 1 ms */
#define FS26_FS_WDW_RECOVERY_1MS         (0x0001U << FS26_FS_WDW_RECOVERY_SHIFT)
/* 2 ms */
#define FS26_FS_WDW_RECOVERY_2MS         (0x0002U << FS26_FS_WDW_RECOVERY_SHIFT)
/* 3 ms */
#define FS26_FS_WDW_RECOVERY_3MS         (0x0003U << FS26_FS_WDW_RECOVERY_SHIFT)
/* 4 ms */
#define FS26_FS_WDW_RECOVERY_4MS         (0x0004U << FS26_FS_WDW_RECOVERY_SHIFT)
/* 6 ms */
#define FS26_FS_WDW_RECOVERY_6MS         (0x0005U << FS26_FS_WDW_RECOVERY_SHIFT)
/* 8 ms */
#define FS26_FS_WDW_RECOVERY_8MS         (0x0006U << FS26_FS_WDW_RECOVERY_SHIFT)
/* 12 ms */
#define FS26_FS_WDW_RECOVERY_12MS        (0x0007U << FS26_FS_WDW_RECOVERY_SHIFT)
/* 16 ms */
#define FS26_FS_WDW_RECOVERY_16MS        (0x0008U << FS26_FS_WDW_RECOVERY_SHIFT)
/* 24 ms */
#define FS26_FS_WDW_RECOVERY_24MS        (0x0009U << FS26_FS_WDW_RECOVERY_SHIFT)
/* 32 ms */
#define FS26_FS_WDW_RECOVERY_32MS        (0x000AU << FS26_FS_WDW_RECOVERY_SHIFT)
/* 64 ms */
#define FS26_FS_WDW_RECOVERY_64MS        (0x000BU << FS26_FS_WDW_RECOVERY_SHIFT)
/* 128 ms */
#define FS26_FS_WDW_RECOVERY_128MS       (0x000CU << FS26_FS_WDW_RECOVERY_SHIFT)
/* 256 ms */
#define FS26_FS_WDW_RECOVERY_256MS       (0x000DU << FS26_FS_WDW_RECOVERY_SHIFT)
/* 512 ms */
#define FS26_FS_WDW_RECOVERY_512MS       (0x000EU << FS26_FS_WDW_RECOVERY_SHIFT)
/* 1024 ms */
#define FS26_FS_WDW_RECOVERY_1024MS      (0x000FU << FS26_FS_WDW_RECOVERY_SHIFT)

/* Closed Window : 31.25% / Open Window : 68.75% */
#define FS26_FS_WDW_DC_31C_68O           (0x0000U << FS26_FS_WDW_DC_SHIFT)
/* Closed Window : 37.50% / Open Window : 62.50% */
#define FS26_FS_WDW_DC_37C_62O            (0x0001U << FS26_FS_WDW_DC_SHIFT)
/* Closed Window : 50% / Open Window : 50% */
#define FS26_FS_WDW_DC_50C_50O           (0x0002U << FS26_FS_WDW_DC_SHIFT)
/* Closed Window : 62.50% / Open Window : 37.50% */
#define FS26_FS_WDW_DC_62C_37O            (0x0003U << FS26_FS_WDW_DC_SHIFT)
/* Closed Window : 68.75% / Open Window : 31.25% */
#define FS26_FS_WDW_DC_68C_31O           (0x0004U << FS26_FS_WDW_DC_SHIFT)

/* Disabled (infinite open window) */
#define FS26_FS_WDW_PERIOD_INFINITE      (0x0000U << FS26_FS_WDW_PERIOD_SHIFT)
/* 1 ms */
#define FS26_FS_WDW_PERIOD_1MS           (0x0001U << FS26_FS_WDW_PERIOD_SHIFT)
/* 2 ms */
#define FS26_FS_WDW_PERIOD_2MS           (0x0002U << FS26_FS_WDW_PERIOD_SHIFT)
/* 3 ms */
#define FS26_FS_WDW_PERIOD_3MS           (0x0003U << FS26_FS_WDW_PERIOD_SHIFT)
/* 4 ms */
#define FS26_FS_WDW_PERIOD_4MS           (0x0004U << FS26_FS_WDW_PERIOD_SHIFT)
/* 6 ms */
#define FS26_FS_WDW_PERIOD_6MS           (0x0005U << FS26_FS_WDW_PERIOD_SHIFT)
/* 8 ms */
#define FS26_FS_WDW_PERIOD_8MS           (0x0006U << FS26_FS_WDW_PERIOD_SHIFT)
/* 12 ms */
#define FS26_FS_WDW_PERIOD_12MS          (0x0007U << FS26_FS_WDW_PERIOD_SHIFT)
/* 16 ms */
#define FS26_FS_WDW_PERIOD_16MS          (0x0008U << FS26_FS_WDW_PERIOD_SHIFT)
/* 24 ms */
#define FS26_FS_WDW_PERIOD_24MS          (0x0009U << FS26_FS_WDW_PERIOD_SHIFT)
/* 32 ms */
#define FS26_FS_WDW_PERIOD_32MS          (0x000AU << FS26_FS_WDW_PERIOD_SHIFT)
/* 64 ms */
#define FS26_FS_WDW_PERIOD_64MS          (0x000BU << FS26_FS_WDW_PERIOD_SHIFT)
/* 128 ms */
#define FS26_FS_WDW_PERIOD_128MS         (0x000CU << FS26_FS_WDW_PERIOD_SHIFT)
/* 256 ms */
#define FS26_FS_WDW_PERIOD_256MS         (0x000DU << FS26_FS_WDW_PERIOD_SHIFT)
/* 512 ms */
#define FS26_FS_WDW_PERIOD_512MS         (0x000EU << FS26_FS_WDW_PERIOD_SHIFT)
/* 1024 ms */
#define FS26_FS_WDW_PERIOD_1024MS        (0x000FU << FS26_FS_WDW_PERIOD_SHIFT)

/******************************************************************************/
/* FS_WD_ANSWER - Type: RW                                                    */
/******************************************************************************/
#define FS26_FS_WD_ANSWER_ADDR           0x0DU
#define FS26_FS_WD_ANSWER_DEFAULT        0x0000U

/* Watchdog answer from MCU. 16 bits watchdog answer needs to be written here. */
#define FS26_FS_WD_ANSWER_MASK           0xFFFFU
#define FS26_FS_WD_ANSWER_SHIFT          0x0000U

/******************************************************************************/
/* FS_WD_TOKEN - Type: RW                                                     */
/******************************************************************************/
#define FS26_FS_WD_TOKEN_ADDR            0x0EU
#define FS26_FS_WD_TOKEN_DEFAULT         0x5AB2U

/* WD Token code. Token value can be written by the MCU here. Default value is 0x5AB2. */
#define FS26_FS_WD_TOKEN_MASK            0xFFFFU
#define FS26_FS_WD_TOKEN_SHIFT           0x0000U

/******************************************************************************/
/* FS_ABIST_ON_DEMAND - Type: RW                                              */
/******************************************************************************/
#define FS26_FS_ABIST_ON_DEMAND_ADDR     0x0FU
#define FS26_FS_ABIST_ON_DEMAND_DEFAULT  0x0000U

/* Request ABIST on VMON_PRE */
#define FS26_FS_ABIST2_VPRE_MASK         0x0001U
#define FS26_FS_ABIST2_VPRE_SHIFT        0x0000U
/* Request ABIST on VMON_CORE */
#define FS26_FS_ABIST2_CORE_MASK         0x0002U
#define FS26_FS_ABIST2_CORE_SHIFT        0x0001U
/* Request ABIST on VMON_LDO1 */
#define FS26_FS_ABIST2_LDO1_MASK         0x0004U
#define FS26_FS_ABIST2_LDO1_SHIFT        0x0002U
/* Request ABIST on VMON_LDO2 */
#define FS26_FS_ABIST2_LDO2_MASK         0x0008U
#define FS26_FS_ABIST2_LDO2_SHIFT        0x0003U
/* Request ABIST on VMON_TRK1 */
#define FS26_FS_ABIST2_TRK1_MASK         0x0010U
#define FS26_FS_ABIST2_TRK1_SHIFT        0x0004U
/* Request ABIST on VMON_TRK2 */
#define FS26_FS_ABIST2_TRK2_MASK         0x0020U
#define FS26_FS_ABIST2_TRK2_SHIFT        0x0005U
/* Request ABIST on VMON_REF */
#define FS26_FS_ABIST2_REF_MASK          0x0040U
#define FS26_FS_ABIST2_REF_SHIFT         0x0006U
/* Request ABIST on VMON_EXT */
#define FS26_FS_ABIST2_EXT_MASK          0x0080U
#define FS26_FS_ABIST2_EXT_SHIFT         0x0007U
/* Launch ABIST on selected VMONs */
#define FS26_FS_LAUNCH_ABIST2_MASK       0x8000U
#define FS26_FS_LAUNCH_ABIST2_SHIFT      0x000FU

/* No ABIST */
#define FS26_FS_ABIST2_VPRE_NO_ABIST     (0x0000U << FS26_FS_ABIST2_VPRE_SHIFT)
/* ABIST on VMON_PRE Requested */
#define FS26_FS_ABIST2_VPRE_ABIST        (0x0001U << FS26_FS_ABIST2_VPRE_SHIFT)

/* No ABIST */
#define FS26_FS_ABIST2_CORE_NO_ABIST     (0x0000U << FS26_FS_ABIST2_CORE_SHIFT)
/* ABIST on VMON_CORE Requested */
#define FS26_FS_ABIST2_CORE_ABIST        (0x0001U << FS26_FS_ABIST2_CORE_SHIFT)

/* No ABIST */
#define FS26_FS_ABIST2_LDO1_NO_ABIST     (0x0000U << FS26_FS_ABIST2_LDO1_SHIFT)
/* ABIST on VMON_LDO1 Requested */
#define FS26_FS_ABIST2_LDO1_ABIST        (0x0001U << FS26_FS_ABIST2_LDO1_SHIFT)

/* No ABIST */
#define FS26_FS_ABIST2_LDO2_NO_ABIST     (0x0000U << FS26_FS_ABIST2_LDO2_SHIFT)
/* ABIST on VMON_LDO2 Requested */
#define FS26_FS_ABIST2_LDO2_ABIST        (0x0001U << FS26_FS_ABIST2_LDO2_SHIFT)

/* No ABIST */
#define FS26_FS_ABIST2_TRK1_NO_ABIST     (0x0000U << FS26_FS_ABIST2_TRK1_SHIFT)
/* ABIST on VMON_TRK1 Requested */
#define FS26_FS_ABIST2_TRK1_ABIST        (0x0001U << FS26_FS_ABIST2_TRK1_SHIFT)

/* No ABIST */
#define FS26_FS_ABIST2_TRK2_NO_ABIST     (0x0000U << FS26_FS_ABIST2_TRK2_SHIFT)
/* ABIST on VMON_TRK2 Requested */
#define FS26_FS_ABIST2_TRK2_ABIST        (0x0001U << FS26_FS_ABIST2_TRK2_SHIFT)

/* No ABIST */
#define FS26_FS_ABIST2_REF_NO_ABIST      (0x0000U << FS26_FS_ABIST2_REF_SHIFT)
/* ABIST on VMON_REF Requested */
#define FS26_FS_ABIST2_REF_ABIST         (0x0001U << FS26_FS_ABIST2_REF_SHIFT)

/* No ABIST */
#define FS26_FS_ABIST2_EXT_NO_ABIST      (0x0000U << FS26_FS_ABIST2_EXT_SHIFT)
/* ABIST on VMON_EXT Requested */
#define FS26_FS_ABIST2_EXT_ABIST         (0x0001U << FS26_FS_ABIST2_EXT_SHIFT)

/* No action */
#define FS26_FS_LAUNCH_ABIST2_NO_ABIST   (0x0000U << FS26_FS_LAUNCH_ABIST2_SHIFT)
/* ABIST launched */
#define FS26_FS_LAUNCH_ABIST2_ABIST      (0x0001U << FS26_FS_LAUNCH_ABIST2_SHIFT)

/******************************************************************************/
/* FS_OVUV_REG_STATUS - Type: RW                                              */
/******************************************************************************/
#define FS26_FS_OVUV_REG_STATUS_ADDR     0x10U
#define FS26_FS_OVUV_REG_STATUS_DEFAULT  0x0000U

/* Undervoltage Monitoring on VMON_EXT */
#define FS26_FS_EXT_UV_MASK              0x0001U
#define FS26_FS_EXT_UV_SHIFT             0x0000U
/* Overvoltage Monitoring on VMON_EXT */
#define FS26_FS_EXT_OV_MASK              0x0002U
#define FS26_FS_EXT_OV_SHIFT             0x0001U
/* Undervoltage Monitoring on VMON_REF */
#define FS26_FS_REF_UV_MASK              0x0004U
#define FS26_FS_REF_UV_SHIFT             0x0002U
/* Overvoltage Monitoring on VMON_REF */
#define FS26_FS_REF_OV_MASK              0x0008U
#define FS26_FS_REF_OV_SHIFT             0x0003U
/* Undervoltage Monitoring on TRK2 */
#define FS26_FS_TRK2_UV_MASK             0x0010U
#define FS26_FS_TRK2_UV_SHIFT            0x0004U
/* Overvoltage Monitoring on TRK2 */
#define FS26_FS_TRK2_OV_MASK             0x0020U
#define FS26_FS_TRK2_OV_SHIFT            0x0005U
/* Undervoltage Monitoring on TRK1 */
#define FS26_FS_TRK1_UV_MASK             0x0040U
#define FS26_FS_TRK1_UV_SHIFT            0x0006U
/* Overvoltage Monitoring on TRK1 */
#define FS26_FS_TRK1_OV_MASK             0x0080U
#define FS26_FS_TRK1_OV_SHIFT            0x0007U
/* Undervoltage Monitoring on LDO2 */
#define FS26_FS_LDO2_UV_MASK             0x0100U
#define FS26_FS_LDO2_UV_SHIFT            0x0008U
/* Overvoltage Monitoring on LDO2 */
#define FS26_FS_LDO2_OV_MASK             0x0200U
#define FS26_FS_LDO2_OV_SHIFT            0x0009U
/* Undervoltage Monitoring on LDO1 */
#define FS26_FS_LDO1_UV_MASK             0x0400U
#define FS26_FS_LDO1_UV_SHIFT            0x000AU
/* Overvoltage Monitoring on LDO1 */
#define FS26_FS_LDO1_OV_MASK             0x0800U
#define FS26_FS_LDO1_OV_SHIFT            0x000BU
/* Undervoltage Monitoring on VCORE */
#define FS26_FS_CORE_UV_MASK             0x1000U
#define FS26_FS_CORE_UV_SHIFT            0x000CU
/* Overvoltage Monitoring on VCORE */
#define FS26_FS_CORE_OV_MASK             0x2000U
#define FS26_FS_CORE_OV_SHIFT            0x000DU
/* Undervoltage Monitoring on VPRE */
#define FS26_FS_VPRE_UV_MASK             0x4000U
#define FS26_FS_VPRE_UV_SHIFT            0x000EU
/* Overvoltage Monitoring on VPRE */
#define FS26_FS_VPRE_OV_MASK             0x8000U
#define FS26_FS_VPRE_OV_SHIFT            0x000FU

/* No Undervoltage */
#define FS26_FS_EXT_UV_NO_EVENT          (0x0000U << FS26_FS_EXT_UV_SHIFT)
/* Undervoltage Reported on VMON_EXT */
#define FS26_FS_EXT_UV_EVENT             (0x0001U << FS26_FS_EXT_UV_SHIFT)

/* No Overvoltage */
#define FS26_FS_EXT_OV_NO_EVENT          (0x0000U << FS26_FS_EXT_OV_SHIFT)
/* Overvoltage Reported on VMON_EXT */
#define FS26_FS_EXT_OV_EVENT             (0x0001U << FS26_FS_EXT_OV_SHIFT)

/* No Undervoltage */
#define FS26_FS_REF_UV_NO_EVENT          (0x0000U << FS26_FS_REF_UV_SHIFT)
/* Undervoltage Reported on VMON_REF */
#define FS26_FS_REF_UV_EVENT             (0x0001U << FS26_FS_REF_UV_SHIFT)

/* No Overvoltage */
#define FS26_FS_REF_OV_NO_EVENT          (0x0000U << FS26_FS_REF_OV_SHIFT)
/* Overvoltage Reported on VMON_REF */
#define FS26_FS_REF_OV_EVENT             (0x0001U << FS26_FS_REF_OV_SHIFT)

/* No Undervoltage */
#define FS26_FS_TRK2_UV_NO_EVENT         (0x0000U << FS26_FS_TRK2_UV_SHIFT)
/* Undervoltage Reported on TRK2 */
#define FS26_FS_TRK2_UV_EVENT            (0x0001U << FS26_FS_TRK2_UV_SHIFT)

/* No Overvoltage */
#define FS26_FS_TRK2_OV_NO_EVENT         (0x0000U << FS26_FS_TRK2_OV_SHIFT)
/* Overvoltage Reported on TRK2 */
#define FS26_FS_TRK2_OV_EVENT            (0x0001U << FS26_FS_TRK2_OV_SHIFT)

/* No Undervoltage */
#define FS26_FS_TRK1_UV_NO_EVENT         (0x0000U << FS26_FS_TRK1_UV_SHIFT)
/* Undervoltage Reported on TRK1 */
#define FS26_FS_TRK1_UV_EVENT            (0x0001U << FS26_FS_TRK1_UV_SHIFT)

/* No Overvoltage */
#define FS26_FS_TRK1_OV_NO_EVENT         (0x0000U << FS26_FS_TRK1_OV_SHIFT)
/* Overvoltage Reported on TRK1 */
#define FS26_FS_TRK1_OV_EVENT            (0x0001U << FS26_FS_TRK1_OV_SHIFT)

/* No Undervoltage */
#define FS26_FS_LDO2_UV_NO_EVENT         (0x0000U << FS26_FS_LDO2_UV_SHIFT)
/* Undervoltage Reported on LDO2 */
#define FS26_FS_LDO2_UV_EVENT            (0x0001U << FS26_FS_LDO2_UV_SHIFT)

/* No Overvoltage */
#define FS26_FS_LDO2_OV_NO_EVENT         (0x0000U << FS26_FS_LDO2_OV_SHIFT)
/* Overvoltage Reported on LDO2 */
#define FS26_FS_LDO2_OV_EVENT            (0x0001U << FS26_FS_LDO2_OV_SHIFT)

/* No Undervoltage */
#define FS26_FS_LDO1_UV_NO_EVENT         (0x0000U << FS26_FS_LDO1_UV_SHIFT)
/* Undervoltage Reported on LDO1 */
#define FS26_FS_LDO1_UV_EVENT            (0x0001U << FS26_FS_LDO1_UV_SHIFT)

/* No Overvoltage */
#define FS26_FS_LDO1_OV_NO_EVENT         (0x0000U << FS26_FS_LDO1_OV_SHIFT)
/* Overvoltage Reported on LDO1 */
#define FS26_FS_LDO1_OV_EVENT            (0x0001U << FS26_FS_LDO1_OV_SHIFT)

/* No Undervoltage */
#define FS26_FS_CORE_UV_NO_EVENT         (0x0000U << FS26_FS_CORE_UV_SHIFT)
/* Undervoltage Reported on VCORE */
#define FS26_FS_CORE_UV_EVENT            (0x0001U << FS26_FS_CORE_UV_SHIFT)

/* No Overvoltage */
#define FS26_FS_CORE_OV_NO_EVENT         (0x0000U << FS26_FS_CORE_OV_SHIFT)
/* Overvoltage Reported on VCORE */
#define FS26_FS_CORE_OV_EVENT            (0x0001U << FS26_FS_CORE_OV_SHIFT)

/* No Undervoltage */
#define FS26_FS_VPRE_UV_NO_EVENT         (0x0000U << FS26_FS_VPRE_UV_SHIFT)
/* Undervoltage Reported on VPRE */
#define FS26_FS_VPRE_UV_EVENT            (0x0001U << FS26_FS_VPRE_UV_SHIFT)

/* No Overvoltage */
#define FS26_FS_VPRE_OV_NO_EVENT         (0x0000U << FS26_FS_VPRE_OV_SHIFT)
/* Overvoltage Reported on VPRE */
#define FS26_FS_VPRE_OV_EVENT            (0x0001U << FS26_FS_VPRE_OV_SHIFT)

/******************************************************************************/
/* FS_RELEASE_FS0B_FS1B - Type: RW                                            */
/******************************************************************************/
#define FS26_FS_RELEASE_FS0B_FS1B_ADDR    0x11U
#define FS26_FS_RELEASE_FS0B_FS1B_DEFAULT 0x0000U

/* Secure 16 bits word to release FS0b and/or FS1b. FS outputs code part. */
#define FS26_FS_RELEASE_FS_OUTPUT_MASK   0xE000U
#define FS26_FS_RELEASE_FS_OUTPUT_SHIFT  0x000DU
/* Secure 16 bits word to release FS0b and/or FS1b. WD token part. */
#define FS26_FS_RELEASE_WD_TOKEN_MASK    0x1FFFU
#define FS26_FS_RELEASE_WD_TOKEN_SHIFT   0x0000U

/* Release FS0b only */
#define FS26_FS_RELEASE_OUTPUT_FS0B      (0x0003U << FS26_FS_RELEASE_FS_OUTPUT_SHIFT)
/* Release FS0b and FS1b */
#define FS26_FS_RELEASE_OUTPUT_FS0B_FS1B (0x0005U << FS26_FS_RELEASE_FS_OUTPUT_SHIFT)
/* Release FS1b only */
#define FS26_FS_RELEASE_OUTPUT_FS1B      (0x0006U << FS26_FS_RELEASE_FS_OUTPUT_SHIFT)

/******************************************************************************/
/* FS_SAFE_IOS_1 - Type: RW                                                   */
/******************************************************************************/
#define FS26_FS_SAFE_IOS_1_ADDR          0x12U
#define FS26_FS_SAFE_IOS_1_DEFAULT       0x0000U

/* Go Back to INIT Fail Safe Request */
#define FS26_FS_GOTO_INIT_MASK           0x0002U
#define FS26_FS_GOTO_INIT_SHIFT          0x0001U
/* Request an assertion of FS1b */
#define FS26_FS_FS1B_REQ_MASK            0x0004U
#define FS26_FS_FS1B_REQ_SHIFT           0x0002U
/* Report a FS1b short to HIGH */
#define FS26_FS_FS1B_DIAG_MASK           0x0008U
#define FS26_FS_FS1B_DIAG_SHIFT          0x0003U
/* Sense of FS1b pad */
#define FS26_FS_FS1B_SNS_MASK            0x0010U
#define FS26_FS_FS1B_SNS_SHIFT           0x0004U
/* FS1b Driver - Digital Command */
#define FS26_FS_FS1B_DRV_MASK            0x0020U
#define FS26_FS_FS1B_DRV_SHIFT           0x0005U
/* Request an assertion of FS0b */
#define FS26_FS_FS0B_REQ_MASK            0x0040U
#define FS26_FS_FS0B_REQ_SHIFT           0x0006U
/* Report a FS0b short to HIGH */
#define FS26_FS_FS0B_DIAG_MASK           0x0080U
#define FS26_FS_FS0B_DIAG_SHIFT          0x0007U
/* Sense of FS0b pad */
#define FS26_FS_FS0B_SNS_MASK            0x0100U
#define FS26_FS_FS0B_SNS_SHIFT           0x0008U
/* FS0b Driver - Digital Command */
#define FS26_FS_FS0B_DRV_MASK            0x0200U
#define FS26_FS_FS0B_DRV_SHIFT           0x0009U
/* Request an assertion of Reset */
#define FS26_FS_RSTB_REQ_MASK            0x0400U
#define FS26_FS_RSTB_REQ_SHIFT           0x000AU
/* Report a Reset short to HIGH */
#define FS26_FS_RSTB_DIAG_MASK           0x0800U
#define FS26_FS_RSTB_DIAG_SHIFT          0x000BU
/* Report a Reset Event (latched) */
#define FS26_FS_RSTB_EVENT_MASK          0x1000U
#define FS26_FS_RSTB_EVENT_SHIFT         0x000CU
/* Sense of RSTb pad */
#define FS26_FS_RSTB_SNS_MASK            0x2000U
#define FS26_FS_RSTB_SNS_SHIFT           0x000DU
/* RSTb Driver - Digital Command */
#define FS26_FS_RSTB_DRV_MASK            0x4000U
#define FS26_FS_RSTB_DRV_SHIFT           0x000EU
/* Report an External Reset */
#define FS26_FS_EXT_RSTB_MASK            0x8000U
#define FS26_FS_EXT_RSTB_SHIFT           0x000FU

/* No action */
#define FS26_FS_GOTO_INIT_NO_ACTION      (0x0000U << FS26_FS_GOTO_INIT_SHIFT)
/* Go back to INIT FS */
#define FS26_FS_GOTO_INIT_INIT           (0x0001U << FS26_FS_GOTO_INIT_SHIFT)

/* No action */
#define FS26_FS_FS1B_REQ_NO_ACTION       (0x0000U << FS26_FS_FS1B_REQ_SHIFT)
/* FS1b assertion */
#define FS26_FS_FS1B_REQ_ASSERT          (0x0001U << FS26_FS_FS1B_REQ_SHIFT)

/* No Failure */
#define FS26_FS_FS1B_DIAG_NO_FAILURE     (0x0000U << FS26_FS_FS1B_DIAG_SHIFT)
/* Short to High detected */
#define FS26_FS_FS1B_DIAG_SHORT          (0x0001U << FS26_FS_FS1B_DIAG_SHIFT)

/* FS1b pad sensed low */
#define FS26_FS_FS1B_SNS_LOW             (0x0000U << FS26_FS_FS1B_SNS_SHIFT)
/* FS1b pad sensed High */
#define FS26_FS_FS1B_SNS_HIGH            (0x0001U << FS26_FS_FS1B_SNS_SHIFT)

/* FS1b Driver command sensed Low */
#define FS26_FS_FS1B_DRV_LOW             (0x0000U << FS26_FS_FS1B_DRV_SHIFT)
/* FS1b Driver command sensed High */
#define FS26_FS_FS1B_DRV_HIGH            (0x0001U << FS26_FS_FS1B_DRV_SHIFT)

/* No action */
#define FS26_FS_FS0B_REQ_NO_ACTION       (0x0000U << FS26_FS_FS0B_REQ_SHIFT)
/* FS0b assertion */
#define FS26_FS_FS0B_REQ_ASSERT          (0x0001U << FS26_FS_FS0B_REQ_SHIFT)

/* No Failure */
#define FS26_FS_FS0B_DIAG_NO_FAILURE     (0x0000U << FS26_FS_FS0B_DIAG_SHIFT)
/* Short to High detected */
#define FS26_FS_FS0B_DIAG_SHORT          (0x0001U << FS26_FS_FS0B_DIAG_SHIFT)

/* FS0b pad sensed low */
#define FS26_FS_FS0B_SNS_LOW             (0x0000U << FS26_FS_FS0B_SNS_SHIFT)
/* FS0b pad sensed High */
#define FS26_FS_FS0B_SNS_HIGH            (0x0001U << FS26_FS_FS0B_SNS_SHIFT)

/* FS0b Driver command sensed Low */
#define FS26_FS_FS0B_DRV_LOW             (0x0000U << FS26_FS_FS0B_DRV_SHIFT)
/* FS0b Driver command sensed High */
#define FS26_FS_FS0B_DRV_HIGH            (0x0001U << FS26_FS_FS0B_DRV_SHIFT)

/* No action */
#define FS26_FS_RSTB_REQ_NO_ACTION       (0x0000U << FS26_FS_RSTB_REQ_SHIFT)
/* RSTb assertion (pulse) */
#define FS26_FS_RSTB_REQ_ASSERT          (0x0001U << FS26_FS_RSTB_REQ_SHIFT)

/* No Failure */
#define FS26_FS_RSTB_DIAG_NO_FAILURE     (0x0000U << FS26_FS_RSTB_DIAG_SHIFT)
/* Short to High detected */
#define FS26_FS_RSTB_DIAG_SHORT          (0x0001U << FS26_FS_RSTB_DIAG_SHIFT)

/* No Failure */
#define FS26_FS_RSTB_EVENT_NO_RESET      (0x0000U << FS26_FS_RSTB_EVENT_SHIFT)
/* Reset Occurred */
#define FS26_FS_RSTB_EVENT_RESET         (0x0001U << FS26_FS_RSTB_EVENT_SHIFT)

/* RSTb pad sensed low */
#define FS26_FS_RSTB_SNS_LOW             (0x0000U << FS26_FS_RSTB_SNS_SHIFT)
/* RSTb pad sensed High */
#define FS26_FS_RSTB_SNS_HIGH            (0x0001U << FS26_FS_RSTB_SNS_SHIFT)

/* RSTb Driver command sensed Low */
#define FS26_FS_RSTB_DRV_LOW             (0x0000U << FS26_FS_RSTB_DRV_SHIFT)
/* RSTb Driver command sensed High */
#define FS26_FS_RSTB_DRV_HIGH            (0x0001U << FS26_FS_RSTB_DRV_SHIFT)

/* No External Reset */
#define FS26_FS_EXT_RSTB_NO_EVENT        (0x0000U << FS26_FS_EXT_RSTB_SHIFT)
/* External Reset */
#define FS26_FS_EXT_RSTB_EVENT           (0x0001U << FS26_FS_EXT_RSTB_SHIFT)

/******************************************************************************/
/* FS_SAFE_IOS_2 - Type: RW                                                   */
/******************************************************************************/
#define FS26_FS_SAFE_IOS_2_ADDR          0x13U
#define FS26_FS_SAFE_IOS_2_DEFAULT       0x0000U

/* FS1b duration timing when low */
#define FS26_FS_FS1B_TDUR_MASK           0x001FU
#define FS26_FS_FS1B_TDUR_SHIFT          0x0000U
/* FS1b delay after assertion of FS0b */
#define FS26_FS_FS1B_TDELAY_MASK         0x03E0U
#define FS26_FS_FS1B_TDELAY_SHIFT        0x0005U

/* 0 ms (no assertion of FS0b) */
#define FS26_FS_FS1B_TDUR_0MS            (0x0000U << FS26_FS_FS1B_TDUR_SHIFT)
/* 5 ms */
#define FS26_FS_FS1B_TDUR_5MS            (0x0001U << FS26_FS_FS1B_TDUR_SHIFT)
/* 10 ms */
#define FS26_FS_FS1B_TDUR_10MS           (0x0002U << FS26_FS_FS1B_TDUR_SHIFT)
/* 15 ms */
#define FS26_FS_FS1B_TDUR_15MS           (0x0003U << FS26_FS_FS1B_TDUR_SHIFT)
/* 20 ms */
#define FS26_FS_FS1B_TDUR_20MS           (0x0004U << FS26_FS_FS1B_TDUR_SHIFT)
/* 25 ms */
#define FS26_FS_FS1B_TDUR_25MS           (0x0005U << FS26_FS_FS1B_TDUR_SHIFT)
/* 30 ms */
#define FS26_FS_FS1B_TDUR_30MS           (0x0006U << FS26_FS_FS1B_TDUR_SHIFT)
/* 40 ms */
#define FS26_FS_FS1B_TDUR_40MS           (0x0007U << FS26_FS_FS1B_TDUR_SHIFT)
/* 50 ms */
#define FS26_FS_FS1B_TDUR_50MS           (0x0008U << FS26_FS_FS1B_TDUR_SHIFT)
/* 60 ms */
#define FS26_FS_FS1B_TDUR_60MS           (0x0009U << FS26_FS_FS1B_TDUR_SHIFT)
/* 80 ms */
#define FS26_FS_FS1B_TDUR_80MS           (0x000AU << FS26_FS_FS1B_TDUR_SHIFT)
/* 100 ms */
#define FS26_FS_FS1B_TDUR_100MS          (0x000BU << FS26_FS_FS1B_TDUR_SHIFT)
/* 125 ms */
#define FS26_FS_FS1B_TDUR_125MS          (0x000CU << FS26_FS_FS1B_TDUR_SHIFT)
/* 150 ms */
#define FS26_FS_FS1B_TDUR_150MS          (0x000DU << FS26_FS_FS1B_TDUR_SHIFT)
/* 175 ms */
#define FS26_FS_FS1B_TDUR_175MS          (0x000EU << FS26_FS_FS1B_TDUR_SHIFT)
/* 200 ms */
#define FS26_FS_FS1B_TDUR_200MS          (0x000FU << FS26_FS_FS1B_TDUR_SHIFT)
/* 225 ms */
#define FS26_FS_FS1B_TDUR_225MS          (0x0010U << FS26_FS_FS1B_TDUR_SHIFT)
/* 250 ms */
#define FS26_FS_FS1B_TDUR_250MS          (0x0011U << FS26_FS_FS1B_TDUR_SHIFT)
/* 300 ms */
#define FS26_FS_FS1B_TDUR_300MS          (0x0012U << FS26_FS_FS1B_TDUR_SHIFT)
/* 400 ms */
#define FS26_FS_FS1B_TDUR_400MS          (0x0013U << FS26_FS_FS1B_TDUR_SHIFT)
/* 500 ms */
#define FS26_FS_FS1B_TDUR_500MS          (0x0014U << FS26_FS_FS1B_TDUR_SHIFT)
/* 600 ms */
#define FS26_FS_FS1B_TDUR_600MS          (0x0015U << FS26_FS_FS1B_TDUR_SHIFT)
/* 700 ms */
#define FS26_FS_FS1B_TDUR_700MS          (0x0016U << FS26_FS_FS1B_TDUR_SHIFT)
/* 800 ms */
#define FS26_FS_FS1B_TDUR_800MS          (0x0017U << FS26_FS_FS1B_TDUR_SHIFT)
/* 1 s */
#define FS26_FS_FS1B_TDUR_1S             (0x0018U << FS26_FS_FS1B_TDUR_SHIFT)
/* 2 s */
#define FS26_FS_FS1B_TDUR_2S             (0x0019U << FS26_FS_FS1B_TDUR_SHIFT)
/* 4 s */
#define FS26_FS_FS1B_TDUR_4S             (0x001AU << FS26_FS_FS1B_TDUR_SHIFT)
/* 5 s */
#define FS26_FS_FS1B_TDUR_5S             (0x001BU << FS26_FS_FS1B_TDUR_SHIFT)
/* 6 s */
#define FS26_FS_FS1B_TDUR_6S             (0x001CU << FS26_FS_FS1B_TDUR_SHIFT)
/* 8 s */
#define FS26_FS_FS1B_TDUR_8S             (0x001DU << FS26_FS_FS1B_TDUR_SHIFT)
/* 10 s */
#define FS26_FS_FS1B_TDUR_10S            (0x001EU << FS26_FS_FS1B_TDUR_SHIFT)
/* Infinite (FS1b released by MCU) */
#define FS26_FS_FS1B_TDUR_INFINITE       (0x001FU << FS26_FS_FS1B_TDUR_SHIFT)

/* 0 ms (start with FS0b - no delay) */
#define FS26_FS_FS1B_TDELAY_0MS          (0x0000U << FS26_FS_FS1B_TDELAY_SHIFT)
/* 5 ms */
#define FS26_FS_FS1B_TDELAY_5MS          (0x0001U << FS26_FS_FS1B_TDELAY_SHIFT)
/* 10 ms */
#define FS26_FS_FS1B_TDELAY_10MS         (0x0002U << FS26_FS_FS1B_TDELAY_SHIFT)
/* 15 ms */
#define FS26_FS_FS1B_TDELAY_15MS         (0x0003U << FS26_FS_FS1B_TDELAY_SHIFT)
/* 20 ms */
#define FS26_FS_FS1B_TDELAY_20MS         (0x0004U << FS26_FS_FS1B_TDELAY_SHIFT)
/* 25 ms */
#define FS26_FS_FS1B_TDELAY_25MS         (0x0005U << FS26_FS_FS1B_TDELAY_SHIFT)
/* 30 ms */
#define FS26_FS_FS1B_TDELAY_30MS         (0x0006U << FS26_FS_FS1B_TDELAY_SHIFT)
/* 40 ms */
#define FS26_FS_FS1B_TDELAY_40MS         (0x0007U << FS26_FS_FS1B_TDELAY_SHIFT)
/* 50 ms */
#define FS26_FS_FS1B_TDELAY_50MS         (0x0008U << FS26_FS_FS1B_TDELAY_SHIFT)
/* 60 ms */
#define FS26_FS_FS1B_TDELAY_60MS         (0x0009U << FS26_FS_FS1B_TDELAY_SHIFT)
/* 80 ms */
#define FS26_FS_FS1B_TDELAY_80MS         (0x000AU << FS26_FS_FS1B_TDELAY_SHIFT)
/* 100 ms */
#define FS26_FS_FS1B_TDELAY_100MS        (0x000BU << FS26_FS_FS1B_TDELAY_SHIFT)
/* 125 ms */
#define FS26_FS_FS1B_TDELAY_125MS        (0x000CU << FS26_FS_FS1B_TDELAY_SHIFT)
/* 150 ms */
#define FS26_FS_FS1B_TDELAY_150MS        (0x000DU << FS26_FS_FS1B_TDELAY_SHIFT)
/* 175 ms */
#define FS26_FS_FS1B_TDELAY_175MS        (0x000EU << FS26_FS_FS1B_TDELAY_SHIFT)
/* 200 ms */
#define FS26_FS_FS1B_TDELAY_200MS        (0x000FU << FS26_FS_FS1B_TDELAY_SHIFT)
/* 225 ms */
#define FS26_FS_FS1B_TDELAY_225MS        (0x0010U << FS26_FS_FS1B_TDELAY_SHIFT)
/* 250 ms */
#define FS26_FS_FS1B_TDELAY_250MS        (0x0011U << FS26_FS_FS1B_TDELAY_SHIFT)
/* 300 ms */
#define FS26_FS_FS1B_TDELAY_300MS        (0x0012U << FS26_FS_FS1B_TDELAY_SHIFT)
/* 400 ms */
#define FS26_FS_FS1B_TDELAY_400MS        (0x0013U << FS26_FS_FS1B_TDELAY_SHIFT)
/* 500 ms */
#define FS26_FS_FS1B_TDELAY_500MS        (0x0014U << FS26_FS_FS1B_TDELAY_SHIFT)
/* 600 ms */
#define FS26_FS_FS1B_TDELAY_600MS        (0x0015U << FS26_FS_FS1B_TDELAY_SHIFT)
/* 700 ms */
#define FS26_FS_FS1B_TDELAY_700MS        (0x0016U << FS26_FS_FS1B_TDELAY_SHIFT)
/* 800 ms */
#define FS26_FS_FS1B_TDELAY_800MS        (0x0017U << FS26_FS_FS1B_TDELAY_SHIFT)
/* 900 ms */
#define FS26_FS_FS1B_TDELAY_900MS        (0x0018U << FS26_FS_FS1B_TDELAY_SHIFT)
/* 1 s */
#define FS26_FS_FS1B_TDELAY_1S           (0x0019U << FS26_FS_FS1B_TDELAY_SHIFT)
/* 2 s */
#define FS26_FS_FS1B_TDELAY_2S           (0x001AU << FS26_FS_FS1B_TDELAY_SHIFT)
/* 4 s */
#define FS26_FS_FS1B_TDELAY_4S           (0x001BU << FS26_FS_FS1B_TDELAY_SHIFT)
/* 5 s */
#define FS26_FS_FS1B_TDELAY_5S           (0x001CU << FS26_FS_FS1B_TDELAY_SHIFT)
/* 6 s */
#define FS26_FS_FS1B_TDELAY_6S           (0x001DU << FS26_FS_FS1B_TDELAY_SHIFT)
/* 8 s */
#define FS26_FS_FS1B_TDELAY_8S           (0x001EU << FS26_FS_FS1B_TDELAY_SHIFT)
/* 10 s */
#define FS26_FS_FS1B_TDELAY_10S          (0x001FU << FS26_FS_FS1B_TDELAY_SHIFT)

/******************************************************************************/
/* FS_DIAG_SAFETY1 - Type: RW                                                 */
/******************************************************************************/
#define FS26_FS_DIAG_SAFETY1_ADDR        0x14U
#define FS26_FS_DIAG_SAFETY1_DEFAULT     0x0000U

/* LBIST Status (MSB = LBIST_CHK_PAT_OK, LSB = LBIST_CHECKER_OK) */
#define FS26_FS_LBIST_STATUS_MASK        0x0003U
#define FS26_FS_LBIST_STATUS_SHIFT       0x0000U
/* Drift of the Fail Safe Oscillator */
#define FS26_FS_FS_OSC_DRIFT_MASK        0x0004U
#define FS26_FS_FS_OSC_DRIFT_SHIFT       0x0002U
/* FS SPI communication error - CRC */
#define FS26_FS_SPI_FS_CRC_MASK          0x0008U
#define FS26_FS_SPI_FS_CRC_SHIFT         0x0003U
/* Invalid FS SPI access (wrong write or read, Write to INIT registers in normal mode, or Wrong address) */
#define FS26_FS_SPI_FS_REQ_MASK          0x0010U
#define FS26_FS_SPI_FS_REQ_SHIFT         0x0004U
/* FS SPI SCLK Error detection */
#define FS26_FS_SPI_FS_CLK_MASK          0x0020U
#define FS26_FS_SPI_FS_CLK_SHIFT         0x0005U
/* Diagnostic on ABIST on Demand */
#define FS26_FS_ABIST2_DONE_MASK         0x0040U
#define FS26_FS_ABIST2_DONE_SHIFT        0x0006U
/* Report ABIST 2 status */
#define FS26_FS_ABIST2_PASS_MASK         0x0080U
#define FS26_FS_ABIST2_PASS_SHIFT        0x0007U
/* Diagnostic on ABIST 1 */
#define FS26_FS_ABIST1_PASS_MASK         0x0100U
#define FS26_FS_ABIST1_PASS_SHIFT        0x0008U
/* WD Refresh status - Timing */
#define FS26_FS_BAD_WD_TIMING_MASK       0x0200U
#define FS26_FS_BAD_WD_TIMING_SHIFT      0x0009U
/* WD Refresh status - Data */
#define FS26_FS_BAD_WD_DATA_MASK         0x0400U
#define FS26_FS_BAD_WD_DATA_SHIFT        0x000AU

/* LBIST FAIL */
#define FS26_FS_LBIST_STATUS_FAIL        (0x0000U << FS26_FS_LBIST_STATUS_SHIFT)
/* LBIST BYPASSED */
#define FS26_FS_LBIST_STATUS_BYPASSED    (0x0001U << FS26_FS_LBIST_STATUS_SHIFT)
/* LBIST FAIL */
#define FS26_FS_LBIST_STATUS_FAIL_0      (0x0002U << FS26_FS_LBIST_STATUS_SHIFT)
/* LBIST OK */
#define FS26_FS_LBIST_STATUS_OK          (0x0003U << FS26_FS_LBIST_STATUS_SHIFT)

/* No Drift */
#define FS26_FS_FS_OSC_DRIFT_NO_DRIFT    (0x0000U << FS26_FS_FS_OSC_DRIFT_SHIFT)
/* Oscillator Drift */
#define FS26_FS_FS_OSC_DRIFT_DRIFT       (0x0001U << FS26_FS_FS_OSC_DRIFT_SHIFT)

/* No Error */
#define FS26_FS_SPI_FS_CRC_NO_ERROR      (0x0000U << FS26_FS_SPI_FS_CRC_SHIFT)
/* Error detected in the CRC */
#define FS26_FS_SPI_FS_CRC_ERROR         (0x0001U << FS26_FS_SPI_FS_CRC_SHIFT)

/* No Error */
#define FS26_FS_SPI_FS_REQ_NO_ERROR      (0x0000U << FS26_FS_SPI_FS_REQ_SHIFT)
/* SPI Violation */
#define FS26_FS_SPI_FS_REQ_ERROR         (0x0001U << FS26_FS_SPI_FS_REQ_SHIFT)

/* No Error */
#define FS26_FS_SPI_FS_CLK_NO_ERROR      (0x0000U << FS26_FS_SPI_FS_CLK_SHIFT)
/* Wrong number of CLK Cycles (other than 32) */
#define FS26_FS_SPI_FS_CLK_ERROR         (0x0001U << FS26_FS_SPI_FS_CLK_SHIFT)

/* ABIST on demand Fail or not executed */
#define FS26_FS_ABIST2_DONE_FAIL         (0x0000U << FS26_FS_ABIST2_DONE_SHIFT)
/* ABIST On Demand Pass */
#define FS26_FS_ABIST2_DONE_PASS         (0x0001U << FS26_FS_ABIST2_DONE_SHIFT)

/* ABIST2 not finished */
#define FS26_FS_ABIST2_PASS_NOT_FINISHED (0x0000U << FS26_FS_ABIST2_PASS_SHIFT)
/* ABIST2 PASS */
#define FS26_FS_ABIST2_PASS_PASS         (0x0001U << FS26_FS_ABIST2_PASS_SHIFT)

/* ABIST Fail or not executed */
#define FS26_FS_ABIST1_PASS_FAIL         (0x0000U << FS26_FS_ABIST1_PASS_SHIFT)
/* ABIST 1 Pass */
#define FS26_FS_ABIST1_PASS_PASS         (0x0001U << FS26_FS_ABIST1_PASS_SHIFT)

/* Good WD Refresh */
#define FS26_FS_BAD_WD_TIMING_GOOD       (0x0000U << FS26_FS_BAD_WD_TIMING_SHIFT)
/* Bad WD refresh, Error in the Timing (window) */
#define FS26_FS_BAD_WD_TIMING_BAD        (0x0001U << FS26_FS_BAD_WD_TIMING_SHIFT)

/* Good WD Refresh */
#define FS26_FS_BAD_WD_DATA_GOOD         (0x0000U << FS26_FS_BAD_WD_DATA_SHIFT)
/* Bad WD refresh, Error in the Data */
#define FS26_FS_BAD_WD_DATA_BAD          (0x0001U << FS26_FS_BAD_WD_DATA_SHIFT)

/******************************************************************************/
/* FS_DIAG_SAFETY2 - Type: RW                                                 */
/******************************************************************************/
#define FS26_FS_DIAG_SAFETY2_ADDR        0x15U
#define FS26_FS_DIAG_SAFETY2_DEFAULT     0x0000U

/* Report ERRMON pin status */
#define FS26_FS_ERRMON_PIN_STATUS_MASK   0x0001U
#define FS26_FS_ERRMON_PIN_STATUS_SHIFT  0x0000U
/* Report an error in the ERRMON input */
#define FS26_FS_ERRMON_MASK              0x0002U
#define FS26_FS_ERRMON_SHIFT             0x0001U
/* Acknowledge ERRMON Failure Timer */
#define FS26_FS_ERRMON_ACK_MASK          0x0004U
#define FS26_FS_ERRMON_ACK_SHIFT         0x0002U
/* Sense of FCCU2 */
#define FS26_FS_FCCU2_RT_MASK            0x0008U
#define FS26_FS_FCCU2_RT_SHIFT           0x0003U
/* Sense of FCCU1 */
#define FS26_FS_FCCU1_RT_MASK            0x0010U
#define FS26_FS_FCCU1_RT_SHIFT           0x0004U
/* Report an error in the FCCU2 input */
#define FS26_FS_FCCU2_MASK               0x0020U
#define FS26_FS_FCCU2_SHIFT              0x0005U
/* Report an error in the FCCU1 input */
#define FS26_FS_FCCU1_MASK               0x0040U
#define FS26_FS_FCCU1_SHIFT              0x0006U
/* Report an error in the FCCU12 input */
#define FS26_FS_FCCU12_MASK              0x0080U
#define FS26_FS_FCCU12_SHIFT             0x0007U

/* Low level */
#define FS26_FS_ERRMON_PIN_STATUS_LOW    (0x0000U << FS26_FS_ERRMON_PIN_STATUS_SHIFT)
/* High level */
#define FS26_FS_ERRMON_PIN_STATUS_HIGH   (0x0001U << FS26_FS_ERRMON_PIN_STATUS_SHIFT)

/* No error */
#define FS26_FS_ERRMON_NO_ERROR          (0x0000U << FS26_FS_ERRMON_SHIFT)
/* Error Detected */
#define FS26_FS_ERRMON_ERROR             (0x0001U << FS26_FS_ERRMON_SHIFT)

/* No error */
#define FS26_FS_ERRMON_ACK_NO_ERROR      (0x0000U << FS26_FS_ERRMON_ACK_SHIFT)
/* Acknowledge ERRMON timeout */
#define FS26_FS_ERRMON_ACK_TIMEOUT       (0x0001U << FS26_FS_ERRMON_ACK_SHIFT)

/* FCCU2 Low */
#define FS26_FS_FCCU2_RT_LOW             (0x0000U << FS26_FS_FCCU2_RT_SHIFT)
/* FCCU2 Low */
#define FS26_FS_FCCU2_RT_HIGH            (0x0001U << FS26_FS_FCCU2_RT_SHIFT)

/* FCCU1 Low */
#define FS26_FS_FCCU1_RT_LOW             (0x0000U << FS26_FS_FCCU1_RT_SHIFT)
/* FCCU1 Low */
#define FS26_FS_FCCU1_RT_HIGH            (0x0001U << FS26_FS_FCCU1_RT_SHIFT)

/* No error */
#define FS26_FS_FCCU2_NO_ERROR           (0x0000U << FS26_FS_FCCU2_SHIFT)
/* Error Detected */
#define FS26_FS_FCCU2_ERROR              (0x0001U << FS26_FS_FCCU2_SHIFT)

/* No error */
#define FS26_FS_FCCU1_NO_ERROR           (0x0000U << FS26_FS_FCCU1_SHIFT)
/* Error Detected */
#define FS26_FS_FCCU1_ERROR              (0x0001U << FS26_FS_FCCU1_SHIFT)

/* No error */
#define FS26_FS_FCCU12_NO_ERROR          (0x0000U << FS26_FS_FCCU12_SHIFT)
/* Error Detected */
#define FS26_FS_FCCU12_ERROR             (0x0001U << FS26_FS_FCCU12_SHIFT)

/******************************************************************************/
/* FS_INTB_MASK - Type: RW                                                    */
/******************************************************************************/
#define FS26_FS_INTB_MASK_ADDR           0x16U
#define FS26_FS_INTB_MASK_DEFAULT        0x0000U

/* Interruption Mask on ERRMON */
#define FS26_FS_ERRMON_M_MASK            0x0010U
#define FS26_FS_ERRMON_M_SHIFT           0x0004U
/* Interruption Mask on BAD_WD_REFRESH */
#define FS26_FS_BAD_WD_M_MASK            0x0020U
#define FS26_FS_BAD_WD_M_SHIFT           0x0005U
/* Interruption Mask on FCCU2 */
#define FS26_FS_FCCU2_M_MASK             0x0040U
#define FS26_FS_FCCU2_M_SHIFT            0x0006U
/* Interruption Mask on FCCU1 */
#define FS26_FS_FCCU1_M_MASK             0x0080U
#define FS26_FS_FCCU1_M_SHIFT            0x0007U
/* Interruption Mask on VMON_EXT event */
#define FS26_FS_EXT_M_MASK               0x0100U
#define FS26_FS_EXT_M_SHIFT              0x0008U
/* Interruption Mask on VMON_REF event */
#define FS26_FS_REF_M_MASK               0x0200U
#define FS26_FS_REF_M_SHIFT              0x0009U
/* Interruption Mask on VMON_TRK2 event */
#define FS26_FS_TRK2_M_MASK              0x0400U
#define FS26_FS_TRK2_M_SHIFT             0x000AU
/* Interruption Mask on VMON_TRK1 event */
#define FS26_FS_TRK1_M_MASK              0x0800U
#define FS26_FS_TRK1_M_SHIFT             0x000BU
/* Interruption Mask on VMON_LDO2 event */
#define FS26_FS_LDO2_M_MASK              0x1000U
#define FS26_FS_LDO2_M_SHIFT             0x000CU
/* Interruption Mask on VMON_LDO1 event */
#define FS26_FS_LDO1_M_MASK              0x2000U
#define FS26_FS_LDO1_M_SHIFT             0x000DU
/* Interruption Mask on VMON_CORE event */
#define FS26_FS_CORE_M_MASK              0x4000U
#define FS26_FS_CORE_M_SHIFT             0x000EU
/* Interruption Mask on VMON_PRE event */
#define FS26_FS_VPRE_M_MASK              0x8000U
#define FS26_FS_VPRE_M_SHIFT             0x000FU

/* Interruption Not Masked */
#define FS26_FS_ERRMON_M_NOT_MASKED      (0x0000U << FS26_FS_ERRMON_M_SHIFT)
/* Interruption Masked */
#define FS26_FS_ERRMON_M_MASKED          (0x0001U << FS26_FS_ERRMON_M_SHIFT)

/* Interruption Not Masked */
#define FS26_FS_BAD_WD_M_NOT_MASKED      (0x0000U << FS26_FS_BAD_WD_M_SHIFT)
/* Interruption Masked */
#define FS26_FS_BAD_WD_M_MASKED          (0x0001U << FS26_FS_BAD_WD_M_SHIFT)

/* Interruption Not Masked */
#define FS26_FS_FCCU2_M_NOT_MASKED       (0x0000U << FS26_FS_FCCU2_M_SHIFT)
/* Interruption Masked */
#define FS26_FS_FCCU2_M_MASKED           (0x0001U << FS26_FS_FCCU2_M_SHIFT)

/* Interruption Not Masked */
#define FS26_FS_FCCU1_M_NOT_MASKED       (0x0000U << FS26_FS_FCCU1_M_SHIFT)
/* Interruption Masked */
#define FS26_FS_FCCU1_M_MASKED           (0x0001U << FS26_FS_FCCU1_M_SHIFT)

/* Interruption Not Masked */
#define FS26_FS_EXT_M_NOT_MASKED         (0x0000U << FS26_FS_EXT_M_SHIFT)
/* Interruption Masked */
#define FS26_FS_EXT_M_MASKED             (0x0001U << FS26_FS_EXT_M_SHIFT)

/* Interruption Not Masked */
#define FS26_FS_REF_M_NOT_MASKED         (0x0000U << FS26_FS_REF_M_SHIFT)
/* Interruption Masked */
#define FS26_FS_REF_M_MASKED             (0x0001U << FS26_FS_REF_M_SHIFT)

/* Interruption Not Masked */
#define FS26_FS_TRK2_M_NOT_MASKED        (0x0000U << FS26_FS_TRK2_M_SHIFT)
/* Interruption Masked */
#define FS26_FS_TRK2_M_MASKED            (0x0001U << FS26_FS_TRK2_M_SHIFT)

/* Interruption Not Masked */
#define FS26_FS_TRK1_M_NOT_MASKED        (0x0000U << FS26_FS_TRK1_M_SHIFT)
/* Interruption Masked */
#define FS26_FS_TRK1_M_MASKED            (0x0001U << FS26_FS_TRK1_M_SHIFT)

/* Interruption Not Masked */
#define FS26_FS_LDO2_M_NOT_MASKED        (0x0000U << FS26_FS_LDO2_M_SHIFT)
/* Interruption Masked */
#define FS26_FS_LDO2_M_MASKED            (0x0001U << FS26_FS_LDO2_M_SHIFT)

/* Interruption Not Masked */
#define FS26_FS_LDO1_M_NOT_MASKED        (0x0000U << FS26_FS_LDO1_M_SHIFT)
/* Interruption Masked */
#define FS26_FS_LDO1_M_MASKED            (0x0001U << FS26_FS_LDO1_M_SHIFT)

/* Interruption Not Masked */
#define FS26_FS_CORE_M_NOT_MASKED        (0x0000U << FS26_FS_CORE_M_SHIFT)
/* Interruption Masked */
#define FS26_FS_CORE_M_MASKED            (0x0001U << FS26_FS_CORE_M_SHIFT)

/* Interruption Not Masked */
#define FS26_FS_VPRE_M_NOT_MASKED        (0x0000U << FS26_FS_VPRE_M_SHIFT)
/* Interruption Masked */
#define FS26_FS_VPRE_M_MASKED            (0x0001U << FS26_FS_VPRE_M_SHIFT)

/******************************************************************************/
/* FS_STATES - Type: RW                                                       */
/******************************************************************************/
#define FS26_FS_STATES_ADDR              0x17U
#define FS26_FS_STATES_DEFAULT           0x0000U

/* Actual State of the Fail Safe State machine */
#define FS26_FS_FS_STATES_MASK           0x001FU
#define FS26_FS_FS_STATES_SHIFT          0x0000U
/* INIT Register Corruption detection */
#define FS26_FS_REG_CORRUPT_MASK         0x0800U
#define FS26_FS_REG_CORRUPT_SHIFT        0x000BU
/* OTP bits corruption detection (5ms cyclic check) */
#define FS26_FS_OTP_CORRUPT_MASK         0x1000U
#define FS26_FS_OTP_CORRUPT_SHIFT        0x000CU
/* DEBUG MODE Status */
#define FS26_FS_DBG_MODE_MASK            0x2000U
#define FS26_FS_DBG_MODE_SHIFT           0x000DU
/* Leave Debug Mode */
#define FS26_FS_EXIT_DBG_MODE_MASK       0x4000U
#define FS26_FS_EXIT_DBG_MODE_SHIFT      0x000EU
/* Test Mode Activation Status */
#define FS26_FS_TM_ACTIVE_MASK           0x8000U
#define FS26_FS_TM_ACTIVE_SHIFT          0x000FU

#define FS26_FS_FS_STATES_0              (0x0000U << FS26_FS_FS_STATES_SHIFT)
#define FS26_FS_FS_STATES_1              (0x0001U << FS26_FS_FS_STATES_SHIFT)

/* No corruption detected in init registers (i.e. no mismatch between register/register_NOT) pair */
#define FS26_FS_REG_CORRUPT_NO_ERROR     (0x0000U << FS26_FS_REG_CORRUPT_SHIFT)
/* Data content corruption detected in init registers (i.e. mismatch between register/register_NOT) pair */
#define FS26_FS_REG_CORRUPT_ERROR        (0x0001U << FS26_FS_REG_CORRUPT_SHIFT)

/* No OTP content CRC error Detected */
#define FS26_FS_OTP_CORRUPT_NO_ERROR     (0x0000U << FS26_FS_OTP_CORRUPT_SHIFT)
/* OTP Content CRC error detected */
#define FS26_FS_OTP_CORRUPT_ERROR        (0x0001U << FS26_FS_OTP_CORRUPT_SHIFT)

/* Not in DEBUG MODE */
#define FS26_FS_DBG_MODE_NOT             (0x0000U << FS26_FS_DBG_MODE_SHIFT)
/* In DEBUG MODE */
#define FS26_FS_DBG_MODE_DEBUG           (0x0001U << FS26_FS_DBG_MODE_SHIFT)

/* No action */
#define FS26_FS_EXIT_DBG_MODE_NO_ACTION  (0x0000U << FS26_FS_EXIT_DBG_MODE_SHIFT)
/* Leave Debug mode */
#define FS26_FS_EXIT_DBG_MODE_LEAVE      (0x0001U << FS26_FS_EXIT_DBG_MODE_SHIFT)

/* Test mode is not activated */
#define FS26_FS_TM_ACTIVE_NOT_ACTIVE     (0x0000U << FS26_FS_TM_ACTIVE_SHIFT)
/* Test mode Activated */
#define FS26_FS_TM_ACTIVE_ACTIVE         (0x0001U << FS26_FS_TM_ACTIVE_SHIFT)

/******************************************************************************/
/* FS_LP_REQ - Type: RW                                                       */
/******************************************************************************/
#define FS26_FS_LP_REQ_ADDR              0x18U
#define FS26_FS_LP_REQ_DEFAULT           0x0000U

/* LOW power command */
#define FS26_FS_FS_LP_REQ_MASK           0x00FFU
#define FS26_FS_FS_LP_REQ_SHIFT          0x0000U

/* Transition to PRE LPOFF */
#define FS26_FS_FS_LP_REQ_PRE_LPOFF      (0x00A5U << FS26_FS_FS_LP_REQ_SHIFT)
/* Transition to FS go LPOFF */
#define FS26_FS_FS_LP_REQ_LPOFF          (0x005AU << FS26_FS_FS_LP_REQ_SHIFT)
/* Transition to PRE STDBY */
#define FS26_FS_FS_LP_REQ_PRE_STANDBY    (0x00AAU << FS26_FS_FS_LP_REQ_SHIFT)
/* Transition to FS go STANDBY */
#define FS26_FS_FS_LP_REQ_STANDBY        (0x0055U << FS26_FS_FS_LP_REQ_SHIFT)

/******************************************************************************/
/* FS_LDT_LPSEL - Type: RW                                                    */
/******************************************************************************/
#define FS26_FS_LDT_LPSEL_ADDR           0x19U
#define FS26_FS_LDT_LPSEL_DEFAULT        0x0000U

/* LOW power command */
#define FS26_FS_LDT_LPSEL_MASK           0x00FFU
#define FS26_FS_LDT_LPSEL_SHIFT          0x0000U

/* Transition to FS go LPOFF when M2FS_ldt_go_lp=1 */
#define FS26_FS_LDT_LPSEL_L              (0x00A5U << FS26_FS_LDT_LPSEL_SHIFT)
/* Transition to FS go STANDBY when M2FS_ldt_go_lp=1 */
#define FS26_FS_LDT_LPSEL_STANDBY        (0x00AAU << FS26_FS_LDT_LPSEL_SHIFT)

#endif /* DRIVERS_FS26_FS26_MAP_H_ */
