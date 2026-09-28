#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/api_error.h"
#include "../model/api_not_found_error.h"
#include "../model/create_snapshot_body.h"
#include "../model/instance_snapshots_list.h"
#include "../model/snapshot.h"
#include "../model/user_error_response.h"
#include "../model/v3_update_snapshot_request.h"


// Create instance snapshot
//
snapshot_t*
SnapshotsAPI_v3CreateInstanceSnapshot(apiClient_t *apiClient, char *instanceId, create_snapshot_body_t *create_snapshot_body);


// Delete an instance snapshot
//
// Delete an instance snapshot. Deletion is asynchronous: the snapshot is marked `deleting` and the call returns 204 before the underlying storage has been reclaimed.  Deletes are idempotent: an unknown `snapshotId`, or an unknown `instanceId`, is a successful no-op that still returns 204, and repeated calls return 204 as well. A 404 means the request path did not match a delete route, not that the target was missing. A repeat therefore returns 204 both while the snapshot is still present in the `deleting` state and after it has disappeared.
//
void
SnapshotsAPI_v3DeleteInstanceSnapshot(apiClient_t *apiClient, char *instanceId, char *snapshotId);


// Delete a snapshot
//
// Delete a snapshot by ID. Deletion is asynchronous: the snapshot is marked `deleting` and the call returns 204 before the underlying storage has been reclaimed.  Deletes are idempotent: an unknown `snapshotId`, or a snapshot that was already deleted, is a successful no-op that still returns 204, and repeated calls return 204 as well. A 404 means the request path did not match a delete route, not that the target was missing. A repeat therefore returns 204 both while the snapshot is still present in the `deleting` state and after it has disappeared.
//
void
SnapshotsAPI_v3DeleteSnapshot(apiClient_t *apiClient, char *snapshotId);


// Get instance snapshot
//
// Get instance snapshot by ID.
//
snapshot_t*
SnapshotsAPI_v3GetInstanceSnapshot(apiClient_t *apiClient, char *instanceId, char *snapshotId);


// Get snapshot
//
// Get snapshot by ID.
//
snapshot_t*
SnapshotsAPI_v3GetSnapshot(apiClient_t *apiClient, char *snapshotId);


// List instance snapshots
//
instance_snapshots_list_t*
SnapshotsAPI_v3ListInstanceSnapshots(apiClient_t *apiClient, char *instanceId, double *limit, double *offset);


// Update an instance snapshot
//
snapshot_t*
SnapshotsAPI_v3PatchInstanceSnapshot(apiClient_t *apiClient, char *instanceId, char *snapshotId, create_snapshot_body_t *create_snapshot_body);


// Restore instance snapshot
//
// Restore the specified instance to the given snapshot.
//
void
SnapshotsAPI_v3RestoreInstanceSnapshot(apiClient_t *apiClient, char *instanceId, char *snapshotId);


// Update snapshot name
//
snapshot_t*
SnapshotsAPI_v3UpdateSnapshot(apiClient_t *apiClient, char *snapshotId, v3_update_snapshot_request_t *v3_update_snapshot_request);


