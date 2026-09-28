#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "ExtensionsAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096


// Delete an existing extension
//
// **Required role:** Domain administrator.  Deletes the extension identified by the given extension ID. Available on on-site deployments only. Deletion is asynchronous: the extension is marked `deleting` and the call returns 204 before removal completes.  Deletes are idempotent: an unknown extension ID, or an extension that was already deleted, is a successful no-op that still returns 204, and repeated calls return 204 as well. A 404 means the request path did not match a delete route, not that the target was missing. A repeat therefore returns 204 both while the record is still present in the `deleting` state and after it has disappeared.
//
void
ExtensionsAPI_v3DeleteExtension(apiClient_t *apiClient, char *extensionId)
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
    char *localVarPath = strdup("/v3/extensions/{extensionId}");

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
    //    printf("%s\n","No content");
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
    free(localVarToReplace_extensionId);

}

// Get extension by ID
//
// **Required role:** Domain administrator.  Returns the extension identified by the given extension ID. Available on on-site deployments only.
//
extension_t*
ExtensionsAPI_v3GetExtensionById(apiClient_t *apiClient, char *extensionId)
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
    char *localVarPath = strdup("/v3/extensions/{extensionId}");

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
    //    printf("%s\n","Extension.");
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
    //    printf("%s\n","Domain administrator permissions required.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","No extension with the given extension ID.");
    //}
    //nonprimitive not container
    extension_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ExtensionsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = extension_parseFromJSON(ExtensionsAPIlocalVarJSON);
        cJSON_Delete(ExtensionsAPIlocalVarJSON);
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

// List all extensions
//
// **Required role:** Domain administrator.  Returns a paginated list of extensions available to the authenticated user. Available on on-site deployments only.
//
extension_list_t*
ExtensionsAPI_v3ListExtensions(apiClient_t *apiClient, double *limit, double *offset, char *if_none_match)
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
    char *localVarPath = strdup("/v3/extensions");





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
    //    printf("%s\n","Paginated list of extensions.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 304) {
    //    printf("%s\n","Not modified.");
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
    //    printf("%s\n","Domain administrator permissions required.");
    //}
    //nonprimitive not container
    extension_list_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ExtensionsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = extension_list_parseFromJSON(ExtensionsAPIlocalVarJSON);
        cJSON_Delete(ExtensionsAPIlocalVarJSON);
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

// Load an extension
//
// **Required role:** Domain administrator.  Loads an extension from a previously uploaded image, identified by its image ID. The extension definition is read from the image (its extension.json), so only the image ID is supplied. Available on on-site deployments only.
//
extension_t*
ExtensionsAPI_v3LoadExtension(apiClient_t *apiClient, load_extension_body_t *load_extension_body)
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
    char *localVarPath = strdup("/v3/extensions");





    // Body Param
    cJSON *localVarSingleItemJSON_load_extension_body = NULL;
    if (load_extension_body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_load_extension_body = load_extension_body_convertToJSON(load_extension_body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_load_extension_body);
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
    //    printf("%s\n","Extension.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Invalid extension or image.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Authentication required.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Domain administrator permissions required.");
    //}
    //nonprimitive not container
    extension_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ExtensionsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = extension_parseFromJSON(ExtensionsAPIlocalVarJSON);
        cJSON_Delete(ExtensionsAPIlocalVarJSON);
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
    if (localVarSingleItemJSON_load_extension_body) {
        cJSON_Delete(localVarSingleItemJSON_load_extension_body);
        localVarSingleItemJSON_load_extension_body = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Validates extension.json
//
// **Required role:** Domain administrator.  Validates and normalises an extension.json document, returning the parsed extension definition. Available on on-site deployments only.
//
object_t*
ExtensionsAPI_v3ParseExtensionJson(apiClient_t *apiClient, object_t *body)
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
    char *localVarPath = strdup("/v3/extensions/parse/extension.json");





    // Body Param
    cJSON *localVarSingleItemJSON_body = NULL;
    if (body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_body = object_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
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
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Invalid extension.json.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Authentication required.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Domain administrator permissions required.");
    //}
    //nonprimitive not container
    object_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ExtensionsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = object_parseFromJSON(ExtensionsAPIlocalVarJSON);
        cJSON_Delete(ExtensionsAPIlocalVarJSON);
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
    if (localVarSingleItemJSON_body) {
        cJSON_Delete(localVarSingleItemJSON_body);
        localVarSingleItemJSON_body = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Update an existing extension
//
// **Required role:** Domain administrator.  Updates the extension identified by the given extension ID with the supplied definition. Available on on-site deployments only.
//
extension_t*
ExtensionsAPI_v3UpdateExtension(apiClient_t *apiClient, char *extensionId, update_extension_body_t *update_extension_body)
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
    char *localVarPath = strdup("/v3/extensions/{extensionId}");

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
    cJSON *localVarSingleItemJSON_update_extension_body = NULL;
    if (update_extension_body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_update_extension_body = update_extension_body_convertToJSON(update_extension_body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_update_extension_body);
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
    //    printf("%s\n","The updated extension.");
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
    //    printf("%s\n","Domain administrator permissions required.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","No extension with the given extension ID.");
    //}
    //nonprimitive not container
    extension_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ExtensionsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = extension_parseFromJSON(ExtensionsAPIlocalVarJSON);
        cJSON_Delete(ExtensionsAPIlocalVarJSON);
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
    free(localVarToReplace_extensionId);
    if (localVarSingleItemJSON_update_extension_body) {
        cJSON_Delete(localVarSingleItemJSON_update_extension_body);
        localVarSingleItemJSON_update_extension_body = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

