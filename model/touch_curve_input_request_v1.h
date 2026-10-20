/*
 * touch_curve_input_request_v1.h
 *
 * 
 */

#ifndef _touch_curve_input_request_v1_H_
#define _touch_curve_input_request_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct touch_curve_input_request_v1_t touch_curve_input_request_v1_t;

#include "any_type.h"
#include "object.h"



typedef struct touch_curve_input_request_v1_t {
    object_t *start; //object
    object_t *end; //object
    list_t *bezier_points; //nonprimitive container
    list_t *start_buttons; //nonprimitive container
    list_t *end_buttons; //nonprimitive container
    int normalized; //boolean
    double wait; //numeric
    double duration; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} touch_curve_input_request_v1_t;

__attribute__((deprecated)) touch_curve_input_request_v1_t *touch_curve_input_request_v1_create(
    object_t *start,
    object_t *end,
    list_t *bezier_points,
    list_t *start_buttons,
    list_t *end_buttons,
    int normalized,
    double wait,
    double duration
);

void touch_curve_input_request_v1_free(touch_curve_input_request_v1_t *touch_curve_input_request_v1);

touch_curve_input_request_v1_t *touch_curve_input_request_v1_parseFromJSON(cJSON *touch_curve_input_request_v1JSON);

cJSON *touch_curve_input_request_v1_convertToJSON(touch_curve_input_request_v1_t *touch_curve_input_request_v1);

#endif /* _touch_curve_input_request_v1_H_ */

