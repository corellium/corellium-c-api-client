/*
 * user_snapshots.h
 *
 * 
 */

#ifndef _user_snapshots_H_
#define _user_snapshots_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct user_snapshots_t user_snapshots_t;

#include "shared_snapshots_info.h"



typedef struct user_snapshots_t {
    struct shared_snapshots_info_t *shared_with_user; //model
    struct shared_snapshots_info_t *shared_by_user; //model

    int _library_owned; // Is the library responsible for freeing this object?
} user_snapshots_t;

__attribute__((deprecated)) user_snapshots_t *user_snapshots_create(
    shared_snapshots_info_t *shared_with_user,
    shared_snapshots_info_t *shared_by_user
);

void user_snapshots_free(user_snapshots_t *user_snapshots);

user_snapshots_t *user_snapshots_parseFromJSON(cJSON *user_snapshotsJSON);

cJSON *user_snapshots_convertToJSON(user_snapshots_t *user_snapshots);

#endif /* _user_snapshots_H_ */

