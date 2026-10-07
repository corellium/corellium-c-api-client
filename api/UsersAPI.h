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
#include "../model/invalid_credentials_error.h"
#include "../model/patch_user_body.h"
#include "../model/reset_link_info.h"
#include "../model/reset_password_body.h"
#include "../model/reset_unauthorized_response.h"
#include "../model/send_reset_link_body.h"
#include "../model/unauthorized_error.h"
#include "../model/update_own_profile_body.h"
#include "../model/user_created.h"
#include "../model/user_error_response.h"


// Agree to terms
//
// Records that you, the signed-in user, accept the current terms and conditions, and returns the time of agreement. The web interface calls this when it shows the terms; call it yourself if your domain requires agreement before using the platform.
//
agreed_ack_t*
UsersAPI_v3AgreeToTerms(apiClient_t *apiClient);


// Change password
//
// Changes a password when you know the current one. Needs no sign-in: send the user's ID in `user`, the current password in `oldPassword`, and the new one in `newPassword`. Returns 204 on success and 403 if the old password is wrong. If you have forgotten the password, use the reset flow instead (`v3SendResetLink`).
//
void
UsersAPI_v3ChangePassword(apiClient_t *apiClient, change_password_body_t *change_password_body);


// Create a user
//
// **Required role:** Domain administrator.  Creates a user account in your domain directly, with a username and password you choose, without sending an invitation. Requires a domain administrator. Returns 201 with the new user's ID. To let people set their own password instead, invite them with `POST /v3/invites`. A new user has no project access until you grant it with the Roles endpoints or add them to a team.
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
// Step 2 (optional) of resetting a forgotten password: checks the token from a reset email and returns the account it belongs to (user ID, username and domain), so a reset page can show whose password is being changed. Needs no sign-in. Returns 400 or 401 if the token is missing, invalid or expired.
//
reset_link_info_t*
UsersAPI_v3GetResetLinkInfo(apiClient_t *apiClient, get_reset_link_info_body_t *get_reset_link_info_body);


// Update a user
//
// Changes a user's account details, such as their name, display label, email or password. Send only the fields you want to change. Only cluster administrators may set or change `clusterAdministrator`, which gives a user control over the whole cluster.
//
void
UsersAPI_v3PatchUser(apiClient_t *apiClient, char *userId, patch_user_body_t *patch_user_body);


// Reset password
//
// Step 3 of resetting a forgotten password. Send the `token` from the reset email, the `newPassword`, and, if the account has two-factor sign-in turned on, a current six-digit code in `totpToken`. Returns 204 when the password has been changed; sign in with the new password.  **Reset flow:** 1. `v3SendResetLink` with the account's email address. 2. Optionally `v3GetResetLinkInfo` with the token from the email, to show which account is being reset. 3. `v3ResetPassword` (this call).  Returns 401 if the token is invalid or expired, or the two-factor code is wrong.
//
void
UsersAPI_v3ResetPassword(apiClient_t *apiClient, reset_password_body_t *reset_password_body);


// Send a password reset link
//
// Step 1 of resetting a forgotten password: emails a password reset link to the given address, if it belongs to an account in the domain you are calling. Needs no sign-in. Always returns 204, whether or not the address matched an account, so the response does not reveal which emails are registered. The link contains the token used by `v3ResetPassword`.
//
void
UsersAPI_v3SendResetLink(apiClient_t *apiClient, send_reset_link_body_t *send_reset_link_body);


// Update your profile
//
// Updates the caller's own display name. Needs no administrator role. Users created through an authentication provider cannot change their label, because the provider owns it.
//
void
UsersAPI_v3UpdateOwnProfile(apiClient_t *apiClient, update_own_profile_body_t *update_own_profile_body);


