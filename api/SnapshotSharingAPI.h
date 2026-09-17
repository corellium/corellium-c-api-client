#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/accept_snapshot_body.h"
#include "../model/api_error.h"
#include "../model/api_not_found_error.h"
#include "../model/set_snapshot_permissions_body.h"
#include "../model/share_snapshot_body.h"
#include "../model/shared_snapshots_response.h"
#include "../model/snapshot.h"
#include "../model/user_error_response.h"


// Accept a shared snapshot
//
snapshot_t*
SnapshotSharingAPI_v3AcceptSharedSnapshot(apiClient_t *apiClient, accept_snapshot_body_t *accept_snapshot_body);


// Delete member(s)
//
// Deletes one or more members from the list of members who have access to the snapshot.
//
void
SnapshotSharingAPI_v3DeleteSnapshotPermissions(apiClient_t *apiClient, char *snapshotId, set_snapshot_permissions_body_t *set_snapshot_permissions_body);


// Fetch shared snapshots
//
// Fetch snapshots shared with and shared by the requesting user.
//
shared_snapshots_response_t*
SnapshotSharingAPI_v3GetSharedSnapshots(apiClient_t *apiClient);


// Set member list
//
// Sets the list of members who have access to the snapshot.
//
snapshot_t*
SnapshotSharingAPI_v3SetSnapshotPermissions(apiClient_t *apiClient, char *snapshotId, set_snapshot_permissions_body_t *set_snapshot_permissions_body);


// Create or update snapshot sharing
//
// Creates or updates the sharing configuration for a snapshot.
//
snapshot_t*
SnapshotSharingAPI_v3ShareSnapshot(apiClient_t *apiClient, char *snapshotId, share_snapshot_body_t *share_snapshot_body);


