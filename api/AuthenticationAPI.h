#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/api_error.h"
#include "../model/api_not_found_error.h"
#include "../model/api_token_result.h"
#include "../model/auth_provider_types_list_response.h"
#include "../model/auth_providers_list_response.h"
#include "../model/login_body.h"
#include "../model/login_result.h"
#include "../model/user_error_response.h"


// Log in
//
// Authenticate and receive a session token. Supply one of three credential types; when more than one is present they are resolved in this fixed order of precedence: (1) `username` + `password` (plus `totpToken` when two-factor is enabled); (2) `token` — an existing session token, renewed for a fresh one; (3) `apiToken` — a persistent API key created by the user (in the web UI or via `POST /v3/auth/apitoken`), not issued by login. The first credential type present wins and the rest are ignored. For example, sending both username/password and an apiToken authenticates via username/password. On success the response contains a newly-regenerated session token (JWT), its expiration, and the session itself — the authenticated user and their domain. The apiToken is never returned. Renewing a Webplayer token instead returns the Webplayer session `identifier` and no `user`.
//
login_result_t*
AuthenticationAPI_v3AuthLogin(apiClient_t *apiClient, login_body_t *login_body);


// Log out
//
// Revoke the current session. For OpenID Connect users this also revokes the upstream session.
//
void
AuthenticationAPI_v3AuthLogout(apiClient_t *apiClient);


// Delete API token
//
// Deletes the authenticated user's currently saved API token.  Deletes are idempotent: a request made when no API token is saved is a successful no-op that still returns 204, and repeated calls return 204 as well. A 404 means the request path did not match a delete route, not that the target was missing.
//
void
AuthenticationAPI_v3DeleteApiToken(apiClient_t *apiClient);


// Fetch SAML metadata
//
// Fetch SAML metadata XML from a trusted provider URL. The URL must be HTTPS and from an allowed domain.
//
char*
AuthenticationAPI_v3FetchAuthProviderMetadata(apiClient_t *apiClient, char *url);


// Generate API token
//
// Generate a new API token for the authenticated user. The token is returned once and replaces any previously issued token.
//
api_token_result_t*
AuthenticationAPI_v3GenerateApiToken(apiClient_t *apiClient);


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


