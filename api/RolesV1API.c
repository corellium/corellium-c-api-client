#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "RolesV1API.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096


// Add team role to project
//
// This endpoint is available for Enterprise accounts only
//
void
RolesV1API_v1AddTeamRoleToProject(apiClient_t *apiClient, char *projectId, char *teamId, char *roleId)
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
    char *localVarPath = strdup("/v1/roles/projects/{projectId}/teams/{teamId}/roles/{roleId}");

    if(!projectId)
        goto end;
    if(!teamId)
        goto end;
    if(!roleId)
        goto end;


    // Path Params
    long sizeOfPathParams_projectId = strlen(projectId)+3 + strlen(teamId)+3 + strlen(roleId)+3 + sizeof("{ projectId }") - 1;
    if(projectId == NULL) {
        goto end;
    }
    char* localVarToReplace_projectId = malloc(sizeOfPathParams_projectId);
    sprintf(localVarToReplace_projectId, "{%s}", "projectId");

    localVarPath = strReplace(localVarPath, localVarToReplace_projectId, projectId);

    // Path Params
    long sizeOfPathParams_teamId = strlen(projectId)+3 + strlen(teamId)+3 + strlen(roleId)+3 + sizeof("{ teamId }") - 1;
    if(teamId == NULL) {
        goto end;
    }
    char* localVarToReplace_teamId = malloc(sizeOfPathParams_teamId);
    sprintf(localVarToReplace_teamId, "{%s}", "teamId");

    localVarPath = strReplace(localVarPath, localVarToReplace_teamId, teamId);

    // Path Params
    long sizeOfPathParams_roleId = strlen(projectId)+3 + strlen(teamId)+3 + strlen(roleId)+3 + sizeof("{ roleId }") - 1;
    if(roleId == NULL) {
        goto end;
    }
    char* localVarToReplace_roleId = malloc(sizeOfPathParams_roleId);
    sprintf(localVarToReplace_roleId, "{%s}", "roleId");

    localVarPath = strReplace(localVarPath, localVarToReplace_roleId, roleId);


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
                    "PUT");

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
    free(localVarToReplace_teamId);
    free(localVarToReplace_roleId);

}

// Add user role to project
//
// This endpoint is available for Enterprise accounts only
//
void
RolesV1API_v1AddUserRoleToProject(apiClient_t *apiClient, char *projectId, char *userId, char *roleId)
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
    char *localVarPath = strdup("/v1/roles/projects/{projectId}/users/{userId}/roles/{roleId}");

    if(!projectId)
        goto end;
    if(!userId)
        goto end;
    if(!roleId)
        goto end;


    // Path Params
    long sizeOfPathParams_projectId = strlen(projectId)+3 + strlen(userId)+3 + strlen(roleId)+3 + sizeof("{ projectId }") - 1;
    if(projectId == NULL) {
        goto end;
    }
    char* localVarToReplace_projectId = malloc(sizeOfPathParams_projectId);
    sprintf(localVarToReplace_projectId, "{%s}", "projectId");

    localVarPath = strReplace(localVarPath, localVarToReplace_projectId, projectId);

    // Path Params
    long sizeOfPathParams_userId = strlen(projectId)+3 + strlen(userId)+3 + strlen(roleId)+3 + sizeof("{ userId }") - 1;
    if(userId == NULL) {
        goto end;
    }
    char* localVarToReplace_userId = malloc(sizeOfPathParams_userId);
    sprintf(localVarToReplace_userId, "{%s}", "userId");

    localVarPath = strReplace(localVarPath, localVarToReplace_userId, userId);

    // Path Params
    long sizeOfPathParams_roleId = strlen(projectId)+3 + strlen(userId)+3 + strlen(roleId)+3 + sizeof("{ roleId }") - 1;
    if(roleId == NULL) {
        goto end;
    }
    char* localVarToReplace_roleId = malloc(sizeOfPathParams_roleId);
    sprintf(localVarToReplace_roleId, "{%s}", "roleId");

    localVarPath = strReplace(localVarPath, localVarToReplace_roleId, roleId);


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
                    "PUT");

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
    free(localVarToReplace_userId);
    free(localVarToReplace_roleId);

}

// Remove team role from project
//
// This endpoint is available for Enterprise accounts only
//
void
RolesV1API_v1RemoveTeamRoleFromProject(apiClient_t *apiClient, char *projectId, char *teamId, char *roleId)
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
    char *localVarPath = strdup("/v1/roles/projects/{projectId}/teams/{teamId}/roles/{roleId}");

    if(!projectId)
        goto end;
    if(!teamId)
        goto end;
    if(!roleId)
        goto end;


    // Path Params
    long sizeOfPathParams_projectId = strlen(projectId)+3 + strlen(teamId)+3 + strlen(roleId)+3 + sizeof("{ projectId }") - 1;
    if(projectId == NULL) {
        goto end;
    }
    char* localVarToReplace_projectId = malloc(sizeOfPathParams_projectId);
    sprintf(localVarToReplace_projectId, "{%s}", "projectId");

    localVarPath = strReplace(localVarPath, localVarToReplace_projectId, projectId);

    // Path Params
    long sizeOfPathParams_teamId = strlen(projectId)+3 + strlen(teamId)+3 + strlen(roleId)+3 + sizeof("{ teamId }") - 1;
    if(teamId == NULL) {
        goto end;
    }
    char* localVarToReplace_teamId = malloc(sizeOfPathParams_teamId);
    sprintf(localVarToReplace_teamId, "{%s}", "teamId");

    localVarPath = strReplace(localVarPath, localVarToReplace_teamId, teamId);

    // Path Params
    long sizeOfPathParams_roleId = strlen(projectId)+3 + strlen(teamId)+3 + strlen(roleId)+3 + sizeof("{ roleId }") - 1;
    if(roleId == NULL) {
        goto end;
    }
    char* localVarToReplace_roleId = malloc(sizeOfPathParams_roleId);
    sprintf(localVarToReplace_roleId, "{%s}", "roleId");

    localVarPath = strReplace(localVarPath, localVarToReplace_roleId, roleId);


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
    free(localVarToReplace_teamId);
    free(localVarToReplace_roleId);

}

// Remove user role from project
//
// This endpoint is available for Enterprise accounts only
//
void
RolesV1API_v1RemoveUserRoleFromProject(apiClient_t *apiClient, char *projectId, char *userId, char *roleId)
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
    char *localVarPath = strdup("/v1/roles/projects/{projectId}/users/{userId}/roles/{roleId}");

    if(!projectId)
        goto end;
    if(!userId)
        goto end;
    if(!roleId)
        goto end;


    // Path Params
    long sizeOfPathParams_projectId = strlen(projectId)+3 + strlen(userId)+3 + strlen(roleId)+3 + sizeof("{ projectId }") - 1;
    if(projectId == NULL) {
        goto end;
    }
    char* localVarToReplace_projectId = malloc(sizeOfPathParams_projectId);
    sprintf(localVarToReplace_projectId, "{%s}", "projectId");

    localVarPath = strReplace(localVarPath, localVarToReplace_projectId, projectId);

    // Path Params
    long sizeOfPathParams_userId = strlen(projectId)+3 + strlen(userId)+3 + strlen(roleId)+3 + sizeof("{ userId }") - 1;
    if(userId == NULL) {
        goto end;
    }
    char* localVarToReplace_userId = malloc(sizeOfPathParams_userId);
    sprintf(localVarToReplace_userId, "{%s}", "userId");

    localVarPath = strReplace(localVarPath, localVarToReplace_userId, userId);

    // Path Params
    long sizeOfPathParams_roleId = strlen(projectId)+3 + strlen(userId)+3 + strlen(roleId)+3 + sizeof("{ roleId }") - 1;
    if(roleId == NULL) {
        goto end;
    }
    char* localVarToReplace_roleId = malloc(sizeOfPathParams_roleId);
    sprintf(localVarToReplace_roleId, "{%s}", "roleId");

    localVarPath = strReplace(localVarPath, localVarToReplace_roleId, roleId);


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
    free(localVarToReplace_userId);
    free(localVarToReplace_roleId);

}

// Get all roles
//
// This endpoint is available for Enterprise accounts only
//
list_t*
RolesV1API_v1Roles(apiClient_t *apiClient)
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
    char *localVarPath = strdup("/v1/roles");




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
    //    printf("%s\n","Roles");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Forbidden");
    //}
    list_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *RolesV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        if(!cJSON_IsArray(RolesV1APIlocalVarJSON)) {
            return 0;//nonprimitive container
        }
        elementToReturn = list_createList();
        cJSON *VarJSON;
        cJSON_ArrayForEach(VarJSON, RolesV1APIlocalVarJSON)
        {
            if(!cJSON_IsObject(VarJSON))
            {
               // return 0;
            }
            char *localVarJSONToChar = cJSON_Print(VarJSON);
            list_addElement(elementToReturn , localVarJSONToChar);
        }

        cJSON_Delete( RolesV1APIlocalVarJSON);
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
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

