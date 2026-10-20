/*
 * snapshot_status_v1.h
 *
 * 
 */

#ifndef _snapshot_status_v1_H_
#define _snapshot_status_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct snapshot_status_v1_t snapshot_status_v1_t;




typedef struct snapshot_status_v1_t {
    char *task; // string
    int created; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} snapshot_status_v1_t;

__attribute__((deprecated)) snapshot_status_v1_t *snapshot_status_v1_create(
    char *task,
    int created
);

void snapshot_status_v1_free(snapshot_status_v1_t *snapshot_status_v1);

snapshot_status_v1_t *snapshot_status_v1_parseFromJSON(cJSON *snapshot_status_v1JSON);

cJSON *snapshot_status_v1_convertToJSON(snapshot_status_v1_t *snapshot_status_v1);

#endif /* _snapshot_status_v1_H_ */

