/*
 * set_snapshot_permissions_body.h
 *
 * 
 */

#ifndef _set_snapshot_permissions_body_H_
#define _set_snapshot_permissions_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct set_snapshot_permissions_body_t set_snapshot_permissions_body_t;




typedef struct set_snapshot_permissions_body_t {
    list_t *members; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} set_snapshot_permissions_body_t;

__attribute__((deprecated)) set_snapshot_permissions_body_t *set_snapshot_permissions_body_create(
    list_t *members
);

void set_snapshot_permissions_body_free(set_snapshot_permissions_body_t *set_snapshot_permissions_body);

set_snapshot_permissions_body_t *set_snapshot_permissions_body_parseFromJSON(cJSON *set_snapshot_permissions_bodyJSON);

cJSON *set_snapshot_permissions_body_convertToJSON(set_snapshot_permissions_body_t *set_snapshot_permissions_body);

#endif /* _set_snapshot_permissions_body_H_ */

