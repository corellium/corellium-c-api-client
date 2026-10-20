/*
 * shared_snapshot.h
 *
 * 
 */

#ifndef _shared_snapshot_H_
#define _shared_snapshot_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct shared_snapshot_t shared_snapshot_t;

#include "snapshot_owner.h"
#include "snapshot_sharing.h"
#include "snapshot_sharing_type.h"
#include "snapshot_status.h"



typedef struct shared_snapshot_t {
    char *shared_on; //date time
    char *shared_with_member; // string
    corellium_api_snapshot_sharing_type__e sharing_type; //referenced enum
    struct snapshot_owner_t *shared_by; //model
    char *id; // string
    double date; //numeric
    double hw_pac; //numeric
    char *instance; // string
    int live; //boolean
    int local; //boolean
    char *model; // string
    char *type; // string
    char *name; // string
    struct snapshot_status_t *status; //model
    int fresh; //boolean
    struct snapshot_sharing_t *sharing; //model

    int _library_owned; // Is the library responsible for freeing this object?
} shared_snapshot_t;

__attribute__((deprecated)) shared_snapshot_t *shared_snapshot_create(
    char *shared_on,
    char *shared_with_member,
    corellium_api_snapshot_sharing_type__e sharing_type,
    snapshot_owner_t *shared_by,
    char *id,
    double date,
    double hw_pac,
    char *instance,
    int live,
    int local,
    char *model,
    char *type,
    char *name,
    snapshot_status_t *status,
    int fresh,
    snapshot_sharing_t *sharing
);

void shared_snapshot_free(shared_snapshot_t *shared_snapshot);

shared_snapshot_t *shared_snapshot_parseFromJSON(cJSON *shared_snapshotJSON);

cJSON *shared_snapshot_convertToJSON(shared_snapshot_t *shared_snapshot);

#endif /* _shared_snapshot_H_ */

