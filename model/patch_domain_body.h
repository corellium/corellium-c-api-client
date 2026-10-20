/*
 * patch_domain_body.h
 *
 * 
 */

#ifndef _patch_domain_body_H_
#define _patch_domain_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct patch_domain_body_t patch_domain_body_t;

#include "allowed_devices_filter_schema.h"
#include "device_auto_shutdown_schema.h"
#include "patch_domain_body_webplayer.h"
#include "snapshot_sharing_permissions_request_schema.h"
#include "trial_extension.h"



typedef struct patch_domain_body_t {
    int totp_required; //boolean
    struct trial_extension_t *trial_extension; //model
    struct device_auto_shutdown_schema_t *device_auto_shutdown; //model
    list_t *allowed_devices_filters; //nonprimitive container
    struct patch_domain_body_webplayer_t *webplayer; //model
    struct snapshot_sharing_permissions_request_schema_t *snapshot_sharing_permissions; //model

    int _library_owned; // Is the library responsible for freeing this object?
} patch_domain_body_t;

__attribute__((deprecated)) patch_domain_body_t *patch_domain_body_create(
    int totp_required,
    trial_extension_t *trial_extension,
    device_auto_shutdown_schema_t *device_auto_shutdown,
    list_t *allowed_devices_filters,
    patch_domain_body_webplayer_t *webplayer,
    snapshot_sharing_permissions_request_schema_t *snapshot_sharing_permissions
);

void patch_domain_body_free(patch_domain_body_t *patch_domain_body);

patch_domain_body_t *patch_domain_body_parseFromJSON(cJSON *patch_domain_bodyJSON);

cJSON *patch_domain_body_convertToJSON(patch_domain_body_t *patch_domain_body);

#endif /* _patch_domain_body_H_ */

