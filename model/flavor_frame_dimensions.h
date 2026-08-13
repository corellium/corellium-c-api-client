/*
 * flavor_frame_dimensions.h
 *
 * Native display resolution.
 */

#ifndef _flavor_frame_dimensions_H_
#define _flavor_frame_dimensions_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct flavor_frame_dimensions_t flavor_frame_dimensions_t;




typedef struct flavor_frame_dimensions_t {
    double width; //numeric
    double height; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} flavor_frame_dimensions_t;

__attribute__((deprecated)) flavor_frame_dimensions_t *flavor_frame_dimensions_create(
    double width,
    double height
);

void flavor_frame_dimensions_free(flavor_frame_dimensions_t *flavor_frame_dimensions);

flavor_frame_dimensions_t *flavor_frame_dimensions_parseFromJSON(cJSON *flavor_frame_dimensionsJSON);

cJSON *flavor_frame_dimensions_convertToJSON(flavor_frame_dimensions_t *flavor_frame_dimensions);

#endif /* _flavor_frame_dimensions_H_ */

