/*
 * update_domain_settings_response_snapshot_sharing_permissions.h
 *
 * Applied snapshot sharing permissions.
 */

#ifndef _update_domain_settings_response_snapshot_sharing_permissions_H_
#define _update_domain_settings_response_snapshot_sharing_permissions_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct update_domain_settings_response_snapshot_sharing_permissions_t update_domain_settings_response_snapshot_sharing_permissions_t;




typedef struct update_domain_settings_response_snapshot_sharing_permissions_t {
    int cloud_enabled; //boolean
    int domain_enabled; //boolean
    int public_link; //boolean
    int domain_restricted_link; //boolean
    int password_public_link; //boolean
    int email_invite; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} update_domain_settings_response_snapshot_sharing_permissions_t;

__attribute__((deprecated)) update_domain_settings_response_snapshot_sharing_permissions_t *update_domain_settings_response_snapshot_sharing_permissions_create(
    int cloud_enabled,
    int domain_enabled,
    int public_link,
    int domain_restricted_link,
    int password_public_link,
    int email_invite
);

void update_domain_settings_response_snapshot_sharing_permissions_free(update_domain_settings_response_snapshot_sharing_permissions_t *update_domain_settings_response_snapshot_sharing_permissions);

update_domain_settings_response_snapshot_sharing_permissions_t *update_domain_settings_response_snapshot_sharing_permissions_parseFromJSON(cJSON *update_domain_settings_response_snapshot_sharing_permissionsJSON);

cJSON *update_domain_settings_response_snapshot_sharing_permissions_convertToJSON(update_domain_settings_response_snapshot_sharing_permissions_t *update_domain_settings_response_snapshot_sharing_permissions);

#endif /* _update_domain_settings_response_snapshot_sharing_permissions_H_ */

