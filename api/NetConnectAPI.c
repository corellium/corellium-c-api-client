#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "NetConnectAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096


// Create a new Network Connection
//
// You must have the domain administrator role to create a network connection. VLAN networks are only supported in bridged networking mode.
//
network_connection_t*
NetConnectAPI_v1CreateNetworkConnection(apiClient_t *apiClient, create_network_connection_options_t *create_network_connection_options)
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
    char *localVarPath = strdup("/v1/network/connections");





    // Body Param
    cJSON *localVarSingleItemJSON_create_network_connection_options = NULL;
    if (create_network_connection_options != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_create_network_connection_options = create_network_connection_options_convertToJSON(create_network_connection_options);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_create_network_connection_options);
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
    //    printf("%s\n","Success");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Forbidden");
    //}
    //nonprimitive not container
    network_connection_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *NetConnectAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = network_connection_parseFromJSON(NetConnectAPIlocalVarJSON);
        cJSON_Delete(NetConnectAPIlocalVarJSON);
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
    if (localVarSingleItemJSON_create_network_connection_options) {
        cJSON_Delete(localVarSingleItemJSON_create_network_connection_options);
        localVarSingleItemJSON_create_network_connection_options = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Delete an existing Network Connection
//
// You must have the domain administrator role to delete a network connection.
//
void
NetConnectAPI_v1DeleteNetworkConnection(apiClient_t *apiClient, char *id, delete_network_connection_options_t *delete_network_connection_options)
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
    char *localVarPath = strdup("/v1/network/connections/{id}");

    if(!id)
        goto end;


    // Path Params
    long sizeOfPathParams_id = strlen(id)+3 + sizeof("{ id }") - 1;
    if(id == NULL) {
        goto end;
    }
    char* localVarToReplace_id = malloc(sizeOfPathParams_id);
    sprintf(localVarToReplace_id, "{%s}", "id");

    localVarPath = strReplace(localVarPath, localVarToReplace_id, id);



    // Body Param
    cJSON *localVarSingleItemJSON_delete_network_connection_options = NULL;
    if (delete_network_connection_options != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_delete_network_connection_options = delete_network_connection_options_convertToJSON(delete_network_connection_options);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_delete_network_connection_options);
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
                    "DELETE");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 204) {
    //    printf("%s\n","Success");
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
    free(localVarToReplace_id);
    if (localVarSingleItemJSON_delete_network_connection_options) {
        cJSON_Delete(localVarSingleItemJSON_delete_network_connection_options);
        localVarSingleItemJSON_delete_network_connection_options = NULL;
    }
    free(localVarBodyParameters);

}

// Return the configuration and per project statuses for a single network provider.
//
// You must have the domain administrator or project administrator role to fetch a network connection.
//
network_connection_t*
NetConnectAPI_v1GetNetworkConnection(apiClient_t *apiClient, char *id)
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
    char *localVarPath = strdup("/v1/network/connections/{id}");

    if(!id)
        goto end;


    // Path Params
    long sizeOfPathParams_id = strlen(id)+3 + sizeof("{ id }") - 1;
    if(id == NULL) {
        goto end;
    }
    char* localVarToReplace_id = malloc(sizeOfPathParams_id);
    sprintf(localVarToReplace_id, "{%s}", "id");

    localVarPath = strReplace(localVarPath, localVarToReplace_id, id);


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
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Not Found");
    //}
    //nonprimitive not container
    network_connection_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *NetConnectAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = network_connection_parseFromJSON(NetConnectAPIlocalVarJSON);
        cJSON_Delete(NetConnectAPIlocalVarJSON);
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
    free(localVarToReplace_id);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// List available network connections
//
// You must have the domain administrator or project administrator role to list network connections.
//
network_connection_pagination_result_t*
NetConnectAPI_v1ListNetworkConnections(apiClient_t *apiClient, double limit, double offset)
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
    char *localVarPath = strdup("/v1/network/connections");





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
    //    printf("%s\n","Success");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Forbidden");
    //}
    //nonprimitive not container
    network_connection_pagination_result_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *NetConnectAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = network_connection_pagination_result_parseFromJSON(NetConnectAPIlocalVarJSON);
        cJSON_Delete(NetConnectAPIlocalVarJSON);
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

// List available physical network interfaces
//
// Lists available physical network interfaces that can be used for VLAN configuration. You must have the domain administrator role to list network interfaces.
//
list_t*
NetConnectAPI_v1ListNetworkInterfaces(apiClient_t *apiClient)
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
    char *localVarPath = strdup("/v1/network/interfaces");




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
    //    printf("%s\n","Success");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Forbidden");
    //}
    //primitive return type not simple
    list_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *localVarJSON = cJSON_Parse(apiClient->dataReceived);
        cJSON *VarJSON;
        elementToReturn = list_createList();
        cJSON_ArrayForEach(VarJSON, localVarJSON){
            keyValuePair_t *keyPair = keyValuePair_create(strdup(VarJSON->string), cJSON_Print(VarJSON));
            list_addElement(elementToReturn, keyPair);
        }
        cJSON_Delete(localVarJSON);
    }

    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// List available network providers
//
// Provides a list of registered network providers to be used when [creating network connections](#post-/v1/network/connections). You must have the domain administrator role to list network providers.
//
network_connection_provider_pagination_result_t*
NetConnectAPI_v1ListNetworkProviders(apiClient_t *apiClient)
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
    char *localVarPath = strdup("/v1/network/providers");




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
    //    printf("%s\n","Success");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Forbidden");
    //}
    //nonprimitive not container
    network_connection_provider_pagination_result_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *NetConnectAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = network_connection_provider_pagination_result_parseFromJSON(NetConnectAPIlocalVarJSON);
        cJSON_Delete(NetConnectAPIlocalVarJSON);
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
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Update Network Connection (partial)
//
// Only updates the specified attributes. You must have the domain administrator role to update a network connection.
//
network_connection_t*
NetConnectAPI_v1PartialUpdateNetworkConnection(apiClient_t *apiClient, char *id, update_network_connection_options_t *update_network_connection_options)
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
    char *localVarPath = strdup("/v1/network/connections/{id}");

    if(!id)
        goto end;


    // Path Params
    long sizeOfPathParams_id = strlen(id)+3 + sizeof("{ id }") - 1;
    if(id == NULL) {
        goto end;
    }
    char* localVarToReplace_id = malloc(sizeOfPathParams_id);
    sprintf(localVarToReplace_id, "{%s}", "id");

    localVarPath = strReplace(localVarPath, localVarToReplace_id, id);



    // Body Param
    cJSON *localVarSingleItemJSON_update_network_connection_options = NULL;
    if (update_network_connection_options != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_update_network_connection_options = update_network_connection_options_convertToJSON(update_network_connection_options);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_update_network_connection_options);
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
    //    printf("%s\n","Success");
    //}
    //nonprimitive not container
    network_connection_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *NetConnectAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = network_connection_parseFromJSON(NetConnectAPIlocalVarJSON);
        cJSON_Delete(NetConnectAPIlocalVarJSON);
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
    free(localVarToReplace_id);
    if (localVarSingleItemJSON_update_network_connection_options) {
        cJSON_Delete(localVarSingleItemJSON_update_network_connection_options);
        localVarSingleItemJSON_update_network_connection_options = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Update Network Connection
//
// You must have the domain administrator role to update a network connection.
//
network_connection_t*
NetConnectAPI_v1UpdateNetworkConnection(apiClient_t *apiClient, char *id, update_network_connection_options_t *update_network_connection_options)
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
    char *localVarPath = strdup("/v1/network/connections/{id}");

    if(!id)
        goto end;


    // Path Params
    long sizeOfPathParams_id = strlen(id)+3 + sizeof("{ id }") - 1;
    if(id == NULL) {
        goto end;
    }
    char* localVarToReplace_id = malloc(sizeOfPathParams_id);
    sprintf(localVarToReplace_id, "{%s}", "id");

    localVarPath = strReplace(localVarPath, localVarToReplace_id, id);



    // Body Param
    cJSON *localVarSingleItemJSON_update_network_connection_options = NULL;
    if (update_network_connection_options != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_update_network_connection_options = update_network_connection_options_convertToJSON(update_network_connection_options);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_update_network_connection_options);
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
    //    printf("%s\n","Success");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Forbidden");
    //}
    //nonprimitive not container
    network_connection_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *NetConnectAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = network_connection_parseFromJSON(NetConnectAPIlocalVarJSON);
        cJSON_Delete(NetConnectAPIlocalVarJSON);
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
    free(localVarToReplace_id);
    if (localVarSingleItemJSON_update_network_connection_options) {
        cJSON_Delete(localVarSingleItemJSON_update_network_connection_options);
        localVarSingleItemJSON_update_network_connection_options = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

