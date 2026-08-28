#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "FirmwareServiceAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096


// Add firmware assets
//
// **Required role:** Cluster administrator.  Adds firmware assets to the cluster firmware service.
//
char*
FirmwareServiceAPI_v3CreateFirmwareAssets(apiClient_t *apiClient, object_t *body)
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
    char *localVarPath = strdup("/v3/cluster/firmware-service/firmware-assets");





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
    //if (apiClient->response_code == 201) {
    //    printf("%s\n","Firmware assets added.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Invalid request.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Cluster administrator permissions required.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Resource not found.");
    //}
    //primitive return type simple string
    char* elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300)
        elementToReturn = strdup((char*)apiClient->dataReceived);

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

// Delete a firmware
//
// **Required role:** Cluster administrator.  Deletes the firmware identified by the given filename from the cluster firmware service.
//
void
FirmwareServiceAPI_v3DeleteFirmware(apiClient_t *apiClient, char *filename)
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
    char *localVarPath = strdup("/v3/cluster/firmware-service/firmwares/{filename}");

    if(!filename)
        goto end;


    // Path Params
    long sizeOfPathParams_filename = strlen(filename)+3 + sizeof("{ filename }") - 1;
    if(filename == NULL) {
        goto end;
    }
    char* localVarToReplace_filename = malloc(sizeOfPathParams_filename);
    sprintf(localVarToReplace_filename, "{%s}", "filename");

    localVarPath = strReplace(localVarPath, localVarToReplace_filename, filename);


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
    //    printf("%s\n","Firmware deleted.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Invalid request.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Cluster administrator permissions required.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Resource not found.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 409) {
    //    printf("%s\n","Resource conflict.");
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
    free(localVarToReplace_filename);

}

// Delete a firmware asset
//
// **Required role:** Cluster administrator.  Deletes the firmware asset identified by the given asset URL from the cluster firmware service.
//
void
FirmwareServiceAPI_v3DeleteFirmwareAsset(apiClient_t *apiClient, char *assetUrl)
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
    char *localVarPath = strdup("/v3/cluster/firmware-service/firmware-assets/{assetUrl}");

    if(!assetUrl)
        goto end;


    // Path Params
    long sizeOfPathParams_assetUrl = strlen(assetUrl)+3 + sizeof("{ assetUrl }") - 1;
    if(assetUrl == NULL) {
        goto end;
    }
    char* localVarToReplace_assetUrl = malloc(sizeOfPathParams_assetUrl);
    sprintf(localVarToReplace_assetUrl, "{%s}", "assetUrl");

    localVarPath = strReplace(localVarPath, localVarToReplace_assetUrl, assetUrl);


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
    //    printf("%s\n","Firmware asset deleted.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Invalid request.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Cluster administrator permissions required.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Resource not found.");
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
    free(localVarToReplace_assetUrl);

}

// Get extended firmware asset info
//
// **Required role:** Cluster administrator.  Returns the firmwares and instances associated with a firmware asset.
//
extended_firmware_asset_info_t*
FirmwareServiceAPI_v3GetFirmwareAssetExtended(apiClient_t *apiClient, char *assetUrl)
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
    char *localVarPath = strdup("/v3/cluster/firmware-service/firmware-assets/{assetUrl}/extended");

    if(!assetUrl)
        goto end;


    // Path Params
    long sizeOfPathParams_assetUrl = strlen(assetUrl)+3 + sizeof("{ assetUrl }") - 1;
    if(assetUrl == NULL) {
        goto end;
    }
    char* localVarToReplace_assetUrl = malloc(sizeOfPathParams_assetUrl);
    sprintf(localVarToReplace_assetUrl, "{%s}", "assetUrl");

    localVarPath = strReplace(localVarPath, localVarToReplace_assetUrl, assetUrl);


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
    //    printf("%s\n","Extended firmware asset info.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Invalid request.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Cluster administrator permissions required.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Resource not found.");
    //}
    //nonprimitive not container
    extended_firmware_asset_info_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *FirmwareServiceAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = extended_firmware_asset_info_parseFromJSON(FirmwareServiceAPIlocalVarJSON);
        cJSON_Delete(FirmwareServiceAPIlocalVarJSON);
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
    free(localVarToReplace_assetUrl);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Get firmware service configuration
//
// **Required role:** Cluster administrator.  Returns the current configuration of the cluster firmware service.
//
firmware_service_config_t*
FirmwareServiceAPI_v3GetFirmwareServiceConfig(apiClient_t *apiClient)
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
    char *localVarPath = strdup("/v3/cluster/firmware-service/config");




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
    //    printf("%s\n","Firmware service configuration.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Invalid request.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Cluster administrator permissions required.");
    //}
    //nonprimitive not container
    firmware_service_config_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *FirmwareServiceAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = firmware_service_config_parseFromJSON(FirmwareServiceAPIlocalVarJSON);
        cJSON_Delete(FirmwareServiceAPIlocalVarJSON);
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

// List firmware assets
//
// **Required role:** Cluster administrator.  Returns a paginated list of firmware assets available in the cluster firmware service.
//
firmware_asset_list_t*
FirmwareServiceAPI_v3ListFirmwareAssets(apiClient_t *apiClient, double *limit, double *offset, char *search, char *order, firmware_asset_filter_t *filter)
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
    char *localVarPath = strdup("/v3/cluster/firmware-service/firmware-assets");





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
    char *keyQuery_search = NULL;
    char * valueQuery_search = NULL;
    keyValuePair_t *keyPairQuery_search = 0;
    if (search)
    {
        keyQuery_search = strdup("search");
        valueQuery_search = strdup((search));
        keyPairQuery_search = keyValuePair_create(keyQuery_search, valueQuery_search);
        list_addElement(localVarQueryParameters,keyPairQuery_search);
    }

    // query parameters
    char *keyQuery_order = NULL;
    char * valueQuery_order = NULL;
    keyValuePair_t *keyPairQuery_order = 0;
    if (order)
    {
        keyQuery_order = strdup("order");
        valueQuery_order = strdup((order));
        keyPairQuery_order = keyValuePair_create(keyQuery_order, valueQuery_order);
        list_addElement(localVarQueryParameters,keyPairQuery_order);
    }

    // query parameters
    char *keyQuery_filter = NULL;
    firmware_asset_filter_t * valueQuery_filter ;
    keyValuePair_t *keyPairQuery_filter = 0;
    if (filter)
    {
        keyQuery_filter = strdup("filter");
        valueQuery_filter = (filter);
        keyPairQuery_filter = keyValuePair_create(keyQuery_filter, &valueQuery_filter);
        list_addElement(localVarQueryParameters,keyPairQuery_filter);
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
    //    printf("%s\n","Paginated list of firmware assets.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Invalid request.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Cluster administrator permissions required.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Resource not found.");
    //}
    //nonprimitive not container
    firmware_asset_list_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *FirmwareServiceAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = firmware_asset_list_parseFromJSON(FirmwareServiceAPIlocalVarJSON);
        cJSON_Delete(FirmwareServiceAPIlocalVarJSON);
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
    if(keyQuery_search){
        free(keyQuery_search);
        keyQuery_search = NULL;
    }
    if(valueQuery_search){
        free(valueQuery_search);
        valueQuery_search = NULL;
    }
    if(keyPairQuery_search){
        keyValuePair_free(keyPairQuery_search);
        keyPairQuery_search = NULL;
    }
    if(keyQuery_order){
        free(keyQuery_order);
        keyQuery_order = NULL;
    }
    if(valueQuery_order){
        free(valueQuery_order);
        valueQuery_order = NULL;
    }
    if(keyPairQuery_order){
        keyValuePair_free(keyPairQuery_order);
        keyPairQuery_order = NULL;
    }
    if(keyQuery_filter){
        free(keyQuery_filter);
        keyQuery_filter = NULL;
    }
    if(keyPairQuery_filter){
        keyValuePair_free(keyPairQuery_filter);
        keyPairQuery_filter = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// List firmware service devices
//
// **Required role:** Cluster administrator.  Returns a paginated list of devices known to the cluster firmware service.
//
firmware_device_list_t*
FirmwareServiceAPI_v3ListFirmwareDevices(apiClient_t *apiClient, double *limit, double *offset, char *search, char *order, char *type, char *model, char *name, char *platform, char *hwModel)
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
    char *localVarPath = strdup("/v3/cluster/firmware-service/devices");





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
    char *keyQuery_search = NULL;
    char * valueQuery_search = NULL;
    keyValuePair_t *keyPairQuery_search = 0;
    if (search)
    {
        keyQuery_search = strdup("search");
        valueQuery_search = strdup((search));
        keyPairQuery_search = keyValuePair_create(keyQuery_search, valueQuery_search);
        list_addElement(localVarQueryParameters,keyPairQuery_search);
    }

    // query parameters
    char *keyQuery_order = NULL;
    char * valueQuery_order = NULL;
    keyValuePair_t *keyPairQuery_order = 0;
    if (order)
    {
        keyQuery_order = strdup("order");
        valueQuery_order = strdup((order));
        keyPairQuery_order = keyValuePair_create(keyQuery_order, valueQuery_order);
        list_addElement(localVarQueryParameters,keyPairQuery_order);
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
    char *keyQuery_model = NULL;
    char * valueQuery_model = NULL;
    keyValuePair_t *keyPairQuery_model = 0;
    if (model)
    {
        keyQuery_model = strdup("model");
        valueQuery_model = strdup((model));
        keyPairQuery_model = keyValuePair_create(keyQuery_model, valueQuery_model);
        list_addElement(localVarQueryParameters,keyPairQuery_model);
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
    char *keyQuery_platform = NULL;
    char * valueQuery_platform = NULL;
    keyValuePair_t *keyPairQuery_platform = 0;
    if (platform)
    {
        keyQuery_platform = strdup("platform");
        valueQuery_platform = strdup((platform));
        keyPairQuery_platform = keyValuePair_create(keyQuery_platform, valueQuery_platform);
        list_addElement(localVarQueryParameters,keyPairQuery_platform);
    }

    // query parameters
    char *keyQuery_hwModel = NULL;
    char * valueQuery_hwModel = NULL;
    keyValuePair_t *keyPairQuery_hwModel = 0;
    if (hwModel)
    {
        keyQuery_hwModel = strdup("hwModel");
        valueQuery_hwModel = strdup((hwModel));
        keyPairQuery_hwModel = keyValuePair_create(keyQuery_hwModel, valueQuery_hwModel);
        list_addElement(localVarQueryParameters,keyPairQuery_hwModel);
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
    //    printf("%s\n","Paginated list of devices.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Invalid request.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Cluster administrator permissions required.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Resource not found.");
    //}
    //nonprimitive not container
    firmware_device_list_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *FirmwareServiceAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = firmware_device_list_parseFromJSON(FirmwareServiceAPIlocalVarJSON);
        cJSON_Delete(FirmwareServiceAPIlocalVarJSON);
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
    if(keyQuery_search){
        free(keyQuery_search);
        keyQuery_search = NULL;
    }
    if(valueQuery_search){
        free(valueQuery_search);
        valueQuery_search = NULL;
    }
    if(keyPairQuery_search){
        keyValuePair_free(keyPairQuery_search);
        keyPairQuery_search = NULL;
    }
    if(keyQuery_order){
        free(keyQuery_order);
        keyQuery_order = NULL;
    }
    if(valueQuery_order){
        free(valueQuery_order);
        valueQuery_order = NULL;
    }
    if(keyPairQuery_order){
        keyValuePair_free(keyPairQuery_order);
        keyPairQuery_order = NULL;
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
    if(keyQuery_model){
        free(keyQuery_model);
        keyQuery_model = NULL;
    }
    if(valueQuery_model){
        free(valueQuery_model);
        valueQuery_model = NULL;
    }
    if(keyPairQuery_model){
        keyValuePair_free(keyPairQuery_model);
        keyPairQuery_model = NULL;
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
    if(keyQuery_platform){
        free(keyQuery_platform);
        keyQuery_platform = NULL;
    }
    if(valueQuery_platform){
        free(valueQuery_platform);
        valueQuery_platform = NULL;
    }
    if(keyPairQuery_platform){
        keyValuePair_free(keyPairQuery_platform);
        keyPairQuery_platform = NULL;
    }
    if(keyQuery_hwModel){
        free(keyQuery_hwModel);
        keyQuery_hwModel = NULL;
    }
    if(valueQuery_hwModel){
        free(valueQuery_hwModel);
        valueQuery_hwModel = NULL;
    }
    if(keyPairQuery_hwModel){
        keyValuePair_free(keyPairQuery_hwModel);
        keyPairQuery_hwModel = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// List firmwares
//
// **Required role:** Cluster administrator.  Returns a paginated list of firmwares available in the cluster firmware service.
//
firmware_list_t*
FirmwareServiceAPI_v3ListFirmwares(apiClient_t *apiClient, double *limit, double *offset, char *search, char *order, char *filename, char *model, char *type, char *version, char *buildId, char *firmwareAssets, char *corelliumChecksum, int *installed)
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
    char *localVarPath = strdup("/v3/cluster/firmware-service/firmwares");





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
    char *keyQuery_search = NULL;
    char * valueQuery_search = NULL;
    keyValuePair_t *keyPairQuery_search = 0;
    if (search)
    {
        keyQuery_search = strdup("search");
        valueQuery_search = strdup((search));
        keyPairQuery_search = keyValuePair_create(keyQuery_search, valueQuery_search);
        list_addElement(localVarQueryParameters,keyPairQuery_search);
    }

    // query parameters
    char *keyQuery_order = NULL;
    char * valueQuery_order = NULL;
    keyValuePair_t *keyPairQuery_order = 0;
    if (order)
    {
        keyQuery_order = strdup("order");
        valueQuery_order = strdup((order));
        keyPairQuery_order = keyValuePair_create(keyQuery_order, valueQuery_order);
        list_addElement(localVarQueryParameters,keyPairQuery_order);
    }

    // query parameters
    char *keyQuery_filename = NULL;
    char * valueQuery_filename = NULL;
    keyValuePair_t *keyPairQuery_filename = 0;
    if (filename)
    {
        keyQuery_filename = strdup("filename");
        valueQuery_filename = strdup((filename));
        keyPairQuery_filename = keyValuePair_create(keyQuery_filename, valueQuery_filename);
        list_addElement(localVarQueryParameters,keyPairQuery_filename);
    }

    // query parameters
    char *keyQuery_model = NULL;
    char * valueQuery_model = NULL;
    keyValuePair_t *keyPairQuery_model = 0;
    if (model)
    {
        keyQuery_model = strdup("model");
        valueQuery_model = strdup((model));
        keyPairQuery_model = keyValuePair_create(keyQuery_model, valueQuery_model);
        list_addElement(localVarQueryParameters,keyPairQuery_model);
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
    char *keyQuery_version = NULL;
    char * valueQuery_version = NULL;
    keyValuePair_t *keyPairQuery_version = 0;
    if (version)
    {
        keyQuery_version = strdup("version");
        valueQuery_version = strdup((version));
        keyPairQuery_version = keyValuePair_create(keyQuery_version, valueQuery_version);
        list_addElement(localVarQueryParameters,keyPairQuery_version);
    }

    // query parameters
    char *keyQuery_buildId = NULL;
    char * valueQuery_buildId = NULL;
    keyValuePair_t *keyPairQuery_buildId = 0;
    if (buildId)
    {
        keyQuery_buildId = strdup("buildId");
        valueQuery_buildId = strdup((buildId));
        keyPairQuery_buildId = keyValuePair_create(keyQuery_buildId, valueQuery_buildId);
        list_addElement(localVarQueryParameters,keyPairQuery_buildId);
    }

    // query parameters
    char *keyQuery_firmwareAssets = NULL;
    char * valueQuery_firmwareAssets = NULL;
    keyValuePair_t *keyPairQuery_firmwareAssets = 0;
    if (firmwareAssets)
    {
        keyQuery_firmwareAssets = strdup("firmwareAssets");
        valueQuery_firmwareAssets = strdup((firmwareAssets));
        keyPairQuery_firmwareAssets = keyValuePair_create(keyQuery_firmwareAssets, valueQuery_firmwareAssets);
        list_addElement(localVarQueryParameters,keyPairQuery_firmwareAssets);
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
    char *keyQuery_installed = NULL;
    char * valueQuery_installed = NULL;
    keyValuePair_t *keyPairQuery_installed = 0;
    if (installed)
    {
        keyQuery_installed = strdup("installed");
        valueQuery_installed = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_installed, MAX_NUMBER_LENGTH, "%d", *installed);
        keyPairQuery_installed = keyValuePair_create(keyQuery_installed, valueQuery_installed);
        list_addElement(localVarQueryParameters,keyPairQuery_installed);
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
    //    printf("%s\n","Paginated list of firmwares.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Invalid request.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Cluster administrator permissions required.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Resource not found.");
    //}
    //nonprimitive not container
    firmware_list_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *FirmwareServiceAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = firmware_list_parseFromJSON(FirmwareServiceAPIlocalVarJSON);
        cJSON_Delete(FirmwareServiceAPIlocalVarJSON);
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
    if(keyQuery_search){
        free(keyQuery_search);
        keyQuery_search = NULL;
    }
    if(valueQuery_search){
        free(valueQuery_search);
        valueQuery_search = NULL;
    }
    if(keyPairQuery_search){
        keyValuePair_free(keyPairQuery_search);
        keyPairQuery_search = NULL;
    }
    if(keyQuery_order){
        free(keyQuery_order);
        keyQuery_order = NULL;
    }
    if(valueQuery_order){
        free(valueQuery_order);
        valueQuery_order = NULL;
    }
    if(keyPairQuery_order){
        keyValuePair_free(keyPairQuery_order);
        keyPairQuery_order = NULL;
    }
    if(keyQuery_filename){
        free(keyQuery_filename);
        keyQuery_filename = NULL;
    }
    if(valueQuery_filename){
        free(valueQuery_filename);
        valueQuery_filename = NULL;
    }
    if(keyPairQuery_filename){
        keyValuePair_free(keyPairQuery_filename);
        keyPairQuery_filename = NULL;
    }
    if(keyQuery_model){
        free(keyQuery_model);
        keyQuery_model = NULL;
    }
    if(valueQuery_model){
        free(valueQuery_model);
        valueQuery_model = NULL;
    }
    if(keyPairQuery_model){
        keyValuePair_free(keyPairQuery_model);
        keyPairQuery_model = NULL;
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
    if(keyQuery_version){
        free(keyQuery_version);
        keyQuery_version = NULL;
    }
    if(valueQuery_version){
        free(valueQuery_version);
        valueQuery_version = NULL;
    }
    if(keyPairQuery_version){
        keyValuePair_free(keyPairQuery_version);
        keyPairQuery_version = NULL;
    }
    if(keyQuery_buildId){
        free(keyQuery_buildId);
        keyQuery_buildId = NULL;
    }
    if(valueQuery_buildId){
        free(valueQuery_buildId);
        valueQuery_buildId = NULL;
    }
    if(keyPairQuery_buildId){
        keyValuePair_free(keyPairQuery_buildId);
        keyPairQuery_buildId = NULL;
    }
    if(keyQuery_firmwareAssets){
        free(keyQuery_firmwareAssets);
        keyQuery_firmwareAssets = NULL;
    }
    if(valueQuery_firmwareAssets){
        free(valueQuery_firmwareAssets);
        valueQuery_firmwareAssets = NULL;
    }
    if(keyPairQuery_firmwareAssets){
        keyValuePair_free(keyPairQuery_firmwareAssets);
        keyPairQuery_firmwareAssets = NULL;
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
    if(keyQuery_installed){
        free(keyQuery_installed);
        keyQuery_installed = NULL;
    }
    if(valueQuery_installed){
        free(valueQuery_installed);
        valueQuery_installed = NULL;
    }
    if(keyPairQuery_installed){
        keyValuePair_free(keyPairQuery_installed);
        keyPairQuery_installed = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Update firmware service configuration
//
// **Required role:** Cluster administrator.  Updates the cluster firmware service configuration and returns the merged result.
//
firmware_service_settings_t*
FirmwareServiceAPI_v3PatchFirmwareServiceConfig(apiClient_t *apiClient, patch_firmware_service_config_body_t *patch_firmware_service_config_body)
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
    char *localVarPath = strdup("/v3/cluster/firmware-service/config");





    // Body Param
    cJSON *localVarSingleItemJSON_patch_firmware_service_config_body = NULL;
    if (patch_firmware_service_config_body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_patch_firmware_service_config_body = patch_firmware_service_config_body_convertToJSON(patch_firmware_service_config_body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_patch_firmware_service_config_body);
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
    //    printf("%s\n","The full merged settings after the update.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Invalid request.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Cluster administrator permissions required.");
    //}
    //nonprimitive not container
    firmware_service_settings_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *FirmwareServiceAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = firmware_service_settings_parseFromJSON(FirmwareServiceAPIlocalVarJSON);
        cJSON_Delete(FirmwareServiceAPIlocalVarJSON);
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
    if (localVarSingleItemJSON_patch_firmware_service_config_body) {
        cJSON_Delete(localVarSingleItemJSON_patch_firmware_service_config_body);
        localVarSingleItemJSON_patch_firmware_service_config_body = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

