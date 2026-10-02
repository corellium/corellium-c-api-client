#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/api_not_found_error.h"
#include "../model/flavor_frame.h"


// Get the device frame layout for a model
//
// Returns the layout of the on-screen device frame (the picture of the phone drawn around the screen) for a model: its size, where the screen sits inside it, and where the home button is. Use it to draw a device image around a screenshot or live display. `flavorId` is a model `flavor` from `GET /v3/models`. Returns 404 if the model has no frame.
//
flavor_frame_t*
FlavorsAPI_v3GetFrame(apiClient_t *apiClient, char *flavorId);


// Get the device frame image for a model
//
// Downloads the picture of the device frame (the phone body drawn around the screen) for a model, to combine with the layout from `v3GetFrame`. Returns 404 if the model has no frame image.
//
binary_t*
FlavorsAPI_v3GetFrameImage(apiClient_t *apiClient, char *flavorId);


// Get the product image for a model
//
// Downloads a product picture of the device model, for example to show in a model picker. Returns 404 if the model has no product image.
//
binary_t*
FlavorsAPI_v3GetProductImage(apiClient_t *apiClient, char *flavorId);


