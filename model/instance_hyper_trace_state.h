/*
 * instance_hyper_trace_state.h
 *
 * Hypervisor (btrace) tracing state.
 */

#ifndef _instance_hyper_trace_state_H_
#define _instance_hyper_trace_state_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct instance_hyper_trace_state_t instance_hyper_trace_state_t;

#include "instance_trace_filter.h"

// Enum ENABLED for instance_hyper_trace_state

typedef enum  { corellium_api_instance_hyper_trace_state_ENABLED_NULL = 0, corellium_api_instance_hyper_trace_state_ENABLED_enabling, corellium_api_instance_hyper_trace_state_ENABLED_enabled, corellium_api_instance_hyper_trace_state_ENABLED_disabling, corellium_api_instance_hyper_trace_state_ENABLED_disabled } corellium_api_instance_hyper_trace_state_ENABLED_e;

char* instance_hyper_trace_state_enabled_ToString(corellium_api_instance_hyper_trace_state_ENABLED_e enabled);

corellium_api_instance_hyper_trace_state_ENABLED_e instance_hyper_trace_state_enabled_FromString(char* enabled);



typedef struct instance_hyper_trace_state_t {
    corellium_api_instance_hyper_trace_state_ENABLED_e enabled; //enum
    double length; //numeric
    list_t *filter; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} instance_hyper_trace_state_t;

__attribute__((deprecated)) instance_hyper_trace_state_t *instance_hyper_trace_state_create(
    corellium_api_instance_hyper_trace_state_ENABLED_e enabled,
    double length,
    list_t *filter
);

void instance_hyper_trace_state_free(instance_hyper_trace_state_t *instance_hyper_trace_state);

instance_hyper_trace_state_t *instance_hyper_trace_state_parseFromJSON(cJSON *instance_hyper_trace_stateJSON);

cJSON *instance_hyper_trace_state_convertToJSON(instance_hyper_trace_state_t *instance_hyper_trace_state);

#endif /* _instance_hyper_trace_state_H_ */

