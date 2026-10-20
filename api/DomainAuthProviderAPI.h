#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/api_error_v1.h"
#include "../model/domain_auth_provider_request.h"
#include "../model/domain_auth_provider_response_v1.h"


// Create a new auth provider for a domain
//
domain_auth_provider_response_v1_t*
DomainAuthProviderAPI_v1CreateDomainAuthProvider(apiClient_t *apiClient, char *domainId, domain_auth_provider_request_t *domain_auth_provider_request);


// Delete an auth provider from a domain
//
void
DomainAuthProviderAPI_v1DeleteDomainAuthProvider(apiClient_t *apiClient, char *domainId, char *providerId);


// Return all configured auth providers for a domain (including globally configured providers)
//
list_t*
DomainAuthProviderAPI_v1GetDomainAuthProviders(apiClient_t *apiClient, char *domainId);


// Update an auth provider for a domain
//
domain_auth_provider_response_v1_t*
DomainAuthProviderAPI_v1UpdateDomainAuthProvider(apiClient_t *apiClient, char *domainId, char *providerId, domain_auth_provider_request_t *domain_auth_provider_request);


