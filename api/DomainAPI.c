#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "DomainAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096


// Create a welcome message for a domain
//
// Creates a new welcome message for the authenticated user's domain admin, or updates the existing one. The message is sanitized to prevent XSS.
//
domain_welcome_message_response_t*
DomainAPI_v3CreateDomainWelcomeMessage(apiClient_t *apiClient, set_domain_welcome_message_body_t *set_domain_welcome_message_body)
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
    char *localVarPath = strdup("/v3/domain/welcome");





    // Body Param
    cJSON *localVarSingleItemJSON_set_domain_welcome_message_body = NULL;
    if (set_domain_welcome_message_body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_set_domain_welcome_message_body = set_domain_welcome_message_body_convertToJSON(set_domain_welcome_message_body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_set_domain_welcome_message_body);
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
    //    printf("%s\n","Welcome message created.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Validation error (e.g. empty message).");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Authentication required.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Permission denied.");
    //}
    //nonprimitive not container
    domain_welcome_message_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DomainAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = domain_welcome_message_response_parseFromJSON(DomainAPIlocalVarJSON);
        cJSON_Delete(DomainAPIlocalVarJSON);
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
    if (localVarSingleItemJSON_set_domain_welcome_message_body) {
        cJSON_Delete(localVarSingleItemJSON_set_domain_welcome_message_body);
        localVarSingleItemJSON_set_domain_welcome_message_body = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Delete the welcome message for the authenticated user's domain
//
void
DomainAPI_v3DeleteDomainWelcomeMessage(apiClient_t *apiClient)
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
    char *localVarPath = strdup("/v3/domain/welcome");




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
    //    printf("%s\n","Welcome message deleted.");
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
    //    printf("%s\n","No welcome message exists for this domain.");
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

}

// Get a domain-level image upload
//
binary_t*
DomainAPI_v3GetDomainImageUpload(apiClient_t *apiClient, char *type, char *imageId, char *name, double *resumableChunkNumber)
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
    char *localVarPath = strdup("/v3/domain/image-upload/{type}/{imageId}/{name}");

    if(!type)
        goto end;
    if(!imageId)
        goto end;
    if(!name)
        goto end;


    // Path Params
    long sizeOfPathParams_type = strlen(type)+3 + strlen(imageId)+3 + strlen(name)+3 + sizeof("{ type }") - 1;
    if(type == NULL) {
        goto end;
    }
    char* localVarToReplace_type = malloc(sizeOfPathParams_type);
    sprintf(localVarToReplace_type, "{%s}", "type");

    localVarPath = strReplace(localVarPath, localVarToReplace_type, type);

    // Path Params
    long sizeOfPathParams_imageId = strlen(type)+3 + strlen(imageId)+3 + strlen(name)+3 + sizeof("{ imageId }") - 1;
    if(imageId == NULL) {
        goto end;
    }
    char* localVarToReplace_imageId = malloc(sizeOfPathParams_imageId);
    sprintf(localVarToReplace_imageId, "{%s}", "imageId");

    localVarPath = strReplace(localVarPath, localVarToReplace_imageId, imageId);

    // Path Params
    long sizeOfPathParams_name = strlen(type)+3 + strlen(imageId)+3 + strlen(name)+3 + sizeof("{ name }") - 1;
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);



    // query parameters
    char *keyQuery_resumableChunkNumber = NULL;
    char * valueQuery_resumableChunkNumber = NULL;
    keyValuePair_t *keyPairQuery_resumableChunkNumber = 0;
    if (resumableChunkNumber)
    {
        keyQuery_resumableChunkNumber = strdup("resumableChunkNumber");
        valueQuery_resumableChunkNumber = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_resumableChunkNumber, MAX_NUMBER_LENGTH, "%d", *resumableChunkNumber);
        keyPairQuery_resumableChunkNumber = keyValuePair_create(keyQuery_resumableChunkNumber, valueQuery_resumableChunkNumber);
        list_addElement(localVarQueryParameters,keyPairQuery_resumableChunkNumber);
    }
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
    //    printf("%s\n","Image file contents (binary stream) or image metadata (JSON). When resumableChunkNumber is present and the chunk exists, returns an empty JSON object.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 204) {
    //    printf("%s\n","Chunk not yet uploaded. Client should upload the chunk.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Permission denied.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","No image matching the given parameters.");
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
    list_freeList(localVarQueryParameters);
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_type);
    free(localVarToReplace_imageId);
    free(localVarToReplace_name);
    if(keyQuery_resumableChunkNumber){
        free(keyQuery_resumableChunkNumber);
        keyQuery_resumableChunkNumber = NULL;
    }
    if(valueQuery_resumableChunkNumber){
        free(valueQuery_resumableChunkNumber);
        valueQuery_resumableChunkNumber = NULL;
    }
    if(keyPairQuery_resumableChunkNumber){
        keyValuePair_free(keyPairQuery_resumableChunkNumber);
        keyPairQuery_resumableChunkNumber = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Get the welcome message for the authenticated user's domain
//
// Retrieves the welcome message for the domain.
//
domain_welcome_message_response_t*
DomainAPI_v3GetDomainWelcomeMessage(apiClient_t *apiClient)
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
    char *localVarPath = strdup("/v3/domain/welcome");




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
    //    printf("%s\n","Domain welcome message.");
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
    //    printf("%s\n","No welcome message exists for this domain.");
    //}
    //nonprimitive not container
    domain_welcome_message_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DomainAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = domain_welcome_message_response_parseFromJSON(DomainAPIlocalVarJSON);
        cJSON_Delete(DomainAPIlocalVarJSON);
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

// Update a welcome message for a domain
//
// Updates a new welcome message for the authenticated user's domain admin, or updates the existing one. The message is sanitized to prevent XSS.
//
domain_welcome_message_response_t*
DomainAPI_v3PatchDomainWelcomeMessage(apiClient_t *apiClient, patch_domain_welcome_message_body_t *patch_domain_welcome_message_body)
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
    char *localVarPath = strdup("/v3/domain/welcome");





    // Body Param
    cJSON *localVarSingleItemJSON_patch_domain_welcome_message_body = NULL;
    if (patch_domain_welcome_message_body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_patch_domain_welcome_message_body = patch_domain_welcome_message_body_convertToJSON(patch_domain_welcome_message_body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_patch_domain_welcome_message_body);
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
    //    printf("%s\n","Updated welcome message.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Validation error (e.g. empty message or no fields provided).");
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
    //    printf("%s\n","No welcome message exists for this domain.");
    //}
    //nonprimitive not container
    domain_welcome_message_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DomainAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = domain_welcome_message_response_parseFromJSON(DomainAPIlocalVarJSON);
        cJSON_Delete(DomainAPIlocalVarJSON);
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
    if (localVarSingleItemJSON_patch_domain_welcome_message_body) {
        cJSON_Delete(localVarSingleItemJSON_patch_domain_welcome_message_body);
        localVarSingleItemJSON_patch_domain_welcome_message_body = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Domain-wide file upload
//
void
DomainAPI_v3UploadDomainImage(apiClient_t *apiClient, char *type, char *imageId, char *name, char *flavor, double *resumableChunkNumber, double *resumableChunkSize, double *resumableCurrentChunkSize, double *resumableTotalSize, double *resumableTotalChunks, binary_t* body)
{
    list_t    *localVarQueryParameters = list_createList();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/v3/domain/image-upload/{type}/{imageId}/{name}");

    if(!type)
        goto end;
    if(!imageId)
        goto end;
    if(!name)
        goto end;


    // Path Params
    long sizeOfPathParams_type = strlen(type)+3 + strlen(imageId)+3 + strlen(name)+3 + sizeof("{ type }") - 1;
    if(type == NULL) {
        goto end;
    }
    char* localVarToReplace_type = malloc(sizeOfPathParams_type);
    sprintf(localVarToReplace_type, "{%s}", "type");

    localVarPath = strReplace(localVarPath, localVarToReplace_type, type);

    // Path Params
    long sizeOfPathParams_imageId = strlen(type)+3 + strlen(imageId)+3 + strlen(name)+3 + sizeof("{ imageId }") - 1;
    if(imageId == NULL) {
        goto end;
    }
    char* localVarToReplace_imageId = malloc(sizeOfPathParams_imageId);
    sprintf(localVarToReplace_imageId, "{%s}", "imageId");

    localVarPath = strReplace(localVarPath, localVarToReplace_imageId, imageId);

    // Path Params
    long sizeOfPathParams_name = strlen(type)+3 + strlen(imageId)+3 + strlen(name)+3 + sizeof("{ name }") - 1;
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);



    // query parameters
    char *keyQuery_flavor = NULL;
    char * valueQuery_flavor = NULL;
    keyValuePair_t *keyPairQuery_flavor = 0;
    if (flavor)
    {
        keyQuery_flavor = strdup("flavor");
        valueQuery_flavor = strdup((flavor));
        keyPairQuery_flavor = keyValuePair_create(keyQuery_flavor, valueQuery_flavor);
        list_addElement(localVarQueryParameters,keyPairQuery_flavor);
    }

    // query parameters
    char *keyQuery_resumableChunkNumber = NULL;
    char * valueQuery_resumableChunkNumber = NULL;
    keyValuePair_t *keyPairQuery_resumableChunkNumber = 0;
    if (resumableChunkNumber)
    {
        keyQuery_resumableChunkNumber = strdup("resumableChunkNumber");
        valueQuery_resumableChunkNumber = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_resumableChunkNumber, MAX_NUMBER_LENGTH, "%d", *resumableChunkNumber);
        keyPairQuery_resumableChunkNumber = keyValuePair_create(keyQuery_resumableChunkNumber, valueQuery_resumableChunkNumber);
        list_addElement(localVarQueryParameters,keyPairQuery_resumableChunkNumber);
    }

    // query parameters
    char *keyQuery_resumableChunkSize = NULL;
    char * valueQuery_resumableChunkSize = NULL;
    keyValuePair_t *keyPairQuery_resumableChunkSize = 0;
    if (resumableChunkSize)
    {
        keyQuery_resumableChunkSize = strdup("resumableChunkSize");
        valueQuery_resumableChunkSize = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_resumableChunkSize, MAX_NUMBER_LENGTH, "%d", *resumableChunkSize);
        keyPairQuery_resumableChunkSize = keyValuePair_create(keyQuery_resumableChunkSize, valueQuery_resumableChunkSize);
        list_addElement(localVarQueryParameters,keyPairQuery_resumableChunkSize);
    }

    // query parameters
    char *keyQuery_resumableCurrentChunkSize = NULL;
    char * valueQuery_resumableCurrentChunkSize = NULL;
    keyValuePair_t *keyPairQuery_resumableCurrentChunkSize = 0;
    if (resumableCurrentChunkSize)
    {
        keyQuery_resumableCurrentChunkSize = strdup("resumableCurrentChunkSize");
        valueQuery_resumableCurrentChunkSize = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_resumableCurrentChunkSize, MAX_NUMBER_LENGTH, "%d", *resumableCurrentChunkSize);
        keyPairQuery_resumableCurrentChunkSize = keyValuePair_create(keyQuery_resumableCurrentChunkSize, valueQuery_resumableCurrentChunkSize);
        list_addElement(localVarQueryParameters,keyPairQuery_resumableCurrentChunkSize);
    }

    // query parameters
    char *keyQuery_resumableTotalSize = NULL;
    char * valueQuery_resumableTotalSize = NULL;
    keyValuePair_t *keyPairQuery_resumableTotalSize = 0;
    if (resumableTotalSize)
    {
        keyQuery_resumableTotalSize = strdup("resumableTotalSize");
        valueQuery_resumableTotalSize = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_resumableTotalSize, MAX_NUMBER_LENGTH, "%d", *resumableTotalSize);
        keyPairQuery_resumableTotalSize = keyValuePair_create(keyQuery_resumableTotalSize, valueQuery_resumableTotalSize);
        list_addElement(localVarQueryParameters,keyPairQuery_resumableTotalSize);
    }

    // query parameters
    char *keyQuery_resumableTotalChunks = NULL;
    char * valueQuery_resumableTotalChunks = NULL;
    keyValuePair_t *keyPairQuery_resumableTotalChunks = 0;
    if (resumableTotalChunks)
    {
        keyQuery_resumableTotalChunks = strdup("resumableTotalChunks");
        valueQuery_resumableTotalChunks = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_resumableTotalChunks, MAX_NUMBER_LENGTH, "%d", *resumableTotalChunks);
        keyPairQuery_resumableTotalChunks = keyValuePair_create(keyQuery_resumableTotalChunks, valueQuery_resumableTotalChunks);
        list_addElement(localVarQueryParameters,keyPairQuery_resumableTotalChunks);
    }

    // Body Param
    localVarBodyParameters = malloc(body->len);
    memcpy(localVarBodyParameters, body->data, body->len);
    localVarBodyLength = body->len;
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/octet-stream"); //consumes
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
    //    printf("%s\n","File uploaded.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","File missing or unable to read file.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Permission denied.");
    //}
    //No return type
end:
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    list_freeList(localVarQueryParameters);
    
    
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    free(localVarToReplace_type);
    free(localVarToReplace_imageId);
    free(localVarToReplace_name);
    free(localVarBodyParameters);
    if(keyQuery_flavor){
        free(keyQuery_flavor);
        keyQuery_flavor = NULL;
    }
    if(valueQuery_flavor){
        free(valueQuery_flavor);
        valueQuery_flavor = NULL;
    }
    if(keyPairQuery_flavor){
        keyValuePair_free(keyPairQuery_flavor);
        keyPairQuery_flavor = NULL;
    }
    if(keyQuery_flavor){
        free(keyQuery_flavor);
        keyQuery_flavor = NULL;
    }
    if(keyPairQuery_flavor){
        keyValuePair_free(keyPairQuery_flavor);
        keyPairQuery_flavor = NULL;
    }

}

