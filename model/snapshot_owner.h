/*
 * snapshot_owner.h
 *
 * 
 */

#ifndef _snapshot_owner_H_
#define _snapshot_owner_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct snapshot_owner_t snapshot_owner_t;




typedef struct snapshot_owner_t {
    char *name; // string
    char *email; // string

    int _library_owned; // Is the library responsible for freeing this object?
} snapshot_owner_t;

__attribute__((deprecated)) snapshot_owner_t *snapshot_owner_create(
    char *name,
    char *email
);

void snapshot_owner_free(snapshot_owner_t *snapshot_owner);

snapshot_owner_t *snapshot_owner_parseFromJSON(cJSON *snapshot_ownerJSON);

cJSON *snapshot_owner_convertToJSON(snapshot_owner_t *snapshot_owner);

#endif /* _snapshot_owner_H_ */

