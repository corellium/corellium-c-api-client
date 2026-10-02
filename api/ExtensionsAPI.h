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
// **Required role:** Domain administrator.  Returns one installed extension, including whether it is enabled and the device models (flavors) it adds. Requires a domain administrator. Available on on-site deployments only.
//
extension_t*
ExtensionsAPI_v3GetExtensionById(apiClient_t *apiClient, char *extensionId);


// List all extensions
//
// **Required role:** Domain administrator.  Lists the extensions installed on this deployment. An extension adds new device models (for example an IoT board such as a Raspberry Pi 4) that you can then create devices from; each one is defined by an `extension.json` file listing its models, CPU cores, memory and boot options. Requires a domain administrator. Available on on-site deployments only. The response carries an ETag; send it back as `If-None-Match` to get 304 when nothing changed.
//
extension_list_t*
ExtensionsAPI_v3ListExtensions(apiClient_t *apiClient, double *limit, double *offset, char *if_none_match);


// Load an extension
//
// **Required role:** Domain administrator.  Installs an extension so its device models become available. **Steps:** (1) optionally check your `extension.json` with `v3ParseExtensionJson`; (2) upload the extension file with `POST /v3/images` using `type: \"extension\"`; (3) call this with the returned `imageId`. The definition is read from the uploaded file, so only the image ID is sent. The new models then appear in `GET /v3/models`. Requires a domain administrator. Available on on-site deployments only.
//
extension_t*
ExtensionsAPI_v3LoadExtension(apiClient_t *apiClient, load_extension_body_t *load_extension_body);


// Validates extension.json
//
// **Required role:** Domain administrator.  Checks an `extension.json` document before you upload it, and returns the normalised definition the platform would use (with defaults filled in). Returns 400 with the problem if the document is invalid. Nothing is installed. Requires a domain administrator. Available on on-site deployments only.
//
object_t*
ExtensionsAPI_v3ParseExtensionJson(apiClient_t *apiClient, object_t *body);


// Update an existing extension
//
// **Required role:** Domain administrator.  Turns an installed extension on or off with `enabled`. While it is off, devices that use its models cannot be created or started. Requires a domain administrator. Available on on-site deployments only.
//
extension_t*
ExtensionsAPI_v3UpdateExtension(apiClient_t *apiClient, char *extensionId, update_extension_body_t *update_extension_body);


