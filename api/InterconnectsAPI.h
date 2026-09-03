#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/api_error.h"
#include "../model/create_interconnect_v3_body.h"
#include "../model/interconnect.h"
#include "../model/interconnect_list.h"
#include "../model/patch_interconnect_body.h"
#include "../model/update_interconnect_v3_body.h"
#include "../model/user_error_response.h"


// Create I/O Interconnect
//
// Create an I/O Interconnect for the specified project and attach virtual device interfaces.
//
interconnect_t*
InterconnectsAPI_v3CreateInterconnect(apiClient_t *apiClient, create_interconnect_v3_body_t *create_interconnect_v3_body);


// Delete I/O Interconnect
//
void
InterconnectsAPI_v3DeleteInterconnect(apiClient_t *apiClient, char *interconnectId);


// Get Interconnect
//
interconnect_t*
InterconnectsAPI_v3GetInterconnect(apiClient_t *apiClient, char *interconnectId);


// List I/O Interconnects
//
interconnect_list_t*
InterconnectsAPI_v3ListInterconnects(apiClient_t *apiClient, double *limit, double *offset, char *name, char *protocol, char *type, char *status, char *sort, char *projectId);


// Patch I/O Interconnect
//
interconnect_t*
InterconnectsAPI_v3PatchInterconnect(apiClient_t *apiClient, char *interconnectId, patch_interconnect_body_t *patch_interconnect_body);


// Update I/O Interconnect
//
interconnect_t*
InterconnectsAPI_v3UpdateInterconnect(apiClient_t *apiClient, char *interconnectId, update_interconnect_v3_body_t *update_interconnect_v3_body);


