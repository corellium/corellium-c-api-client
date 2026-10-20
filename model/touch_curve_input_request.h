/*
 * touch_curve_input_request.h
 *
 * 
 */

#ifndef _touch_curve_input_request_H_
#define _touch_curve_input_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct touch_curve_input_request_t touch_curve_input_request_t;




typedef struct touch_curve_input_request_t {
    list_t *start; //primitive container
    list_t *end; //primitive container
    list_t *bezier_points; //primitive container
    list_t *start_buttons; //primitive container
    list_t *end_buttons; //primitive container
    int normalized; //boolean
    double wait; //numeric
    double duration; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} touch_curve_input_request_t;

__attribute__((deprecated)) touch_curve_input_request_t *touch_curve_input_request_create(
    list_t *start,
    list_t *end,
    list_t *bezier_points,
    list_t *start_buttons,
    list_t *end_buttons,
    int normalized,
    double wait,
    double duration
);

void touch_curve_input_request_free(touch_curve_input_request_t *touch_curve_input_request);

touch_curve_input_request_t *touch_curve_input_request_parseFromJSON(cJSON *touch_curve_input_requestJSON);

cJSON *touch_curve_input_request_convertToJSON(touch_curve_input_request_t *touch_curve_input_request);

#endif /* _touch_curve_input_request_H_ */

