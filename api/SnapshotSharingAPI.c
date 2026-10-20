#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "SnapshotSharingAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096


// Accept a shared snapshot
//
// Checks that you may use a snapshot someone shared with you, using the access code they gave you (and the password, for `passwordPublicLink`). Returns the snapshot.  To create a device from it, call `POST /v3/instances` with `sharedSnapshot` set to the snapshot's `id` (and `sharedSnapshotPassword` for password-protected shares). Returns 403 if the snapshot is not shared with you, for example it is limited to another domain or you are not on its member list.
//
snapshot_t*
SnapshotSharingAPI_v3AcceptSharedSnapshot(apiClient_t *apiClient, accept_snapshot_body_t *accept_snapshot_body)
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
    char *localVarPath = strdup("/v3/snapshots/accept");





    // Body Param
    cJSON *localVarSingleItemJSON_accept_snapshot_body = NULL;
    if (accept_snapshot_body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_accept_snapshot_body = accept_snapshot_body_convertToJSON(accept_snapshot_body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_accept_snapshot_body);
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
    //    printf("%s\n","Successfully accepted shared snapshot.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","The request was invalid, for example a missing or malformed field. The body says which field; fix it before retrying.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Signed in, but not allowed to do this: you lack the required role, have no access to the project, or your license does not include the feature.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Snapshot not found.");
    //}
    //nonprimitive not container
    snapshot_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *SnapshotSharingAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = snapshot_parseFromJSON(SnapshotSharingAPIlocalVarJSON);
        cJSON_Delete(SnapshotSharingAPIlocalVarJSON);
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
    if (localVarSingleItemJSON_accept_snapshot_body) {
        cJSON_Delete(localVarSingleItemJSON_accept_snapshot_body);
        localVarSingleItemJSON_accept_snapshot_body = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Delete member(s)
//
// Deletes one or more members from the list of members who have access to the snapshot.  Members that do not currently have access are ignored rather than reported as an error. Deletes are idempotent: an unknown `snapshotId` is a successful no-op that still returns 204, and repeated calls return 204 as well. A 404 means the request path did not match a delete route, not that the target was missing.
//
void
SnapshotSharingAPI_v3DeleteSnapshotPermissions(apiClient_t *apiClient, char *snapshotId, set_snapshot_permissions_body_t *set_snapshot_permissions_body)
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
    char *localVarPath = strdup("/v3/snapshots/{snapshotId}/permissions");

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
    cJSON *localVarSingleItemJSON_set_snapshot_permissions_body = NULL;
    if (set_snapshot_permissions_body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_set_snapshot_permissions_body = set_snapshot_permissions_body_convertToJSON(set_snapshot_permissions_body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_set_snapshot_permissions_body);
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
    //    printf("%s\n","Member(s) removed from the snapshot; empty body.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Invalid request body, or malformed snapshot ID.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Signed in, but not allowed to do this: you lack the required role, have no access to the project, or your license does not include the feature.");
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
    free(localVarToReplace_snapshotId);
    if (localVarSingleItemJSON_set_snapshot_permissions_body) {
        cJSON_Delete(localVarSingleItemJSON_set_snapshot_permissions_body);
        localVarSingleItemJSON_set_snapshot_permissions_body = NULL;
    }
    free(localVarBodyParameters);

}

// Fetch shared snapshots
//
// Lists snapshots involving you: `sharedWithUser` holds snapshots other people shared with you, and `sharedByUser` holds snapshots you shared. Use it to find a snapshot to create a device from, or to review what you are sharing.
//
shared_snapshots_response_t*
SnapshotSharingAPI_v3GetSharedSnapshots(apiClient_t *apiClient)
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
    char *localVarPath = strdup("/v3/snapshots/shared");




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
    //    printf("%s\n","Successfully retrieved shared snapshots.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Signed in, but not allowed to do this: you lack the required role, have no access to the project, or your license does not include the feature.");
    //}
    //nonprimitive not container
    shared_snapshots_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *SnapshotSharingAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = shared_snapshots_response_parseFromJSON(SnapshotSharingAPIlocalVarJSON);
        cJSON_Delete(SnapshotSharingAPIlocalVarJSON);
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
// Sets who may use a snapshot shared by email invitation: send the full list of members, by email address or user ID. The list replaces the previous one. If the snapshot was not shared yet, this shares it with sharing type `emailInvite`. Returns the snapshot with its updated `sharing` details.
//
snapshot_t*
SnapshotSharingAPI_v3SetSnapshotPermissions(apiClient_t *apiClient, char *snapshotId, set_snapshot_permissions_body_t *set_snapshot_permissions_body)
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
    char *localVarPath = strdup("/v3/snapshots/{snapshotId}/permissions");

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
    cJSON *localVarSingleItemJSON_set_snapshot_permissions_body = NULL;
    if (set_snapshot_permissions_body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_set_snapshot_permissions_body = set_snapshot_permissions_body_convertToJSON(set_snapshot_permissions_body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_set_snapshot_permissions_body);
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
    //    printf("%s\n","Successfully updated the members who have access to the snapshot.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","The request was invalid, for example a missing or malformed field. The body says which field; fix it before retrying.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Signed in, but not allowed to do this: you lack the required role, have no access to the project, or your license does not include the feature.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Snapshot not found.");
    //}
    //nonprimitive not container
    snapshot_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *SnapshotSharingAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = snapshot_parseFromJSON(SnapshotSharingAPIlocalVarJSON);
        cJSON_Delete(SnapshotSharingAPIlocalVarJSON);
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
    if (localVarSingleItemJSON_set_snapshot_permissions_body) {
        cJSON_Delete(localVarSingleItemJSON_set_snapshot_permissions_body);
        localVarSingleItemJSON_set_snapshot_permissions_body = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Create or update snapshot sharing
//
// Shares one of your snapshots so other people can create devices from it, or stops sharing it. Choose who can use it with `sharingType` (see `SnapshotSharingType`); for `passwordPublicLink` also set `password`. The response is the snapshot with its `sharing` details, including the `accessCode` to give to the people you share with. Send `notShared` to stop sharing. Returns 403 if snapshot sharing, or that sharing type, is not enabled for your domain or license.
//
snapshot_t*
SnapshotSharingAPI_v3ShareSnapshot(apiClient_t *apiClient, char *snapshotId, share_snapshot_body_t *share_snapshot_body)
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
    char *localVarPath = strdup("/v3/snapshots/{snapshotId}/share");

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
    cJSON *localVarSingleItemJSON_share_snapshot_body = NULL;
    if (share_snapshot_body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_share_snapshot_body = share_snapshot_body_convertToJSON(share_snapshot_body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_share_snapshot_body);
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
    //    printf("%s\n","Snapshot sharing configuration updated.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","The request was invalid, for example a missing or malformed field. The body says which field; fix it before retrying.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Signed in, but not allowed to do this: you lack the required role, have no access to the project, or your license does not include the feature.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Snapshot not found.");
    //}
    //nonprimitive not container
    snapshot_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *SnapshotSharingAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = snapshot_parseFromJSON(SnapshotSharingAPIlocalVarJSON);
        cJSON_Delete(SnapshotSharingAPIlocalVarJSON);
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
    if (localVarSingleItemJSON_share_snapshot_body) {
        cJSON_Delete(localVarSingleItemJSON_share_snapshot_body);
        localVarSingleItemJSON_share_snapshot_body = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

