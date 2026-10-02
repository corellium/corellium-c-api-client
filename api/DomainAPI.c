#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "DomainAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096


// Create a welcome message for a domain
//
// **Required role:** Domain administrator.  Creates a new welcome message for the authenticated user's domain admin, or updates the existing one. The message is sanitized to prevent XSS.
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
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Domain administrator permissions required. Signed in, but not allowed to do this: you lack the required role, have no access to the project, or your license does not include the feature.");
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
// **Required role:** Domain administrator.  Delete the welcome message for the authenticated user's domain.  Deletes are idempotent: a domain with no welcome message is a successful no-op that still returns 204, and repeated calls return 204 as well. A 404 means the request path did not match a delete route, not that the target was missing.
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
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Domain administrator permissions required. Signed in, but not allowed to do this: you lack the required role, have no access to the project, or your license does not include the feature.");
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

// Get image upload status
//
// **Required role:** Domain administrator on on-site deployments; cloud administrator on cloud deployments.  Checks the progress of a chunked upload made with `v3PutDomainImageUpload`, or downloads the finished file. With chunk parameters (`resumableChunkNumber` and friends) it returns 200 if that chunk is already stored and 204 if it still needs to be sent; without them it downloads the image file.
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
    //    printf("%s\n","An empty JSON object when a probed chunk is already stored, the image bytes when the file is stored locally, or the image metadata when no file has been stored yet.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 204) {
    //    printf("%s\n","The probed chunk is not stored yet and still needs to be uploaded.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 302) {
    //    printf("%s\n","The image is stored in S3; follow the Location header to download it.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","The image identifier is invalid or the image record is missing.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Domain administrator permissions required on on-site deployments; cloud administrator permissions required on cloud deployments. Signed in, but not allowed to do this: you lack the required role, have no access to the project, or your license does not include the feature.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","No image with the given identifier.");
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
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Signed in, but not allowed to do this: you lack the required role, have no access to the project, or your license does not include the feature.");
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

// List domain-level firmware images
//
// **Required role:** Domain administrator.  Lists the firmware images uploaded at domain level (not in a project or instance), one entry per device model. Requires a domain administrator. Use it to find the `imageId` of a domain firmware upload, for example to delete it with `DELETE /v3/images/{imageId}`. These images also appear in `GET /v3/models/{model}/software` for the matching model.
//
domain_software_list_t*
DomainAPI_v3ListDomainSoftware(apiClient_t *apiClient, double *limit, double *offset)
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
    char *localVarPath = strdup("/v3/domain/software");





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
    //    printf("%s\n","Paginated list of domain firmware uploads.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Invalid limit or offset.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Domain administrator permissions required. Signed in, but not allowed to do this: you lack the required role, have no access to the project, or your license does not include the feature.");
    //}
    //nonprimitive not container
    domain_software_list_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DomainAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = domain_software_list_parseFromJSON(DomainAPIlocalVarJSON);
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
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Update a welcome message for a domain
//
// **Required role:** Domain administrator.  Updates a new welcome message for the authenticated user's domain admin, or updates the existing one. The message is sanitized to prevent XSS.
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
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Domain administrator permissions required. Signed in, but not allowed to do this: you lack the required role, have no access to the project, or your license does not include the feature.");
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

// Upload image chunk
//
// **Required role:** Domain administrator on on-site deployments; cloud administrator on cloud deployments.  Uploads one chunk of a file as a domain-level image: one that belongs to no project or instance and is available across your domain. Requires a domain administrator (on-site) or cloud administrator. Works like `v3PutProjectImageUpload`: you choose the image ID (a new random UUID), the record is created on the first chunk, and `type` and `name` in the path set the image type and name. A domain-level `fw` image is offered as a choice when anyone in the domain creates a device of the matching model, without an install step. The result is the same as `POST /v3/images` with no `projectId` or `instanceId` followed by `PUT /v3/images/{imageId}/file`, which applies the same administrator rule to chunk uploads.
//
object_t*
DomainAPI_v3PutDomainImageUpload(apiClient_t *apiClient, char *type, char *imageId, char *name, binary_t* body, double *resumableChunkNumber, double *resumableChunkSize, double *resumableCurrentChunkSize, double *resumableTotalSize, double *resumableTotalChunks, char *corelliumChecksum, char *flavor, char *x_corellium_image_encoding, int *x_corellium_image_encapsulated, double *x_corellium_total_file_size, char *x_corellium_image_password)
{
    list_t    *localVarQueryParameters = list_createList();
    list_t    *localVarHeaderParameters = list_createList();
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



    // header parameters
    char *keyHeader_x_corellium_image_encoding = NULL;
    char * valueHeader_x_corellium_image_encoding = 0;
    keyValuePair_t *keyPairHeader_x_corellium_image_encoding = 0;
    if (x_corellium_image_encoding) {
        keyHeader_x_corellium_image_encoding = strdup("x-corellium-image-encoding");
        valueHeader_x_corellium_image_encoding = strdup((x_corellium_image_encoding));
        keyPairHeader_x_corellium_image_encoding = keyValuePair_create(keyHeader_x_corellium_image_encoding, valueHeader_x_corellium_image_encoding);
        list_addElement(localVarHeaderParameters,keyPairHeader_x_corellium_image_encoding);
    }


    // header parameters
    char *keyHeader_x_corellium_image_encapsulated = NULL;
    int valueHeader_x_corellium_image_encapsulated = 0;
    keyValuePair_t *keyPairHeader_x_corellium_image_encapsulated = 0;
    if (x_corellium_image_encapsulated) {
        keyHeader_x_corellium_image_encapsulated = strdup("x-corellium-image-encapsulated");
        valueHeader_x_corellium_image_encapsulated = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueHeader_x_corellium_image_encapsulated, MAX_NUMBER_LENGTH, "%d", *x_corellium_image_encapsulated);
        keyPairHeader_x_corellium_image_encapsulated = keyValuePair_create(keyHeader_x_corellium_image_encapsulated, &valueHeader_x_corellium_image_encapsulated);
        list_addElement(localVarHeaderParameters,keyPairHeader_x_corellium_image_encapsulated);
    }


    // header parameters
    char *keyHeader_x_corellium_total_file_size = NULL;
    double valueHeader_x_corellium_total_file_size = 0;
    keyValuePair_t *keyPairHeader_x_corellium_total_file_size = 0;
    if (x_corellium_total_file_size) {
        keyHeader_x_corellium_total_file_size = strdup("x-corellium-total-file-size");
        valueHeader_x_corellium_total_file_size = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueHeader_x_corellium_total_file_size, MAX_NUMBER_LENGTH, "%d", *x_corellium_total_file_size);
        keyPairHeader_x_corellium_total_file_size = keyValuePair_create(keyHeader_x_corellium_total_file_size, &valueHeader_x_corellium_total_file_size);
        list_addElement(localVarHeaderParameters,keyPairHeader_x_corellium_total_file_size);
    }


    // header parameters
    char *keyHeader_x_corellium_image_password = NULL;
    char * valueHeader_x_corellium_image_password = 0;
    keyValuePair_t *keyPairHeader_x_corellium_image_password = 0;
    if (x_corellium_image_password) {
        keyHeader_x_corellium_image_password = strdup("x-corellium-image-password");
        valueHeader_x_corellium_image_password = strdup((x_corellium_image_password));
        keyPairHeader_x_corellium_image_password = keyValuePair_create(keyHeader_x_corellium_image_password, valueHeader_x_corellium_image_password);
        list_addElement(localVarHeaderParameters,keyPairHeader_x_corellium_image_password);
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

    // query parameters
    char *keyQuery_corelliumChecksum = NULL;
    char * valueQuery_corelliumChecksum = NULL;
    keyValuePair_t *keyPairQuery_corelliumChecksum = 0;
    if (corelliumChecksum)
    {
        keyQuery_corelliumChecksum = strdup("corelliumChecksum");
        valueQuery_corelliumChecksum = strdup((corelliumChecksum));
        keyPairQuery_corelliumChecksum = keyValuePair_create(keyQuery_corelliumChecksum, valueQuery_corelliumChecksum);
        list_addElement(localVarQueryParameters,keyPairQuery_corelliumChecksum);
    }

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
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","Chunk stored. The body is an empty JSON object. Send the next chunk; the image is finished when the last chunk arrives.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Invalid chunk or upload parameters, unreadable body, or a missing/mismatched corelliumChecksum for a firmware upload.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Domain administrator permissions required on on-site deployments; cloud administrator permissions required on cloud deployments. Signed in, but not allowed to do this: you lack the required role, have no access to the project, or your license does not include the feature.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","No image with the given identifier.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 507) {
    //    printf("%s\n","The image pool does not have enough space for this upload.");
    //}
    //nonprimitive not container
    object_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DomainAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = object_parseFromJSON(DomainAPIlocalVarJSON);
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
    list_freeList(localVarQueryParameters);
    list_freeList(localVarHeaderParameters);
    
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    free(localVarToReplace_type);
    free(localVarToReplace_imageId);
    free(localVarToReplace_name);
    if (keyHeader_x_corellium_image_encoding) {
        free(keyHeader_x_corellium_image_encoding);
        keyHeader_x_corellium_image_encoding = NULL;
    }
    if (valueHeader_x_corellium_image_encoding) {
        free(valueHeader_x_corellium_image_encoding);
        valueHeader_x_corellium_image_encoding = NULL;
    }
    free(keyPairHeader_x_corellium_image_encoding);
    if (keyHeader_x_corellium_image_encapsulated) {
        free(keyHeader_x_corellium_image_encapsulated);
        keyHeader_x_corellium_image_encapsulated = NULL;
    }
    free(keyPairHeader_x_corellium_image_encapsulated);
    if (keyHeader_x_corellium_total_file_size) {
        free(keyHeader_x_corellium_total_file_size);
        keyHeader_x_corellium_total_file_size = NULL;
    }
    free(keyPairHeader_x_corellium_total_file_size);
    if (keyHeader_x_corellium_image_password) {
        free(keyHeader_x_corellium_image_password);
        keyHeader_x_corellium_image_password = NULL;
    }
    if (valueHeader_x_corellium_image_password) {
        free(valueHeader_x_corellium_image_password);
        valueHeader_x_corellium_image_password = NULL;
    }
    free(keyPairHeader_x_corellium_image_password);
    free(localVarBodyParameters);
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
    if(keyQuery_resumableChunkSize){
        free(keyQuery_resumableChunkSize);
        keyQuery_resumableChunkSize = NULL;
    }
    if(valueQuery_resumableChunkSize){
        free(valueQuery_resumableChunkSize);
        valueQuery_resumableChunkSize = NULL;
    }
    if(keyPairQuery_resumableChunkSize){
        keyValuePair_free(keyPairQuery_resumableChunkSize);
        keyPairQuery_resumableChunkSize = NULL;
    }
    if(keyQuery_resumableCurrentChunkSize){
        free(keyQuery_resumableCurrentChunkSize);
        keyQuery_resumableCurrentChunkSize = NULL;
    }
    if(valueQuery_resumableCurrentChunkSize){
        free(valueQuery_resumableCurrentChunkSize);
        valueQuery_resumableCurrentChunkSize = NULL;
    }
    if(keyPairQuery_resumableCurrentChunkSize){
        keyValuePair_free(keyPairQuery_resumableCurrentChunkSize);
        keyPairQuery_resumableCurrentChunkSize = NULL;
    }
    if(keyQuery_resumableTotalSize){
        free(keyQuery_resumableTotalSize);
        keyQuery_resumableTotalSize = NULL;
    }
    if(valueQuery_resumableTotalSize){
        free(valueQuery_resumableTotalSize);
        valueQuery_resumableTotalSize = NULL;
    }
    if(keyPairQuery_resumableTotalSize){
        keyValuePair_free(keyPairQuery_resumableTotalSize);
        keyPairQuery_resumableTotalSize = NULL;
    }
    if(keyQuery_resumableTotalChunks){
        free(keyQuery_resumableTotalChunks);
        keyQuery_resumableTotalChunks = NULL;
    }
    if(valueQuery_resumableTotalChunks){
        free(valueQuery_resumableTotalChunks);
        valueQuery_resumableTotalChunks = NULL;
    }
    if(keyPairQuery_resumableTotalChunks){
        keyValuePair_free(keyPairQuery_resumableTotalChunks);
        keyPairQuery_resumableTotalChunks = NULL;
    }
    if(keyQuery_corelliumChecksum){
        free(keyQuery_corelliumChecksum);
        keyQuery_corelliumChecksum = NULL;
    }
    if(valueQuery_corelliumChecksum){
        free(valueQuery_corelliumChecksum);
        valueQuery_corelliumChecksum = NULL;
    }
    if(keyPairQuery_corelliumChecksum){
        keyValuePair_free(keyPairQuery_corelliumChecksum);
        keyPairQuery_corelliumChecksum = NULL;
    }
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
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

