/*
 * ai_tools_config.h
 *
 * 
 */

#ifndef _ai_tools_config_H_
#define _ai_tools_config_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct ai_tools_config_t ai_tools_config_t;




typedef struct ai_tools_config_t {
    int ai_enabled; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} ai_tools_config_t;

__attribute__((deprecated)) ai_tools_config_t *ai_tools_config_create(
    int ai_enabled
);

void ai_tools_config_free(ai_tools_config_t *ai_tools_config);

ai_tools_config_t *ai_tools_config_parseFromJSON(cJSON *ai_tools_configJSON);

cJSON *ai_tools_config_convertToJSON(ai_tools_config_t *ai_tools_config);

#endif /* _ai_tools_config_H_ */

