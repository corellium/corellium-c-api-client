#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "SnapshotsAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096


// Create instance snapshot
//
snapshot_t*
SnapshotsAPI_v3CreateInstanceSnapshot(apiClient_t *apiClient, char *instanceId, create_snapshot_body_t *create_snapshot_body)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/snapshots");

    if(!instanceId)
        goto end;


    // Path Params
    long sizeOfPathParams_instanceId = strlen(instanceId)+3 + sizeof("{ instanceId }") - 1;
    if(instanceId == NULL) {
        goto end;
    }
    char* localVarToReplace_instanceId = malloc(sizeOfPathParams_instanceId);
    sprintf(localVarToReplace_instanceId, "{%s}", "instanceId");

    localVarPath = strReplace(localVarPath, localVarToReplace_instanceId, instanceId);



    // Body Param
    cJSON *localVarSingleItemJSON_create_snapshot_body = NULL;
    if (create_snapshot_body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_create_snapshot_body = create_snapshot_body_convertToJSON(create_snapshot_body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_create_snapshot_body);
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
    //    printf("%s\n","Created snapshot.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Instance not found.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Permission denied.");
    //}
    //nonprimitive not container
    snapshot_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *SnapshotsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = snapshot_parseFromJSON(SnapshotsAPIlocalVarJSON);
        cJSON_Delete(SnapshotsAPIlocalVarJSON);
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
    free(localVarToReplace_instanceId);
    if (localVarSingleItemJSON_create_snapshot_body) {
        cJSON_Delete(localVarSingleItemJSON_create_snapshot_body);
        localVarSingleItemJSON_create_snapshot_body = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Delete an instance snapshot
//
// Delete an instance snapshot. Deletion is asynchronous: the snapshot is marked `deleting` and the call returns 204 before the underlying storage has been reclaimed.  Deletes are idempotent: an unknown `snapshotId`, or an unknown `instanceId`, is a successful no-op that still returns 204, and repeated calls return 204 as well. A 404 means the request path did not match a delete route, not that the target was missing. A repeat therefore returns 204 both while the snapshot is still present in the `deleting` state and after it has disappeared.
//
void
SnapshotsAPI_v3DeleteInstanceSnapshot(apiClient_t *apiClient, char *instanceId, char *snapshotId)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/snapshots/{snapshotId}");

    if(!instanceId)
        goto end;
    if(!snapshotId)
        goto end;


    // Path Params
    long sizeOfPathParams_instanceId = strlen(instanceId)+3 + strlen(snapshotId)+3 + sizeof("{ instanceId }") - 1;
    if(instanceId == NULL) {
        goto end;
    }
    char* localVarToReplace_instanceId = malloc(sizeOfPathParams_instanceId);
    sprintf(localVarToReplace_instanceId, "{%s}", "instanceId");

    localVarPath = strReplace(localVarPath, localVarToReplace_instanceId, instanceId);

    // Path Params
    long sizeOfPathParams_snapshotId = strlen(instanceId)+3 + strlen(snapshotId)+3 + sizeof("{ snapshotId }") - 1;
    if(snapshotId == NULL) {
        goto end;
    }
    char* localVarToReplace_snapshotId = malloc(sizeOfPathParams_snapshotId);
    sprintf(localVarToReplace_snapshotId, "{%s}", "snapshotId");

    localVarPath = strReplace(localVarPath, localVarToReplace_snapshotId, snapshotId);


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
    //    printf("%s\n","Snapshot deleted; empty body.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Malformed snapshot ID.");
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
    
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_instanceId);
    free(localVarToReplace_snapshotId);

}

// Delete a snapshot
//
// Delete a snapshot by ID. Deletion is asynchronous: the snapshot is marked `deleting` and the call returns 204 before the underlying storage has been reclaimed.  Deletes are idempotent: an unknown `snapshotId`, or a snapshot that was already deleted, is a successful no-op that still returns 204, and repeated calls return 204 as well. A 404 means the request path did not match a delete route, not that the target was missing. A repeat therefore returns 204 both while the snapshot is still present in the `deleting` state and after it has disappeared.
//
void
SnapshotsAPI_v3DeleteSnapshot(apiClient_t *apiClient, char *snapshotId)
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
    char *localVarPath = strdup("/v3/snapshots/{snapshotId}");

    if(!snapshotId)
        goto end;


    // Path Params
    long sizeOfPathParams_snapshotId = strlen(snapshotId)+3 + sizeof("{ snapshotId }") - 1;
    if(snapshotId == NULL) {
        goto end;
    }
    char* localVarToReplace_snapshotId = malloc(sizeOfPathParams_snapshotId);
    sprintf(localVarToReplace_snapshotId, "{%s}", "snapshotId");

    localVarPath = strReplace(localVarPath, localVarToReplace_snapshotId, snapshotId);


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
    //    printf("%s\n","Successfully deleted snapshot; empty body.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Malformed snapshot ID.");
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
    
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_snapshotId);

}

// Get instance snapshot
//
// Get instance snapshot by ID.
//
snapshot_t*
SnapshotsAPI_v3GetInstanceSnapshot(apiClient_t *apiClient, char *instanceId, char *snapshotId)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/snapshots/{snapshotId}");

    if(!instanceId)
        goto end;
    if(!snapshotId)
        goto end;


    // Path Params
    long sizeOfPathParams_instanceId = strlen(instanceId)+3 + strlen(snapshotId)+3 + sizeof("{ instanceId }") - 1;
    if(instanceId == NULL) {
        goto end;
    }
    char* localVarToReplace_instanceId = malloc(sizeOfPathParams_instanceId);
    sprintf(localVarToReplace_instanceId, "{%s}", "instanceId");

    localVarPath = strReplace(localVarPath, localVarToReplace_instanceId, instanceId);

    // Path Params
    long sizeOfPathParams_snapshotId = strlen(instanceId)+3 + strlen(snapshotId)+3 + sizeof("{ snapshotId }") - 1;
    if(snapshotId == NULL) {
        goto end;
    }
    char* localVarToReplace_snapshotId = malloc(sizeOfPathParams_snapshotId);
    sprintf(localVarToReplace_snapshotId, "{%s}", "snapshotId");

    localVarPath = strReplace(localVarPath, localVarToReplace_snapshotId, snapshotId);


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
    //    printf("%s\n","Instance snapshot details.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Permission denied.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Instance or snapshot not found.");
    //}
    //nonprimitive not container
    snapshot_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *SnapshotsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = snapshot_parseFromJSON(SnapshotsAPIlocalVarJSON);
        cJSON_Delete(SnapshotsAPIlocalVarJSON);
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
    free(localVarToReplace_instanceId);
    free(localVarToReplace_snapshotId);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Get snapshot
//
// Get snapshot by ID.
//
snapshot_t*
SnapshotsAPI_v3GetSnapshot(apiClient_t *apiClient, char *snapshotId)
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
    char *localVarPath = strdup("/v3/snapshots/{snapshotId}");

    if(!snapshotId)
        goto end;


    // Path Params
    long sizeOfPathParams_snapshotId = strlen(snapshotId)+3 + sizeof("{ snapshotId }") - 1;
    if(snapshotId == NULL) {
        goto end;
    }
    char* localVarToReplace_snapshotId = malloc(sizeOfPathParams_snapshotId);
    sprintf(localVarToReplace_snapshotId, "{%s}", "snapshotId");

    localVarPath = strReplace(localVarPath, localVarToReplace_snapshotId, snapshotId);


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
    //    printf("%s\n","Successfully retrieved snapshot.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Permission denied.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Snapshot not found.");
    //}
    //nonprimitive not container
    snapshot_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *SnapshotsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = snapshot_parseFromJSON(SnapshotsAPIlocalVarJSON);
        cJSON_Delete(SnapshotsAPIlocalVarJSON);
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
    free(localVarToReplace_snapshotId);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// List instance snapshots
//
instance_snapshots_list_t*
SnapshotsAPI_v3ListInstanceSnapshots(apiClient_t *apiClient, char *instanceId, double *limit, double *offset)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/snapshots");

    if(!instanceId)
        goto end;


    // Path Params
    long sizeOfPathParams_instanceId = strlen(instanceId)+3 + sizeof("{ instanceId }") - 1;
    if(instanceId == NULL) {
        goto end;
    }
    char* localVarToReplace_instanceId = malloc(sizeOfPathParams_instanceId);
    sprintf(localVarToReplace_instanceId, "{%s}", "instanceId");

    localVarPath = strReplace(localVarPath, localVarToReplace_instanceId, instanceId);



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
    //    printf("%s\n","Paginated list of snapshots for the instance.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Permission denied.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Instance not found.");
    //}
    //nonprimitive not container
    instance_snapshots_list_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *SnapshotsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = instance_snapshots_list_parseFromJSON(SnapshotsAPIlocalVarJSON);
        cJSON_Delete(SnapshotsAPIlocalVarJSON);
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
    free(localVarToReplace_instanceId);
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

// Update an instance snapshot
//
snapshot_t*
SnapshotsAPI_v3PatchInstanceSnapshot(apiClient_t *apiClient, char *instanceId, char *snapshotId, create_snapshot_body_t *create_snapshot_body)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/snapshots/{snapshotId}");

    if(!instanceId)
        goto end;
    if(!snapshotId)
        goto end;


    // Path Params
    long sizeOfPathParams_instanceId = strlen(instanceId)+3 + strlen(snapshotId)+3 + sizeof("{ instanceId }") - 1;
    if(instanceId == NULL) {
        goto end;
    }
    char* localVarToReplace_instanceId = malloc(sizeOfPathParams_instanceId);
    sprintf(localVarToReplace_instanceId, "{%s}", "instanceId");

    localVarPath = strReplace(localVarPath, localVarToReplace_instanceId, instanceId);

    // Path Params
    long sizeOfPathParams_snapshotId = strlen(instanceId)+3 + strlen(snapshotId)+3 + sizeof("{ snapshotId }") - 1;
    if(snapshotId == NULL) {
        goto end;
    }
    char* localVarToReplace_snapshotId = malloc(sizeOfPathParams_snapshotId);
    sprintf(localVarToReplace_snapshotId, "{%s}", "snapshotId");

    localVarPath = strReplace(localVarPath, localVarToReplace_snapshotId, snapshotId);



    // Body Param
    cJSON *localVarSingleItemJSON_create_snapshot_body = NULL;
    if (create_snapshot_body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_create_snapshot_body = create_snapshot_body_convertToJSON(create_snapshot_body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_create_snapshot_body);
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
    //    printf("%s\n","Updated snapshot.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Validation error or no changes provided.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Permission denied.");
    //}
    //nonprimitive not container
    snapshot_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *SnapshotsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = snapshot_parseFromJSON(SnapshotsAPIlocalVarJSON);
        cJSON_Delete(SnapshotsAPIlocalVarJSON);
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
    free(localVarToReplace_instanceId);
    free(localVarToReplace_snapshotId);
    if (localVarSingleItemJSON_create_snapshot_body) {
        cJSON_Delete(localVarSingleItemJSON_create_snapshot_body);
        localVarSingleItemJSON_create_snapshot_body = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Restore instance snapshot
//
// Restore the specified instance to the given snapshot.
//
void
SnapshotsAPI_v3RestoreInstanceSnapshot(apiClient_t *apiClient, char *instanceId, char *snapshotId)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/snapshots/{snapshotId}/restore");

    if(!instanceId)
        goto end;
    if(!snapshotId)
        goto end;


    // Path Params
    long sizeOfPathParams_instanceId = strlen(instanceId)+3 + strlen(snapshotId)+3 + sizeof("{ instanceId }") - 1;
    if(instanceId == NULL) {
        goto end;
    }
    char* localVarToReplace_instanceId = malloc(sizeOfPathParams_instanceId);
    sprintf(localVarToReplace_instanceId, "{%s}", "instanceId");

    localVarPath = strReplace(localVarPath, localVarToReplace_instanceId, instanceId);

    // Path Params
    long sizeOfPathParams_snapshotId = strlen(instanceId)+3 + strlen(snapshotId)+3 + sizeof("{ snapshotId }") - 1;
    if(snapshotId == NULL) {
        goto end;
    }
    char* localVarToReplace_snapshotId = malloc(sizeOfPathParams_snapshotId);
    sprintf(localVarToReplace_snapshotId, "{%s}", "snapshotId");

    localVarPath = strReplace(localVarPath, localVarToReplace_snapshotId, snapshotId);


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
    //if (apiClient->response_code == 204) {
    //    printf("%s\n","Restore snapshot accepted.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Invalid snapshot ID.");
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
    
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_instanceId);
    free(localVarToReplace_snapshotId);

}

// Update snapshot name
//
snapshot_t*
SnapshotsAPI_v3UpdateSnapshot(apiClient_t *apiClient, char *snapshotId, v3_update_snapshot_request_t *v3_update_snapshot_request)
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
    char *localVarPath = strdup("/v3/snapshots/{snapshotId}");

    if(!snapshotId)
        goto end;


    // Path Params
    long sizeOfPathParams_snapshotId = strlen(snapshotId)+3 + sizeof("{ snapshotId }") - 1;
    if(snapshotId == NULL) {
        goto end;
    }
    char* localVarToReplace_snapshotId = malloc(sizeOfPathParams_snapshotId);
    sprintf(localVarToReplace_snapshotId, "{%s}", "snapshotId");

    localVarPath = strReplace(localVarPath, localVarToReplace_snapshotId, snapshotId);



    // Body Param
    cJSON *localVarSingleItemJSON_v3_update_snapshot_request = NULL;
    if (v3_update_snapshot_request != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_v3_update_snapshot_request = v3_update_snapshot_request_convertToJSON(v3_update_snapshot_request);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_v3_update_snapshot_request);
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
    //    printf("%s\n","Successfully updated snapshot name.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Permission denied.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Snapshot not found.");
    //}
    //nonprimitive not container
    snapshot_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *SnapshotsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = snapshot_parseFromJSON(SnapshotsAPIlocalVarJSON);
        cJSON_Delete(SnapshotsAPIlocalVarJSON);
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
    free(localVarToReplace_snapshotId);
    if (localVarSingleItemJSON_v3_update_snapshot_request) {
        cJSON_Delete(localVarSingleItemJSON_v3_update_snapshot_request);
        localVarSingleItemJSON_v3_update_snapshot_request = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

