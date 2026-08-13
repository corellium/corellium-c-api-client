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
// Deletes a cluster snapshot by ID. Requires cluster administrator permissions and the clusterSnapshotMgmt feature.
//
void
ClusterAPI_v3DeleteClusterSnapshot(apiClient_t *apiClient, char *snapshotId);


// Get cluster configuration
//
// Returns the current cluster configuration. Requires cluster administrator permissions.
//
object_t*
ClusterAPI_v3GetClusterConfig(apiClient_t *apiClient);


// Get cluster node
//
// Returns details for a specific node by ID. Requires cluster administrator permissions.
//
node_information_t*
ClusterAPI_v3GetClusterNode(apiClient_t *apiClient, char *nodeId);


// Get node console websocket URL
//
// Returns the WebSocket URL for accessing the node console via SSH. Connect to the returned URL to open the console stream. Requires cluster administrator permissions.
//
node_console_endpoint_t*
ClusterAPI_v3GetClusterNodeConsole(apiClient_t *apiClient, char *nodeId);


// Get cluster snapshot
//
// Returns details for a specific cluster snapshot. Requires cluster administrator permissions and the clusterSnapshotMgmt feature.
//
cluster_snapshot_t*
ClusterAPI_v3GetClusterSnapshot(apiClient_t *apiClient, char *snapshotId);


// List cluster nodes
//
// Returns information about all nodes in the cluster. Requires cluster administrator permissions.
//
node_list_t*
ClusterAPI_v3ListClusterNodes(apiClient_t *apiClient, double *limit, double *offset);


// List cluster snapshots
//
// Returns a paginated list of cluster volume snapshots. Requires cluster administrator permissions and the clusterSnapshotMgmt feature.
//
cluster_snapshot_list_t*
ClusterAPI_v3ListClusterSnapshots(apiClient_t *apiClient, double *limit, double *offset, char *springboard, char *live, char *fresh, char *deviceName, char *task, char *search, char *to, char *from, char *orderBy);


// Update cluster configuration
//
// Applies configuration changes across all controller nodes. Requires cluster administrator permissions.
//
void
ClusterAPI_v3PatchClusterConfig(apiClient_t *apiClient, patch_cluster_config_body_t *patch_cluster_config_body);


