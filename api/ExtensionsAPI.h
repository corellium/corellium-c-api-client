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
#include "../model/extension.h"
#include "../model/extension_list.h"
#include "../model/load_extension_body.h"
#include "../model/object.h"
#include "../model/update_extension_body.h"
#include "../model/user_error.h"


// Delete an existing extension
//
// Deletes the extension identified by the given extension ID.
//
void
ExtensionsAPI_v3DeleteExtension(apiClient_t *apiClient, char *extensionId);


// Get extension by ID
//
// Returns the extension identified by the given extension ID.
//
extension_t*
ExtensionsAPI_v3GetExtensionById(apiClient_t *apiClient, char *extensionId);


// List all extensions
//
// Returns a paginated list of extensions available to the authenticated user.
//
extension_list_t*
ExtensionsAPI_v3ListExtensions(apiClient_t *apiClient, double *limit, double *offset, char *if_none_match);


// Load an extension
//
// Loads an extension from a previously uploaded image, identified by its image ID. The extension definition is read from the image (its extension.json), so only the image ID is supplied.
//
extension_t*
ExtensionsAPI_v3LoadExtension(apiClient_t *apiClient, load_extension_body_t *load_extension_body);


// Validates extension.json
//
// Validates and normalises an extension.json document, returning the parsed extension definition.
//
object_t*
ExtensionsAPI_v3ParseExtensionJson(apiClient_t *apiClient, object_t *body);


// Update an existing extension
//
// Updates the extension identified by the given extension ID with the supplied definition.
//
extension_t*
ExtensionsAPI_v3UpdateExtension(apiClient_t *apiClient, char *extensionId, update_extension_body_t *update_extension_body);


