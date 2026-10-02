#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/api_error.h"


// Check that the API is ready
//
// Health check. Returns 204 (no body) when the API is up and accepting requests, and 503 while it is shutting down. Needs no sign-in, so monitoring tools and scripts can call it before doing real work, for example to wait for a deployment to come back after an upgrade.
//
void
StatusAPI_v3Ready(apiClient_t *apiClient);


