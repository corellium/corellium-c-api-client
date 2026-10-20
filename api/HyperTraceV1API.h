#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/api_error_v1.h"
#include "../model/btrace_enable_options.h"
#include "../model/kcrange_v1.h"
#include "../model/token_v1.h"
#include "../model/user_error_v1.h"


// Pre-authorize an btrace download
//
token_v1_t*
HyperTraceV1API_v1BtracePreauthorize(apiClient_t *apiClient, char *instanceId);


// Clear HyperTrace logs
//
void
HyperTraceV1API_v1ClearHyperTrace(apiClient_t *apiClient, char *instanceId);


// Get Kernel extension ranges
//
list_t*
HyperTraceV1API_v1Kcrange(apiClient_t *apiClient, char *instanceId);


// Start HyperTrace on an instance
//
void
HyperTraceV1API_v1StartHyperTrace(apiClient_t *apiClient, char *instanceId, btrace_enable_options_t *btrace_enable_options);


// Stop HyperTrace on an instance.
//
void
HyperTraceV1API_v1StopHyperTrace(apiClient_t *apiClient, char *instanceId);


