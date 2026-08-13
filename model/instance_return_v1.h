/*
 * instance_return_v1.h
 *
 * 
 */

#ifndef _instance_return_v1_H_
#define _instance_return_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct instance_return_v1_t instance_return_v1_t;

#include "instance_state_v1.h"



typedef struct instance_return_v1_t {
    char *id; // string
    corellium_api_instance_state_v1__e state; //referenced enum

    int _library_owned; // Is the library responsible for freeing this object?
} instance_return_v1_t;

__attribute__((deprecated)) instance_return_v1_t *instance_return_v1_create(
    char *id,
    corellium_api_instance_state_v1__e state
);

void instance_return_v1_free(instance_return_v1_t *instance_return_v1);

instance_return_v1_t *instance_return_v1_parseFromJSON(cJSON *instance_return_v1JSON);

cJSON *instance_return_v1_convertToJSON(instance_return_v1_t *instance_return_v1);

#endif /* _instance_return_v1_H_ */

