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


// Delete a RAM dump
//
// Deletes this device's RAM dump file. Returns 204 whether or not a dump existed. Requires the RAM dump license feature. An unknown `instanceId` is a successful no-op that returns 204.
//
void
RAMDumpAPI_v3ClearRamDump(apiClient_t *apiClient, char *instanceId);


// Get a RAM dump download token
//
// Returns a short-lived token that authorizes downloading this device's RAM dump without an `Authorization` header, so you can hand the link to a download manager or browser. Download with `GET /v1/preauthed/{token}/{filename}`. The token works only for this device's RAM dump and expires when your current session token expires. Requires the RAM dump license feature.
//
token_t*
RAMDumpAPI_v3RamDumpPreauthorize(apiClient_t *apiClient, char *instanceId);


// Start a RAM dump
//
// Captures the full contents of the device's memory to a file, for offline analysis with memory forensics tools. Returns 202 as soon as the dump has started; it is written in the background, and large memory sizes take a while. Download it with `v3RamDumpPreauthorize` when it is done, and delete it with `v3ClearRamDump`. Requires the RAM dump license feature (403 otherwise).
//
void
RAMDumpAPI_v3StartRamDump(apiClient_t *apiClient, char *instanceId);


