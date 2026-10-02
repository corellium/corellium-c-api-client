#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/api_error.h"
#include "../model/api_not_found_error.h"
#include "../model/cluster_config.h"
#include "../model/cluster_config_update_error.h"
#include "../model/cluster_snapshot.h"
#include "../model/cluster_snapshot_list.h"
#include "../model/node_console_endpoint.h"
#include "../model/node_information.h"
#include "../model/node_list.h"
#include "../model/patch_cluster_config_body.h"
#include "../model/user_error_response.h"


// Delete cluster snapshot
//
// **Required role:** Cluster administrator.  Deletes a snapshot from the cluster, for example to free storage. Snapshots that are in use, still being created, or were just restored cannot be deleted (400). Requires a cluster administrator and the cluster snapshot management feature (`clusterSnapshotMgmt`).  Deletes are idempotent: an unknown `snapshotId`, or a snapshot that was already deleted, is a successful no-op that still returns 204, and repeated calls return 204 as well. A 404 means the request path did not match a delete route, not that the target was missing.
//
void
ClusterAPI_v3DeleteClusterSnapshot(apiClient_t *apiClient, char *snapshotId);


// Get cluster configuration
//
// **Required role:** Cluster administrator.  Returns the settings that apply to the whole cluster. Requires a cluster administrator.
//
cluster_config_t*
ClusterAPI_v3GetClusterConfig(apiClient_t *apiClient);


// Get cluster node
//
// **Required role:** Cluster administrator.  Returns details for one server (node) in the cluster, identified by the ID from `v3ListClusterNodes`. Requires a cluster administrator.
//
node_information_t*
ClusterAPI_v3GetClusterNode(apiClient_t *apiClient, char *nodeId);


// Get node console websocket URL
//
// **Required role:** Cluster administrator.  Returns a WebSocket URL for a terminal session on one cluster server (node), for maintenance and troubleshooting. Open the URL with a WebSocket client to get the console stream. Requires a cluster administrator.
//
node_console_endpoint_t*
ClusterAPI_v3GetClusterNodeConsole(apiClient_t *apiClient, char *nodeId);


// Get cluster snapshot
//
// **Required role:** Cluster administrator.  Returns one snapshot from the cluster-wide list. Requires a cluster administrator and the cluster snapshot management feature (`clusterSnapshotMgmt`).
//
cluster_snapshot_t*
ClusterAPI_v3GetClusterSnapshot(apiClient_t *apiClient, char *snapshotId);


// List cluster nodes
//
// **Required role:** Cluster administrator.  Lists the servers (nodes) that make up this Corellium cluster, with their status and resources. Use it to check cluster health or find a node before opening its console. Requires a cluster administrator. Results are paginated.
//
node_list_t*
ClusterAPI_v3ListClusterNodes(apiClient_t *apiClient, double *limit, double *offset);


// List cluster snapshots
//
// **Required role:** Cluster administrator.  Lists device snapshots across the whole cluster, for administrators managing storage. Requires a cluster administrator and the cluster snapshot management feature (`clusterSnapshotMgmt`). Results are paginated. For one device's snapshots, use `GET /v3/instances/{instanceId}/snapshots` instead.
//
cluster_snapshot_list_t*
ClusterAPI_v3ListClusterSnapshots(apiClient_t *apiClient, double *limit, double *offset, char *springboard, char *live, char *fresh, char *deviceName, char *task, char *search, char to, char from, char *orderBy);


// Update cluster configuration
//
// **Required role:** Cluster administrator.  Changes cluster-wide settings and applies them on every controller node. Send only the settings you want to change. Requires a cluster administrator.
//
void
ClusterAPI_v3PatchClusterConfig(apiClient_t *apiClient, patch_cluster_config_body_t *patch_cluster_config_body);


