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
#include "../model/user_error_response.h"


// Disable TOTP for this user
//
// Turns two-factor sign-in off for your account. Send your `password` and a current six-digit code (`totpToken`) from your authenticator app. On success a confirmation email is sent, signing in no longer needs a code, and the response is a fresh login result with a new session token. Returns 401 if the password or code is wrong.
//
totp_status_response_t*
TOTPAPI_v3DisableTotp(apiClient_t *apiClient, totp_disable_body_t *totp_disable_body);


// Enable TOTP for this user
//
// Step 2 of turning on two-factor sign-in. Send the `secret` from `v3GenerateTotp`, the current six-digit code (`totpToken`) the authenticator app shows for it, and your account `password`. If the password is right and the code matches, two-factor sign-in is turned on and a confirmation email is sent.  From then on, signing in with a username and password also needs `totpToken` (see `v3AuthLogin`). The response is a fresh login result with a new session token; use it for later requests. Returns 401 if the password or code is wrong; generate a new code and retry.
//
totp_status_response_t*
TOTPAPI_v3EnableTotp(apiClient_t *apiClient, totp_enable_body_t *totp_enable_body);


// Generate a TOTP secret
//
// Step 1 of turning on two-factor sign-in (TOTP: six-digit codes from an authenticator app such as Google Authenticator, 1Password or Authy). Creates a new secret and returns it both as text (`secret`) and as a QR code image. Show the QR code to the user to scan with their authenticator app, or let them type the secret in.  Nothing is turned on yet, and the secret is not saved: two-factor sign-in starts only after step 2, `v3EnableTotp`, succeeds. Keep the `secret` value; step 2 needs it. Calling this again creates a different secret. Returns 403 if your deployment is not licensed for two-factor sign-in.
//
totp_generate_response_t*
TOTPAPI_v3GenerateTotp(apiClient_t *apiClient);


