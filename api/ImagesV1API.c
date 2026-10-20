#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "ImagesV1API.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096


// Get Image Metadata
//
image_v1_t*
ImagesV1API_v1GetImage(apiClient_t *apiClient, char *imageId)
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
    char *localVarPath = strdup("/v1/images/{imageId}");

    if(!imageId)
        goto end;


    // Path Params
    long sizeOfPathParams_imageId = strlen(imageId)+3 + sizeof("{ imageId }") - 1;
    if(imageId == NULL) {
        goto end;
    }
    char* localVarToReplace_imageId = malloc(sizeOfPathParams_imageId);
    sprintf(localVarToReplace_imageId, "{%s}", "imageId");

    localVarPath = strReplace(localVarPath, localVarToReplace_imageId, imageId);


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
    //    printf("%s\n","application/json");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","application/json");
    //}
    //nonprimitive not container
    image_v1_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ImagesV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = image_v1_parseFromJSON(ImagesV1APIlocalVarJSON);
        cJSON_Delete(ImagesV1APIlocalVarJSON);
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
    free(localVarToReplace_imageId);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Get all Images Metadata
//
list_t*
ImagesV1API_v1GetImages(apiClient_t *apiClient, char *project)
{
    list_t    *localVarQueryParameters = list_createList();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/v1/images");





    // query parameters
    char *keyQuery_project = NULL;
    char * valueQuery_project = NULL;
    keyValuePair_t *keyPairQuery_project = 0;
    if (project)
    {
        keyQuery_project = strdup("project");
        valueQuery_project = strdup((project));
        keyPairQuery_project = keyValuePair_create(keyQuery_project, valueQuery_project);
        list_addElement(localVarQueryParameters,keyPairQuery_project);
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
    //    printf("%s\n","application/json");
    //}
    list_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ImagesV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        if(!cJSON_IsArray(ImagesV1APIlocalVarJSON)) {
            return 0;//nonprimitive container
        }
        elementToReturn = list_createList();
        cJSON *VarJSON;
        cJSON_ArrayForEach(VarJSON, ImagesV1APIlocalVarJSON)
        {
            if(!cJSON_IsObject(VarJSON))
            {
               // return 0;
            }
            char *localVarJSONToChar = cJSON_Print(VarJSON);
            list_addElement(elementToReturn , localVarJSONToChar);
        }

        cJSON_Delete( ImagesV1APIlocalVarJSON);
        cJSON_Delete( VarJSON);
    }
    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    list_freeList(localVarQueryParameters);
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    if(keyQuery_project){
        free(keyQuery_project);
        keyQuery_project = NULL;
    }
    if(valueQuery_project){
        free(valueQuery_project);
        valueQuery_project = NULL;
    }
    if(keyPairQuery_project){
        keyValuePair_free(keyPairQuery_project);
        keyPairQuery_project = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

