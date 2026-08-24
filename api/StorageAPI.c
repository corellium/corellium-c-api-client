#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "StorageAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096


// Attach storage device
//
// **Required role:** Cluster administrator.  Mounts a registered storage device. Returns 200 if already mounted, 202 if a mount job was queued. Requires the serverAttachedStorage feature.
//
storage_already_mounted_response_t*
StorageAPI_v3AttachClusterStorage(apiClient_t *apiClient, char *id)
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
    char *localVarPath = strdup("/v3/cluster/storage/{id}/attach");

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
    //    printf("%s\n","Device is already mounted.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 202) {
    //    printf("%s\n","Mount job queued.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Server-attached storage is not available on cloud installations.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Authentication required.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Cluster administrator permissions required. The serverAttachedStorage feature must be enabled.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Storage device not found.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Failed to queue the mount job.");
    //}
    //nonprimitive not container
    storage_already_mounted_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *StorageAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = storage_already_mounted_response_parseFromJSON(StorageAPIlocalVarJSON);
        cJSON_Delete(StorageAPIlocalVarJSON);
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

// Eject storage device
//
// **Required role:** Cluster administrator.  Unmounts a registered storage device. Returns 200 if already unmounted, 202 if an unmount job was queued. Requires the serverAttachedStorage feature.
//
storage_eject_already_unmounted_response_t*
StorageAPI_v3EjectClusterStorage(apiClient_t *apiClient, char *id)
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
    char *localVarPath = strdup("/v3/cluster/storage/{id}/eject");

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
    //    printf("%s\n","Device is already unmounted.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 202) {
    //    printf("%s\n","Unmount job queued.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Server-attached storage is not available on cloud installations.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Authentication required.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Cluster administrator permissions required. The serverAttachedStorage feature must be enabled.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Storage device not found.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Failed to queue the unmount job.");
    //}
    //nonprimitive not container
    storage_eject_already_unmounted_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *StorageAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = storage_eject_already_unmounted_response_parseFromJSON(StorageAPIlocalVarJSON);
        cJSON_Delete(StorageAPIlocalVarJSON);
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

// List cluster storage devices
//
// **Required role:** Cluster administrator.  Returns all attached storage devices. Requires the serverAttachedStorage feature.
//
storage_device_list_t*
StorageAPI_v3ListClusterStorage(apiClient_t *apiClient, double *limit, double *offset, char *id, char *device, char *fsType, char *fsUuid, char *label, char *serial, char *vendor, char *model, char *mountPolicy, char *status, char *sort)
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
    char *localVarPath = strdup("/v3/cluster/storage");





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
    char *keyQuery_id = NULL;
    char * valueQuery_id = NULL;
    keyValuePair_t *keyPairQuery_id = 0;
    if (id)
    {
        keyQuery_id = strdup("id");
        valueQuery_id = strdup((id));
        keyPairQuery_id = keyValuePair_create(keyQuery_id, valueQuery_id);
        list_addElement(localVarQueryParameters,keyPairQuery_id);
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
    char *keyQuery_fsUuid = NULL;
    char * valueQuery_fsUuid = NULL;
    keyValuePair_t *keyPairQuery_fsUuid = 0;
    if (fsUuid)
    {
        keyQuery_fsUuid = strdup("fsUuid");
        valueQuery_fsUuid = strdup((fsUuid));
        keyPairQuery_fsUuid = keyValuePair_create(keyQuery_fsUuid, valueQuery_fsUuid);
        list_addElement(localVarQueryParameters,keyPairQuery_fsUuid);
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
    //    printf("%s\n","Paginated list of attached storage devices.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Invalid query parameter(s).");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Authentication required.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Cluster administrator permissions required. The serverAttachedStorage feature must be enabled.");
    //}
    //nonprimitive not container
    storage_device_list_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *StorageAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = storage_device_list_parseFromJSON(StorageAPIlocalVarJSON);
        cJSON_Delete(StorageAPIlocalVarJSON);
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
    if(keyQuery_id){
        free(keyQuery_id);
        keyQuery_id = NULL;
    }
    if(valueQuery_id){
        free(valueQuery_id);
        valueQuery_id = NULL;
    }
    if(keyPairQuery_id){
        keyValuePair_free(keyPairQuery_id);
        keyPairQuery_id = NULL;
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
    if(keyQuery_fsUuid){
        free(keyQuery_fsUuid);
        keyQuery_fsUuid = NULL;
    }
    if(valueQuery_fsUuid){
        free(valueQuery_fsUuid);
        valueQuery_fsUuid = NULL;
    }
    if(keyPairQuery_fsUuid){
        keyValuePair_free(keyPairQuery_fsUuid);
        keyPairQuery_fsUuid = NULL;
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

// List storage devices
//
// List all attached storage devices visible to the authenticated user.
//
storage_list_t*
StorageAPI_v3ListStorage(apiClient_t *apiClient, double *limit, double *offset, char *sort, char *identifier, char *device, char *fsType, char *mountPolicy, char *status)
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
    char *localVarPath = strdup("/v3/storage");





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
    //    printf("%s\n","List of storage devices.");
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
    //nonprimitive not container
    storage_list_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *StorageAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = storage_list_parseFromJSON(StorageAPIlocalVarJSON);
        cJSON_Delete(StorageAPIlocalVarJSON);
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
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// List storage files
//
// List files at a path within an attached storage device. The device is resolved by identifier and the filesystem contents are listed at the given path within the mount point.
//
storage_file_list_t*
StorageAPI_v3ListStorageFiles(apiClient_t *apiClient, char *id, char *path, double *limit, double *offset, char *sort, char *name, char *type)
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
    char *localVarPath = strdup("/v3/storage/{id}/files/{path}");

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
    //    printf("%s\n","List of files and directories.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Invalid path or query parameters.");
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
    //    printf("%s\n","No storage device or path with the given identifier.");
    //}
    //nonprimitive not container
    storage_file_list_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *StorageAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = storage_file_list_parseFromJSON(StorageAPIlocalVarJSON);
        cJSON_Delete(StorageAPIlocalVarJSON);
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
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

