#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/agreed_ack_v1.h"
#include "../model/api_error_v1.h"
#include "../model/credentials.h"
#include "../model/password_change_body.h"
#include "../model/password_reset_body.h"
#include "../model/reset_link_body.h"
#include "../model/reset_link_info_return.h"
#include "../model/token_v1.h"
#include "../model/user_create.h"
#include "../model/user_create_return.h"
#include "../model/user_update.h"


// Change User Password
//
// Authenticated solely by the old-password.
//
void
UsersV1API_v1ChangePasswordUsers(apiClient_t *apiClient, password_change_body_t *password_change_body);


// Create User
//
user_create_return_t*
UsersV1API_v1CreateUser(apiClient_t *apiClient, user_create_t *user_create);


// Delete User
//
void
UsersV1API_v1DeleteUser(apiClient_t *apiClient, char *userId);


// Send Password Reset Link Info
//
reset_link_info_return_t*
UsersV1API_v1GetResetLinkInfo(apiClient_t *apiClient, char *token);


// Reset User Password
//
void
UsersV1API_v1ResetUserPassword(apiClient_t *apiClient, password_reset_body_t *password_reset_body);


// Send Password Reset Link
//
void
UsersV1API_v1SendUserResetLink(apiClient_t *apiClient, reset_link_body_t *reset_link_body);


// Update User
//
// Update a user. Fields such as `name`, `label`, `password`, and `clusterAdministrator` can be updated.  Only users with the Cluster Administrator role can set or modify the `clusterAdministrator` flag.
//
void
UsersV1API_v1UpdateUser(apiClient_t *apiClient, char *userId, user_update_t *user_update);


// Consent to the current terms and conditions
//
agreed_ack_v1_t*
UsersV1API_v1UserAgreeTerms(apiClient_t *apiClient);


// Log In
//
token_v1_t*
UsersV1API_v1UsersLogin(apiClient_t *apiClient, credentials_t *credentials);


