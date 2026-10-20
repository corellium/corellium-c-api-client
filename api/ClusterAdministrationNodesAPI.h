#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/any_type.h"
#include "../model/api_error_v1.h"
#include "../model/node_information_v1.h"
#include "../model/object.h"


// Get node details by ID
//
node_information_v1_t*
ClusterAdministrationNodesAPI_v1GetClusterNodes(apiClient_t *apiClient, char *nodeId);


// Access node console via SSH
//
// Access node console via SSH (WebSocket upgrade)
//
void
ClusterAdministrationNodesAPI_v1GetConsoleClusterNodes(apiClient_t *apiClient, char *nodeId);


// List servers in the cluster
//
list_t*
ClusterAdministrationNodesAPI_v1ListClusterNodes(apiClient_t *apiClient, double limit, double offset);


