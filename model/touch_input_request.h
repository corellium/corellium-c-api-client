/*
 * touch_input_request.h
 *
 * 
 */

#ifndef _touch_input_request_H_
#define _touch_input_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct touch_input_request_t touch_input_request_t;




typedef struct touch_input_request_t {
    list_t *position; //primitive container
    list_t *buttons; //primitive container
    int normalized; //boolean
    double wait; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} touch_input_request_t;

__attribute__((deprecated)) touch_input_request_t *touch_input_request_create(
    list_t *position,
    list_t *buttons,
    int normalized,
    double wait
);

void touch_input_request_free(touch_input_request_t *touch_input_request);

touch_input_request_t *touch_input_request_parseFromJSON(cJSON *touch_input_requestJSON);

cJSON *touch_input_request_convertToJSON(touch_input_request_t *touch_input_request);

#endif /* _touch_input_request_H_ */

