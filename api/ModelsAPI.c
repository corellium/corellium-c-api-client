#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "ModelsAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096


// Get Software for Model
//
// Get software for model. The `model` path parameter is resolved as a flavor ID first and as a product identifier second. Addressing a flavor ID additionally returns `springboardSnapshot` for the builds that have a rapid-start snapshot, which a product identifier cannot report because several flavors can share one product.
//
list_t*
ModelsAPI_v3GetModelSoftware(apiClient_t *apiClient, char *model)
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
    char *localVarPath = strdup("/v3/models/{model}/software");

    if(!model)
        goto end;


    // Path Params
    long sizeOfPathParams_model = strlen(model)+3 + sizeof("{ model }") - 1;
    if(model == NULL) {
        goto end;
    }
    char* localVarToReplace_model = malloc(sizeOfPathParams_model);
    sprintf(localVarToReplace_model, "{%s}", "model");

    localVarPath = strReplace(localVarPath, localVarToReplace_model, model);


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
    //    printf("%s\n","Supported software loads for this model.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Authentication required.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Permission denied.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","No software found for the given model.");
    //}
    list_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ModelsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        if(!cJSON_IsArray(ModelsAPIlocalVarJSON)) {
            return 0;//nonprimitive container
        }
        elementToReturn = list_createList();
        cJSON *VarJSON;
        cJSON_ArrayForEach(VarJSON, ModelsAPIlocalVarJSON)
        {
            if(!cJSON_IsObject(VarJSON))
            {
               // return 0;
            }
            char *localVarJSONToChar = cJSON_Print(VarJSON);
            list_addElement(elementToReturn , localVarJSONToChar);
        }

        cJSON_Delete( ModelsAPIlocalVarJSON);
        cJSON_Delete( VarJSON);
    }
    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_model);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Get Supported Models
//
// Get supported models. The response carries an `ETag`; repeating the request with that value in `If-None-Match` returns 304 when the catalog is unchanged.
//
list_t*
ModelsAPI_v3GetModels(apiClient_t *apiClient, char *if_none_match)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = list_createList();
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/v3/models");





    // header parameters
    char *keyHeader_if_none_match = NULL;
    char * valueHeader_if_none_match = 0;
    keyValuePair_t *keyPairHeader_if_none_match = 0;
    if (if_none_match) {
        keyHeader_if_none_match = strdup("if-none-match");
        valueHeader_if_none_match = strdup((if_none_match));
        keyPairHeader_if_none_match = keyValuePair_create(keyHeader_if_none_match, valueHeader_if_none_match);
        list_addElement(localVarHeaderParameters,keyPairHeader_if_none_match);
    }

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
    //    printf("%s\n","Supported device configurations.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 304) {
    //    printf("%s\n","The resource is unchanged since the ETag given in If-None-Match.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Authentication required.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Permission denied.");
    //}
    list_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ModelsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        if(!cJSON_IsArray(ModelsAPIlocalVarJSON)) {
            return 0;//nonprimitive container
        }
        elementToReturn = list_createList();
        cJSON *VarJSON;
        cJSON_ArrayForEach(VarJSON, ModelsAPIlocalVarJSON)
        {
            if(!cJSON_IsObject(VarJSON))
            {
               // return 0;
            }
            char *localVarJSONToChar = cJSON_Print(VarJSON);
            list_addElement(elementToReturn , localVarJSONToChar);
        }

        cJSON_Delete( ModelsAPIlocalVarJSON);
        cJSON_Delete( VarJSON);
    }
    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    list_freeList(localVarHeaderParameters);
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    if (keyHeader_if_none_match) {
        free(keyHeader_if_none_match);
        keyHeader_if_none_match = NULL;
    }
    if (valueHeader_if_none_match) {
        free(valueHeader_if_none_match);
        valueHeader_if_none_match = NULL;
    }
    free(keyPairHeader_if_none_match);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

