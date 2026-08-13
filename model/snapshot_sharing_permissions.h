/*
 * snapshot_sharing_permissions.h
 *
 * 
 */

#ifndef _snapshot_sharing_permissions_H_
#define _snapshot_sharing_permissions_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct snapshot_sharing_permissions_t snapshot_sharing_permissions_t;




typedef struct snapshot_sharing_permissions_t {
    int cloud_enabled; //boolean
    int domain_enabled; //boolean
    int public_link; //boolean
    int domain_restricted_link; //boolean
    int password_public_link; //boolean
    int email_invite; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} snapshot_sharing_permissions_t;

__attribute__((deprecated)) snapshot_sharing_permissions_t *snapshot_sharing_permissions_create(
    int cloud_enabled,
    int domain_enabled,
    int public_link,
    int domain_restricted_link,
    int password_public_link,
    int email_invite
);

void snapshot_sharing_permissions_free(snapshot_sharing_permissions_t *snapshot_sharing_permissions);

snapshot_sharing_permissions_t *snapshot_sharing_permissions_parseFromJSON(cJSON *snapshot_sharing_permissionsJSON);

cJSON *snapshot_sharing_permissions_convertToJSON(snapshot_sharing_permissions_t *snapshot_sharing_permissions);

#endif /* _snapshot_sharing_permissions_H_ */

