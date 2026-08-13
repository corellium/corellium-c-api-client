/*
 * instance_trace_filter.h
 *
 * 
 */

#ifndef _instance_trace_filter_H_
#define _instance_trace_filter_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct instance_trace_filter_t instance_trace_filter_t;




typedef struct instance_trace_filter_t {
    char *trait; // string
    char *value; // string

    int _library_owned; // Is the library responsible for freeing this object?
} instance_trace_filter_t;

__attribute__((deprecated)) instance_trace_filter_t *instance_trace_filter_create(
    char *trait,
    char *value
);

void instance_trace_filter_free(instance_trace_filter_t *instance_trace_filter);

instance_trace_filter_t *instance_trace_filter_parseFromJSON(cJSON *instance_trace_filterJSON);

cJSON *instance_trace_filter_convertToJSON(instance_trace_filter_t *instance_trace_filter);

#endif /* _instance_trace_filter_H_ */

