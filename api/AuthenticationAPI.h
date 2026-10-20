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
// **Start here.** Almost every other call needs you to prove who you are by sending a token in the `Authorization` header: `Authorization: Bearer <token>`. There are two kinds of token:  - **API token (best for scripts and automation).** A long-lived key you create once, in the web interface or with `POST /v3/auth/apitoken`. It is shown only once, so store it safely. You can send it directly as the Bearer token on every request, or exchange it here for a session token by sending `apiToken`. - **Session token.** A short-lived token (a JWT) returned by this call. Send it as the Bearer token until `expiration`, then log in again or renew it by sending it back as `token`.  Supply one of three credential types; when more than one is present they are resolved in this fixed order of precedence: (1) `username` + `password` (plus `totpToken`, a six-digit code from your authenticator app, when two-factor sign-in is enabled); (2) `token`, an existing session token, renewed for a fresh one; (3) `apiToken`, a persistent API key created by the user, not issued by login. The first credential type present wins and the rest are ignored. For example, sending both username/password and an apiToken authenticates via username/password. On success the response contains a newly-regenerated session token, its `expiration` time, and the session itself: the authenticated user and their domain. The apiToken is never returned. Renewing a Webplayer token instead returns the Webplayer session `identifier` and no `user`.  A 403 means the credentials were wrong (or a required two-factor code was missing or wrong).
//
login_result_t*
AuthenticationAPI_v3AuthLogin(apiClient_t *apiClient, login_body_t *login_body);


// Log out
//
// Ends the current session: the session token you send becomes invalid, so later requests with it fail with 401. For OpenID Connect (single sign-on) users this also ends the session with the identity provider. API tokens are not affected; remove one with `v3DeleteApiToken`.
//
void
AuthenticationAPI_v3AuthLogout(apiClient_t *apiClient);


// Delete API token
//
// Deletes your API token, so it can no longer be used to sign in. Scripts using it will get 401 until you give them a new one from `v3GenerateApiToken`.  Deletes are idempotent: a request made when no API token is saved is a successful no-op that still returns 204, and repeated calls return 204 as well. A 404 means the request path did not match a delete route, not that the target was missing.
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
// Creates a new API token for you: a long-lived key for scripts, CI jobs and SDKs, so they do not need your password. The response contains the token; it is shown only this once and cannot be retrieved later, so store it somewhere safe (for example a secrets manager). Each user has one API token at a time: generating a new one replaces the old one, which stops working immediately. Use it as `Authorization: Bearer <apiToken>`, or exchange it for a session token with `v3AuthLogin`.
//
api_token_result_t*
AuthenticationAPI_v3GenerateApiToken(apiClient_t *apiClient);


// Get provider authorization URL
//
// Starts single sign-on with the given identity provider by redirecting the caller's browser there (302). Open this URL in a browser, not from a script: after the user signs in at the provider, the provider sends the browser back to the callback route, which finishes signing in.
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
// Lists the ways users can sign in to your domain, such as username and password or single sign-on (SSO) through an identity provider like Okta. Needs no sign-in, so a login page can call it to show the right buttons. To sign in with an SSO provider, send the user's browser to its `authorizationUrl`.
//
auth_providers_list_response_t*
AuthenticationAPI_v3ListAuthProviders(apiClient_t *apiClient, double *limit, double *offset);


// Authentication provider callback (POST)
//
// Handle the final authorization response from an SSO provider (POST binding) and redirect back to the client.
//
void
AuthenticationAPI_v3PostAuthProviderCallback(apiClient_t *apiClient, char *providerId);


