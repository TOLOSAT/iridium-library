/**
 * @file    pus193.h
 * @author  Yann Awbi
 * @author  Merlin Kooshmanian
 * @brief   Header file for PUS 193 (Iridium) functions
 *
 * @copyright Copyright (c) TOLOSAT 2025
 */

#ifndef PUS193_H
#define PUS193_H

/******************************* Include Files *******************************/

#include "pus_types.h"
#include "drv/iridium_driver.h"

/***************************** Macros Definitions ****************************/

/***************************** Types Definitions *****************************/

/**
 * @struct  pus193Env_t
 * @brief   Struct type definition of a PUS193 (Iridium) environment instance
 */
typedef struct
{
    iridiumInst_t *p_iridium_inst; /**< Pointer to the Iridium instance */
} pus193Env_t;

/*************************** Variables Declarations **************************/

/*************************** Functions Declarations **************************/

extern returnCode_t ExecuteS193SS1(void *env, pusTC_t *tc, pusTM_t *tm, pusExecutionError_t *error_code);
extern returnCode_t ExecuteS193SS2(void *env, pusTC_t *tc, pusTM_t *tm, pusExecutionError_t *error_code);
extern returnCode_t ExecuteS193SS3(void *env, pusTC_t *tc, pusTM_t *tm, pusExecutionError_t *error_code);
extern returnCode_t ExecuteS193SS5(void *env, pusTC_t *tc, pusTM_t *tm, pusExecutionError_t *error_code);
extern returnCode_t ExecuteS193SS7(void *env, pusTC_t *tc, pusTM_t *tm, pusExecutionError_t *error_code);
extern returnCode_t ExecuteS193SS8(void *env, pusTC_t *tc, pusTM_t *tm, pusExecutionError_t *error_code);

#endif /* PUS193_H */