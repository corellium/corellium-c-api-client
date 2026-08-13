#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/api_not_found_error_v1.h"
#include "../model/image_v1.h"


// Get Image Metadata
//
image_v1_t*
ImagesV1API_v1GetImage(apiClient_t *apiClient, char *imageId);


// Get all Images Metadata
//
list_t*
ImagesV1API_v1GetImages(apiClient_t *apiClient, char *project);


