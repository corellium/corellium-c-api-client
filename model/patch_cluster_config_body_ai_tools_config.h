/*
 * patch_cluster_config_body_ai_tools_config.h
 *
 * 
 */

#ifndef _patch_cluster_config_body_ai_tools_config_H_
#define _patch_cluster_config_body_ai_tools_config_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct patch_cluster_config_body_ai_tools_config_t patch_cluster_config_body_ai_tools_config_t;




typedef struct patch_cluster_config_body_ai_tools_config_t {
    int ai_enabled; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} patch_cluster_config_body_ai_tools_config_t;

__attribute__((deprecated)) patch_cluster_config_body_ai_tools_config_t *patch_cluster_config_body_ai_tools_config_create(
    int ai_enabled
);

void patch_cluster_config_body_ai_tools_config_free(patch_cluster_config_body_ai_tools_config_t *patch_cluster_config_body_ai_tools_config);

patch_cluster_config_body_ai_tools_config_t *patch_cluster_config_body_ai_tools_config_parseFromJSON(cJSON *patch_cluster_config_body_ai_tools_configJSON);

cJSON *patch_cluster_config_body_ai_tools_config_convertToJSON(patch_cluster_config_body_ai_tools_config_t *patch_cluster_config_body_ai_tools_config);

#endif /* _patch_cluster_config_body_ai_tools_config_H_ */

