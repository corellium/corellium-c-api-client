#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/hypertune_hash_response.h"
#include "../model/hypertune_init_response.h"


// Get Hypertune state hash
//
// Returns the current Hypertune state hash for the cluster.
//
hypertune_hash_response_t*
HypertuneAPI_v3HypertuneHash(apiClient_t *apiClient, char *token, char *branch, char *body);


// Get Hypertune initialization data
//
// Returns the Hypertune initialization data used by the SDK.
//
hypertune_init_response_t*
HypertuneAPI_v3HypertuneInit(apiClient_t *apiClient, char *token, char *branch, char *body);


