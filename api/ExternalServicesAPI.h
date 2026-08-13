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
// Proxies the request to the external service identified by serviceName.
//
void
ExternalServicesAPI_deleteExternalService(apiClient_t *apiClient, char *apiVersion, char *serviceName, char *path);


// Proxy a GET request to an external service
//
// Proxies the request to the external service identified by serviceName.
//
void
ExternalServicesAPI_getExternalService(apiClient_t *apiClient, char *apiVersion, char *serviceName, char *path);


// Proxy a PATCH request to an external service
//
// Proxies the request to the external service identified by serviceName.
//
void
ExternalServicesAPI_patchExternalService(apiClient_t *apiClient, char *apiVersion, char *serviceName, char *path);


// Proxy a POST request to an external service
//
// Proxies the request to the external service identified by serviceName.
//
void
ExternalServicesAPI_postExternalService(apiClient_t *apiClient, char *apiVersion, char *serviceName, char *path);


// Proxy a PUT request to an external service
//
// Proxies the request to the external service identified by serviceName.
//
void
ExternalServicesAPI_putExternalService(apiClient_t *apiClient, char *apiVersion, char *serviceName, char *path);


