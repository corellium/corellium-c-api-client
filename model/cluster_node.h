/*
 * cluster_node.h
 *
 * 
 */

#ifndef _cluster_node_H_
#define _cluster_node_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct cluster_node_t cluster_node_t;

#include "cluster_node_available.h"
#include "cluster_node_reserved.h"
#include "cluster_node_total.h"



typedef struct cluster_node_t {
    struct cluster_node_reserved_t *reserved; //model
    struct cluster_node_total_t *total; //model
    struct cluster_node_available_t *available; //model
    char *hostname; // string
    char *address; // string
    char *last_seen; //date time

    int _library_owned; // Is the library responsible for freeing this object?
} cluster_node_t;

__attribute__((deprecated)) cluster_node_t *cluster_node_create(
    cluster_node_reserved_t *reserved,
    cluster_node_total_t *total,
    cluster_node_available_t *available,
    char *hostname,
    char *address,
    char *last_seen
);

void cluster_node_free(cluster_node_t *cluster_node);

cluster_node_t *cluster_node_parseFromJSON(cJSON *cluster_nodeJSON);

cJSON *cluster_node_convertToJSON(cluster_node_t *cluster_node);

#endif /* _cluster_node_H_ */

