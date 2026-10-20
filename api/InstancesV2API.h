#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/api_error_v1.h"
#include "../model/instance_state_v1.h"
#include "../model/user_error_v1.h"


// Recommended SSH Command for Quick Connect
//
char*
InstancesV2API_v2GetInstanceQuickConnectCommand(apiClient_t *apiClient, char *instanceId);


// Get state of Instance
//
corellium_api_instance_state_v1__e
InstancesV2API_v2GetInstanceState(apiClient_t *apiClient, char *instanceId, char *returnAttr);


