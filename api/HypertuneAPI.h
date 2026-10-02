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
// Returns a short fingerprint of the current feature-flag settings for this cluster. The web interface compares it with its cached copy and downloads the full settings with `v3HypertuneInit` only when it changes. Most API clients do not need this.
//
hypertune_hash_response_t*
HypertuneAPI_v3HypertuneHash(apiClient_t *apiClient, char *token, char *branch, char *body);


// Get Hypertune initialization data
//
// Returns the full feature-flag settings for this cluster, which the web interface uses to decide which features to show. Most API clients do not need this; use `GET /v3/config` to learn what a deployment supports.
//
hypertune_init_response_t*
HypertuneAPI_v3HypertuneInit(apiClient_t *apiClient, char *token, char *branch, char *body);


