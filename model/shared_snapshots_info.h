/*
 * shared_snapshots_info.h
 *
 * 
 */

#ifndef _shared_snapshots_info_H_
#define _shared_snapshots_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct shared_snapshots_info_t shared_snapshots_info_t;

#include "snapshot_owner.h"



typedef struct shared_snapshots_info_t {
    char *id; // string
    char *name; // string
    char *model; // string
    double shared_on; //numeric
    char *shared_with_member; // string
    struct snapshot_owner_t *shared_by; //model

    int _library_owned; // Is the library responsible for freeing this object?
} shared_snapshots_info_t;

__attribute__((deprecated)) shared_snapshots_info_t *shared_snapshots_info_create(
    char *id,
    char *name,
    char *model,
    double shared_on,
    char *shared_with_member,
    snapshot_owner_t *shared_by
);

void shared_snapshots_info_free(shared_snapshots_info_t *shared_snapshots_info);

shared_snapshots_info_t *shared_snapshots_info_parseFromJSON(cJSON *shared_snapshots_infoJSON);

cJSON *shared_snapshots_info_convertToJSON(shared_snapshots_info_t *shared_snapshots_info);

#endif /* _shared_snapshots_info_H_ */

