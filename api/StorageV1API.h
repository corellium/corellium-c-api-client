#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/any_type.h"
#include "../model/api_error_v1.h"
#include "../model/api_not_found_error_v1.h"
#include "../model/get_storage_response.h"
#include "../model/object.h"
#include "../model/validation_error.h"


// Mount and attach a storage device
//
// Initiates an asynchronous mount job for a registered storage device. If already mounted, returns status 200. If not, queues a background job and returns 202.
//
object_t*
StorageV1API_v1AttachStorageCluster(apiClient_t *apiClient, char *id);


// Eject/Unmount removable media
//
// Initiates an asynchronous unmount job for the physical storage device. If the device is already unmounted, returns success. If mounted, creates a background job to safely unmount.
//
object_t*
StorageV1API_v1EjectStorageCluster(apiClient_t *apiClient, char *id);


// Get storage devices
//
// List all attached storage devices. This endpoint is only available to all authenticated users.
//
get_storage_response_t*
StorageV1API_v1ListStorage(apiClient_t *apiClient, double limit, double offset, char *identifier, char *device, char *fsType, char *mountPolicy, char *status, char *sort);


// Get storage devices
//
// List all attached storage devices. This endpoint is only available to cluster administrators.
//
get_storage_response_t*
StorageV1API_v1ListStorageCluster(apiClient_t *apiClient, double limit, double offset, char *device, char *fsType, char *fsUUID, char *label, char *serial, char *vendor, char *model, char *mountPolicy, char *status, char *sort);


// List Storage Files
//
// List files from attached storage devices. Looks up the storage device by identifier,   then lists filesystem contents at the given path within the device's mount point.   This endpoint is available to all authenticated users.
//
object_t*
StorageV1API_v1ListStorageFiles(apiClient_t *apiClient, char *id, char *path, double limit, double offset, char *name, char *type, char *sort);


