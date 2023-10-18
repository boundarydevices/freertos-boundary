/*
 * Copyright 2023 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _PIN_MUX_H_
#define _PIN_MUX_H_


/***********************************************************************************************************************
 * Definitions
 **********************************************************************************************************************/

/*!
 * @addtogroup pin_mux
 * @{
 */

/***********************************************************************************************************************
 * API
 **********************************************************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif


/*!
 * @brief Calls initialization functions.
 *
 */
void BOARD_InitBootPins(void);

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitDebugConsolePins(void);                     /*!< Function assigned for the core: Cortex-M33[cm33] */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitMipiPanelPins(void);                        /*!< Function assigned for the core: Cortex-M33[cm33] */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitPCA6414I2CPins(void);                       /*!< Function assigned for the core: Cortex-M33[cm33] */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitIt6161IntPins(void);                        /*!< Function assigned for the core: Cortex-M33[cm33] */

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */
#endif /* _PIN_MUX_H_ */

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
