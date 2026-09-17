#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/api_error.h"
#include "../model/config_response.h"
#include "../model/deployment_version.h"


// Get all configs
//
config_response_t*
ConfigAPI_v3GetConfig(apiClient_t *apiClient);


// Get Deployment Version
//
// Get the version and build identity of the running deployment.
//
deployment_version_t*
ConfigAPI_v3GetVersion(apiClient_t *apiClient);


