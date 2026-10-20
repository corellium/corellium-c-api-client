/*
 * cluster_node_status.h
 *
 * 
 */

#ifndef _cluster_node_status_H_
#define _cluster_node_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct cluster_node_status_t cluster_node_status_t;

#include "cluster_node.h"
#include "cluster_node_status_cluster_totals.h"



typedef struct cluster_node_status_t {
    struct cluster_node_status_cluster_totals_t *cluster_totals; //model
    list_t *nodes; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} cluster_node_status_t;

__attribute__((deprecated)) cluster_node_status_t *cluster_node_status_create(
    cluster_node_status_cluster_totals_t *cluster_totals,
    list_t *nodes
);

void cluster_node_status_free(cluster_node_status_t *cluster_node_status);

cluster_node_status_t *cluster_node_status_parseFromJSON(cJSON *cluster_node_statusJSON);

cJSON *cluster_node_status_convertToJSON(cluster_node_status_t *cluster_node_status);

#endif /* _cluster_node_status_H_ */

