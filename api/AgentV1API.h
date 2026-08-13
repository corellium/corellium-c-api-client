#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/agent_app_ready_response_v1.h"
#include "../model/agent_apps_list_v1.h"
#include "../model/agent_error_v1.h"
#include "../model/agent_icons.h"
#include "../model/agent_install_body_v1.h"
#include "../model/agent_profiles_return.h"
#include "../model/agent_system_adb_auth_v1.h"
#include "../model/agent_system_get_prop_body_v1.h"
#include "../model/agent_system_set_hostname_body_v1.h"
#include "../model/agent_value_return.h"
#include "../model/any_type.h"
#include "../model/api_error_v1.h"
#include "../model/file_changes.h"
#include "../model/object.h"


// Check if App subsystem is ready
//
agent_app_ready_response_v1_t*
AgentV1API_v1AgentAppReady(apiClient_t *apiClient, char *instanceId);


// Delete a File on VM
//
void
AgentV1API_v1AgentDeleteFile(apiClient_t *apiClient, char *instanceId, char *filePath);


// Download a File from VM
//
binary_t*
AgentV1API_v1AgentGetFile(apiClient_t *apiClient, char *instanceId, char *filePath);


// Get the path for a new temp file
//
// Returns a temporary random filename that is guranteed to be unique on the VMs filesystem at the time of invocation of this method.
//
char*
AgentV1API_v1AgentGetTempFilename(apiClient_t *apiClient, char *instanceId);


// Install App at path
//
// Installs the app located at path which must be present on the VM filesystem
//
void
AgentV1API_v1AgentInstallApp(apiClient_t *apiClient, char *instanceId, agent_install_body_v1_t *agent_install_body_v1);


// Install a Profile to VM
//
void
AgentV1API_v1AgentInstallProfile(apiClient_t *apiClient, char *instanceId, binary_t* body);


// Kill an App
//
object_t*
AgentV1API_v1AgentKillApp(apiClient_t *apiClient, char *instanceId, char *bundleId);


// List App Icons
//
// List App Icons as base64 data
//
list_t*
AgentV1API_v1AgentListAppIcons(apiClient_t *apiClient, char *instanceId, char *bundleID);


// List Apps
//
agent_apps_list_v1_t*
AgentV1API_v1AgentListApps(apiClient_t *apiClient, char *instanceId);


// List Apps Status
//
agent_apps_list_v1_t*
AgentV1API_v1AgentListAppsStatus(apiClient_t *apiClient, char *instanceId);


// List Profiles
//
agent_profiles_return_t*
AgentV1API_v1AgentListProfiles(apiClient_t *apiClient, char *instanceId);


// Run an App
//
object_t*
AgentV1API_v1AgentRunApp(apiClient_t *apiClient, char *instanceId, char *bundleId);


// Change Attrs of a File on VM
//
void
AgentV1API_v1AgentSetFileAttributes(apiClient_t *apiClient, char *instanceId, char *filePath, file_changes_t *file_changes);


// Get ADB Auth Setting (AOSP only)
//
agent_system_adb_auth_v1_t*
AgentV1API_v1AgentSystemGetAdbAuth(apiClient_t *apiClient, char *instanceId);


// Get IP of eth0 (AOSP only)
//
agent_value_return_t*
AgentV1API_v1AgentSystemGetNetwork(apiClient_t *apiClient, char *instanceId);


// Get System Property (AOSP only)
//
agent_value_return_t*
AgentV1API_v1AgentSystemGetProp(apiClient_t *apiClient, char *instanceId, agent_system_get_prop_body_v1_t *agent_system_get_prop_body_v1);


// Install OpenGApps (AOSP only)
//
void
AgentV1API_v1AgentSystemInstallOpenGApps(apiClient_t *apiClient, char *instanceId, object_t *body);


// Lock Device (iOS Only)
//
void
AgentV1API_v1AgentSystemLock(apiClient_t *apiClient, char *instanceId);


// Set ADB Auth Setting (AOSP only)
//
void
AgentV1API_v1AgentSystemSetAdbAuth(apiClient_t *apiClient, char *instanceId, agent_system_adb_auth_v1_t *agent_system_adb_auth_v1);


// Set Hostname of instance
//
void
AgentV1API_v1AgentSystemSetHostname(apiClient_t *apiClient, char *instanceId, agent_system_set_hostname_body_v1_t *agent_system_set_hostname_body_v1);


// Instruct VM to halt
//
void
AgentV1API_v1AgentSystemShutdown(apiClient_t *apiClient, char *instanceId);


// Unlock Device (iOS Only)
//
void
AgentV1API_v1AgentSystemUnlock(apiClient_t *apiClient, char *instanceId);


// Uninstall an App
//
object_t*
AgentV1API_v1AgentUninstallApp(apiClient_t *apiClient, char *instanceId, char *bundleId);


// Uninstall a Profile from VM
//
void
AgentV1API_v1AgentUninstallProfile(apiClient_t *apiClient, char *instanceId, char *profileId);


// Upload a file to VM
//
void
AgentV1API_v1AgentUploadFile(apiClient_t *apiClient, char *instanceId, char *filePath, binary_t* body);


