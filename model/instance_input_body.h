/*
 * instance_input_body.h
 *
 * 
 */

#ifndef _instance_input_body_H_
#define _instance_input_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct instance_input_body_t instance_input_body_t;

#include "text_input_request.h"
#include "touch_curve_input_request.h"
#include "touch_input_request.h"



typedef struct instance_input_body_t {
    list_t *position; //primitive container
    list_t *buttons; //primitive container
    int normalized; //boolean
    double wait; //numeric
    list_t *start; //primitive container
    list_t *end; //primitive container
    list_t *bezier_points; //primitive container
    list_t *start_buttons; //primitive container
    list_t *end_buttons; //primitive container
    double duration; //numeric
    char *text; // string
    double key_duration; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} instance_input_body_t;

__attribute__((deprecated)) instance_input_body_t *instance_input_body_create(
    list_t *position,
    list_t *buttons,
    int normalized,
    double wait,
    list_t *start,
    list_t *end,
    list_t *bezier_points,
    list_t *start_buttons,
    list_t *end_buttons,
    double duration,
    char *text,
    double key_duration
);

void instance_input_body_free(instance_input_body_t *instance_input_body);

instance_input_body_t *instance_input_body_parseFromJSON(cJSON *instance_input_bodyJSON);

cJSON *instance_input_body_convertToJSON(instance_input_body_t *instance_input_body);

#endif /* _instance_input_body_H_ */

