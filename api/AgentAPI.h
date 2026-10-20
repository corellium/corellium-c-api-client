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
#include "../model/agent_file_archive_download_body.h"
#include "../model/agent_file_attributes_body.h"
#include "../model/agent_file_download_token.h"
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
#include "../model/user_error_response.h"


// Delete a file on VM
//
// Delete a file from the VM filesystem.  Deletes are idempotent: an unknown `instanceId`, or a path the on-device agent no longer has, is a successful no-op that still returns 204, and repeated calls return 204 as well. A 404 means the request path did not match a delete route, not that the target was missing. Other agent-reported failures, and an unreachable agent, are still reported as failures.
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
// Checks whether the device's agent is ready to manage apps. The agent is a helper service running inside the device that carries out the Agent calls (installing and running apps, reading and writing files, and so on). It starts after the device boots, so a device that just turned `on` may not be ready yet. Call this first and wait until it reports ready before using the other Agent endpoints.
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
// Downloads one file from the device's filesystem, given its full path on the device (for example `/tmp/log.txt`). The response body is the raw file. For large files, use `v3PreauthorizeFileDownloadAgent` so the download does not have to pass through your SDK client.
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
// Returns an unused temporary file path on the device, free at the moment of the call. Use it as the target for `v3UploadFileAgent`, for example to stage an app package before `v3InstallAgent`.
//
agent_temp_file_response_t*
AgentAPI_v3GetTempFileAgent(apiClient_t *apiClient, char *instanceId);


// Install app at path
//
// Installs an app from a package file that is already on the device, for example an `.ipa` (iOS) or `.apk` (Android). Returns 204 once installed.  **Installing an app from your computer:** 1. `v3GetAppReadyAgent`: wait until the agent is ready. 2. `v3GetTempFileAgent`: get a free temporary path on the device. 3. `v3UploadFileAgent`: upload the package to that path. 4. `v3InstallAgent` (this call) with that `path`. 5. `v3ListAppsAgent` to find the app's bundle ID, then `v3RunAppAgent` to start it.
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
// Force-quits a running app on the device, identified by its bundle ID. The app stays installed; start it again with `v3RunAppAgent`.
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
// Lists the apps installed on the device, with each app's bundle ID (for example `com.android.egg`) and name. The bundle ID is what the run, kill and uninstall calls need.
//
agent_apps_list_t*
AgentAPI_v3ListAppsAgent(apiClient_t *apiClient, char *instanceId, char *loadIcons);


// List apps status
//
// Returns, for every installed app, whether it is currently running. Use it to check that an app started after `v3RunAppAgent`, or stopped after `v3KillAppAgent`.
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


// Pre-authorize an archive download from VM
//
// Returns a short-lived token for downloading several files and folders from the device as one ZIP archive, built on the server. List the paths to include in the body, then download with `GET /v1/preauthed/{token}/{filename}`. The token expires with your current session.
//
agent_file_download_token_t*
AgentAPI_v3PreauthorizeFileArchiveDownloadAgent(apiClient_t *apiClient, char *instanceId, agent_file_archive_download_body_t *agent_file_archive_download_body);


// Pre-authorize a file download from VM
//
// Returns a short-lived token for downloading one device file directly (for example from a browser or download manager) without an `Authorization` header and without buffering it in your SDK client. Download it with `GET /v1/preauthed/{token}/{filename}`. The token works only for this file and expires with your current session.
//
agent_file_download_token_t*
AgentAPI_v3PreauthorizeFileDownloadAgent(apiClient_t *apiClient, char *instanceId, char *filePath);


// Run an app
//
// Launches an installed app on the device, identified by its bundle ID from `v3ListAppsAgent`. Returns 204 once the launch has been requested; check `v3ListAppsStatusAgent` to confirm it is running.
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
// Changes a file on the device: move or rename it (`path`), change its permissions (`mode`), or change its owner. Send only what you want to change.
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
// Removes an app from the device, identified by its bundle ID.
//
void
AgentAPI_v3UninstallAppAgent(apiClient_t *apiClient, char *instanceId, char *bundleId);


// Uninstall a profile
//
// Uninstall a configuration profile from the VM.  Deletes are idempotent: an unknown `instanceId`, or a profile that is not installed, is a successful no-op that still returns 204, and repeated calls return 204 as well. A 404 means the request path did not match a delete route, not that the target was missing. Other agent-reported failures, and an unreachable agent, are still reported as failures.
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
// Writes a file onto the device's filesystem at the given full path, replacing any file already there. Send the raw file bytes as the body. Use `v3GetTempFileAgent` first if you just need somewhere to put a file, for example an app package to install.
//
void
AgentAPI_v3UploadFileAgent(apiClient_t *apiClient, char *instanceId, char *filePath, binary_t* body);


