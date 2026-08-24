#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "ExtensionsV1API.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096


// Delete an existing extension
//
void
ExtensionsV1API_v1DeleteExtension(apiClient_t *apiClient, char *extensionId)
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
    char *localVarPath = strdup("/v1/extensions/{extensionId}");

    if(!extensionId)
        goto end;


    // Path Params
    long sizeOfPathParams_extensionId = strlen(extensionId)+3 + sizeof("{ extensionId }") - 1;
    if(extensionId == NULL) {
        goto end;
    }
    char* localVarToReplace_extensionId = malloc(sizeOfPathParams_extensionId);
    sprintf(localVarToReplace_extensionId, "{%s}", "extensionId");

    localVarPath = strReplace(localVarPath, localVarToReplace_extensionId, extensionId);


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
                    "DELETE");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 204) {
    //    printf("%s\n","Accepted");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Forbidden");
    //}
    //No return type
end:
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_extensionId);

}

// Get extension by id
//
extension_v1_t*
ExtensionsV1API_v1GetExtensionById(apiClient_t *apiClient, char *extensionId)
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
    char *localVarPath = strdup("/v1/extensions/{extensionId}");

    if(!extensionId)
        goto end;


    // Path Params
    long sizeOfPathParams_extensionId = strlen(extensionId)+3 + sizeof("{ extensionId }") - 1;
    if(extensionId == NULL) {
        goto end;
    }
    char* localVarToReplace_extensionId = malloc(sizeOfPathParams_extensionId);
    sprintf(localVarToReplace_extensionId, "{%s}", "extensionId");

    localVarPath = strReplace(localVarPath, localVarToReplace_extensionId, extensionId);


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
    //    printf("%s\n","Extension");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Forbidden");
    //}
    //nonprimitive not container
    extension_v1_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ExtensionsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = extension_v1_parseFromJSON(ExtensionsV1APIlocalVarJSON);
        cJSON_Delete(ExtensionsV1APIlocalVarJSON);
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
    free(localVarToReplace_extensionId);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Get all extensions
//
list_t*
ExtensionsV1API_v1GetExtensions(apiClient_t *apiClient, double limit, double offset, char *if_none_match)
{
    list_t    *localVarQueryParameters = list_createList();
    list_t    *localVarHeaderParameters = list_createList();
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/v1/extensions");





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


    // query parameters
    char *keyQuery_limit = NULL;
    double valueQuery_limit ;
    keyValuePair_t *keyPairQuery_limit = 0;
    if (limit)
    {
        keyQuery_limit = strdup("limit");
        valueQuery_limit = (limit);
        keyPairQuery_limit = keyValuePair_create(keyQuery_limit, &valueQuery_limit);
        list_addElement(localVarQueryParameters,keyPairQuery_limit);
    }

    // query parameters
    char *keyQuery_offset = NULL;
    double valueQuery_offset ;
    keyValuePair_t *keyPairQuery_offset = 0;
    if (offset)
    {
        keyQuery_offset = strdup("offset");
        valueQuery_offset = (offset);
        keyPairQuery_offset = keyValuePair_create(keyQuery_offset, &valueQuery_offset);
        list_addElement(localVarQueryParameters,keyPairQuery_offset);
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
    //    printf("%s\n","Extensions");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 304) {
    //    printf("%s\n","No changes");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Forbidden");
    //}
    list_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ExtensionsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        if(!cJSON_IsArray(ExtensionsV1APIlocalVarJSON)) {
            return 0;//nonprimitive container
        }
        elementToReturn = list_createList();
        cJSON *VarJSON;
        cJSON_ArrayForEach(VarJSON, ExtensionsV1APIlocalVarJSON)
        {
            if(!cJSON_IsObject(VarJSON))
            {
               // return 0;
            }
            char *localVarJSONToChar = cJSON_Print(VarJSON);
            list_addElement(elementToReturn , localVarJSONToChar);
        }

        cJSON_Delete( ExtensionsV1APIlocalVarJSON);
        cJSON_Delete( VarJSON);
    }
    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    list_freeList(localVarQueryParameters);
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
    if(keyQuery_limit){
        free(keyQuery_limit);
        keyQuery_limit = NULL;
    }
    if(keyPairQuery_limit){
        keyValuePair_free(keyPairQuery_limit);
        keyPairQuery_limit = NULL;
    }
    if(keyQuery_offset){
        free(keyQuery_offset);
        keyQuery_offset = NULL;
    }
    if(keyPairQuery_offset){
        keyValuePair_free(keyPairQuery_offset);
        keyPairQuery_offset = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Load an extension
//
extension_v1_t*
ExtensionsV1API_v1LoadExtension(apiClient_t *apiClient, v1_load_extension_parameters_t *v1_load_extension_parameters)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/v1/extensions");





    // Body Param
    cJSON *localVarSingleItemJSON_v1_load_extension_parameters = NULL;
    if (v1_load_extension_parameters != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_v1_load_extension_parameters = v1_load_extension_parameters_convertToJSON(v1_load_extension_parameters);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_v1_load_extension_parameters);
        localVarBodyLength = strlen(localVarBodyParameters);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","Extension");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Forbidden");
    //}
    //nonprimitive not container
    extension_v1_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ExtensionsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = extension_v1_parseFromJSON(ExtensionsV1APIlocalVarJSON);
        cJSON_Delete(ExtensionsV1APIlocalVarJSON);
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
    list_freeList(localVarContentType);
    free(localVarPath);
    if (localVarSingleItemJSON_v1_load_extension_parameters) {
        cJSON_Delete(localVarSingleItemJSON_v1_load_extension_parameters);
        localVarSingleItemJSON_v1_load_extension_parameters = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Validates extension.json
//
object_t*
ExtensionsV1API_v1ParseExtensionJson(apiClient_t *apiClient, extension_v1_t *extension_v1)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/v1/extensions/parse/extension.json");





    // Body Param
    cJSON *localVarSingleItemJSON_extension_v1 = NULL;
    if (extension_v1 != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_extension_v1 = extension_v1_convertToJSON(extension_v1);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_extension_v1);
        localVarBodyLength = strlen(localVarBodyParameters);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    //nonprimitive not container
    object_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ExtensionsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = object_parseFromJSON(ExtensionsV1APIlocalVarJSON);
        cJSON_Delete(ExtensionsV1APIlocalVarJSON);
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
    list_freeList(localVarContentType);
    free(localVarPath);
    if (localVarSingleItemJSON_extension_v1) {
        cJSON_Delete(localVarSingleItemJSON_extension_v1);
        localVarSingleItemJSON_extension_v1 = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Update an existing extension
//
void
ExtensionsV1API_v1UpdateExtension(apiClient_t *apiClient, char *extensionId, update_extension_t *update_extension)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/v1/extensions/{extensionId}");

    if(!extensionId)
        goto end;


    // Path Params
    long sizeOfPathParams_extensionId = strlen(extensionId)+3 + sizeof("{ extensionId }") - 1;
    if(extensionId == NULL) {
        goto end;
    }
    char* localVarToReplace_extensionId = malloc(sizeOfPathParams_extensionId);
    sprintf(localVarToReplace_extensionId, "{%s}", "extensionId");

    localVarPath = strReplace(localVarPath, localVarToReplace_extensionId, extensionId);



    // Body Param
    cJSON *localVarSingleItemJSON_update_extension = NULL;
    if (update_extension != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_update_extension = update_extension_convertToJSON(update_extension);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_update_extension);
        localVarBodyLength = strlen(localVarBodyParameters);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "PUT");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 204) {
    //    printf("%s\n","Accepted");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Forbidden");
    //}
    //No return type
end:
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    free(localVarToReplace_extensionId);
    if (localVarSingleItemJSON_update_extension) {
        cJSON_Delete(localVarSingleItemJSON_update_extension);
        localVarSingleItemJSON_update_extension = NULL;
    }
    free(localVarBodyParameters);

}

