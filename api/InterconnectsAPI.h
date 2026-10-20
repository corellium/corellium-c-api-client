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
// Creates an I/O interconnect: a virtual wire, hub or switch that links interfaces on your devices so they can talk to each other, as if you had cabled real hardware together (for example connecting the Ethernet ports of two boards). Give it a `name`, the `projectId`, a `protocol` and `type`, and the device `interfaces` to connect; every device must be in that project. Returns the new interconnect, which starts with status `detached`.  You can also connect or disconnect one device interface later with `POST /v3/instances/{instanceId}/interfaces` and `DELETE /v3/instances/{instanceId}/interfaces/{interfaceId}`; those device-level calls require the configurable I/O license feature.
//
interconnect_t*
InterconnectsAPI_v3CreateInterconnect(apiClient_t *apiClient, create_interconnect_v3_body_t *create_interconnect_v3_body);


// Delete I/O Interconnect
//
// Deletes an I/O interconnect, disconnecting every device interface on it. The devices themselves are not affected.  Deletes are idempotent: an unknown `interconnectId`, or one that is not visible to the caller, is a successful no-op that still returns 204, and repeated calls return 204 as well. A 404 means the request path did not match a delete route, not that the target was missing.
//
void
InterconnectsAPI_v3DeleteInterconnect(apiClient_t *apiClient, char *interconnectId);


// Get Interconnect
//
// Returns one I/O interconnect, including which device interfaces it connects and its current status.
//
interconnect_t*
InterconnectsAPI_v3GetInterconnect(apiClient_t *apiClient, char *interconnectId);


// List I/O Interconnects
//
// Lists the I/O interconnects in your projects, with their status and how many devices each connects. Filter by name, protocol, type, status or project, sort with `sort`, and page with `limit` and `offset`.
//
interconnect_list_t*
InterconnectsAPI_v3ListInterconnects(apiClient_t *apiClient, double *limit, double *offset, char *name, char *protocol, char *type, char *status, char *sort, char *projectId);


// Patch I/O Interconnect
//
// Changes only the fields you send: `name` and/or `interfaces`. When you send `interfaces`, it replaces the whole list of connected interfaces. Returns the updated interconnect.
//
interconnect_t*
InterconnectsAPI_v3PatchInterconnect(apiClient_t *apiClient, char *interconnectId, patch_interconnect_body_t *patch_interconnect_body);


// Update I/O Interconnect
//
// Replaces an interconnect's `name` and full list of connected `interfaces`. Interfaces you leave out are disconnected. `projectId`, `protocol` and `type` cannot be changed; if you send them they must match the current values. To change only some fields, use `v3PatchInterconnect`.
//
interconnect_t*
InterconnectsAPI_v3UpdateInterconnect(apiClient_t *apiClient, char *interconnectId, update_interconnect_v3_body_t *update_interconnect_v3_body);


