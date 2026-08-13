/*
 * cluster_node_status_cluster_totals.h
 *
 * Aggregate cluster resource totals.
 */

#ifndef _cluster_node_status_cluster_totals_H_
#define _cluster_node_status_cluster_totals_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct cluster_node_status_cluster_totals_t cluster_node_status_cluster_totals_t;

#include "cluster_node_status_cluster_totals_available.h"
#include "cluster_node_status_cluster_totals_reserved.h"
#include "cluster_node_status_cluster_totals_total.h"



typedef struct cluster_node_status_cluster_totals_t {
    struct cluster_node_status_cluster_totals_reserved_t *reserved; //model
    struct cluster_node_status_cluster_totals_total_t *total; //model
    struct cluster_node_status_cluster_totals_available_t *available; //model

    int _library_owned; // Is the library responsible for freeing this object?
} cluster_node_status_cluster_totals_t;

__attribute__((deprecated)) cluster_node_status_cluster_totals_t *cluster_node_status_cluster_totals_create(
    cluster_node_status_cluster_totals_reserved_t *reserved,
    cluster_node_status_cluster_totals_total_t *total,
    cluster_node_status_cluster_totals_available_t *available
);

void cluster_node_status_cluster_totals_free(cluster_node_status_cluster_totals_t *cluster_node_status_cluster_totals);

cluster_node_status_cluster_totals_t *cluster_node_status_cluster_totals_parseFromJSON(cJSON *cluster_node_status_cluster_totalsJSON);

cJSON *cluster_node_status_cluster_totals_convertToJSON(cluster_node_status_cluster_totals_t *cluster_node_status_cluster_totals);

#endif /* _cluster_node_status_cluster_totals_H_ */

