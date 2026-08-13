#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/any_type.h"
#include "../model/create_interconnect_body.h"
#include "../model/get_interconnects_response.h"
#include "../model/interconnect_response.h"
#include "../model/object.h"
#include "../model/partial_update_interconnect_request.h"
#include "../model/update_interconnect_body.h"


// Create I/O Interconnect
//
// Create an I/O Interconnect for the specified project and attach virtual device interfaces.
//
interconnect_response_t*
InterconnectsV1API_v1CreateInterconnect(apiClient_t *apiClient, create_interconnect_body_t *create_interconnect_body);


// Delete I/O Interconnect
//
void
InterconnectsV1API_v1DeleteInterconnect(apiClient_t *apiClient, char *interconnectId);


// Get Interconnect
//
interconnect_response_t*
InterconnectsV1API_v1GetInterconnect(apiClient_t *apiClient, char *interconnectId);


// Get all I/O Interconnects
//
get_interconnects_response_t*
InterconnectsV1API_v1ListInterconnects(apiClient_t *apiClient, double limit, double offset, char *name, char *protocol, char *type, char *status, char *project, char *sort);


// Partial Update Interconnect
//
// Update some interconnect details for the specified interconnect identifier.
//
interconnect_response_t*
InterconnectsV1API_v1PatchInterconnect(apiClient_t *apiClient, char *interconnectId, partial_update_interconnect_request_t *partial_update_interconnect_request);


// Update Interconnect
//
// Update interconnect details for the specified interconnect identifier.
//
interconnect_response_t*
InterconnectsV1API_v1UpdateInterconnect(apiClient_t *apiClient, char *interconnectId, update_interconnect_body_t *update_interconnect_body);


