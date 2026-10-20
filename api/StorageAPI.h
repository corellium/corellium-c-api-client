#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/api_error.h"
#include "../model/api_not_found_error.h"
#include "../model/storage_already_mounted_response.h"
#include "../model/storage_attach_response.h"
#include "../model/storage_device_list.h"
#include "../model/storage_eject_already_unmounted_response.h"
#include "../model/storage_file_list.h"
#include "../model/storage_list.h"
#include "../model/storage_queue_error.h"
#include "../model/user_error_response.h"


// Attach storage device
//
// **Required role:** Cluster administrator.  Mounts an attached storage device so its files can be used. Mounting runs in the background: returns 202 when the mount has been queued, or 200 if the device is already mounted. Browse its files with `GET /v3/storage/{id}/files/{path}`. Requires a cluster administrator. Requires the serverAttachedStorage feature. Not available on cloud installations.
//
storage_already_mounted_response_t*
StorageAPI_v3AttachClusterStorage(apiClient_t *apiClient, char *id);


// Eject storage device
//
// **Required role:** Cluster administrator.  Unmounts an attached storage device so it can be unplugged safely. Unmounting runs in the background: returns 202 when the unmount has been queued, or 200 if the device is already unmounted. Requires a cluster administrator. Requires the serverAttachedStorage feature. Not available on cloud installations.
//
storage_eject_already_unmounted_response_t*
StorageAPI_v3EjectClusterStorage(apiClient_t *apiClient, char *id);


// List cluster storage devices
//
// **Required role:** Cluster administrator.  Lists the physical storage devices (for example USB drives) attached to the cluster's servers, for cluster administrators. Requires a cluster administrator. Requires the serverAttachedStorage feature. Not available on cloud installations.
//
storage_device_list_t*
StorageAPI_v3ListClusterStorage(apiClient_t *apiClient, double *limit, double *offset, char *id, char *device, char *fsType, char *fsUuid, char *label, char *serial, char *vendor, char *model, char *mountPolicy, char *status, char *sort);


// List server-attached storage devices
//
// Lists the physical storage devices (for example USB drives or disks) plugged into an on-site Corellium server, with their name, filesystem, label, vendor, whether they are mounted, and whether they are mounted read-only (`RO`) or read-write (`RW`). Use a device's `id` with `v3ListStorageFiles` to browse its contents. For cluster administrators on on-site deployments; not available on cloud installations. Results are paginated and can be filtered and sorted with the query parameters.
//
storage_list_t*
StorageAPI_v3ListStorage(apiClient_t *apiClient, double *limit, double *offset, char *sort, char *identifier, char *device, char *fsType, char *mountPolicy, char *status);


// List storage files
//
// Lists the files and folders at one path on a server-attached storage device (see `v3ListStorage`), with each entry's name, type, size and modification time. Use `/` to list the top level, then pass a folder's path to go deeper. The path must be a folder; a file path returns 400, and paths that try to leave the device (for example with `..`) are rejected. Returns 404 if the device or path does not exist.
//
storage_file_list_t*
StorageAPI_v3ListStorageFiles(apiClient_t *apiClient, char *id, char *path, double *limit, double *offset, char *sort, char *name, char *type);


