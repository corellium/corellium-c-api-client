#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/api_error_v1.h"
#include "../model/api_not_found_error_v1.h"
#include "../model/instance_v1.h"
#include "../model/network_status_response.h"
#include "../model/project_key_v1.h"
#include "../model/project_settings_v1.h"
#include "../model/project_v1.h"
#include "../model/project_with_keys_v1.h"
#include "../model/user_error_v1.h"


// Add Project Authorized Key
//
project_key_v1_t*
ProjectsV1API_v1AddProjectKey(apiClient_t *apiClient, char *projectId, project_key_v1_t *project_key_v1);


// Create a Project
//
project_v1_t*
ProjectsV1API_v1CreateProject(apiClient_t *apiClient, project_v1_t *project_v1);


// Delete a Project
//
void
ProjectsV1API_v1DeleteProject(apiClient_t *apiClient, char *projectId);


// Get a Project
//
project_with_keys_v1_t*
ProjectsV1API_v1GetProject(apiClient_t *apiClient, char *projectId);


// Get Instances in Project
//
list_t*
ProjectsV1API_v1GetProjectInstances(apiClient_t *apiClient, char *projectId, char *name, char *returnAttr);


// Get Project Authorized Keys
//
list_t*
ProjectsV1API_v1GetProjectKeys(apiClient_t *apiClient, char *projectId);


// Retrieve the network connection log for a project
//
char*
ProjectsV1API_v1GetProjectNetworkLog(apiClient_t *apiClient, char *projectId);


// Retrieve the network connection status for a project
//
network_status_response_t*
ProjectsV1API_v1GetProjectNetworkStatus(apiClient_t *apiClient, char *projectId);


// Get Project VPN Configuration
//
// A Project VPN allows connection _into_ virtual devices in the project (e.g., connecting a researcher's computer as a VPN client to a virtual device within the project). If a Project VPN has been defined, this will return the configuration.
//
char*
ProjectsV1API_v1GetProjectVpnConfig(apiClient_t *apiClient, char *projectId, char *format);


// Get Projects
//
list_t*
ProjectsV1API_v1GetProjects(apiClient_t *apiClient, char *name, int *ids_only);


// Delete Project Authorized Key
//
void
ProjectsV1API_v1RemoveProjectKey(apiClient_t *apiClient, char *projectId, char *keyId);


// Update a Project
//
project_v1_t*
ProjectsV1API_v1UpdateProject(apiClient_t *apiClient, char *projectId, project_v1_t *project_v1);


// Change Project Settings
//
void
ProjectsV1API_v1UpdateProjectSettings(apiClient_t *apiClient, char *projectId, project_settings_v1_t *project_settings_v1);


