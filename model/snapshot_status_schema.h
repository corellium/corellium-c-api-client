/*
 * snapshot_status_schema.h
 *
 * The status of the snapshot.
 */

#ifndef _snapshot_status_schema_H_
#define _snapshot_status_schema_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct snapshot_status_schema_t snapshot_status_schema_t;




typedef struct snapshot_status_schema_t {
    char *task; // string
    int created; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} snapshot_status_schema_t;

__attribute__((deprecated)) snapshot_status_schema_t *snapshot_status_schema_create(
    char *task,
    int created
);

void snapshot_status_schema_free(snapshot_status_schema_t *snapshot_status_schema);

snapshot_status_schema_t *snapshot_status_schema_parseFromJSON(cJSON *snapshot_status_schemaJSON);

cJSON *snapshot_status_schema_convertToJSON(snapshot_status_schema_t *snapshot_status_schema);

#endif /* _snapshot_status_schema_H_ */

