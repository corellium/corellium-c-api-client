/*
 * post_share_snapshot_request_payload.h
 *
 * 
 */

#ifndef _post_share_snapshot_request_payload_H_
#define _post_share_snapshot_request_payload_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_share_snapshot_request_payload_t post_share_snapshot_request_payload_t;




typedef struct post_share_snapshot_request_payload_t {
    char *sharing_type; // string
    char *password; // string

    int _library_owned; // Is the library responsible for freeing this object?
} post_share_snapshot_request_payload_t;

__attribute__((deprecated)) post_share_snapshot_request_payload_t *post_share_snapshot_request_payload_create(
    char *sharing_type,
    char *password
);

void post_share_snapshot_request_payload_free(post_share_snapshot_request_payload_t *post_share_snapshot_request_payload);

post_share_snapshot_request_payload_t *post_share_snapshot_request_payload_parseFromJSON(cJSON *post_share_snapshot_request_payloadJSON);

cJSON *post_share_snapshot_request_payload_convertToJSON(post_share_snapshot_request_payload_t *post_share_snapshot_request_payload);

#endif /* _post_share_snapshot_request_payload_H_ */

