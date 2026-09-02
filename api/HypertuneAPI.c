#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "HypertuneAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096


// Get Hypertune state hash
//
// Returns the current Hypertune state hash for the cluster.
//
hypertune_hash_response_t*
HypertuneAPI_v3HypertuneHash(apiClient_t *apiClient, char *token, char *branch, char *body)
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
    char *localVarPath = strdup("/v3/hypertune/hash");





    // query parameters
    char *keyQuery_token = NULL;
    char * valueQuery_token = NULL;
    keyValuePair_t *keyPairQuery_token = 0;
    if (token)
    {
        keyQuery_token = strdup("token");
        valueQuery_token = strdup((token));
        keyPairQuery_token = keyValuePair_create(keyQuery_token, valueQuery_token);
        list_addElement(localVarQueryParameters,keyPairQuery_token);
    }

    // query parameters
    char *keyQuery_branch = NULL;
    char * valueQuery_branch = NULL;
    keyValuePair_t *keyPairQuery_branch = 0;
    if (branch)
    {
        keyQuery_branch = strdup("branch");
        valueQuery_branch = strdup((branch));
        keyPairQuery_branch = keyValuePair_create(keyQuery_branch, valueQuery_branch);
        list_addElement(localVarQueryParameters,keyPairQuery_branch);
    }

    // query parameters
    char *keyQuery_body = NULL;
    char * valueQuery_body = NULL;
    keyValuePair_t *keyPairQuery_body = 0;
    if (body)
    {
        keyQuery_body = strdup("body");
        valueQuery_body = strdup((body));
        keyPairQuery_body = keyValuePair_create(keyQuery_body, valueQuery_body);
        list_addElement(localVarQueryParameters,keyPairQuery_body);
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
    //    printf("%s\n","Hypertune state hash.");
    //}
    //nonprimitive not container
    hypertune_hash_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *HypertuneAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = hypertune_hash_response_parseFromJSON(HypertuneAPIlocalVarJSON);
        cJSON_Delete(HypertuneAPIlocalVarJSON);
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
    if(keyQuery_token){
        free(keyQuery_token);
        keyQuery_token = NULL;
    }
    if(valueQuery_token){
        free(valueQuery_token);
        valueQuery_token = NULL;
    }
    if(keyPairQuery_token){
        keyValuePair_free(keyPairQuery_token);
        keyPairQuery_token = NULL;
    }
    if(keyQuery_branch){
        free(keyQuery_branch);
        keyQuery_branch = NULL;
    }
    if(valueQuery_branch){
        free(valueQuery_branch);
        valueQuery_branch = NULL;
    }
    if(keyPairQuery_branch){
        keyValuePair_free(keyPairQuery_branch);
        keyPairQuery_branch = NULL;
    }
    if(keyQuery_body){
        free(keyQuery_body);
        keyQuery_body = NULL;
    }
    if(valueQuery_body){
        free(valueQuery_body);
        valueQuery_body = NULL;
    }
    if(keyPairQuery_body){
        keyValuePair_free(keyPairQuery_body);
        keyPairQuery_body = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Get Hypertune initialization data
//
// Returns the Hypertune initialization data used by the SDK.
//
hypertune_init_response_t*
HypertuneAPI_v3HypertuneInit(apiClient_t *apiClient, char *token, char *branch, char *body)
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
    char *localVarPath = strdup("/v3/hypertune/init");





    // query parameters
    char *keyQuery_token = NULL;
    char * valueQuery_token = NULL;
    keyValuePair_t *keyPairQuery_token = 0;
    if (token)
    {
        keyQuery_token = strdup("token");
        valueQuery_token = strdup((token));
        keyPairQuery_token = keyValuePair_create(keyQuery_token, valueQuery_token);
        list_addElement(localVarQueryParameters,keyPairQuery_token);
    }

    // query parameters
    char *keyQuery_branch = NULL;
    char * valueQuery_branch = NULL;
    keyValuePair_t *keyPairQuery_branch = 0;
    if (branch)
    {
        keyQuery_branch = strdup("branch");
        valueQuery_branch = strdup((branch));
        keyPairQuery_branch = keyValuePair_create(keyQuery_branch, valueQuery_branch);
        list_addElement(localVarQueryParameters,keyPairQuery_branch);
    }

    // query parameters
    char *keyQuery_body = NULL;
    char * valueQuery_body = NULL;
    keyValuePair_t *keyPairQuery_body = 0;
    if (body)
    {
        keyQuery_body = strdup("body");
        valueQuery_body = strdup((body));
        keyPairQuery_body = keyValuePair_create(keyQuery_body, valueQuery_body);
        list_addElement(localVarQueryParameters,keyPairQuery_body);
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
    //    printf("%s\n","Hypertune initialization data.");
    //}
    //nonprimitive not container
    hypertune_init_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *HypertuneAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = hypertune_init_response_parseFromJSON(HypertuneAPIlocalVarJSON);
        cJSON_Delete(HypertuneAPIlocalVarJSON);
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
    if(keyQuery_token){
        free(keyQuery_token);
        keyQuery_token = NULL;
    }
    if(valueQuery_token){
        free(valueQuery_token);
        valueQuery_token = NULL;
    }
    if(keyPairQuery_token){
        keyValuePair_free(keyPairQuery_token);
        keyPairQuery_token = NULL;
    }
    if(keyQuery_branch){
        free(keyQuery_branch);
        keyQuery_branch = NULL;
    }
    if(valueQuery_branch){
        free(valueQuery_branch);
        valueQuery_branch = NULL;
    }
    if(keyPairQuery_branch){
        keyValuePair_free(keyPairQuery_branch);
        keyPairQuery_branch = NULL;
    }
    if(keyQuery_body){
        free(keyQuery_body);
        keyQuery_body = NULL;
    }
    if(valueQuery_body){
        free(valueQuery_body);
        valueQuery_body = NULL;
    }
    if(keyPairQuery_body){
        keyValuePair_free(keyPairQuery_body);
        keyPairQuery_body = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

