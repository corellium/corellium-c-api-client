/*
 * cluster_config_coordinator_config_webplayer.h
 *
 * 
 */

#ifndef _cluster_config_coordinator_config_webplayer_H_
#define _cluster_config_coordinator_config_webplayer_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct cluster_config_coordinator_config_webplayer_t cluster_config_coordinator_config_webplayer_t;




typedef struct cluster_config_coordinator_config_webplayer_t {
    double inactivity_delete_timeout; //numeric
    double inactivity_shutdown_timeout; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} cluster_config_coordinator_config_webplayer_t;

__attribute__((deprecated)) cluster_config_coordinator_config_webplayer_t *cluster_config_coordinator_config_webplayer_create(
    double inactivity_delete_timeout,
    double inactivity_shutdown_timeout
);

void cluster_config_coordinator_config_webplayer_free(cluster_config_coordinator_config_webplayer_t *cluster_config_coordinator_config_webplayer);

cluster_config_coordinator_config_webplayer_t *cluster_config_coordinator_config_webplayer_parseFromJSON(cJSON *cluster_config_coordinator_config_webplayerJSON);

cJSON *cluster_config_coordinator_config_webplayer_convertToJSON(cluster_config_coordinator_config_webplayer_t *cluster_config_coordinator_config_webplayer);

#endif /* _cluster_config_coordinator_config_webplayer_H_ */

