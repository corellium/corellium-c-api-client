#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "TOTPAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096


// Disable TOTP for this user
//
// Turns two-factor sign-in off for your account. Send your `password` and a current six-digit code (`totpToken`) from your authenticator app. On success a confirmation email is sent, signing in no longer needs a code, and the response is a fresh login result with a new session token. Returns 401 if the password or code is wrong.
//
totp_status_response_t*
TOTPAPI_v3DisableTotp(apiClient_t *apiClient, totp_disable_body_t *totp_disable_body)
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
    char *localVarPath = strdup("/v3/totp/disable");





    // Body Param
    cJSON *localVarSingleItemJSON_totp_disable_body = NULL;
    if (totp_disable_body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_totp_disable_body = totp_disable_body_convertToJSON(totp_disable_body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_totp_disable_body);
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
    //    printf("%s\n","TOTP disabled.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","The request was invalid, for example a missing or malformed field. The body says which field; fix it before retrying.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Invalid login token, password, or TOTP token.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Multi-factor authentication is not licensed for this deployment.");
    //}
    //nonprimitive not container
    totp_status_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *TOTPAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = totp_status_response_parseFromJSON(TOTPAPIlocalVarJSON);
        cJSON_Delete(TOTPAPIlocalVarJSON);
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
    if (localVarSingleItemJSON_totp_disable_body) {
        cJSON_Delete(localVarSingleItemJSON_totp_disable_body);
        localVarSingleItemJSON_totp_disable_body = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Enable TOTP for this user
//
// Step 2 of turning on two-factor sign-in. Send the `secret` from `v3GenerateTotp`, the current six-digit code (`totpToken`) the authenticator app shows for it, and your account `password`. If the password is right and the code matches, two-factor sign-in is turned on and a confirmation email is sent.  From then on, signing in with a username and password also needs `totpToken` (see `v3AuthLogin`). The response is a fresh login result with a new session token; use it for later requests. Returns 401 if the password or code is wrong; generate a new code and retry.
//
totp_status_response_t*
TOTPAPI_v3EnableTotp(apiClient_t *apiClient, totp_enable_body_t *totp_enable_body)
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
    char *localVarPath = strdup("/v3/totp/enable");





    // Body Param
    cJSON *localVarSingleItemJSON_totp_enable_body = NULL;
    if (totp_enable_body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_totp_enable_body = totp_enable_body_convertToJSON(totp_enable_body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_totp_enable_body);
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
    //    printf("%s\n","TOTP enabled.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","The request was invalid, for example a missing or malformed field. The body says which field; fix it before retrying.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Invalid login token, password, or TOTP token.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Multi-factor authentication is not licensed for this deployment.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","User not found.");
    //}
    //nonprimitive not container
    totp_status_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *TOTPAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = totp_status_response_parseFromJSON(TOTPAPIlocalVarJSON);
        cJSON_Delete(TOTPAPIlocalVarJSON);
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
    if (localVarSingleItemJSON_totp_enable_body) {
        cJSON_Delete(localVarSingleItemJSON_totp_enable_body);
        localVarSingleItemJSON_totp_enable_body = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Generate a TOTP secret
//
// Step 1 of turning on two-factor sign-in (TOTP: six-digit codes from an authenticator app such as Google Authenticator, 1Password or Authy). Creates a new secret and returns it both as text (`secret`) and as a QR code image. Show the QR code to the user to scan with their authenticator app, or let them type the secret in.  Nothing is turned on yet, and the secret is not saved: two-factor sign-in starts only after step 2, `v3EnableTotp`, succeeds. Keep the `secret` value; step 2 needs it. Calling this again creates a different secret. Returns 403 if your deployment is not licensed for two-factor sign-in.
//
totp_generate_response_t*
TOTPAPI_v3GenerateTotp(apiClient_t *apiClient)
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
    char *localVarPath = strdup("/v3/totp/generate");




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
    //    printf("%s\n","Generated TOTP secret and QR code.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Invalid token format.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Invalid login token.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Multi-factor authentication is not licensed for this deployment.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","User not found.");
    //}
    //nonprimitive not container
    totp_generate_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *TOTPAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = totp_generate_response_parseFromJSON(TOTPAPIlocalVarJSON);
        cJSON_Delete(TOTPAPIlocalVarJSON);
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

