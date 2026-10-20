/*
 * activity_resource_starts_with_filter.h
 *
 * 
 */

#ifndef _activity_resource_starts_with_filter_H_
#define _activity_resource_starts_with_filter_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct activity_resource_starts_with_filter_t activity_resource_starts_with_filter_t;

#include "any_type.h"
#include "object.h"



typedef struct activity_resource_starts_with_filter_t {
    object_t *starts_with; //object

    int _library_owned; // Is the library responsible for freeing this object?
} activity_resource_starts_with_filter_t;

__attribute__((deprecated)) activity_resource_starts_with_filter_t *activity_resource_starts_with_filter_create(
    object_t *starts_with
);

void activity_resource_starts_with_filter_free(activity_resource_starts_with_filter_t *activity_resource_starts_with_filter);

activity_resource_starts_with_filter_t *activity_resource_starts_with_filter_parseFromJSON(cJSON *activity_resource_starts_with_filterJSON);

cJSON *activity_resource_starts_with_filter_convertToJSON(activity_resource_starts_with_filter_t *activity_resource_starts_with_filter);

#endif /* _activity_resource_starts_with_filter_H_ */

