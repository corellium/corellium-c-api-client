#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/api_error.h"
#include "../model/create_domain_auth_provider_body.h"
#include "../model/create_domain_auth_provider_response.h"
#include "../model/domain_auth_provider_response.h"
#include "../model/domain_auth_providers_list.h"
#include "../model/patch_domain_auth_provider_body.h"
#include "../model/user_error_response.h"


// Create a new auth provider for a domain
//
// **Required role:** Domain administrator.  Create a new auth provider for a domain.
//
create_domain_auth_provider_response_t*
DomainAuthProvidersAPI_v3CreateDomainAuthProvider(apiClient_t *apiClient, char *domainId, create_domain_auth_provider_body_t *create_domain_auth_provider_body);


// Delete an auth provider from a domain
//
// **Required role:** Domain administrator.  Delete an auth provider from a domain.  Deletes are idempotent: a `providerId` that is not attached to the domain, or an unknown `domainId`, is a successful no-op that still returns 204, and repeated calls return 204 as well. A 404 means the request path did not match a delete route, not that the target was missing. The underlying provider record is only removed when no other domain still references it, and default providers are never removed.
//
void
DomainAuthProvidersAPI_v3DeleteDomainAuthProvider(apiClient_t *apiClient, char *domainId, char *providerId);


// Return all configured auth providers for a domain (including globally configured providers)
//
// **Required role:** Domain administrator.  Return all configured auth providers for a domain (including globally configured providers).
//
domain_auth_providers_list_t*
DomainAuthProvidersAPI_v3ListDomainAuthProviders(apiClient_t *apiClient, char *domainId, double *limit, double *offset);


// Partially update an auth provider for a domain
//
// **Required role:** Domain administrator.  Partially update an auth provider for a domain.
//
domain_auth_provider_response_t*
DomainAuthProvidersAPI_v3PatchDomainAuthProvider(apiClient_t *apiClient, char *domainId, char *providerId, patch_domain_auth_provider_body_t *patch_domain_auth_provider_body);


// Update an auth provider for a domain
//
// **Required role:** Domain administrator.  Update an auth provider for a domain.
//
domain_auth_provider_response_t*
DomainAuthProvidersAPI_v3UpdateDomainAuthProvider(apiClient_t *apiClient, char *domainId, char *providerId, create_domain_auth_provider_body_t *create_domain_auth_provider_body);


