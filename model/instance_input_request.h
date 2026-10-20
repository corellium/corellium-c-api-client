/*
 * instance_input_request.h
 *
 * 
 */

#ifndef _instance_input_request_H_
#define _instance_input_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct instance_input_request_t instance_input_request_t;

#include "any_type.h"
#include "object.h"
#include "text_input_request_v1.h"
#include "touch_curve_input_request_v1.h"
#include "touch_input_request_v1.h"



typedef struct instance_input_request_t {
    object_t *position; //object
    list_t *buttons; //nonprimitive container
    int normalized; //boolean
    double wait; //numeric
    object_t *start; //object
    object_t *end; //object
    list_t *bezier_points; //nonprimitive container
    list_t *start_buttons; //nonprimitive container
    list_t *end_buttons; //nonprimitive container
    double duration; //numeric
    char *required; // string
    double key_duration; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} instance_input_request_t;

__attribute__((deprecated)) instance_input_request_t *instance_input_request_create(
    object_t *position,
    list_t *buttons,
    int normalized,
    double wait,
    object_t *start,
    object_t *end,
    list_t *bezier_points,
    list_t *start_buttons,
    list_t *end_buttons,
    double duration,
    char *required,
    double key_duration
);

void instance_input_request_free(instance_input_request_t *instance_input_request);

instance_input_request_t *instance_input_request_parseFromJSON(cJSON *instance_input_requestJSON);

cJSON *instance_input_request_convertToJSON(instance_input_request_t *instance_input_request);

#endif /* _instance_input_request_H_ */

