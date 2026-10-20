#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/firmware_v1.h"
#include "../model/model_v1.h"


// Get Software for Model
//
list_t*
ModelsV1API_v1GetModelSoftware(apiClient_t *apiClient, char *model);


// Get Supported Models
//
list_t*
ModelsV1API_v1GetModels(apiClient_t *apiClient);


