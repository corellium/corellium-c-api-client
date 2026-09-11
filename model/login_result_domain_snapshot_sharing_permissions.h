/*
 * login_result_domain_snapshot_sharing_permissions.h
 *
 * Snapshot sharing permissions.
 */

#ifndef _login_result_domain_snapshot_sharing_permissions_H_
#define _login_result_domain_snapshot_sharing_permissions_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct login_result_domain_snapshot_sharing_permissions_t login_result_domain_snapshot_sharing_permissions_t;




typedef struct login_result_domain_snapshot_sharing_permissions_t {
    int cloud_enabled; //boolean
    int domain_enabled; //boolean
    int public_link; //boolean
    int domain_restricted_link; //boolean
    int password_public_link; //boolean
    int email_invite; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} login_result_domain_snapshot_sharing_permissions_t;

__attribute__((deprecated)) login_result_domain_snapshot_sharing_permissions_t *login_result_domain_snapshot_sharing_permissions_create(
    int cloud_enabled,
    int domain_enabled,
    int public_link,
    int domain_restricted_link,
    int password_public_link,
    int email_invite
);

void login_result_domain_snapshot_sharing_permissions_free(login_result_domain_snapshot_sharing_permissions_t *login_result_domain_snapshot_sharing_permissions);

login_result_domain_snapshot_sharing_permissions_t *login_result_domain_snapshot_sharing_permissions_parseFromJSON(cJSON *login_result_domain_snapshot_sharing_permissionsJSON);

cJSON *login_result_domain_snapshot_sharing_permissions_convertToJSON(login_result_domain_snapshot_sharing_permissions_t *login_result_domain_snapshot_sharing_permissions);

#endif /* _login_result_domain_snapshot_sharing_permissions_H_ */

