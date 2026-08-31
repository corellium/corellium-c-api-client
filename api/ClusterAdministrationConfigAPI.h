#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/any_type.h"
#include "../model/api_error_v1.h"
#include "../model/cluster_configuration_payload.h"
#include "../model/node_updates_failed.h"
#include "../model/object.h"


// Get cluster configuration
//
object_t*
ClusterAdministrationConfigAPI_v1GetClusterConfig(apiClient_t *apiClient);


// Update cluster configuration
//
void
ClusterAdministrationConfigAPI_v1PatchClusterConfig(apiClient_t *apiClient, body);


