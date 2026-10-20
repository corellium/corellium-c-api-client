/*
 * snapshot_owner_v1.h
 *
 * 
 */

#ifndef _snapshot_owner_v1_H_
#define _snapshot_owner_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct snapshot_owner_v1_t snapshot_owner_v1_t;




typedef struct snapshot_owner_v1_t {
    char *name; // string
    char *email; // string

    int _library_owned; // Is the library responsible for freeing this object?
} snapshot_owner_v1_t;

__attribute__((deprecated)) snapshot_owner_v1_t *snapshot_owner_v1_create(
    char *name,
    char *email
);

void snapshot_owner_v1_free(snapshot_owner_v1_t *snapshot_owner_v1);

snapshot_owner_v1_t *snapshot_owner_v1_parseFromJSON(cJSON *snapshot_owner_v1JSON);

cJSON *snapshot_owner_v1_convertToJSON(snapshot_owner_v1_t *snapshot_owner_v1);

#endif /* _snapshot_owner_v1_H_ */

