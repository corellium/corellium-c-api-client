/*
 * snapshot_permissions_request_payload.h
 *
 * 
 */

#ifndef _snapshot_permissions_request_payload_H_
#define _snapshot_permissions_request_payload_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct snapshot_permissions_request_payload_t snapshot_permissions_request_payload_t;




typedef struct snapshot_permissions_request_payload_t {
    list_t *members; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} snapshot_permissions_request_payload_t;

__attribute__((deprecated)) snapshot_permissions_request_payload_t *snapshot_permissions_request_payload_create(
    list_t *members
);

void snapshot_permissions_request_payload_free(snapshot_permissions_request_payload_t *snapshot_permissions_request_payload);

snapshot_permissions_request_payload_t *snapshot_permissions_request_payload_parseFromJSON(cJSON *snapshot_permissions_request_payloadJSON);

cJSON *snapshot_permissions_request_payload_convertToJSON(snapshot_permissions_request_payload_t *snapshot_permissions_request_payload);

#endif /* _snapshot_permissions_request_payload_H_ */

