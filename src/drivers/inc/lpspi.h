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

#ifndef DRIVERS_LPSPI_LPSPI_H_
#define DRIVERS_LPSPI_LPSPI_H_

#include "S32K344_LPSPI.h"
/******************************************************************************
* LPSPI modules
*
*//*! @addtogroup lpspi_modules
* @{
* @details LPSPI modules support by devices:
* |Module |S32K314|S32K324|S32K344|S32K358|
* |:-----:|:-----:|:-----:|:-----:|:-----:|
* |LPSPI0 |X      |X      |X      |X      |
* |LPSPI1 |X      |X      |X      |X      |
* |LPSPI2 |X      |X      |X      |X      |
* |LPSPI3 |X      |X      |X      |X      |
* |LPSPI4 |X      |X      |X      |X      |
* |LPSPI5 |X      |X      |X      |X      |
*******************************************************************************/

#define LPSPI0  ((LPSPI_Type *)IP_LPSPI_0_BASE)  ///< LPSPI0 module

#if defined(LPSPI_1_BASE)
  #define LPSPI1  ((LPSPI_Type *)IP_LPSPI_1_BASE)  ///< LPSPI1 module
#endif
#if defined(LPSPI_2_BASE)
  #define LPSPI2  ((LPSPI_Type *)IP_LPSPI_2_BASE)  ///< LPSPI2 module
#endif
#if defined(LPSPI_3_BASE)
  #define LPSPI3  ((LPSPI_Type *)IP_LPSPI_3_BASE)  ///< LPSPI3 module
#endif
#if defined(LPSPI_4_BASE)
  #define LPSPI4  ((LPSPI_Type *)IP_LPSPI_4_BASE)  ///< LPSPI4 module
#endif
#if defined(LPSPI_5_BASE)
  #define LPSPI5  ((LPSPI_Type *)LPSPI_5_BASE)  ///< LPSPI5 module
#endif
/*! @} End of lpspi_modules                                                   */


/******************************************************************************
 * Configuration structure definitions                                        *
 ******************************************************************************/
typedef struct { uint32_t CR, CFGR0, CFGR1, DMR0, DMR1, CCR, FCR, TCR; } tLPSPI;

/******************************************************************************
* LPSPI default list configurations used by LPSPI_InitList() function
*
*//*! @addtogroup lpspi_config
* @{
*******************************************************************************/
/***************************************************************************//*!
 * @brief   Basic configuration for master mode
 * @details Basic configuration for master mode
 * |Feature                                   |Configuration                                                                                    |
 * |:----------------------------------------:|:-----------------------------------------------------------------------------------------------:|
 * |Module Enable                             |Disabled                                                                                          |
 * |Debug  Enable                             |Enabled                                                                                          |
 * |Host Request Enable                       |Disabled                                                                                         |
 * |Circular FIFO Enable                      |Disabled                                                                                         |
 * |Receive Data Match Only                   |[x] Received data is stored in the receive FIFO as in normal operations                          |
 * |^                                         |[ ] Received data is discarded unless the Data Match Flag (DMF) is set                           |
 * |Mode                                      |[x] Master                                                                                       |
 * |^                                         |[ ] Slave                                                                                        |
 * |Sample                                    |[x] Input data is sampled on SCK edge                                                            |
 * |^                                         |[ ] Input data is sampled on delayed SCK edge                                                    |
 * |Automatic PCS                             |Disabled                                                                                         |
 * |No Stall                                  |[ ] Transfers will not stall. FIFO underruns and overruns can occur.                             |
 * |^                                         |[x] Transfers will stall when the transmit FIFO is empty or the receive FIFO is full             |
 * |Peripheral Chip Select Polarity           |All PCS pins are active low                                                                      |
 * |Match Configuration                       |[x] Match is disabled                                                                            |
 * |^                                         |[ ] if 1st data word equals MATCH0 OR MATCH1                                                     |
 * |^                                         |[ ] if any data word equals MATCH0 OR MATCH1                                                     |
 * |^                                         |[ ] if 1st data word equals MATCH0 AND 2nd data word equals MATCH1                               |
 * |^                                         |[ ] if any data word equals MATCH0 AND the next data word equals MATCH1                          |
 * |^                                         |[ ] Match is enabled, if (1st data word AND MATCH1) equals (MATCH0 AND MATCH1)                   |
 * |^                                         |[ ] Match is enabled, if (any data word AND MATCH1) equals (MATCH0 AND MATCH1)                   |
 * |Pin Configuration                         |[x] SIN is used for input data and SOUT is used for output data                                  |
 * |^                                         |[ ] SIN is used for both input and output data, only half-duplex serial transfers are supported  |
 * |^                                         |[ ] SOUT is used for both input and output data, only half-duplex serial transfers are supported |
 * |^                                         |[ ] SOUT is used for input data and SIN is used for output data                                  |
 * |Output Configuration                      |[x] Output data retains last value when chip select is negated                                   |
 * |^                                         |[ ] Output data is tristated when chip select is negated                                         |
 * |Peripheral Chip Select Configuration      |[x] PCS[7:2] are configured for chip select function                                             |
 * |^                                         |[ ] PCS[3:2] are configured for half-duplex 4-bit transfers (PCS[3:2] = DATA[3:2])               |
 * |^                                         |[ ] PCS[7:2] are configured for half-duplex 4-bit and 8-bit transfers (PCS[7:2] = DATA[7:2])     |
 * @param   sckpscs  SCK-to-PCS Delay value [1..256].
 * @param   pscssck  PCS-to-SCK Delay value [1..256].
 * @param   dbt      Delay Between Transfers. Bits 7-4 SCK Inter-Frame Delay value [1-15]. Bits 3-0 PCS to PCS delay value [2..15].
 * @param   sckdiv   SCK Divider. Bits 7-4 SCK Hold value [1-15]. Bits 3-0 SCK Setup value [1..15].
 * @param   rxwm     Receive FIFO Watermark  [0-3]
 * @param   txwm     Transmit FIFO Watermark [0-3]
 * @showinitializer
 ******************************************************************************/

#define LPSPI_MSTR_CONFIG(sckpscs,pscssck,dbt,sckdiv,rxwm,txwm)                                             \
(tLPSPI){                                                                                                   \
/*CR   */  CLR(LPSPI_CR_MEN_MASK)|CLR(LPSPI_CR_RST_MASK)|SET(LPSPI_CR_DBGEN_MASK)|                          \
/*...  */  CLR(LPSPI_CR_RTF_MASK)|CLR(LPSPI_CR_RRF_MASK),                                                   \
/*CFGR0*/  CLR(LPSPI_CFGR0_HREN_MASK)|CLR(LPSPI_CFGR0_HRPOL_MASK )|CLR(LPSPI_CFGR0_HRSEL_MASK)|             \
/*...  */  CLR(LPSPI_CFGR0_CIRFIFO_MASK)|CLR(LPSPI_CFGR0_RDMO_MASK),                                        \
/*CFGR1*/  SET(LPSPI_CFGR1_MASTER_MASK)|CLR(LPSPI_CFGR1_SAMPLE_MASK)|CLR(LPSPI_CFGR1_AUTOPCS_MASK)|         \
/*...  */  CLR(LPSPI_CFGR1_NOSTALL_MASK)|LPSPI_CFGR1_PCSPOL(0)|LPSPI_CFGR1_MATCFG(0)|LPSPI_CFGR1_PINCFG(0)| \
/*...  */  CLR(LPSPI_CFGR1_OUTCFG_MASK)|CLR(LPSPI_CFGR1_PCSCFG_MASK),                                       \
/*DMR0 */  LPSPI_DMR0_MATCH0(0),                                                                            \
/*DMR1 */  LPSPI_DMR1_MATCH1(0),                                                                            \
/*CCR  */  LPSPI_CCR_SCKDIV(sckdiv)|LPSPI_CCR_DBT(dbt)|LPSPI_CCR_PCSSCK(pscssck)|LPSPI_CCR_SCKPCS(sckpscs), \
/*FCR  */  LPSPI_FCR_TXWATER(txwm)|LPSPI_FCR_RXWATER(rxwm)                                                  \
}
/*! @} End of lpspi_config */

/******************************************************************************
* LPSPI interrupt request flags used by LPSPI_GetIrqFlags, LPSPI_ClrIrqFlags and LPSPI_GetClrIrqFlags functions
*
*//*! @addtogroup lpspi_irqs
* @{
*******************************************************************************/
#define LPSPI_TDF     (uint32_t)(1UL << 0)  ///< Transmit FIFO is equal or less than FCR[TXWATER]
#define LPSPI_RDF     (uint32_t)(1UL << 1)  ///< Receive FIFO is greater than FCR[RXWATER]
#define LPSPI_WCF     (uint32_t)(1UL << 8)  ///< Last bit of a received word is sampled.
#define LPSPI_FCF     (uint32_t)(1UL << 9)  ///< End of each frame transfer, when the PCS negates.
#define LPSPI_TCF     (uint32_t)(1UL << 10) ///< Transmit FIFO empty,
#define LPSPI_TEF     (uint32_t)(1UL << 11) ///< Transmit Error
#define LPSPI_REF     (uint32_t)(1UL << 12) ///< Receive Error
#define LPSPI_DMF     (uint32_t)(1UL << 13) ///< Data Match
#define LPSPI_MBF     (uint32_t)(1UL << 24) ///< Module Busy
/*! @} End of lpspi_irqs                                                    */

/******************************************************************************
* LPSPI interrupt request sources used by LPSPI_EnableIrq and LPSPI_DisableIrq functions
*
*//*! @addtogroup lpspi_irq_sources
* @{
*******************************************************************************/
#define LPSPI_TDIE    (uint32_t)(1UL <<  0) ///< Transmit Data Interrupt.
#define LPSPI_RDIE    (uint32_t)(1UL <<  1) ///< Receive Data Interrupt.
#define LPSPI_WCIE    (uint32_t)(1UL <<  8) ///< Word Complete Interrupt.
#define LPSPI_FCIE    (uint32_t)(1UL <<  9) ///< Frame Complete Interrupt.
#define LPSPI_TCIE    (uint32_t)(1UL << 10) ///< Transfer Complete Interrupt.
#define LPSPI_TEIE    (uint32_t)(1UL << 11) ///< Transmit Error Interrupt.
#define LPSPI_REIE    (uint32_t)(1UL << 12) ///< Transfer Complete Interrupt.
#define LPSPI_DMIE    (uint32_t)(1UL << 13) ///< Data Match Interrupt.
/*! @} End of lpspi_irq_sources     */

/******************************************************************************
* LPSPI DMA request sources used by LPSPI_EnableDma and LPSPI_DisableDma  function.
*
*//*! @addtogroup lpspi_dma
* @{
*******************************************************************************/
#define LPSPI_TDDE    (uint32_t)(1UL << 0) ///< Transmit Data DMA.
#define LPSPI_RDDE    (uint32_t)(1UL << 1) ///< Receive Data DMA.
/*! @} End of lpspi_dma */

/******************************************************************************
* LPSPI Receive status LPSPI_GetRxStat function.
*
*//*! @addtogroup lpspi_rx_stat
* @{
*******************************************************************************/
#define LPSPI_SOF     (uint32_t)(1UL << 0) ///< RX FIFO Empty.
#define LPSPI_RXEMPTY (uint32_t)(1UL << 1) ///< Indicates that this is the first data word received after LPSPI_PCS assertion.
/*! @} End of lpspi_rx_stat */

/******************************************************************************
* LPSPI command bit setting used by LPSPI_SetXfrCmd function
*
*//*! @addtogroup lpspi_cmd_setting
* @{
*******************************************************************************/
#define LPSPI_TXMSK   (uint32_t)(1UL << 18) ///< Transmit Data Mask. When set, transmit data is masked (no data is loaded from transmit FIFO and output pin is tristated).
#define LPSPI_RXMSK   (uint32_t)(1UL << 19) ///< Receive Data Mask. When set, receive data is masked (receive data is not stored in receive FIFO).
#define LPSPI_CONTC   (uint32_t)(1UL << 20) ///< Continuing Command. In master mode, the Continuing Command bit allows the command word to be changed within a continuous transfer.
#define LPSPI_CONT    (uint32_t)(1UL << 21) ///< Continuous Transfer. In master mode, continuous transfer will keep the PCS asserted at the end of the frame size, until a command word is received that starts a new frame. In slave mode, when continuous transfer is enabled, the LPSPI will only transmit the first FRAMESZ bits; after which the LPSPI will transmit received data (assuming a 32-bit shift register).
#define LPSPI_BYSW    (uint32_t)(1UL << 22) ///< Byte Swap. Byte swap will swap the contents of [31:24] with [7:0] and [23:16] with [15:8] for each transmit data word read from the FIFO and for each received data word stored to the FIFO (or compared with match registers).
#define LPSPI_LSBF    (uint32_t)(1UL << 23) ///< LSB First.
#define LPSPI_CPHA    (uint32_t)(1UL << 30) ///< Clock Polarity. CLR - Data is captured on the leading edge of SCK and changed on the following edge of SCK. SET - Data is changed on the leading edge of SCK and captured on the following edge of SCK.
#define LPSPI_CPOL    (uint32_t)(1UL << 31) ///< Clock Phase. CLR - The inactive state value of SCK is low. SET - The inactive state value of SCK is high
/*! @} End of lpspi_cmd_setting */

/******************************************************************************
* LPSPI Transfer Width used by LPSPI_SetXfrCmd function
*
*//*! @addtogroup lpspi_width
* @{
*******************************************************************************/
#define LPSPI_1BTRANSF   0U ///< 1 bit transfer
#define LPSPI_2BTRANSF   1U ///< 2 bit transfer
#define LPSPI_4BTRANSF   2U ///< 4 bit transfer
/*! @} End of lpspi_width */

/******************************************************************************
* LPSPI Prescaler value applied to the clock used by LPSPI_SetXfrCmd function
*
*//*! @addtogroup lpspi_div
* @{
*******************************************************************************/
#define LPSPI_DIV1       0U ///< Divide by 1
#define LPSPI_DIV2       1U ///< Divide by 2
#define LPSPI_DIV4       2U ///< Divide by 4
#define LPSPI_DIV8       3U ///< Divide by 8
#define LPSPI_DIV16      4U ///< Divide by 16
#define LPSPI_DIV32      5U ///< Divide by 32
#define LPSPI_DIV64      6U ///< Divide by 64
#define LPSPI_DIV128     7U ///< Divide by 128
/*! @} End of lpspi_div */

/******************************************************************************
* LPSPI callback registered by LPSPI_InstallCallback() function
*
*//*! @addtogroup tLPSPI_CALLBACK
* @{
*******************************************************************************/
/*! @brief tLPSPI_CALLBACK type declaration                                   */
typedef enum
{
  TDF_CALLBACK = (uint32_t)(1UL <<  0), ///< Transmit FIFO is equal or less than FCR[TXWATER]
  RDF_CALLBACK = (uint32_t)(1UL <<  1), ///< Receive FIFO is greater than FCR[RXWATER]
  WCF_CALLBACK = (uint32_t)(1UL <<  8), ///< Last bit of a received word is sampled.
  FCF_CALLBACK = (uint32_t)(1UL <<  9), ///< End of each frame transfer, when the PCS negates.
  TCF_CALLBACK = (uint32_t)(1UL << 10), ///< Transmit FIFO empty,
  TEF_CALLBACK = (uint32_t)(1UL << 11), ///< Transmit Error
  REF_CALLBACK = (uint32_t)(1UL << 12), ///< Receive Error
  DMF_CALLBACK = (uint32_t)(1UL << 13), ///< Data Match
  MBF_CALLBACK = (uint32_t)(1UL << 24)  ///< Module Busy
} tLPSPI_CALLBACK_TYPE;

/*! @brief tLPSPI_CALLBACK function declaration                               */
typedef void (*tLPSPI_CALLBACK)(volatile LPSPI_Type *module, tLPSPI_CALLBACK_TYPE type);
/*! @} End of tLPSPI_CALLBACK                                                 */

/******************************************************************************
* LPSPI function and macro definitions
*
*//*! @addtogroup lpspi_macro
* @{
*******************************************************************************/
/***************************************************************************//*!
 * @brief   Returns interrupt flags.
 * @details This macro returns interrupt flags
 * @param   module   One of @ref lpspi_modules.
 * @return  Mask of @ref lpspi_irqs.
 * @note    Implemented as a macro.
 * @see     @ref LPSPI_ClrIrqFlags
 ******************************************************************************/
#define LPSPI_GetIrqFlags(module) module->SR

/***************************************************************************//*!
 * @brief   Clears interrupt flags.
 * @details This macro clears interrupt flags given by mask parameter
 * @param   module  One of @ref lpspi_modules.
 * @param   mask    @ref uint32_t Mask of @ref lpspi_irqs.
 * @note    Implemented as a macro.
 * @see     @ref LPSPI_ClrIrqFlags @ref LPSPI_GetIrqFlags
 ******************************************************************************/
#define LPSPI_ClrIrqFlags(module,mask) do{ module->SR = (mask); }while(0)

/***************************************************************************//*!
 * @brief   Returns and clears interrupt flags.
 * @details This macro returns and clears interrupt flags.
 * @param   module   One of @ref lpspi_modules.
 * @return  Mask of @ref lpspi_irqs.
 * @note    Implemented as a macro.
 * @see     @ref LPSPI_GetIrqFlags @ref LPSPI_ClrIrqFlags @ref lpspi_irqs.
 ******************************************************************************/



#define LPSPI_GetClrIrqFlags(module)                 \
({                                                   \
  register uint32_t __r = LPSPI_GetIrqFlags(module); \
  LPSPI_ClrIrqFlags (module, __r);                   \
  __r;                                               \
})

/***************************************************************************//*!
 * @brief   Enable interrupt request.
 * @details Enables interrupt request for source given by argument.
 * @param   module   One of @ref lpspi_modules.
 * @param   mask @ref lpspi_irq_sources.
 * @note    Implemented as a macro.
 * @see     @ref LPSPI_DisableIrq
 ******************************************************************************/
#define LPSPI_EnableIrq(module,mask) do{ module->IER |= (mask); }while(0)

/***************************************************************************//*!
 * @brief   Disable interrupt request.
 * @details Disables interrupt request for source given by argument.
 * @param   module   One of @ref lpspi_modules.
 * @param   mask     @ref lpspi_irq_sources.
 * @note    Implemented as a macro.
 * @see     @ref LPSPI_EnableIrq
 ******************************************************************************/
#define LPSPI_DisableIrq(module,mask) do{ module->IER &= (~(mask)); }while(0)

/***************************************************************************//*!
 * @brief   Enable DMA request.
 * @details Enables DMA request for source given by argument.
 * @param   module   One of @ref lpspi_modules.
 * @param   mask     @ref lpspi_dma.
 * @note    Implemented as a macro.
 * @see     @ref LPSPI_DisableDma
 ******************************************************************************/
#define LPSPI_EnableDma(module,mask) do{ module->DER |= (mask); }while(0)

/***************************************************************************//*!
 * @brief   Diasable DMA request.
 * @details Diasables DMA request for source given by argument.
 * @param   module   One of @ref lpspi_modules.
 * @param   mask     @ref lpspi_dma.
 * @note    Implemented as a macro.
 * @see     @ref LPSPI_EnableDma
 ******************************************************************************/
#define LPSPI_DisableDma(module,mask) do{ module->DER &= (~(mask)); }while(0)

/***************************************************************************//*!
 * @brief   Reset Transmit FIFO.
 * @details This macro resets Transmit FIFO
 * @param   module   One of @ref lpspi_modules.
 * @note    Implemented as a macro.
 * @see     @ref LPSPI_ResetRxFifo
 ******************************************************************************/
#define LPSPI_ResetTxFifo(module) do{ module->CR |= LPSPI_CR_RTF_MASK; }while(0)

/***************************************************************************//*!
 * @brief   Reset Receive FIFO.
 * @details This macro resets Receive FIFO
 * @param   module   One of @ref lpspi_modules.
 * @note    Implemented as a macro.
 * @see     @ref LPSPI_ResetTxFifo
 ******************************************************************************/
#define LPSPI_ResetRxFifo(module) do{ module->CR |= LPSPI_CR_RRF_MASK; }while(0)

/***************************************************************************//*!
 * @brief   Software Reset of LPSPI module.
 * @details This macro resets all internal logic and registers, except the
 *          Control Register. RST remains set until cleared bysoftware.
 * @param   module   One of @ref lpspi_modules.
 * @note    Implemented as a macro.
 * @see     @ref LPSPI_ResetTxFifo
 ******************************************************************************/
#define LPSPI_ResetModule(module) do{ module->CR |= LPSPI_CR_RST_MASK; }while(0)

/***************************************************************************//*!
 * @brief   Enable LPSPI module.
 * @details This macro enables LPSPI module.
 * @param   module   One of @ref lpspi_modules.
 * @note    Implemented as a macro.
 * @see     @ref LPSPI_Disable
 ******************************************************************************/
#define LPSPI_Enable(module) do{ module->CR |= LPSPI_CR_MEN_MASK; }while(0)

/***************************************************************************//*!
 * @brief   Disable LPSPI module.
 * @details This macro disables LPSPI module.
 * @param   module   One of @ref lpspi_modules.
 * @note    Implemented as a macro.
 * @see     @ref LPSPI_Enable
 ******************************************************************************/
#define LPSPI_Disable(module) do{ module->CR &= (~(LPSPI_CR_MEN_MASK)); }while(0)

/***************************************************************************//*!
 * @brief   Returns receiver FIFO Count.
 * @details This macro returns the number of words currently stored in the receive FIFO.
 * @param   module   One of @ref lpspi_modules.
 * @return  number of words [0..7].
 * @note    Implemented as a macro.
 * @see     @ref LPSPI_GetTxFifoCount @ref LPSPI_SetRxWaterMark
 ******************************************************************************/
#define LPSPI_GetRxFifoCount(module) \
  ((module->FSR & LPSPI_FSR_RXCOUNT_MASK)>>LPSPI_FSR_RXCOUNT_SHIFT)

/***************************************************************************//*!
 * @brief   Returns transmitter FIFO Count.
 * @details This macro returns the number of words currently stored in the transmit FIFO.
 * @param   module   One of @ref lpspi_modules.
 * @return  number of words [0..7].
 * @note    Implemented as a macro.
 * @see     @ref LPSPI_GetRxFifoCount @ref LPSPI_SetTxWaterMark
 ******************************************************************************/
#define LPSPI_GetTxFifoCount(module) \
  ((module->FSR & LPSPI_FSR_TXCOUNT_MASK)>>LPSPI_FSR_TXCOUNT_SHIFT)

/***************************************************************************//*!
 * @brief   Set receiver FIFO watermark.
 * @details This macro sets receiver FIFO watermark.
 * @param   module   One of @ref lpspi_modules.
 * @param   count    Watermark number of words [0..7].
 * @note    Implemented as a macro.
 * @see     @ref LPSPI_GetRxFifoCount @ref LPSPI_SetTxWaterMark
 ******************************************************************************/
#define LPSPI_SetRxWaterMark(module,count) \
  do{ module->FCR |= LPSPI_FCR_RXWATER(count); }while(0)

/***************************************************************************//*!
 * @brief   Set transmitter FIFO watermark.
 * @details This macro sets transmitter FIFO watermark.
 * @param   module   One of @ref lpspi_modules.
 * @param   count    Watermark number of words [0..7].
 * @note    Implemented as a macro.
 * @see     @ref LPSPI_GetTxFifoCount @ref LPSPI_SetRxWaterMark
 ******************************************************************************/
#define LPSPI_SetTxWaterMark(module,count) \
  do{ module->FCR |= LPSPI_FCR_TXWATER(count); }while(0)

/***************************************************************************//*!
 * @brief   Get received data.
 * @details This macro gets received data (from Receive Data Register).
 * @param   module   One of @ref lpspi_modules.
 * @return  @ref uint32_t data.
 * @note    Implemented as a macro.
 * @see     @ref LPSPI_GetRxStat @ref LPSPI_SendData
 ******************************************************************************/
#define LPSPI_GetData(module) module->RDR

/***************************************************************************//*!
 * @brief   Get receive status.
 * @details This macro gets receive status.
 * @param   module   One of @ref lpspi_modules.
 * @return  Mask of @ref lpspi_rx_stat.
 * @note    Implemented as a macro.
 * @see     @ref LPSPI_GetData
 ******************************************************************************/
#define LPSPI_GetRxStat(module) module->RSR

/***************************************************************************//*!
 * @brief   Send data.
 * @details This macro sends data (Writes to the Transmit Data Register).
 * @param   module   One of @ref lpspi_modules.
 * @param   data     @ref uint32_t data.
 * @note    Implemented as a macro.
 * @see     @ref LPSPI_SetXfrCmd @ref LPSPI_GetData
 ******************************************************************************/
#define LPSPI_SendData(module,data) do{ module->TDR = data; }while(0)

/***************************************************************************//*!
 * @brief   Set transfer command.
 * @details This macro sets transfer commad given by mask.
 * @param   module   One of @ref lpspi_modules.
 * @param   mask     Mask of bit settings see @ref lpspi_cmd_setting.
 * @param   frsize   Configures the frame size in number of bits equal to (frsize + 1) .
 * @param   width    Transfer width. @ref lpspi_width
 * @param   chipsel  Peripheral Chip Select 0-7
 * @param   presc    Prescaler Value @ref lpspi_div
 * @note    Implemented as a macro.
 * @see     @ref LPSPI_SendData
 ******************************************************************************/
#define LPSPI_SetXfrCmd(module,mask,frsize,width,chipsel,presc)          \
do{                                                                      \
  module->TCR = (mask)|LPSPI_TCR_FRAMESZ(frsize)|LPSPI_TCR_WIDTH(width)| \
                       LPSPI_TCR_PCS(chipsel)|LPSPI_TCR_PRESCALE(presc); \
}while(0)                                                                \

/***************************************************************************//*!
 * @brief   LPSPI module date ready.
 * @details This macro returns information whether data has been received.
 * @param   module  One of @ref lpspi_modules.
 * @return  false - Receive Data is not ready, true - Receive data is ready .
 * @note    Implemented as a macro.
 * @see     @ref LPSPI_TxReady
 ******************************************************************************/
#define LPSPI_DataReady(module) ((module->SR & LPSPI_SR_RDF_MASK)>>LPSPI_SR_RDF_SHIFT)

/***************************************************************************//*!
 * @brief   LPSPI module ready for transmit.
 * @details This macro returns information whether transmitter is ready for sending data.
 * @param   module  One of @ref lpspi_modules.
 * @return  false - Transmit data not requested, true - Transmit data requested.
 * @note    Implemented as a macro.
 * @see     @ref LPSPI_DataReady
 ******************************************************************************/
#define LPSPI_TxReady(module) ((module->SR & LPSPI_SR_TDF_MASK)>>LPSPI_SR_TDF_SHIFT)

/***************************************************************************//*!
 * @brief   LPSPI initialization.
 * @details This function initializes selected Low Power Serial Peripheral Interface (LPSPI).
 * @param   module   One of @ref lpspi_modules.
 * @param   cfg      Select one of the @ref lpspi_config.
 * @note    Implemented as a function call.
 * @see     @ref LPSPI_InstallCallback
 ******************************************************************************/
#define LPSPI_Init(module,cfg) LPSPI_prvInit(module,cfg)

/***************************************************************************//*!
 * @brief   Installs callback function for interrupt vector depended on LPSPI module.
 * @details This function install callback function for interrupt vector depended
 *          on LPSPI modul.
 * @param   module One of @ref lpspi_modules.
 * @param   ip     Priority to set. This device supports 16 priority levels for
 *                 interrupts.
 * @param   callback  Pointer to the @ref tLPSPI_CALLBACK.
 * @note    Implemented as a function call.
 * @see     @ref LPSPI_Init, @ref LPSPI_EnableIrq
 ******************************************************************************/
#define LPSPI_InstallCallback(module,ip,callback) module##_InstallCallback (ip,callback)
/*! @} End of lpspi_macro*/

/******************************************************************************
 * public function prototypes                                                 *
 ******************************************************************************/
void LPSPI_prvInit (volatile LPSPI_Type *module, tLPSPI cfg);

void LPSPI0_InstallCallback (uint8_t ip, tLPSPI_CALLBACK pCallback);
void LPSPI1_InstallCallback (uint8_t ip, tLPSPI_CALLBACK pCallback);
void LPSPI2_InstallCallback (uint8_t ip, tLPSPI_CALLBACK pCallback);
void LPSPI3_InstallCallback (uint8_t ip, tLPSPI_CALLBACK pCallback);
void LPSPI4_InstallCallback (uint8_t ip, tLPSPI_CALLBACK pCallback);
void LPSPI5_InstallCallback (uint8_t ip, tLPSPI_CALLBACK pCallback);

/******************************************************************************
 * interrupt handler prototypes                                               *
 ******************************************************************************/
void LPSPI0_Handler (void);
void LPSPI1_Handler (void);
void LPSPI2_Handler (void);
void LPSPI3_Handler (void);
void LPSPI4_Handler (void);
void LPSPI5_Handler (void);

#endif /* DRIVERS_LPSPI_LPSPI_H_ */
