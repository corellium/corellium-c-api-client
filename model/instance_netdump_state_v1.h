/*
 * instance_netdump_state_v1.h
 *
 * 
 */

#ifndef _instance_netdump_state_v1_H_
#define _instance_netdump_state_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct instance_netdump_state_v1_t instance_netdump_state_v1_t;




typedef struct instance_netdump_state_v1_t {
    char *hash; // string
    char *info; // string
    int enabled; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} instance_netdump_state_v1_t;

__attribute__((deprecated)) instance_netdump_state_v1_t *instance_netdump_state_v1_create(
    char *hash,
    char *info,
    int enabled
);

void instance_netdump_state_v1_free(instance_netdump_state_v1_t *instance_netdump_state_v1);

instance_netdump_state_v1_t *instance_netdump_state_v1_parseFromJSON(cJSON *instance_netdump_state_v1JSON);

cJSON *instance_netdump_state_v1_convertToJSON(instance_netdump_state_v1_t *instance_netdump_state_v1);

#endif /* _instance_netdump_state_v1_H_ */

