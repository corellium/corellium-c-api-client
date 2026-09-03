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
// **Required role:** Cluster administrator.  Mounts a registered storage device. Returns 200 if already mounted, 202 if a mount job was queued. Requires the serverAttachedStorage feature.
//
storage_already_mounted_response_t*
StorageAPI_v3AttachClusterStorage(apiClient_t *apiClient, char *id);


// Eject storage device
//
// **Required role:** Cluster administrator.  Unmounts a registered storage device. Returns 200 if already unmounted, 202 if an unmount job was queued. Requires the serverAttachedStorage feature.
//
storage_eject_already_unmounted_response_t*
StorageAPI_v3EjectClusterStorage(apiClient_t *apiClient, char *id);


// List cluster storage devices
//
// **Required role:** Cluster administrator.  Returns all attached storage devices. Requires the serverAttachedStorage feature.
//
storage_device_list_t*
StorageAPI_v3ListClusterStorage(apiClient_t *apiClient, double *limit, double *offset, char *id, char *device, char *fsType, char *fsUuid, char *label, char *serial, char *vendor, char *model, char *mountPolicy, char *status, char *sort);


// List storage devices
//
// List all attached storage devices visible to the authenticated user.
//
storage_list_t*
StorageAPI_v3ListStorage(apiClient_t *apiClient, double *limit, double *offset, char *sort, char *identifier, char *device, char *fsType, char *mountPolicy, char *status);


// List storage files
//
// List files at a path within an attached storage device. The device is resolved by identifier and the filesystem contents are listed at the given path within the mount point.
//
storage_file_list_t*
StorageAPI_v3ListStorageFiles(apiClient_t *apiClient, char *id, char *path, double *limit, double *offset, char *sort, char *name, char *type);


