#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/api_error_v1.h"
#include "../model/role_v1.h"
#include "../model/user_error_v1.h"


// Add team role to project
//
// This endpoint is available for Enterprise accounts only
//
void
RolesV1API_v1AddTeamRoleToProject(apiClient_t *apiClient, char *projectId, char *teamId, char *roleId);


// Add user role to project
//
// This endpoint is available for Enterprise accounts only
//
void
RolesV1API_v1AddUserRoleToProject(apiClient_t *apiClient, char *projectId, char *userId, char *roleId);


// Remove team role from project
//
// This endpoint is available for Enterprise accounts only
//
void
RolesV1API_v1RemoveTeamRoleFromProject(apiClient_t *apiClient, char *projectId, char *teamId, char *roleId);


// Remove user role from project
//
// This endpoint is available for Enterprise accounts only
//
void
RolesV1API_v1RemoveUserRoleFromProject(apiClient_t *apiClient, char *projectId, char *userId, char *roleId);


// Get all roles
//
// This endpoint is available for Enterprise accounts only
//
list_t*
RolesV1API_v1Roles(apiClient_t *apiClient);


