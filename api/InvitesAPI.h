#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/any_type.h"
#include "../model/api_error.h"
#include "../model/api_not_found_error.h"
#include "../model/create_invites_body.h"
#include "../model/edit_invites_body.h"
#include "../model/invitation.h"
#include "../model/invitation_by_token.h"
#include "../model/invite_signup_body.h"
#include "../model/invite_signup_response.h"
#include "../model/invites_list_response.h"
#include "../model/object.h"
#include "../model/revoke_invites_body.h"
#include "../model/revoke_invites_response.h"
#include "../model/user_error_response.h"


// Create invites
//
// **Required role:** Domain administrator or project administrator.  Invite one or more users to create an account in the domain.
//
object_t*
InvitesAPI_v3CreateInvites(apiClient_t *apiClient, create_invites_body_t *create_invites_body);


// Edit invites
//
// **Required role:** Domain administrator or project administrator.  Edit the settings of one or more existing invites.
//
invitation_t*
InvitesAPI_v3EditInvites(apiClient_t *apiClient, edit_invites_body_t *edit_invites_body);


// Get an invite by token
//
// Look up an invitation by its token. Public endpoint used during signup.
//
invitation_by_token_t*
InvitesAPI_v3GetInviteByToken(apiClient_t *apiClient, char *token);


// List invites
//
// **Required role:** Domain administrator or project administrator.  List all invites for the requesting user's domain.
//
invites_list_response_t*
InvitesAPI_v3ListInvites(apiClient_t *apiClient, double *limit, double *offset);


// Revoke invites
//
// **Required role:** Domain administrator or project administrator.  Revoke one or more invites.
//
revoke_invites_response_t*
InvitesAPI_v3RevokeInvites(apiClient_t *apiClient, revoke_invites_body_t *revoke_invites_body);


// Sign up from an invite
//
// Create a new user account from an invitation token. Public endpoint.
//
invite_signup_response_t*
InvitesAPI_v3SignupFromInvite(apiClient_t *apiClient, invite_signup_body_t *invite_signup_body);


