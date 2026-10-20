/*
 * cluster_node_status_cluster_totals_reserved.h
 *
 * Total reserved across cluster.
 */

#ifndef _cluster_node_status_cluster_totals_reserved_H_
#define _cluster_node_status_cluster_totals_reserved_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct cluster_node_status_cluster_totals_reserved_t cluster_node_status_cluster_totals_reserved_t;




typedef struct cluster_node_status_cluster_totals_reserved_t {
    double cores; //numeric
    double ram; //numeric
    double disk; //numeric
    double slot; //numeric
    double gpu; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} cluster_node_status_cluster_totals_reserved_t;

__attribute__((deprecated)) cluster_node_status_cluster_totals_reserved_t *cluster_node_status_cluster_totals_reserved_create(
    double cores,
    double ram,
    double disk,
    double slot,
    double gpu
);

void cluster_node_status_cluster_totals_reserved_free(cluster_node_status_cluster_totals_reserved_t *cluster_node_status_cluster_totals_reserved);

cluster_node_status_cluster_totals_reserved_t *cluster_node_status_cluster_totals_reserved_parseFromJSON(cJSON *cluster_node_status_cluster_totals_reservedJSON);

cJSON *cluster_node_status_cluster_totals_reserved_convertToJSON(cluster_node_status_cluster_totals_reserved_t *cluster_node_status_cluster_totals_reserved);

#endif /* _cluster_node_status_cluster_totals_reserved_H_ */

