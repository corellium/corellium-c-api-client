/*
 * flavor_frame_inner.h
 *
 * Inner screen area within the frame.
 */

#ifndef _flavor_frame_inner_H_
#define _flavor_frame_inner_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct flavor_frame_inner_t flavor_frame_inner_t;




typedef struct flavor_frame_inner_t {
    double top; //numeric
    double left; //numeric
    double width; //numeric
    double height; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} flavor_frame_inner_t;

__attribute__((deprecated)) flavor_frame_inner_t *flavor_frame_inner_create(
    double top,
    double left,
    double width,
    double height
);

void flavor_frame_inner_free(flavor_frame_inner_t *flavor_frame_inner);

flavor_frame_inner_t *flavor_frame_inner_parseFromJSON(cJSON *flavor_frame_innerJSON);

cJSON *flavor_frame_inner_convertToJSON(flavor_frame_inner_t *flavor_frame_inner);

#endif /* _flavor_frame_inner_H_ */

