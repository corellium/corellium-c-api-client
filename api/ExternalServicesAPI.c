#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "ExternalServicesAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096


// Proxy a DELETE request to an external service
//
// Forwards this request to an optional external service connected to the platform (named by `serviceName`, for example `apps`), passing along the rest of the path, and returns that service's response unchanged. What each path does is defined by the external service, not by this API. Returns 503 if the service is not available on this deployment or cannot be reached.
//
void
ExternalServicesAPI_deleteExternalService(apiClient_t *apiClient, char *apiVersion, char *serviceName, char *path)
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
    char *localVarPath = strdup("/{apiVersion}/external-services/{serviceName}/{path}");

    if(!apiVersion)
        goto end;
    if(!serviceName)
        goto end;
    if(!path)
        goto end;


    // Path Params
    long sizeOfPathParams_apiVersion = strlen(apiVersion)+3 + strlen(serviceName)+3 + strlen(path)+3 + sizeof("{ apiVersion }") - 1;
    if(apiVersion == NULL) {
        goto end;
    }
    char* localVarToReplace_apiVersion = malloc(sizeOfPathParams_apiVersion);
    sprintf(localVarToReplace_apiVersion, "{%s}", "apiVersion");

    localVarPath = strReplace(localVarPath, localVarToReplace_apiVersion, apiVersion);

    // Path Params
    long sizeOfPathParams_serviceName = strlen(apiVersion)+3 + strlen(serviceName)+3 + strlen(path)+3 + sizeof("{ serviceName }") - 1;
    if(serviceName == NULL) {
        goto end;
    }
    char* localVarToReplace_serviceName = malloc(sizeOfPathParams_serviceName);
    sprintf(localVarToReplace_serviceName, "{%s}", "serviceName");

    localVarPath = strReplace(localVarPath, localVarToReplace_serviceName, serviceName);

    // Path Params
    long sizeOfPathParams_path = strlen(apiVersion)+3 + strlen(serviceName)+3 + strlen(path)+3 + sizeof("{ path }") - 1;
    if(path == NULL) {
        goto end;
    }
    char* localVarToReplace_path = malloc(sizeOfPathParams_path);
    sprintf(localVarToReplace_path, "{%s}", "path");

    localVarPath = strReplace(localVarPath, localVarToReplace_path, path);


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
    //    printf("%s\n","Response proxied from the external service.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Signed in, but not allowed to do this: you lack the required role, have no access to the project, or your license does not include the feature.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 503) {
    //    printf("%s\n","External service not found, cluster token not set, or the upstream service is unreachable.");
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
    free(localVarToReplace_apiVersion);
    free(localVarToReplace_serviceName);
    free(localVarToReplace_path);

}

// Proxy a GET request to an external service
//
// Forwards this request to an optional external service connected to the platform (named by `serviceName`, for example `apps`), passing along the rest of the path, and returns that service's response unchanged. What each path does is defined by the external service, not by this API. Returns 503 if the service is not available on this deployment or cannot be reached.
//
void
ExternalServicesAPI_getExternalService(apiClient_t *apiClient, char *apiVersion, char *serviceName, char *path)
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
    char *localVarPath = strdup("/{apiVersion}/external-services/{serviceName}/{path}");

    if(!apiVersion)
        goto end;
    if(!serviceName)
        goto end;
    if(!path)
        goto end;


    // Path Params
    long sizeOfPathParams_apiVersion = strlen(apiVersion)+3 + strlen(serviceName)+3 + strlen(path)+3 + sizeof("{ apiVersion }") - 1;
    if(apiVersion == NULL) {
        goto end;
    }
    char* localVarToReplace_apiVersion = malloc(sizeOfPathParams_apiVersion);
    sprintf(localVarToReplace_apiVersion, "{%s}", "apiVersion");

    localVarPath = strReplace(localVarPath, localVarToReplace_apiVersion, apiVersion);

    // Path Params
    long sizeOfPathParams_serviceName = strlen(apiVersion)+3 + strlen(serviceName)+3 + strlen(path)+3 + sizeof("{ serviceName }") - 1;
    if(serviceName == NULL) {
        goto end;
    }
    char* localVarToReplace_serviceName = malloc(sizeOfPathParams_serviceName);
    sprintf(localVarToReplace_serviceName, "{%s}", "serviceName");

    localVarPath = strReplace(localVarPath, localVarToReplace_serviceName, serviceName);

    // Path Params
    long sizeOfPathParams_path = strlen(apiVersion)+3 + strlen(serviceName)+3 + strlen(path)+3 + sizeof("{ path }") - 1;
    if(path == NULL) {
        goto end;
    }
    char* localVarToReplace_path = malloc(sizeOfPathParams_path);
    sprintf(localVarToReplace_path, "{%s}", "path");

    localVarPath = strReplace(localVarPath, localVarToReplace_path, path);


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
    //    printf("%s\n","Response proxied from the external service.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Signed in, but not allowed to do this: you lack the required role, have no access to the project, or your license does not include the feature.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 503) {
    //    printf("%s\n","External service not found, cluster token not set, or the upstream service is unreachable.");
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
    free(localVarToReplace_apiVersion);
    free(localVarToReplace_serviceName);
    free(localVarToReplace_path);

}

// Proxy a PATCH request to an external service
//
// Forwards this request to an optional external service connected to the platform (named by `serviceName`, for example `apps`), passing along the rest of the path, and returns that service's response unchanged. What each path does is defined by the external service, not by this API. Returns 503 if the service is not available on this deployment or cannot be reached.
//
void
ExternalServicesAPI_patchExternalService(apiClient_t *apiClient, char *apiVersion, char *serviceName, char *path)
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
    char *localVarPath = strdup("/{apiVersion}/external-services/{serviceName}/{path}");

    if(!apiVersion)
        goto end;
    if(!serviceName)
        goto end;
    if(!path)
        goto end;


    // Path Params
    long sizeOfPathParams_apiVersion = strlen(apiVersion)+3 + strlen(serviceName)+3 + strlen(path)+3 + sizeof("{ apiVersion }") - 1;
    if(apiVersion == NULL) {
        goto end;
    }
    char* localVarToReplace_apiVersion = malloc(sizeOfPathParams_apiVersion);
    sprintf(localVarToReplace_apiVersion, "{%s}", "apiVersion");

    localVarPath = strReplace(localVarPath, localVarToReplace_apiVersion, apiVersion);

    // Path Params
    long sizeOfPathParams_serviceName = strlen(apiVersion)+3 + strlen(serviceName)+3 + strlen(path)+3 + sizeof("{ serviceName }") - 1;
    if(serviceName == NULL) {
        goto end;
    }
    char* localVarToReplace_serviceName = malloc(sizeOfPathParams_serviceName);
    sprintf(localVarToReplace_serviceName, "{%s}", "serviceName");

    localVarPath = strReplace(localVarPath, localVarToReplace_serviceName, serviceName);

    // Path Params
    long sizeOfPathParams_path = strlen(apiVersion)+3 + strlen(serviceName)+3 + strlen(path)+3 + sizeof("{ path }") - 1;
    if(path == NULL) {
        goto end;
    }
    char* localVarToReplace_path = malloc(sizeOfPathParams_path);
    sprintf(localVarToReplace_path, "{%s}", "path");

    localVarPath = strReplace(localVarPath, localVarToReplace_path, path);


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
                    "PATCH");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","Response proxied from the external service.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Signed in, but not allowed to do this: you lack the required role, have no access to the project, or your license does not include the feature.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 503) {
    //    printf("%s\n","External service not found, cluster token not set, or the upstream service is unreachable.");
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
    free(localVarToReplace_apiVersion);
    free(localVarToReplace_serviceName);
    free(localVarToReplace_path);

}

// Proxy a POST request to an external service
//
// Forwards this request to an optional external service connected to the platform (named by `serviceName`, for example `apps`), passing along the rest of the path, and returns that service's response unchanged. What each path does is defined by the external service, not by this API. Returns 503 if the service is not available on this deployment or cannot be reached.
//
void
ExternalServicesAPI_postExternalService(apiClient_t *apiClient, char *apiVersion, char *serviceName, char *path)
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
    char *localVarPath = strdup("/{apiVersion}/external-services/{serviceName}/{path}");

    if(!apiVersion)
        goto end;
    if(!serviceName)
        goto end;
    if(!path)
        goto end;


    // Path Params
    long sizeOfPathParams_apiVersion = strlen(apiVersion)+3 + strlen(serviceName)+3 + strlen(path)+3 + sizeof("{ apiVersion }") - 1;
    if(apiVersion == NULL) {
        goto end;
    }
    char* localVarToReplace_apiVersion = malloc(sizeOfPathParams_apiVersion);
    sprintf(localVarToReplace_apiVersion, "{%s}", "apiVersion");

    localVarPath = strReplace(localVarPath, localVarToReplace_apiVersion, apiVersion);

    // Path Params
    long sizeOfPathParams_serviceName = strlen(apiVersion)+3 + strlen(serviceName)+3 + strlen(path)+3 + sizeof("{ serviceName }") - 1;
    if(serviceName == NULL) {
        goto end;
    }
    char* localVarToReplace_serviceName = malloc(sizeOfPathParams_serviceName);
    sprintf(localVarToReplace_serviceName, "{%s}", "serviceName");

    localVarPath = strReplace(localVarPath, localVarToReplace_serviceName, serviceName);

    // Path Params
    long sizeOfPathParams_path = strlen(apiVersion)+3 + strlen(serviceName)+3 + strlen(path)+3 + sizeof("{ path }") - 1;
    if(path == NULL) {
        goto end;
    }
    char* localVarToReplace_path = malloc(sizeOfPathParams_path);
    sprintf(localVarToReplace_path, "{%s}", "path");

    localVarPath = strReplace(localVarPath, localVarToReplace_path, path);


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
    //    printf("%s\n","Response proxied from the external service.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Signed in, but not allowed to do this: you lack the required role, have no access to the project, or your license does not include the feature.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 503) {
    //    printf("%s\n","External service not found, cluster token not set, or the upstream service is unreachable.");
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
    free(localVarToReplace_apiVersion);
    free(localVarToReplace_serviceName);
    free(localVarToReplace_path);

}

// Proxy a PUT request to an external service
//
// Forwards this request to an optional external service connected to the platform (named by `serviceName`, for example `apps`), passing along the rest of the path, and returns that service's response unchanged. What each path does is defined by the external service, not by this API. Returns 503 if the service is not available on this deployment or cannot be reached.
//
void
ExternalServicesAPI_putExternalService(apiClient_t *apiClient, char *apiVersion, char *serviceName, char *path)
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
    char *localVarPath = strdup("/{apiVersion}/external-services/{serviceName}/{path}");

    if(!apiVersion)
        goto end;
    if(!serviceName)
        goto end;
    if(!path)
        goto end;


    // Path Params
    long sizeOfPathParams_apiVersion = strlen(apiVersion)+3 + strlen(serviceName)+3 + strlen(path)+3 + sizeof("{ apiVersion }") - 1;
    if(apiVersion == NULL) {
        goto end;
    }
    char* localVarToReplace_apiVersion = malloc(sizeOfPathParams_apiVersion);
    sprintf(localVarToReplace_apiVersion, "{%s}", "apiVersion");

    localVarPath = strReplace(localVarPath, localVarToReplace_apiVersion, apiVersion);

    // Path Params
    long sizeOfPathParams_serviceName = strlen(apiVersion)+3 + strlen(serviceName)+3 + strlen(path)+3 + sizeof("{ serviceName }") - 1;
    if(serviceName == NULL) {
        goto end;
    }
    char* localVarToReplace_serviceName = malloc(sizeOfPathParams_serviceName);
    sprintf(localVarToReplace_serviceName, "{%s}", "serviceName");

    localVarPath = strReplace(localVarPath, localVarToReplace_serviceName, serviceName);

    // Path Params
    long sizeOfPathParams_path = strlen(apiVersion)+3 + strlen(serviceName)+3 + strlen(path)+3 + sizeof("{ path }") - 1;
    if(path == NULL) {
        goto end;
    }
    char* localVarToReplace_path = malloc(sizeOfPathParams_path);
    sprintf(localVarToReplace_path, "{%s}", "path");

    localVarPath = strReplace(localVarPath, localVarToReplace_path, path);


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
    //    printf("%s\n","Response proxied from the external service.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Signed in, but not allowed to do this: you lack the required role, have no access to the project, or your license does not include the feature.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 503) {
    //    printf("%s\n","External service not found, cluster token not set, or the upstream service is unreachable.");
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
    free(localVarToReplace_apiVersion);
    free(localVarToReplace_serviceName);
    free(localVarToReplace_path);

}

