#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/api_conflict_error.h"
#include "../model/api_error.h"
#include "../model/token.h"
#include "../model/user_error_response.h"


// Clear RAM Dump
//
void
RAMDumpAPI_v3ClearRamDump(apiClient_t *apiClient, char *instanceId);


// Pre-authorize a RAM Dump download
//
token_t*
RAMDumpAPI_v3RamDumpPreauthorize(apiClient_t *apiClient, char *instanceId);


// Start a RAM Dump on an instance
//
void
RAMDumpAPI_v3StartRamDump(apiClient_t *apiClient, char *instanceId);


