#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/config_response.h"


// Get all configs
//
config_response_t*
ConfigAPI_v3GetConfig(apiClient_t *apiClient);


