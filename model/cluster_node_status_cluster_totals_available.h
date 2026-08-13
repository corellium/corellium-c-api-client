/*
 * cluster_node_status_cluster_totals_available.h
 *
 * Total available across cluster.
 */

#ifndef _cluster_node_status_cluster_totals_available_H_
#define _cluster_node_status_cluster_totals_available_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct cluster_node_status_cluster_totals_available_t cluster_node_status_cluster_totals_available_t;




typedef struct cluster_node_status_cluster_totals_available_t {
    double cores; //numeric
    double ram; //numeric
    double disk; //numeric
    double slot; //numeric
    double gpu; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} cluster_node_status_cluster_totals_available_t;

__attribute__((deprecated)) cluster_node_status_cluster_totals_available_t *cluster_node_status_cluster_totals_available_create(
    double cores,
    double ram,
    double disk,
    double slot,
    double gpu
);

void cluster_node_status_cluster_totals_available_free(cluster_node_status_cluster_totals_available_t *cluster_node_status_cluster_totals_available);

cluster_node_status_cluster_totals_available_t *cluster_node_status_cluster_totals_available_parseFromJSON(cJSON *cluster_node_status_cluster_totals_availableJSON);

cJSON *cluster_node_status_cluster_totals_available_convertToJSON(cluster_node_status_cluster_totals_available_t *cluster_node_status_cluster_totals_available);

#endif /* _cluster_node_status_cluster_totals_available_H_ */

