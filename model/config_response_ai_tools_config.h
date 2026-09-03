/*
 * config_response_ai_tools_config.h
 *
 * Configuration for all cluster-hosted AI tools.
 */

#ifndef _config_response_ai_tools_config_H_
#define _config_response_ai_tools_config_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct config_response_ai_tools_config_t config_response_ai_tools_config_t;




typedef struct config_response_ai_tools_config_t {
    int ai_enabled; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} config_response_ai_tools_config_t;

__attribute__((deprecated)) config_response_ai_tools_config_t *config_response_ai_tools_config_create(
    int ai_enabled
);

void config_response_ai_tools_config_free(config_response_ai_tools_config_t *config_response_ai_tools_config);

config_response_ai_tools_config_t *config_response_ai_tools_config_parseFromJSON(cJSON *config_response_ai_tools_configJSON);

cJSON *config_response_ai_tools_config_convertToJSON(config_response_ai_tools_config_t *config_response_ai_tools_config);

#endif /* _config_response_ai_tools_config_H_ */

