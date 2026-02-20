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

#include "lpspi.h"


/******************************************************************************
 * data type definitions                                                      *
 ******************************************************************************/
static tLPSPI_CALLBACK pCallbackLPSPI[LPSPI_INSTANCE_COUNT];

/******************************************************************************
 * public function definitions                                                *
 ******************************************************************************/
void LPSPI_prvInit (volatile LPSPI_Type *module,tLPSPI cfg)
{
  module->CR =(uint32_t)0x0u;
  module->CFGR0 = cfg.CFGR0;
  module->CFGR1 = cfg.CFGR1;
  module->DMR0  = cfg.DMR0;
  module->DMR1  = cfg.DMR1;
  module->CCR   = cfg.CCR;
  module->FCR   = cfg.FCR;
  module->CR    = cfg.CR;
  module->TCR   = cfg.TCR;
}

void LPSPI0_InstallCallback (uint8_t ip, tLPSPI_CALLBACK pCallback)
{
  pCallbackLPSPI[0] = pCallback;
//  NVIC_SetPriority (LPSPI0_IRQn, ip);
//  NVIC_EnableIRQ (LPSPI0_IRQn);
}

#if defined(LPSPI1)
void LPSPI1_InstallCallback (uint8_t ip, tLPSPI_CALLBACK pCallback)
{
  pCallbackLPSPI[1] = pCallback;
  NVIC_SetPriority (LPSPI1_IRQn, ip);
  NVIC_EnableIRQ (LPSPI1_IRQn);
}
#endif

#if defined(LPSPI2)
void LPSPI2_InstallCallback (uint8_t ip, tLPSPI_CALLBACK pCallback)
{
  pCallbackLPSPI[2] = pCallback;
  NVIC_SetPriority (LPSPI2_IRQn, ip);
  NVIC_EnableIRQ (LPSPI2_IRQn);
}
#endif

#if defined(LPSPI3)
void LPSPI3_InstallCallback (uint8_t ip, tLPSPI_CALLBACK pCallback)
{
  pCallbackLPSPI[3] = pCallback;
  NVIC_SetPriority (LPSPI3_IRQn, ip);
  NVIC_EnableIRQ (LPSPI3_IRQn);
}
#endif

#if defined(LPSPI4)
void LPSPI4_InstallCallback (uint8_t ip, tLPSPI_CALLBACK pCallback)
{
  pCallbackLPSPI[4] = pCallback;
  NVIC_SetPriority (LPSPI4_IRQn, ip);
  NVIC_EnableIRQ (LPSPI4_IRQn);
}
#endif

#if defined(LPSPI5)
void LPSPI5_InstallCallback (uint8_t ip, tLPSPI_CALLBACK pCallback)
{
  pCallbackLPSPI[5] = pCallback;
  NVIC_SetPriority (LPSPI5_IRQn, ip);
  NVIC_EnableIRQ (LPSPI5_IRQn);
}
#endif

/******************************************************************************
 * interrupt function definitions                                             *
 ******************************************************************************/
void LPSPI0_Handler (void)
{
  pCallbackLPSPI[0](LPSPI0,(tLPSPI_CALLBACK_TYPE)LPSPI_GetClrIrqFlags(LPSPI0));
}

#if defined(LPSPI1)
void LPSPI1_Handler (void)
{
  pCallbackLPSPI[1](LPSPI1,(tLPSPI_CALLBACK_TYPE)LPSPI_GetClrIrqFlags(LPSPI1));
}
#endif

#if defined(LPSPI2)
void LPSPI2_Handler (void)
{
  pCallbackLPSPI[2](LPSPI2,(tLPSPI_CALLBACK_TYPE)LPSPI_GetClrIrqFlags(LPSPI2));
}
#endif

#if defined(LPSPI3)
void LPSPI3_Handler (void)
{
  pCallbackLPSPI[3](LPSPI3,(tLPSPI_CALLBACK_TYPE)LPSPI_GetClrIrqFlags(LPSPI3));
}
#endif

#if defined(LPSPI4)
void LPSPI4_Handler (void)
{
  pCallbackLPSPI[4](LPSPI4,(tLPSPI_CALLBACK_TYPE)LPSPI_GetClrIrqFlags(LPSPI4)); }
#endif


#if defined(LPSPI5)
void LPSPI5_Handler (void)
{
  pCallbackLPSPI[5](LPSPI5,(tLPSPI_CALLBACK_TYPE)LPSPI_GetClrIrqFlags(LPSPI5));
}
#endif
/******************************************************************************
 * End of module                                                              *
 ******************************************************************************/
