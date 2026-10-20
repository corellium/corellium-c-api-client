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
// Checks that you may use a snapshot someone shared with you, using the access code they gave you (and the password, for `passwordPublicLink`). Returns the snapshot.  To create a device from it, call `POST /v3/instances` with `sharedSnapshot` set to the snapshot's `id` (and `sharedSnapshotPassword` for password-protected shares). Returns 403 if the snapshot is not shared with you, for example it is limited to another domain or you are not on its member list.
//
snapshot_t*
SnapshotSharingAPI_v3AcceptSharedSnapshot(apiClient_t *apiClient, accept_snapshot_body_t *accept_snapshot_body);


// Delete member(s)
//
// Deletes one or more members from the list of members who have access to the snapshot.  Members that do not currently have access are ignored rather than reported as an error. Deletes are idempotent: an unknown `snapshotId` is a successful no-op that still returns 204, and repeated calls return 204 as well. A 404 means the request path did not match a delete route, not that the target was missing.
//
void
SnapshotSharingAPI_v3DeleteSnapshotPermissions(apiClient_t *apiClient, char *snapshotId, set_snapshot_permissions_body_t *set_snapshot_permissions_body);


// Fetch shared snapshots
//
// Lists snapshots involving you: `sharedWithUser` holds snapshots other people shared with you, and `sharedByUser` holds snapshots you shared. Use it to find a snapshot to create a device from, or to review what you are sharing.
//
shared_snapshots_response_t*
SnapshotSharingAPI_v3GetSharedSnapshots(apiClient_t *apiClient);


// Set member list
//
// Sets who may use a snapshot shared by email invitation: send the full list of members, by email address or user ID. The list replaces the previous one. If the snapshot was not shared yet, this shares it with sharing type `emailInvite`. Returns the snapshot with its updated `sharing` details.
//
snapshot_t*
SnapshotSharingAPI_v3SetSnapshotPermissions(apiClient_t *apiClient, char *snapshotId, set_snapshot_permissions_body_t *set_snapshot_permissions_body);


// Create or update snapshot sharing
//
// Shares one of your snapshots so other people can create devices from it, or stops sharing it. Choose who can use it with `sharingType` (see `SnapshotSharingType`); for `passwordPublicLink` also set `password`. The response is the snapshot with its `sharing` details, including the `accessCode` to give to the people you share with. Send `notShared` to stop sharing. Returns 403 if snapshot sharing, or that sharing type, is not enabled for your domain or license.
//
snapshot_t*
SnapshotSharingAPI_v3ShareSnapshot(apiClient_t *apiClient, char *snapshotId, share_snapshot_body_t *share_snapshot_body);


