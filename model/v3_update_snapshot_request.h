/*
 * v3_update_snapshot_request.h
 *
 * 
 */

#ifndef _v3_update_snapshot_request_H_
#define _v3_update_snapshot_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v3_update_snapshot_request_t v3_update_snapshot_request_t;




typedef struct v3_update_snapshot_request_t {
    char *name; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v3_update_snapshot_request_t;

__attribute__((deprecated)) v3_update_snapshot_request_t *v3_update_snapshot_request_create(
    char *name
);

void v3_update_snapshot_request_free(v3_update_snapshot_request_t *v3_update_snapshot_request);

v3_update_snapshot_request_t *v3_update_snapshot_request_parseFromJSON(cJSON *v3_update_snapshot_requestJSON);

cJSON *v3_update_snapshot_request_convertToJSON(v3_update_snapshot_request_t *v3_update_snapshot_request);

#endif /* _v3_update_snapshot_request_H_ */

