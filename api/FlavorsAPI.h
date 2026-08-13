#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/api_not_found_error.h"
#include "../model/flavor_frame.h"


// Get frame for flavor
//
// Get frame for the given flavor ID.
//
flavor_frame_t*
FlavorsAPI_v3GetFrame(apiClient_t *apiClient, char *flavorId);


// Get frame image for flavor
//
// Get frame image for the given flavor ID.
//
binary_t*
FlavorsAPI_v3GetFrameImage(apiClient_t *apiClient, char *flavorId);


// Get product image for flavor
//
// Get product image for the given flavor ID.
//
binary_t*
FlavorsAPI_v3GetProductImage(apiClient_t *apiClient, char *flavorId);


