#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "ActivityV1API.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096


// Start activity export
//
activity_export_response_t*
ActivityV1API_v1ActivityExport(apiClient_t *apiClient, activity_export_dto_t *activity_export_dto)
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
    char *localVarPath = strdup("/v1/activity/export");





    // Body Param
    cJSON *localVarSingleItemJSON_activity_export_dto = NULL;
    if (activity_export_dto != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_activity_export_dto = activity_export_dto_convertToJSON(activity_export_dto);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_activity_export_dto);
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
    //    printf("%s\n","Success");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Forbidden");
    //}
    //nonprimitive not container
    activity_export_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ActivityV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = activity_export_response_parseFromJSON(ActivityV1APIlocalVarJSON);
        cJSON_Delete(ActivityV1APIlocalVarJSON);
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
    if (localVarSingleItemJSON_activity_export_dto) {
        cJSON_Delete(localVarSingleItemJSON_activity_export_dto);
        localVarSingleItemJSON_activity_export_dto = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Get resource activities
//
activity_list_t*
ActivityV1API_v1ActivityList(apiClient_t *apiClient, activity_request_t *request)
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
    char *localVarPath = strdup("/v1/activity");





    // query parameters
    char *keyQuery_request = NULL;
    activity_request_t * valueQuery_request ;
    keyValuePair_t *keyPairQuery_request = 0;
    if (request)
    {
        keyQuery_request = strdup("request");
        valueQuery_request = (request);
        keyPairQuery_request = keyValuePair_create(keyQuery_request, &valueQuery_request);
        list_addElement(localVarQueryParameters,keyPairQuery_request);
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
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Forbidden");
    //}
    //nonprimitive not container
    activity_list_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ActivityV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = activity_list_parseFromJSON(ActivityV1APIlocalVarJSON);
        cJSON_Delete(ActivityV1APIlocalVarJSON);
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
    if(keyQuery_request){
        free(keyQuery_request);
        keyQuery_request = NULL;
    }
    if(keyPairQuery_request){
        keyValuePair_free(keyPairQuery_request);
        keyPairQuery_request = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Download activity
//
// Download activity for a given task
//
activity_list_t*
ActivityV1API_v1DownloadActivity(apiClient_t *apiClient, char *taskId)
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
    char *localVarPath = strdup("/v1/activity/export/{taskId}/download");

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
    //    printf("%s\n","Success");
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
    activity_list_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ActivityV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = activity_list_parseFromJSON(ActivityV1APIlocalVarJSON);
        cJSON_Delete(ActivityV1APIlocalVarJSON);
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

// Get export task status
//
activity_list_t*
ActivityV1API_v1GetActivityExportStatus(apiClient_t *apiClient, char *taskId)
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
    char *localVarPath = strdup("/v1/activity/export/{taskId}");

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
    //    printf("%s\n","Success");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Forbidden");
    //}
    //nonprimitive not container
    activity_list_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ActivityV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = activity_list_parseFromJSON(ActivityV1APIlocalVarJSON);
        cJSON_Delete(ActivityV1APIlocalVarJSON);
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
activity_list_t*
ActivityV1API_v1GetActivityExportTasks(apiClient_t *apiClient)
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
    char *localVarPath = strdup("/v1/activity/export");




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
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Forbidden");
    //}
    //nonprimitive not container
    activity_list_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ActivityV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = activity_list_parseFromJSON(ActivityV1APIlocalVarJSON);
        cJSON_Delete(ActivityV1APIlocalVarJSON);
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

