#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "AuthenticationAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096


// Log in
//
// Authenticate with username/password, an API token, or an existing bearer token.
//
login_result_t*
AuthenticationAPI_v3AuthLogin(apiClient_t *apiClient, login_body_t *login_body)
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
    char *localVarPath = strdup("/v3/auth/login");





    // Body Param
    cJSON *localVarSingleItemJSON_login_body = NULL;
    if (login_body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_login_body = login_body_convertToJSON(login_body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_login_body);
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
    //    printf("%s\n","Authentication succeeded.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Missing or invalid credentials in the request body.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Invalid username or password.");
    //}
    //nonprimitive not container
    login_result_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *AuthenticationAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = login_result_parseFromJSON(AuthenticationAPIlocalVarJSON);
        cJSON_Delete(AuthenticationAPIlocalVarJSON);
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
    if (localVarSingleItemJSON_login_body) {
        cJSON_Delete(localVarSingleItemJSON_login_body);
        localVarSingleItemJSON_login_body = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Log out
//
// Revoke the current session. For OpenID Connect users this also revokes the upstream session.
//
void
AuthenticationAPI_v3AuthLogout(apiClient_t *apiClient)
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
    char *localVarPath = strdup("/v3/auth/logout");




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
    //    printf("%s\n","Logout succeeded.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Permission denied.");
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

}

// Fetch SAML metadata
//
// Fetch SAML metadata XML from a trusted provider URL. The URL must be HTTPS and from an allowed domain.
//
char*
AuthenticationAPI_v3FetchAuthProviderMetadata(apiClient_t *apiClient, char *url)
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
    char *localVarPath = strdup("/v3/auth/providers/fetch-metadata");





    // query parameters
    char *keyQuery_url = NULL;
    char * valueQuery_url = NULL;
    keyValuePair_t *keyPairQuery_url = 0;
    if (url)
    {
        keyQuery_url = strdup("url");
        valueQuery_url = strdup((url));
        keyPairQuery_url = keyValuePair_create(keyQuery_url, valueQuery_url);
        list_addElement(localVarQueryParameters,keyPairQuery_url);
    }
    list_addElement(localVarHeaderType,"application/xml"); //produces
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
    //    printf("%s\n","SAML metadata document.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Missing or non-HTTPS URL parameter.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","The URL domain is not in the allowed list.");
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
    list_freeList(localVarQueryParameters);
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    if(keyQuery_url){
        free(keyQuery_url);
        keyQuery_url = NULL;
    }
    if(valueQuery_url){
        free(valueQuery_url);
        valueQuery_url = NULL;
    }
    if(keyPairQuery_url){
        keyValuePair_free(keyPairQuery_url);
        keyPairQuery_url = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Get provider authorization URL
//
// Redirect the caller to the authorization URL of the given authentication provider.
//
void
AuthenticationAPI_v3GetAuthProviderAuthorizationUrl(apiClient_t *apiClient, char *providerId, char *type, char *code, char *email, char *token)
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
    char *localVarPath = strdup("/v3/auth/providers/{providerId}/authorization_url");

    if(!providerId)
        goto end;


    // Path Params
    long sizeOfPathParams_providerId = strlen(providerId)+3 + sizeof("{ providerId }") - 1;
    if(providerId == NULL) {
        goto end;
    }
    char* localVarToReplace_providerId = malloc(sizeOfPathParams_providerId);
    sprintf(localVarToReplace_providerId, "{%s}", "providerId");

    localVarPath = strReplace(localVarPath, localVarToReplace_providerId, providerId);



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

    // query parameters
    char *keyQuery_code = NULL;
    char * valueQuery_code = NULL;
    keyValuePair_t *keyPairQuery_code = 0;
    if (code)
    {
        keyQuery_code = strdup("code");
        valueQuery_code = strdup((code));
        keyPairQuery_code = keyValuePair_create(keyQuery_code, valueQuery_code);
        list_addElement(localVarQueryParameters,keyPairQuery_code);
    }

    // query parameters
    char *keyQuery_email = NULL;
    char * valueQuery_email = NULL;
    keyValuePair_t *keyPairQuery_email = 0;
    if (email)
    {
        keyQuery_email = strdup("email");
        valueQuery_email = strdup((email));
        keyPairQuery_email = keyValuePair_create(keyQuery_email, valueQuery_email);
        list_addElement(localVarQueryParameters,keyPairQuery_email);
    }

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
    //if (apiClient->response_code == 302) {
    //    printf("%s\n","Success — redirects the caller to the identity provider&#39;s authorization URL.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","No provider with the given providerId.");
    //}
    //No return type
end:
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    list_freeList(localVarQueryParameters);
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_providerId);
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
    if(keyQuery_type){
        free(keyQuery_type);
        keyQuery_type = NULL;
    }
    if(keyPairQuery_type){
        keyValuePair_free(keyPairQuery_type);
        keyPairQuery_type = NULL;
    }
    if(keyQuery_code){
        free(keyQuery_code);
        keyQuery_code = NULL;
    }
    if(valueQuery_code){
        free(valueQuery_code);
        valueQuery_code = NULL;
    }
    if(keyPairQuery_code){
        keyValuePair_free(keyPairQuery_code);
        keyPairQuery_code = NULL;
    }
    if(keyQuery_code){
        free(keyQuery_code);
        keyQuery_code = NULL;
    }
    if(keyPairQuery_code){
        keyValuePair_free(keyPairQuery_code);
        keyPairQuery_code = NULL;
    }
    if(keyQuery_email){
        free(keyQuery_email);
        keyQuery_email = NULL;
    }
    if(valueQuery_email){
        free(valueQuery_email);
        valueQuery_email = NULL;
    }
    if(keyPairQuery_email){
        keyValuePair_free(keyPairQuery_email);
        keyPairQuery_email = NULL;
    }
    if(keyQuery_email){
        free(keyQuery_email);
        keyQuery_email = NULL;
    }
    if(keyPairQuery_email){
        keyValuePair_free(keyPairQuery_email);
        keyPairQuery_email = NULL;
    }
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
    if(keyQuery_token){
        free(keyQuery_token);
        keyQuery_token = NULL;
    }
    if(keyPairQuery_token){
        keyValuePair_free(keyPairQuery_token);
        keyPairQuery_token = NULL;
    }

}

// Authentication provider callback (GET)
//
// Handle the final authorization response from an SSO provider and redirect back to the client.
//
void
AuthenticationAPI_v3GetAuthProviderCallback(apiClient_t *apiClient, char *providerId, char *error, char *error_description)
{
    list_t    *localVarQueryParameters = list_createList();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = NULL;
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/v3/auth/providers/{providerId}/callback");

    if(!providerId)
        goto end;


    // Path Params
    long sizeOfPathParams_providerId = strlen(providerId)+3 + sizeof("{ providerId }") - 1;
    if(providerId == NULL) {
        goto end;
    }
    char* localVarToReplace_providerId = malloc(sizeOfPathParams_providerId);
    sprintf(localVarToReplace_providerId, "{%s}", "providerId");

    localVarPath = strReplace(localVarPath, localVarToReplace_providerId, providerId);



    // query parameters
    char *keyQuery_error = NULL;
    char * valueQuery_error = NULL;
    keyValuePair_t *keyPairQuery_error = 0;
    if (error)
    {
        keyQuery_error = strdup("error");
        valueQuery_error = strdup((error));
        keyPairQuery_error = keyValuePair_create(keyQuery_error, valueQuery_error);
        list_addElement(localVarQueryParameters,keyPairQuery_error);
    }

    // query parameters
    char *keyQuery_error_description = NULL;
    char * valueQuery_error_description = NULL;
    keyValuePair_t *keyPairQuery_error_description = 0;
    if (error_description)
    {
        keyQuery_error_description = strdup("error_description");
        valueQuery_error_description = strdup((error_description));
        keyPairQuery_error_description = keyValuePair_create(keyQuery_error_description, valueQuery_error_description);
        list_addElement(localVarQueryParameters,keyPairQuery_error_description);
    }
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
    //if (apiClient->response_code == 302) {
    //    printf("%s\n","Success — redirects the caller back to the application after handling the callback.");
    //}
    //No return type
end:
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    list_freeList(localVarQueryParameters);
    
    
    
    
    free(localVarPath);
    free(localVarToReplace_providerId);
    if(keyQuery_error){
        free(keyQuery_error);
        keyQuery_error = NULL;
    }
    if(valueQuery_error){
        free(valueQuery_error);
        valueQuery_error = NULL;
    }
    if(keyPairQuery_error){
        keyValuePair_free(keyPairQuery_error);
        keyPairQuery_error = NULL;
    }
    if(keyQuery_error){
        free(keyQuery_error);
        keyQuery_error = NULL;
    }
    if(keyPairQuery_error){
        keyValuePair_free(keyPairQuery_error);
        keyPairQuery_error = NULL;
    }
    if(keyQuery_error_description){
        free(keyQuery_error_description);
        keyQuery_error_description = NULL;
    }
    if(valueQuery_error_description){
        free(valueQuery_error_description);
        valueQuery_error_description = NULL;
    }
    if(keyPairQuery_error_description){
        keyValuePair_free(keyPairQuery_error_description);
        keyPairQuery_error_description = NULL;
    }
    if(keyQuery_error_description){
        free(keyQuery_error_description);
        keyQuery_error_description = NULL;
    }
    if(keyPairQuery_error_description){
        keyValuePair_free(keyPairQuery_error_description);
        keyPairQuery_error_description = NULL;
    }

}

// Get service provider metadata
//
// Return the SAML service provider metadata XML for the given authentication provider.
//
char*
AuthenticationAPI_v3GetAuthProviderSpMetadata(apiClient_t *apiClient, char *providerId)
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
    char *localVarPath = strdup("/v3/auth/providers/{providerId}/spmetadata");

    if(!providerId)
        goto end;


    // Path Params
    long sizeOfPathParams_providerId = strlen(providerId)+3 + sizeof("{ providerId }") - 1;
    if(providerId == NULL) {
        goto end;
    }
    char* localVarToReplace_providerId = malloc(sizeOfPathParams_providerId);
    sprintf(localVarToReplace_providerId, "{%s}", "providerId");

    localVarPath = strReplace(localVarPath, localVarToReplace_providerId, providerId);


    list_addElement(localVarHeaderType,"application/xml"); //produces
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
    //    printf("%s\n","Service provider metadata document.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Permission denied.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","The provider does not expose service provider metadata.");
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
    free(localVarToReplace_providerId);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// List authentication provider types
//
// Return schemas describing the supported authentication provider types.
//
auth_provider_types_list_response_t*
AuthenticationAPI_v3ListAuthProviderTypes(apiClient_t *apiClient, double *limit, double *offset)
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
    char *localVarPath = strdup("/v3/auth/providers/types");





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
    //    printf("%s\n","Paginated list of supported authentication provider types.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Invalid request.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Permission denied.");
    //}
    //nonprimitive not container
    auth_provider_types_list_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *AuthenticationAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = auth_provider_types_list_response_parseFromJSON(AuthenticationAPIlocalVarJSON);
        cJSON_Delete(AuthenticationAPIlocalVarJSON);
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

// List authentication providers
//
// Return all configured authentication providers for the requesting domain.
//
auth_providers_list_response_t*
AuthenticationAPI_v3ListAuthProviders(apiClient_t *apiClient, double *limit, double *offset)
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
    char *localVarPath = strdup("/v3/auth/providers");





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
    //    printf("%s\n","Paginated list of configured authentication providers.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Invalid request.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Permission denied.");
    //}
    //nonprimitive not container
    auth_providers_list_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *AuthenticationAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = auth_providers_list_response_parseFromJSON(AuthenticationAPIlocalVarJSON);
        cJSON_Delete(AuthenticationAPIlocalVarJSON);
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

// Authentication provider callback (POST)
//
// Handle the final authorization response from an SSO provider (POST binding) and redirect back to the client.
//
void
AuthenticationAPI_v3PostAuthProviderCallback(apiClient_t *apiClient, char *providerId)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = NULL;
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/v3/auth/providers/{providerId}/callback");

    if(!providerId)
        goto end;


    // Path Params
    long sizeOfPathParams_providerId = strlen(providerId)+3 + sizeof("{ providerId }") - 1;
    if(providerId == NULL) {
        goto end;
    }
    char* localVarToReplace_providerId = malloc(sizeOfPathParams_providerId);
    sprintf(localVarToReplace_providerId, "{%s}", "providerId");

    localVarPath = strReplace(localVarPath, localVarToReplace_providerId, providerId);


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
    //if (apiClient->response_code == 302) {
    //    printf("%s\n","Success — redirects the caller back to the application after handling the callback.");
    //}
    //No return type
end:
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    
    
    free(localVarPath);
    free(localVarToReplace_providerId);

}

