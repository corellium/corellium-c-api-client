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
// Get software for model. The `model` path parameter is resolved as a flavor ID first and as a product identifier second. Addressing a flavor ID additionally returns `springboardSnapshot` for the builds that have a rapid-start snapshot, which a product identifier cannot report because several flavors can share one product.
//
list_t*
ModelsAPI_v3GetModelSoftware(apiClient_t *apiClient, char *model);


// Get Supported Models
//
// Get supported models. The response carries an `ETag`; repeating the request with that value in `If-None-Match` returns 304 when the catalog is unchanged.
//
list_t*
ModelsAPI_v3GetModels(apiClient_t *apiClient, char *if_none_match);


