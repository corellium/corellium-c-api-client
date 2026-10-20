#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "ConfigAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096


// Get deployment configuration
//
// Returns how this Corellium deployment is set up: its version, whether it is on-site or cloud, whether it is air-gapped, the sign-in providers offered, limits such as the per-device snapshot limit (`snapshotLimit`) and the maximum kernel and ramdisk upload sizes, and which optional features are turned on. Needs no sign-in, so a client can call it first to adapt to the deployment before the user signs in. Build-time feature flags may add further boolean properties beyond those listed.
//
config_response_t*
ConfigAPI_v3GetConfig(apiClient_t *apiClient)
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
    char *localVarPath = strdup("/v3/config");




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
    //nonprimitive not container
    config_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ConfigAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = config_response_parseFromJSON(ConfigAPIlocalVarJSON);
        cJSON_Delete(ConfigAPIlocalVarJSON);
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

// Get the platform version
//
// Returns which version of the Corellium platform you are talking to: the product version (for example `7.4.0-28212`), plus the build it came from. Include it when reporting a problem to support, or check it to see whether a feature you need is available on this deployment.
//
deployment_version_t*
ConfigAPI_v3GetVersion(apiClient_t *apiClient)
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
    char *localVarPath = strdup("/v3/version");




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
    //    printf("%s\n","Version and build identity of the running deployment.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
    //}
    //nonprimitive not container
    deployment_version_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ConfigAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = deployment_version_parseFromJSON(ConfigAPIlocalVarJSON);
        cJSON_Delete(ConfigAPIlocalVarJSON);
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

