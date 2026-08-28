#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/any_type.h"
#include "../model/api_error_v1.h"
#include "../model/extension_v1.h"
#include "../model/object.h"
#include "../model/update_extension.h"
#include "../model/user_error_v1.h"
#include "../model/v1_load_extension_parameters.h"


// Delete an existing extension
//
void
ExtensionsV1API_v1DeleteExtension(apiClient_t *apiClient, char *extensionId);


// Get extension by id
//
extension_v1_t*
ExtensionsV1API_v1GetExtensionById(apiClient_t *apiClient, char *extensionId);


// Get all extensions
//
list_t*
ExtensionsV1API_v1GetExtensions(apiClient_t *apiClient, double limit, double offset, char *if_none_match);


// Load an extension
//
extension_v1_t*
ExtensionsV1API_v1LoadExtension(apiClient_t *apiClient, v1_load_extension_parameters_t *v1_load_extension_parameters);


// Validates extension.json
//
object_t*
ExtensionsV1API_v1ParseExtensionJson(apiClient_t *apiClient, extension_v1_t *extension_v1);


// Update an existing extension
//
void
ExtensionsV1API_v1UpdateExtension(apiClient_t *apiClient, char *extensionId, update_extension_t *update_extension);


