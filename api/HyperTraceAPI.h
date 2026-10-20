#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/api_error.h"
#include "../model/api_not_found_error.h"
#include "../model/enable_btrace_body.h"
#include "../model/kcrange.h"
#include "../model/token.h"
#include "../model/user_error_response.h"


// Get a HyperTrace download token
//
// Returns a short-lived token that authorizes downloading this device's HyperTrace output without an `Authorization` header. Download with `GET /v1/preauthed/{token}/{filename}`. The token works only for this device's trace and expires when your current session token expires.
//
token_t*
HyperTraceAPI_v3BtracePreauthorize(apiClient_t *apiClient, char *instanceId);


// Clear HyperTrace output
//
// Deletes the HyperTrace output recorded so far on this device. An unknown `instanceId` is a successful no-op that returns 204.
//
void
HyperTraceAPI_v3ClearHyperTrace(apiClient_t *apiClient, char *instanceId);


// List kernel extension address ranges
//
// Lists the kernel extensions loaded on the device with the memory address range each occupies. Pass a `range` to `v3StartHyperTrace` to trace code in just that extension. The device must be running.
//
list_t*
HyperTraceAPI_v3GetInstanceKcrange(apiClient_t *apiClient, char *instanceId);


// Start HyperTrace
//
// Starts HyperTrace on a running device. HyperTrace records which kernel code runs inside the address ranges you choose, without changing the device's software, so you can measure kernel code coverage.  **Workflow:** list kernel extensions with `v3GetInstanceKcrange`, start tracing with the `ranges` you want (this call), exercise the device, stop with `v3StopHyperTrace`, then download with `v3BtracePreauthorize`. Clear old output with `v3ClearHyperTrace`.
//
void
HyperTraceAPI_v3StartHyperTrace(apiClient_t *apiClient, char *instanceId, enable_btrace_body_t *enable_btrace_body);


// Stop HyperTrace
//
// Stops HyperTrace on this device. The trace recorded so far is kept for download with `v3BtracePreauthorize`.
//
void
HyperTraceAPI_v3StopHyperTrace(apiClient_t *apiClient, char *instanceId);


