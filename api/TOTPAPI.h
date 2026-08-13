#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/api_error.h"
#include "../model/api_not_found_error.h"
#include "../model/totp_disable_body.h"
#include "../model/totp_enable_body.h"
#include "../model/totp_generate_response.h"
#include "../model/totp_status_response.h"
#include "../model/user_error.h"


// Disable TOTP for this user
//
// Disables multi-factor authentication for the user after validating their password and current TOTP token, returning a refreshed login result.
//
totp_status_response_t*
TOTPAPI_v3DisableTotp(apiClient_t *apiClient, totp_disable_body_t *totp_disable_body);


// Enable TOTP for this user
//
// Confirms a previously generated TOTP secret and enables multi-factor authentication for the user, returning a refreshed login result.
//
totp_status_response_t*
TOTPAPI_v3EnableTotp(apiClient_t *apiClient, totp_enable_body_t *totp_enable_body);


// Generate a TOTP secret
//
// Generates a new TOTP secret for the user and returns it along with a QR code that can be scanned by an authenticator app.
//
totp_generate_response_t*
TOTPAPI_v3GenerateTotp(apiClient_t *apiClient);


