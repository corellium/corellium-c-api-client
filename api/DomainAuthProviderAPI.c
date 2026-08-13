#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "DomainAuthProviderAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096


// Create a new auth provider for a domain
//
domain_auth_provider_response_v1_t*
DomainAuthProviderAPI_v1CreateDomainAuthProvider(apiClient_t *apiClient, char *domainId, domain_auth_provider_request_t *domain_auth_provider_request)
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
    char *localVarPath = strdup("/v1/domain/{domainId}/auth");

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
    cJSON *localVarSingleItemJSON_domain_auth_provider_request = NULL;
    if (domain_auth_provider_request != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_domain_auth_provider_request = domain_auth_provider_request_convertToJSON(domain_auth_provider_request);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_domain_auth_provider_request);
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
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Forbidden");
    //}
    //nonprimitive not container
    domain_auth_provider_response_v1_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DomainAuthProviderAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = domain_auth_provider_response_v1_parseFromJSON(DomainAuthProviderAPIlocalVarJSON);
        cJSON_Delete(DomainAuthProviderAPIlocalVarJSON);
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
    if (localVarSingleItemJSON_domain_auth_provider_request) {
        cJSON_Delete(localVarSingleItemJSON_domain_auth_provider_request);
        localVarSingleItemJSON_domain_auth_provider_request = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Delete an auth provider from a domain
//
void
DomainAuthProviderAPI_v1DeleteDomainAuthProvider(apiClient_t *apiClient, char *domainId, char *providerId)
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
    char *localVarPath = strdup("/v1/domain/{domainId}/auth/{providerId}");

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
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","OK");
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
    free(localVarToReplace_domainId);
    free(localVarToReplace_providerId);

}

// Return all configured auth providers for a domain (including globally configured providers)
//
list_t*
DomainAuthProviderAPI_v1GetDomainAuthProviders(apiClient_t *apiClient, char *domainId)
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
    char *localVarPath = strdup("/v1/domain/{domainId}/auth");

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
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Forbidden");
    //}
    list_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DomainAuthProviderAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        if(!cJSON_IsArray(DomainAuthProviderAPIlocalVarJSON)) {
            return 0;//nonprimitive container
        }
        elementToReturn = list_createList();
        cJSON *VarJSON;
        cJSON_ArrayForEach(VarJSON, DomainAuthProviderAPIlocalVarJSON)
        {
            if(!cJSON_IsObject(VarJSON))
            {
               // return 0;
            }
            char *localVarJSONToChar = cJSON_Print(VarJSON);
            list_addElement(elementToReturn , localVarJSONToChar);
        }

        cJSON_Delete( DomainAuthProviderAPIlocalVarJSON);
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
    free(localVarToReplace_domainId);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Update an auth provider for a domain
//
domain_auth_provider_response_v1_t*
DomainAuthProviderAPI_v1UpdateDomainAuthProvider(apiClient_t *apiClient, char *domainId, char *providerId, domain_auth_provider_request_t *domain_auth_provider_request)
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
    char *localVarPath = strdup("/v1/domain/{domainId}/auth/{providerId}");

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
    cJSON *localVarSingleItemJSON_domain_auth_provider_request = NULL;
    if (domain_auth_provider_request != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_domain_auth_provider_request = domain_auth_provider_request_convertToJSON(domain_auth_provider_request);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_domain_auth_provider_request);
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
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Forbidden");
    //}
    //nonprimitive not container
    domain_auth_provider_response_v1_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DomainAuthProviderAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = domain_auth_provider_response_v1_parseFromJSON(DomainAuthProviderAPIlocalVarJSON);
        cJSON_Delete(DomainAuthProviderAPIlocalVarJSON);
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
    if (localVarSingleItemJSON_domain_auth_provider_request) {
        cJSON_Delete(localVarSingleItemJSON_domain_auth_provider_request);
        localVarSingleItemJSON_domain_auth_provider_request = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

