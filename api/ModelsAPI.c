#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "ModelsAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096


// List software for a model
//
// Lists the operating-system builds you can install on a new instance of one model. Identify the model by its flavor ID (for example `iphone17a`) or its product identifier. Each entry's `osVersion` and `osBuild` are the values to pass to `POST /v3/instances`.  **Where the list comes from.** It includes vendor builds the platform supports for this model (for example public iOS releases), firmware installed cluster-wide with `POST /v3/images/install-firmware`, and firmware uploaded at domain level with `POST /v3/images` (no `projectId` or `instanceId`). It does **not** include images that belong to a project or instance; to boot one of those, reference it explicitly when creating the instance.  **Choosing a build.** - `installed: true` builds are already on your deployment and start fastest. Others are downloaded when first used. - On Android there are usually two builds per version; `rooted` tells them apart. MATRIX needs the rooted build. - `springboardSnapshot` present means the build supports rapid start.  Returns 404 if the model is unknown or has no software.
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
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Signed in, but not allowed to do this: you lack the required role, have no access to the project, or your license does not include the feature.");
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

// List device models
//
// Lists every device model you can create an instance of. Call it first when creating a device: pick a model, then list its software with `v3GetModelSoftware`, then create the instance with `POST /v3/instances`.  The list only includes models your account can use. iOS models are left out if iOS is disabled for your domain, models from vendors your domain has not enabled are left out, and beta models appear only on deployments that allow them.  Each entry tells you what you need to create a valid instance: - `flavor`: the value to pass as `flavor` when creating the instance. - `cores`, `coresMin`, `coresMax`, `coresStep`, `coresAllowed`: which CPU core counts are allowed. - `ram`, `ramMin`, `ramMax`: allowed memory, in MiB. - `hasSoftware`: false means there is no operating system available for this model yet, so an instance cannot be created from a standard build. - `mast`: whether MATRIX assessments work on it.  **Caching.** The response carries an `ETag` header. Send it back as `If-None-Match` on later calls; if nothing has changed you get 304 with no body and can reuse your copy.
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
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Signed in, but not allowed to do this: you lack the required role, have no access to the project, or your license does not include the feature.");
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

