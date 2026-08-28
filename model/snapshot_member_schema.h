/*
 * snapshot_member_schema.h
 *
 * 
 */

#ifndef _snapshot_member_schema_H_
#define _snapshot_member_schema_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct snapshot_member_schema_t snapshot_member_schema_t;




typedef struct snapshot_member_schema_t {
    char *email; // string
    char *invite_sent_at; //date time
    char *shared_on; //date time
    char *user_id; // string
    char *name; // string

    int _library_owned; // Is the library responsible for freeing this object?
} snapshot_member_schema_t;

__attribute__((deprecated)) snapshot_member_schema_t *snapshot_member_schema_create(
    char *email,
    char *invite_sent_at,
    char *shared_on,
    char *user_id,
    char *name
);

void snapshot_member_schema_free(snapshot_member_schema_t *snapshot_member_schema);

snapshot_member_schema_t *snapshot_member_schema_parseFromJSON(cJSON *snapshot_member_schemaJSON);

cJSON *snapshot_member_schema_convertToJSON(snapshot_member_schema_t *snapshot_member_schema);

#endif /* _snapshot_member_schema_H_ */

