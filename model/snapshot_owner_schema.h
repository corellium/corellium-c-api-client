/*
 * snapshot_owner_schema.h
 *
 * The owner of the snapshot.
 */

#ifndef _snapshot_owner_schema_H_
#define _snapshot_owner_schema_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct snapshot_owner_schema_t snapshot_owner_schema_t;

#include "any_type.h"
#include "object.h"



typedef struct snapshot_owner_schema_t {
    char *name; // string
    object_t *email; //object

    int _library_owned; // Is the library responsible for freeing this object?
} snapshot_owner_schema_t;

__attribute__((deprecated)) snapshot_owner_schema_t *snapshot_owner_schema_create(
    char *name,
    object_t *email
);

void snapshot_owner_schema_free(snapshot_owner_schema_t *snapshot_owner_schema);

snapshot_owner_schema_t *snapshot_owner_schema_parseFromJSON(cJSON *snapshot_owner_schemaJSON);

cJSON *snapshot_owner_schema_convertToJSON(snapshot_owner_schema_t *snapshot_owner_schema);

#endif /* _snapshot_owner_schema_H_ */

