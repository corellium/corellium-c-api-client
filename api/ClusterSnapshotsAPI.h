#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/api_error_v1.h"
#include "../model/cluster_snapshot_v1.h"
#include "../model/snapshot_list.h"
#include "../model/snapshot_request.h"
#include "../model/user_error_v1.h"


// Delete a Cluster Snapshot
//
void
ClusterSnapshotsAPI_v1DeleteClusterSnapshot(apiClient_t *apiClient, char *snapshotId);


// Get Cluster Snapshot
//
cluster_snapshot_v1_t*
ClusterSnapshotsAPI_v1GetClusterSnapshot(apiClient_t *apiClient, char *snapshotId);


// Get Cluster Snapshots
//
snapshot_list_t*
ClusterSnapshotsAPI_v1GetClusterSnapshots(apiClient_t *apiClient, snapshot_request_t *request);


