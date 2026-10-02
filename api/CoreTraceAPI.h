#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/api_error.h"
#include "../model/kernel_task.h"
#include "../model/token.h"
#include "../model/user_error_response.h"


// Clear CoreTrace output
//
// Deletes the CoreTrace (system call trace) output recorded so far on this device, so the next download contains only new activity. Tracing keeps running if it is on. Requires the CoreTrace license feature (403 otherwise). An unknown `instanceId` is a successful no-op that returns 204.
//
void
CoreTraceAPI_v3ClearCoreTrace(apiClient_t *apiClient, char *instanceId);


// List running processes (CoreTrace)
//
// Lists the processes running on the device with their threads, including each process's `processId` and name and each thread's `taskId`. Use it to pick which processes to trace with CoreTrace (set `straceFilter` on `v3PatchInstance`). The device must be running.
//
list_t*
CoreTraceAPI_v3ListThreads(apiClient_t *apiClient, char *instanceId);


// Start CoreTrace
//
// Starts CoreTrace on a running device. CoreTrace records the system calls made by processes on the device, so you can see what an app does at the operating-system level (files opened, network connections, processes started).  **Workflow:** 1. `v3StartCoreTrace` (this call). 2. Use the device or app you want to observe. Optionally list running processes with `v3ListThreads`, and limit tracing to some of them with `straceFilter` on `v3PatchInstance`. 3. `v3StopCoreTrace`. 4. `v3StracePreauthorize` to get a download token, then download the trace. 5. `v3ClearCoreTrace` to discard it before the next run.  Returns 400 if this device does not support CoreTrace, and 403 if your license does not include it.
//
void
CoreTraceAPI_v3StartCoreTrace(apiClient_t *apiClient, char *instanceId);


// Stop CoreTrace
//
// Stops CoreTrace on this device. The trace recorded so far is kept, so you can download it with `v3StracePreauthorize`. Requires the CoreTrace license feature.
//
void
CoreTraceAPI_v3StopCoreTrace(apiClient_t *apiClient, char *instanceId);


// Get a CoreTrace download token
//
// Returns a short-lived token that authorizes downloading this device's CoreTrace output without an `Authorization` header. Download with `GET /v1/preauthed/{token}/{filename}`. The token works only for this device's trace and expires when your current session token expires.
//
token_t*
CoreTraceAPI_v3StracePreauthorize(apiClient_t *apiClient, char *instanceId);


