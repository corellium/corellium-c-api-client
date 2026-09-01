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
#include "../model/network_connection_providers.h"
#include "../model/network_connections.h"
#include "../model/network_interfaces.h"
#include "../model/object.h"
#include "../model/partial_update_network_connection_body.h"
#include "../model/update_network_connection_body.h"
#include "../model/user_error.h"
#include "../model/v3_delete_network_connection_request.h"


// Create a new Network Connection
//
// You must have the domain administrator role to create a network connection. VLAN networks are only supported in bridged networking mode.
//
list_t*
NetConnectAPI_v3CreateNetworkConnection(apiClient_t *apiClient, object_t *body);


// Delete an existing Network Connection
//
// Delete an existing Network Connection. You must have the domain administrator role to delete a network connection.
//
void
NetConnectAPI_v3DeleteNetworkConnection(apiClient_t *apiClient, char *id, v3_delete_network_connection_request_t *v3_delete_network_connection_request);


// Fetch an existing Network Connection
//
// Returns the configuration and per-project statuses for a single network connection. You must have the domain administrator or project administrator role to fetch a network connection.
//
object_t*
NetConnectAPI_v3GetNetworkConnection(apiClient_t *apiClient, char *id);


// List available network connections
//
// You must have the domain administrator or project administrator role to list network connections.
//
network_connections_t*
NetConnectAPI_v3ListNetworkConnections(apiClient_t *apiClient, double *limit, double *offset);


// List available physical network interfaces
//
// Lists available physical network interfaces that can be used for VLAN configuration. You must have the domain administrator role to list network interfaces.
//
network_interfaces_t*
NetConnectAPI_v3ListNetworkInterfaces(apiClient_t *apiClient, double *limit, double *offset);


// List available network providers
//
// Provides a list of registered network providers to be used when creating network connections via [`createNetworkConnection`](#operation/v3CreateNetworkConnection). You must have the domain administrator role to list network providers.
//
network_connection_providers_t*
NetConnectAPI_v3ListNetworkProviders(apiClient_t *apiClient, double *limit, double *offset);


// Update Network Connection (patch)
//
// Only updates the specified attributes. You must have the domain administrator role to update a network connection.
//
object_t*
NetConnectAPI_v3PartialUpdateNetworkConnection(apiClient_t *apiClient, char *id, partial_update_network_connection_body_t *partial_update_network_connection_body);


// Update Network Connection
//
// You must have the domain administrator role to update a network connection.
//
object_t*
NetConnectAPI_v3UpdateNetworkConnection(apiClient_t *apiClient, char *id, update_network_connection_body_t *update_network_connection_body);


