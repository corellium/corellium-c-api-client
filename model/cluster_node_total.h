/*
 * cluster_node_total.h
 *
 * Total available resources.
 */

#ifndef _cluster_node_total_H_
#define _cluster_node_total_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct cluster_node_total_t cluster_node_total_t;




typedef struct cluster_node_total_t {
    double cores; //numeric
    double ram; //numeric
    double disk; //numeric
    double slot; //numeric
    double gpu; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} cluster_node_total_t;

__attribute__((deprecated)) cluster_node_total_t *cluster_node_total_create(
    double cores,
    double ram,
    double disk,
    double slot,
    double gpu
);

void cluster_node_total_free(cluster_node_total_t *cluster_node_total);

cluster_node_total_t *cluster_node_total_parseFromJSON(cJSON *cluster_node_totalJSON);

cJSON *cluster_node_total_convertToJSON(cluster_node_total_t *cluster_node_total);

#endif /* _cluster_node_total_H_ */

