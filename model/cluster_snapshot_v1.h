/*
 * cluster_snapshot_v1.h
 *
 * 
 */

#ifndef _cluster_snapshot_v1_H_
#define _cluster_snapshot_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct cluster_snapshot_v1_t cluster_snapshot_v1_t;




typedef struct cluster_snapshot_v1_t {
    char *identifier; // string

    int _library_owned; // Is the library responsible for freeing this object?
} cluster_snapshot_v1_t;

__attribute__((deprecated)) cluster_snapshot_v1_t *cluster_snapshot_v1_create(
    char *identifier
);

void cluster_snapshot_v1_free(cluster_snapshot_v1_t *cluster_snapshot_v1);

cluster_snapshot_v1_t *cluster_snapshot_v1_parseFromJSON(cJSON *cluster_snapshot_v1JSON);

cJSON *cluster_snapshot_v1_convertToJSON(cluster_snapshot_v1_t *cluster_snapshot_v1);

#endif /* _cluster_snapshot_v1_H_ */

