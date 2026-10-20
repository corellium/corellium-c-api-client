#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "UsersV1API.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096


// Change User Password
//
// Authenticated solely by the old-password.
//
void
UsersV1API_v1ChangePasswordUsers(apiClient_t *apiClient, password_change_body_t *password_change_body)
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
    char *localVarPath = strdup("/v1/users/change-password");





    // Body Param
    cJSON *localVarSingleItemJSON_password_change_body = NULL;
    if (password_change_body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_password_change_body = password_change_body_convertToJSON(password_change_body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_password_change_body);
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
    //    printf("%s\n","Accepted");
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
    if (localVarSingleItemJSON_password_change_body) {
        cJSON_Delete(localVarSingleItemJSON_password_change_body);
        localVarSingleItemJSON_password_change_body = NULL;
    }
    free(localVarBodyParameters);

}

// Create User
//
user_create_return_t*
UsersV1API_v1CreateUser(apiClient_t *apiClient, user_create_t *user_create)
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
    char *localVarPath = strdup("/v1/users");





    // Body Param
    cJSON *localVarSingleItemJSON_user_create = NULL;
    if (user_create != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_user_create = user_create_convertToJSON(user_create);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_user_create);
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
    user_create_return_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *UsersV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = user_create_return_parseFromJSON(UsersV1APIlocalVarJSON);
        cJSON_Delete(UsersV1APIlocalVarJSON);
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
    if (localVarSingleItemJSON_user_create) {
        cJSON_Delete(localVarSingleItemJSON_user_create);
        localVarSingleItemJSON_user_create = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Delete User
//
void
UsersV1API_v1DeleteUser(apiClient_t *apiClient, char *userId)
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
    char *localVarPath = strdup("/v1/users/{userId}");

    if(!userId)
        goto end;


    // Path Params
    long sizeOfPathParams_userId = strlen(userId)+3 + sizeof("{ userId }") - 1;
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
    //if (apiClient->response_code == 200) {
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
    free(localVarToReplace_userId);

}

// Send Password Reset Link Info
//
reset_link_info_return_t*
UsersV1API_v1GetResetLinkInfo(apiClient_t *apiClient, char *token)
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
    char *localVarPath = strdup("/v1/users/reset-link-info");





    // query parameters
    char *keyQuery_token = NULL;
    char * valueQuery_token = NULL;
    keyValuePair_t *keyPairQuery_token = 0;
    if (token)
    {
        keyQuery_token = strdup("token");
        valueQuery_token = strdup((token));
        keyPairQuery_token = keyValuePair_create(keyQuery_token, valueQuery_token);
        list_addElement(localVarQueryParameters,keyPairQuery_token);
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
    //    printf("%s\n","Reset Link Info");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Forbidden");
    //}
    //nonprimitive not container
    reset_link_info_return_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *UsersV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = reset_link_info_return_parseFromJSON(UsersV1APIlocalVarJSON);
        cJSON_Delete(UsersV1APIlocalVarJSON);
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
    if(keyQuery_token){
        free(keyQuery_token);
        keyQuery_token = NULL;
    }
    if(valueQuery_token){
        free(valueQuery_token);
        valueQuery_token = NULL;
    }
    if(keyPairQuery_token){
        keyValuePair_free(keyPairQuery_token);
        keyPairQuery_token = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Reset User Password
//
void
UsersV1API_v1ResetUserPassword(apiClient_t *apiClient, password_reset_body_t *password_reset_body)
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
    char *localVarPath = strdup("/v1/users/reset-password");





    // Body Param
    cJSON *localVarSingleItemJSON_password_reset_body = NULL;
    if (password_reset_body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_password_reset_body = password_reset_body_convertToJSON(password_reset_body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_password_reset_body);
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
    //    printf("%s\n","Accepted");
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
    if (localVarSingleItemJSON_password_reset_body) {
        cJSON_Delete(localVarSingleItemJSON_password_reset_body);
        localVarSingleItemJSON_password_reset_body = NULL;
    }
    free(localVarBodyParameters);

}

// Send Password Reset Link
//
void
UsersV1API_v1SendUserResetLink(apiClient_t *apiClient, reset_link_body_t *reset_link_body)
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
    char *localVarPath = strdup("/v1/users/send-reset-link");





    // Body Param
    cJSON *localVarSingleItemJSON_reset_link_body = NULL;
    if (reset_link_body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_reset_link_body = reset_link_body_convertToJSON(reset_link_body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_reset_link_body);
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
    //    printf("%s\n","Accepted");
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
    if (localVarSingleItemJSON_reset_link_body) {
        cJSON_Delete(localVarSingleItemJSON_reset_link_body);
        localVarSingleItemJSON_reset_link_body = NULL;
    }
    free(localVarBodyParameters);

}

// Update User
//
// Update a user. Fields such as `name`, `label`, `password`, and `clusterAdministrator` can be updated.  Only users with the Cluster Administrator role can set or modify the `clusterAdministrator` flag.
//
void
UsersV1API_v1UpdateUser(apiClient_t *apiClient, char *userId, user_update_t *user_update)
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
    char *localVarPath = strdup("/v1/users/{userId}");

    if(!userId)
        goto end;


    // Path Params
    long sizeOfPathParams_userId = strlen(userId)+3 + sizeof("{ userId }") - 1;
    if(userId == NULL) {
        goto end;
    }
    char* localVarToReplace_userId = malloc(sizeOfPathParams_userId);
    sprintf(localVarToReplace_userId, "{%s}", "userId");

    localVarPath = strReplace(localVarPath, localVarToReplace_userId, userId);



    // Body Param
    cJSON *localVarSingleItemJSON_user_update = NULL;
    if (user_update != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_user_update = user_update_convertToJSON(user_update);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_user_update);
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
    free(localVarToReplace_userId);
    if (localVarSingleItemJSON_user_update) {
        cJSON_Delete(localVarSingleItemJSON_user_update);
        localVarSingleItemJSON_user_update = NULL;
    }
    free(localVarBodyParameters);

}

// Consent to the current terms and conditions
//
agreed_ack_v1_t*
UsersV1API_v1UserAgreeTerms(apiClient_t *apiClient)
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
    char *localVarPath = strdup("/v1/users/agree");




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
    //    printf("%s\n","application/json");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Forbidden");
    //}
    //nonprimitive not container
    agreed_ack_v1_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *UsersV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = agreed_ack_v1_parseFromJSON(UsersV1APIlocalVarJSON);
        cJSON_Delete(UsersV1APIlocalVarJSON);
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

// Log In
//
token_v1_t*
UsersV1API_v1UsersLogin(apiClient_t *apiClient, credentials_t *credentials)
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
    char *localVarPath = strdup("/v1/users/login");





    // Body Param
    cJSON *localVarSingleItemJSON_credentials = NULL;
    if (credentials != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_credentials = credentials_convertToJSON(credentials);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_credentials);
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
    //    printf("%s\n","User Authorization");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Forbidden");
    //}
    //nonprimitive not container
    token_v1_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *UsersV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = token_v1_parseFromJSON(UsersV1APIlocalVarJSON);
        cJSON_Delete(UsersV1APIlocalVarJSON);
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
    if (localVarSingleItemJSON_credentials) {
        cJSON_Delete(localVarSingleItemJSON_credentials);
        localVarSingleItemJSON_credentials = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

