/*
 * domain_config_snapshot_sharing_permissions.h
 *
 * Snapshot sharing permissions.
 */

#ifndef _domain_config_snapshot_sharing_permissions_H_
#define _domain_config_snapshot_sharing_permissions_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct domain_config_snapshot_sharing_permissions_t domain_config_snapshot_sharing_permissions_t;




typedef struct domain_config_snapshot_sharing_permissions_t {
    int cloud_enabled; //boolean
    int domain_enabled; //boolean
    int public_link; //boolean
    int domain_restricted_link; //boolean
    int password_public_link; //boolean
    int email_invite; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} domain_config_snapshot_sharing_permissions_t;

__attribute__((deprecated)) domain_config_snapshot_sharing_permissions_t *domain_config_snapshot_sharing_permissions_create(
    int cloud_enabled,
    int domain_enabled,
    int public_link,
    int domain_restricted_link,
    int password_public_link,
    int email_invite
);

void domain_config_snapshot_sharing_permissions_free(domain_config_snapshot_sharing_permissions_t *domain_config_snapshot_sharing_permissions);

domain_config_snapshot_sharing_permissions_t *domain_config_snapshot_sharing_permissions_parseFromJSON(cJSON *domain_config_snapshot_sharing_permissionsJSON);

cJSON *domain_config_snapshot_sharing_permissions_convertToJSON(domain_config_snapshot_sharing_permissions_t *domain_config_snapshot_sharing_permissions);

#endif /* _domain_config_snapshot_sharing_permissions_H_ */

