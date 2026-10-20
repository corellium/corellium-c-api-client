/*
 * touch_input_request_v1.h
 *
 * 
 */

#ifndef _touch_input_request_v1_H_
#define _touch_input_request_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct touch_input_request_v1_t touch_input_request_v1_t;

#include "any_type.h"
#include "object.h"



typedef struct touch_input_request_v1_t {
    object_t *position; //object
    list_t *buttons; //nonprimitive container
    int normalized; //boolean
    double wait; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} touch_input_request_v1_t;

__attribute__((deprecated)) touch_input_request_v1_t *touch_input_request_v1_create(
    object_t *position,
    list_t *buttons,
    int normalized,
    double wait
);

void touch_input_request_v1_free(touch_input_request_v1_t *touch_input_request_v1);

touch_input_request_v1_t *touch_input_request_v1_parseFromJSON(cJSON *touch_input_request_v1JSON);

cJSON *touch_input_request_v1_convertToJSON(touch_input_request_v1_t *touch_input_request_v1);

#endif /* _touch_input_request_v1_H_ */

