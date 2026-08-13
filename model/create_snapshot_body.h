/*
 * create_snapshot_body.h
 *
 * 
 */

#ifndef _create_snapshot_body_H_
#define _create_snapshot_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct create_snapshot_body_t create_snapshot_body_t;




typedef struct create_snapshot_body_t {
    char *name; // string

    int _library_owned; // Is the library responsible for freeing this object?
} create_snapshot_body_t;

__attribute__((deprecated)) create_snapshot_body_t *create_snapshot_body_create(
    char *name
);

void create_snapshot_body_free(create_snapshot_body_t *create_snapshot_body);

create_snapshot_body_t *create_snapshot_body_parseFromJSON(cJSON *create_snapshot_bodyJSON);

cJSON *create_snapshot_body_convertToJSON(create_snapshot_body_t *create_snapshot_body);

#endif /* _create_snapshot_body_H_ */

