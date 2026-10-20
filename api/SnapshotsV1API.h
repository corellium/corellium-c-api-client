#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/api_error_v1.h"
#include "../model/snapshot_creation_options.h"
#include "../model/snapshot_v1.h"
#include "../model/user_error_v1.h"


// Create Instance Snapshot
//
snapshot_v1_t*
SnapshotsV1API_v1CreateSnapshot(apiClient_t *apiClient, char *instanceId, snapshot_creation_options_t *snapshot_creation_options);


// Delete an Instance Snapshot
//
void
SnapshotsV1API_v1DeleteInstanceSnapshot(apiClient_t *apiClient, char *instanceId, char *snapshotId);


// Delete a Snapshot
//
void
SnapshotsV1API_v1DeleteSnapshot(apiClient_t *apiClient, char *snapshotId);


// Get Instance Snapshot
//
snapshot_v1_t*
SnapshotsV1API_v1GetInstanceSnapshot(apiClient_t *apiClient, char *instanceId, char *snapshotId);


// Get Instance Snapshots
//
list_t*
SnapshotsV1API_v1GetInstanceSnapshots(apiClient_t *apiClient, char *instanceId);


// Get Snapshot
//
snapshot_v1_t*
SnapshotsV1API_v1GetSnapshot(apiClient_t *apiClient, char *snapshotId);


// Rename an Instance Snapshot
//
snapshot_v1_t*
SnapshotsV1API_v1RenameInstanceSnapshot(apiClient_t *apiClient, char *instanceId, char *snapshotId, snapshot_creation_options_t *snapshot_creation_options);


// Restore an Instance Snapshot
//
void
SnapshotsV1API_v1RestoreInstanceSnapshot(apiClient_t *apiClient, char *instanceId, char *snapshotId);


// Rename a Snapshot
//
snapshot_v1_t*
SnapshotsV1API_v1SnapshotRename(apiClient_t *apiClient, char *snapshotId, snapshot_creation_options_t *snapshot_creation_options);


