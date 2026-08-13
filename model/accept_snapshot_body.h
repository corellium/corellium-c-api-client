/*
 * accept_snapshot_body.h
 *
 * 
 */

#ifndef _accept_snapshot_body_H_
#define _accept_snapshot_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct accept_snapshot_body_t accept_snapshot_body_t;




typedef struct accept_snapshot_body_t {
    char *access_code; // string
    char *password; // string

    int _library_owned; // Is the library responsible for freeing this object?
} accept_snapshot_body_t;

__attribute__((deprecated)) accept_snapshot_body_t *accept_snapshot_body_create(
    char *access_code,
    char *password
);

void accept_snapshot_body_free(accept_snapshot_body_t *accept_snapshot_body);

accept_snapshot_body_t *accept_snapshot_body_parseFromJSON(cJSON *accept_snapshot_bodyJSON);

cJSON *accept_snapshot_body_convertToJSON(accept_snapshot_body_t *accept_snapshot_body);

#endif /* _accept_snapshot_body_H_ */

