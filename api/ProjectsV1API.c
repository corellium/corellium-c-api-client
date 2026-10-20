#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "ProjectsV1API.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096


// Add Project Authorized Key
//
project_key_v1_t*
ProjectsV1API_v1AddProjectKey(apiClient_t *apiClient, char *projectId, project_key_v1_t *project_key_v1)
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
    char *localVarPath = strdup("/v1/projects/{projectId}/keys");

    if(!projectId)
        goto end;


    // Path Params
    long sizeOfPathParams_projectId = strlen(projectId)+3 + sizeof("{ projectId }") - 1;
    if(projectId == NULL) {
        goto end;
    }
    char* localVarToReplace_projectId = malloc(sizeOfPathParams_projectId);
    sprintf(localVarToReplace_projectId, "{%s}", "projectId");

    localVarPath = strReplace(localVarPath, localVarToReplace_projectId, projectId);



    // Body Param
    cJSON *localVarSingleItemJSON_project_key_v1 = NULL;
    if (project_key_v1 != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_project_key_v1 = project_key_v1_convertToJSON(project_key_v1);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_project_key_v1);
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
    //    printf("%s\n","Authorized Key");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Forbidden");
    //}
    //nonprimitive not container
    project_key_v1_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ProjectsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = project_key_v1_parseFromJSON(ProjectsV1APIlocalVarJSON);
        cJSON_Delete(ProjectsV1APIlocalVarJSON);
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
    free(localVarToReplace_projectId);
    if (localVarSingleItemJSON_project_key_v1) {
        cJSON_Delete(localVarSingleItemJSON_project_key_v1);
        localVarSingleItemJSON_project_key_v1 = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Create a Project
//
project_v1_t*
ProjectsV1API_v1CreateProject(apiClient_t *apiClient, project_v1_t *project_v1)
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
    char *localVarPath = strdup("/v1/projects");





    // Body Param
    cJSON *localVarSingleItemJSON_project_v1 = NULL;
    if (project_v1 != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_project_v1 = project_v1_convertToJSON(project_v1);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_project_v1);
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
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Forbidden");
    //}
    //nonprimitive not container
    project_v1_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ProjectsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = project_v1_parseFromJSON(ProjectsV1APIlocalVarJSON);
        cJSON_Delete(ProjectsV1APIlocalVarJSON);
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
    if (localVarSingleItemJSON_project_v1) {
        cJSON_Delete(localVarSingleItemJSON_project_v1);
        localVarSingleItemJSON_project_v1 = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Delete a Project
//
void
ProjectsV1API_v1DeleteProject(apiClient_t *apiClient, char *projectId)
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
    char *localVarPath = strdup("/v1/projects/{projectId}");

    if(!projectId)
        goto end;


    // Path Params
    long sizeOfPathParams_projectId = strlen(projectId)+3 + sizeof("{ projectId }") - 1;
    if(projectId == NULL) {
        goto end;
    }
    char* localVarToReplace_projectId = malloc(sizeOfPathParams_projectId);
    sprintf(localVarToReplace_projectId, "{%s}", "projectId");

    localVarPath = strReplace(localVarPath, localVarToReplace_projectId, projectId);


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
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Forbidden");
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
    free(localVarToReplace_projectId);

}

// Get a Project
//
project_with_keys_v1_t*
ProjectsV1API_v1GetProject(apiClient_t *apiClient, char *projectId)
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
    char *localVarPath = strdup("/v1/projects/{projectId}");

    if(!projectId)
        goto end;


    // Path Params
    long sizeOfPathParams_projectId = strlen(projectId)+3 + sizeof("{ projectId }") - 1;
    if(projectId == NULL) {
        goto end;
    }
    char* localVarToReplace_projectId = malloc(sizeOfPathParams_projectId);
    sprintf(localVarToReplace_projectId, "{%s}", "projectId");

    localVarPath = strReplace(localVarPath, localVarToReplace_projectId, projectId);


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
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Forbidden");
    //}
    //nonprimitive not container
    project_with_keys_v1_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ProjectsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = project_with_keys_v1_parseFromJSON(ProjectsV1APIlocalVarJSON);
        cJSON_Delete(ProjectsV1APIlocalVarJSON);
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
    free(localVarToReplace_projectId);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Get Instances in Project
//
list_t*
ProjectsV1API_v1GetProjectInstances(apiClient_t *apiClient, char *projectId, char *name, char *returnAttr)
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
    char *localVarPath = strdup("/v1/projects/{projectId}/instances");

    if(!projectId)
        goto end;


    // Path Params
    long sizeOfPathParams_projectId = strlen(projectId)+3 + sizeof("{ projectId }") - 1;
    if(projectId == NULL) {
        goto end;
    }
    char* localVarToReplace_projectId = malloc(sizeOfPathParams_projectId);
    sprintf(localVarToReplace_projectId, "{%s}", "projectId");

    localVarPath = strReplace(localVarPath, localVarToReplace_projectId, projectId);



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
    //    printf("%s\n","Success");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Forbidden");
    //}
    list_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ProjectsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        if(!cJSON_IsArray(ProjectsV1APIlocalVarJSON)) {
            return 0;//nonprimitive container
        }
        elementToReturn = list_createList();
        cJSON *VarJSON;
        cJSON_ArrayForEach(VarJSON, ProjectsV1APIlocalVarJSON)
        {
            if(!cJSON_IsObject(VarJSON))
            {
               // return 0;
            }
            char *localVarJSONToChar = cJSON_Print(VarJSON);
            list_addElement(elementToReturn , localVarJSONToChar);
        }

        cJSON_Delete( ProjectsV1APIlocalVarJSON);
        cJSON_Delete( VarJSON);
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
    free(localVarToReplace_projectId);
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

// Get Project Authorized Keys
//
list_t*
ProjectsV1API_v1GetProjectKeys(apiClient_t *apiClient, char *projectId)
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
    char *localVarPath = strdup("/v1/projects/{projectId}/keys");

    if(!projectId)
        goto end;


    // Path Params
    long sizeOfPathParams_projectId = strlen(projectId)+3 + sizeof("{ projectId }") - 1;
    if(projectId == NULL) {
        goto end;
    }
    char* localVarToReplace_projectId = malloc(sizeOfPathParams_projectId);
    sprintf(localVarToReplace_projectId, "{%s}", "projectId");

    localVarPath = strReplace(localVarPath, localVarToReplace_projectId, projectId);


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
    //    printf("%s\n","Authorized Keys");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Forbidden");
    //}
    list_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ProjectsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        if(!cJSON_IsArray(ProjectsV1APIlocalVarJSON)) {
            return 0;//nonprimitive container
        }
        elementToReturn = list_createList();
        cJSON *VarJSON;
        cJSON_ArrayForEach(VarJSON, ProjectsV1APIlocalVarJSON)
        {
            if(!cJSON_IsObject(VarJSON))
            {
               // return 0;
            }
            char *localVarJSONToChar = cJSON_Print(VarJSON);
            list_addElement(elementToReturn , localVarJSONToChar);
        }

        cJSON_Delete( ProjectsV1APIlocalVarJSON);
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
    free(localVarToReplace_projectId);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Retrieve the network connection log for a project
//
char*
ProjectsV1API_v1GetProjectNetworkLog(apiClient_t *apiClient, char *projectId)
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
    char *localVarPath = strdup("/v1/projects/{projectId}/network/log");

    if(!projectId)
        goto end;


    // Path Params
    long sizeOfPathParams_projectId = strlen(projectId)+3 + sizeof("{ projectId }") - 1;
    if(projectId == NULL) {
        goto end;
    }
    char* localVarToReplace_projectId = malloc(sizeOfPathParams_projectId);
    sprintf(localVarToReplace_projectId, "{%s}", "projectId");

    localVarPath = strReplace(localVarPath, localVarToReplace_projectId, projectId);


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
    //    printf("%s\n","OK");
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
    //if (apiClient->response_code == 503) {
    //    printf("%s\n","Service Unavailable");
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
    free(localVarToReplace_projectId);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Retrieve the network connection status for a project
//
network_status_response_t*
ProjectsV1API_v1GetProjectNetworkStatus(apiClient_t *apiClient, char *projectId)
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
    char *localVarPath = strdup("/v1/projects/{projectId}/network/status");

    if(!projectId)
        goto end;


    // Path Params
    long sizeOfPathParams_projectId = strlen(projectId)+3 + sizeof("{ projectId }") - 1;
    if(projectId == NULL) {
        goto end;
    }
    char* localVarToReplace_projectId = malloc(sizeOfPathParams_projectId);
    sprintf(localVarToReplace_projectId, "{%s}", "projectId");

    localVarPath = strReplace(localVarPath, localVarToReplace_projectId, projectId);


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
    //    printf("%s\n","OK");
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
    network_status_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ProjectsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = network_status_response_parseFromJSON(ProjectsV1APIlocalVarJSON);
        cJSON_Delete(ProjectsV1APIlocalVarJSON);
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
    free(localVarToReplace_projectId);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Get Project VPN Configuration
//
// A Project VPN allows connection _into_ virtual devices in the project (e.g., connecting a researcher's computer as a VPN client to a virtual device within the project). If a Project VPN has been defined, this will return the configuration.
//
char*
ProjectsV1API_v1GetProjectVpnConfig(apiClient_t *apiClient, char *projectId, char *format)
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
    char *localVarPath = strdup("/v1/projects/{projectId}/vpnconfig/{format}");

    if(!projectId)
        goto end;
    if(!format)
        goto end;


    // Path Params
    long sizeOfPathParams_projectId = strlen(projectId)+3 + strlen(format)+3 + sizeof("{ projectId }") - 1;
    if(projectId == NULL) {
        goto end;
    }
    char* localVarToReplace_projectId = malloc(sizeOfPathParams_projectId);
    sprintf(localVarToReplace_projectId, "{%s}", "projectId");

    localVarPath = strReplace(localVarPath, localVarToReplace_projectId, projectId);

    // Path Params
    long sizeOfPathParams_format = strlen(projectId)+3 + strlen(format)+3 + sizeof("{ format }") - 1;
    if(format == NULL) {
        goto end;
    }
    char* localVarToReplace_format = malloc(sizeOfPathParams_format);
    sprintf(localVarToReplace_format, "{%s}", "format");

    localVarPath = strReplace(localVarPath, localVarToReplace_format, format);


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
    //    printf("%s\n","OpenVPN Configuration");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Forbidden");
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
    free(localVarToReplace_projectId);
    free(localVarToReplace_format);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Get Projects
//
list_t*
ProjectsV1API_v1GetProjects(apiClient_t *apiClient, char *name, int *ids_only)
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
    char *localVarPath = strdup("/v1/projects");





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
    char *keyQuery_ids_only = NULL;
    char * valueQuery_ids_only = NULL;
    keyValuePair_t *keyPairQuery_ids_only = 0;
    if (ids_only)
    {
        keyQuery_ids_only = strdup("ids_only");
        valueQuery_ids_only = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_ids_only, MAX_NUMBER_LENGTH, "%d", *ids_only);
        keyPairQuery_ids_only = keyValuePair_create(keyQuery_ids_only, valueQuery_ids_only);
        list_addElement(localVarQueryParameters,keyPairQuery_ids_only);
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
    //    printf("%s\n","Projects");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Forbidden");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","No Projects Found");
    //}
    list_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ProjectsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        if(!cJSON_IsArray(ProjectsV1APIlocalVarJSON)) {
            return 0;//nonprimitive container
        }
        elementToReturn = list_createList();
        cJSON *VarJSON;
        cJSON_ArrayForEach(VarJSON, ProjectsV1APIlocalVarJSON)
        {
            if(!cJSON_IsObject(VarJSON))
            {
               // return 0;
            }
            char *localVarJSONToChar = cJSON_Print(VarJSON);
            list_addElement(elementToReturn , localVarJSONToChar);
        }

        cJSON_Delete( ProjectsV1APIlocalVarJSON);
        cJSON_Delete( VarJSON);
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
    if(keyQuery_ids_only){
        free(keyQuery_ids_only);
        keyQuery_ids_only = NULL;
    }
    if(valueQuery_ids_only){
        free(valueQuery_ids_only);
        valueQuery_ids_only = NULL;
    }
    if(keyPairQuery_ids_only){
        keyValuePair_free(keyPairQuery_ids_only);
        keyPairQuery_ids_only = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Delete Project Authorized Key
//
void
ProjectsV1API_v1RemoveProjectKey(apiClient_t *apiClient, char *projectId, char *keyId)
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
    char *localVarPath = strdup("/v1/projects/{projectId}/keys/{keyId}");

    if(!projectId)
        goto end;
    if(!keyId)
        goto end;


    // Path Params
    long sizeOfPathParams_projectId = strlen(projectId)+3 + strlen(keyId)+3 + sizeof("{ projectId }") - 1;
    if(projectId == NULL) {
        goto end;
    }
    char* localVarToReplace_projectId = malloc(sizeOfPathParams_projectId);
    sprintf(localVarToReplace_projectId, "{%s}", "projectId");

    localVarPath = strReplace(localVarPath, localVarToReplace_projectId, projectId);

    // Path Params
    long sizeOfPathParams_keyId = strlen(projectId)+3 + strlen(keyId)+3 + sizeof("{ keyId }") - 1;
    if(keyId == NULL) {
        goto end;
    }
    char* localVarToReplace_keyId = malloc(sizeOfPathParams_keyId);
    sprintf(localVarToReplace_keyId, "{%s}", "keyId");

    localVarPath = strReplace(localVarPath, localVarToReplace_keyId, keyId);


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
    //    printf("%s\n","Deleted");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Forbidden");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Not found");
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
    free(localVarToReplace_projectId);
    free(localVarToReplace_keyId);

}

// Update a Project
//
project_v1_t*
ProjectsV1API_v1UpdateProject(apiClient_t *apiClient, char *projectId, project_v1_t *project_v1)
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
    char *localVarPath = strdup("/v1/projects/{projectId}");

    if(!projectId)
        goto end;


    // Path Params
    long sizeOfPathParams_projectId = strlen(projectId)+3 + sizeof("{ projectId }") - 1;
    if(projectId == NULL) {
        goto end;
    }
    char* localVarToReplace_projectId = malloc(sizeOfPathParams_projectId);
    sprintf(localVarToReplace_projectId, "{%s}", "projectId");

    localVarPath = strReplace(localVarPath, localVarToReplace_projectId, projectId);



    // Body Param
    cJSON *localVarSingleItemJSON_project_v1 = NULL;
    if (project_v1 != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_project_v1 = project_v1_convertToJSON(project_v1);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_project_v1);
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
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Forbidden");
    //}
    //nonprimitive not container
    project_v1_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ProjectsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = project_v1_parseFromJSON(ProjectsV1APIlocalVarJSON);
        cJSON_Delete(ProjectsV1APIlocalVarJSON);
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
    free(localVarToReplace_projectId);
    if (localVarSingleItemJSON_project_v1) {
        cJSON_Delete(localVarSingleItemJSON_project_v1);
        localVarSingleItemJSON_project_v1 = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Change Project Settings
//
void
ProjectsV1API_v1UpdateProjectSettings(apiClient_t *apiClient, char *projectId, project_settings_v1_t *project_settings_v1)
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
    char *localVarPath = strdup("/v1/projects/{projectId}/settings");

    if(!projectId)
        goto end;


    // Path Params
    long sizeOfPathParams_projectId = strlen(projectId)+3 + sizeof("{ projectId }") - 1;
    if(projectId == NULL) {
        goto end;
    }
    char* localVarToReplace_projectId = malloc(sizeOfPathParams_projectId);
    sprintf(localVarToReplace_projectId, "{%s}", "projectId");

    localVarPath = strReplace(localVarPath, localVarToReplace_projectId, projectId);



    // Body Param
    cJSON *localVarSingleItemJSON_project_settings_v1 = NULL;
    if (project_settings_v1 != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_project_settings_v1 = project_settings_v1_convertToJSON(project_settings_v1);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_project_settings_v1);
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
    //    printf("%s\n","Success");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Validation Error");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Forbidden");
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
    free(localVarToReplace_projectId);
    if (localVarSingleItemJSON_project_settings_v1) {
        cJSON_Delete(localVarSingleItemJSON_project_settings_v1);
        localVarSingleItemJSON_project_settings_v1 = NULL;
    }
    free(localVarBodyParameters);

}

