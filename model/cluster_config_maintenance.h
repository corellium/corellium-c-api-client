/*
 * cluster_config_maintenance.h
 *
 * 
 */

#ifndef _cluster_config_maintenance_H_
#define _cluster_config_maintenance_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct cluster_config_maintenance_t cluster_config_maintenance_t;




typedef struct cluster_config_maintenance_t {
    char *message; // string
    char *header; // string

    int _library_owned; // Is the library responsible for freeing this object?
} cluster_config_maintenance_t;

__attribute__((deprecated)) cluster_config_maintenance_t *cluster_config_maintenance_create(
    char *message,
    char *header
);

void cluster_config_maintenance_free(cluster_config_maintenance_t *cluster_config_maintenance);

cluster_config_maintenance_t *cluster_config_maintenance_parseFromJSON(cJSON *cluster_config_maintenanceJSON);

cJSON *cluster_config_maintenance_convertToJSON(cluster_config_maintenance_t *cluster_config_maintenance);

#endif /* _cluster_config_maintenance_H_ */

