#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/api_error.h"
#include "../model/kernel_task.h"
#include "../model/user_error.h"


// Clear CoreTrace logs
//
void
CoreTraceAPI_v3ClearCoreTrace(apiClient_t *apiClient, char *instanceId);


// Get Running Threads (CoreTrace)
//
list_t*
CoreTraceAPI_v3ListThreads(apiClient_t *apiClient, char *instanceId);


// Start CoreTrace on an instance
//
void
CoreTraceAPI_v3StartCoreTrace(apiClient_t *apiClient, char *instanceId);


// Stop CoreTrace on an instance.
//
void
CoreTraceAPI_v3StopCoreTrace(apiClient_t *apiClient, char *instanceId);


