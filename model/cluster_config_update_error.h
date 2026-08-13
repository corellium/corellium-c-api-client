/*
 * cluster_config_update_error.h
 *
 * 
 */

#ifndef _cluster_config_update_error_H_
#define _cluster_config_update_error_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct cluster_config_update_error_t cluster_config_update_error_t;

#include "node_information.h"



typedef struct cluster_config_update_error_t {
    char *message; // string
    list_t *nodes; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} cluster_config_update_error_t;

__attribute__((deprecated)) cluster_config_update_error_t *cluster_config_update_error_create(
    char *message,
    list_t *nodes
);

void cluster_config_update_error_free(cluster_config_update_error_t *cluster_config_update_error);

cluster_config_update_error_t *cluster_config_update_error_parseFromJSON(cJSON *cluster_config_update_errorJSON);

cJSON *cluster_config_update_error_convertToJSON(cluster_config_update_error_t *cluster_config_update_error);

#endif /* _cluster_config_update_error_H_ */

