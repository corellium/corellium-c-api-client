#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "AgentAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096


// Delete a file on VM
//
// Delete a file from the VM filesystem.  Deletes are idempotent: an unknown `instanceId`, or a path the on-device agent no longer has, is a successful no-op that still returns 204, and repeated calls return 204 as well. A 404 means the request path did not match a delete route, not that the target was missing. Other agent-reported failures, and an unreachable agent, are still reported as failures.
//
void
AgentAPI_v3DeleteFileAgent(apiClient_t *apiClient, char *instanceId, char *filePath)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/agent/v1/file/device/{filePath}");

    if(!instanceId)
        goto end;
    if(!filePath)
        goto end;


    // Path Params
    long sizeOfPathParams_instanceId = strlen(instanceId)+3 + strlen(filePath)+3 + sizeof("{ instanceId }") - 1;
    if(instanceId == NULL) {
        goto end;
    }
    char* localVarToReplace_instanceId = malloc(sizeOfPathParams_instanceId);
    sprintf(localVarToReplace_instanceId, "{%s}", "instanceId");

    localVarPath = strReplace(localVarPath, localVarToReplace_instanceId, instanceId);

    // Path Params
    long sizeOfPathParams_filePath = strlen(instanceId)+3 + strlen(filePath)+3 + sizeof("{ filePath }") - 1;
    if(filePath == NULL) {
        goto end;
    }
    char* localVarToReplace_filePath = malloc(sizeOfPathParams_filePath);
    sprintf(localVarToReplace_filePath, "{%s}", "filePath");

    localVarPath = strReplace(localVarPath, localVarToReplace_filePath, filePath);


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
    //    printf("%s\n","File deleted successfully.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Agent error.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
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
    
    free(localVarPath);
    free(localVarToReplace_instanceId);
    free(localVarToReplace_filePath);

}

// Get ADB auth setting
//
// Get the current ADB authorization setting (Android only).
//
agent_system_adb_auth_t*
AgentAPI_v3GetAdbAuthAgent(apiClient_t *apiClient, char *instanceId)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/agent/v1/system/adbauth");

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
    //    printf("%s\n","Current ADB auth setting.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Agent error.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Signed in, but not allowed to do this: you lack the required role, have no access to the project, or your license does not include the feature.");
    //}
    //nonprimitive not container
    agent_system_adb_auth_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *AgentAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = agent_system_adb_auth_parseFromJSON(AgentAPIlocalVarJSON);
        cJSON_Delete(AgentAPIlocalVarJSON);
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

// Check if app subsystem is ready
//
// Checks whether the device's agent is ready to manage apps. The agent is a helper service running inside the device that carries out the Agent calls (installing and running apps, reading and writing files, and so on). It starts after the device boots, so a device that just turned `on` may not be ready yet. Call this first and wait until it reports ready before using the other Agent endpoints.
//
agent_app_ready_response_t*
AgentAPI_v3GetAppReadyAgent(apiClient_t *apiClient, char *instanceId)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/agent/v1/app/ready");

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
    //    printf("%s\n","App agent state.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Agent error.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Signed in, but not allowed to do this: you lack the required role, have no access to the project, or your license does not include the feature.");
    //}
    //nonprimitive not container
    agent_app_ready_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *AgentAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = agent_app_ready_response_parseFromJSON(AgentAPIlocalVarJSON);
        cJSON_Delete(AgentAPIlocalVarJSON);
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

// Get container health
//
// Check whether a nested container is healthy (Android only).
//
agent_container_health_t*
AgentAPI_v3GetContainerHealthAgent(apiClient_t *apiClient, char *instanceId, char *containerId)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/agent/v1/container/containers/{containerId}/is-healthy");

    if(!instanceId)
        goto end;
    if(!containerId)
        goto end;


    // Path Params
    long sizeOfPathParams_instanceId = strlen(instanceId)+3 + strlen(containerId)+3 + sizeof("{ instanceId }") - 1;
    if(instanceId == NULL) {
        goto end;
    }
    char* localVarToReplace_instanceId = malloc(sizeOfPathParams_instanceId);
    sprintf(localVarToReplace_instanceId, "{%s}", "instanceId");

    localVarPath = strReplace(localVarPath, localVarToReplace_instanceId, instanceId);

    // Path Params
    long sizeOfPathParams_containerId = strlen(instanceId)+3 + strlen(containerId)+3 + sizeof("{ containerId }") - 1;
    if(containerId == NULL) {
        goto end;
    }
    char* localVarToReplace_containerId = malloc(sizeOfPathParams_containerId);
    sprintf(localVarToReplace_containerId, "{%s}", "containerId");

    localVarPath = strReplace(localVarPath, localVarToReplace_containerId, containerId);


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
    //    printf("%s\n","Container health.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Agent error.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Signed in, but not allowed to do this: you lack the required role, have no access to the project, or your license does not include the feature.");
    //}
    //nonprimitive not container
    agent_container_health_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *AgentAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = agent_container_health_parseFromJSON(AgentAPIlocalVarJSON);
        cJSON_Delete(AgentAPIlocalVarJSON);
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
    free(localVarToReplace_containerId);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Download a file from VM
//
// Downloads one file from the device's filesystem, given its full path on the device (for example `/tmp/log.txt`). The response body is the raw file. For large files, use `v3PreauthorizeFileDownloadAgent` so the download does not have to pass through your SDK client.
//
binary_t*
AgentAPI_v3GetFileAgent(apiClient_t *apiClient, char *instanceId, char *filePath)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/agent/v1/file/device/{filePath}");

    if(!instanceId)
        goto end;
    if(!filePath)
        goto end;


    // Path Params
    long sizeOfPathParams_instanceId = strlen(instanceId)+3 + strlen(filePath)+3 + sizeof("{ instanceId }") - 1;
    if(instanceId == NULL) {
        goto end;
    }
    char* localVarToReplace_instanceId = malloc(sizeOfPathParams_instanceId);
    sprintf(localVarToReplace_instanceId, "{%s}", "instanceId");

    localVarPath = strReplace(localVarPath, localVarToReplace_instanceId, instanceId);

    // Path Params
    long sizeOfPathParams_filePath = strlen(instanceId)+3 + strlen(filePath)+3 + sizeof("{ filePath }") - 1;
    if(filePath == NULL) {
        goto end;
    }
    char* localVarToReplace_filePath = malloc(sizeOfPathParams_filePath);
    sprintf(localVarToReplace_filePath, "{%s}", "filePath");

    localVarPath = strReplace(localVarPath, localVarToReplace_filePath, filePath);


    list_addElement(localVarHeaderType,"application/octet-stream"); //produces
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
    //    printf("%s\n","File contents.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Agent error.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Signed in, but not allowed to do this: you lack the required role, have no access to the project, or your license does not include the feature.");
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
    free(localVarToReplace_instanceId);
    free(localVarToReplace_filePath);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Get eth0 IP address
//
// Get the IP address bound to eth0 (Android only).
//
agent_system_network_response_t*
AgentAPI_v3GetNetworkAgent(apiClient_t *apiClient, char *instanceId)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/agent/v1/system/network");

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
    //    printf("%s\n","IP address of eth0.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Agent error.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Signed in, but not allowed to do this: you lack the required role, have no access to the project, or your license does not include the feature.");
    //}
    //nonprimitive not container
    agent_system_network_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *AgentAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = agent_system_network_response_parseFromJSON(AgentAPIlocalVarJSON);
        cJSON_Delete(AgentAPIlocalVarJSON);
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

// Get a system property
//
// Get the value of a system property (Android only).
//
agent_system_get_prop_response_t*
AgentAPI_v3GetPropAgent(apiClient_t *apiClient, char *instanceId, agent_system_get_prop_body_t *agent_system_get_prop_body)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/agent/v1/system/getprop");

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
    cJSON *localVarSingleItemJSON_agent_system_get_prop_body = NULL;
    if (agent_system_get_prop_body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_agent_system_get_prop_body = agent_system_get_prop_body_convertToJSON(agent_system_get_prop_body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_agent_system_get_prop_body);
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
    //    printf("%s\n","Value of the requested property.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Agent error.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Signed in, but not allowed to do this: you lack the required role, have no access to the project, or your license does not include the feature.");
    //}
    //nonprimitive not container
    agent_system_get_prop_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *AgentAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = agent_system_get_prop_response_parseFromJSON(AgentAPIlocalVarJSON);
        cJSON_Delete(AgentAPIlocalVarJSON);
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
    if (localVarSingleItemJSON_agent_system_get_prop_body) {
        cJSON_Delete(localVarSingleItemJSON_agent_system_get_prop_body);
        localVarSingleItemJSON_agent_system_get_prop_body = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Get Remote.It status
//
// Get the installation status of the Remote.It package on the VM (RPi only).
//
agent_remote_it_status_t*
AgentAPI_v3GetRemoteItStatusAgent(apiClient_t *apiClient, char *instanceId)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/agent/v1/remoteit/status");

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
    //    printf("%s\n","Current Remote.It status.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Agent error.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Signed in, but not allowed to do this: you lack the required role, have no access to the project, or your license does not include the feature.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","The resource does not exist, or you cannot see it.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 405) {
    //    printf("%s\n","Method not allowed.");
    //}
    //nonprimitive not container
    agent_remote_it_status_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *AgentAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = agent_remote_it_status_parseFromJSON(AgentAPIlocalVarJSON);
        cJSON_Delete(AgentAPIlocalVarJSON);
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

// Get a temp file path on VM
//
// Returns an unused temporary file path on the device, free at the moment of the call. Use it as the target for `v3UploadFileAgent`, for example to stage an app package before `v3InstallAgent`.
//
agent_temp_file_response_t*
AgentAPI_v3GetTempFileAgent(apiClient_t *apiClient, char *instanceId)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/agent/v1/file/temp");

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
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","Temporary file path.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Agent error.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Signed in, but not allowed to do this: you lack the required role, have no access to the project, or your license does not include the feature.");
    //}
    //nonprimitive not container
    agent_temp_file_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *AgentAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = agent_temp_file_response_parseFromJSON(AgentAPIlocalVarJSON);
        cJSON_Delete(AgentAPIlocalVarJSON);
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

// Install app at path
//
// Installs an app from a package file that is already on the device, for example an `.ipa` (iOS) or `.apk` (Android). Returns 204 once installed.  **Installing an app from your computer:** 1. `v3GetAppReadyAgent`: wait until the agent is ready. 2. `v3GetTempFileAgent`: get a free temporary path on the device. 3. `v3UploadFileAgent`: upload the package to that path. 4. `v3InstallAgent` (this call) with that `path`. 5. `v3ListAppsAgent` to find the app's bundle ID, then `v3RunAppAgent` to start it.
//
void
AgentAPI_v3InstallAgent(apiClient_t *apiClient, char *instanceId, agent_install_body_t *agent_install_body)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/agent/v1/app/install");

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
    cJSON *localVarSingleItemJSON_agent_install_body = NULL;
    if (agent_install_body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_agent_install_body = agent_install_body_convertToJSON(agent_install_body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_agent_install_body);
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
    //    printf("%s\n","App installed successfully.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Agent error.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
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
    free(localVarToReplace_instanceId);
    if (localVarSingleItemJSON_agent_install_body) {
        cJSON_Delete(localVarSingleItemJSON_agent_install_body);
        localVarSingleItemJSON_agent_install_body = NULL;
    }
    free(localVarBodyParameters);

}

// Install OpenGApps
//
// Download and install OpenGApps on the instance (Android only).
//
void
AgentAPI_v3InstallOpenGappsAgent(apiClient_t *apiClient, char *instanceId, agent_system_install_open_gapps_body_t *agent_system_install_open_gapps_body)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/agent/v1/system/install-opengapps");

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
    cJSON *localVarSingleItemJSON_agent_system_install_open_gapps_body = NULL;
    if (agent_system_install_open_gapps_body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_agent_system_install_open_gapps_body = agent_system_install_open_gapps_body_convertToJSON(agent_system_install_open_gapps_body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_agent_system_install_open_gapps_body);
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
    //    printf("%s\n","OpenGApps installation started successfully.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Agent error.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
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
    free(localVarToReplace_instanceId);
    if (localVarSingleItemJSON_agent_system_install_open_gapps_body) {
        cJSON_Delete(localVarSingleItemJSON_agent_system_install_open_gapps_body);
        localVarSingleItemJSON_agent_system_install_open_gapps_body = NULL;
    }
    free(localVarBodyParameters);

}

// Install a profile
//
// Install a configuration profile on the VM.
//
void
AgentAPI_v3InstallProfileAgent(apiClient_t *apiClient, char *instanceId, binary_t* body)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/agent/v1/profile/install");

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
    localVarBodyParameters = malloc(body->len);
    memcpy(localVarBodyParameters, body->data, body->len);
    localVarBodyLength = body->len;
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/octet-stream"); //consumes
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
    //    printf("%s\n","Profile installed successfully.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Agent error.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
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
    free(localVarToReplace_instanceId);
    free(localVarBodyParameters);

}

// Install Remote.It
//
// Install the Remote.It package on the VM (RPi only). The device name and platform code are derived server-side from the instance and its flavor.
//
agent_remote_it_status_t*
AgentAPI_v3InstallRemoteItAgent(apiClient_t *apiClient, char *instanceId)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/agent/v1/remoteit/install");

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
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","Remote.It status after install.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Agent error.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Signed in, but not allowed to do this: you lack the required role, have no access to the project, or your license does not include the feature.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","The resource does not exist, or you cannot see it.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 405) {
    //    printf("%s\n","Method not allowed.");
    //}
    //nonprimitive not container
    agent_remote_it_status_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *AgentAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = agent_remote_it_status_parseFromJSON(AgentAPIlocalVarJSON);
        cJSON_Delete(AgentAPIlocalVarJSON);
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

// Kill an app
//
// Force-quits a running app on the device, identified by its bundle ID. The app stays installed; start it again with `v3RunAppAgent`.
//
void
AgentAPI_v3KillAppAgent(apiClient_t *apiClient, char *instanceId, char *bundleId)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/agent/v1/app/apps/{bundleId}/kill");

    if(!instanceId)
        goto end;
    if(!bundleId)
        goto end;


    // Path Params
    long sizeOfPathParams_instanceId = strlen(instanceId)+3 + strlen(bundleId)+3 + sizeof("{ instanceId }") - 1;
    if(instanceId == NULL) {
        goto end;
    }
    char* localVarToReplace_instanceId = malloc(sizeOfPathParams_instanceId);
    sprintf(localVarToReplace_instanceId, "{%s}", "instanceId");

    localVarPath = strReplace(localVarPath, localVarToReplace_instanceId, instanceId);

    // Path Params
    long sizeOfPathParams_bundleId = strlen(instanceId)+3 + strlen(bundleId)+3 + sizeof("{ bundleId }") - 1;
    if(bundleId == NULL) {
        goto end;
    }
    char* localVarToReplace_bundleId = malloc(sizeOfPathParams_bundleId);
    sprintf(localVarToReplace_bundleId, "{%s}", "bundleId");

    localVarPath = strReplace(localVarPath, localVarToReplace_bundleId, bundleId);


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
    //    printf("%s\n","App killed successfully.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Agent error.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
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
    
    free(localVarPath);
    free(localVarToReplace_instanceId);
    free(localVarToReplace_bundleId);

}

// Kill Frida
//
// Stop the running Frida session on the VM.
//
agent_frida_response_t*
AgentAPI_v3KillFridaAgent(apiClient_t *apiClient, char *instanceId)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/agent/v1/frida/run-frida-kill");

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
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","Frida killed successfully.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Agent error.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Signed in, but not allowed to do this: you lack the required role, have no access to the project, or your license does not include the feature.");
    //}
    //nonprimitive not container
    agent_frida_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *AgentAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = agent_frida_response_parseFromJSON(AgentAPIlocalVarJSON);
        cJSON_Delete(AgentAPIlocalVarJSON);
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

// List app icons
//
// List app icons as base64-encoded data for the specified bundle IDs.
//
agent_icons_response_t*
AgentAPI_v3ListAppIconsAgent(apiClient_t *apiClient, char *instanceId, char *bundleId)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/agent/v1/app/icons");

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
    char *keyQuery_bundleId = NULL;
    char * valueQuery_bundleId = NULL;
    keyValuePair_t *keyPairQuery_bundleId = 0;
    if (bundleId)
    {
        keyQuery_bundleId = strdup("bundleId");
        valueQuery_bundleId = strdup((bundleId));
        keyPairQuery_bundleId = keyValuePair_create(keyQuery_bundleId, valueQuery_bundleId);
        list_addElement(localVarQueryParameters,keyPairQuery_bundleId);
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
    //    printf("%s\n","App icons keyed by bundle ID.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Agent error.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Signed in, but not allowed to do this: you lack the required role, have no access to the project, or your license does not include the feature.");
    //}
    //nonprimitive not container
    agent_icons_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *AgentAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = agent_icons_response_parseFromJSON(AgentAPIlocalVarJSON);
        cJSON_Delete(AgentAPIlocalVarJSON);
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
    if(keyQuery_bundleId){
        free(keyQuery_bundleId);
        keyQuery_bundleId = NULL;
    }
    if(valueQuery_bundleId){
        free(valueQuery_bundleId);
        valueQuery_bundleId = NULL;
    }
    if(keyPairQuery_bundleId){
        keyValuePair_free(keyPairQuery_bundleId);
        keyPairQuery_bundleId = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// List apps
//
// Lists the apps installed on the device, with each app's bundle ID (for example `com.android.egg`) and name. The bundle ID is what the run, kill and uninstall calls need.
//
agent_apps_list_t*
AgentAPI_v3ListAppsAgent(apiClient_t *apiClient, char *instanceId, char *loadIcons)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/agent/v1/app/apps");

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
    char *keyQuery_loadIcons = NULL;
    char * valueQuery_loadIcons = NULL;
    keyValuePair_t *keyPairQuery_loadIcons = 0;
    if (loadIcons)
    {
        keyQuery_loadIcons = strdup("loadIcons");
        valueQuery_loadIcons = strdup((loadIcons));
        keyPairQuery_loadIcons = keyValuePair_create(keyQuery_loadIcons, valueQuery_loadIcons);
        list_addElement(localVarQueryParameters,keyPairQuery_loadIcons);
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
    //    printf("%s\n","Installed apps info.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Agent error.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Signed in, but not allowed to do this: you lack the required role, have no access to the project, or your license does not include the feature.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","The agent returned an invalid app list.");
    //}
    //nonprimitive not container
    agent_apps_list_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *AgentAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = agent_apps_list_parseFromJSON(AgentAPIlocalVarJSON);
        cJSON_Delete(AgentAPIlocalVarJSON);
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
    if(keyQuery_loadIcons){
        free(keyQuery_loadIcons);
        keyQuery_loadIcons = NULL;
    }
    if(valueQuery_loadIcons){
        free(valueQuery_loadIcons);
        valueQuery_loadIcons = NULL;
    }
    if(keyPairQuery_loadIcons){
        keyValuePair_free(keyPairQuery_loadIcons);
        keyPairQuery_loadIcons = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// List apps status
//
// Returns, for every installed app, whether it is currently running. Use it to check that an app started after `v3RunAppAgent`, or stopped after `v3KillAppAgent`.
//
agent_apps_status_list_t*
AgentAPI_v3ListAppsStatusAgent(apiClient_t *apiClient, char *instanceId)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/agent/v1/app/apps/update");

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
    //    printf("%s\n","Installed apps status info.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Agent error.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Signed in, but not allowed to do this: you lack the required role, have no access to the project, or your license does not include the feature.");
    //}
    //nonprimitive not container
    agent_apps_status_list_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *AgentAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = agent_apps_status_list_parseFromJSON(AgentAPIlocalVarJSON);
        cJSON_Delete(AgentAPIlocalVarJSON);
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

// List containers
//
// List the nested containers on the VM (Android only).
//
agent_container_list_t*
AgentAPI_v3ListContainersAgent(apiClient_t *apiClient, char *instanceId)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/agent/v1/container/containers");

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
    //    printf("%s\n","List of containers.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Agent error.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Signed in, but not allowed to do this: you lack the required role, have no access to the project, or your license does not include the feature.");
    //}
    //nonprimitive not container
    agent_container_list_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *AgentAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = agent_container_list_parseFromJSON(AgentAPIlocalVarJSON);
        cJSON_Delete(AgentAPIlocalVarJSON);
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

// List Frida processes
//
// Run frida-ps on the VM and return the list of processes.
//
agent_frida_process_list_t*
AgentAPI_v3ListFridaProcessesAgent(apiClient_t *apiClient, char *instanceId)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/agent/v1/frida/run-frida-ps");

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
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","Frida process list.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Agent error.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Signed in, but not allowed to do this: you lack the required role, have no access to the project, or your license does not include the feature.");
    //}
    //nonprimitive not container
    agent_frida_process_list_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *AgentAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = agent_frida_process_list_parseFromJSON(AgentAPIlocalVarJSON);
        cJSON_Delete(AgentAPIlocalVarJSON);
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

// List profiles
//
// List the configuration profiles installed on the VM.
//
agent_profile_list_response_t*
AgentAPI_v3ListProfilesAgent(apiClient_t *apiClient, char *instanceId)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/agent/v1/profile/profiles");

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
    //    printf("%s\n","Installed profiles.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Agent error.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Signed in, but not allowed to do this: you lack the required role, have no access to the project, or your license does not include the feature.");
    //}
    //nonprimitive not container
    agent_profile_list_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *AgentAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = agent_profile_list_response_parseFromJSON(AgentAPIlocalVarJSON);
        cJSON_Delete(AgentAPIlocalVarJSON);
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

// Lock device
//
// Lock the device (iOS only).
//
void
AgentAPI_v3LockAgent(apiClient_t *apiClient, char *instanceId)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/agent/v1/system/lock");

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
    //    printf("%s\n","Device locked successfully.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Agent error.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
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
    
    free(localVarPath);
    free(localVarToReplace_instanceId);

}

// Pre-authorize an archive download from VM
//
// Returns a short-lived token for downloading several files and folders from the device as one ZIP archive, built on the server. List the paths to include in the body, then download with `GET /v1/preauthed/{token}/{filename}`. The token expires with your current session.
//
agent_file_download_token_t*
AgentAPI_v3PreauthorizeFileArchiveDownloadAgent(apiClient_t *apiClient, char *instanceId, agent_file_archive_download_body_t *agent_file_archive_download_body)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/agent-authorize/v1/file/download");

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
    cJSON *localVarSingleItemJSON_agent_file_archive_download_body = NULL;
    if (agent_file_archive_download_body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_agent_file_archive_download_body = agent_file_archive_download_body_convertToJSON(agent_file_archive_download_body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_agent_file_archive_download_body);
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
    //    printf("%s\n","Preauthorized archive download token.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","The request was invalid, for example a missing or malformed field. The body says which field; fix it before retrying.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Signed in, but not allowed to do this: you lack the required role, have no access to the project, or your license does not include the feature.");
    //}
    //nonprimitive not container
    agent_file_download_token_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *AgentAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = agent_file_download_token_parseFromJSON(AgentAPIlocalVarJSON);
        cJSON_Delete(AgentAPIlocalVarJSON);
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
    if (localVarSingleItemJSON_agent_file_archive_download_body) {
        cJSON_Delete(localVarSingleItemJSON_agent_file_archive_download_body);
        localVarSingleItemJSON_agent_file_archive_download_body = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Pre-authorize a file download from VM
//
// Returns a short-lived token for downloading one device file directly (for example from a browser or download manager) without an `Authorization` header and without buffering it in your SDK client. Download it with `GET /v1/preauthed/{token}/{filename}`. The token works only for this file and expires with your current session.
//
agent_file_download_token_t*
AgentAPI_v3PreauthorizeFileDownloadAgent(apiClient_t *apiClient, char *instanceId, char *filePath)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/agent-authorize/v1/file/device/{filePath}");

    if(!instanceId)
        goto end;
    if(!filePath)
        goto end;


    // Path Params
    long sizeOfPathParams_instanceId = strlen(instanceId)+3 + strlen(filePath)+3 + sizeof("{ instanceId }") - 1;
    if(instanceId == NULL) {
        goto end;
    }
    char* localVarToReplace_instanceId = malloc(sizeOfPathParams_instanceId);
    sprintf(localVarToReplace_instanceId, "{%s}", "instanceId");

    localVarPath = strReplace(localVarPath, localVarToReplace_instanceId, instanceId);

    // Path Params
    long sizeOfPathParams_filePath = strlen(instanceId)+3 + strlen(filePath)+3 + sizeof("{ filePath }") - 1;
    if(filePath == NULL) {
        goto end;
    }
    char* localVarToReplace_filePath = malloc(sizeOfPathParams_filePath);
    sprintf(localVarToReplace_filePath, "{%s}", "filePath");

    localVarPath = strReplace(localVarPath, localVarToReplace_filePath, filePath);


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
    //    printf("%s\n","Preauthorized download token.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","The request was invalid, for example a missing or malformed field. The body says which field; fix it before retrying.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Signed in, but not allowed to do this: you lack the required role, have no access to the project, or your license does not include the feature.");
    //}
    //nonprimitive not container
    agent_file_download_token_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *AgentAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = agent_file_download_token_parseFromJSON(AgentAPIlocalVarJSON);
        cJSON_Delete(AgentAPIlocalVarJSON);
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
    free(localVarToReplace_filePath);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Run an app
//
// Launches an installed app on the device, identified by its bundle ID from `v3ListAppsAgent`. Returns 204 once the launch has been requested; check `v3ListAppsStatusAgent` to confirm it is running.
//
void
AgentAPI_v3RunAppAgent(apiClient_t *apiClient, char *instanceId, char *bundleId)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/agent/v1/app/apps/{bundleId}/run");

    if(!instanceId)
        goto end;
    if(!bundleId)
        goto end;


    // Path Params
    long sizeOfPathParams_instanceId = strlen(instanceId)+3 + strlen(bundleId)+3 + sizeof("{ instanceId }") - 1;
    if(instanceId == NULL) {
        goto end;
    }
    char* localVarToReplace_instanceId = malloc(sizeOfPathParams_instanceId);
    sprintf(localVarToReplace_instanceId, "{%s}", "instanceId");

    localVarPath = strReplace(localVarPath, localVarToReplace_instanceId, instanceId);

    // Path Params
    long sizeOfPathParams_bundleId = strlen(instanceId)+3 + strlen(bundleId)+3 + sizeof("{ bundleId }") - 1;
    if(bundleId == NULL) {
        goto end;
    }
    char* localVarToReplace_bundleId = malloc(sizeOfPathParams_bundleId);
    sprintf(localVarToReplace_bundleId, "{%s}", "bundleId");

    localVarPath = strReplace(localVarPath, localVarToReplace_bundleId, bundleId);


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
    //    printf("%s\n","App started successfully.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Agent error.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
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
    
    free(localVarPath);
    free(localVarToReplace_instanceId);
    free(localVarToReplace_bundleId);

}

// Run Frida
//
// Attach Frida to a target process on the VM.
//
agent_frida_response_t*
AgentAPI_v3RunFridaAgent(apiClient_t *apiClient, char *instanceId, agent_frida_run_body_t *agent_frida_run_body)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/agent/v1/frida/run-frida");

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
    cJSON *localVarSingleItemJSON_agent_frida_run_body = NULL;
    if (agent_frida_run_body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_agent_frida_run_body = agent_frida_run_body_convertToJSON(agent_frida_run_body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_agent_frida_run_body);
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
    //    printf("%s\n","Frida attached successfully.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Agent error.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Signed in, but not allowed to do this: you lack the required role, have no access to the project, or your license does not include the feature.");
    //}
    //nonprimitive not container
    agent_frida_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *AgentAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = agent_frida_response_parseFromJSON(AgentAPIlocalVarJSON);
        cJSON_Delete(AgentAPIlocalVarJSON);
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
    if (localVarSingleItemJSON_agent_frida_run_body) {
        cJSON_Delete(localVarSingleItemJSON_agent_frida_run_body);
        localVarSingleItemJSON_agent_frida_run_body = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Set ADB auth setting
//
// Enable or disable ADB authorization (Android only).
//
void
AgentAPI_v3SetAdbAuthAgent(apiClient_t *apiClient, char *instanceId, agent_system_adb_auth_t *agent_system_adb_auth)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/agent/v1/system/adbauth");

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
    cJSON *localVarSingleItemJSON_agent_system_adb_auth = NULL;
    if (agent_system_adb_auth != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_agent_system_adb_auth = agent_system_adb_auth_convertToJSON(agent_system_adb_auth);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_agent_system_adb_auth);
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
    //if (apiClient->response_code == 204) {
    //    printf("%s\n","ADB auth setting updated successfully.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Agent error.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
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
    free(localVarToReplace_instanceId);
    if (localVarSingleItemJSON_agent_system_adb_auth) {
        cJSON_Delete(localVarSingleItemJSON_agent_system_adb_auth);
        localVarSingleItemJSON_agent_system_adb_auth = NULL;
    }
    free(localVarBodyParameters);

}

// Set device properties
//
// Set device properties (model and manufacturer ID) of the instance (Android only).
//
agent_system_result_t*
AgentAPI_v3SetDevicePropertiesAgent(apiClient_t *apiClient, char *instanceId, agent_system_set_device_properties_body_t *agent_system_set_device_properties_body)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/agent/v1/system/setDeviceProperties");

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
    cJSON *localVarSingleItemJSON_agent_system_set_device_properties_body = NULL;
    if (agent_system_set_device_properties_body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_agent_system_set_device_properties_body = agent_system_set_device_properties_body_convertToJSON(agent_system_set_device_properties_body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_agent_system_set_device_properties_body);
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
    //    printf("%s\n","Device properties updated.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Agent error.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Signed in, but not allowed to do this: you lack the required role, have no access to the project, or your license does not include the feature.");
    //}
    //nonprimitive not container
    agent_system_result_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *AgentAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = agent_system_result_parseFromJSON(AgentAPIlocalVarJSON);
        cJSON_Delete(AgentAPIlocalVarJSON);
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
    if (localVarSingleItemJSON_agent_system_set_device_properties_body) {
        cJSON_Delete(localVarSingleItemJSON_agent_system_set_device_properties_body);
        localVarSingleItemJSON_agent_system_set_device_properties_body = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Change attributes of a file on VM
//
// Changes a file on the device: move or rename it (`path`), change its permissions (`mode`), or change its owner. Send only what you want to change.
//
void
AgentAPI_v3SetFileAttributesAgent(apiClient_t *apiClient, char *instanceId, char *filePath, agent_file_attributes_body_t *agent_file_attributes_body)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/agent/v1/file/device/{filePath}");

    if(!instanceId)
        goto end;
    if(!filePath)
        goto end;


    // Path Params
    long sizeOfPathParams_instanceId = strlen(instanceId)+3 + strlen(filePath)+3 + sizeof("{ instanceId }") - 1;
    if(instanceId == NULL) {
        goto end;
    }
    char* localVarToReplace_instanceId = malloc(sizeOfPathParams_instanceId);
    sprintf(localVarToReplace_instanceId, "{%s}", "instanceId");

    localVarPath = strReplace(localVarPath, localVarToReplace_instanceId, instanceId);

    // Path Params
    long sizeOfPathParams_filePath = strlen(instanceId)+3 + strlen(filePath)+3 + sizeof("{ filePath }") - 1;
    if(filePath == NULL) {
        goto end;
    }
    char* localVarToReplace_filePath = malloc(sizeOfPathParams_filePath);
    sprintf(localVarToReplace_filePath, "{%s}", "filePath");

    localVarPath = strReplace(localVarPath, localVarToReplace_filePath, filePath);



    // Body Param
    cJSON *localVarSingleItemJSON_agent_file_attributes_body = NULL;
    if (agent_file_attributes_body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_agent_file_attributes_body = agent_file_attributes_body_convertToJSON(agent_file_attributes_body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_agent_file_attributes_body);
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
    //if (apiClient->response_code == 204) {
    //    printf("%s\n","File attributes updated successfully.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Agent error.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
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
    free(localVarToReplace_instanceId);
    free(localVarToReplace_filePath);
    if (localVarSingleItemJSON_agent_file_attributes_body) {
        cJSON_Delete(localVarSingleItemJSON_agent_file_attributes_body);
        localVarSingleItemJSON_agent_file_attributes_body = NULL;
    }
    free(localVarBodyParameters);

}

// Set instance hostname
//
// Set the hostname of the instance.
//
agent_system_result_t*
AgentAPI_v3SetHostnameAgent(apiClient_t *apiClient, char *instanceId, agent_system_set_hostname_body_t *agent_system_set_hostname_body)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/agent/v1/system/setHostname");

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
    cJSON *localVarSingleItemJSON_agent_system_set_hostname_body = NULL;
    if (agent_system_set_hostname_body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_agent_system_set_hostname_body = agent_system_set_hostname_body_convertToJSON(agent_system_set_hostname_body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_agent_system_set_hostname_body);
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
    //    printf("%s\n","Hostname set successfully.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Agent error.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Signed in, but not allowed to do this: you lack the required role, have no access to the project, or your license does not include the feature.");
    //}
    //nonprimitive not container
    agent_system_result_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *AgentAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = agent_system_result_parseFromJSON(AgentAPIlocalVarJSON);
        cJSON_Delete(AgentAPIlocalVarJSON);
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
    if (localVarSingleItemJSON_agent_system_set_hostname_body) {
        cJSON_Delete(localVarSingleItemJSON_agent_system_set_hostname_body);
        localVarSingleItemJSON_agent_system_set_hostname_body = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Shut down instance
//
// Shut down the instance.
//
void
AgentAPI_v3ShutdownAgent(apiClient_t *apiClient, char *instanceId)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/agent/v1/system/shutdown");

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
    //    printf("%s\n","Shutdown initiated successfully.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Agent error.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
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
    
    free(localVarPath);
    free(localVarToReplace_instanceId);

}

// Start a container
//
// Start a nested container on the VM (Android only).
//
void
AgentAPI_v3StartContainerAgent(apiClient_t *apiClient, char *instanceId, char *containerId)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/agent/v1/container/containers/{containerId}/start");

    if(!instanceId)
        goto end;
    if(!containerId)
        goto end;


    // Path Params
    long sizeOfPathParams_instanceId = strlen(instanceId)+3 + strlen(containerId)+3 + sizeof("{ instanceId }") - 1;
    if(instanceId == NULL) {
        goto end;
    }
    char* localVarToReplace_instanceId = malloc(sizeOfPathParams_instanceId);
    sprintf(localVarToReplace_instanceId, "{%s}", "instanceId");

    localVarPath = strReplace(localVarPath, localVarToReplace_instanceId, instanceId);

    // Path Params
    long sizeOfPathParams_containerId = strlen(instanceId)+3 + strlen(containerId)+3 + sizeof("{ containerId }") - 1;
    if(containerId == NULL) {
        goto end;
    }
    char* localVarToReplace_containerId = malloc(sizeOfPathParams_containerId);
    sprintf(localVarToReplace_containerId, "{%s}", "containerId");

    localVarPath = strReplace(localVarPath, localVarToReplace_containerId, containerId);


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
    //    printf("%s\n","Container started.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Agent error.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
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
    
    free(localVarPath);
    free(localVarToReplace_instanceId);
    free(localVarToReplace_containerId);

}

// Start an app in a container
//
// Start an Android application in a nested container (Android only).
//
void
AgentAPI_v3StartContainerAppAgent(apiClient_t *apiClient, char *instanceId, char *containerId, char *packageName, char *activityName)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/agent/v1/container/containers/{containerId}/start-application/{packageName}/{activityName}");

    if(!instanceId)
        goto end;
    if(!containerId)
        goto end;
    if(!packageName)
        goto end;
    if(!activityName)
        goto end;


    // Path Params
    long sizeOfPathParams_instanceId = strlen(instanceId)+3 + strlen(containerId)+3 + strlen(packageName)+3 + strlen(activityName)+3 + sizeof("{ instanceId }") - 1;
    if(instanceId == NULL) {
        goto end;
    }
    char* localVarToReplace_instanceId = malloc(sizeOfPathParams_instanceId);
    sprintf(localVarToReplace_instanceId, "{%s}", "instanceId");

    localVarPath = strReplace(localVarPath, localVarToReplace_instanceId, instanceId);

    // Path Params
    long sizeOfPathParams_containerId = strlen(instanceId)+3 + strlen(containerId)+3 + strlen(packageName)+3 + strlen(activityName)+3 + sizeof("{ containerId }") - 1;
    if(containerId == NULL) {
        goto end;
    }
    char* localVarToReplace_containerId = malloc(sizeOfPathParams_containerId);
    sprintf(localVarToReplace_containerId, "{%s}", "containerId");

    localVarPath = strReplace(localVarPath, localVarToReplace_containerId, containerId);

    // Path Params
    long sizeOfPathParams_packageName = strlen(instanceId)+3 + strlen(containerId)+3 + strlen(packageName)+3 + strlen(activityName)+3 + sizeof("{ packageName }") - 1;
    if(packageName == NULL) {
        goto end;
    }
    char* localVarToReplace_packageName = malloc(sizeOfPathParams_packageName);
    sprintf(localVarToReplace_packageName, "{%s}", "packageName");

    localVarPath = strReplace(localVarPath, localVarToReplace_packageName, packageName);

    // Path Params
    long sizeOfPathParams_activityName = strlen(instanceId)+3 + strlen(containerId)+3 + strlen(packageName)+3 + strlen(activityName)+3 + sizeof("{ activityName }") - 1;
    if(activityName == NULL) {
        goto end;
    }
    char* localVarToReplace_activityName = malloc(sizeOfPathParams_activityName);
    sprintf(localVarToReplace_activityName, "{%s}", "activityName");

    localVarPath = strReplace(localVarPath, localVarToReplace_activityName, activityName);


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
    //    printf("%s\n","Application started.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Agent error.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
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
    
    free(localVarPath);
    free(localVarToReplace_instanceId);
    free(localVarToReplace_containerId);
    free(localVarToReplace_packageName);
    free(localVarToReplace_activityName);

}

// Start and monitor an app in a container
//
// Start an Android application in a nested container and monitor it (Android only).
//
void
AgentAPI_v3StartContainerAppMonitoredAgent(apiClient_t *apiClient, char *instanceId, char *containerId, char *packageName, char *activityName)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/agent/v1/container/containers/{containerId}/start-application-and-monitor/{packageName}/{activityName}");

    if(!instanceId)
        goto end;
    if(!containerId)
        goto end;
    if(!packageName)
        goto end;
    if(!activityName)
        goto end;


    // Path Params
    long sizeOfPathParams_instanceId = strlen(instanceId)+3 + strlen(containerId)+3 + strlen(packageName)+3 + strlen(activityName)+3 + sizeof("{ instanceId }") - 1;
    if(instanceId == NULL) {
        goto end;
    }
    char* localVarToReplace_instanceId = malloc(sizeOfPathParams_instanceId);
    sprintf(localVarToReplace_instanceId, "{%s}", "instanceId");

    localVarPath = strReplace(localVarPath, localVarToReplace_instanceId, instanceId);

    // Path Params
    long sizeOfPathParams_containerId = strlen(instanceId)+3 + strlen(containerId)+3 + strlen(packageName)+3 + strlen(activityName)+3 + sizeof("{ containerId }") - 1;
    if(containerId == NULL) {
        goto end;
    }
    char* localVarToReplace_containerId = malloc(sizeOfPathParams_containerId);
    sprintf(localVarToReplace_containerId, "{%s}", "containerId");

    localVarPath = strReplace(localVarPath, localVarToReplace_containerId, containerId);

    // Path Params
    long sizeOfPathParams_packageName = strlen(instanceId)+3 + strlen(containerId)+3 + strlen(packageName)+3 + strlen(activityName)+3 + sizeof("{ packageName }") - 1;
    if(packageName == NULL) {
        goto end;
    }
    char* localVarToReplace_packageName = malloc(sizeOfPathParams_packageName);
    sprintf(localVarToReplace_packageName, "{%s}", "packageName");

    localVarPath = strReplace(localVarPath, localVarToReplace_packageName, packageName);

    // Path Params
    long sizeOfPathParams_activityName = strlen(instanceId)+3 + strlen(containerId)+3 + strlen(packageName)+3 + strlen(activityName)+3 + sizeof("{ activityName }") - 1;
    if(activityName == NULL) {
        goto end;
    }
    char* localVarToReplace_activityName = malloc(sizeOfPathParams_activityName);
    sprintf(localVarToReplace_activityName, "{%s}", "activityName");

    localVarPath = strReplace(localVarPath, localVarToReplace_activityName, activityName);


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
    //    printf("%s\n","Application started and monitored.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Agent error.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
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
    
    free(localVarPath);
    free(localVarToReplace_instanceId);
    free(localVarToReplace_containerId);
    free(localVarToReplace_packageName);
    free(localVarToReplace_activityName);

}

// Stop a container
//
// Stop a nested container on the VM (Android only).
//
void
AgentAPI_v3StopContainerAgent(apiClient_t *apiClient, char *instanceId, char *containerId)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/agent/v1/container/containers/{containerId}/stop");

    if(!instanceId)
        goto end;
    if(!containerId)
        goto end;


    // Path Params
    long sizeOfPathParams_instanceId = strlen(instanceId)+3 + strlen(containerId)+3 + sizeof("{ instanceId }") - 1;
    if(instanceId == NULL) {
        goto end;
    }
    char* localVarToReplace_instanceId = malloc(sizeOfPathParams_instanceId);
    sprintf(localVarToReplace_instanceId, "{%s}", "instanceId");

    localVarPath = strReplace(localVarPath, localVarToReplace_instanceId, instanceId);

    // Path Params
    long sizeOfPathParams_containerId = strlen(instanceId)+3 + strlen(containerId)+3 + sizeof("{ containerId }") - 1;
    if(containerId == NULL) {
        goto end;
    }
    char* localVarToReplace_containerId = malloc(sizeOfPathParams_containerId);
    sprintf(localVarToReplace_containerId, "{%s}", "containerId");

    localVarPath = strReplace(localVarPath, localVarToReplace_containerId, containerId);


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
    //    printf("%s\n","Container stopped.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Agent error.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
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
    
    free(localVarPath);
    free(localVarToReplace_instanceId);
    free(localVarToReplace_containerId);

}

// Stop a monitored app in a container
//
// Stop the monitored Android application in a nested container, if one is monitored (Android only).
//
void
AgentAPI_v3StopContainerAppAgent(apiClient_t *apiClient, char *instanceId, char *containerId)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/agent/v1/container/containers/{containerId}/stop-application-if-monitored");

    if(!instanceId)
        goto end;
    if(!containerId)
        goto end;


    // Path Params
    long sizeOfPathParams_instanceId = strlen(instanceId)+3 + strlen(containerId)+3 + sizeof("{ instanceId }") - 1;
    if(instanceId == NULL) {
        goto end;
    }
    char* localVarToReplace_instanceId = malloc(sizeOfPathParams_instanceId);
    sprintf(localVarToReplace_instanceId, "{%s}", "instanceId");

    localVarPath = strReplace(localVarPath, localVarToReplace_instanceId, instanceId);

    // Path Params
    long sizeOfPathParams_containerId = strlen(instanceId)+3 + strlen(containerId)+3 + sizeof("{ containerId }") - 1;
    if(containerId == NULL) {
        goto end;
    }
    char* localVarToReplace_containerId = malloc(sizeOfPathParams_containerId);
    sprintf(localVarToReplace_containerId, "{%s}", "containerId");

    localVarPath = strReplace(localVarPath, localVarToReplace_containerId, containerId);


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
    //    printf("%s\n","Application stopped.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Agent error.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
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
    
    free(localVarPath);
    free(localVarToReplace_instanceId);
    free(localVarToReplace_containerId);

}

// Uninstall an app
//
// Removes an app from the device, identified by its bundle ID.
//
void
AgentAPI_v3UninstallAppAgent(apiClient_t *apiClient, char *instanceId, char *bundleId)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/agent/v1/app/apps/{bundleId}/uninstall");

    if(!instanceId)
        goto end;
    if(!bundleId)
        goto end;


    // Path Params
    long sizeOfPathParams_instanceId = strlen(instanceId)+3 + strlen(bundleId)+3 + sizeof("{ instanceId }") - 1;
    if(instanceId == NULL) {
        goto end;
    }
    char* localVarToReplace_instanceId = malloc(sizeOfPathParams_instanceId);
    sprintf(localVarToReplace_instanceId, "{%s}", "instanceId");

    localVarPath = strReplace(localVarPath, localVarToReplace_instanceId, instanceId);

    // Path Params
    long sizeOfPathParams_bundleId = strlen(instanceId)+3 + strlen(bundleId)+3 + sizeof("{ bundleId }") - 1;
    if(bundleId == NULL) {
        goto end;
    }
    char* localVarToReplace_bundleId = malloc(sizeOfPathParams_bundleId);
    sprintf(localVarToReplace_bundleId, "{%s}", "bundleId");

    localVarPath = strReplace(localVarPath, localVarToReplace_bundleId, bundleId);


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
    //    printf("%s\n","App uninstalled successfully.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Agent error.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
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
    
    free(localVarPath);
    free(localVarToReplace_instanceId);
    free(localVarToReplace_bundleId);

}

// Uninstall a profile
//
// Uninstall a configuration profile from the VM.  Deletes are idempotent: an unknown `instanceId`, or a profile that is not installed, is a successful no-op that still returns 204, and repeated calls return 204 as well. A 404 means the request path did not match a delete route, not that the target was missing. Other agent-reported failures, and an unreachable agent, are still reported as failures.
//
void
AgentAPI_v3UninstallProfileAgent(apiClient_t *apiClient, char *instanceId, char *profileId)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/agent/v1/profile/profiles/{profileId}");

    if(!instanceId)
        goto end;
    if(!profileId)
        goto end;


    // Path Params
    long sizeOfPathParams_instanceId = strlen(instanceId)+3 + strlen(profileId)+3 + sizeof("{ instanceId }") - 1;
    if(instanceId == NULL) {
        goto end;
    }
    char* localVarToReplace_instanceId = malloc(sizeOfPathParams_instanceId);
    sprintf(localVarToReplace_instanceId, "{%s}", "instanceId");

    localVarPath = strReplace(localVarPath, localVarToReplace_instanceId, instanceId);

    // Path Params
    long sizeOfPathParams_profileId = strlen(instanceId)+3 + strlen(profileId)+3 + sizeof("{ profileId }") - 1;
    if(profileId == NULL) {
        goto end;
    }
    char* localVarToReplace_profileId = malloc(sizeOfPathParams_profileId);
    sprintf(localVarToReplace_profileId, "{%s}", "profileId");

    localVarPath = strReplace(localVarPath, localVarToReplace_profileId, profileId);


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
    //    printf("%s\n","Profile uninstalled successfully.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Agent error.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
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
    
    free(localVarPath);
    free(localVarToReplace_instanceId);
    free(localVarToReplace_profileId);

}

// Uninstall Remote.It
//
// Uninstall the Remote.It package from the VM (RPi only).
//
agent_remote_it_status_t*
AgentAPI_v3UninstallRemoteItAgent(apiClient_t *apiClient, char *instanceId)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/agent/v1/remoteit/uninstall");

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
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","Remote.It status after uninstall.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Agent error.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Signed in, but not allowed to do this: you lack the required role, have no access to the project, or your license does not include the feature.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","The resource does not exist, or you cannot see it.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 405) {
    //    printf("%s\n","Method not allowed.");
    //}
    //nonprimitive not container
    agent_remote_it_status_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *AgentAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = agent_remote_it_status_parseFromJSON(AgentAPIlocalVarJSON);
        cJSON_Delete(AgentAPIlocalVarJSON);
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

// Unlock device
//
// Unlock the device (iOS only).
//
void
AgentAPI_v3UnlockAgent(apiClient_t *apiClient, char *instanceId)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/agent/v1/system/unlock");

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
    //    printf("%s\n","Device unlocked successfully.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Agent error.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
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
    
    free(localVarPath);
    free(localVarToReplace_instanceId);

}

// Upload a file to VM
//
// Writes a file onto the device's filesystem at the given full path, replacing any file already there. Send the raw file bytes as the body. Use `v3GetTempFileAgent` first if you just need somewhere to put a file, for example an app package to install.
//
void
AgentAPI_v3UploadFileAgent(apiClient_t *apiClient, char *instanceId, char *filePath, binary_t* body)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/agent/v1/file/device/{filePath}");

    if(!instanceId)
        goto end;
    if(!filePath)
        goto end;


    // Path Params
    long sizeOfPathParams_instanceId = strlen(instanceId)+3 + strlen(filePath)+3 + sizeof("{ instanceId }") - 1;
    if(instanceId == NULL) {
        goto end;
    }
    char* localVarToReplace_instanceId = malloc(sizeOfPathParams_instanceId);
    sprintf(localVarToReplace_instanceId, "{%s}", "instanceId");

    localVarPath = strReplace(localVarPath, localVarToReplace_instanceId, instanceId);

    // Path Params
    long sizeOfPathParams_filePath = strlen(instanceId)+3 + strlen(filePath)+3 + sizeof("{ filePath }") - 1;
    if(filePath == NULL) {
        goto end;
    }
    char* localVarToReplace_filePath = malloc(sizeOfPathParams_filePath);
    sprintf(localVarToReplace_filePath, "{%s}", "filePath");

    localVarPath = strReplace(localVarPath, localVarToReplace_filePath, filePath);



    // Body Param
    localVarBodyParameters = malloc(body->len);
    memcpy(localVarBodyParameters, body->data, body->len);
    localVarBodyLength = body->len;
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/octet-stream"); //consumes
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
    //if (apiClient->response_code == 204) {
    //    printf("%s\n","File uploaded successfully.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Agent error.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
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
    free(localVarToReplace_instanceId);
    free(localVarToReplace_filePath);
    free(localVarBodyParameters);

}

