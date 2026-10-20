/*
 * update_domain_settings_response.h
 *
 * 
 */

#ifndef _update_domain_settings_response_H_
#define _update_domain_settings_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct update_domain_settings_response_t update_domain_settings_response_t;

#include "allowed_devices_filter_schema.h"
#include "device_auto_shutdown_schema.h"
#include "trial_extension.h"
#include "update_domain_settings_response_settings.h"
#include "update_domain_settings_response_snapshot_sharing_permissions.h"
#include "update_domain_settings_response_webplayer.h"



typedef struct update_domain_settings_response_t {
    char *domain_id; // string
    struct update_domain_settings_response_settings_t *settings; //model
    struct trial_extension_t *trial_extension; //model
    struct device_auto_shutdown_schema_t *device_auto_shutdown; //model
    list_t *allowed_devices_filters; //nonprimitive container
    struct update_domain_settings_response_webplayer_t *webplayer; //model
    struct update_domain_settings_response_snapshot_sharing_permissions_t *snapshot_sharing_permissions; //model

    int _library_owned; // Is the library responsible for freeing this object?
} update_domain_settings_response_t;

__attribute__((deprecated)) update_domain_settings_response_t *update_domain_settings_response_create(
    char *domain_id,
    update_domain_settings_response_settings_t *settings,
    trial_extension_t *trial_extension,
    device_auto_shutdown_schema_t *device_auto_shutdown,
    list_t *allowed_devices_filters,
    update_domain_settings_response_webplayer_t *webplayer,
    update_domain_settings_response_snapshot_sharing_permissions_t *snapshot_sharing_permissions
);

void update_domain_settings_response_free(update_domain_settings_response_t *update_domain_settings_response);

update_domain_settings_response_t *update_domain_settings_response_parseFromJSON(cJSON *update_domain_settings_responseJSON);

cJSON *update_domain_settings_response_convertToJSON(update_domain_settings_response_t *update_domain_settings_response);

#endif /* _update_domain_settings_response_H_ */

