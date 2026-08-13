#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/api_error.h"
#include "../model/api_not_found_error.h"
#include "../model/create_hook_body.h"
#include "../model/hook.h"
#include "../model/hook_list.h"
#include "../model/update_hook_body.h"
#include "../model/user_error.h"


// Clear Hooks on an instance
//
void
HypervisorHooksAPI_v3ClearHyperTraceHooks(apiClient_t *apiClient, char *instanceId);


// Create a hypervisor hook for an instance
//
// Creates a new hypervisor hook for the given instance.
//
hook_t*
HypervisorHooksAPI_v3CreateHook(apiClient_t *apiClient, char *instanceId, create_hook_body_t *create_hook_body);


// Delete a hypervisor hook
//
// Deletes the hypervisor hook identified by the given hookId.
//
void
HypervisorHooksAPI_v3DeleteHook(apiClient_t *apiClient, char *hookId);


// Execute Hooks on an instance
//
void
HypervisorHooksAPI_v3ExecuteHyperTraceHooks(apiClient_t *apiClient, char *instanceId);


// Get a hypervisor hook by ID
//
// Returns the hypervisor hook identified by the given hookId.
//
hook_t*
HypervisorHooksAPI_v3GetHook(apiClient_t *apiClient, char *hookId);


// List hypervisor hooks for an instance
//
// Returns a paginated list of hypervisor hooks configured for the given instance.
//
hook_list_t*
HypervisorHooksAPI_v3ListHooks(apiClient_t *apiClient, char *instanceId, double *limit, double *offset, char *sort);


// Update a hypervisor hook
//
// Updates the hypervisor hook identified by the given hookId.
//
hook_t*
HypervisorHooksAPI_v3UpdateHook(apiClient_t *apiClient, char *hookId, update_hook_body_t *update_hook_body);


