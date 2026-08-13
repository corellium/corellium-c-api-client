/*
 * user_snapshots_schema.h
 *
 * 
 */

#ifndef _user_snapshots_schema_H_
#define _user_snapshots_schema_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct user_snapshots_schema_t user_snapshots_schema_t;

#include "shared_snapshots_info_schema.h"



typedef struct user_snapshots_schema_t {
    list_t *shared_with_user; //nonprimitive container
    list_t *shared_by_user; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} user_snapshots_schema_t;

__attribute__((deprecated)) user_snapshots_schema_t *user_snapshots_schema_create(
    list_t *shared_with_user,
    list_t *shared_by_user
);

void user_snapshots_schema_free(user_snapshots_schema_t *user_snapshots_schema);

user_snapshots_schema_t *user_snapshots_schema_parseFromJSON(cJSON *user_snapshots_schemaJSON);

cJSON *user_snapshots_schema_convertToJSON(user_snapshots_schema_t *user_snapshots_schema);

#endif /* _user_snapshots_schema_H_ */

