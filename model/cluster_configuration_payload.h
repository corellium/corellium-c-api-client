/*
 * cluster_configuration_payload.h
 *
 * 
 */

#ifndef _cluster_configuration_payload_H_
#define _cluster_configuration_payload_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct cluster_configuration_payload_t cluster_configuration_payload_t;

#include "coordinator_config_v1.h"



typedef struct cluster_configuration_payload_t {
    double snapshot_limit; //numeric
    struct coordinator_config_v1_t *coordinator_config; //model

    int _library_owned; // Is the library responsible for freeing this object?
} cluster_configuration_payload_t;

__attribute__((deprecated)) cluster_configuration_payload_t *cluster_configuration_payload_create(
    double snapshot_limit,
    coordinator_config_v1_t *coordinator_config
);

void cluster_configuration_payload_free(cluster_configuration_payload_t *cluster_configuration_payload);

cluster_configuration_payload_t *cluster_configuration_payload_parseFromJSON(cJSON *cluster_configuration_payloadJSON);

cJSON *cluster_configuration_payload_convertToJSON(cluster_configuration_payload_t *cluster_configuration_payload);

#endif /* _cluster_configuration_payload_H_ */

