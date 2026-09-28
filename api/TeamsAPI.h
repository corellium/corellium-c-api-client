#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/api_error.h"
#include "../model/api_not_found_error.h"
#include "../model/create_team_body.h"
#include "../model/team_created.h"
#include "../model/teams_list_response.h"
#include "../model/update_team_body.h"
#include "../model/user_error_response.h"


// Add a user to a team
//
// **Required role:** Domain administrator.  Add a user to a team. Available for Enterprise accounts only.
//
void
TeamsAPI_v3AddUserToTeam(apiClient_t *apiClient, char *teamId, char *userId);


// Create a team
//
// **Required role:** Domain administrator.  Create a team. Available for Enterprise accounts only.
//
team_created_t*
TeamsAPI_v3CreateTeam(apiClient_t *apiClient, create_team_body_t *create_team_body);


// Delete a team
//
// **Required role:** Domain administrator.  Delete a team. Available for Enterprise accounts only.  Deletes are idempotent: a `teamId` that does not exist, including one that was already deleted, is a successful no-op that still returns 204, and repeated calls return 204 as well. A 404 means the request path did not match a delete route, not that the target was missing.
//
void
TeamsAPI_v3DeleteTeam(apiClient_t *apiClient, char *teamId);


// List teams
//
// List teams for the requesting domain. Available for Enterprise accounts only.
//
teams_list_response_t*
TeamsAPI_v3ListTeams(apiClient_t *apiClient, double *limit, double *offset);


// Remove a user from a team
//
// **Required role:** Domain administrator.  Remove a user from a team. Available for Enterprise accounts only.  Removal is idempotent: if the user is not a member of the team, the call is a no-op and still returns 204. Repeated calls therefore also return 204. A `teamId` or `userId` that does not exist is also a successful no-op that returns 204.
//
void
TeamsAPI_v3RemoveUserFromTeam(apiClient_t *apiClient, char *teamId, char *userId);


// Update a team
//
// **Required role:** Domain administrator.  Update a team. Available for Enterprise accounts only.
//
void
TeamsAPI_v3UpdateTeam(apiClient_t *apiClient, char *teamId, update_team_body_t *update_team_body);


