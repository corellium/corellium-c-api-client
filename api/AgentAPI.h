#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/agent_app_ready_response.h"
#include "../model/agent_apps_list.h"
#include "../model/agent_apps_status_list.h"
#include "../model/agent_container_health.h"
#include "../model/agent_container_list.h"
#include "../model/agent_error.h"
#include "../model/agent_file_attributes_body.h"
#include "../model/agent_frida_process_list.h"
#include "../model/agent_frida_response.h"
#include "../model/agent_frida_run_body.h"
#include "../model/agent_icons_response.h"
#include "../model/agent_install_body.h"
#include "../model/agent_profile_list_response.h"
#include "../model/agent_remote_it_status.h"
#include "../model/agent_system_adb_auth.h"
#include "../model/agent_system_get_prop_body.h"
#include "../model/agent_system_get_prop_response.h"
#include "../model/agent_system_install_open_gapps_body.h"
#include "../model/agent_system_network_response.h"
#include "../model/agent_system_result.h"
#include "../model/agent_system_set_device_properties_body.h"
#include "../model/agent_system_set_hostname_body.h"
#include "../model/agent_temp_file_response.h"
#include "../model/api_error.h"
#include "../model/api_not_found_error.h"


// Delete a file on VM
//
// Delete a file from the VM filesystem.
//
void
AgentAPI_v3DeleteFileAgent(apiClient_t *apiClient, char *instanceId, char *filePath);


// Get ADB auth setting
//
// Get the current ADB authorization setting (Android only).
//
agent_system_adb_auth_t*
AgentAPI_v3GetAdbAuthAgent(apiClient_t *apiClient, char *instanceId);


// Check if app subsystem is ready
//
// Check if the app subsystem on the VM is ready.
//
agent_app_ready_response_t*
AgentAPI_v3GetAppReadyAgent(apiClient_t *apiClient, char *instanceId);


// Get container health
//
// Check whether a nested container is healthy (Android only).
//
agent_container_health_t*
AgentAPI_v3GetContainerHealthAgent(apiClient_t *apiClient, char *instanceId, char *containerId);


// Download a file from VM
//
// Download a file from the VM filesystem.
//
binary_t*
AgentAPI_v3GetFileAgent(apiClient_t *apiClient, char *instanceId, char *filePath);


// Get eth0 IP address
//
// Get the IP address bound to eth0 (Android only).
//
agent_system_network_response_t*
AgentAPI_v3GetNetworkAgent(apiClient_t *apiClient, char *instanceId);


// Get a system property
//
// Get the value of a system property (Android only).
//
agent_system_get_prop_response_t*
AgentAPI_v3GetPropAgent(apiClient_t *apiClient, char *instanceId, agent_system_get_prop_body_t *agent_system_get_prop_body);


// Get Remote.It status
//
// Get the installation status of the Remote.It package on the VM (RPi only).
//
agent_remote_it_status_t*
AgentAPI_v3GetRemoteItStatusAgent(apiClient_t *apiClient, char *instanceId);


// Get a temp file path on VM
//
// Returns a unique temporary file path on the VM filesystem guaranteed to be available at the time of invocation.
//
agent_temp_file_response_t*
AgentAPI_v3GetTempFileAgent(apiClient_t *apiClient, char *instanceId);


// Install app at path
//
// Installs the app located at path, which must be present on the VM filesystem.
//
void
AgentAPI_v3InstallAgent(apiClient_t *apiClient, char *instanceId, agent_install_body_t *agent_install_body);


// Install OpenGApps
//
// Download and install OpenGApps on the instance (Android only).
//
void
AgentAPI_v3InstallOpenGappsAgent(apiClient_t *apiClient, char *instanceId, agent_system_install_open_gapps_body_t *agent_system_install_open_gapps_body);


// Install a profile
//
// Install a configuration profile on the VM.
//
void
AgentAPI_v3InstallProfileAgent(apiClient_t *apiClient, char *instanceId, binary_t* body);


// Install Remote.It
//
// Install the Remote.It package on the VM (RPi only). The device name and platform code are derived server-side from the instance and its flavor.
//
agent_remote_it_status_t*
AgentAPI_v3InstallRemoteItAgent(apiClient_t *apiClient, char *instanceId);


// Kill an app
//
// Kill a running app on the VM.
//
void
AgentAPI_v3KillAppAgent(apiClient_t *apiClient, char *instanceId, char *bundleId);


// Kill Frida
//
// Stop the running Frida session on the VM.
//
agent_frida_response_t*
AgentAPI_v3KillFridaAgent(apiClient_t *apiClient, char *instanceId);


// List app icons
//
// List app icons as base64-encoded data for the specified bundle IDs.
//
agent_icons_response_t*
AgentAPI_v3ListAppIconsAgent(apiClient_t *apiClient, char *instanceId, char *bundleId);


// List apps
//
// List installed apps on the VM.
//
agent_apps_list_t*
AgentAPI_v3ListAppsAgent(apiClient_t *apiClient, char *instanceId, char *loadIcons);


// List apps status
//
// List running status for all installed apps on the VM.
//
agent_apps_status_list_t*
AgentAPI_v3ListAppsStatusAgent(apiClient_t *apiClient, char *instanceId);


// List containers
//
// List the nested containers on the VM (Android only).
//
agent_container_list_t*
AgentAPI_v3ListContainersAgent(apiClient_t *apiClient, char *instanceId);


// List Frida processes
//
// Run frida-ps on the VM and return the list of processes.
//
agent_frida_process_list_t*
AgentAPI_v3ListFridaProcessesAgent(apiClient_t *apiClient, char *instanceId);


// List profiles
//
// List the configuration profiles installed on the VM.
//
agent_profile_list_response_t*
AgentAPI_v3ListProfilesAgent(apiClient_t *apiClient, char *instanceId);


// Lock device
//
// Lock the device (iOS only).
//
void
AgentAPI_v3LockAgent(apiClient_t *apiClient, char *instanceId);


// Run an app
//
// Run an installed app on the VM.
//
void
AgentAPI_v3RunAppAgent(apiClient_t *apiClient, char *instanceId, char *bundleId);


// Run Frida
//
// Attach Frida to a target process on the VM.
//
agent_frida_response_t*
AgentAPI_v3RunFridaAgent(apiClient_t *apiClient, char *instanceId, agent_frida_run_body_t *agent_frida_run_body);


// Set ADB auth setting
//
// Enable or disable ADB authorization (Android only).
//
void
AgentAPI_v3SetAdbAuthAgent(apiClient_t *apiClient, char *instanceId, agent_system_adb_auth_t *agent_system_adb_auth);


// Set device properties
//
// Set device properties (model and manufacturer ID) of the instance (Android only).
//
agent_system_result_t*
AgentAPI_v3SetDevicePropertiesAgent(apiClient_t *apiClient, char *instanceId, agent_system_set_device_properties_body_t *agent_system_set_device_properties_body);


// Change attributes of a file on VM
//
// Change attributes (path, mode, ownership) of a file on the VM filesystem.
//
void
AgentAPI_v3SetFileAttributesAgent(apiClient_t *apiClient, char *instanceId, char *filePath, agent_file_attributes_body_t *agent_file_attributes_body);


// Set instance hostname
//
// Set the hostname of the instance.
//
agent_system_result_t*
AgentAPI_v3SetHostnameAgent(apiClient_t *apiClient, char *instanceId, agent_system_set_hostname_body_t *agent_system_set_hostname_body);


// Shut down instance
//
// Shut down the instance.
//
void
AgentAPI_v3ShutdownAgent(apiClient_t *apiClient, char *instanceId);


// Start a container
//
// Start a nested container on the VM (Android only).
//
void
AgentAPI_v3StartContainerAgent(apiClient_t *apiClient, char *instanceId, char *containerId);


// Start an app in a container
//
// Start an Android application in a nested container (Android only).
//
void
AgentAPI_v3StartContainerAppAgent(apiClient_t *apiClient, char *instanceId, char *containerId, char *packageName, char *activityName);


// Start and monitor an app in a container
//
// Start an Android application in a nested container and monitor it (Android only).
//
void
AgentAPI_v3StartContainerAppMonitoredAgent(apiClient_t *apiClient, char *instanceId, char *containerId, char *packageName, char *activityName);


// Stop a container
//
// Stop a nested container on the VM (Android only).
//
void
AgentAPI_v3StopContainerAgent(apiClient_t *apiClient, char *instanceId, char *containerId);


// Stop a monitored app in a container
//
// Stop the monitored Android application in a nested container, if one is monitored (Android only).
//
void
AgentAPI_v3StopContainerAppAgent(apiClient_t *apiClient, char *instanceId, char *containerId);


// Uninstall an app
//
// Uninstall an app from the VM.
//
void
AgentAPI_v3UninstallAppAgent(apiClient_t *apiClient, char *instanceId, char *bundleId);


// Uninstall a profile
//
// Uninstall a configuration profile from the VM.
//
void
AgentAPI_v3UninstallProfileAgent(apiClient_t *apiClient, char *instanceId, char *profileId);


// Uninstall Remote.It
//
// Uninstall the Remote.It package from the VM (RPi only).
//
agent_remote_it_status_t*
AgentAPI_v3UninstallRemoteItAgent(apiClient_t *apiClient, char *instanceId);


// Unlock device
//
// Unlock the device (iOS only).
//
void
AgentAPI_v3UnlockAgent(apiClient_t *apiClient, char *instanceId);


// Upload a file to VM
//
// Upload a file to the VM filesystem at the specified path.
//
void
AgentAPI_v3UploadFileAgent(apiClient_t *apiClient, char *instanceId, char *filePath, binary_t* body);


