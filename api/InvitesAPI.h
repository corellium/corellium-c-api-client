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
#include "../model/get_invite_by_token_body.h"
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
// **Required role:** Domain administrator or project administrator.  Invites people by email to create an account in your domain. Requires a domain or project administrator. Each person is emailed a signup link; they create their account with `v3SignupFromInvite`. Use `settings` to add them to teams and give them project access automatically when they sign up.  The response has one entry per email address: either the created `invite`, or an `error`. An address fails if someone in your domain already uses it, or if it already has a pending invite. To email a pending invite again, send the same address with `resend: true`; this issues a new signup link and the old one stops working.
//
object_t*
InvitesAPI_v3CreateInvites(apiClient_t *apiClient, create_invites_body_t *create_invites_body);


// Edit invites
//
// **Required role:** Domain administrator or project administrator.  Changes the teams and projects a pending invite will grant when the person signs up. Requires a domain or project administrator. Only the first invite matching the given IDs is changed, so send one ID per request. Team and project IDs not in your domain are dropped. Returns the invite after the change. The person is not emailed again.
//
invitation_t*
InvitesAPI_v3EditInvites(apiClient_t *apiClient, edit_invites_body_t *edit_invites_body);


// Get an invite by token
//
// Looks up an invitation from the token in a signup link, so a signup page can show which domain and email the invite is for before the person creates their account. Needs no sign-in. Returns 403 if the invite has expired, the token does not match, or the domain is disabled, and 404 if no invite has this token.
//
invitation_by_token_t*
InvitesAPI_v3GetInviteByToken(apiClient_t *apiClient, get_invite_by_token_body_t *get_invite_by_token_body);


// List invites
//
// **Required role:** Domain administrator or project administrator.  Lists invitations that have been sent in your domain but not yet used or revoked, with each invite's email and the teams and projects it will grant. Requires a domain or project administrator. Results are paginated with `limit` and `offset`.
//
invites_list_response_t*
InvitesAPI_v3ListInvites(apiClient_t *apiClient, double *limit, double *offset);


// Revoke invites
//
// **Required role:** Domain administrator or project administrator.  Cancels pending invites, so their signup links stop working. Requires a domain or project administrator. Returns how many invites were removed; IDs that do not match a pending invite in your domain are ignored. People who already signed up are not affected; remove their accounts with `DELETE /v3/users/{userId}`.
//
revoke_invites_response_t*
InvitesAPI_v3RevokeInvites(apiClient_t *apiClient, revoke_invites_body_t *revoke_invites_body);


// Sign up from an invite
//
// Creates a new user account from the token in an invitation email. Needs no sign-in. The account uses the invited email (or `email` from a single sign-on provider, if given) as its username. The teams and project access set on the invite are applied, and the invite is then used up. If your domain requires agreeing to its terms, `agreed` must be true. Returns 403 if the invite has expired or the domain is disabled, and 404 if the token is unknown or already used.
//
invite_signup_response_t*
InvitesAPI_v3SignupFromInvite(apiClient_t *apiClient, invite_signup_body_t *invite_signup_body);


