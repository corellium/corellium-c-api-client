#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/any_type.h"
#include "../model/api_error_v1.h"
#include "../model/api_token.h"
#include "../model/object.h"
#include "../model/token_v1.h"


// Log In
//
// Authenticate with username/password or a persistent apiToken. On success returns a freshly-regenerated session token (JWT).
//
token_v1_t*
AuthenticationV1API_v1AuthLogin(apiClient_t *apiClient, object_t *body);


// Delete API token
//
// Delete the authenticated user's currently saved API token.
//
void
AuthenticationV1API_v1DeleteApiToken(apiClient_t *apiClient);


// Generate API token
//
// Generate a new API token for the authenticated user. The token is returned once and replaces any previously issued token.
//
api_token_t*
AuthenticationV1API_v1GenerateApiToken(apiClient_t *apiClient);


