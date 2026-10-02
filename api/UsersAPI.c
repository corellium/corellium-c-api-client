#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "UsersAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096


// Agree to terms
//
// Records that you, the signed-in user, accept the current terms and conditions, and returns the time of agreement. The web interface calls this when it shows the terms; call it yourself if your domain requires agreement before using the platform.
//
agreed_ack_t*
UsersAPI_v3AgreeToTerms(apiClient_t *apiClient)
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
    char *localVarPath = strdup("/v3/users/agree");




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
    //    printf("%s\n","Terms accepted.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","The session token is missing, invalid, or expired.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Signed in, but not allowed to do this: you lack the required role, have no access to the project, or your license does not include the feature.");
    //}
    //nonprimitive not container
    agreed_ack_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *UsersAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = agreed_ack_parseFromJSON(UsersAPIlocalVarJSON);
        cJSON_Delete(UsersAPIlocalVarJSON);
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

// Change password
//
// Changes a password when you know the current one. Needs no sign-in: send the user's ID in `user`, the current password in `oldPassword`, and the new one in `newPassword`. Returns 204 on success and 403 if the old password is wrong. If you have forgotten the password, use the reset flow instead (`v3SendResetLink`).
//
void
UsersAPI_v3ChangePassword(apiClient_t *apiClient, change_password_body_t *change_password_body)
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
    char *localVarPath = strdup("/v3/users/change-password");





    // Body Param
    cJSON *localVarSingleItemJSON_change_password_body = NULL;
    if (change_password_body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_change_password_body = change_password_body_convertToJSON(change_password_body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_change_password_body);
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
    //    printf("%s\n","Password changed.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","The request was invalid, for example a missing or malformed field. The body says which field; fix it before retrying.");
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
    if (localVarSingleItemJSON_change_password_body) {
        cJSON_Delete(localVarSingleItemJSON_change_password_body);
        localVarSingleItemJSON_change_password_body = NULL;
    }
    free(localVarBodyParameters);

}

// Create a user
//
// **Required role:** Domain administrator.  Creates a user account in your domain directly, with a username and password you choose, without sending an invitation. Requires a domain administrator. Returns 201 with the new user's ID. To let people set their own password instead, invite them with `POST /v3/invites`. A new user has no project access until you grant it with the Roles endpoints or add them to a team.
//
user_created_t*
UsersAPI_v3CreateUser(apiClient_t *apiClient, create_user_body_t *create_user_body)
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
    char *localVarPath = strdup("/v3/users");





    // Body Param
    cJSON *localVarSingleItemJSON_create_user_body = NULL;
    if (create_user_body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_create_user_body = create_user_body_convertToJSON(create_user_body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_create_user_body);
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
    //if (apiClient->response_code == 201) {
    //    printf("%s\n","User created.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","The request was invalid, for example a missing or malformed field. The body says which field; fix it before retrying.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Domain administrator permissions required. Signed in, but not allowed to do this: you lack the required role, have no access to the project, or your license does not include the feature.");
    //}
    //nonprimitive not container
    user_created_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *UsersAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = user_created_parseFromJSON(UsersAPIlocalVarJSON);
        cJSON_Delete(UsersAPIlocalVarJSON);
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
    if (localVarSingleItemJSON_create_user_body) {
        cJSON_Delete(localVarSingleItemJSON_create_user_body);
        localVarSingleItemJSON_create_user_body = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Delete a user
//
// **Required role:** Domain administrator.  Deletes the user identified by the given userId.  Deletes are idempotent: a `userId` that does not exist, including one that was already deleted, is a successful no-op that still returns 204, and repeated calls return 204 as well. A 404 means the request path did not match a delete route, not that the target was missing.
//
void
UsersAPI_v3DeleteUser(apiClient_t *apiClient, char *userId)
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
    char *localVarPath = strdup("/v3/users/{userId}");

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
    //if (apiClient->response_code == 204) {
    //    printf("%s\n","User deleted.");
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
    free(localVarToReplace_userId);

}

// Get reset link info
//
// Step 2 (optional) of resetting a forgotten password: checks the token from a reset email and returns the account it belongs to (user ID, username and domain), so a reset page can show whose password is being changed. Needs no sign-in. Returns 400 or 401 if the token is missing, invalid or expired.
//
reset_link_info_t*
UsersAPI_v3GetResetLinkInfo(apiClient_t *apiClient, get_reset_link_info_body_t *get_reset_link_info_body)
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
    char *localVarPath = strdup("/v3/users/reset-link-info");





    // Body Param
    cJSON *localVarSingleItemJSON_get_reset_link_info_body = NULL;
    if (get_reset_link_info_body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_get_reset_link_info_body = get_reset_link_info_body_convertToJSON(get_reset_link_info_body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_get_reset_link_info_body);
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
    //    printf("%s\n","Reset link info.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Token was not supplied, or is not a password reset token.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","The reset token failed verification: malformed, tampered with, or expired.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Signed in, but not allowed to do this: you lack the required role, have no access to the project, or your license does not include the feature.");
    //}
    //nonprimitive not container
    reset_link_info_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *UsersAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = reset_link_info_parseFromJSON(UsersAPIlocalVarJSON);
        cJSON_Delete(UsersAPIlocalVarJSON);
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
    if (localVarSingleItemJSON_get_reset_link_info_body) {
        cJSON_Delete(localVarSingleItemJSON_get_reset_link_info_body);
        localVarSingleItemJSON_get_reset_link_info_body = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Update a user
//
// Changes a user's account details, such as their name, display label, email or password. Send only the fields you want to change. Only cluster administrators may set or change `clusterAdministrator`, which gives a user control over the whole cluster.
//
void
UsersAPI_v3PatchUser(apiClient_t *apiClient, char *userId, patch_user_body_t *patch_user_body)
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
    char *localVarPath = strdup("/v3/users/{userId}");

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
    cJSON *localVarSingleItemJSON_patch_user_body = NULL;
    if (patch_user_body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_patch_user_body = patch_user_body_convertToJSON(patch_user_body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_patch_user_body);
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
    //    printf("%s\n","User updated.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","The request was invalid, for example a missing or malformed field. The body says which field; fix it before retrying.");
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
    free(localVarToReplace_userId);
    if (localVarSingleItemJSON_patch_user_body) {
        cJSON_Delete(localVarSingleItemJSON_patch_user_body);
        localVarSingleItemJSON_patch_user_body = NULL;
    }
    free(localVarBodyParameters);

}

// Reset password
//
// Step 3 of resetting a forgotten password. Send the `token` from the reset email, the `newPassword`, and, if the account has two-factor sign-in turned on, a current six-digit code in `totpToken`. Returns 204 when the password has been changed; sign in with the new password.  **Reset flow:** 1. `v3SendResetLink` with the account's email address. 2. Optionally `v3GetResetLinkInfo` with the token from the email, to show which account is being reset. 3. `v3ResetPassword` (this call).  Returns 401 if the token is invalid or expired, or the two-factor code is wrong.
//
void
UsersAPI_v3ResetPassword(apiClient_t *apiClient, reset_password_body_t *reset_password_body)
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
    char *localVarPath = strdup("/v3/users/reset-password");





    // Body Param
    cJSON *localVarSingleItemJSON_reset_password_body = NULL;
    if (reset_password_body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_reset_password_body = reset_password_body_convertToJSON(reset_password_body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_reset_password_body);
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
    //    printf("%s\n","Password reset.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Password reset token must be supplied.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","The one-time code is incorrect, or the reset token failed verification.");
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
    if (localVarSingleItemJSON_reset_password_body) {
        cJSON_Delete(localVarSingleItemJSON_reset_password_body);
        localVarSingleItemJSON_reset_password_body = NULL;
    }
    free(localVarBodyParameters);

}

// Send a password reset link
//
// Step 1 of resetting a forgotten password: emails a password reset link to the given address, if it belongs to an account in the domain you are calling. Needs no sign-in. Always returns 204, whether or not the address matched an account, so the response does not reveal which emails are registered. The link contains the token used by `v3ResetPassword`.
//
void
UsersAPI_v3SendResetLink(apiClient_t *apiClient, send_reset_link_body_t *send_reset_link_body)
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
    char *localVarPath = strdup("/v3/users/send-reset-link");





    // Body Param
    cJSON *localVarSingleItemJSON_send_reset_link_body = NULL;
    if (send_reset_link_body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_send_reset_link_body = send_reset_link_body_convertToJSON(send_reset_link_body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_send_reset_link_body);
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
    //    printf("%s\n","Reset link sent (if the email matched an account).");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","The request body failed validation.");
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
    if (localVarSingleItemJSON_send_reset_link_body) {
        cJSON_Delete(localVarSingleItemJSON_send_reset_link_body);
        localVarSingleItemJSON_send_reset_link_body = NULL;
    }
    free(localVarBodyParameters);

}

