/*
 * Copyright (c) 2014, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#if !defined(__FSL_MCGLITE_HAL_MODES_H__)
#define __FSL_MCGLITE_HAL_MODES_H__

#include <stdint.h>
#include <stdbool.h>
#include "fsl_mcglite_hal.h"

/*! @addtogroup mcglite_hal*/
/*! @{*/

/*! @file fsl_mcg_lite_hal_modes.h */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @brief MCG_Lite clock mode definitions */
typedef enum _mcglite_mode
{
    kMcgliteModeHirc48M,                     /* clock mode is HIRC 48M*/
    kMcgliteModeLirc8M,                      /* clock mode is LIRC 8M  */
    kMcgliteModeLirc2M,                      /* clock mode is LIRC 2M  */
    kMcgliteModeExt,                         /* clock mode is EXT  */
    kMcgliteModeStop,                        /* clock mode is STOP  */
    kMcgliteModeError                        /* Unknown mode */
} mcglite_mode_t;

/*! @brief MCG_Lite mode transition API error code definitions */
typedef enum McgliteModeErrorCode {
    /* MCG_Lite mode error codes */
    kMcgliteModeErrNone = 0x00,    /* - No error */
    kMcgliteModeErrExt  = 0x01,    /* - External clock source not available. */
} mcglite_mode_error_t;

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus*/

/*! @name MCG_Lite clock mode API */
/*@{*/

/*!
 * @brief Gets the current MCG_Lite clock mode.
 *
 * This is an internal function that checks the MCG registers and determine
 * the current MCG_lite mode.
 *
 * @param baseAddr MCG_Lite register base address.
 *
 * @return Current MCG_Lite mode or error code.
 */
mcglite_mode_t CLOCK_HAL_GetMode(uint32_t baseAddr);

/*!
 * @brief Sets the MCG_Lite to HIRC mode.
 *
 * This is an internal function that changes MCG_Lite
 * to HRIC mode.
 *
 * @param baseAddr MCG_Lite register base address.
 * @param outclkfreq MCGOUTCLK frequency in new mode.
 *
 * @return Error code.
 */
mcglite_mode_error_t CLOCK_HAL_SetHircMode(uint32_t baseAddr, uint32_t *outClkFreq);

/*!
 * @brief Sets the MCG_Lite to LIRC mode.
 *
 * This is an internal function that changes MCG_Lite
 * to LIRC mode.
 *
 * @param baseAddr MCG_Lite register base address.
 * @param lirc     Set to LIRC2M or LIRC8M.
 * @param div1     The FCRDIV setting.
 * @param outclkfreq MCGOUTCLK frequency in new mode.
 *
 * @return Error code.
 */
mcglite_mode_error_t CLOCK_HAL_SetLircMode(uint32_t baseAddr,
                               mcglite_lirc_select_t lirc,
                               mcglite_lirc_div_t div1,
                               uint32_t *outClkFreq);

/*!
 * @brief Sets the MCG_Lite to EXT mode.
 *
 * This is an internal function that changes MCG_Lite
 * to EXT mode. Before this function, please make sure
 * the OSC or external clock source is ready.
 *
 * @param baseAddr MCG_Lite register base address.
 * @param outclkfreq MCGOUTCLK frequency in new mode.
 *
 * @return Error code.
 */
mcglite_mode_error_t CLOCK_HAL_SetExtMode(uint32_t baseAddr, uint32_t *outClkFreq);

/*! @}*/

#if defined(__cplusplus)
}
#endif /* __cplusplus*/

/*! @}*/

#endif /* __FSL_MCGLITE_HAL_MODES_H__*/
/*******************************************************************************
 * EOF
 ******************************************************************************/

