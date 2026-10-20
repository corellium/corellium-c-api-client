/*
 * patch_cluster_config_body.h
 *
 * 
 */

#ifndef _patch_cluster_config_body_H_
#define _patch_cluster_config_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct patch_cluster_config_body_t patch_cluster_config_body_t;

#include "coordinator_config.h"
#include "patch_cluster_config_body_ai_tools_config.h"



typedef struct patch_cluster_config_body_t {
    double snapshot_limit; //numeric
    struct coordinator_config_t *coordinator_config; //model
    struct patch_cluster_config_body_ai_tools_config_t *ai_tools_config; //model
    char *originating_node; // string

    int _library_owned; // Is the library responsible for freeing this object?
} patch_cluster_config_body_t;

__attribute__((deprecated)) patch_cluster_config_body_t *patch_cluster_config_body_create(
    double snapshot_limit,
    coordinator_config_t *coordinator_config,
    patch_cluster_config_body_ai_tools_config_t *ai_tools_config,
    char *originating_node
);

void patch_cluster_config_body_free(patch_cluster_config_body_t *patch_cluster_config_body);

patch_cluster_config_body_t *patch_cluster_config_body_parseFromJSON(cJSON *patch_cluster_config_bodyJSON);

cJSON *patch_cluster_config_body_convertToJSON(patch_cluster_config_body_t *patch_cluster_config_body);

#endif /* _patch_cluster_config_body_H_ */

