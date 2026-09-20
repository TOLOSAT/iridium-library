/**
 * @file    pus193.c
 * @author  Yann Awbi
 * @author  Merlin Kooshmanian
 * @brief   Source file for PUS 193 (Iridium) functions
 *
 * @copyright Copyright (c) TOLOSAT 2026
 * SPDX-License-Identifier: Apache-2.0
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
 * @copydoc ExecuteS193SS1
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
        pus193Env_t *pus193_env = (pus193Env_t *)env;
        if (pus193_env->p_iridium_inst != NULL)
        {
            // Error code Initialization
            *error_code = PUS_EXECUTION_NO_ERROR;

            // Start Iridium Iridium Driver
            return_value = IridiumStart(pus193_env->p_iridium_inst);
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
 * @copydoc ExecuteS193SS2
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
        pus193Env_t *pus193_env = (pus193Env_t *)env;
        if (pus193_env->p_iridium_inst != NULL)
        {
            // Error code Initialization
            *error_code = PUS_EXECUTION_NO_ERROR;

            // Start Iridium Iridium Driver
            return_value = IridiumStop(pus193_env->p_iridium_inst);
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
 * @copydoc ExecuteS193SS3
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
        pus193Env_t *pus193_env = (pus193Env_t *)env;
        if (pus193_env->p_iridium_inst != NULL)
        {
            uint8_t network_availability = 0u; // Use a uint8_t for network availability to ensure having a constant size

            // Error code Initialization
            *error_code = PUS_EXECUTION_NO_ERROR;

            // GetStatus
            return_value = IridiumGetNetworkAvailability(pus193_env->p_iridium_inst, &network_availability);
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
 * @copydoc ExecuteS193SS5
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
        pus193Env_t *pus193_env = (pus193Env_t *)env;
        if (pus193_env->p_iridium_inst != NULL)
        {
            iridiumSBDStatus_t status = { 0 };

            // Error code Initialization
            *error_code = PUS_EXECUTION_NO_ERROR;

            // GetStatus
            return_value = IridiumGetSBDStatus(pus193_env->p_iridium_inst, &status);
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
 * @copydoc ExecuteS193SS7
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
        pus193Env_t *pus193_env = (pus193Env_t *)env;
        if (pus193_env->p_iridium_inst != NULL)
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
            return_value = IridiumSendSBD(pus193_env->p_iridium_inst, &tx_msg);
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
 * @copydoc ExecuteS193SS8
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
        pus193Env_t *pus193_env = (pus193Env_t *)env;
        if (pus193_env->p_iridium_inst != NULL)
        {
            iridiumSBDRxMsg_t rx_msg = { 0 };

            // Error code Initialization
            *error_code = PUS_EXECUTION_NO_ERROR;

            // Send the message
            return_value = IridiumReceiveSBD(pus193_env->p_iridium_inst, &rx_msg);
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
