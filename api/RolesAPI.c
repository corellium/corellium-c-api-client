#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "RolesAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096


// Add team role to deployment
//
// **Required role:** Domain administrator.  Grants a team a role within a deployment. Available for Enterprise accounts only.
//
void
RolesAPI_v3AddTeamRoleToDeployment(apiClient_t *apiClient, char *deploymentId, char *teamId, char *roleId)
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
    char *localVarPath = strdup("/v3/roles/deployments/{deploymentId}/teams/{teamId}/roles/{roleId}");

    if(!deploymentId)
        goto end;
    if(!teamId)
        goto end;
    if(!roleId)
        goto end;


    // Path Params
    long sizeOfPathParams_deploymentId = strlen(deploymentId)+3 + strlen(teamId)+3 + strlen(roleId)+3 + sizeof("{ deploymentId }") - 1;
    if(deploymentId == NULL) {
        goto end;
    }
    char* localVarToReplace_deploymentId = malloc(sizeOfPathParams_deploymentId);
    sprintf(localVarToReplace_deploymentId, "{%s}", "deploymentId");

    localVarPath = strReplace(localVarPath, localVarToReplace_deploymentId, deploymentId);

    // Path Params
    long sizeOfPathParams_teamId = strlen(deploymentId)+3 + strlen(teamId)+3 + strlen(roleId)+3 + sizeof("{ teamId }") - 1;
    if(teamId == NULL) {
        goto end;
    }
    char* localVarToReplace_teamId = malloc(sizeOfPathParams_teamId);
    sprintf(localVarToReplace_teamId, "{%s}", "teamId");

    localVarPath = strReplace(localVarPath, localVarToReplace_teamId, teamId);

    // Path Params
    long sizeOfPathParams_roleId = strlen(deploymentId)+3 + strlen(teamId)+3 + strlen(roleId)+3 + sizeof("{ roleId }") - 1;
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
    //if (apiClient->response_code == 204) {
    //    printf("%s\n","Role assigned.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Invalid request.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Domain administrator permissions required.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Deployment, team, or role not found.");
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
    free(localVarToReplace_deploymentId);
    free(localVarToReplace_teamId);
    free(localVarToReplace_roleId);

}

// Add team role to project
//
// **Required role:** Domain administrator or project administrator.  Grants a team a role within a project. Available for Enterprise accounts only.
//
void
RolesAPI_v3AddTeamRoleToProject(apiClient_t *apiClient, char *projectId, char *teamId, char *roleId)
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
    char *localVarPath = strdup("/v3/roles/projects/{projectId}/teams/{teamId}/roles/{roleId}");

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
    //if (apiClient->response_code == 204) {
    //    printf("%s\n","Role assigned.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Invalid request.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Domain administrator or project administrator permissions required.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Project, team, or role not found.");
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

// Add user role to deployment
//
// **Required role:** Domain administrator.  Grants a user a role within a deployment. Available for Enterprise accounts only.
//
void
RolesAPI_v3AddUserRoleToDeployment(apiClient_t *apiClient, char *deploymentId, char *userId, char *roleId)
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
    char *localVarPath = strdup("/v3/roles/deployments/{deploymentId}/users/{userId}/roles/{roleId}");

    if(!deploymentId)
        goto end;
    if(!userId)
        goto end;
    if(!roleId)
        goto end;


    // Path Params
    long sizeOfPathParams_deploymentId = strlen(deploymentId)+3 + strlen(userId)+3 + strlen(roleId)+3 + sizeof("{ deploymentId }") - 1;
    if(deploymentId == NULL) {
        goto end;
    }
    char* localVarToReplace_deploymentId = malloc(sizeOfPathParams_deploymentId);
    sprintf(localVarToReplace_deploymentId, "{%s}", "deploymentId");

    localVarPath = strReplace(localVarPath, localVarToReplace_deploymentId, deploymentId);

    // Path Params
    long sizeOfPathParams_userId = strlen(deploymentId)+3 + strlen(userId)+3 + strlen(roleId)+3 + sizeof("{ userId }") - 1;
    if(userId == NULL) {
        goto end;
    }
    char* localVarToReplace_userId = malloc(sizeOfPathParams_userId);
    sprintf(localVarToReplace_userId, "{%s}", "userId");

    localVarPath = strReplace(localVarPath, localVarToReplace_userId, userId);

    // Path Params
    long sizeOfPathParams_roleId = strlen(deploymentId)+3 + strlen(userId)+3 + strlen(roleId)+3 + sizeof("{ roleId }") - 1;
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
    //if (apiClient->response_code == 204) {
    //    printf("%s\n","Role assigned.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Invalid request.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Domain administrator permissions required.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Deployment, user, or role not found.");
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
    free(localVarToReplace_deploymentId);
    free(localVarToReplace_userId);
    free(localVarToReplace_roleId);

}

// Add user role to project
//
// **Required role:** Domain administrator or project administrator.  Grants a user a role within a project. Available for Enterprise accounts only.
//
void
RolesAPI_v3AddUserRoleToProject(apiClient_t *apiClient, char *projectId, char *userId, char *roleId)
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
    char *localVarPath = strdup("/v3/roles/projects/{projectId}/users/{userId}/roles/{roleId}");

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
    //if (apiClient->response_code == 204) {
    //    printf("%s\n","Role assigned.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Invalid request.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Domain administrator or project administrator permissions required.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Project, user, or role not found.");
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

// List deployment role assignments
//
// **Required role:** Domain administrator or project administrator.  Returns paginated role assignments scoped to deployments. Available for Enterprise accounts only.
//
roles_list_response_t*
RolesAPI_v3ListDeploymentRoles(apiClient_t *apiClient, double *limit, double *offset)
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
    char *localVarPath = strdup("/v3/roles/deployments");





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
    //    printf("%s\n","Paginated list of deployment role assignments.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Invalid request.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Domain administrator or project administrator permissions required.");
    //}
    //nonprimitive not container
    roles_list_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *RolesAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = roles_list_response_parseFromJSON(RolesAPIlocalVarJSON);
        cJSON_Delete(RolesAPIlocalVarJSON);
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

// List all role assignments for the caller's domain
//
// **Required role:** Domain administrator or project administrator.  Returns paginated project role assignments for both users and teams. Available for Enterprise accounts only.
//
roles_list_response_t*
RolesAPI_v3ListRoles(apiClient_t *apiClient, double *limit, double *offset)
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
    char *localVarPath = strdup("/v3/roles");





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
    //    printf("%s\n","Paginated list of role assignments.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Invalid request.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Domain administrator or project administrator permissions required.");
    //}
    //nonprimitive not container
    roles_list_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *RolesAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = roles_list_response_parseFromJSON(RolesAPIlocalVarJSON);
        cJSON_Delete(RolesAPIlocalVarJSON);
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

// Remove team role from deployment
//
// **Required role:** Domain administrator.  Revokes a team role within a deployment. Available for Enterprise accounts only.
//
void
RolesAPI_v3RemoveTeamRoleFromDeployment(apiClient_t *apiClient, char *deploymentId, char *teamId, char *roleId)
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
    char *localVarPath = strdup("/v3/roles/deployments/{deploymentId}/teams/{teamId}/roles/{roleId}");

    if(!deploymentId)
        goto end;
    if(!teamId)
        goto end;
    if(!roleId)
        goto end;


    // Path Params
    long sizeOfPathParams_deploymentId = strlen(deploymentId)+3 + strlen(teamId)+3 + strlen(roleId)+3 + sizeof("{ deploymentId }") - 1;
    if(deploymentId == NULL) {
        goto end;
    }
    char* localVarToReplace_deploymentId = malloc(sizeOfPathParams_deploymentId);
    sprintf(localVarToReplace_deploymentId, "{%s}", "deploymentId");

    localVarPath = strReplace(localVarPath, localVarToReplace_deploymentId, deploymentId);

    // Path Params
    long sizeOfPathParams_teamId = strlen(deploymentId)+3 + strlen(teamId)+3 + strlen(roleId)+3 + sizeof("{ teamId }") - 1;
    if(teamId == NULL) {
        goto end;
    }
    char* localVarToReplace_teamId = malloc(sizeOfPathParams_teamId);
    sprintf(localVarToReplace_teamId, "{%s}", "teamId");

    localVarPath = strReplace(localVarPath, localVarToReplace_teamId, teamId);

    // Path Params
    long sizeOfPathParams_roleId = strlen(deploymentId)+3 + strlen(teamId)+3 + strlen(roleId)+3 + sizeof("{ roleId }") - 1;
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
    //if (apiClient->response_code == 204) {
    //    printf("%s\n","Role removed.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Invalid request.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Domain administrator permissions required.");
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
    free(localVarToReplace_deploymentId);
    free(localVarToReplace_teamId);
    free(localVarToReplace_roleId);

}

// Remove team role from project
//
// **Required role:** Domain administrator or project administrator.  Revokes a team role within a project. Available for Enterprise accounts only.
//
void
RolesAPI_v3RemoveTeamRoleFromProject(apiClient_t *apiClient, char *projectId, char *teamId, char *roleId)
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
    char *localVarPath = strdup("/v3/roles/projects/{projectId}/teams/{teamId}/roles/{roleId}");

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
    //if (apiClient->response_code == 204) {
    //    printf("%s\n","Role removed.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Invalid request.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Domain administrator or project administrator permissions required.");
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

// Remove user role from deployment
//
// **Required role:** Domain administrator.  Revokes a user role within a deployment. Available for Enterprise accounts only.
//
void
RolesAPI_v3RemoveUserRoleFromDeployment(apiClient_t *apiClient, char *deploymentId, char *userId, char *roleId)
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
    char *localVarPath = strdup("/v3/roles/deployments/{deploymentId}/users/{userId}/roles/{roleId}");

    if(!deploymentId)
        goto end;
    if(!userId)
        goto end;
    if(!roleId)
        goto end;


    // Path Params
    long sizeOfPathParams_deploymentId = strlen(deploymentId)+3 + strlen(userId)+3 + strlen(roleId)+3 + sizeof("{ deploymentId }") - 1;
    if(deploymentId == NULL) {
        goto end;
    }
    char* localVarToReplace_deploymentId = malloc(sizeOfPathParams_deploymentId);
    sprintf(localVarToReplace_deploymentId, "{%s}", "deploymentId");

    localVarPath = strReplace(localVarPath, localVarToReplace_deploymentId, deploymentId);

    // Path Params
    long sizeOfPathParams_userId = strlen(deploymentId)+3 + strlen(userId)+3 + strlen(roleId)+3 + sizeof("{ userId }") - 1;
    if(userId == NULL) {
        goto end;
    }
    char* localVarToReplace_userId = malloc(sizeOfPathParams_userId);
    sprintf(localVarToReplace_userId, "{%s}", "userId");

    localVarPath = strReplace(localVarPath, localVarToReplace_userId, userId);

    // Path Params
    long sizeOfPathParams_roleId = strlen(deploymentId)+3 + strlen(userId)+3 + strlen(roleId)+3 + sizeof("{ roleId }") - 1;
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
    //if (apiClient->response_code == 204) {
    //    printf("%s\n","Role removed.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Invalid request.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Domain administrator permissions required.");
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
    free(localVarToReplace_deploymentId);
    free(localVarToReplace_userId);
    free(localVarToReplace_roleId);

}

// Remove user role from project
//
// **Required role:** Domain administrator or project administrator.  Revokes a user role within a project. Available for Enterprise accounts only.
//
void
RolesAPI_v3RemoveUserRoleFromProject(apiClient_t *apiClient, char *projectId, char *userId, char *roleId)
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
    char *localVarPath = strdup("/v3/roles/projects/{projectId}/users/{userId}/roles/{roleId}");

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
    //if (apiClient->response_code == 204) {
    //    printf("%s\n","Role removed.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Invalid request.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Domain administrator or project administrator permissions required.");
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

