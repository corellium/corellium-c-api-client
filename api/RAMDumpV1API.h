#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/api_conflict_error_v1.h"
#include "../model/api_error_v1.h"
#include "../model/token_v1.h"
#include "../model/user_error_v1.h"


// Clear RAM Dump
//
void
RAMDumpV1API_v1ClearRamDump(apiClient_t *apiClient, char *instanceId);


// Pre-authorize a RAM Dump download
//
token_v1_t*
RAMDumpV1API_v1RAMDumpPreauthorize(apiClient_t *apiClient, char *instanceId);


// Start a RAM Dump on an instance
//
void
RAMDumpV1API_v1StartRamDump(apiClient_t *apiClient, char *instanceId);


