#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/api_error.h"
#include "../model/api_not_found_error.h"
#include "../model/auth_provider_types_list_response.h"
#include "../model/auth_providers_list_response.h"
#include "../model/login_body.h"
#include "../model/login_result.h"
#include "../model/user_error.h"


// Log in
//
// Authenticate with username/password, an API token, or an existing bearer token.
//
login_result_t*
AuthenticationAPI_v3AuthLogin(apiClient_t *apiClient, login_body_t *login_body);


// Log out
//
// Revoke the current session. For OpenID Connect users this also revokes the upstream session.
//
void
AuthenticationAPI_v3AuthLogout(apiClient_t *apiClient);


// Fetch SAML metadata
//
// Fetch SAML metadata XML from a trusted provider URL. The URL must be HTTPS and from an allowed domain.
//
char*
AuthenticationAPI_v3FetchAuthProviderMetadata(apiClient_t *apiClient, char *url);


// Get provider authorization URL
//
// Redirect the caller to the authorization URL of the given authentication provider.
//
void
AuthenticationAPI_v3GetAuthProviderAuthorizationUrl(apiClient_t *apiClient, char *providerId, char *type, char *code, char *email, char *token);


// Authentication provider callback (GET)
//
// Handle the final authorization response from an SSO provider and redirect back to the client.
//
void
AuthenticationAPI_v3GetAuthProviderCallback(apiClient_t *apiClient, char *providerId, char *error, char *error_description);


// Get service provider metadata
//
// Return the SAML service provider metadata XML for the given authentication provider.
//
char*
AuthenticationAPI_v3GetAuthProviderSpMetadata(apiClient_t *apiClient, char *providerId);


// List authentication provider types
//
// **Required role:** Domain administrator.  Return schemas describing the supported authentication provider types.
//
auth_provider_types_list_response_t*
AuthenticationAPI_v3ListAuthProviderTypes(apiClient_t *apiClient, double *limit, double *offset);


// List authentication providers
//
// Return all configured authentication providers for the requesting domain.
//
auth_providers_list_response_t*
AuthenticationAPI_v3ListAuthProviders(apiClient_t *apiClient, double *limit, double *offset);


// Authentication provider callback (POST)
//
// Handle the final authorization response from an SSO provider (POST binding) and redirect back to the client.
//
void
AuthenticationAPI_v3PostAuthProviderCallback(apiClient_t *apiClient, char *providerId);


