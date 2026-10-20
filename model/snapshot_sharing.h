/*
 * snapshot_sharing.h
 *
 * The sharing information of the snapshot.
 */

#ifndef _snapshot_sharing_H_
#define _snapshot_sharing_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct snapshot_sharing_t snapshot_sharing_t;

#include "snapshot_member.h"
#include "snapshot_owner.h"
#include "snapshot_sharing_type.h"



typedef struct snapshot_sharing_t {
    corellium_api_snapshot_sharing_type__e sharing_type; //referenced enum
    char *access_code; // string
    char *shared_on; //date time
    struct snapshot_owner_t *shared_by; //model
    list_t *members; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} snapshot_sharing_t;

__attribute__((deprecated)) snapshot_sharing_t *snapshot_sharing_create(
    corellium_api_snapshot_sharing_type__e sharing_type,
    char *access_code,
    char *shared_on,
    snapshot_owner_t *shared_by,
    list_t *members
);

void snapshot_sharing_free(snapshot_sharing_t *snapshot_sharing);

snapshot_sharing_t *snapshot_sharing_parseFromJSON(cJSON *snapshot_sharingJSON);

cJSON *snapshot_sharing_convertToJSON(snapshot_sharing_t *snapshot_sharing);

#endif /* _snapshot_sharing_H_ */

