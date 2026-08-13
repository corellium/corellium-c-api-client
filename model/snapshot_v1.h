/*
 * snapshot_v1.h
 *
 * 
 */

#ifndef _snapshot_v1_H_
#define _snapshot_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct snapshot_v1_t snapshot_v1_t;

#include "snapshot_sharing_v1.h"
#include "snapshot_status.h"



typedef struct snapshot_v1_t {
    char *id; // string
    char *name; // string
    char *instance; // string
    struct snapshot_status_t *status; //model
    double date; //numeric
    int fresh; //boolean
    int live; //boolean
    int local; //boolean
    char *model; // string
    struct snapshot_sharing_v1_t *sharing; //model

    int _library_owned; // Is the library responsible for freeing this object?
} snapshot_v1_t;

__attribute__((deprecated)) snapshot_v1_t *snapshot_v1_create(
    char *id,
    char *name,
    char *instance,
    snapshot_status_t *status,
    double date,
    int fresh,
    int live,
    int local,
    char *model,
    snapshot_sharing_v1_t *sharing
);

void snapshot_v1_free(snapshot_v1_t *snapshot_v1);

snapshot_v1_t *snapshot_v1_parseFromJSON(cJSON *snapshot_v1JSON);

cJSON *snapshot_v1_convertToJSON(snapshot_v1_t *snapshot_v1);

#endif /* _snapshot_v1_H_ */

