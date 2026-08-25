#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "InterconnectsAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096


// Create I/O Interconnect
//
// Create an I/O Interconnect for the specified project and attach virtual device interfaces.
//
interconnect_t*
InterconnectsAPI_v3CreateInterconnect(apiClient_t *apiClient, create_interconnect_v3_body_t *create_interconnect_v3_body)
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
    char *localVarPath = strdup("/v3/interconnects");





    // Body Param
    cJSON *localVarSingleItemJSON_create_interconnect_v3_body = NULL;
    if (create_interconnect_v3_body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_create_interconnect_v3_body = create_interconnect_v3_body_convertToJSON(create_interconnect_v3_body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_create_interconnect_v3_body);
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
    //    printf("%s\n","Created interconnect.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Invalid request.");
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
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal server error.");
    //}
    //nonprimitive not container
    interconnect_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *InterconnectsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = interconnect_parseFromJSON(InterconnectsAPIlocalVarJSON);
        cJSON_Delete(InterconnectsAPIlocalVarJSON);
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
    if (localVarSingleItemJSON_create_interconnect_v3_body) {
        cJSON_Delete(localVarSingleItemJSON_create_interconnect_v3_body);
        localVarSingleItemJSON_create_interconnect_v3_body = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Delete I/O Interconnect
//
void
InterconnectsAPI_v3DeleteInterconnect(apiClient_t *apiClient, char *interconnectId)
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
    char *localVarPath = strdup("/v3/interconnects/{interconnectId}");

    if(!interconnectId)
        goto end;


    // Path Params
    long sizeOfPathParams_interconnectId = strlen(interconnectId)+3 + sizeof("{ interconnectId }") - 1;
    if(interconnectId == NULL) {
        goto end;
    }
    char* localVarToReplace_interconnectId = malloc(sizeOfPathParams_interconnectId);
    sprintf(localVarToReplace_interconnectId, "{%s}", "interconnectId");

    localVarPath = strReplace(localVarPath, localVarToReplace_interconnectId, interconnectId);


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
    //    printf("%s\n","Successfully deleted interconnect.");
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
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal server error.");
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
    free(localVarToReplace_interconnectId);

}

// Get Interconnect
//
interconnect_t*
InterconnectsAPI_v3GetInterconnect(apiClient_t *apiClient, char *interconnectId)
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
    char *localVarPath = strdup("/v3/interconnects/{interconnectId}");

    if(!interconnectId)
        goto end;


    // Path Params
    long sizeOfPathParams_interconnectId = strlen(interconnectId)+3 + sizeof("{ interconnectId }") - 1;
    if(interconnectId == NULL) {
        goto end;
    }
    char* localVarToReplace_interconnectId = malloc(sizeOfPathParams_interconnectId);
    sprintf(localVarToReplace_interconnectId, "{%s}", "interconnectId");

    localVarPath = strReplace(localVarPath, localVarToReplace_interconnectId, interconnectId);


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
    //    printf("%s\n","Successfully retrieved interconnect details.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Invalid request.");
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
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal server error.");
    //}
    //nonprimitive not container
    interconnect_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *InterconnectsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = interconnect_parseFromJSON(InterconnectsAPIlocalVarJSON);
        cJSON_Delete(InterconnectsAPIlocalVarJSON);
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
    free(localVarToReplace_interconnectId);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// List I/O Interconnects
//
interconnect_list_t*
InterconnectsAPI_v3ListInterconnects(apiClient_t *apiClient, double *limit, double *offset, char *name, char *protocol, char *type, char *status, char *sort, char *projectId)
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
    char *localVarPath = strdup("/v3/interconnects");





    // query parameters
    char *keyQuery_limit = NULL;
    char * valueQuery_limit = NULL;
    keyValuePair_t *keyPairQuery_limit = 0;
    if (limit)
    {
        keyQuery_limit = strdup("limit");
        valueQuery_limit = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_limit, MAX_NUMBER_LENGTH, "%d", *limit);
        keyPairQuery_limit = keyValuePair_create(keyQuery_limit, valueQuery_limit);
        list_addElement(localVarQueryParameters,keyPairQuery_limit);
    }

    // query parameters
    char *keyQuery_offset = NULL;
    char * valueQuery_offset = NULL;
    keyValuePair_t *keyPairQuery_offset = 0;
    if (offset)
    {
        keyQuery_offset = strdup("offset");
        valueQuery_offset = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_offset, MAX_NUMBER_LENGTH, "%d", *offset);
        keyPairQuery_offset = keyValuePair_create(keyQuery_offset, valueQuery_offset);
        list_addElement(localVarQueryParameters,keyPairQuery_offset);
    }

    // query parameters
    char *keyQuery_name = NULL;
    char * valueQuery_name = NULL;
    keyValuePair_t *keyPairQuery_name = 0;
    if (name)
    {
        keyQuery_name = strdup("name");
        valueQuery_name = strdup((name));
        keyPairQuery_name = keyValuePair_create(keyQuery_name, valueQuery_name);
        list_addElement(localVarQueryParameters,keyPairQuery_name);
    }

    // query parameters
    char *keyQuery_protocol = NULL;
    char * valueQuery_protocol = NULL;
    keyValuePair_t *keyPairQuery_protocol = 0;
    if (protocol)
    {
        keyQuery_protocol = strdup("protocol");
        valueQuery_protocol = strdup((protocol));
        keyPairQuery_protocol = keyValuePair_create(keyQuery_protocol, valueQuery_protocol);
        list_addElement(localVarQueryParameters,keyPairQuery_protocol);
    }

    // query parameters
    char *keyQuery_type = NULL;
    char * valueQuery_type = NULL;
    keyValuePair_t *keyPairQuery_type = 0;
    if (type)
    {
        keyQuery_type = strdup("type");
        valueQuery_type = strdup((type));
        keyPairQuery_type = keyValuePair_create(keyQuery_type, valueQuery_type);
        list_addElement(localVarQueryParameters,keyPairQuery_type);
    }

    // query parameters
    char *keyQuery_status = NULL;
    char * valueQuery_status = NULL;
    keyValuePair_t *keyPairQuery_status = 0;
    if (status)
    {
        keyQuery_status = strdup("status");
        valueQuery_status = strdup((status));
        keyPairQuery_status = keyValuePair_create(keyQuery_status, valueQuery_status);
        list_addElement(localVarQueryParameters,keyPairQuery_status);
    }

    // query parameters
    char *keyQuery_sort = NULL;
    char * valueQuery_sort = NULL;
    keyValuePair_t *keyPairQuery_sort = 0;
    if (sort)
    {
        keyQuery_sort = strdup("sort");
        valueQuery_sort = strdup((sort));
        keyPairQuery_sort = keyValuePair_create(keyQuery_sort, valueQuery_sort);
        list_addElement(localVarQueryParameters,keyPairQuery_sort);
    }

    // query parameters
    char *keyQuery_projectId = NULL;
    char * valueQuery_projectId = NULL;
    keyValuePair_t *keyPairQuery_projectId = 0;
    if (projectId)
    {
        keyQuery_projectId = strdup("projectId");
        valueQuery_projectId = strdup((projectId));
        keyPairQuery_projectId = keyValuePair_create(keyQuery_projectId, valueQuery_projectId);
        list_addElement(localVarQueryParameters,keyPairQuery_projectId);
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
    //    printf("%s\n","Successfully retrieved interconnects.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Invalid request.");
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
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal server error.");
    //}
    //nonprimitive not container
    interconnect_list_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *InterconnectsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = interconnect_list_parseFromJSON(InterconnectsAPIlocalVarJSON);
        cJSON_Delete(InterconnectsAPIlocalVarJSON);
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
    list_freeList(localVarQueryParameters);
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    if(keyQuery_limit){
        free(keyQuery_limit);
        keyQuery_limit = NULL;
    }
    if(valueQuery_limit){
        free(valueQuery_limit);
        valueQuery_limit = NULL;
    }
    if(keyPairQuery_limit){
        keyValuePair_free(keyPairQuery_limit);
        keyPairQuery_limit = NULL;
    }
    if(keyQuery_offset){
        free(keyQuery_offset);
        keyQuery_offset = NULL;
    }
    if(valueQuery_offset){
        free(valueQuery_offset);
        valueQuery_offset = NULL;
    }
    if(keyPairQuery_offset){
        keyValuePair_free(keyPairQuery_offset);
        keyPairQuery_offset = NULL;
    }
    if(keyQuery_name){
        free(keyQuery_name);
        keyQuery_name = NULL;
    }
    if(valueQuery_name){
        free(valueQuery_name);
        valueQuery_name = NULL;
    }
    if(keyPairQuery_name){
        keyValuePair_free(keyPairQuery_name);
        keyPairQuery_name = NULL;
    }
    if(keyQuery_protocol){
        free(keyQuery_protocol);
        keyQuery_protocol = NULL;
    }
    if(valueQuery_protocol){
        free(valueQuery_protocol);
        valueQuery_protocol = NULL;
    }
    if(keyPairQuery_protocol){
        keyValuePair_free(keyPairQuery_protocol);
        keyPairQuery_protocol = NULL;
    }
    if(keyQuery_type){
        free(keyQuery_type);
        keyQuery_type = NULL;
    }
    if(valueQuery_type){
        free(valueQuery_type);
        valueQuery_type = NULL;
    }
    if(keyPairQuery_type){
        keyValuePair_free(keyPairQuery_type);
        keyPairQuery_type = NULL;
    }
    if(keyQuery_status){
        free(keyQuery_status);
        keyQuery_status = NULL;
    }
    if(valueQuery_status){
        free(valueQuery_status);
        valueQuery_status = NULL;
    }
    if(keyPairQuery_status){
        keyValuePair_free(keyPairQuery_status);
        keyPairQuery_status = NULL;
    }
    if(keyQuery_sort){
        free(keyQuery_sort);
        keyQuery_sort = NULL;
    }
    if(valueQuery_sort){
        free(valueQuery_sort);
        valueQuery_sort = NULL;
    }
    if(keyPairQuery_sort){
        keyValuePair_free(keyPairQuery_sort);
        keyPairQuery_sort = NULL;
    }
    if(keyQuery_projectId){
        free(keyQuery_projectId);
        keyQuery_projectId = NULL;
    }
    if(valueQuery_projectId){
        free(valueQuery_projectId);
        valueQuery_projectId = NULL;
    }
    if(keyPairQuery_projectId){
        keyValuePair_free(keyPairQuery_projectId);
        keyPairQuery_projectId = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Patch I/O Interconnect
//
interconnect_t*
InterconnectsAPI_v3PatchInterconnect(apiClient_t *apiClient, char *interconnectId, patch_interconnect_body_t *patch_interconnect_body)
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
    char *localVarPath = strdup("/v3/interconnects/{interconnectId}");

    if(!interconnectId)
        goto end;


    // Path Params
    long sizeOfPathParams_interconnectId = strlen(interconnectId)+3 + sizeof("{ interconnectId }") - 1;
    if(interconnectId == NULL) {
        goto end;
    }
    char* localVarToReplace_interconnectId = malloc(sizeOfPathParams_interconnectId);
    sprintf(localVarToReplace_interconnectId, "{%s}", "interconnectId");

    localVarPath = strReplace(localVarPath, localVarToReplace_interconnectId, interconnectId);



    // Body Param
    cJSON *localVarSingleItemJSON_patch_interconnect_body = NULL;
    if (patch_interconnect_body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_patch_interconnect_body = patch_interconnect_body_convertToJSON(patch_interconnect_body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_patch_interconnect_body);
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
                    "PATCH");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","Successfully updated interconnect.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Invalid request.");
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
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal server error.");
    //}
    //nonprimitive not container
    interconnect_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *InterconnectsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = interconnect_parseFromJSON(InterconnectsAPIlocalVarJSON);
        cJSON_Delete(InterconnectsAPIlocalVarJSON);
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
    free(localVarToReplace_interconnectId);
    if (localVarSingleItemJSON_patch_interconnect_body) {
        cJSON_Delete(localVarSingleItemJSON_patch_interconnect_body);
        localVarSingleItemJSON_patch_interconnect_body = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Update I/O Interconnect
//
interconnect_t*
InterconnectsAPI_v3UpdateInterconnect(apiClient_t *apiClient, char *interconnectId, update_interconnect_v3_body_t *update_interconnect_v3_body)
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
    char *localVarPath = strdup("/v3/interconnects/{interconnectId}");

    if(!interconnectId)
        goto end;


    // Path Params
    long sizeOfPathParams_interconnectId = strlen(interconnectId)+3 + sizeof("{ interconnectId }") - 1;
    if(interconnectId == NULL) {
        goto end;
    }
    char* localVarToReplace_interconnectId = malloc(sizeOfPathParams_interconnectId);
    sprintf(localVarToReplace_interconnectId, "{%s}", "interconnectId");

    localVarPath = strReplace(localVarPath, localVarToReplace_interconnectId, interconnectId);



    // Body Param
    cJSON *localVarSingleItemJSON_update_interconnect_v3_body = NULL;
    if (update_interconnect_v3_body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_update_interconnect_v3_body = update_interconnect_v3_body_convertToJSON(update_interconnect_v3_body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_update_interconnect_v3_body);
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
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","Successfully updated interconnect.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Invalid request.");
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
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal server error.");
    //}
    //nonprimitive not container
    interconnect_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *InterconnectsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = interconnect_parseFromJSON(InterconnectsAPIlocalVarJSON);
        cJSON_Delete(InterconnectsAPIlocalVarJSON);
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
    free(localVarToReplace_interconnectId);
    if (localVarSingleItemJSON_update_interconnect_v3_body) {
        cJSON_Delete(localVarSingleItemJSON_update_interconnect_v3_body);
        localVarSingleItemJSON_update_interconnect_v3_body = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

