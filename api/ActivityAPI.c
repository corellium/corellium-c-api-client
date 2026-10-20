#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "ActivityAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096


// Start activity export
//
// **Required role:** Domain administrator.  Starts building a file of activity records for download, for audits or offline analysis. Requires a domain administrator and the user-logging license feature (403 otherwise).  Choose the file format with the `Accept` header: `application/json` or `text/csv` (any other value returns 400). The body takes the same filters as `v3ListActivities`, but the export is not paginated: it contains every matching record.  **Workflow:** 1. `v3CreateActivityExport` (this call). Returns 201 with an `id` like `activity-export/<UUID>`. 2. Poll `v3GetActivityExportStatus` with the `<UUID>` part until `status` is `complete`. 3. `v3DownloadActivity` with the same UUID to get the file.
//
create_activity_export_response_t*
ActivityAPI_v3CreateActivityExport(apiClient_t *apiClient, char *accept, create_activity_export_body_t *create_activity_export_body)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = list_createList();
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/v3/activity/export");





    // header parameters
    char *keyHeader_accept = NULL;
    char * valueHeader_accept = 0;
    keyValuePair_t *keyPairHeader_accept = 0;
    if (accept) {
        keyHeader_accept = strdup("accept");
        valueHeader_accept = strdup((accept));
        keyPairHeader_accept = keyValuePair_create(keyHeader_accept, valueHeader_accept);
        list_addElement(localVarHeaderParameters,keyPairHeader_accept);
    }


    // Body Param
    cJSON *localVarSingleItemJSON_create_activity_export_body = NULL;
    if (create_activity_export_body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_create_activity_export_body = create_activity_export_body_convertToJSON(create_activity_export_body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_create_activity_export_body);
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
    //    printf("%s\n","Export task accepted.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Invalid request body or export rejected.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Domain administrator permissions required. Signed in, but not allowed to do this: you lack the required role, have no access to the project, or your license does not include the feature.");
    //}
    //nonprimitive not container
    create_activity_export_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ActivityAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = create_activity_export_response_parseFromJSON(ActivityAPIlocalVarJSON);
        cJSON_Delete(ActivityAPIlocalVarJSON);
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
    
    list_freeList(localVarHeaderParameters);
    
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyHeader_accept) {
        free(keyHeader_accept);
        keyHeader_accept = NULL;
    }
    if (valueHeader_accept) {
        free(valueHeader_accept);
        valueHeader_accept = NULL;
    }
    free(keyPairHeader_accept);
    if (localVarSingleItemJSON_create_activity_export_body) {
        cJSON_Delete(localVarSingleItemJSON_create_activity_export_body);
        localVarSingleItemJSON_create_activity_export_body = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Download activity for a given task
//
// **Required role:** Domain administrator.  Downloads the file produced by a finished activity export, as JSON or CSV depending on the format you asked for. Pass the UUID part of the export `id`. Returns 404 if the file is not ready or does not exist; check `v3GetActivityExportStatus` first. Requires a domain administrator and the user-logging license feature.
//
binary_t*
ActivityAPI_v3DownloadActivity(apiClient_t *apiClient, char *taskId)
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
    char *localVarPath = strdup("/v3/activity/export/{taskId}/download");

    if(!taskId)
        goto end;


    // Path Params
    long sizeOfPathParams_taskId = strlen(taskId)+3 + sizeof("{ taskId }") - 1;
    if(taskId == NULL) {
        goto end;
    }
    char* localVarToReplace_taskId = malloc(sizeOfPathParams_taskId);
    sprintf(localVarToReplace_taskId, "{%s}", "taskId");

    localVarPath = strReplace(localVarPath, localVarToReplace_taskId, taskId);


    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"text/csv"); //produces
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
    //    printf("%s\n","Activity export file download.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Unable to get image export type.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Domain administrator permissions required. Signed in, but not allowed to do this: you lack the required role, have no access to the project, or your license does not include the feature.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Task not found.");
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
    
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_taskId);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Get export task status
//
// **Required role:** Domain administrator.  Returns the status of an activity export started with `v3CreateActivityExport`. Pass the UUID part of the export `id`. Poll until `status` is `complete`, then call `v3DownloadActivity`. Finished tasks are cleaned up, so a task that no longer exists is reported as `complete`. Requires a domain administrator and the user-logging license feature.
//
activity_export_status_t*
ActivityAPI_v3GetActivityExportStatus(apiClient_t *apiClient, char *taskId)
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
    char *localVarPath = strdup("/v3/activity/export/{taskId}");

    if(!taskId)
        goto end;


    // Path Params
    long sizeOfPathParams_taskId = strlen(taskId)+3 + sizeof("{ taskId }") - 1;
    if(taskId == NULL) {
        goto end;
    }
    char* localVarToReplace_taskId = malloc(sizeOfPathParams_taskId);
    sprintf(localVarToReplace_taskId, "{%s}", "taskId");

    localVarPath = strReplace(localVarPath, localVarToReplace_taskId, taskId);


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
    //    printf("%s\n","Task status.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Domain administrator permissions required. Signed in, but not allowed to do this: you lack the required role, have no access to the project, or your license does not include the feature.");
    //}
    //nonprimitive not container
    activity_export_status_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ActivityAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = activity_export_status_parseFromJSON(ActivityAPIlocalVarJSON);
        cJSON_Delete(ActivityAPIlocalVarJSON);
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
    free(localVarToReplace_taskId);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Get all export tasks for user
//
// **Required role:** Domain administrator.  Lists the activity exports you have started, with each one's status and the filters it used. Requires a domain administrator and the user-logging license feature. Results are paginated with `limit` and `offset`.
//
activity_export_task_list_t*
ActivityAPI_v3GetActivityExportTasks(apiClient_t *apiClient, double *limit, double *offset)
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
    char *localVarPath = strdup("/v3/activity/export");





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
    //    printf("%s\n","List of export tasks.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Domain administrator permissions required. Signed in, but not allowed to do this: you lack the required role, have no access to the project, or your license does not include the feature.");
    //}
    //nonprimitive not container
    activity_export_task_list_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ActivityAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = activity_export_task_list_parseFromJSON(ActivityAPIlocalVarJSON);
        cJSON_Delete(ActivityAPIlocalVarJSON);
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

// Get resource activities
//
// Returns the activity log: a record of what happened in your domain, such as devices created, started and deleted, users signing in, and settings changed, with who did it and when. You only see events your role allows. Filter by device, project, user, time range or free text, and page with `limit` and `offset`. For a full download of many records, use `v3CreateActivityExport` instead.
//
activity_list_response_t*
ActivityAPI_v3ListActivities(apiClient_t *apiClient, char *resource, double *limit, double *offset, char *orderBy, char *instanceId, char *projectId, char *actor, char *search, char to, char from)
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
    char *localVarPath = strdup("/v3/activity");





    // query parameters
    char *keyQuery_resource = NULL;
    char * valueQuery_resource = NULL;
    keyValuePair_t *keyPairQuery_resource = 0;
    if (resource)
    {
        keyQuery_resource = strdup("resource");
        valueQuery_resource = strdup((resource));
        keyPairQuery_resource = keyValuePair_create(keyQuery_resource, valueQuery_resource);
        list_addElement(localVarQueryParameters,keyPairQuery_resource);
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

    // query parameters
    char *keyQuery_orderBy = NULL;
    char * valueQuery_orderBy = NULL;
    keyValuePair_t *keyPairQuery_orderBy = 0;
    if (orderBy)
    {
        keyQuery_orderBy = strdup("orderBy");
        valueQuery_orderBy = strdup((orderBy));
        keyPairQuery_orderBy = keyValuePair_create(keyQuery_orderBy, valueQuery_orderBy);
        list_addElement(localVarQueryParameters,keyPairQuery_orderBy);
    }

    // query parameters
    char *keyQuery_instanceId = NULL;
    char * valueQuery_instanceId = NULL;
    keyValuePair_t *keyPairQuery_instanceId = 0;
    if (instanceId)
    {
        keyQuery_instanceId = strdup("instanceId");
        valueQuery_instanceId = strdup((instanceId));
        keyPairQuery_instanceId = keyValuePair_create(keyQuery_instanceId, valueQuery_instanceId);
        list_addElement(localVarQueryParameters,keyPairQuery_instanceId);
    }

    // query parameters
    char *keyQuery_projectId = NULL;
    char * valueQuery_projectId = NULL;
    keyValuePair_t *keyPairQuery_projectId = 0;
    if (projectId)
    {
        keyQuery_projectId = strdup("projectId");
        valueQuery_projectId = strdup((projectId));
        keyPairQuery_projectId = keyValuePair_create(keyQuery_projectId, valueQuery_projectId);
        list_addElement(localVarQueryParameters,keyPairQuery_projectId);
    }

    // query parameters
    char *keyQuery_actor = NULL;
    char * valueQuery_actor = NULL;
    keyValuePair_t *keyPairQuery_actor = 0;
    if (actor)
    {
        keyQuery_actor = strdup("actor");
        valueQuery_actor = strdup((actor));
        keyPairQuery_actor = keyValuePair_create(keyQuery_actor, valueQuery_actor);
        list_addElement(localVarQueryParameters,keyPairQuery_actor);
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
    char *keyQuery_to = NULL;
    char valueQuery_to ;
    keyValuePair_t *keyPairQuery_to = 0;
    if (to)
    {
        keyQuery_to = strdup("to");
        valueQuery_to = (to);
        keyPairQuery_to = keyValuePair_create(keyQuery_to, &valueQuery_to);
        list_addElement(localVarQueryParameters,keyPairQuery_to);
    }

    // query parameters
    char *keyQuery_from = NULL;
    char valueQuery_from ;
    keyValuePair_t *keyPairQuery_from = 0;
    if (from)
    {
        keyQuery_from = strdup("from");
        valueQuery_from = (from);
        keyPairQuery_from = keyValuePair_create(keyQuery_from, &valueQuery_from);
        list_addElement(localVarQueryParameters,keyPairQuery_from);
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
    //    printf("%s\n","List of activities.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Invalid query parameter(s) or column name.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Signed in, but not allowed to do this: you lack the required role, have no access to the project, or your license does not include the feature.");
    //}
    //nonprimitive not container
    activity_list_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ActivityAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = activity_list_response_parseFromJSON(ActivityAPIlocalVarJSON);
        cJSON_Delete(ActivityAPIlocalVarJSON);
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
    if(keyQuery_resource){
        free(keyQuery_resource);
        keyQuery_resource = NULL;
    }
    if(valueQuery_resource){
        free(valueQuery_resource);
        valueQuery_resource = NULL;
    }
    if(keyPairQuery_resource){
        keyValuePair_free(keyPairQuery_resource);
        keyPairQuery_resource = NULL;
    }
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
    if(keyQuery_orderBy){
        free(keyQuery_orderBy);
        keyQuery_orderBy = NULL;
    }
    if(valueQuery_orderBy){
        free(valueQuery_orderBy);
        valueQuery_orderBy = NULL;
    }
    if(keyPairQuery_orderBy){
        keyValuePair_free(keyPairQuery_orderBy);
        keyPairQuery_orderBy = NULL;
    }
    if(keyQuery_instanceId){
        free(keyQuery_instanceId);
        keyQuery_instanceId = NULL;
    }
    if(valueQuery_instanceId){
        free(valueQuery_instanceId);
        valueQuery_instanceId = NULL;
    }
    if(keyPairQuery_instanceId){
        keyValuePair_free(keyPairQuery_instanceId);
        keyPairQuery_instanceId = NULL;
    }
    if(keyQuery_projectId){
        free(keyQuery_projectId);
        keyQuery_projectId = NULL;
    }
    if(valueQuery_projectId){
        free(valueQuery_projectId);
        valueQuery_projectId = NULL;
    }
    if(keyPairQuery_projectId){
        keyValuePair_free(keyPairQuery_projectId);
        keyPairQuery_projectId = NULL;
    }
    if(keyQuery_actor){
        free(keyQuery_actor);
        keyQuery_actor = NULL;
    }
    if(valueQuery_actor){
        free(valueQuery_actor);
        valueQuery_actor = NULL;
    }
    if(keyPairQuery_actor){
        keyValuePair_free(keyPairQuery_actor);
        keyPairQuery_actor = NULL;
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
    if(keyQuery_to){
        free(keyQuery_to);
        keyQuery_to = NULL;
    }
    if(keyPairQuery_to){
        keyValuePair_free(keyPairQuery_to);
        keyPairQuery_to = NULL;
    }
    if(keyQuery_from){
        free(keyQuery_from);
        keyQuery_from = NULL;
    }
    if(keyPairQuery_from){
        keyValuePair_free(keyPairQuery_from);
        keyPairQuery_from = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

