/*
 * cluster_snapshot_list.h
 *
 * 
 */

#ifndef _cluster_snapshot_list_H_
#define _cluster_snapshot_list_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct cluster_snapshot_list_t cluster_snapshot_list_t;

#include "cluster_snapshot.h"



typedef struct cluster_snapshot_list_t {
    list_t *results; //nonprimitive container
    double count; //numeric
    double total; //numeric
    double limit; //numeric
    double offset; //numeric
    int has_more; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} cluster_snapshot_list_t;

__attribute__((deprecated)) cluster_snapshot_list_t *cluster_snapshot_list_create(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
);

void cluster_snapshot_list_free(cluster_snapshot_list_t *cluster_snapshot_list);

cluster_snapshot_list_t *cluster_snapshot_list_parseFromJSON(cJSON *cluster_snapshot_listJSON);

cJSON *cluster_snapshot_list_convertToJSON(cluster_snapshot_list_t *cluster_snapshot_list);

#endif /* _cluster_snapshot_list_H_ */

