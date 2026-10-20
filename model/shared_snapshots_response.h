/*
 * shared_snapshots_response.h
 *
 * 
 */

#ifndef _shared_snapshots_response_H_
#define _shared_snapshots_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct shared_snapshots_response_t shared_snapshots_response_t;

#include "shared_snapshot.h"



typedef struct shared_snapshots_response_t {
    list_t *shared_with_user; //nonprimitive container
    list_t *shared_by_user; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} shared_snapshots_response_t;

__attribute__((deprecated)) shared_snapshots_response_t *shared_snapshots_response_create(
    list_t *shared_with_user,
    list_t *shared_by_user
);

void shared_snapshots_response_free(shared_snapshots_response_t *shared_snapshots_response);

shared_snapshots_response_t *shared_snapshots_response_parseFromJSON(cJSON *shared_snapshots_responseJSON);

cJSON *shared_snapshots_response_convertToJSON(shared_snapshots_response_t *shared_snapshots_response);

#endif /* _shared_snapshots_response_H_ */

