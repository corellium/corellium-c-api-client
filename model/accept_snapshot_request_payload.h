/*
 * accept_snapshot_request_payload.h
 *
 * 
 */

#ifndef _accept_snapshot_request_payload_H_
#define _accept_snapshot_request_payload_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct accept_snapshot_request_payload_t accept_snapshot_request_payload_t;




typedef struct accept_snapshot_request_payload_t {
    char *access_code; // string
    char *password; // string

    int _library_owned; // Is the library responsible for freeing this object?
} accept_snapshot_request_payload_t;

__attribute__((deprecated)) accept_snapshot_request_payload_t *accept_snapshot_request_payload_create(
    char *access_code,
    char *password
);

void accept_snapshot_request_payload_free(accept_snapshot_request_payload_t *accept_snapshot_request_payload);

accept_snapshot_request_payload_t *accept_snapshot_request_payload_parseFromJSON(cJSON *accept_snapshot_request_payloadJSON);

cJSON *accept_snapshot_request_payload_convertToJSON(accept_snapshot_request_payload_t *accept_snapshot_request_payload);

#endif /* _accept_snapshot_request_payload_H_ */

