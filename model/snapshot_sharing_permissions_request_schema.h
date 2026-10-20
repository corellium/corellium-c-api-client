/*
 * snapshot_sharing_permissions_request_schema.h
 *
 * 
 */

#ifndef _snapshot_sharing_permissions_request_schema_H_
#define _snapshot_sharing_permissions_request_schema_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct snapshot_sharing_permissions_request_schema_t snapshot_sharing_permissions_request_schema_t;




typedef struct snapshot_sharing_permissions_request_schema_t {
    int enabled; //boolean
    int public_link; //boolean
    int domain_restricted_link; //boolean
    int password_public_link; //boolean
    int email_invite; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} snapshot_sharing_permissions_request_schema_t;

__attribute__((deprecated)) snapshot_sharing_permissions_request_schema_t *snapshot_sharing_permissions_request_schema_create(
    int enabled,
    int public_link,
    int domain_restricted_link,
    int password_public_link,
    int email_invite
);

void snapshot_sharing_permissions_request_schema_free(snapshot_sharing_permissions_request_schema_t *snapshot_sharing_permissions_request_schema);

snapshot_sharing_permissions_request_schema_t *snapshot_sharing_permissions_request_schema_parseFromJSON(cJSON *snapshot_sharing_permissions_request_schemaJSON);

cJSON *snapshot_sharing_permissions_request_schema_convertToJSON(snapshot_sharing_permissions_request_schema_t *snapshot_sharing_permissions_request_schema);

#endif /* _snapshot_sharing_permissions_request_schema_H_ */

