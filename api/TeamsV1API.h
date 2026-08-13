#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/api_error_v1.h"
#include "../model/api_internal_consistency_error.h"
#include "../model/api_not_found_error_v1.h"
#include "../model/create_team.h"
#include "../model/team_create.h"
#include "../model/team_v1.h"
#include "../model/user_error_v1.h"


// Add user to team
//
// This endpoint is available for Enterprise accounts only
//
void
TeamsV1API_v1AddUserToTeam(apiClient_t *apiClient, char *teamId, char *userId);


// Remove user from team
//
// This endpoint is available for Enterprise accounts only
//
void
TeamsV1API_v1RemoveUserFromTeam(apiClient_t *apiClient, char *teamId, char *userId);


// Update team
//
// This endpoint is available for Enterprise accounts only
//
void
TeamsV1API_v1TeamChange(apiClient_t *apiClient, char *teamId, create_team_t *create_team);


// Create team
//
// This endpoint is available for Enterprise accounts only
//
team_create_t*
TeamsV1API_v1TeamCreate(apiClient_t *apiClient, create_team_t *create_team);


// Delete team
//
// This endpoint is available for Enterprise accounts only
//
void
TeamsV1API_v1TeamDelete(apiClient_t *apiClient, char *teamId);


// Get teams
//
// This endpoint is available for Enterprise accounts only
//
list_t*
TeamsV1API_v1Teams(apiClient_t *apiClient);


