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
// Saves a snapshot of the device's current state, so you can return to it later with `v3RestoreInstanceSnapshot`. Take one before a risky change (an app install, a jailbreak step, an OS change) to be able to undo it.  **Running or off.** A device that is off can always be snapshotted. A running device can only be snapshotted if its model supports live snapshots; otherwise the request fails with 400, so stop the device first (`v3StopInstance`).  The snapshot is saved in the background: the response is the new snapshot with status `creating`. Poll `v3GetInstanceSnapshot` until it is ready. Each device can keep a limited number of snapshots (`snapshotLimit` in `GET /v3/config`); at the limit, delete an old one first.
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
// Returns one snapshot of this device, including its status. Poll it after `v3CreateInstanceSnapshot` until the snapshot has finished `creating`.
//
snapshot_t*
SnapshotsAPI_v3GetInstanceSnapshot(apiClient_t *apiClient, char *instanceId, char *snapshotId);


// Get snapshot
//
// Returns one snapshot by its ID, including its status and sharing details. Works for snapshots of your devices; use `v3AcceptSharedSnapshot` for snapshots shared with you.
//
snapshot_t*
SnapshotsAPI_v3GetSnapshot(apiClient_t *apiClient, char *snapshotId);


// List instance snapshots
//
// Lists the snapshots saved for one device, with each snapshot's ID, name and status. A snapshot is a saved copy of the device's storage at a moment in time; restore it with `v3RestoreInstanceSnapshot` to put the device back to that state. Results are paginated with `limit` and `offset`.
//
instance_snapshots_list_t*
SnapshotsAPI_v3ListInstanceSnapshots(apiClient_t *apiClient, char *instanceId, double *limit, double *offset);


// Update an instance snapshot
//
// Renames a snapshot. Send the new `name`. Returns the updated snapshot.
//
snapshot_t*
SnapshotsAPI_v3PatchInstanceSnapshot(apiClient_t *apiClient, char *instanceId, char *snapshotId, create_snapshot_body_t *create_snapshot_body);


// Restore instance snapshot
//
// Puts the device back to the state saved in a snapshot, replacing its current storage. Anything changed since the snapshot was taken is lost; take a new snapshot first if you want to keep it. The restore runs in the background and starts the device from the snapshot; returns 204 once it has been accepted. Poll `v3GetInstanceState` until the device is `on`.
//
void
SnapshotsAPI_v3RestoreInstanceSnapshot(apiClient_t *apiClient, char *instanceId, char *snapshotId);


// Update snapshot name
//
// Renames a snapshot. Send the new `name`. Returns the updated snapshot.
//
snapshot_t*
SnapshotsAPI_v3UpdateSnapshot(apiClient_t *apiClient, char *snapshotId, v3_update_snapshot_request_t *v3_update_snapshot_request);


