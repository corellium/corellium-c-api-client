#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/accept_snapshot_request_payload.h"
#include "../model/api_error_v1.h"
#include "../model/post_share_snapshot_request_payload.h"
#include "../model/snapshot_permissions_request_payload.h"
#include "../model/snapshot_v1.h"
#include "../model/user_error_v1.h"
#include "../model/user_snapshots.h"


// Accept a snapshot shared with you
//
snapshot_v1_t*
SnapshotSharingV1API_v1AcceptSharedSnapshot(apiClient_t *apiClient, accept_snapshot_request_payload_t *accept_snapshot_request_payload);


// Delete member(s)
//
// Deletes one or more members from the list of members who have access to the snapshot
//
snapshot_v1_t*
SnapshotSharingV1API_v1DeleteSnapshotPermissions(apiClient_t *apiClient, char *snapshotId, snapshot_permissions_request_payload_t *snapshot_permissions_request_payload);


// Fetch shared snapshots
//
// Fetch snapshots shared with and shared by the requesting user
//
user_snapshots_t*
SnapshotSharingV1API_v1GetSharedSnapshots(apiClient_t *apiClient);


// Set member list
//
// Sets the list of members who have access to the snapshot
//
snapshot_v1_t*
SnapshotSharingV1API_v1SetSnapshotPermissions(apiClient_t *apiClient, char *snapshotId, snapshot_permissions_request_payload_t *snapshot_permissions_request_payload);


// Share snapshot
//
// Share a snapshot
//
snapshot_v1_t*
SnapshotSharingV1API_v1ShareSnapshot(apiClient_t *apiClient, char *snapshotId, post_share_snapshot_request_payload_t *post_share_snapshot_request_payload);


