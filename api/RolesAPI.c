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
    //    printf("%s\n","The request was invalid, for example a missing or malformed field. The body says which field; fix it before retrying.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Domain administrator permissions required. Signed in, but not allowed to do this: you lack the required role, have no access to the project, or your license does not include the feature.");
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
// **Required role:** Domain administrator or project administrator.  Gives every member of a team a role on a project. Pass `all-users` as `teamId` to give the role to everyone in your domain. People added to the team later get the access automatically. Requires a domain administrator, or a project administrator of that project. Available for Enterprise accounts only.
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
    //    printf("%s\n","The request was invalid, for example a missing or malformed field. The body says which field; fix it before retrying.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Domain administrator or project administrator permissions required. Signed in, but not allowed to do this: you lack the required role, have no access to the project, or your license does not include the feature.");
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
    //    printf("%s\n","The request was invalid, for example a missing or malformed field. The body says which field; fix it before retrying.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Domain administrator permissions required. Signed in, but not allowed to do this: you lack the required role, have no access to the project, or your license does not include the feature.");
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
// **Required role:** Domain administrator or project administrator.  Gives a user a role on a project: `member` to use the project and its devices, or `admin` to also manage it. This is how a new user gets access to a project. Requires a domain administrator, or a project administrator of that project. Returns 404 if the project, user or role does not exist. Available for Enterprise accounts only.
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
    //    printf("%s\n","The request was invalid, for example a missing or malformed field. The body says which field; fix it before retrying.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Domain administrator or project administrator permissions required. Signed in, but not allowed to do this: you lack the required role, have no access to the project, or your license does not include the feature.");
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
    //    printf("%s\n","The request was invalid, for example a missing or malformed field. The body says which field; fix it before retrying.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Domain administrator or project administrator permissions required. Signed in, but not allowed to do this: you lack the required role, have no access to the project, or your license does not include the feature.");
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
// **Required role:** Domain administrator or project administrator.  Lists who has which role on which project in your domain, for both individual users and teams: each entry names a role and either a `user` or a `team`, plus the `project`. Use it to audit access. Requires a domain or project administrator. Available for Enterprise accounts only.
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
    //    printf("%s\n","The request was invalid, for example a missing or malformed field. The body says which field; fix it before retrying.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Domain administrator or project administrator permissions required. Signed in, but not allowed to do this: you lack the required role, have no access to the project, or your license does not include the feature.");
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
// **Required role:** Domain administrator.  Revokes a team role within a deployment. Available for Enterprise accounts only.  Revocation is idempotent: if the team does not currently hold that role in the deployment, the call is a no-op and still returns 204. Repeated calls therefore also return 204. A `deploymentId` or `teamId` that does not exist is also a successful no-op that returns 204.
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
    //    printf("%s\n","Role removed, or the team did not hold the role.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","The request was invalid, for example a missing or malformed field. The body says which field; fix it before retrying.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Domain administrator permissions required. Signed in, but not allowed to do this: you lack the required role, have no access to the project, or your license does not include the feature.");
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
// **Required role:** Domain administrator or project administrator.  Takes a role on a project away from a team, so its members lose the access they had through it. Requires a domain administrator, or a project administrator of that project. Available for Enterprise accounts only.  Revocation is idempotent: if the team does not currently hold that role in the project, the call is a no-op and still returns 204. Repeated calls therefore also return 204. A `projectId` or `teamId` that does not exist is also a successful no-op that returns 204. A project administrator acting on another project in their own domain receives 403. An unrecognized `roleId` returns 400.
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
    //    printf("%s\n","Role removed, or the team did not hold the role.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Unrecognized role.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Domain administrator or project administrator permissions required. Signed in, but not allowed to do this: you lack the required role, have no access to the project, or your license does not include the feature.");
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
// **Required role:** Domain administrator.  Revokes a user role within a deployment. Available for Enterprise accounts only.  Revocation is idempotent: if the user does not currently hold that role in the deployment, the call is a no-op and still returns 204. Repeated calls therefore also return 204. A `deploymentId` or `userId` that does not exist is also a successful no-op that returns 204.
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
    //    printf("%s\n","Role removed, or the user did not hold the role.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","The request was invalid, for example a missing or malformed field. The body says which field; fix it before retrying.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Domain administrator permissions required. Signed in, but not allowed to do this: you lack the required role, have no access to the project, or your license does not include the feature.");
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
// **Required role:** Domain administrator or project administrator.  Takes a role on a project away from a user, so they lose that access (unless they also have it through a team). Requires a domain administrator, or a project administrator of that project. Available for Enterprise accounts only.  Revocation is idempotent: if the user does not currently hold that role in the project, the call is a no-op and still returns 204. Repeated calls therefore also return 204. A `projectId` or `userId` that does not exist is also a successful no-op that returns 204. A project administrator acting on another project in their own domain receives 403. An unrecognized `roleId` returns 400.
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
    //    printf("%s\n","Role removed, or the user did not hold the role.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Unrecognized role.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Domain administrator or project administrator permissions required. Signed in, but not allowed to do this: you lack the required role, have no access to the project, or your license does not include the feature.");
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

