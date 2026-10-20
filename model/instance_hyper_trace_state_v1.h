/*
 * instance_hyper_trace_state_v1.h
 *
 * 
 */

#ifndef _instance_hyper_trace_state_v1_H_
#define _instance_hyper_trace_state_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct instance_hyper_trace_state_v1_t instance_hyper_trace_state_v1_t;


// Enum ENABLED for instance_hyper_trace_state_v1

typedef enum  { corellium_api_instance_hyper_trace_state_v1_ENABLED_NULL = 0, corellium_api_instance_hyper_trace_state_v1_ENABLED_enabling, corellium_api_instance_hyper_trace_state_v1_ENABLED_enabled, corellium_api_instance_hyper_trace_state_v1_ENABLED_disabling, corellium_api_instance_hyper_trace_state_v1_ENABLED_disabled } corellium_api_instance_hyper_trace_state_v1_ENABLED_e;

char* instance_hyper_trace_state_v1_enabled_ToString(corellium_api_instance_hyper_trace_state_v1_ENABLED_e enabled);

corellium_api_instance_hyper_trace_state_v1_ENABLED_e instance_hyper_trace_state_v1_enabled_FromString(char* enabled);



typedef struct instance_hyper_trace_state_v1_t {
    corellium_api_instance_hyper_trace_state_v1_ENABLED_e enabled; //enum
    double length; //numeric
    char *filter; // string

    int _library_owned; // Is the library responsible for freeing this object?
} instance_hyper_trace_state_v1_t;

__attribute__((deprecated)) instance_hyper_trace_state_v1_t *instance_hyper_trace_state_v1_create(
    corellium_api_instance_hyper_trace_state_v1_ENABLED_e enabled,
    double length,
    char *filter
);

void instance_hyper_trace_state_v1_free(instance_hyper_trace_state_v1_t *instance_hyper_trace_state_v1);

instance_hyper_trace_state_v1_t *instance_hyper_trace_state_v1_parseFromJSON(cJSON *instance_hyper_trace_state_v1JSON);

cJSON *instance_hyper_trace_state_v1_convertToJSON(instance_hyper_trace_state_v1_t *instance_hyper_trace_state_v1);

#endif /* _instance_hyper_trace_state_v1_H_ */

