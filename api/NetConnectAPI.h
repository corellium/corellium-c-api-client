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
#include "../model/user_error_response.h"
#include "../model/v3_delete_network_connection_request.h"


// Create a new Network Connection
//
// Creates a network connection that projects can route their outbound device traffic through. Pick a provider type from `v3ListNetworkProviders` and supply its settings; for a VLAN, pick a physical interface from `v3ListNetworkInterfaces`. VLAN networks are only supported in bridged networking mode. Afterwards, attach it to a project by setting the project's `settings.connection`. You must have the domain administrator role to create a network connection.
//
list_t*
NetConnectAPI_v3CreateNetworkConnection(apiClient_t *apiClient, object_t *body);


// Delete an existing Network Connection
//
// Delete an existing Network Connection. You must have the domain administrator role to delete a network connection.  Deletes are idempotent: an unknown `id`, or a connection that was already deleted, is a successful no-op that still returns 204, and repeated calls return 204 as well. A 404 means the request path did not match a delete route, not that the target was missing. A connection still attached to projects returns 400 unless `force` is set.
//
void
NetConnectAPI_v3DeleteNetworkConnection(apiClient_t *apiClient, char *id, v3_delete_network_connection_request_t *v3_delete_network_connection_request);


// Fetch an existing Network Connection
//
// Returns one network connection: its settings and, for each project using it, the connection's current state there. A network connection routes a project's outbound device traffic through a network you control, such as a VPN or a VLAN. You must have the domain administrator or project administrator role to fetch a network connection.
//
object_t*
NetConnectAPI_v3GetNetworkConnection(apiClient_t *apiClient, char *id);


// List available network connections
//
// Lists the network connections set up in your domain. A network connection routes a project's outbound device traffic through a network you control, such as a VPN or a VLAN; a project uses one when its `settings.connection` is set to the connection's ID (see `PATCH /v3/projects/{projectId}`). You must have the domain administrator or project administrator role to list network connections.
//
network_connections_t*
NetConnectAPI_v3ListNetworkConnections(apiClient_t *apiClient, double *limit, double *offset);


// List available physical network interfaces
//
// Lists the physical network ports on the server that can carry a VLAN network connection. Use one of these names when creating a VLAN connection. You must have the domain administrator role to list network interfaces.
//
network_interfaces_t*
NetConnectAPI_v3ListNetworkInterfaces(apiClient_t *apiClient, double *limit, double *offset);


// List available network providers
//
// Provides a list of registered network providers to be used when creating network connections via [`createNetworkConnection`](#tag/netconnect/POST/v3/network/connections). You must have the domain administrator role to list network providers.
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
// Replaces all of a network connection's settings. To change only some of them, use `v3PartialUpdateNetworkConnection`. You must have the domain administrator role to update a network connection.
//
object_t*
NetConnectAPI_v3UpdateNetworkConnection(apiClient_t *apiClient, char *id, update_network_connection_body_t *update_network_connection_body);


