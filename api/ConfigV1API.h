#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/config_response_v1.h"


// Get all configs
//
config_response_v1_t*
ConfigV1API_v1GetConfig(apiClient_t *apiClient);


