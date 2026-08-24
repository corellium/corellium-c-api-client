#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/any_type.h"
#include "../model/api_error.h"
#include "../model/api_not_found_error.h"
#include "../model/cluster_config_update_error.h"
#include "../model/cluster_snapshot.h"
#include "../model/cluster_snapshot_list.h"
#include "../model/node_console_endpoint.h"
#include "../model/node_information.h"
#include "../model/node_list.h"
#include "../model/object.h"
#include "../model/patch_cluster_config_body.h"
#include "../model/user_error.h"


// Delete cluster snapshot
//
// **Required role:** Cluster administrator.  Deletes a cluster snapshot by ID. Requires the clusterSnapshotMgmt feature.
//
void
ClusterAPI_v3DeleteClusterSnapshot(apiClient_t *apiClient, char *snapshotId);


// Get cluster configuration
//
// **Required role:** Cluster administrator.  Returns the current cluster configuration.
//
object_t*
ClusterAPI_v3GetClusterConfig(apiClient_t *apiClient);


// Get cluster node
//
// **Required role:** Cluster administrator.  Returns details for a specific node by ID.
//
node_information_t*
ClusterAPI_v3GetClusterNode(apiClient_t *apiClient, char *nodeId);


// Get node console websocket URL
//
// **Required role:** Cluster administrator.  Returns the WebSocket URL for accessing the node console via SSH. Connect to the returned URL to open the console stream.
//
node_console_endpoint_t*
ClusterAPI_v3GetClusterNodeConsole(apiClient_t *apiClient, char *nodeId);


// Get cluster snapshot
//
// **Required role:** Cluster administrator.  Returns details for a specific cluster snapshot. Requires the clusterSnapshotMgmt feature.
//
cluster_snapshot_t*
ClusterAPI_v3GetClusterSnapshot(apiClient_t *apiClient, char *snapshotId);


// List cluster nodes
//
// **Required role:** Cluster administrator.  Returns information about all nodes in the cluster.
//
node_list_t*
ClusterAPI_v3ListClusterNodes(apiClient_t *apiClient, double *limit, double *offset);


// List cluster snapshots
//
// **Required role:** Cluster administrator.  Returns a paginated list of cluster volume snapshots. Requires the clusterSnapshotMgmt feature.
//
cluster_snapshot_list_t*
ClusterAPI_v3ListClusterSnapshots(apiClient_t *apiClient, double *limit, double *offset, char *springboard, char *live, char *fresh, char *deviceName, char *task, char *search, char *to, char *from, char *orderBy);


// Update cluster configuration
//
// **Required role:** Cluster administrator.  Applies configuration changes across all controller nodes.
//
void
ClusterAPI_v3PatchClusterConfig(apiClient_t *apiClient, patch_cluster_config_body_t *patch_cluster_config_body);


