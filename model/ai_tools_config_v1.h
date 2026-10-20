/*
 * ai_tools_config_v1.h
 *
 * 
 */

#ifndef _ai_tools_config_v1_H_
#define _ai_tools_config_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct ai_tools_config_v1_t ai_tools_config_v1_t;




typedef struct ai_tools_config_v1_t {
    int ai_enabled; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} ai_tools_config_v1_t;

__attribute__((deprecated)) ai_tools_config_v1_t *ai_tools_config_v1_create(
    int ai_enabled
);

void ai_tools_config_v1_free(ai_tools_config_v1_t *ai_tools_config_v1);

ai_tools_config_v1_t *ai_tools_config_v1_parseFromJSON(cJSON *ai_tools_config_v1JSON);

cJSON *ai_tools_config_v1_convertToJSON(ai_tools_config_v1_t *ai_tools_config_v1);

#endif /* _ai_tools_config_v1_H_ */

