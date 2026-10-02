#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "InstancesAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096


// Connect an I/O interface
//
// Connects one of this device's I/O interfaces (for example a GPIO bank, `gpio/0`) to an I/O interconnect, a virtual wire that links interfaces on different devices so they can signal each other. Create the interconnect first with the Interconnects endpoints. Requires the configurable I/O license feature (403 otherwise).
//
void
InstancesAPI_v3AttachInstanceInterface(apiClient_t *apiClient, char *instanceId, attach_interface_body_t *attach_interface_body)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/interfaces");

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
    cJSON *localVarSingleItemJSON_attach_interface_body = NULL;
    if (attach_interface_body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_attach_interface_body = attach_interface_body_convertToJSON(attach_interface_body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_attach_interface_body);
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
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Instance not found.");
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
    if (localVarSingleItemJSON_attach_interface_body) {
        cJSON_Delete(localVarSingleItemJSON_attach_interface_body);
        localVarSingleItemJSON_attach_interface_body = NULL;
    }
    free(localVarBodyParameters);

}

// Clear kernel panics
//
// Deletes the recorded kernel panics for this device, so the next `v3GetInstancePanics` shows only new ones. An unknown `instanceId` is a successful no-op that returns 204.
//
void
InstancesAPI_v3ClearInstancePanics(apiClient_t *apiClient, char *instanceId)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/panics");

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

// Create a device
//
// Creates a new virtual device (instance) in a project. This returns quickly with the new `id` and `state: \"creating\"`; the device is then built in the background, which can take several minutes. Poll `v3GetInstanceState` (or `v3GetInstance`) until the state is `on` before using it. If it becomes `error`, read the instance's `error` field.  **Minimum request:** `projectId`, `flavor`, and `osVersion` and/or `osBuild`.  **Typical steps:** 1. `GET /v3/models`: pick a model and note its `flavor`, allowed cores, and memory. 2. `GET /v3/models/{model}/software`: pick a build and note its `osVersion` and `osBuild`. 3. `POST /v3/instances` with `{ \"projectId\", \"flavor\", \"osVersion\", \"osBuild\" }`. Add `name` so you can find it later, and `bootOptions` (for example `cores`, `ram`) to change the defaults. 4. Poll the state until `on`.  **How the operating system is chosen.** With both `osVersion` and `osBuild`, that exact build is used. With only `osBuild`, the build with that ID is used. With only `osVersion`, the newest build of that version is used. To boot your own firmware file instead, set `fwPackage`.  Some options need license features (for example creating devices from custom firmware, or custom model definitions via `charmBootArgs`); using one your license lacks returns 403.
//
create_instance_response_t*
InstancesAPI_v3CreateInstance(apiClient_t *apiClient, create_instance_body_t *create_instance_body)
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
    char *localVarPath = strdup("/v3/instances");





    // Body Param
    cJSON *localVarSingleItemJSON_create_instance_body = NULL;
    if (create_instance_body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_create_instance_body = create_instance_body_convertToJSON(create_instance_body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_create_instance_body);
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
    //    printf("%s\n","Success");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Invalid instance definition.");
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
    //if (apiClient->response_code == 409) {
    //    printf("%s\n","Instance could not be created due to a conflict.");
    //}
    //nonprimitive not container
    create_instance_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *InstancesAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = create_instance_response_parseFromJSON(InstancesAPIlocalVarJSON);
        cJSON_Delete(InstancesAPIlocalVarJSON);
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
    if (localVarSingleItemJSON_create_instance_body) {
        cJSON_Delete(localVarSingleItemJSON_create_instance_body);
        localVarSingleItemJSON_create_instance_body = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Remove Instance
//
// Removes the instance. Deletion is asynchronous: the call schedules the teardown and returns 204 immediately, while the instance remains visible in a `deleting` state until teardown completes.  An `instanceId` that does not exist also returns 204. The API cannot tell a call with an invalid ID apart from a second call made to confirm an earlier delete succeeded, so both succeed. Repeated calls return 204 as well. A 404 means the request path did not match a delete route, not that the target was missing. A repeat therefore returns 204 both while the record is still present in the `deleting` state and after it has disappeared.
//
void
InstancesAPI_v3DeleteInstance(apiClient_t *apiClient, char *instanceId)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}");

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

// Disconnect an I/O interface
//
// Disconnects one of this device's I/O interfaces from an I/O interconnect. Requires the configurable I/O license feature.  Deletes are idempotent: an unknown instance, interconnect or interface, including one that was already detached, is a successful no-op that still returns 204, and repeated calls return 204 as well. A 404 means the request path did not match a delete route, not that the target was missing.
//
void
InstancesAPI_v3DetachInstanceInterface(apiClient_t *apiClient, char *instanceId, char *interfaceId, detach_interface_body_t *detach_interface_body)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/interfaces/{interfaceId}");

    if(!instanceId)
        goto end;
    if(!interfaceId)
        goto end;


    // Path Params
    long sizeOfPathParams_instanceId = strlen(instanceId)+3 + strlen(interfaceId)+3 + sizeof("{ instanceId }") - 1;
    if(instanceId == NULL) {
        goto end;
    }
    char* localVarToReplace_instanceId = malloc(sizeOfPathParams_instanceId);
    sprintf(localVarToReplace_instanceId, "{%s}", "instanceId");

    localVarPath = strReplace(localVarPath, localVarToReplace_instanceId, instanceId);

    // Path Params
    long sizeOfPathParams_interfaceId = strlen(instanceId)+3 + strlen(interfaceId)+3 + sizeof("{ interfaceId }") - 1;
    if(interfaceId == NULL) {
        goto end;
    }
    char* localVarToReplace_interfaceId = malloc(sizeOfPathParams_interfaceId);
    sprintf(localVarToReplace_interfaceId, "{%s}", "interfaceId");

    localVarPath = strReplace(localVarPath, localVarToReplace_interfaceId, interfaceId);



    // Body Param
    cJSON *localVarSingleItemJSON_detach_interface_body = NULL;
    if (detach_interface_body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_detach_interface_body = detach_interface_body_convertToJSON(detach_interface_body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_detach_interface_body);
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
    //    printf("%s\n","No content");
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
    free(localVarToReplace_interfaceId);
    if (localVarSingleItemJSON_detach_interface_body) {
        cJSON_Delete(localVarSingleItemJSON_detach_interface_body);
        localVarSingleItemJSON_detach_interface_body = NULL;
    }
    free(localVarBodyParameters);

}

// Stop exposing the device port
//
// Turns off the exposed port enabled with `v3EnableExposePort`. Runs as a background task on the device; returns 204 once it is scheduled.
//
void
InstancesAPI_v3DisableExposePort(apiClient_t *apiClient, char *instanceId)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/exposeport/disable");

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

// Download the Enhanced Network Monitor capture
//
// Downloads the packets recorded by Enhanced Network Monitor (see `v3StartNetdump`) as a pcapng file, which packet analyzers such as Wireshark open directly. Requires the Enhanced Network Monitor feature (403 otherwise).
//
binary_t*
InstancesAPI_v3DownloadNetdumpPcap(apiClient_t *apiClient, char *instanceId)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/netdump.pcap");

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


    list_addElement(localVarHeaderType,"application/vnd.tcpdump.pcap"); //produces
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
    //    printf("%s\n","PCAPNG file.");
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
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Download the Network Monitor capture
//
// Downloads the traffic recorded by Network Monitor (see `v3StartNetworkMonitor`) as a pcap file. Save it with a `.pcap` extension and open it in a packet analyzer such as Wireshark. Download while monitoring runs or after stopping it.
//
binary_t*
InstancesAPI_v3DownloadNetworkMonitorPcap(apiClient_t *apiClient, char *instanceId)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/networkMonitor.pcap");

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


    list_addElement(localVarHeaderType,"application/vnd.tcpdump.pcap"); //produces
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
    //    printf("%s\n","PCAP file.");
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
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Expose the device port
//
// Turns on the exposed port for this device, for device access. This runs as a background task on the device; returns 204 once it is scheduled. Undo with `v3DisableExposePort`.
//
void
InstancesAPI_v3EnableExposePort(apiClient_t *apiClient, char *instanceId)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/exposeport/enable");

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

// Get a device
//
// Returns everything about one device: its name, model, operating system, state, boot options, network details and consoles. Use `state` to see whether it is ready, and `error` to see why it failed. Pass `returnAttr` to get only some fields.
//
instance_t*
InstancesAPI_v3GetInstance(apiClient_t *apiClient, char *instanceId, char *returnAttr)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}");

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
    char *keyQuery_returnAttr = NULL;
    char * valueQuery_returnAttr = NULL;
    keyValuePair_t *keyPairQuery_returnAttr = 0;
    if (returnAttr)
    {
        keyQuery_returnAttr = strdup("returnAttr");
        valueQuery_returnAttr = strdup((returnAttr));
        keyPairQuery_returnAttr = keyValuePair_create(keyQuery_returnAttr, valueQuery_returnAttr);
        list_addElement(localVarQueryParameters,keyPairQuery_returnAttr);
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
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Signed in, but not allowed to do this: you lack the required role, have no access to the project, or your license does not include the feature.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Instance not found.");
    //}
    //nonprimitive not container
    instance_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *InstancesAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = instance_parseFromJSON(InstancesAPIlocalVarJSON);
        cJSON_Delete(InstancesAPIlocalVarJSON);
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
    if(keyQuery_returnAttr){
        free(keyQuery_returnAttr);
        keyQuery_returnAttr = NULL;
    }
    if(valueQuery_returnAttr){
        free(valueQuery_returnAttr);
        valueQuery_returnAttr = NULL;
    }
    if(keyPairQuery_returnAttr){
        keyValuePair_free(keyPairQuery_returnAttr);
        keyPairQuery_returnAttr = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Get console websocket URL
//
// Get console WebSocket URL.  Instances can have more than one console. To connect to a specific console: 1. Call Get Instance and read the `consoles` array. 2. Take the `id` of the console you want and remove the `port-` prefix (e.g. `port-uart7-cons` becomes `uart7-cons`). 3. Pass that value as the `type` query parameter (e.g. `?type=uart7-cons`).  If `type` is omitted, the default console (`cons`) is used. Some models have no default console and require `type`.
//
instance_console_endpoint_t*
InstancesAPI_v3GetInstanceConsole(apiClient_t *apiClient, char *instanceId, char *type)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/console");

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
    //    printf("%s\n","Success");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Invalid console type, or type omitted on a model without a default console.");
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
    //    printf("%s\n","Instance not found.");
    //}
    //nonprimitive not container
    instance_console_endpoint_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *InstancesAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = instance_console_endpoint_parseFromJSON(InstancesAPIlocalVarJSON);
        cJSON_Delete(InstancesAPIlocalVarJSON);
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

// Read the console log
//
// Returns the text output of the device's main console (serial output from boot messages, the kernel and system services) as plain text. Useful for seeing why a device will not boot. For a live, interactive console, use `v3GetInstanceConsole` instead.
//
char*
InstancesAPI_v3GetInstanceConsoleLog(apiClient_t *apiClient, char *instanceId)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/consoleLog");

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


    list_addElement(localVarHeaderType,"text/plain"); //produces
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
    //    printf("%s\n","Current console log.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Signed in, but not allowed to do this: you lack the required role, have no access to the project, or your license does not include the feature.");
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
    
    free(localVarPath);
    free(localVarToReplace_instanceId);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Read board LEDs, buttons and switches
//
// Returns the current state of the simulated LEDs, buttons and switches (GPIO pins) on an IoT or embedded board model, for example whether an LED your firmware drives is lit. The device must be running. Phone models do not have these, and the request fails for them. See `GpiosState` for the format.
//
gpios_state_t*
InstancesAPI_v3GetInstanceGpios(apiClient_t *apiClient, char *instanceId)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/gpios");

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
    //    printf("%s\n","Current GPIO state.");
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
    //    printf("%s\n","Instance not found.");
    //}
    //nonprimitive not container
    gpios_state_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *InstancesAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = gpios_state_parseFromJSON(InstancesAPIlocalVarJSON);
        cJSON_Delete(InstancesAPIlocalVarJSON);
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

// Get image upload status
//
// Checks the progress of a chunked upload made with `v3PutInstanceImageUpload`, or downloads the finished file. With chunk parameters (`resumableChunkNumber` and friends) it returns 200 if that chunk is already stored and 204 if it still needs to be sent; without them it downloads the image file.
//
binary_t*
InstancesAPI_v3GetInstanceImageUpload(apiClient_t *apiClient, char *instance, char *type, char *imageId, char *name, double *resumableChunkNumber)
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
    char *localVarPath = strdup("/v3/instances/{instance}/image-upload/{type}/{imageId}/{name}");

    if(!instance)
        goto end;
    if(!type)
        goto end;
    if(!imageId)
        goto end;
    if(!name)
        goto end;


    // Path Params
    long sizeOfPathParams_instance = strlen(instance)+3 + strlen(type)+3 + strlen(imageId)+3 + strlen(name)+3 + sizeof("{ instance }") - 1;
    if(instance == NULL) {
        goto end;
    }
    char* localVarToReplace_instance = malloc(sizeOfPathParams_instance);
    sprintf(localVarToReplace_instance, "{%s}", "instance");

    localVarPath = strReplace(localVarPath, localVarToReplace_instance, instance);

    // Path Params
    long sizeOfPathParams_type = strlen(instance)+3 + strlen(type)+3 + strlen(imageId)+3 + strlen(name)+3 + sizeof("{ type }") - 1;
    if(type == NULL) {
        goto end;
    }
    char* localVarToReplace_type = malloc(sizeOfPathParams_type);
    sprintf(localVarToReplace_type, "{%s}", "type");

    localVarPath = strReplace(localVarPath, localVarToReplace_type, type);

    // Path Params
    long sizeOfPathParams_imageId = strlen(instance)+3 + strlen(type)+3 + strlen(imageId)+3 + strlen(name)+3 + sizeof("{ imageId }") - 1;
    if(imageId == NULL) {
        goto end;
    }
    char* localVarToReplace_imageId = malloc(sizeOfPathParams_imageId);
    sprintf(localVarToReplace_imageId, "{%s}", "imageId");

    localVarPath = strReplace(localVarPath, localVarToReplace_imageId, imageId);

    // Path Params
    long sizeOfPathParams_name = strlen(instance)+3 + strlen(type)+3 + strlen(imageId)+3 + strlen(name)+3 + sizeof("{ name }") - 1;
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);



    // query parameters
    char *keyQuery_resumableChunkNumber = NULL;
    char * valueQuery_resumableChunkNumber = NULL;
    keyValuePair_t *keyPairQuery_resumableChunkNumber = 0;
    if (resumableChunkNumber)
    {
        keyQuery_resumableChunkNumber = strdup("resumableChunkNumber");
        valueQuery_resumableChunkNumber = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_resumableChunkNumber, MAX_NUMBER_LENGTH, "%d", *resumableChunkNumber);
        keyPairQuery_resumableChunkNumber = keyValuePair_create(keyQuery_resumableChunkNumber, valueQuery_resumableChunkNumber);
        list_addElement(localVarQueryParameters,keyPairQuery_resumableChunkNumber);
    }
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
    //    printf("%s\n","An empty JSON object when a probed chunk is already stored, the image bytes when the file is stored locally, or the image metadata when no file has been stored yet.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 204) {
    //    printf("%s\n","The probed chunk is not stored yet and still needs to be uploaded.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 302) {
    //    printf("%s\n","The image is stored in S3; follow the Location header to download it.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","The image identifier is invalid or the image record is missing.");
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
    //    printf("%s\n","No image with the given identifier.");
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
    list_freeList(localVarQueryParameters);
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_instance);
    free(localVarToReplace_type);
    free(localVarToReplace_imageId);
    free(localVarToReplace_name);
    if(keyQuery_resumableChunkNumber){
        free(keyQuery_resumableChunkNumber);
        keyQuery_resumableChunkNumber = NULL;
    }
    if(valueQuery_resumableChunkNumber){
        free(valueQuery_resumableChunkNumber);
        valueQuery_resumableChunkNumber = NULL;
    }
    if(keyPairQuery_resumableChunkNumber){
        keyValuePair_free(keyPairQuery_resumableChunkNumber);
        keyPairQuery_resumableChunkNumber = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// List kernel panics
//
// Returns the kernel panics (crashes of the operating system itself) recorded on this device, as a list of panic records. An empty list means none have happened since the last clear. Clear them with `v3ClearInstancePanics`.
//
list_t*
InstancesAPI_v3GetInstancePanics(apiClient_t *apiClient, char *instanceId)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/panics");

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
    //    printf("%s\n","Array of panics.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Signed in, but not allowed to do this: you lack the required role, have no access to the project, or your license does not include the feature.");
    //}
    list_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *InstancesAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        if(!cJSON_IsArray(InstancesAPIlocalVarJSON)) {
            return 0;//nonprimitive container
        }
        elementToReturn = list_createList();
        cJSON *VarJSON;
        cJSON_ArrayForEach(VarJSON, InstancesAPIlocalVarJSON)
        {
            if(!cJSON_IsObject(VarJSON))
            {
               // return 0;
            }
            char *localVarJSONToChar = cJSON_Print(VarJSON);
            list_addElement(elementToReturn , localVarJSONToChar);
        }

        cJSON_Delete( InstancesAPIlocalVarJSON);
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

// Read simulated sensors
//
// Returns the current values of the device's simulated sensors and hardware: motion (accelerometer, gyroscope, compass), environment (temperature, light, pressure, humidity, proximity), GPS location, battery, and biometric bypass. Only values the device reports are included; a missing field does not mean zero. See `PeripheralsData`.
//
peripherals_data_t*
InstancesAPI_v3GetInstancePeripherals(apiClient_t *apiClient, char *instanceId)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/peripherals");

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
    //    printf("%s\n","Current peripherals state.");
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
    //    printf("%s\n","Instance not found.");
    //}
    //nonprimitive not container
    peripherals_data_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *InstancesAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = peripherals_data_parseFromJSON(InstancesAPIlocalVarJSON);
        cJSON_Delete(InstancesAPIlocalVarJSON);
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

// Get the SSH quick-connect command
//
// Returns a ready-to-paste SSH command for connecting to this device, as a JSON string. Run it in a terminal on a computer that can reach the device, for example one connected with the project VPN (`GET /v3/projects/{projectId}/vpnconfig/{format}`).
//
char*
InstancesAPI_v3GetInstanceQuickConnectCommand(apiClient_t *apiClient, char *instanceId)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/quickConnectCommand");

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
    //    printf("%s\n","Quick connect command.");
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
    
    free(localVarPath);
    free(localVarToReplace_instanceId);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Take a screenshot
//
// Captures what the device's screen shows right now and returns it as an image. Choose the file type in the path: `screenshot.png` or `screenshot.jpeg`. Use `scale` to shrink it: `scale=2` returns half the width and height, `scale=4` a quarter; the default 1 is full size. The device must be running.
//
binary_t*
InstancesAPI_v3GetInstanceScreenshot(apiClient_t *apiClient, char *instanceId, char *format, double *scale)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/screenshot.{format}");

    if(!instanceId)
        goto end;
    if(!format)
        goto end;


    // Path Params
    long sizeOfPathParams_instanceId = strlen(instanceId)+3 + strlen(format)+3 + sizeof("{ instanceId }") - 1;
    if(instanceId == NULL) {
        goto end;
    }
    char* localVarToReplace_instanceId = malloc(sizeOfPathParams_instanceId);
    sprintf(localVarToReplace_instanceId, "{%s}", "instanceId");

    localVarPath = strReplace(localVarPath, localVarToReplace_instanceId, instanceId);

    // Path Params
    long sizeOfPathParams_format = strlen(instanceId)+3 + strlen(format)+3 + sizeof("{ format }") - 1;
    if(format == NULL) {
        goto end;
    }
    char* localVarToReplace_format = malloc(sizeOfPathParams_format);
    sprintf(localVarToReplace_format, "{%s}", "format");

    localVarPath = strReplace(localVarPath, localVarToReplace_format, format);



    // query parameters
    char *keyQuery_scale = NULL;
    char * valueQuery_scale = NULL;
    keyValuePair_t *keyPairQuery_scale = 0;
    if (scale)
    {
        keyQuery_scale = strdup("scale");
        valueQuery_scale = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_scale, MAX_NUMBER_LENGTH, "%d", *scale);
        keyPairQuery_scale = keyValuePair_create(keyQuery_scale, valueQuery_scale);
        list_addElement(localVarQueryParameters,keyPairQuery_scale);
    }
    list_addElement(localVarHeaderType,"image/png"); //produces
    list_addElement(localVarHeaderType,"image/jpeg"); //produces
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
    //    printf("%s\n","Screenshot.");
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
    //    printf("%s\n","Instance not found.");
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
    list_freeList(localVarQueryParameters);
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_instanceId);
    free(localVarToReplace_format);
    if(keyQuery_scale){
        free(keyQuery_scale);
        keyQuery_scale = NULL;
    }
    if(valueQuery_scale){
        free(valueQuery_scale);
        valueQuery_scale = NULL;
    }
    if(keyPairQuery_scale){
        keyValuePair_free(keyPairQuery_scale);
        keyPairQuery_scale = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Get a device's state
//
// Returns only the device's current state (for example `creating`, `on`, `off`), as a bare JSON string. This is the call to poll while waiting for a device to finish creating, starting, stopping or rebooting. See `InstanceState` for what each value means.
//
corellium_api_instance_state__e
InstancesAPI_v3GetInstanceState(apiClient_t *apiClient, char *instanceId, char *returnAttr)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/state");

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
    char *keyQuery_returnAttr = NULL;
    char * valueQuery_returnAttr = NULL;
    keyValuePair_t *keyPairQuery_returnAttr = 0;
    if (returnAttr)
    {
        keyQuery_returnAttr = strdup("returnAttr");
        valueQuery_returnAttr = strdup((returnAttr));
        keyPairQuery_returnAttr = keyValuePair_create(keyQuery_returnAttr, valueQuery_returnAttr);
        list_addElement(localVarQueryParameters,keyPairQuery_returnAttr);
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
    //    printf("%s\n","Current instance state.");
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
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Instance not found.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 409) {
    //    printf("%s\n","The request conflicts with the current state of the resource.");
    //}
    //nonprimitive not container
    corellium_api_instance_state__e elementToReturn = 0;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *InstancesAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = instance_state_parseFromJSON(InstancesAPIlocalVarJSON);
        cJSON_Delete(InstancesAPIlocalVarJSON);
        if(elementToReturn == 0) {
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
    if(keyQuery_returnAttr){
        free(keyQuery_returnAttr);
        keyQuery_returnAttr = NULL;
    }
    if(valueQuery_returnAttr){
        free(valueQuery_returnAttr);
        valueQuery_returnAttr = NULL;
    }
    if(keyPairQuery_returnAttr){
        keyValuePair_free(keyPairQuery_returnAttr);
        keyPairQuery_returnAttr = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return 0;

}

// Send an SMS message to an iOS device
//
// Delivers a text message to an iOS device as if it arrived over the cellular network, so apps see a normal incoming SMS. Useful for testing one-time-password and verification-code flows. Send either `number` (the sender's phone number) and `message` (the text), or `raw` with the message bytes in hexadecimal for low-level testing. The device must be running.
//
void
InstancesAPI_v3InjectMessage(apiClient_t *apiClient, char *instanceId, message_body_t *message_body)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/message");

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
    cJSON *localVarSingleItemJSON_message_body = NULL;
    if (message_body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_message_body = message_body_convertToJSON(message_body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_message_body);
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
    if (localVarSingleItemJSON_message_body) {
        cJSON_Delete(localVarSingleItemJSON_message_body);
        localVarSingleItemJSON_message_body = NULL;
    }
    free(localVarBodyParameters);

}

// Get a kernel download token
//
// Returns a short-lived token that authorizes downloading this device's kernel file without an `Authorization` header, for loading into a disassembler or debugger. Download with `GET /v1/preauthed/{token}/{filename}`. The token works only for this device's kernel and expires when your current session token expires.
//
token_t*
InstancesAPI_v3KernelPreauthorize(apiClient_t *apiClient, char *instanceId)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/kernel-authorize");

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
    token_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *InstancesAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = token_parseFromJSON(InstancesAPIlocalVarJSON);
        cJSON_Delete(InstancesAPIlocalVarJSON);
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

// List Instances
//
// Lists the devices (instances) you can access across your projects. Results are paginated with `limit` and `offset`; use `name` to find a device by name. To list only one project's devices, use `GET /v3/projects/{projectId}/instances`.
//
instance_list_t*
InstancesAPI_v3ListInstances(apiClient_t *apiClient, double *limit, double *offset, char *name, char *returnAttr)
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
    char *localVarPath = strdup("/v3/instances");





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
    char *keyQuery_returnAttr = NULL;
    char * valueQuery_returnAttr = NULL;
    keyValuePair_t *keyPairQuery_returnAttr = 0;
    if (returnAttr)
    {
        keyQuery_returnAttr = strdup("returnAttr");
        valueQuery_returnAttr = strdup((returnAttr));
        keyPairQuery_returnAttr = keyValuePair_create(keyQuery_returnAttr, valueQuery_returnAttr);
        list_addElement(localVarQueryParameters,keyPairQuery_returnAttr);
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
    //    printf("%s\n","Paginated list of instances.");
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
    instance_list_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *InstancesAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = instance_list_parseFromJSON(InstancesAPIlocalVarJSON);
        cJSON_Delete(InstancesAPIlocalVarJSON);
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
    if(keyQuery_returnAttr){
        free(keyQuery_returnAttr);
        keyQuery_returnAttr = NULL;
    }
    if(valueQuery_returnAttr){
        free(valueQuery_returnAttr);
        valueQuery_returnAttr = NULL;
    }
    if(keyPairQuery_returnAttr){
        keyValuePair_free(keyPairQuery_returnAttr);
        keyPairQuery_returnAttr = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Play a video or audio file into the device
//
// Plays a media file into the device, so apps receive it as if it came from the device's camera (video) and microphone (audio). Use it to test camera or scanning features, for example feeding a QR code video to an app. Open the camera app on the device to see it.  Give exactly one source: `imageId` of a `media` image you uploaded with `POST /v3/images`, or a `url` the platform can download the file from. Returns 204 once playback starts. Call `v3MediaStop` to stop it.
//
void
InstancesAPI_v3MediaPlay(apiClient_t *apiClient, char *instanceId, media_play_body_t *media_play_body)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/media/play");

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
    cJSON *localVarSingleItemJSON_media_play_body = NULL;
    if (media_play_body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_media_play_body = media_play_body_convertToJSON(media_play_body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_media_play_body);
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
    //    printf("%s\n","The request was invalid, for example a missing or malformed field. The body says which field; fix it before retrying.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Instance not found.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 409) {
    //    printf("%s\n","The request conflicts with the current state of the resource.");
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
    if (localVarSingleItemJSON_media_play_body) {
        cJSON_Delete(localVarSingleItemJSON_media_play_body);
        localVarSingleItemJSON_media_play_body = NULL;
    }
    free(localVarBodyParameters);

}

// Stop playing media
//
// Stops media started with `v3MediaPlay`.
//
void
InstancesAPI_v3MediaStop(apiClient_t *apiClient, char *instanceId)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/media/stop");

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
    //    printf("%s\n","The request was invalid, for example a missing or malformed field. The body says which field; fix it before retrying.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Instance not found.");
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

// Change device settings
//
// Changes a device's settings. Send only the fields you want to change: `name` (the label shown in lists), `bootOptions` (for example `cores`, `ram`, boot arguments), `proxy` (which device ports are forwarded, and whether they are reachable from outside the project), and `straceFilter` (which processes CoreTrace records, by name, process ID or thread ID; see `v3ListThreads`). Returns the updated device. This call does not turn the device on or off; use `v3StartInstance`, `v3StopInstance`, `v3RebootInstance`, `v3PauseInstance` and `v3UnpauseInstance` for that.
//
instance_t*
InstancesAPI_v3PatchInstance(apiClient_t *apiClient, char *instanceId, patch_instance_body_t *patch_instance_body)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}");

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
    cJSON *localVarSingleItemJSON_patch_instance_body = NULL;
    if (patch_instance_body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_patch_instance_body = patch_instance_body_convertToJSON(patch_instance_body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_patch_instance_body);
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
    //    printf("%s\n","Success");
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
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Instance not found.");
    //}
    //nonprimitive not container
    instance_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *InstancesAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = instance_parseFromJSON(InstancesAPIlocalVarJSON);
        cJSON_Delete(InstancesAPIlocalVarJSON);
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
    if (localVarSingleItemJSON_patch_instance_body) {
        cJSON_Delete(localVarSingleItemJSON_patch_instance_body);
        localVarSingleItemJSON_patch_instance_body = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Update Instance Read Only
//
// Turns read-only mode on or off for the device. Returns the updated device.
//
instance_t*
InstancesAPI_v3PatchInstanceReadOnly(apiClient_t *apiClient, char *instanceId, patch_instance_read_only_body_t *patch_instance_read_only_body)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/read-only");

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
    cJSON *localVarSingleItemJSON_patch_instance_read_only_body = NULL;
    if (patch_instance_read_only_body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_patch_instance_read_only_body = patch_instance_read_only_body_convertToJSON(patch_instance_read_only_body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_patch_instance_read_only_body);
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
    //    printf("%s\n","Success");
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
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Instance not found.");
    //}
    //nonprimitive not container
    instance_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *InstancesAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = instance_parseFromJSON(InstancesAPIlocalVarJSON);
        cJSON_Delete(InstancesAPIlocalVarJSON);
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
    if (localVarSingleItemJSON_patch_instance_read_only_body) {
        cJSON_Delete(localVarSingleItemJSON_patch_instance_read_only_body);
        localVarSingleItemJSON_patch_instance_read_only_body = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Pause a device
//
// Freezes a running device in place without shutting it down: it stops executing but keeps its memory and state, so `v3UnpauseInstance` resumes it exactly where it stopped. The state becomes `paused`.
//
void
InstancesAPI_v3PauseInstance(apiClient_t *apiClient, char *instanceId)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/pause");

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
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Signed in, but not allowed to do this: you lack the required role, have no access to the project, or your license does not include the feature.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Instance not found.");
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

// Provide Instance Input
//
// Sends a touch or button event to the VM. Events in the request array are processed in order.  Each element of the request array is one of: - **TouchInputRequest** – holds buttons (or keys) and/or touches at a screen position.   - Set `buttons` to `[\"finger\"]` to press down and `[]` to release all buttons.   - Omit `buttons` to leave the current press state unchanged.   - `position` is an array of per-finger `[x, y]` coordinates. May be omitted for button-only input. - **TouchCurveInputRequest** – animates a drag/swipe from `start` to `end` over `duration` ms.   - Optional `bezierPoints` shape the path; omit for a straight-line drag. - **TextInputRequest** – types the given text.  Buttons (or keys) accepted by `buttons` / `startButtons` / `endButtons` are an array of strings, each either a single ASCII character or one of the following keywords: - VM buttons (case-insensitive): `finger`, `homeButton`, `holdButton` (Power/Hold),   `volumeUp`, `volumeDown`, `backButton`, `overviewButton`. `ringerSwitch` is not supported. - Keyboard key names: `again`, `alt`, `alterase`, `apostrophe`, `back`, `backslash`, `backspace`,   `bassboost`, `bookmarks`, `bsp`, `calc`, `camera`, `cancel`, `caps`, `capslock`, `chat`, `close`,   `closecd`, `comma`, `compose`, `computer`, `config`, `connect`, `copy`, `ctrl`, `cut`,   `cyclewindows`, `dashboard`, `del`, `delete`, `deletefile`, `dot`, `down`, `edit`, `eject`,   `ejectclose`, `email`, `end`, `enter`, `equal`, `esc`, `escape`, `exit`, `f1`–`f24`, `fastfwd`,   `file`, `finance`, `find`, `forward`, `front`, `grave`, `hangeul`, `hanja`, `help`,   `henkan`, `home`, `homepage`, `hp`, `hrgn`, `ins`, `insert`, `iso`, `k102`, `kp0`–`kp9`,   `kpasterisk`, `kpcomma`, `kpdot`, `kpenter`, `kpequal`, `kpjpcomma`, `kpleftparen`, `kpminus`,   `kpplus`, `kpplusminus`, `kprightparen`, `kpslash`, `ktkn`, `ktknhrgn`, `left`, `leftalt`,   `leftbrace`, `leftctrl`, `leftmeta`, `leftshift`, `linefeed`, `macro`, `mail`, `menu`, `meta`,   `minus`, `move`, `msdos`, `muhenkan`, `mute`, `new`, `next`, `numlock`, `open`, `pagedown`,   `pageup`, `paste`, `pause`, `pausecd`, `pgdn`, `pgup`, `phone`, `play`, `playcd`, `playpause`,   `power`, `previous`, `print`, `prog1`–`prog4`, `props`, `question`, `record`, `redo`, `refresh`,   `return`, `rewind`, `right`, `rightalt`, `rightbrace`, `rightctrl`, `rightmeta`, `rightshift`,   `ro`, `rotate`, `scale`, `screenlock`, `scrolldown`, `scrolllock`, `scrollup`, `search`,   `semicolon`, `sendfile`, `setup`, `shift`, `shop`, `slash`, `sleep`, `sound`, `space`, `sport`,   `stop`, `stopcd`, `suspend`, `sysrq`, `tab`, `undo`, `up`, `voldown`, `volup`, `wakeup`, `www`,   `xfer`, `yen`, `zkhk`.  Use `finger:1` to press the fingerprint sensor (see the `fingerprint` example).
//
input_response_t*
InstancesAPI_v3PostInstanceInput(apiClient_t *apiClient, char *instanceId, list_t *instance_input_body)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/input");

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
    //notstring
    cJSON *localVar_instance_input_body = NULL;
    cJSON *localVarItemJSON_instance_input_body = NULL;
    cJSON *localVarSingleItemJSON_instance_input_body = NULL;
    if (instance_input_body != NULL)
    {
        localVarItemJSON_instance_input_body = cJSON_CreateObject();
        localVarSingleItemJSON_instance_input_body = cJSON_AddArrayToObject(localVarItemJSON_instance_input_body, "instance_input_body");
        if (localVarSingleItemJSON_instance_input_body == NULL)
        {
            // nonprimitive container

            goto end;
        }
    }

    listEntry_t *instance_input_bodyBodyListEntry;
    list_ForEach(instance_input_bodyBodyListEntry, instance_input_body)
    {
        localVar_instance_input_body = instance_input_body_convertToJSON(instance_input_bodyBodyListEntry->data);
        if(localVar_instance_input_body == NULL)
        {
            goto end;
        }
        cJSON_AddItemToArray(localVarSingleItemJSON_instance_input_body, localVar_instance_input_body);
        localVarBodyParameters = cJSON_Print(localVarItemJSON_instance_input_body);
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
    //    printf("%s\n","ETA of input completion in milliseconds.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Invalid input (e.g. unknown button name or malformed position).");
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
    //    printf("%s\n","Instance not found.");
    //}
    //nonprimitive not container
    input_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *InstancesAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = input_response_parseFromJSON(InstancesAPIlocalVarJSON);
        cJSON_Delete(InstancesAPIlocalVarJSON);
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
    if (localVarItemJSON_instance_input_body) {
        cJSON_Delete(localVarItemJSON_instance_input_body);
        localVarItemJSON_instance_input_body = NULL;
    }
    if (localVarSingleItemJSON_instance_input_body) {
        cJSON_Delete(localVarSingleItemJSON_instance_input_body);
        localVarSingleItemJSON_instance_input_body = NULL;
    }
    if (localVar_instance_input_body) {
        cJSON_Delete(localVar_instance_input_body);
        localVar_instance_input_body = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Upload image chunk
//
// Uploads one chunk of a file attached to this device, using the same resumable protocol as `PUT /v3/images/{imageId}/file`. You choose the image ID (a new random UUID) and the image record is created on the first chunk; `type` and `name` in the path set the image type and name. Because the image is attached to the device, it replaces any image of the same `type` already attached (for `partition`, only the one with the same `name`), and it is deleted when the device is deleted. The web interface uses this route, for example to replace a kernel. For your own code, `POST /v3/images` with `instanceId` followed by `PUT /v3/images/{imageId}/file` is easier to follow. Returns 200 with an empty object for each stored chunk.
//
object_t*
InstancesAPI_v3PutInstanceImageUpload(apiClient_t *apiClient, char *instance, char *type, char *imageId, char *name, binary_t* body, double *resumableChunkNumber, double *resumableChunkSize, double *resumableCurrentChunkSize, double *resumableTotalSize, double *resumableTotalChunks, char *corelliumChecksum, char *flavor, char *x_corellium_image_encoding, int *x_corellium_image_encapsulated, double *x_corellium_total_file_size, char *x_corellium_image_password)
{
    list_t    *localVarQueryParameters = list_createList();
    list_t    *localVarHeaderParameters = list_createList();
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/v3/instances/{instance}/image-upload/{type}/{imageId}/{name}");

    if(!instance)
        goto end;
    if(!type)
        goto end;
    if(!imageId)
        goto end;
    if(!name)
        goto end;


    // Path Params
    long sizeOfPathParams_instance = strlen(instance)+3 + strlen(type)+3 + strlen(imageId)+3 + strlen(name)+3 + sizeof("{ instance }") - 1;
    if(instance == NULL) {
        goto end;
    }
    char* localVarToReplace_instance = malloc(sizeOfPathParams_instance);
    sprintf(localVarToReplace_instance, "{%s}", "instance");

    localVarPath = strReplace(localVarPath, localVarToReplace_instance, instance);

    // Path Params
    long sizeOfPathParams_type = strlen(instance)+3 + strlen(type)+3 + strlen(imageId)+3 + strlen(name)+3 + sizeof("{ type }") - 1;
    if(type == NULL) {
        goto end;
    }
    char* localVarToReplace_type = malloc(sizeOfPathParams_type);
    sprintf(localVarToReplace_type, "{%s}", "type");

    localVarPath = strReplace(localVarPath, localVarToReplace_type, type);

    // Path Params
    long sizeOfPathParams_imageId = strlen(instance)+3 + strlen(type)+3 + strlen(imageId)+3 + strlen(name)+3 + sizeof("{ imageId }") - 1;
    if(imageId == NULL) {
        goto end;
    }
    char* localVarToReplace_imageId = malloc(sizeOfPathParams_imageId);
    sprintf(localVarToReplace_imageId, "{%s}", "imageId");

    localVarPath = strReplace(localVarPath, localVarToReplace_imageId, imageId);

    // Path Params
    long sizeOfPathParams_name = strlen(instance)+3 + strlen(type)+3 + strlen(imageId)+3 + strlen(name)+3 + sizeof("{ name }") - 1;
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);



    // header parameters
    char *keyHeader_x_corellium_image_encoding = NULL;
    char * valueHeader_x_corellium_image_encoding = 0;
    keyValuePair_t *keyPairHeader_x_corellium_image_encoding = 0;
    if (x_corellium_image_encoding) {
        keyHeader_x_corellium_image_encoding = strdup("x-corellium-image-encoding");
        valueHeader_x_corellium_image_encoding = strdup((x_corellium_image_encoding));
        keyPairHeader_x_corellium_image_encoding = keyValuePair_create(keyHeader_x_corellium_image_encoding, valueHeader_x_corellium_image_encoding);
        list_addElement(localVarHeaderParameters,keyPairHeader_x_corellium_image_encoding);
    }


    // header parameters
    char *keyHeader_x_corellium_image_encapsulated = NULL;
    int valueHeader_x_corellium_image_encapsulated = 0;
    keyValuePair_t *keyPairHeader_x_corellium_image_encapsulated = 0;
    if (x_corellium_image_encapsulated) {
        keyHeader_x_corellium_image_encapsulated = strdup("x-corellium-image-encapsulated");
        valueHeader_x_corellium_image_encapsulated = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueHeader_x_corellium_image_encapsulated, MAX_NUMBER_LENGTH, "%d", *x_corellium_image_encapsulated);
        keyPairHeader_x_corellium_image_encapsulated = keyValuePair_create(keyHeader_x_corellium_image_encapsulated, &valueHeader_x_corellium_image_encapsulated);
        list_addElement(localVarHeaderParameters,keyPairHeader_x_corellium_image_encapsulated);
    }


    // header parameters
    char *keyHeader_x_corellium_total_file_size = NULL;
    double valueHeader_x_corellium_total_file_size = 0;
    keyValuePair_t *keyPairHeader_x_corellium_total_file_size = 0;
    if (x_corellium_total_file_size) {
        keyHeader_x_corellium_total_file_size = strdup("x-corellium-total-file-size");
        valueHeader_x_corellium_total_file_size = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueHeader_x_corellium_total_file_size, MAX_NUMBER_LENGTH, "%d", *x_corellium_total_file_size);
        keyPairHeader_x_corellium_total_file_size = keyValuePair_create(keyHeader_x_corellium_total_file_size, &valueHeader_x_corellium_total_file_size);
        list_addElement(localVarHeaderParameters,keyPairHeader_x_corellium_total_file_size);
    }


    // header parameters
    char *keyHeader_x_corellium_image_password = NULL;
    char * valueHeader_x_corellium_image_password = 0;
    keyValuePair_t *keyPairHeader_x_corellium_image_password = 0;
    if (x_corellium_image_password) {
        keyHeader_x_corellium_image_password = strdup("x-corellium-image-password");
        valueHeader_x_corellium_image_password = strdup((x_corellium_image_password));
        keyPairHeader_x_corellium_image_password = keyValuePair_create(keyHeader_x_corellium_image_password, valueHeader_x_corellium_image_password);
        list_addElement(localVarHeaderParameters,keyPairHeader_x_corellium_image_password);
    }


    // query parameters
    char *keyQuery_resumableChunkNumber = NULL;
    char * valueQuery_resumableChunkNumber = NULL;
    keyValuePair_t *keyPairQuery_resumableChunkNumber = 0;
    if (resumableChunkNumber)
    {
        keyQuery_resumableChunkNumber = strdup("resumableChunkNumber");
        valueQuery_resumableChunkNumber = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_resumableChunkNumber, MAX_NUMBER_LENGTH, "%d", *resumableChunkNumber);
        keyPairQuery_resumableChunkNumber = keyValuePair_create(keyQuery_resumableChunkNumber, valueQuery_resumableChunkNumber);
        list_addElement(localVarQueryParameters,keyPairQuery_resumableChunkNumber);
    }

    // query parameters
    char *keyQuery_resumableChunkSize = NULL;
    char * valueQuery_resumableChunkSize = NULL;
    keyValuePair_t *keyPairQuery_resumableChunkSize = 0;
    if (resumableChunkSize)
    {
        keyQuery_resumableChunkSize = strdup("resumableChunkSize");
        valueQuery_resumableChunkSize = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_resumableChunkSize, MAX_NUMBER_LENGTH, "%d", *resumableChunkSize);
        keyPairQuery_resumableChunkSize = keyValuePair_create(keyQuery_resumableChunkSize, valueQuery_resumableChunkSize);
        list_addElement(localVarQueryParameters,keyPairQuery_resumableChunkSize);
    }

    // query parameters
    char *keyQuery_resumableCurrentChunkSize = NULL;
    char * valueQuery_resumableCurrentChunkSize = NULL;
    keyValuePair_t *keyPairQuery_resumableCurrentChunkSize = 0;
    if (resumableCurrentChunkSize)
    {
        keyQuery_resumableCurrentChunkSize = strdup("resumableCurrentChunkSize");
        valueQuery_resumableCurrentChunkSize = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_resumableCurrentChunkSize, MAX_NUMBER_LENGTH, "%d", *resumableCurrentChunkSize);
        keyPairQuery_resumableCurrentChunkSize = keyValuePair_create(keyQuery_resumableCurrentChunkSize, valueQuery_resumableCurrentChunkSize);
        list_addElement(localVarQueryParameters,keyPairQuery_resumableCurrentChunkSize);
    }

    // query parameters
    char *keyQuery_resumableTotalSize = NULL;
    char * valueQuery_resumableTotalSize = NULL;
    keyValuePair_t *keyPairQuery_resumableTotalSize = 0;
    if (resumableTotalSize)
    {
        keyQuery_resumableTotalSize = strdup("resumableTotalSize");
        valueQuery_resumableTotalSize = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_resumableTotalSize, MAX_NUMBER_LENGTH, "%d", *resumableTotalSize);
        keyPairQuery_resumableTotalSize = keyValuePair_create(keyQuery_resumableTotalSize, valueQuery_resumableTotalSize);
        list_addElement(localVarQueryParameters,keyPairQuery_resumableTotalSize);
    }

    // query parameters
    char *keyQuery_resumableTotalChunks = NULL;
    char * valueQuery_resumableTotalChunks = NULL;
    keyValuePair_t *keyPairQuery_resumableTotalChunks = 0;
    if (resumableTotalChunks)
    {
        keyQuery_resumableTotalChunks = strdup("resumableTotalChunks");
        valueQuery_resumableTotalChunks = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_resumableTotalChunks, MAX_NUMBER_LENGTH, "%d", *resumableTotalChunks);
        keyPairQuery_resumableTotalChunks = keyValuePair_create(keyQuery_resumableTotalChunks, valueQuery_resumableTotalChunks);
        list_addElement(localVarQueryParameters,keyPairQuery_resumableTotalChunks);
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
    char *keyQuery_flavor = NULL;
    char * valueQuery_flavor = NULL;
    keyValuePair_t *keyPairQuery_flavor = 0;
    if (flavor)
    {
        keyQuery_flavor = strdup("flavor");
        valueQuery_flavor = strdup((flavor));
        keyPairQuery_flavor = keyValuePair_create(keyQuery_flavor, valueQuery_flavor);
        list_addElement(localVarQueryParameters,keyPairQuery_flavor);
    }

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
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","Chunk stored. The body is an empty JSON object. Send the next chunk; the image is finished when the last chunk arrives.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Invalid chunk or upload parameters, unreadable body, or a missing/mismatched corelliumChecksum for a firmware upload.");
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
    //    printf("%s\n","No image with the given identifier.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 507) {
    //    printf("%s\n","The image pool does not have enough space for this upload.");
    //}
    //nonprimitive not container
    object_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *InstancesAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = object_parseFromJSON(InstancesAPIlocalVarJSON);
        cJSON_Delete(InstancesAPIlocalVarJSON);
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
    list_freeList(localVarHeaderParameters);
    
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    free(localVarToReplace_instance);
    free(localVarToReplace_type);
    free(localVarToReplace_imageId);
    free(localVarToReplace_name);
    if (keyHeader_x_corellium_image_encoding) {
        free(keyHeader_x_corellium_image_encoding);
        keyHeader_x_corellium_image_encoding = NULL;
    }
    if (valueHeader_x_corellium_image_encoding) {
        free(valueHeader_x_corellium_image_encoding);
        valueHeader_x_corellium_image_encoding = NULL;
    }
    free(keyPairHeader_x_corellium_image_encoding);
    if (keyHeader_x_corellium_image_encapsulated) {
        free(keyHeader_x_corellium_image_encapsulated);
        keyHeader_x_corellium_image_encapsulated = NULL;
    }
    free(keyPairHeader_x_corellium_image_encapsulated);
    if (keyHeader_x_corellium_total_file_size) {
        free(keyHeader_x_corellium_total_file_size);
        keyHeader_x_corellium_total_file_size = NULL;
    }
    free(keyPairHeader_x_corellium_total_file_size);
    if (keyHeader_x_corellium_image_password) {
        free(keyHeader_x_corellium_image_password);
        keyHeader_x_corellium_image_password = NULL;
    }
    if (valueHeader_x_corellium_image_password) {
        free(valueHeader_x_corellium_image_password);
        valueHeader_x_corellium_image_password = NULL;
    }
    free(keyPairHeader_x_corellium_image_password);
    free(localVarBodyParameters);
    if(keyQuery_resumableChunkNumber){
        free(keyQuery_resumableChunkNumber);
        keyQuery_resumableChunkNumber = NULL;
    }
    if(valueQuery_resumableChunkNumber){
        free(valueQuery_resumableChunkNumber);
        valueQuery_resumableChunkNumber = NULL;
    }
    if(keyPairQuery_resumableChunkNumber){
        keyValuePair_free(keyPairQuery_resumableChunkNumber);
        keyPairQuery_resumableChunkNumber = NULL;
    }
    if(keyQuery_resumableChunkSize){
        free(keyQuery_resumableChunkSize);
        keyQuery_resumableChunkSize = NULL;
    }
    if(valueQuery_resumableChunkSize){
        free(valueQuery_resumableChunkSize);
        valueQuery_resumableChunkSize = NULL;
    }
    if(keyPairQuery_resumableChunkSize){
        keyValuePair_free(keyPairQuery_resumableChunkSize);
        keyPairQuery_resumableChunkSize = NULL;
    }
    if(keyQuery_resumableCurrentChunkSize){
        free(keyQuery_resumableCurrentChunkSize);
        keyQuery_resumableCurrentChunkSize = NULL;
    }
    if(valueQuery_resumableCurrentChunkSize){
        free(valueQuery_resumableCurrentChunkSize);
        valueQuery_resumableCurrentChunkSize = NULL;
    }
    if(keyPairQuery_resumableCurrentChunkSize){
        keyValuePair_free(keyPairQuery_resumableCurrentChunkSize);
        keyPairQuery_resumableCurrentChunkSize = NULL;
    }
    if(keyQuery_resumableTotalSize){
        free(keyQuery_resumableTotalSize);
        keyQuery_resumableTotalSize = NULL;
    }
    if(valueQuery_resumableTotalSize){
        free(valueQuery_resumableTotalSize);
        valueQuery_resumableTotalSize = NULL;
    }
    if(keyPairQuery_resumableTotalSize){
        keyValuePair_free(keyPairQuery_resumableTotalSize);
        keyPairQuery_resumableTotalSize = NULL;
    }
    if(keyQuery_resumableTotalChunks){
        free(keyQuery_resumableTotalChunks);
        keyQuery_resumableTotalChunks = NULL;
    }
    if(valueQuery_resumableTotalChunks){
        free(valueQuery_resumableTotalChunks);
        valueQuery_resumableTotalChunks = NULL;
    }
    if(keyPairQuery_resumableTotalChunks){
        keyValuePair_free(keyPairQuery_resumableTotalChunks);
        keyPairQuery_resumableTotalChunks = NULL;
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
    if(keyQuery_flavor){
        free(keyQuery_flavor);
        keyQuery_flavor = NULL;
    }
    if(valueQuery_flavor){
        free(valueQuery_flavor);
        valueQuery_flavor = NULL;
    }
    if(keyPairQuery_flavor){
        keyValuePair_free(keyPairQuery_flavor);
        keyPairQuery_flavor = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Restart a device
//
// Restarts a running device. Returns 204 once the reboot is accepted; the state becomes `rebooting` and then `on`. Poll `v3GetInstanceState` to see when it is back.
//
void
InstancesAPI_v3RebootInstance(apiClient_t *apiClient, char *instanceId)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/reboot");

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
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Signed in, but not allowed to do this: you lack the required role, have no access to the project, or your license does not include the feature.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Instance not found.");
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

// Restore a backup onto a device
//
// Restores the backup attached to this device, replacing the device's data with the backup's contents. First attach the backup file by uploading it with `POST /v3/images` using `type: \"backup\"` and `instanceId` set to this device. Returns 204 once the restore has been scheduled; it runs in the background, so poll `v3GetInstanceState` until the device settles.  Supply `password` if the backup is encrypted. Fails with 404 if no backup is attached. Requires the backup-restore license feature (403 otherwise).
//
void
InstancesAPI_v3RestoreBackup(apiClient_t *apiClient, char *instanceId, restore_backup_body_t *restore_backup_body)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/restoreBackup");

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
    cJSON *localVarSingleItemJSON_restore_backup_body = NULL;
    if (restore_backup_body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_restore_backup_body = restore_backup_body_convertToJSON(restore_backup_body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_restore_backup_body);
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
    if (localVarSingleItemJSON_restore_backup_body) {
        cJSON_Delete(localVarSingleItemJSON_restore_backup_body);
        localVarSingleItemJSON_restore_backup_body = NULL;
    }
    free(localVarBodyParameters);

}

// Rotate the device
//
// Turns the device to a new orientation, as if you rotated the phone in your hand; apps receive the rotation event. `orientation` is 1 = portrait, 2 = portrait upside down, 3 = landscape (top of device on the left), 4 = landscape (top of device on the right).
//
void
InstancesAPI_v3RotateInstance(apiClient_t *apiClient, char *instanceId, rotate_body_t *rotate_body)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/rotate");

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
    cJSON *localVarSingleItemJSON_rotate_body = NULL;
    if (rotate_body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_rotate_body = rotate_body_convertToJSON(rotate_body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_rotate_body);
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
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Signed in, but not allowed to do this: you lack the required role, have no access to the project, or your license does not include the feature.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Instance not found.");
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
    if (localVarSingleItemJSON_rotate_body) {
        cJSON_Delete(localVarSingleItemJSON_rotate_body);
        localVarSingleItemJSON_rotate_body = NULL;
    }
    free(localVarBodyParameters);

}

// Press board buttons or flip switches
//
// Sets the state of the simulated buttons and switches (GPIO pins) on an IoT or embedded board model, as if you pressed a button or flipped a switch on real hardware; your firmware sees the change. Send the full bank layout you got from `v3GetInstanceGpios`, with the bits you want changed. Returns the state after the change. The device must be running.
//
gpios_state_t*
InstancesAPI_v3SetInstanceGpios(apiClient_t *apiClient, char *instanceId, gpios_state_t *gpios_state)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/gpios");

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
    cJSON *localVarSingleItemJSON_gpios_state = NULL;
    if (gpios_state != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_gpios_state = gpios_state_convertToJSON(gpios_state);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_gpios_state);
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
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","Current GPIOs state.");
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
    //    printf("%s\n","Instance not found.");
    //}
    //nonprimitive not container
    gpios_state_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *InstancesAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = gpios_state_parseFromJSON(InstancesAPIlocalVarJSON);
        cJSON_Delete(InstancesAPIlocalVarJSON);
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
    if (localVarSingleItemJSON_gpios_state) {
        cJSON_Delete(localVarSingleItemJSON_gpios_state);
        localVarSingleItemJSON_gpios_state = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Change simulated sensors
//
// Changes what the device's simulated sensors report to apps, for example to fake a GPS location, a low battery, or a tilt. Send only the fields you want to change. The new values are saved with the device and then the current readings are returned.  A field is applied only if its feature is enabled for the device (motion, environment, location, battery, biometric bypass); values for disabled features are ignored silently, so check the response. `biometricPass: 1` makes fingerprint and face checks succeed.
//
peripherals_data_t*
InstancesAPI_v3SetInstancePeripherals(apiClient_t *apiClient, char *instanceId, peripherals_data_t *peripherals_data)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/peripherals");

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
    cJSON *localVarSingleItemJSON_peripherals_data = NULL;
    if (peripherals_data != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_peripherals_data = peripherals_data_convertToJSON(peripherals_data);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_peripherals_data);
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
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","Current peripherals state.");
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
    //    printf("%s\n","Instance not found.");
    //}
    //nonprimitive not container
    peripherals_data_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *InstancesAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = peripherals_data_parseFromJSON(InstancesAPIlocalVarJSON);
        cJSON_Delete(InstancesAPIlocalVarJSON);
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
    if (localVarSingleItemJSON_peripherals_data) {
        cJSON_Delete(localVarSingleItemJSON_peripherals_data);
        localVarSingleItemJSON_peripherals_data = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Turn a device on
//
// Turns on a device that is `off`. Returns 204 as soon as the start is accepted; the device then boots in the background. Poll `v3GetInstanceState` until it is `on`. Returns 409 if the device is already on.  **Starting paused (`paused: true`).** The device is powered on but no code runs until you call `v3UnpauseInstance` or resume it from a debugger. This is the standard way to debug a device from its very first instruction, for example custom or IoT firmware, or code that runs early in boot: 1. Upload your firmware and create the device (or stop an existing one). 2. `v3StartInstance` with `{ \"paused\": true }`. 3. Connect your debugger (for example GDB) to the device's debug port, shown in the device's connection details. 4. Load symbols from your firmware or kernel file, set breakpoints, or load code into memory. 5. Continue execution from the debugger (`c` in GDB).  Once a debugger is attached, pause and resume from the debugger rather than with `v3PauseInstance` / `v3UnpauseInstance`: GDB expects to control pausing itself, and pausing through the API can confuse its session.  **Network monitoring (`sockCap: true`).** Starts the device with process network monitoring enabled, so network activity can be attributed to the processes that made it.
//
void
InstancesAPI_v3StartInstance(apiClient_t *apiClient, char *instanceId, start_instance_body_t *start_instance_body)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/start");

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
    cJSON *localVarSingleItemJSON_start_instance_body = NULL;
    if (start_instance_body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_start_instance_body = start_instance_body_convertToJSON(start_instance_body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_start_instance_body);
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
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Signed in, but not allowed to do this: you lack the required role, have no access to the project, or your license does not include the feature.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Instance not found.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 409) {
    //    printf("%s\n","Instance is already started.");
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
    if (localVarSingleItemJSON_start_instance_body) {
        cJSON_Delete(localVarSingleItemJSON_start_instance_body);
        localVarSingleItemJSON_start_instance_body = NULL;
    }
    free(localVarBodyParameters);

}

// Start Enhanced Network Monitor
//
// Starts Enhanced Network Monitor on this device. It captures raw network packets, and every filter in the body is optional: limit the capture to certain ports, protocols, hosts, or process names to keep it small. Download it with `v3DownloadNetdumpPcap`. Requires the Enhanced Network Monitor feature (403 otherwise).
//
void
InstancesAPI_v3StartNetdump(apiClient_t *apiClient, char *instanceId, enable_netdump_body_t *enable_netdump_body)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/netdump/enable");

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
    cJSON *localVarSingleItemJSON_enable_netdump_body = NULL;
    if (enable_netdump_body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_enable_netdump_body = enable_netdump_body_convertToJSON(enable_netdump_body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_enable_netdump_body);
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
    if (localVarSingleItemJSON_enable_netdump_body) {
        cJSON_Delete(localVarSingleItemJSON_enable_netdump_body);
        localVarSingleItemJSON_enable_netdump_body = NULL;
    }
    free(localVarBodyParameters);

}

// Start Network Monitor
//
// Starts Network Monitor on this device. It records the device's network traffic, including HTTPS traffic decrypted by intercepting its encryption, so you can see what apps send and receive. Download the capture as a pcap file (open it with Wireshark) with `v3DownloadNetworkMonitorPcap`. Apps that pin their certificates may refuse the intercepted connections. Requires the Network Monitor license feature (403 otherwise).
//
void
InstancesAPI_v3StartNetworkMonitor(apiClient_t *apiClient, char *instanceId, enable_sslsplit_body_t *enable_sslsplit_body)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/sslsplit/enable");

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
    cJSON *localVarSingleItemJSON_enable_sslsplit_body = NULL;
    if (enable_sslsplit_body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_enable_sslsplit_body = enable_sslsplit_body_convertToJSON(enable_sslsplit_body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_enable_sslsplit_body);
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
    if (localVarSingleItemJSON_enable_sslsplit_body) {
        cJSON_Delete(localVarSingleItemJSON_enable_sslsplit_body);
        localVarSingleItemJSON_enable_sslsplit_body = NULL;
    }
    free(localVarBodyParameters);

}

// Turn a device off
//
// Turns a running device off. By default (`soft: true`) the operating system is asked to shut down cleanly. Send `{ \"soft\": false }` to force an immediate stop instead; use it when a clean shutdown does not finish. Returns 204 once the stop is accepted; poll `v3GetInstanceState` until it is `off`. Returns 409 if the device is already off. A stopped device keeps its storage and can be turned on again with `v3StartInstance`.
//
void
InstancesAPI_v3StopInstance(apiClient_t *apiClient, char *instanceId, stop_instance_body_t *stop_instance_body)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/stop");

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
    cJSON *localVarSingleItemJSON_stop_instance_body = NULL;
    if (stop_instance_body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_stop_instance_body = stop_instance_body_convertToJSON(stop_instance_body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_stop_instance_body);
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
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Signed in, but not allowed to do this: you lack the required role, have no access to the project, or your license does not include the feature.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Instance not found.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 409) {
    //    printf("%s\n","Instance is currently in an off state.");
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
    if (localVarSingleItemJSON_stop_instance_body) {
        cJSON_Delete(localVarSingleItemJSON_stop_instance_body);
        localVarSingleItemJSON_stop_instance_body = NULL;
    }
    free(localVarBodyParameters);

}

// Stop Enhanced Network Monitor
//
// Stops Enhanced Network Monitor on this device. The capture so far can still be downloaded with `v3DownloadNetdumpPcap`.
//
void
InstancesAPI_v3StopNetdump(apiClient_t *apiClient, char *instanceId)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/netdump/disable");

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

// Stop Network Monitor
//
// Stops Network Monitor on this device. The capture so far can still be downloaded with `v3DownloadNetworkMonitorPcap`. Requires the Network Monitor license feature.
//
void
InstancesAPI_v3StopNetworkMonitor(apiClient_t *apiClient, char *instanceId)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/sslsplit/disable");

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

// Resume a paused device
//
// Resumes a device that was paused with `v3PauseInstance`, or started with `paused: true`. It continues from exactly where it stopped.
//
void
InstancesAPI_v3UnpauseInstance(apiClient_t *apiClient, char *instanceId)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/unpause");

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
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Signed in, but not allowed to do this: you lack the required role, have no access to the project, or your license does not include the feature.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Instance not found.");
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

// Upgrade the iOS version
//
// Upgrades an iOS device to a newer iOS version while keeping it as the same device. Returns 202 with `state: \"updating\"` once accepted; the upgrade runs in the background, so poll `v3GetInstanceState` until it is `on`. Pick the version from `GET /v3/models/{model}/software`. Use `osVersion`; the old `os` field is rejected. Requires the OS update license feature (403 otherwise).
//
instance_upgrade_response_t*
InstancesAPI_v3UpgradeInstance(apiClient_t *apiClient, char *instanceId, instance_upgrade_body_t *instance_upgrade_body)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/upgrade");

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
    cJSON *localVarSingleItemJSON_instance_upgrade_body = NULL;
    if (instance_upgrade_body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_instance_upgrade_body = instance_upgrade_body_convertToJSON(instance_upgrade_body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_instance_upgrade_body);
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
    //if (apiClient->response_code == 202) {
    //    printf("%s\n","Upgrade started.");
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
    instance_upgrade_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *InstancesAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = instance_upgrade_response_parseFromJSON(InstancesAPIlocalVarJSON);
        cJSON_Delete(InstancesAPIlocalVarJSON);
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
    if (localVarSingleItemJSON_instance_upgrade_body) {
        cJSON_Delete(localVarSingleItemJSON_instance_upgrade_body);
        localVarSingleItemJSON_instance_upgrade_body = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Check a device connection token
//
// Checks whether a connection token issued for this device is still valid. Returns 204 if it is. This call needs no `Authorization` header; the token in the body is what is checked.
//
void
InstancesAPI_v3ValidateInstanceToken(apiClient_t *apiClient, char *instanceId, token_validate_body_t *token_validate_body)
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
    char *localVarPath = strdup("/v3/instances/{instanceId}/token/validate");

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
    cJSON *localVarSingleItemJSON_token_validate_body = NULL;
    if (token_validate_body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_token_validate_body = token_validate_body_convertToJSON(token_validate_body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_token_validate_body);
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
    //    printf("%s\n","Token is valid.");
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
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Instance not found.");
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
    if (localVarSingleItemJSON_token_validate_body) {
        cJSON_Delete(localVarSingleItemJSON_token_validate_body);
        localVarSingleItemJSON_token_validate_body = NULL;
    }
    free(localVarBodyParameters);

}

