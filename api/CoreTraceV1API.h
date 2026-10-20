#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/api_error_v1.h"
#include "../model/kernel_task_v1.h"
#include "../model/user_error_v1.h"


// Clear CoreTrace logs
//
void
CoreTraceV1API_v1ClearCoreTrace(apiClient_t *apiClient, char *instanceId);


// Get Running Threads (CoreTrace)
//
list_t*
CoreTraceV1API_v1ListThreads(apiClient_t *apiClient, char *instanceId);


// Start CoreTrace on an instance
//
void
CoreTraceV1API_v1StartCoreTrace(apiClient_t *apiClient, char *instanceId);


// Stop CoreTrace on an instance.
//
void
CoreTraceV1API_v1StopCoreTrace(apiClient_t *apiClient, char *instanceId);


