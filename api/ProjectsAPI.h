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
// **Required role:** Domain administrator.  Creates a new project in your domain. Requires a domain administrator.  **Give it quota, or it cannot run devices.** A new project created without `quotas` has zero quota. Quota is reserved out of your domain's total allowance, so if the whole allowance is already reserved by other projects, lower one of them with `v3PatchProject` first.  When you set `quotas`, `cores` is required. `instances` is derived from `cores` if you leave it out, and memory is always calculated from cores (6144 MiB per core); any `ram` you send is ignored.  Returns 201 with the new project, including its `id`.
//
project_t*
ProjectsAPI_v3CreateProject(apiClient_t *apiClient, create_project_body_t *create_project_body);


// Add a project key
//
// **Required role:** Domain administrator or project administrator.  Authorizes a public key on the project, so its holder can connect to the project's devices. Requires a domain or project administrator.  Set `kind` to `ssh` for SSH access or `adb` for Android Debug Bridge access, and put the public key (never the private key) in `key`, in the same one-line format as an OpenSSH `authorized_keys` entry. `label` is an optional note to help you recognise the key later. Returns 400 if the key cannot be parsed.
//
project_key_t*
ProjectsAPI_v3CreateProjectKey(apiClient_t *apiClient, char *projectId, create_project_key_body_t *create_project_key_body);


// Delete a project
//
// **Required role:** Domain administrator.  Deletes a project together with every file (image) uploaded to it. Requires a domain administrator.  The project must not contain any devices: if it does, the request fails with 409 and nothing is deleted. Delete the devices first with `DELETE /v3/instances/{instanceId}` and wait until they are gone.  Deletes are idempotent: an unknown `projectId`, or a project that was already deleted, is a successful no-op that still returns 204, and repeated calls return 204 as well. A 404 means the request path did not match a delete route, not that the target was missing.
//
void
ProjectsAPI_v3DeleteProject(apiClient_t *apiClient, char *projectId);


// Delete a project key
//
// **Required role:** Domain administrator or project administrator.  Removes an authorized key from the project, so it can no longer be used to connect to the project's devices. Requires a domain or project administrator.  Deletes are idempotent: a `keyId` that is not present on the project, or an unknown `projectId`, is a successful no-op that still returns 204, and repeated calls return 204 as well. A 404 means the request path did not match a delete route, not that the target was missing.
//
void
ProjectsAPI_v3DeleteProjectKey(apiClient_t *apiClient, char *projectId, char *keyId);


// Fetch firmware assets for a project
//
// Asks the platform to download firmware assets (for example the decryption keys some iOS versions need to boot) from the given URLs and store them for your domain. Use it when device creation reports that assets are missing: the missing asset URLs appear in that error and in each firmware entry. The response lists which URLs were newly stored, which were already present, and which failed and why. Returns 409 if downloading assets is turned off on this deployment (for example an air-gapped one); there, upload the assets as a file and install them with `POST /v3/images/install-firmware-assets` instead.
//
fetch_firmware_assets_response_t*
ProjectsAPI_v3FetchProjectFirmwareAssets(apiClient_t *apiClient, char *projectId, fetch_firmware_assets_body_t *fetch_firmware_assets_body);


// Get a project
//
// Returns one project with its settings, quotas, and current resource usage (`quotasUsed`). Compare `quotas` with `quotasUsed` to see whether there is room for another device before creating one. Returns 404 if the project does not exist and 403 if you cannot access it.
//
project_t*
ProjectsAPI_v3GetProject(apiClient_t *apiClient, char *projectId);


// Get image upload status
//
// Checks the progress of a chunked upload made with `v3PutProjectImageUpload`, or downloads the finished file.  - **With chunk parameters** (`resumableChunkNumber` and friends): returns 200 if that chunk is already stored, or 204 if it still needs to be sent. Use this to resume an interrupted upload without re-sending data. - **Without them:** downloads the image file.
//
binary_t*
ProjectsAPI_v3GetProjectImageUpload(apiClient_t *apiClient, char *projectId, char *type, char *imageId, char *name, double *resumableChunkNumber);


// Get project network log
//
// Returns the log of the project's outbound VPN connection as plain text. Use it to diagnose a connection that will not come up.
//
char*
ProjectsAPI_v3GetProjectNetworkLog(apiClient_t *apiClient, char *projectId);


// Get project network status
//
// Returns the state of the project's outbound VPN connection (the connection set in `settings.connection`), such as whether it is connected, and error details if it is not. Use it to check that device traffic is flowing through your VPN.
//
network_status_t*
ProjectsAPI_v3GetProjectNetworkStatus(apiClient_t *apiClient, char *projectId);


// Get project VPN configuration
//
// Downloads a VPN configuration that lets your computer join the project's device network, so you can reach the devices directly (for example by SSH or a local debugger). Set `format` to 'ovpn' to get an OpenVPN profile to import into any OpenVPN client. Any other value returns a zip for the Tunnelblick client on macOS. Returns 400 if the project does not have a VPN endpoint yet.
//
char*
ProjectsAPI_v3GetProjectVpnConfig(apiClient_t *apiClient, char *projectId, char *format);


// List project instances
//
// Lists the devices (instances) in a project, with their ID, name and current state. Results are paginated with `limit` and `offset`; use `name` to find a device by its exact name. For full device details, call `GET /v3/instances/{instanceId}`.
//
project_instance_list_t*
ProjectsAPI_v3ListProjectInstances(apiClient_t *apiClient, char *projectId, double *limit, double *offset, char *name);


// List project keys
//
// Lists the public keys authorized on this project. Keys let you connect to the project's devices over SSH, or to Android devices over ADB, without a password. Returns 403 if your deployment is not licensed for key pairing.
//
project_key_list_t*
ProjectsAPI_v3ListProjectKeys(apiClient_t *apiClient, char *projectId, double *limit, double *offset);


// List projects
//
// Lists the projects you can access. A project is a workspace that holds devices (instances), the files uploaded for them, and a share of your domain's resources (CPU cores, memory and device count). Almost every other call needs a project ID, so this is usually the first call after you sign in.  Results are paginated with `limit` and `offset`. Use `name` to find one project by its exact name (not case-sensitive). Each entry includes its quotas, current usage, and the number of authorized keys.
//
project_list_t*
ProjectsAPI_v3ListProjects(apiClient_t *apiClient, double *limit, double *offset, char *name);


// Update a project
//
// Changes a project's name, settings or quotas. Send only the fields you want to change.  - `settings` is merged into the existing settings: fields you leave out keep their current values. - `quotas` follows the same rules as on create: `cores` is required, `instances` is derived when omitted, and memory is always calculated from cores. - Changing the network connection (`settings.connection`) is refused with 400 while any device in the project is running. Stop the devices first.  Returns the updated project.
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
// Uploads one chunk of a file into this project, using the same resumable protocol as `PUT /v3/images/{imageId}/file`. The difference is that you choose the image ID yourself (a new random UUID) and the image record is created automatically when the first chunk arrives, so no `POST /v3/images` call is needed. The `type` and `name` in the path set the image type and name. The image belongs to the project and is deleted with it. The web interface uses this route when uploading firmware while creating a device. For your own code, `POST /v3/images` followed by `PUT /v3/images/{imageId}/file` is easier to follow. Returns 200 with an empty object for each stored chunk. If an upload fails for a reason other than a network error, the partial image is deleted.
//
object_t*
ProjectsAPI_v3PutProjectImageUpload(apiClient_t *apiClient, char *projectId, char *type, char *imageId, char *name, binary_t* body, double *resumableChunkNumber, double *resumableChunkSize, double *resumableCurrentChunkSize, double *resumableTotalSize, double *resumableTotalChunks, char *corelliumChecksum, char *flavor, char *x_corellium_image_encoding, int *x_corellium_image_encapsulated, double *x_corellium_total_file_size, char *x_corellium_image_password);


