/*
 * instance_trace_state.h
 *
 * System call (strace) tracing state.
 */

#ifndef _instance_trace_state_H_
#define _instance_trace_state_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct instance_trace_state_t instance_trace_state_t;

#include "instance_trace_filter.h"



typedef struct instance_trace_state_t {
    int enabled; //boolean
    double length; //numeric
    list_t *filter; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} instance_trace_state_t;

__attribute__((deprecated)) instance_trace_state_t *instance_trace_state_create(
    int enabled,
    double length,
    list_t *filter
);

void instance_trace_state_free(instance_trace_state_t *instance_trace_state);

instance_trace_state_t *instance_trace_state_parseFromJSON(cJSON *instance_trace_stateJSON);

cJSON *instance_trace_state_convertToJSON(instance_trace_state_t *instance_trace_state);

#endif /* _instance_trace_state_H_ */

