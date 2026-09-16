#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/api_error.h"
#include "../model/api_not_found_error.h"
#include "../model/model.h"
#include "../model/model_firmware.h"


// Get Software for Model
//
list_t*
ModelsAPI_v3GetModelSoftware(apiClient_t *apiClient, char *model);


// Get Supported Models
//
list_t*
ModelsAPI_v3GetModels(apiClient_t *apiClient);


