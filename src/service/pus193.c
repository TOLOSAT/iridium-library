/**
 * @file    pus193.c
 * @author  Yann Awbi
 * @author  Merlin Kooshmanian
 * @brief   Source file for PUS 193 (Iridium) functions
 *
 * @copyright Copyright (c) TOLOSAT 2025
 */

/******************************* Include Files *******************************/

#include <string.h>

#include "kernel.h"
#include "tm_management.h"
#include "service/pus193.h"

/***************************** Macros Definitions ****************************/

/*************************** Functions Declarations **************************/

/*************************** Variables Definitions ***************************/

/*************************** Functions Definitions ***************************/

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
returnCode_t ExecuteS193SS1(void *env, pusTC_t *tc, pusTM_t *tm, pusExecutionError_t *error_code)
{
    returnCode_t return_value = RET_SUCCESSFUL;

    // Unused
    (void)(tc);
    (void)(tm);

    // Check parameter(s)
    if ((env != NULL) && (error_code != NULL))
    {
        pusS193Env_t *pus_193_env = (pusS193Env_t *)env;
        if (pus_193_env->p_iridium_inst != NULL)
        {
            // Error code Initialization
            *error_code = PUS_EXECUTION_NO_ERROR;

            // Start Iridium Iridium Driver
            return_value = IridiumStart(pus_193_env->p_iridium_inst);
            if (return_value != RET_SUCCESSFUL)
            {
                *error_code = PUS_EXECUTION_FAILED;
            }
        }
        else
        {
            return_value = RET_INVALID_PARAM;
        }
    }
    else
    {
        return_value = RET_INVALID_PARAM;
    }

    return return_value;
}

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
returnCode_t ExecuteS193SS2(void *env, pusTC_t *tc, pusTM_t *tm, pusExecutionError_t *error_code)
{
    returnCode_t return_value = RET_SUCCESSFUL;

    // Unused
    (void)(env);
    (void)(tc);
    (void)(tm);

    // Check parameter(s)
    if ((env != NULL) && (error_code != NULL))
    {
        pusS193Env_t *pus_193_env = (pusS193Env_t *)env;
        if (pus_193_env->p_iridium_inst != NULL)
        {
            // Error code Initialization
            *error_code = PUS_EXECUTION_NO_ERROR;

            // Start Iridium Iridium Driver
            return_value = IridiumStop(pus_193_env->p_iridium_inst);
            if (return_value != RET_SUCCESSFUL)
            {
                *error_code = PUS_EXECUTION_FAILED;
            }
        }
        else
        {
            return_value = RET_INVALID_PARAM;
        }
    }
    else
    {
        return_value = RET_INVALID_PARAM;
    }

    return return_value;
}

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
returnCode_t ExecuteS193SS3(void *env, pusTC_t *tc, pusTM_t *tm, pusExecutionError_t *error_code)
{
    returnCode_t return_value = RET_SUCCESSFUL;

    // Unused
    (void)(env);
    (void)(tc);

    // Check parameter(s)
    if ((env != NULL) && (error_code != NULL))
    {
        // Get PUS 193 environment
        pusS193Env_t *pus_193_env = (pusS193Env_t *)env;
        if (pus_193_env->p_iridium_inst != NULL)
        {
            uint8_t network_availability = 0u; // Use a uint8_t for network availability to ensure having a constant size

            // Error code Initialization
            *error_code = PUS_EXECUTION_NO_ERROR;

            // GetStatus
            return_value = IridiumGetNetworkAvailability(pus_193_env->p_iridium_inst, &network_availability);
            if (return_value == RET_SUCCESSFUL)
            {
                return_value = BuildTM(tm, 193u, 4u, (data_t)&network_availability, sizeof(uint8_t));
                if (return_value != RET_SUCCESSFUL)
                {
                    *error_code = PUS_EXECUTION_FAILED;
                }
            }
            else
            {
                *error_code = PUS_EXECUTION_FAILED;
            }
        }
        else
        {
            return_value = RET_INVALID_PARAM;
        }
    }
    else
    {
        return_value = RET_INVALID_PARAM;
    }

    return return_value;
}

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
returnCode_t ExecuteS193SS5(void *env, pusTC_t *tc, pusTM_t *tm, pusExecutionError_t *error_code)
{
    returnCode_t return_value = RET_SUCCESSFUL;

    // Unused
    (void)(env);
    (void)(tc);

    // Check parameter(s)
    if ((env != NULL) && (error_code != NULL))
    {
        // Get PUS 193 environment
        pusS193Env_t *pus_193_env = (pusS193Env_t *)env;
        if (pus_193_env->p_iridium_inst != NULL)
        {
            iridiumSBDStatus_t status = { 0 };

            // Error code Initialization
            *error_code = PUS_EXECUTION_NO_ERROR;

            // GetStatus
            return_value = IridiumGetSBDStatus(pus_193_env->p_iridium_inst, &status);
            if (return_value == RET_SUCCESSFUL)
            {
                return_value = BuildTM(tm, 193u, 6u, (data_t)&status, sizeof(iridiumSBDStatus_t));
                if (return_value != RET_SUCCESSFUL)
                {
                    *error_code = PUS_EXECUTION_FAILED;
                }
            }
            else
            {
                *error_code = PUS_EXECUTION_FAILED;
            }
        }
        else
        {
            return_value = RET_INVALID_PARAM;
        }
    }
    else
    {
        return_value = RET_INVALID_PARAM;
    }

    return return_value;
}

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
returnCode_t ExecuteS193SS7(void *env, pusTC_t *tc, pusTM_t *tm, pusExecutionError_t *error_code)
{
    returnCode_t return_value = RET_SUCCESSFUL;

    // Unused
    (void)(env);
    (void)(tm);

    // Check parameter(s)
    if ((env != NULL) && (error_code != NULL))
    {
        // Get PUS 193 environment
        pusS193Env_t *pus_193_env = (pusS193Env_t *)env;
        if (pus_193_env->p_iridium_inst != NULL)
        {
            iridiumSBDTxMsg_t tx_msg = { 0 };
            uint16_t msg_size        = 0u;

            // Error code Initialization
            *error_code = PUS_EXECUTION_NO_ERROR;

            // Get message size
            msg_size = tc->spp_header.packet_data_length + 1u - TC_HEADER_SIZE - CRC_TRAILER_SIZE;

            // Get tx_message from tc
            (void)memcpy(tx_msg, tc->data, msg_size);

            // Send the message
            return_value = IridiumSendSBD(pus_193_env->p_iridium_inst, &tx_msg);
            if (return_value != RET_SUCCESSFUL)
            {
                *error_code = PUS_EXECUTION_FAILED;
            }
        }
        else
        {
            return_value = RET_INVALID_PARAM;
        }
    }
    else
    {
        return_value = RET_INVALID_PARAM;
    }

    return return_value;
}

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
returnCode_t ExecuteS193SS8(void *env, pusTC_t *tc, pusTM_t *tm, pusExecutionError_t *error_code)
{
    returnCode_t return_value = RET_SUCCESSFUL;

    // Unused
    (void)(env);
    (void)(tc);

    // Check parameter(s)
    if ((env != NULL) && (error_code != NULL))
    {
        // Get PUS 193 environment
        pusS193Env_t *pus_193_env = (pusS193Env_t *)env;
        if (pus_193_env->p_iridium_inst != NULL)
        {
            iridiumSBDRxMsg_t rx_msg = { 0 };

            // Error code Initialization
            *error_code = PUS_EXECUTION_NO_ERROR;

            // Send the message
            return_value = IridiumReceiveSBD(pus_193_env->p_iridium_inst, &rx_msg);
            if (return_value == RET_SUCCESSFUL)
            {
                return_value = BuildTM(tm, 193u, 6u, (data_t)&rx_msg, sizeof(iridiumSBDRxMsg_t));
                if (return_value != RET_SUCCESSFUL)
                {
                    *error_code = PUS_EXECUTION_FAILED;
                }
            }
            else
            {
                *error_code = PUS_EXECUTION_FAILED;
            }
        }
        else
        {
            return_value = RET_INVALID_PARAM;
        }
    }
    else
    {
        return_value = RET_INVALID_PARAM;
    }

    return return_value;
}
