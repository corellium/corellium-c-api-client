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
#include "../model/domain_welcome_message_response.h"
#include "../model/object.h"
#include "../model/patch_domain_welcome_message_body.h"
#include "../model/set_domain_welcome_message_body.h"
#include "../model/user_error.h"


// Create a welcome message for a domain
//
// Creates a new welcome message for the authenticated user's domain admin, or updates the existing one. The message is sanitized to prevent XSS.
//
domain_welcome_message_response_t*
DomainAPI_v3CreateDomainWelcomeMessage(apiClient_t *apiClient, set_domain_welcome_message_body_t *set_domain_welcome_message_body);


// Delete the welcome message for the authenticated user's domain
//
void
DomainAPI_v3DeleteDomainWelcomeMessage(apiClient_t *apiClient);


// Get a domain-level image upload
//
binary_t*
DomainAPI_v3GetDomainImageUpload(apiClient_t *apiClient, char *type, char *imageId, char *name, double *resumableChunkNumber);


// Get the welcome message for the authenticated user's domain
//
// Retrieves the welcome message for the domain.
//
domain_welcome_message_response_t*
DomainAPI_v3GetDomainWelcomeMessage(apiClient_t *apiClient);


// Update a welcome message for a domain
//
// Updates a new welcome message for the authenticated user's domain admin, or updates the existing one. The message is sanitized to prevent XSS.
//
domain_welcome_message_response_t*
DomainAPI_v3PatchDomainWelcomeMessage(apiClient_t *apiClient, patch_domain_welcome_message_body_t *patch_domain_welcome_message_body);


// Domain-wide file upload
//
void
DomainAPI_v3UploadDomainImage(apiClient_t *apiClient, char *type, char *imageId, char *name, char *flavor, double *resumableChunkNumber, double *resumableChunkSize, double *resumableCurrentChunkSize, double *resumableTotalSize, double *resumableTotalChunks, binary_t* body);


