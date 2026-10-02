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
// **Required role:** Domain administrator or project administrator.  Gives every member of a team a role on a project. Pass `all-users` as `teamId` to give the role to everyone in your domain. People added to the team later get the access automatically. Requires a domain administrator, or a project administrator of that project. Available for Enterprise accounts only.
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
// **Required role:** Domain administrator or project administrator.  Gives a user a role on a project: `member` to use the project and its devices, or `admin` to also manage it. This is how a new user gets access to a project. Requires a domain administrator, or a project administrator of that project. Returns 404 if the project, user or role does not exist. Available for Enterprise accounts only.
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
// **Required role:** Domain administrator or project administrator.  Lists who has which role on which project in your domain, for both individual users and teams: each entry names a role and either a `user` or a `team`, plus the `project`. Use it to audit access. Requires a domain or project administrator. Available for Enterprise accounts only.
//
roles_list_response_t*
RolesAPI_v3ListRoles(apiClient_t *apiClient, double *limit, double *offset);


// Remove team role from deployment
//
// **Required role:** Domain administrator.  Revokes a team role within a deployment. Available for Enterprise accounts only.  Revocation is idempotent: if the team does not currently hold that role in the deployment, the call is a no-op and still returns 204. Repeated calls therefore also return 204. A `deploymentId` or `teamId` that does not exist is also a successful no-op that returns 204.
//
void
RolesAPI_v3RemoveTeamRoleFromDeployment(apiClient_t *apiClient, char *deploymentId, char *teamId, char *roleId);


// Remove team role from project
//
// **Required role:** Domain administrator or project administrator.  Takes a role on a project away from a team, so its members lose the access they had through it. Requires a domain administrator, or a project administrator of that project. Available for Enterprise accounts only.  Revocation is idempotent: if the team does not currently hold that role in the project, the call is a no-op and still returns 204. Repeated calls therefore also return 204. A `projectId` or `teamId` that does not exist is also a successful no-op that returns 204. A project administrator acting on another project in their own domain receives 403. An unrecognized `roleId` returns 400.
//
void
RolesAPI_v3RemoveTeamRoleFromProject(apiClient_t *apiClient, char *projectId, char *teamId, char *roleId);


// Remove user role from deployment
//
// **Required role:** Domain administrator.  Revokes a user role within a deployment. Available for Enterprise accounts only.  Revocation is idempotent: if the user does not currently hold that role in the deployment, the call is a no-op and still returns 204. Repeated calls therefore also return 204. A `deploymentId` or `userId` that does not exist is also a successful no-op that returns 204.
//
void
RolesAPI_v3RemoveUserRoleFromDeployment(apiClient_t *apiClient, char *deploymentId, char *userId, char *roleId);


// Remove user role from project
//
// **Required role:** Domain administrator or project administrator.  Takes a role on a project away from a user, so they lose that access (unless they also have it through a team). Requires a domain administrator, or a project administrator of that project. Available for Enterprise accounts only.  Revocation is idempotent: if the user does not currently hold that role in the project, the call is a no-op and still returns 204. Repeated calls therefore also return 204. A `projectId` or `userId` that does not exist is also a successful no-op that returns 204. A project administrator acting on another project in their own domain receives 403. An unrecognized `roleId` returns 400.
//
void
RolesAPI_v3RemoveUserRoleFromProject(apiClient_t *apiClient, char *projectId, char *userId, char *roleId);


