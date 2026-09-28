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
#include "../model/user_error_response.h"


// Delete an existing extension
//
// **Required role:** Domain administrator.  Deletes the extension identified by the given extension ID. Available on on-site deployments only. Deletion is asynchronous: the extension is marked `deleting` and the call returns 204 before removal completes.  Deletes are idempotent: an unknown extension ID, or an extension that was already deleted, is a successful no-op that still returns 204, and repeated calls return 204 as well. A 404 means the request path did not match a delete route, not that the target was missing. A repeat therefore returns 204 both while the record is still present in the `deleting` state and after it has disappeared.
//
void
ExtensionsAPI_v3DeleteExtension(apiClient_t *apiClient, char *extensionId);


// Get extension by ID
//
// **Required role:** Domain administrator.  Returns the extension identified by the given extension ID. Available on on-site deployments only.
//
extension_t*
ExtensionsAPI_v3GetExtensionById(apiClient_t *apiClient, char *extensionId);


// List all extensions
//
// **Required role:** Domain administrator.  Returns a paginated list of extensions available to the authenticated user. Available on on-site deployments only.
//
extension_list_t*
ExtensionsAPI_v3ListExtensions(apiClient_t *apiClient, double *limit, double *offset, char *if_none_match);


// Load an extension
//
// **Required role:** Domain administrator.  Loads an extension from a previously uploaded image, identified by its image ID. The extension definition is read from the image (its extension.json), so only the image ID is supplied. Available on on-site deployments only.
//
extension_t*
ExtensionsAPI_v3LoadExtension(apiClient_t *apiClient, load_extension_body_t *load_extension_body);


// Validates extension.json
//
// **Required role:** Domain administrator.  Validates and normalises an extension.json document, returning the parsed extension definition. Available on on-site deployments only.
//
object_t*
ExtensionsAPI_v3ParseExtensionJson(apiClient_t *apiClient, object_t *body);


// Update an existing extension
//
// **Required role:** Domain administrator.  Updates the extension identified by the given extension ID with the supplied definition. Available on on-site deployments only.
//
extension_t*
ExtensionsAPI_v3UpdateExtension(apiClient_t *apiClient, char *extensionId, update_extension_body_t *update_extension_body);


