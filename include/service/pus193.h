/**
 * @file    pus193.h
 * @author  Yann Awbi
 * @author  Merlin Kooshmanian
 * @brief   Header file for PUS 193 (Iridium) functions
 *
 * @copyright Copyright (c) TOLOSAT 2026
 */

#ifndef PUS193_H
#define PUS193_H

/******************************* Include Files *******************************/

#include "pus_types.h"
#include "drivers/iridium9603.h"

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

/**
 * @fn              ExecuteS193SS1(void *env, pusTC_t *tc, pusTM_t *tm, pusExecutionError_t *error_code)
 * @brief           Function that initialises the Iridium transceiver after receiving a S193SS1 TC
 * @param[in,out]   env PUS191 environment
 * @param[in]       tc S191SS1 TC that initialises the Iridium transceiver
 * @param[out]      tm Not used here
 * @param[out]      error_code Indicates which error has been encountered
 * @retval          #RET_ERROR if cannot build TM
 * @retval          #RET_INVALID_PARAM if a pointer is NULL
 * @retval          #RET_SUCCESSFUL else
 */
extern returnCode_t ExecuteS193SS1(void *env, pusTC_t *tc, pusTM_t *tm, pusExecutionError_t *error_code);

/**
 * @fn              ExecuteS193SS2(void *env, pusTC_t *tc, pusTM_t *tm, pusExecutionError_t *error_code)
 * @brief           Function that stops the Iridium transceiver after receiving a S193SS2 TC
 * @param[in,out]   env PUS191 environment
 * @param[in]       tc S161SS2 TC that requests the stop of the transciever
 * @param[out]      tm Not used here
 * @param[out]      error_code Indicates which error has been encountered
 * @retval          #RET_ERROR if cannot build TM
 * @retval          #RET_INVALID_PARAM if a pointer is NULL
 * @retval          #RET_SUCCESSFUL else
 */
extern returnCode_t ExecuteS193SS2(void *env, pusTC_t *tc, pusTM_t *tm, pusExecutionError_t *error_code);

/**
 * @fn              ExecuteS193SS3(void *env, pusTC_t *tc, pusTM_t *tm, pusExecutionError_t *error_code)
 * @brief           Function that send S193SS4 TM (Iridium Network Status) when requested by a S193SS3
 * @param[in,out]   env PUS191 environment
 * @param[in]       tc S161SS3 TC that requests this TM
 * @param[out]      tm S161SS4 TM that we will send
 * @param[out]      error_code Indicates which error has been encountered
 * @retval          #RET_ERROR if cannot build TM
 * @retval          #RET_INVALID_PARAM if a pointer is NULL
 * @retval          #RET_SUCCESSFUL else
 */
extern returnCode_t ExecuteS193SS3(void *env, pusTC_t *tc, pusTM_t *tm, pusExecutionError_t *error_code);

/**
 * @fn              ExecuteS193SS5(void *env, pusTC_t *tc, pusTM_t *tm, pusExecutionError_t *error_code)
 * @brief           Function that send S193SS6 TM (Iridium SBD status) when requested by a S193SS5
 * @param[in,out]   env PUS191 environment
 * @param[in]       tc S161SS5 TC that requests this TM
 * @param[out]      tm S161SS6 TM that we will send
 * @param[out]      error_code Indicates which error has been encountered
 * @retval          #RET_ERROR if cannot build TM
 * @retval          #RET_INVALID_PARAM if a pointer is NULL
 * @retval          #RET_SUCCESSFUL else
 */
extern returnCode_t ExecuteS193SS5(void *env, pusTC_t *tc, pusTM_t *tm, pusExecutionError_t *error_code);

/**
 * @fn              ExecuteS193SS7(void *env, pusTC_t *tc, pusTM_t *tm, pusExecutionError_t *error_code)
 * @brief           Function that send a SBD when receiving a S161SS5
 * @param[in,out]   env PUS191 environment
 * @param[in]       tc S193SS7 TC that request to send an SBD message and include the message to send
 * @param[out]      tm Not used here
 * @param[out]      error_code Indicates which error has been encountered
 * @retval          #RET_ERROR if cannot build TM
 * @retval          #RET_INVALID_PARAM if a pointer is NULL
 * @retval          #RET_SUCCESSFUL else
 */
extern returnCode_t ExecuteS193SS7(void *env, pusTC_t *tc, pusTM_t *tm, pusExecutionError_t *error_code);

/**
 * @fn              ExecuteS193SS8(void *env, pusTC_t *tc, pusTM_t *tm, pusExecutionError_t *error_code)
 * @brief           Function that send a S193SS9 TM (SBD message) when receiving a S161SS8
 * @param[in,out]   env PUS191 environment
 * @param[in]       tc S193SS8 TC that request to receive an SBD message
 * @param[out]      tm S191SS9 TM containing the SBD message
 * @param[out]      error_code Indicates which error has been encountered
 * @retval          #RET_ERROR if cannot build TM
 * @retval          #RET_INVALID_PARAM if a pointer is NULL
 * @retval          #RET_SUCCESSFUL else
 */
extern returnCode_t ExecuteS193SS8(void *env, pusTC_t *tc, pusTM_t *tm, pusExecutionError_t *error_code);

#endif /* PUS193_H */