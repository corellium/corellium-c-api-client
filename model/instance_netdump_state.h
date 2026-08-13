/*
 * instance_netdump_state.h
 *
 * 
 */

#ifndef _instance_netdump_state_H_
#define _instance_netdump_state_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct instance_netdump_state_t instance_netdump_state_t;




typedef struct instance_netdump_state_t {
    char *hash; // string
    char *info; // string
    int enabled; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} instance_netdump_state_t;

__attribute__((deprecated)) instance_netdump_state_t *instance_netdump_state_create(
    char *hash,
    char *info,
    int enabled
);

void instance_netdump_state_free(instance_netdump_state_t *instance_netdump_state);

instance_netdump_state_t *instance_netdump_state_parseFromJSON(cJSON *instance_netdump_stateJSON);

cJSON *instance_netdump_state_convertToJSON(instance_netdump_state_t *instance_netdump_state);

#endif /* _instance_netdump_state_H_ */

