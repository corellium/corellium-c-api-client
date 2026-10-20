#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "SnapshotSharingV1API.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096


// Accept a snapshot shared with you
//
snapshot_v1_t*
SnapshotSharingV1API_v1AcceptSharedSnapshot(apiClient_t *apiClient, accept_snapshot_request_payload_t *accept_snapshot_request_payload)
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
    char *localVarPath = strdup("/v1/snapshots/accept");





    // Body Param
    cJSON *localVarSingleItemJSON_accept_snapshot_request_payload = NULL;
    if (accept_snapshot_request_payload != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_accept_snapshot_request_payload = accept_snapshot_request_payload_convertToJSON(accept_snapshot_request_payload);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_accept_snapshot_request_payload);
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
    //    printf("%s\n","application/json");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
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
    snapshot_v1_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *SnapshotSharingV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = snapshot_v1_parseFromJSON(SnapshotSharingV1APIlocalVarJSON);
        cJSON_Delete(SnapshotSharingV1APIlocalVarJSON);
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
    if (localVarSingleItemJSON_accept_snapshot_request_payload) {
        cJSON_Delete(localVarSingleItemJSON_accept_snapshot_request_payload);
        localVarSingleItemJSON_accept_snapshot_request_payload = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Delete member(s)
//
// Deletes one or more members from the list of members who have access to the snapshot
//
snapshot_v1_t*
SnapshotSharingV1API_v1DeleteSnapshotPermissions(apiClient_t *apiClient, char *snapshotId, snapshot_permissions_request_payload_t *snapshot_permissions_request_payload)
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
    char *localVarPath = strdup("/v1/snapshots/{snapshotId}/permissions");

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
    cJSON *localVarSingleItemJSON_snapshot_permissions_request_payload = NULL;
    if (snapshot_permissions_request_payload != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_snapshot_permissions_request_payload = snapshot_permissions_request_payload_convertToJSON(snapshot_permissions_request_payload);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_snapshot_permissions_request_payload);
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
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","application/json");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
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
    snapshot_v1_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *SnapshotSharingV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = snapshot_v1_parseFromJSON(SnapshotSharingV1APIlocalVarJSON);
        cJSON_Delete(SnapshotSharingV1APIlocalVarJSON);
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
    if (localVarSingleItemJSON_snapshot_permissions_request_payload) {
        cJSON_Delete(localVarSingleItemJSON_snapshot_permissions_request_payload);
        localVarSingleItemJSON_snapshot_permissions_request_payload = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Fetch shared snapshots
//
// Fetch snapshots shared with and shared by the requesting user
//
user_snapshots_t*
SnapshotSharingV1API_v1GetSharedSnapshots(apiClient_t *apiClient)
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
    char *localVarPath = strdup("/v1/snapshots/shared");




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
    //    printf("%s\n","application/json");
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
    user_snapshots_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *SnapshotSharingV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = user_snapshots_parseFromJSON(SnapshotSharingV1APIlocalVarJSON);
        cJSON_Delete(SnapshotSharingV1APIlocalVarJSON);
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

// Set member list
//
// Sets the list of members who have access to the snapshot
//
snapshot_v1_t*
SnapshotSharingV1API_v1SetSnapshotPermissions(apiClient_t *apiClient, char *snapshotId, snapshot_permissions_request_payload_t *snapshot_permissions_request_payload)
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
    char *localVarPath = strdup("/v1/snapshots/{snapshotId}/permissions");

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
    cJSON *localVarSingleItemJSON_snapshot_permissions_request_payload = NULL;
    if (snapshot_permissions_request_payload != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_snapshot_permissions_request_payload = snapshot_permissions_request_payload_convertToJSON(snapshot_permissions_request_payload);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_snapshot_permissions_request_payload);
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
    //    printf("%s\n","application/json");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
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
    snapshot_v1_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *SnapshotSharingV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = snapshot_v1_parseFromJSON(SnapshotSharingV1APIlocalVarJSON);
        cJSON_Delete(SnapshotSharingV1APIlocalVarJSON);
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
    if (localVarSingleItemJSON_snapshot_permissions_request_payload) {
        cJSON_Delete(localVarSingleItemJSON_snapshot_permissions_request_payload);
        localVarSingleItemJSON_snapshot_permissions_request_payload = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Share snapshot
//
// Share a snapshot
//
snapshot_v1_t*
SnapshotSharingV1API_v1ShareSnapshot(apiClient_t *apiClient, char *snapshotId, post_share_snapshot_request_payload_t *post_share_snapshot_request_payload)
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
    char *localVarPath = strdup("/v1/snapshots/{snapshotId}/share");

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
    cJSON *localVarSingleItemJSON_post_share_snapshot_request_payload = NULL;
    if (post_share_snapshot_request_payload != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_post_share_snapshot_request_payload = post_share_snapshot_request_payload_convertToJSON(post_share_snapshot_request_payload);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_post_share_snapshot_request_payload);
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
    //    printf("%s\n","application/json");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
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
    snapshot_v1_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *SnapshotSharingV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = snapshot_v1_parseFromJSON(SnapshotSharingV1APIlocalVarJSON);
        cJSON_Delete(SnapshotSharingV1APIlocalVarJSON);
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
    if (localVarSingleItemJSON_post_share_snapshot_request_payload) {
        cJSON_Delete(localVarSingleItemJSON_post_share_snapshot_request_payload);
        localVarSingleItemJSON_post_share_snapshot_request_payload = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

