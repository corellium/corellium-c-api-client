#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/any_type.h"
#include "../model/api_error_v1.h"
#include "../model/api_not_found_error_v1.h"
#include "../model/invitation_v1.h"
#include "../model/invite_revoke_params.h"
#include "../model/object.h"
#include "../model/user_error_v1.h"


// Create Invite
//
// Domain Admin route to invite a new user to create an account
//
object_t*
InvitesV1API_v1CreateUserInvites(apiClient_t *apiClient);


// 
//
void
InvitesV1API_v1EditInvites(apiClient_t *apiClient);


// Get Invites
//
// Gets all invites for a user's domain
//
list_t*
InvitesV1API_v1Invites(apiClient_t *apiClient);


// 
//
void
InvitesV1API_v1InvitesByToken(apiClient_t *apiClient);


// Revoke Invite
//
void
InvitesV1API_v1RevokeUserInvite(apiClient_t *apiClient, invite_revoke_params_t *invite_revoke_params);


// 
//
void
InvitesV1API_v1UserCreateFromInvite(apiClient_t *apiClient);


