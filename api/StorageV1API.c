#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "StorageV1API.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096


// Mount and attach a storage device
//
// Initiates an asynchronous mount job for a registered storage device. If already mounted, returns status 200. If not, queues a background job and returns 202.
//
object_t*
StorageV1API_v1AttachStorageCluster(apiClient_t *apiClient, char *id)
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
    char *localVarPath = strdup("/v1/cluster/storage/{id}/attach");

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
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","Device is already mounted");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 202) {
    //    printf("%s\n","Mount job successfully queued");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Forbidden");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","MediaStore record not found");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","System failure while queuing the job");
    //}
    //nonprimitive not container
    object_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *StorageV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = object_parseFromJSON(StorageV1APIlocalVarJSON);
        cJSON_Delete(StorageV1APIlocalVarJSON);
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

// Eject/Unmount removable media
//
// Initiates an asynchronous unmount job for the physical storage device. If the device is already unmounted, returns success. If mounted, creates a background job to safely unmount.
//
object_t*
StorageV1API_v1EjectStorageCluster(apiClient_t *apiClient, char *id)
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
    char *localVarPath = strdup("/v1/cluster/storage/{id}/eject");

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
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","Device is already unmounted");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 202) {
    //    printf("%s\n","Unmount job successfully queued");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Forbidden");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","MediaStore record not found");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","System failure during job queuing");
    //}
    //nonprimitive not container
    object_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *StorageV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = object_parseFromJSON(StorageV1APIlocalVarJSON);
        cJSON_Delete(StorageV1APIlocalVarJSON);
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

// Get storage devices
//
// List all attached storage devices. This endpoint is only available to all authenticated users.
//
get_storage_response_t*
StorageV1API_v1ListStorage(apiClient_t *apiClient, double limit, double offset, char *identifier, char *device, char *fsType, char *mountPolicy, char *status, char *sort)
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
    char *localVarPath = strdup("/v1/storage");





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

    // query parameters
    char *keyQuery_identifier = NULL;
    char * valueQuery_identifier = NULL;
    keyValuePair_t *keyPairQuery_identifier = 0;
    if (identifier)
    {
        keyQuery_identifier = strdup("identifier");
        valueQuery_identifier = strdup((identifier));
        keyPairQuery_identifier = keyValuePair_create(keyQuery_identifier, valueQuery_identifier);
        list_addElement(localVarQueryParameters,keyPairQuery_identifier);
    }

    // query parameters
    char *keyQuery_device = NULL;
    char * valueQuery_device = NULL;
    keyValuePair_t *keyPairQuery_device = 0;
    if (device)
    {
        keyQuery_device = strdup("device");
        valueQuery_device = strdup((device));
        keyPairQuery_device = keyValuePair_create(keyQuery_device, valueQuery_device);
        list_addElement(localVarQueryParameters,keyPairQuery_device);
    }

    // query parameters
    char *keyQuery_fsType = NULL;
    char * valueQuery_fsType = NULL;
    keyValuePair_t *keyPairQuery_fsType = 0;
    if (fsType)
    {
        keyQuery_fsType = strdup("fsType");
        valueQuery_fsType = strdup((fsType));
        keyPairQuery_fsType = keyValuePair_create(keyQuery_fsType, valueQuery_fsType);
        list_addElement(localVarQueryParameters,keyPairQuery_fsType);
    }

    // query parameters
    char *keyQuery_mountPolicy = NULL;
    char * valueQuery_mountPolicy = NULL;
    keyValuePair_t *keyPairQuery_mountPolicy = 0;
    if (mountPolicy)
    {
        keyQuery_mountPolicy = strdup("mountPolicy");
        valueQuery_mountPolicy = strdup((mountPolicy));
        keyPairQuery_mountPolicy = keyValuePair_create(keyQuery_mountPolicy, valueQuery_mountPolicy);
        list_addElement(localVarQueryParameters,keyPairQuery_mountPolicy);
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
    //    printf("%s\n","Successfully retrieved storage devices");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Unauthorized");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Forbidden");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal server error");
    //}
    //nonprimitive not container
    get_storage_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *StorageV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = get_storage_response_parseFromJSON(StorageV1APIlocalVarJSON);
        cJSON_Delete(StorageV1APIlocalVarJSON);
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
    if(keyQuery_identifier){
        free(keyQuery_identifier);
        keyQuery_identifier = NULL;
    }
    if(valueQuery_identifier){
        free(valueQuery_identifier);
        valueQuery_identifier = NULL;
    }
    if(keyPairQuery_identifier){
        keyValuePair_free(keyPairQuery_identifier);
        keyPairQuery_identifier = NULL;
    }
    if(keyQuery_device){
        free(keyQuery_device);
        keyQuery_device = NULL;
    }
    if(valueQuery_device){
        free(valueQuery_device);
        valueQuery_device = NULL;
    }
    if(keyPairQuery_device){
        keyValuePair_free(keyPairQuery_device);
        keyPairQuery_device = NULL;
    }
    if(keyQuery_fsType){
        free(keyQuery_fsType);
        keyQuery_fsType = NULL;
    }
    if(valueQuery_fsType){
        free(valueQuery_fsType);
        valueQuery_fsType = NULL;
    }
    if(keyPairQuery_fsType){
        keyValuePair_free(keyPairQuery_fsType);
        keyPairQuery_fsType = NULL;
    }
    if(keyQuery_mountPolicy){
        free(keyQuery_mountPolicy);
        keyQuery_mountPolicy = NULL;
    }
    if(valueQuery_mountPolicy){
        free(valueQuery_mountPolicy);
        valueQuery_mountPolicy = NULL;
    }
    if(keyPairQuery_mountPolicy){
        keyValuePair_free(keyPairQuery_mountPolicy);
        keyPairQuery_mountPolicy = NULL;
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
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Get storage devices
//
// List all attached storage devices. This endpoint is only available to cluster administrators.
//
get_storage_response_t*
StorageV1API_v1ListStorageCluster(apiClient_t *apiClient, double limit, double offset, char *device, char *fsType, char *fsUUID, char *label, char *serial, char *vendor, char *model, char *mountPolicy, char *status, char *sort)
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
    char *localVarPath = strdup("/v1/cluster/storage");





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

    // query parameters
    char *keyQuery_device = NULL;
    char * valueQuery_device = NULL;
    keyValuePair_t *keyPairQuery_device = 0;
    if (device)
    {
        keyQuery_device = strdup("device");
        valueQuery_device = strdup((device));
        keyPairQuery_device = keyValuePair_create(keyQuery_device, valueQuery_device);
        list_addElement(localVarQueryParameters,keyPairQuery_device);
    }

    // query parameters
    char *keyQuery_fsType = NULL;
    char * valueQuery_fsType = NULL;
    keyValuePair_t *keyPairQuery_fsType = 0;
    if (fsType)
    {
        keyQuery_fsType = strdup("fsType");
        valueQuery_fsType = strdup((fsType));
        keyPairQuery_fsType = keyValuePair_create(keyQuery_fsType, valueQuery_fsType);
        list_addElement(localVarQueryParameters,keyPairQuery_fsType);
    }

    // query parameters
    char *keyQuery_fsUUID = NULL;
    char * valueQuery_fsUUID = NULL;
    keyValuePair_t *keyPairQuery_fsUUID = 0;
    if (fsUUID)
    {
        keyQuery_fsUUID = strdup("fsUUID");
        valueQuery_fsUUID = strdup((fsUUID));
        keyPairQuery_fsUUID = keyValuePair_create(keyQuery_fsUUID, valueQuery_fsUUID);
        list_addElement(localVarQueryParameters,keyPairQuery_fsUUID);
    }

    // query parameters
    char *keyQuery_label = NULL;
    char * valueQuery_label = NULL;
    keyValuePair_t *keyPairQuery_label = 0;
    if (label)
    {
        keyQuery_label = strdup("label");
        valueQuery_label = strdup((label));
        keyPairQuery_label = keyValuePair_create(keyQuery_label, valueQuery_label);
        list_addElement(localVarQueryParameters,keyPairQuery_label);
    }

    // query parameters
    char *keyQuery_serial = NULL;
    char * valueQuery_serial = NULL;
    keyValuePair_t *keyPairQuery_serial = 0;
    if (serial)
    {
        keyQuery_serial = strdup("serial");
        valueQuery_serial = strdup((serial));
        keyPairQuery_serial = keyValuePair_create(keyQuery_serial, valueQuery_serial);
        list_addElement(localVarQueryParameters,keyPairQuery_serial);
    }

    // query parameters
    char *keyQuery_vendor = NULL;
    char * valueQuery_vendor = NULL;
    keyValuePair_t *keyPairQuery_vendor = 0;
    if (vendor)
    {
        keyQuery_vendor = strdup("vendor");
        valueQuery_vendor = strdup((vendor));
        keyPairQuery_vendor = keyValuePair_create(keyQuery_vendor, valueQuery_vendor);
        list_addElement(localVarQueryParameters,keyPairQuery_vendor);
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
    char *keyQuery_mountPolicy = NULL;
    char * valueQuery_mountPolicy = NULL;
    keyValuePair_t *keyPairQuery_mountPolicy = 0;
    if (mountPolicy)
    {
        keyQuery_mountPolicy = strdup("mountPolicy");
        valueQuery_mountPolicy = strdup((mountPolicy));
        keyPairQuery_mountPolicy = keyValuePair_create(keyQuery_mountPolicy, valueQuery_mountPolicy);
        list_addElement(localVarQueryParameters,keyPairQuery_mountPolicy);
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
    //    printf("%s\n","Successfully retrieved storage devices");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Unauthorized");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Forbidden");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal server error");
    //}
    //nonprimitive not container
    get_storage_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *StorageV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = get_storage_response_parseFromJSON(StorageV1APIlocalVarJSON);
        cJSON_Delete(StorageV1APIlocalVarJSON);
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
    if(keyQuery_device){
        free(keyQuery_device);
        keyQuery_device = NULL;
    }
    if(valueQuery_device){
        free(valueQuery_device);
        valueQuery_device = NULL;
    }
    if(keyPairQuery_device){
        keyValuePair_free(keyPairQuery_device);
        keyPairQuery_device = NULL;
    }
    if(keyQuery_fsType){
        free(keyQuery_fsType);
        keyQuery_fsType = NULL;
    }
    if(valueQuery_fsType){
        free(valueQuery_fsType);
        valueQuery_fsType = NULL;
    }
    if(keyPairQuery_fsType){
        keyValuePair_free(keyPairQuery_fsType);
        keyPairQuery_fsType = NULL;
    }
    if(keyQuery_fsUUID){
        free(keyQuery_fsUUID);
        keyQuery_fsUUID = NULL;
    }
    if(valueQuery_fsUUID){
        free(valueQuery_fsUUID);
        valueQuery_fsUUID = NULL;
    }
    if(keyPairQuery_fsUUID){
        keyValuePair_free(keyPairQuery_fsUUID);
        keyPairQuery_fsUUID = NULL;
    }
    if(keyQuery_label){
        free(keyQuery_label);
        keyQuery_label = NULL;
    }
    if(valueQuery_label){
        free(valueQuery_label);
        valueQuery_label = NULL;
    }
    if(keyPairQuery_label){
        keyValuePair_free(keyPairQuery_label);
        keyPairQuery_label = NULL;
    }
    if(keyQuery_serial){
        free(keyQuery_serial);
        keyQuery_serial = NULL;
    }
    if(valueQuery_serial){
        free(valueQuery_serial);
        valueQuery_serial = NULL;
    }
    if(keyPairQuery_serial){
        keyValuePair_free(keyPairQuery_serial);
        keyPairQuery_serial = NULL;
    }
    if(keyQuery_vendor){
        free(keyQuery_vendor);
        keyQuery_vendor = NULL;
    }
    if(valueQuery_vendor){
        free(valueQuery_vendor);
        valueQuery_vendor = NULL;
    }
    if(keyPairQuery_vendor){
        keyValuePair_free(keyPairQuery_vendor);
        keyPairQuery_vendor = NULL;
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
    if(keyQuery_mountPolicy){
        free(keyQuery_mountPolicy);
        keyQuery_mountPolicy = NULL;
    }
    if(valueQuery_mountPolicy){
        free(valueQuery_mountPolicy);
        valueQuery_mountPolicy = NULL;
    }
    if(keyPairQuery_mountPolicy){
        keyValuePair_free(keyPairQuery_mountPolicy);
        keyPairQuery_mountPolicy = NULL;
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
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// List Storage Files
//
// List files from attached storage devices. Looks up the storage device by identifier,   then lists filesystem contents at the given path within the device's mount point.   This endpoint is available to all authenticated users.
//
object_t*
StorageV1API_v1ListStorageFiles(apiClient_t *apiClient, char *id, char *path, double limit, double offset, char *name, char *type, char *sort)
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
    char *localVarPath = strdup("/v1/storage/{id}/files/{path}");

    if(!id)
        goto end;
    if(!path)
        goto end;


    // Path Params
    long sizeOfPathParams_id = strlen(id)+3 + strlen(path)+3 + sizeof("{ id }") - 1;
    if(id == NULL) {
        goto end;
    }
    char* localVarToReplace_id = malloc(sizeOfPathParams_id);
    sprintf(localVarToReplace_id, "{%s}", "id");

    localVarPath = strReplace(localVarPath, localVarToReplace_id, id);

    // Path Params
    long sizeOfPathParams_path = strlen(id)+3 + strlen(path)+3 + sizeof("{ path }") - 1;
    if(path == NULL) {
        goto end;
    }
    char* localVarToReplace_path = malloc(sizeOfPathParams_path);
    sprintf(localVarToReplace_path, "{%s}", "path");

    localVarPath = strReplace(localVarPath, localVarToReplace_path, path);



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
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Unauthorized");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Forbidden");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Not Found (storage device or path)");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal Server Error");
    //}
    //nonprimitive not container
    object_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *StorageV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = object_parseFromJSON(StorageV1APIlocalVarJSON);
        cJSON_Delete(StorageV1APIlocalVarJSON);
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
    free(localVarToReplace_id);
    free(localVarToReplace_path);
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
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

