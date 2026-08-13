/*
 * cluster_snapshot_status.h
 *
 * Current status of the snapshot.
 */

#ifndef _cluster_snapshot_status_H_
#define _cluster_snapshot_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct cluster_snapshot_status_t cluster_snapshot_status_t;




typedef struct cluster_snapshot_status_t {
    char *task; // string
    int created; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} cluster_snapshot_status_t;

__attribute__((deprecated)) cluster_snapshot_status_t *cluster_snapshot_status_create(
    char *task,
    int created
);

void cluster_snapshot_status_free(cluster_snapshot_status_t *cluster_snapshot_status);

cluster_snapshot_status_t *cluster_snapshot_status_parseFromJSON(cJSON *cluster_snapshot_statusJSON);

cJSON *cluster_snapshot_status_convertToJSON(cluster_snapshot_status_t *cluster_snapshot_status);

#endif /* _cluster_snapshot_status_H_ */

