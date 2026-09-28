#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/agreed_ack.h"
#include "../model/api_error.h"
#include "../model/change_password_body.h"
#include "../model/create_user_body.h"
#include "../model/get_reset_link_info_body.h"
#include "../model/patch_user_body.h"
#include "../model/reset_link_info.h"
#include "../model/reset_password_body.h"
#include "../model/reset_unauthorized_response.h"
#include "../model/send_reset_link_body.h"
#include "../model/unauthorized_error.h"
#include "../model/user_created.h"
#include "../model/user_error_response.h"


// Agree to terms
//
// Consent to the current terms and conditions.
//
agreed_ack_t*
UsersAPI_v3AgreeToTerms(apiClient_t *apiClient);


// Change password
//
// Change a password, authenticated solely by the old password.
//
void
UsersAPI_v3ChangePassword(apiClient_t *apiClient, change_password_body_t *change_password_body);


// Create a user
//
// **Required role:** Domain administrator.  Creates a new user in the caller's domain.
//
user_created_t*
UsersAPI_v3CreateUser(apiClient_t *apiClient, create_user_body_t *create_user_body);


// Delete a user
//
// **Required role:** Domain administrator.  Deletes the user identified by the given userId.  Deletes are idempotent: a `userId` that does not exist, including one that was already deleted, is a successful no-op that still returns 204, and repeated calls return 204 as well. A 404 means the request path did not match a delete route, not that the target was missing.
//
void
UsersAPI_v3DeleteUser(apiClient_t *apiClient, char *userId);


// Get reset link info
//
// Return account info associated with a password reset token.
//
reset_link_info_t*
UsersAPI_v3GetResetLinkInfo(apiClient_t *apiClient, get_reset_link_info_body_t *get_reset_link_info_body);


// Update a user
//
// Updates a user. Only cluster administrators may set the clusterAdministrator flag.
//
void
UsersAPI_v3PatchUser(apiClient_t *apiClient, char *userId, patch_user_body_t *patch_user_body);


// Reset password
//
// Reset a password using a reset token.
//
void
UsersAPI_v3ResetPassword(apiClient_t *apiClient, reset_password_body_t *reset_password_body);


// Send a password reset link
//
// Sends a password reset link to the specified user.
//
void
UsersAPI_v3SendResetLink(apiClient_t *apiClient, send_reset_link_body_t *send_reset_link_body);


