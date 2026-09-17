#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "DomainAuthProvidersAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096


// Create a new auth provider for a domain
//
// **Required role:** Domain administrator.  Create a new auth provider for a domain.
//
create_domain_auth_provider_response_t*
DomainAuthProvidersAPI_v3CreateDomainAuthProvider(apiClient_t *apiClient, char *domainId, create_domain_auth_provider_body_t *create_domain_auth_provider_body)
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
    char *localVarPath = strdup("/v3/domain/{domainId}/auth");

    if(!domainId)
        goto end;


    // Path Params
    long sizeOfPathParams_domainId = strlen(domainId)+3 + sizeof("{ domainId }") - 1;
    if(domainId == NULL) {
        goto end;
    }
    char* localVarToReplace_domainId = malloc(sizeOfPathParams_domainId);
    sprintf(localVarToReplace_domainId, "{%s}", "domainId");

    localVarPath = strReplace(localVarPath, localVarToReplace_domainId, domainId);



    // Body Param
    cJSON *localVarSingleItemJSON_create_domain_auth_provider_body = NULL;
    if (create_domain_auth_provider_body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_create_domain_auth_provider_body = create_domain_auth_provider_body_convertToJSON(create_domain_auth_provider_body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_create_domain_auth_provider_body);
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
    //    printf("%s\n","Auth provider created.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Invalid request body.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Domain administrator permissions required.");
    //}
    //nonprimitive not container
    create_domain_auth_provider_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DomainAuthProvidersAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = create_domain_auth_provider_response_parseFromJSON(DomainAuthProvidersAPIlocalVarJSON);
        cJSON_Delete(DomainAuthProvidersAPIlocalVarJSON);
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
    free(localVarToReplace_domainId);
    if (localVarSingleItemJSON_create_domain_auth_provider_body) {
        cJSON_Delete(localVarSingleItemJSON_create_domain_auth_provider_body);
        localVarSingleItemJSON_create_domain_auth_provider_body = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Delete an auth provider from a domain
//
// **Required role:** Domain administrator.  Delete an auth provider from a domain.
//
void
DomainAuthProvidersAPI_v3DeleteDomainAuthProvider(apiClient_t *apiClient, char *domainId, char *providerId)
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
    char *localVarPath = strdup("/v3/domain/{domainId}/auth/{providerId}");

    if(!domainId)
        goto end;
    if(!providerId)
        goto end;


    // Path Params
    long sizeOfPathParams_domainId = strlen(domainId)+3 + strlen(providerId)+3 + sizeof("{ domainId }") - 1;
    if(domainId == NULL) {
        goto end;
    }
    char* localVarToReplace_domainId = malloc(sizeOfPathParams_domainId);
    sprintf(localVarToReplace_domainId, "{%s}", "domainId");

    localVarPath = strReplace(localVarPath, localVarToReplace_domainId, domainId);

    // Path Params
    long sizeOfPathParams_providerId = strlen(domainId)+3 + strlen(providerId)+3 + sizeof("{ providerId }") - 1;
    if(providerId == NULL) {
        goto end;
    }
    char* localVarToReplace_providerId = malloc(sizeOfPathParams_providerId);
    sprintf(localVarToReplace_providerId, "{%s}", "providerId");

    localVarPath = strReplace(localVarPath, localVarToReplace_providerId, providerId);


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
    //    printf("%s\n","Successfully deleted auth provider.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Authentication required.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Domain administrator permissions required.");
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
    free(localVarToReplace_domainId);
    free(localVarToReplace_providerId);

}

// Return all configured auth providers for a domain (including globally configured providers)
//
// **Required role:** Domain administrator.  Return all configured auth providers for a domain (including globally configured providers).
//
domain_auth_providers_list_t*
DomainAuthProvidersAPI_v3ListDomainAuthProviders(apiClient_t *apiClient, char *domainId, double *limit, double *offset)
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
    char *localVarPath = strdup("/v3/domain/{domainId}/auth");

    if(!domainId)
        goto end;


    // Path Params
    long sizeOfPathParams_domainId = strlen(domainId)+3 + sizeof("{ domainId }") - 1;
    if(domainId == NULL) {
        goto end;
    }
    char* localVarToReplace_domainId = malloc(sizeOfPathParams_domainId);
    sprintf(localVarToReplace_domainId, "{%s}", "domainId");

    localVarPath = strReplace(localVarPath, localVarToReplace_domainId, domainId);



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
    //    printf("%s\n","List of auth providers.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Domain administrator permissions required.");
    //}
    //nonprimitive not container
    domain_auth_providers_list_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DomainAuthProvidersAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = domain_auth_providers_list_parseFromJSON(DomainAuthProvidersAPIlocalVarJSON);
        cJSON_Delete(DomainAuthProvidersAPIlocalVarJSON);
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
    free(localVarToReplace_domainId);
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
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Partially update an auth provider for a domain
//
// **Required role:** Domain administrator.  Partially update an auth provider for a domain.
//
domain_auth_provider_response_t*
DomainAuthProvidersAPI_v3PatchDomainAuthProvider(apiClient_t *apiClient, char *domainId, char *providerId, patch_domain_auth_provider_body_t *patch_domain_auth_provider_body)
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
    char *localVarPath = strdup("/v3/domain/{domainId}/auth/{providerId}");

    if(!domainId)
        goto end;
    if(!providerId)
        goto end;


    // Path Params
    long sizeOfPathParams_domainId = strlen(domainId)+3 + strlen(providerId)+3 + sizeof("{ domainId }") - 1;
    if(domainId == NULL) {
        goto end;
    }
    char* localVarToReplace_domainId = malloc(sizeOfPathParams_domainId);
    sprintf(localVarToReplace_domainId, "{%s}", "domainId");

    localVarPath = strReplace(localVarPath, localVarToReplace_domainId, domainId);

    // Path Params
    long sizeOfPathParams_providerId = strlen(domainId)+3 + strlen(providerId)+3 + sizeof("{ providerId }") - 1;
    if(providerId == NULL) {
        goto end;
    }
    char* localVarToReplace_providerId = malloc(sizeOfPathParams_providerId);
    sprintf(localVarToReplace_providerId, "{%s}", "providerId");

    localVarPath = strReplace(localVarPath, localVarToReplace_providerId, providerId);



    // Body Param
    cJSON *localVarSingleItemJSON_patch_domain_auth_provider_body = NULL;
    if (patch_domain_auth_provider_body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_patch_domain_auth_provider_body = patch_domain_auth_provider_body_convertToJSON(patch_domain_auth_provider_body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_patch_domain_auth_provider_body);
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
    //    printf("%s\n","Updated auth provider.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Invalid request body.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Domain administrator permissions required.");
    //}
    //nonprimitive not container
    domain_auth_provider_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DomainAuthProvidersAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = domain_auth_provider_response_parseFromJSON(DomainAuthProvidersAPIlocalVarJSON);
        cJSON_Delete(DomainAuthProvidersAPIlocalVarJSON);
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
    free(localVarToReplace_domainId);
    free(localVarToReplace_providerId);
    if (localVarSingleItemJSON_patch_domain_auth_provider_body) {
        cJSON_Delete(localVarSingleItemJSON_patch_domain_auth_provider_body);
        localVarSingleItemJSON_patch_domain_auth_provider_body = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Update an auth provider for a domain
//
// **Required role:** Domain administrator.  Update an auth provider for a domain.
//
domain_auth_provider_response_t*
DomainAuthProvidersAPI_v3UpdateDomainAuthProvider(apiClient_t *apiClient, char *domainId, char *providerId, create_domain_auth_provider_body_t *create_domain_auth_provider_body)
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
    char *localVarPath = strdup("/v3/domain/{domainId}/auth/{providerId}");

    if(!domainId)
        goto end;
    if(!providerId)
        goto end;


    // Path Params
    long sizeOfPathParams_domainId = strlen(domainId)+3 + strlen(providerId)+3 + sizeof("{ domainId }") - 1;
    if(domainId == NULL) {
        goto end;
    }
    char* localVarToReplace_domainId = malloc(sizeOfPathParams_domainId);
    sprintf(localVarToReplace_domainId, "{%s}", "domainId");

    localVarPath = strReplace(localVarPath, localVarToReplace_domainId, domainId);

    // Path Params
    long sizeOfPathParams_providerId = strlen(domainId)+3 + strlen(providerId)+3 + sizeof("{ providerId }") - 1;
    if(providerId == NULL) {
        goto end;
    }
    char* localVarToReplace_providerId = malloc(sizeOfPathParams_providerId);
    sprintf(localVarToReplace_providerId, "{%s}", "providerId");

    localVarPath = strReplace(localVarPath, localVarToReplace_providerId, providerId);



    // Body Param
    cJSON *localVarSingleItemJSON_create_domain_auth_provider_body = NULL;
    if (create_domain_auth_provider_body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_create_domain_auth_provider_body = create_domain_auth_provider_body_convertToJSON(create_domain_auth_provider_body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_create_domain_auth_provider_body);
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
    //    printf("%s\n","Updated auth provider.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Invalid request body.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Domain administrator permissions required.");
    //}
    //nonprimitive not container
    domain_auth_provider_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DomainAuthProvidersAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = domain_auth_provider_response_parseFromJSON(DomainAuthProvidersAPIlocalVarJSON);
        cJSON_Delete(DomainAuthProvidersAPIlocalVarJSON);
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
    free(localVarToReplace_domainId);
    free(localVarToReplace_providerId);
    if (localVarSingleItemJSON_create_domain_auth_provider_body) {
        cJSON_Delete(localVarSingleItemJSON_create_domain_auth_provider_body);
        localVarSingleItemJSON_create_domain_auth_provider_body = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

