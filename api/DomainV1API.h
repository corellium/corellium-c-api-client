#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/api_error_v1.h"
#include "../model/create_domain_welcome_message_body.h"
#include "../model/domain_welcome_message_response_v1.h"
#include "../model/update_domain_welcome_message_request.h"


// Create a welcome message for a domain
//
// Creates a new welcome message for the authenticated user's domain admin, or updates the existing one. The message is sanitized to prevent XSS.
//
domain_welcome_message_response_v1_t*
DomainV1API_v1CreateDomainWelcomeMessage(apiClient_t *apiClient, create_domain_welcome_message_body_t *create_domain_welcome_message_body);


// Delete the welcome message for the authenticated user's domain
//
void
DomainV1API_v1DeleteDomainWelcomeMessage(apiClient_t *apiClient);


// Get the welcome message for the authenticated user's domain
//
// Retrieves the welcome message for the domain.
//
domain_welcome_message_response_v1_t*
DomainV1API_v1GetDomainWelcomeMessage(apiClient_t *apiClient);


// Update a welcome message for a domain
//
// Updates a new welcome message for the authenticated user's domain admin, or updates the existing one. The message is sanitized to prevent XSS.
//
domain_welcome_message_response_v1_t*
DomainV1API_v1UpdateDomainWelcomeMessage(apiClient_t *apiClient, update_domain_welcome_message_request_t *update_domain_welcome_message_request);


