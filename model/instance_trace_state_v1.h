/*
 * instance_trace_state_v1.h
 *
 * 
 */

#ifndef _instance_trace_state_v1_H_
#define _instance_trace_state_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct instance_trace_state_v1_t instance_trace_state_v1_t;




typedef struct instance_trace_state_v1_t {
    int enabled; //boolean
    double length; //numeric
    char *filter; // string

    int _library_owned; // Is the library responsible for freeing this object?
} instance_trace_state_v1_t;

__attribute__((deprecated)) instance_trace_state_v1_t *instance_trace_state_v1_create(
    int enabled,
    double length,
    char *filter
);

void instance_trace_state_v1_free(instance_trace_state_v1_t *instance_trace_state_v1);

instance_trace_state_v1_t *instance_trace_state_v1_parseFromJSON(cJSON *instance_trace_state_v1JSON);

cJSON *instance_trace_state_v1_convertToJSON(instance_trace_state_v1_t *instance_trace_state_v1);

#endif /* _instance_trace_state_v1_H_ */

