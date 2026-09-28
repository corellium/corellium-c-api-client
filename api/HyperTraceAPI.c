#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "HyperTraceAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096


// Pre-authorize a btrace download
//
token_t*
HyperTraceAPI_v3BtracePreauthorize(apiClient_t *apiClient, char *instanceId)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/btrace-authorize");

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
    //    printf("%s\n","Token.");
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
    token_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *HyperTraceAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = token_parseFromJSON(HyperTraceAPIlocalVarJSON);
        cJSON_Delete(HyperTraceAPIlocalVarJSON);
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
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Clear HyperTrace logs
//
// Clear HyperTrace logs. An unknown `instanceId` is a successful no-op that returns 204.
//
void
HyperTraceAPI_v3ClearHyperTrace(apiClient_t *apiClient, char *instanceId)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/btrace");

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
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Authentication required.");
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

}

// Get Kernel extension ranges
//
list_t*
HyperTraceAPI_v3GetInstanceKcrange(apiClient_t *apiClient, char *instanceId)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/btrace-kcrange");

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
    //    printf("%s\n","Kcranges.");
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
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Instance not found.");
    //}
    list_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *HyperTraceAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        if(!cJSON_IsArray(HyperTraceAPIlocalVarJSON)) {
            return 0;//nonprimitive container
        }
        elementToReturn = list_createList();
        cJSON *VarJSON;
        cJSON_ArrayForEach(VarJSON, HyperTraceAPIlocalVarJSON)
        {
            if(!cJSON_IsObject(VarJSON))
            {
               // return 0;
            }
            char *localVarJSONToChar = cJSON_Print(VarJSON);
            list_addElement(elementToReturn , localVarJSONToChar);
        }

        cJSON_Delete( HyperTraceAPIlocalVarJSON);
        cJSON_Delete( VarJSON);
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
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Start HyperTrace on an instance
//
void
HyperTraceAPI_v3StartHyperTrace(apiClient_t *apiClient, char *instanceId, enable_btrace_body_t *enable_btrace_body)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/btrace/enable");

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
    cJSON *localVarSingleItemJSON_enable_btrace_body = NULL;
    if (enable_btrace_body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_enable_btrace_body = enable_btrace_body_convertToJSON(enable_btrace_body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_enable_btrace_body);
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
    list_freeList(localVarContentType);
    free(localVarPath);
    free(localVarToReplace_instanceId);
    if (localVarSingleItemJSON_enable_btrace_body) {
        cJSON_Delete(localVarSingleItemJSON_enable_btrace_body);
        localVarSingleItemJSON_enable_btrace_body = NULL;
    }
    free(localVarBodyParameters);

}

// Stop HyperTrace on an instance.
//
void
HyperTraceAPI_v3StopHyperTrace(apiClient_t *apiClient, char *instanceId)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/btrace/disable");

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

}

