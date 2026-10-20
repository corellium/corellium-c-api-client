#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "TeamsV1API.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096


// Add user to team
//
// This endpoint is available for Enterprise accounts only
//
void
TeamsV1API_v1AddUserToTeam(apiClient_t *apiClient, char *teamId, char *userId)
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
    char *localVarPath = strdup("/v1/teams/{teamId}/users/{userId}");

    if(!teamId)
        goto end;
    if(!userId)
        goto end;


    // Path Params
    long sizeOfPathParams_teamId = strlen(teamId)+3 + strlen(userId)+3 + sizeof("{ teamId }") - 1;
    if(teamId == NULL) {
        goto end;
    }
    char* localVarToReplace_teamId = malloc(sizeOfPathParams_teamId);
    sprintf(localVarToReplace_teamId, "{%s}", "teamId");

    localVarPath = strReplace(localVarPath, localVarToReplace_teamId, teamId);

    // Path Params
    long sizeOfPathParams_userId = strlen(teamId)+3 + strlen(userId)+3 + sizeof("{ userId }") - 1;
    if(userId == NULL) {
        goto end;
    }
    char* localVarToReplace_userId = malloc(sizeOfPathParams_userId);
    sprintf(localVarToReplace_userId, "{%s}", "userId");

    localVarPath = strReplace(localVarPath, localVarToReplace_userId, userId);


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
    //    printf("%s\n","Success");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Forbidden");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal Server Error");
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
    free(localVarToReplace_teamId);
    free(localVarToReplace_userId);

}

// Remove user from team
//
// This endpoint is available for Enterprise accounts only
//
void
TeamsV1API_v1RemoveUserFromTeam(apiClient_t *apiClient, char *teamId, char *userId)
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
    char *localVarPath = strdup("/v1/teams/{teamId}/users/{userId}");

    if(!teamId)
        goto end;
    if(!userId)
        goto end;


    // Path Params
    long sizeOfPathParams_teamId = strlen(teamId)+3 + strlen(userId)+3 + sizeof("{ teamId }") - 1;
    if(teamId == NULL) {
        goto end;
    }
    char* localVarToReplace_teamId = malloc(sizeOfPathParams_teamId);
    sprintf(localVarToReplace_teamId, "{%s}", "teamId");

    localVarPath = strReplace(localVarPath, localVarToReplace_teamId, teamId);

    // Path Params
    long sizeOfPathParams_userId = strlen(teamId)+3 + strlen(userId)+3 + sizeof("{ userId }") - 1;
    if(userId == NULL) {
        goto end;
    }
    char* localVarToReplace_userId = malloc(sizeOfPathParams_userId);
    sprintf(localVarToReplace_userId, "{%s}", "userId");

    localVarPath = strReplace(localVarPath, localVarToReplace_userId, userId);


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
    //    printf("%s\n","Success");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Forbidden");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal Server Error");
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
    free(localVarToReplace_teamId);
    free(localVarToReplace_userId);

}

// Update team
//
// This endpoint is available for Enterprise accounts only
//
void
TeamsV1API_v1TeamChange(apiClient_t *apiClient, char *teamId, create_team_t *create_team)
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
    char *localVarPath = strdup("/v1/teams/{teamId}");

    if(!teamId)
        goto end;


    // Path Params
    long sizeOfPathParams_teamId = strlen(teamId)+3 + sizeof("{ teamId }") - 1;
    if(teamId == NULL) {
        goto end;
    }
    char* localVarToReplace_teamId = malloc(sizeOfPathParams_teamId);
    sprintf(localVarToReplace_teamId, "{%s}", "teamId");

    localVarPath = strReplace(localVarPath, localVarToReplace_teamId, teamId);



    // Body Param
    cJSON *localVarSingleItemJSON_create_team = NULL;
    if (create_team != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_create_team = create_team_convertToJSON(create_team);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_create_team);
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
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Forbidden");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Not Found");
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
    free(localVarToReplace_teamId);
    if (localVarSingleItemJSON_create_team) {
        cJSON_Delete(localVarSingleItemJSON_create_team);
        localVarSingleItemJSON_create_team = NULL;
    }
    free(localVarBodyParameters);

}

// Create team
//
// This endpoint is available for Enterprise accounts only
//
team_create_t*
TeamsV1API_v1TeamCreate(apiClient_t *apiClient, create_team_t *create_team)
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
    char *localVarPath = strdup("/v1/teams");





    // Body Param
    cJSON *localVarSingleItemJSON_create_team = NULL;
    if (create_team != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_create_team = create_team_convertToJSON(create_team);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_create_team);
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
    //    printf("%s\n","User");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Forbidden");
    //}
    //nonprimitive not container
    team_create_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *TeamsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = team_create_parseFromJSON(TeamsV1APIlocalVarJSON);
        cJSON_Delete(TeamsV1APIlocalVarJSON);
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
    if (localVarSingleItemJSON_create_team) {
        cJSON_Delete(localVarSingleItemJSON_create_team);
        localVarSingleItemJSON_create_team = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Delete team
//
// This endpoint is available for Enterprise accounts only
//
void
TeamsV1API_v1TeamDelete(apiClient_t *apiClient, char *teamId)
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
    char *localVarPath = strdup("/v1/teams/{teamId}");

    if(!teamId)
        goto end;


    // Path Params
    long sizeOfPathParams_teamId = strlen(teamId)+3 + sizeof("{ teamId }") - 1;
    if(teamId == NULL) {
        goto end;
    }
    char* localVarToReplace_teamId = malloc(sizeOfPathParams_teamId);
    sprintf(localVarToReplace_teamId, "{%s}", "teamId");

    localVarPath = strReplace(localVarPath, localVarToReplace_teamId, teamId);


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
    //    printf("%s\n","Success");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Forbidden");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal Server Error");
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
    free(localVarToReplace_teamId);

}

// Get teams
//
// This endpoint is available for Enterprise accounts only
//
list_t*
TeamsV1API_v1Teams(apiClient_t *apiClient)
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
    char *localVarPath = strdup("/v1/teams");




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
    //    printf("%s\n","Teams");
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
        cJSON *TeamsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        if(!cJSON_IsArray(TeamsV1APIlocalVarJSON)) {
            return 0;//nonprimitive container
        }
        elementToReturn = list_createList();
        cJSON *VarJSON;
        cJSON_ArrayForEach(VarJSON, TeamsV1APIlocalVarJSON)
        {
            if(!cJSON_IsObject(VarJSON))
            {
               // return 0;
            }
            char *localVarJSONToChar = cJSON_Print(VarJSON);
            list_addElement(elementToReturn , localVarJSONToChar);
        }

        cJSON_Delete( TeamsV1APIlocalVarJSON);
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

