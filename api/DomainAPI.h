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
#include "../model/insufficient_storage_error.h"
#include "../model/object.h"
#include "../model/patch_domain_welcome_message_body.h"
#include "../model/set_domain_welcome_message_body.h"
#include "../model/user_error.h"


// Create a welcome message for a domain
//
// **Required role:** Domain administrator.  Creates a new welcome message for the authenticated user's domain admin, or updates the existing one. The message is sanitized to prevent XSS.
//
domain_welcome_message_response_t*
DomainAPI_v3CreateDomainWelcomeMessage(apiClient_t *apiClient, set_domain_welcome_message_body_t *set_domain_welcome_message_body);


// Delete the welcome message for the authenticated user's domain
//
// **Required role:** Domain administrator.  Delete the welcome message for the authenticated user's domain.
//
void
DomainAPI_v3DeleteDomainWelcomeMessage(apiClient_t *apiClient);


// Get image upload status
//
// **Required role:** Domain administrator on on-site deployments; cloud administrator on cloud deployments.  Check resumable upload status for a domain-wide image or download the image file.
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
// **Required role:** Domain administrator.  Updates a new welcome message for the authenticated user's domain admin, or updates the existing one. The message is sanitized to prevent XSS.
//
domain_welcome_message_response_t*
DomainAPI_v3PatchDomainWelcomeMessage(apiClient_t *apiClient, patch_domain_welcome_message_body_t *patch_domain_welcome_message_body);


// Upload image chunk
//
// **Required role:** Domain administrator on on-site deployments; cloud administrator on cloud deployments.  Upload a chunk of a domain-wide image using the resumable upload protocol. Creates the image record on the first chunk if it does not yet exist.
//
void
DomainAPI_v3PutDomainImageUpload(apiClient_t *apiClient, char *type, char *imageId, char *name, binary_t* body, double *resumableChunkNumber, double *resumableChunkSize, double *resumableCurrentChunkSize, double *resumableTotalSize, double *resumableTotalChunks, char *corelliumChecksum, char *flavor, char *x_corellium_image_encoding, int *x_corellium_image_encapsulated, double *x_corellium_total_file_size, char *x_corellium_image_password);


