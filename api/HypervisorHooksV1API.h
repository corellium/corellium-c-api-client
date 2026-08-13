#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/api_error_v1.h"
#include "../model/hook_v1.h"
#include "../model/user_error_v1.h"
#include "../model/v1_create_hook_parameters.h"
#include "../model/v1_update_hook_parameters.h"


// Clear Hooks on an instance
//
void
HypervisorHooksV1API_v1ClearHyperTraceHooks(apiClient_t *apiClient, char *instanceId);


// Create hypervisor hook for Instance
//
hook_v1_t*
HypervisorHooksV1API_v1CreateHook(apiClient_t *apiClient, char *instanceId, v1_create_hook_parameters_t *v1_create_hook_parameters);


// Delete an existing hypervisor hook
//
void
HypervisorHooksV1API_v1DeleteHook(apiClient_t *apiClient, char *hookId);


// Execute Hooks on an instance
//
void
HypervisorHooksV1API_v1ExecuteHyperTraceHooks(apiClient_t *apiClient, char *instanceId);


// Get hypervisor hook by id
//
hook_v1_t*
HypervisorHooksV1API_v1GetHookById(apiClient_t *apiClient, char *hookId);


// Get all hypervisor hooks for Instance
//
list_t*
HypervisorHooksV1API_v1GetHooks(apiClient_t *apiClient, char *instanceId, double limit, double offset, char *sort);


// Update an existing hypervisor hook
//
hook_v1_t*
HypervisorHooksV1API_v1UpdateHook(apiClient_t *apiClient, char *hookId, v1_update_hook_parameters_t *v1_update_hook_parameters);


