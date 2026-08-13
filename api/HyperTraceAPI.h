#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/api_error.h"
#include "../model/enable_btrace_body.h"
#include "../model/kcrange.h"
#include "../model/token.h"
#include "../model/user_error.h"


// Pre-authorize a btrace download
//
token_t*
HyperTraceAPI_v3BtracePreauthorize(apiClient_t *apiClient, char *instanceId);


// Clear HyperTrace logs
//
void
HyperTraceAPI_v3ClearHyperTrace(apiClient_t *apiClient, char *instanceId);


// Get Kernel extension ranges
//
list_t*
HyperTraceAPI_v3GetInstanceKcrange(apiClient_t *apiClient, char *instanceId);


// Start HyperTrace on an instance
//
void
HyperTraceAPI_v3StartHyperTrace(apiClient_t *apiClient, char *instanceId, enable_btrace_body_t *enable_btrace_body);


// Stop HyperTrace on an instance.
//
void
HyperTraceAPI_v3StopHyperTrace(apiClient_t *apiClient, char *instanceId);


