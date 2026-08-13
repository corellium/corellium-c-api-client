#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "FlavorsAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096


// Get frame for flavor
//
// Get frame for the given flavor ID.
//
flavor_frame_t*
FlavorsAPI_v3GetFrame(apiClient_t *apiClient, char *flavorId)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/v3/flavors/{flavorId}");

    if(!flavorId)
        goto end;


    // Path Params
    long sizeOfPathParams_flavorId = strlen(flavorId)+3 + sizeof("{ flavorId }") - 1;
    if(flavorId == NULL) {
        goto end;
    }
    char* localVarToReplace_flavorId = malloc(sizeOfPathParams_flavorId);
    sprintf(localVarToReplace_flavorId, "{%s}", "flavorId");

    localVarPath = strReplace(localVarPath, localVarToReplace_flavorId, flavorId);


    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "GET");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","Frame for the flavor.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","No frame found for the given flavor ID.");
    //}
    //nonprimitive not container
    flavor_frame_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *FlavorsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = flavor_frame_parseFromJSON(FlavorsAPIlocalVarJSON);
        cJSON_Delete(FlavorsAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_flavorId);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Get frame image for flavor
//
// Get frame image for the given flavor ID.
//
binary_t*
FlavorsAPI_v3GetFrameImage(apiClient_t *apiClient, char *flavorId)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/v3/flavors/{flavorId}/image");

    if(!flavorId)
        goto end;


    // Path Params
    long sizeOfPathParams_flavorId = strlen(flavorId)+3 + sizeof("{ flavorId }") - 1;
    if(flavorId == NULL) {
        goto end;
    }
    char* localVarToReplace_flavorId = malloc(sizeOfPathParams_flavorId);
    sprintf(localVarToReplace_flavorId, "{%s}", "flavorId");

    localVarPath = strReplace(localVarPath, localVarToReplace_flavorId, flavorId);


    list_addElement(localVarHeaderType,"application/octet-stream"); //produces
    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "GET");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","Frame image file.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","No frame image found for the given flavor ID.");
    //}
    //primitive return type simple binary
    binary_t* elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300)
        elementToReturn = instantiate_binary_t(apiClient->dataReceived, apiClient->dataReceivedLen);

    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_flavorId);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Get product image for flavor
//
// Get product image for the given flavor ID.
//
binary_t*
FlavorsAPI_v3GetProductImage(apiClient_t *apiClient, char *flavorId)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/v3/flavors/{flavorId}/productimage");

    if(!flavorId)
        goto end;


    // Path Params
    long sizeOfPathParams_flavorId = strlen(flavorId)+3 + sizeof("{ flavorId }") - 1;
    if(flavorId == NULL) {
        goto end;
    }
    char* localVarToReplace_flavorId = malloc(sizeOfPathParams_flavorId);
    sprintf(localVarToReplace_flavorId, "{%s}", "flavorId");

    localVarPath = strReplace(localVarPath, localVarToReplace_flavorId, flavorId);


    list_addElement(localVarHeaderType,"application/octet-stream"); //produces
    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "GET");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","Product image file.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","No product image found for the given flavor ID.");
    //}
    //primitive return type simple binary
    binary_t* elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300)
        elementToReturn = instantiate_binary_t(apiClient->dataReceived, apiClient->dataReceivedLen);

    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_flavorId);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

