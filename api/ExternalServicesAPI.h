#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/api_error.h"


// Proxy a DELETE request to an external service
//
// Forwards this request to an optional external service connected to the platform (named by `serviceName`, for example `apps`), passing along the rest of the path, and returns that service's response unchanged. What each path does is defined by the external service, not by this API. Returns 503 if the service is not available on this deployment or cannot be reached.
//
void
ExternalServicesAPI_deleteExternalService(apiClient_t *apiClient, char *apiVersion, char *serviceName, char *path);


// Proxy a GET request to an external service
//
// Forwards this request to an optional external service connected to the platform (named by `serviceName`, for example `apps`), passing along the rest of the path, and returns that service's response unchanged. What each path does is defined by the external service, not by this API. Returns 503 if the service is not available on this deployment or cannot be reached.
//
void
ExternalServicesAPI_getExternalService(apiClient_t *apiClient, char *apiVersion, char *serviceName, char *path);


// Proxy a PATCH request to an external service
//
// Forwards this request to an optional external service connected to the platform (named by `serviceName`, for example `apps`), passing along the rest of the path, and returns that service's response unchanged. What each path does is defined by the external service, not by this API. Returns 503 if the service is not available on this deployment or cannot be reached.
//
void
ExternalServicesAPI_patchExternalService(apiClient_t *apiClient, char *apiVersion, char *serviceName, char *path);


// Proxy a POST request to an external service
//
// Forwards this request to an optional external service connected to the platform (named by `serviceName`, for example `apps`), passing along the rest of the path, and returns that service's response unchanged. What each path does is defined by the external service, not by this API. Returns 503 if the service is not available on this deployment or cannot be reached.
//
void
ExternalServicesAPI_postExternalService(apiClient_t *apiClient, char *apiVersion, char *serviceName, char *path);


// Proxy a PUT request to an external service
//
// Forwards this request to an optional external service connected to the platform (named by `serviceName`, for example `apps`), passing along the rest of the path, and returns that service's response unchanged. What each path does is defined by the external service, not by this API. Returns 503 if the service is not available on this deployment or cannot be reached.
//
void
ExternalServicesAPI_putExternalService(apiClient_t *apiClient, char *apiVersion, char *serviceName, char *path);


