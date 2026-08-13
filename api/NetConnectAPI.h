#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/api_error_v1.h"
#include "../model/api_not_found_error_v1.h"
#include "../model/create_network_connection_options.h"
#include "../model/delete_network_connection_options.h"
#include "../model/network_connection.h"
#include "../model/network_connection_pagination_result.h"
#include "../model/network_connection_provider_pagination_result.h"
#include "../model/update_network_connection_options.h"


// Create a new Network Connection
//
// You must have the domain administrator role to create a network connection. VLAN networks are only supported in bridged networking mode.
//
network_connection_t*
NetConnectAPI_v1CreateNetworkConnection(apiClient_t *apiClient, create_network_connection_options_t *create_network_connection_options);


// Delete an existing Network Connection
//
// You must have the domain administrator role to delete a network connection.
//
void
NetConnectAPI_v1DeleteNetworkConnection(apiClient_t *apiClient, char *id, delete_network_connection_options_t *delete_network_connection_options);


// Return the configuration and per project statuses for a single network provider.
//
// You must have the domain administrator or project administrator role to fetch a network connection.
//
network_connection_t*
NetConnectAPI_v1GetNetworkConnection(apiClient_t *apiClient, char *id);


// List available network connections
//
// You must have the domain administrator or project administrator role to list network connections.
//
network_connection_pagination_result_t*
NetConnectAPI_v1ListNetworkConnections(apiClient_t *apiClient, double limit, double offset);


// List available physical network interfaces
//
// Lists available physical network interfaces that can be used for VLAN configuration. You must have the domain administrator role to list network interfaces.
//
list_t*
NetConnectAPI_v1ListNetworkInterfaces(apiClient_t *apiClient);


// List available network providers
//
// Provides a list of registered network providers to be used when [creating network connections](#post-/v1/network/connections). You must have the domain administrator role to list network providers.
//
network_connection_provider_pagination_result_t*
NetConnectAPI_v1ListNetworkProviders(apiClient_t *apiClient);


// Update Network Connection (partial)
//
// Only updates the specified attributes. You must have the domain administrator role to update a network connection.
//
network_connection_t*
NetConnectAPI_v1PartialUpdateNetworkConnection(apiClient_t *apiClient, char *id, update_network_connection_options_t *update_network_connection_options);


// Update Network Connection
//
// You must have the domain administrator role to update a network connection.
//
network_connection_t*
NetConnectAPI_v1UpdateNetworkConnection(apiClient_t *apiClient, char *id, update_network_connection_options_t *update_network_connection_options);


