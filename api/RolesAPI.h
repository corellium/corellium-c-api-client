#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/api_error.h"
#include "../model/api_not_found_error.h"
#include "../model/roles_list_response.h"
#include "../model/user_error_response.h"


// Add team role to deployment
//
// **Required role:** Domain administrator.  Grants a team a role within a deployment. Available for Enterprise accounts only.
//
void
RolesAPI_v3AddTeamRoleToDeployment(apiClient_t *apiClient, char *deploymentId, char *teamId, char *roleId);


// Add team role to project
//
// **Required role:** Domain administrator or project administrator.  Grants a team a role within a project. Available for Enterprise accounts only.
//
void
RolesAPI_v3AddTeamRoleToProject(apiClient_t *apiClient, char *projectId, char *teamId, char *roleId);


// Add user role to deployment
//
// **Required role:** Domain administrator.  Grants a user a role within a deployment. Available for Enterprise accounts only.
//
void
RolesAPI_v3AddUserRoleToDeployment(apiClient_t *apiClient, char *deploymentId, char *userId, char *roleId);


// Add user role to project
//
// **Required role:** Domain administrator or project administrator.  Grants a user a role within a project. Available for Enterprise accounts only.
//
void
RolesAPI_v3AddUserRoleToProject(apiClient_t *apiClient, char *projectId, char *userId, char *roleId);


// List deployment role assignments
//
// **Required role:** Domain administrator or project administrator.  Returns paginated role assignments scoped to deployments. Available for Enterprise accounts only.
//
roles_list_response_t*
RolesAPI_v3ListDeploymentRoles(apiClient_t *apiClient, double *limit, double *offset);


// List all role assignments for the caller's domain
//
// **Required role:** Domain administrator or project administrator.  Returns paginated project role assignments for both users and teams. Available for Enterprise accounts only.
//
roles_list_response_t*
RolesAPI_v3ListRoles(apiClient_t *apiClient, double *limit, double *offset);


// Remove team role from deployment
//
// **Required role:** Domain administrator.  Revokes a team role within a deployment. Available for Enterprise accounts only.
//
void
RolesAPI_v3RemoveTeamRoleFromDeployment(apiClient_t *apiClient, char *deploymentId, char *teamId, char *roleId);


// Remove team role from project
//
// **Required role:** Domain administrator or project administrator.  Revokes a team role within a project. Available for Enterprise accounts only.
//
void
RolesAPI_v3RemoveTeamRoleFromProject(apiClient_t *apiClient, char *projectId, char *teamId, char *roleId);


// Remove user role from deployment
//
// **Required role:** Domain administrator.  Revokes a user role within a deployment. Available for Enterprise accounts only.
//
void
RolesAPI_v3RemoveUserRoleFromDeployment(apiClient_t *apiClient, char *deploymentId, char *userId, char *roleId);


// Remove user role from project
//
// **Required role:** Domain administrator or project administrator.  Revokes a user role within a project. Available for Enterprise accounts only.
//
void
RolesAPI_v3RemoveUserRoleFromProject(apiClient_t *apiClient, char *projectId, char *userId, char *roleId);


