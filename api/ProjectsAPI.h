#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/any_type.h"
#include "../model/api_conflict_error.h"
#include "../model/api_error.h"
#include "../model/api_not_found_error.h"
#include "../model/create_project_body.h"
#include "../model/create_project_key_body.h"
#include "../model/fetch_firmware_assets_body.h"
#include "../model/fetch_firmware_assets_response.h"
#include "../model/insufficient_storage_error.h"
#include "../model/network_status.h"
#include "../model/object.h"
#include "../model/patch_project_body.h"
#include "../model/project.h"
#include "../model/project_instance_list.h"
#include "../model/project_key.h"
#include "../model/project_key_list.h"
#include "../model/project_list.h"
#include "../model/user_error_response.h"
#include "../model/vpn_config_preauthorization.h"


// Create a project
//
// **Required role:** Domain administrator.  Create a new project in the authenticated user's domain.
//
project_t*
ProjectsAPI_v3CreateProject(apiClient_t *apiClient, create_project_body_t *create_project_body);


// Add a project key
//
// **Required role:** Domain administrator or project administrator.  Add an authorized key to a project.
//
project_key_t*
ProjectsAPI_v3CreateProjectKey(apiClient_t *apiClient, char *projectId, create_project_key_body_t *create_project_key_body);


// Delete a project
//
// **Required role:** Domain administrator.  Delete a project. The project must contain no devices.  Deletes are idempotent: an unknown `projectId`, or a project that was already deleted, is a successful no-op that still returns 204, and repeated calls return 204 as well. A 404 means the request path did not match a delete route, not that the target was missing.
//
void
ProjectsAPI_v3DeleteProject(apiClient_t *apiClient, char *projectId);


// Delete a project key
//
// **Required role:** Domain administrator or project administrator.  Remove an authorized key from a project.  Deletes are idempotent: a `keyId` that is not present on the project, or an unknown `projectId`, is a successful no-op that still returns 204, and repeated calls return 204 as well. A 404 means the request path did not match a delete route, not that the target was missing.
//
void
ProjectsAPI_v3DeleteProjectKey(apiClient_t *apiClient, char *projectId, char *keyId);


// Fetch firmware assets for a project
//
// Relays a set of firmware asset URLs to the firmware service, which downloads the assets server-side and stores them for the project's domain.
//
fetch_firmware_assets_response_t*
ProjectsAPI_v3FetchProjectFirmwareAssets(apiClient_t *apiClient, char *projectId, fetch_firmware_assets_body_t *fetch_firmware_assets_body);


// Get a project
//
// Retrieve a single project by identifier.
//
project_t*
ProjectsAPI_v3GetProject(apiClient_t *apiClient, char *projectId);


// Get image upload status
//
// Check resumable upload status for a project image or download the image file.
//
binary_t*
ProjectsAPI_v3GetProjectImageUpload(apiClient_t *apiClient, char *projectId, char *type, char *imageId, char *name, double *resumableChunkNumber);


// Get project network log
//
// Retrieve the egress network connection log for a project as plain text.
//
char*
ProjectsAPI_v3GetProjectNetworkLog(apiClient_t *apiClient, char *projectId);


// Get project network status
//
// Retrieve the egress network connection status for a project.
//
network_status_t*
ProjectsAPI_v3GetProjectNetworkStatus(apiClient_t *apiClient, char *projectId);


// Get project VPN configuration
//
// Retrieve the project VPN configuration. A project VPN allows a client (e.g. a researcher's computer) to connect into the virtual devices within the project. The response media type follows the requested format: 'ovpn' returns a text OpenVPN profile, any other value returns a binary Tunnelblick zip.
//
char*
ProjectsAPI_v3GetProjectVpnConfig(apiClient_t *apiClient, char *projectId, char *format);


// List project instances
//
// List the instances belonging to a project.
//
project_instance_list_t*
ProjectsAPI_v3ListProjectInstances(apiClient_t *apiClient, char *projectId, double *limit, double *offset, char *name);


// List project keys
//
// List the authorized keys for a project.
//
project_key_list_t*
ProjectsAPI_v3ListProjectKeys(apiClient_t *apiClient, char *projectId, double *limit, double *offset);


// List projects
//
// List the projects the authenticated user can access.
//
project_list_t*
ProjectsAPI_v3ListProjects(apiClient_t *apiClient, double *limit, double *offset, char *name);


// Update a project
//
// Update a project's name, settings, or quotas. This is the single canonical way to change project settings: fields provided in `settings` are merged into the project's existing settings, so omitted fields are preserved.
//
project_t*
ProjectsAPI_v3PatchProject(apiClient_t *apiClient, char *projectId, patch_project_body_t *patch_project_body);


// Pre-authorize a VPN configuration download
//
// Pre-authorize a VPN configuration download. Returns a short-lived signed token that authorizes the download without an Authorization header, so it can be embedded in a plain download URL: GET /v1/preauthed-vpn-configs/{token}/{filename}. The token carries the client identifier and the format, and expires with the calling session token.
//
vpn_config_preauthorization_t*
ProjectsAPI_v3PreauthVpnConfig(apiClient_t *apiClient, char *projectId, char *filename);


// Upload image chunk
//
// Upload a chunk of a project image using the resumable upload protocol. Creates the image record on the first chunk if it does not yet exist. This is the upload used while creating a device, before any instance exists to own the image.
//
object_t*
ProjectsAPI_v3PutProjectImageUpload(apiClient_t *apiClient, char *projectId, char *type, char *imageId, char *name, binary_t* body, double *resumableChunkNumber, double *resumableChunkSize, double *resumableCurrentChunkSize, double *resumableTotalSize, double *resumableTotalChunks, char *corelliumChecksum, char *flavor, char *x_corellium_image_encoding, int *x_corellium_image_encapsulated, double *x_corellium_total_file_size, char *x_corellium_image_password);


