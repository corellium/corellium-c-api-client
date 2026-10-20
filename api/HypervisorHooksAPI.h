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
#include "../model/user_error_response.h"


// Stop hypervisor hooks
//
// Deactivates the hypervisor hooks on this device, so they stop running. The hook definitions are kept and can be activated again with `v3ExecuteHyperTraceHooks`.
//
void
HypervisorHooksAPI_v3ClearHyperTraceHooks(apiClient_t *apiClient, char *instanceId);


// Create a hypervisor hook for an instance
//
// Adds a hypervisor hook to a device: the `patch` code runs each time the device executes `address`. Hooks are enabled by default. Activate the device's hooks with `POST /v3/instances/{instanceId}/hooks/execute` and deactivate them with `.../hooks/clear`. Returns 201 with the new hook.
//
hook_t*
HypervisorHooksAPI_v3CreateHook(apiClient_t *apiClient, char *instanceId, create_hook_body_t *create_hook_body);


// Delete a hypervisor hook
//
// Deletes a hypervisor hook from its device.  Deletes are idempotent: an unknown `hookId`, or a hook that was already deleted, is a successful no-op that still returns 204, and repeated calls return 204 as well. A 404 means the request path did not match a delete route, not that the target was missing.
//
void
HypervisorHooksAPI_v3DeleteHook(apiClient_t *apiClient, char *hookId);


// Run hypervisor hooks
//
// Activates the hypervisor hooks configured for this device. A hook is a small patch, written in a C-like (`csmfcc`) or assembly-like (`csmfvm`) language, that runs whenever the device executes a chosen memory address; create and manage hooks with the Hypervisor Hooks endpoints (`POST /v3/instances/{instanceId}/hooks`). Only hooks marked `enabled` run. Does nothing if no hooks are configured.
//
void
HypervisorHooksAPI_v3ExecuteHyperTraceHooks(apiClient_t *apiClient, char *instanceId);


// Get a hypervisor hook by ID
//
// Returns one hypervisor hook, including its address, patch code and whether it is enabled.
//
hook_t*
HypervisorHooksAPI_v3GetHook(apiClient_t *apiClient, char *hookId);


// List hypervisor hooks for an instance
//
// Lists the hypervisor hooks set up on a device. A hook is a small piece of code, written in a C-like or assembly-like language, that the hypervisor runs whenever the device executes a chosen memory address, without changing the software on the device. Use hooks to log values, change behavior, or bypass checks while testing. Results are paginated; `sort` orders them by creation date.
//
hook_list_t*
HypervisorHooksAPI_v3ListHooks(apiClient_t *apiClient, char *instanceId, double *limit, double *offset, char *sort);


// Update a hypervisor hook
//
// Changes a hypervisor hook. Send only the fields you want to change, for example `enabled: false` to switch it off without deleting it. Returns the updated hook.
//
hook_t*
HypervisorHooksAPI_v3UpdateHook(apiClient_t *apiClient, char *hookId, update_hook_body_t *update_hook_body);


