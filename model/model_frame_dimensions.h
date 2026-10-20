/*
 * model_frame_dimensions.h
 *
 * Native display resolution.
 */

#ifndef _model_frame_dimensions_H_
#define _model_frame_dimensions_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct model_frame_dimensions_t model_frame_dimensions_t;




typedef struct model_frame_dimensions_t {
    double width; //numeric
    double height; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} model_frame_dimensions_t;

__attribute__((deprecated)) model_frame_dimensions_t *model_frame_dimensions_create(
    double width,
    double height
);

void model_frame_dimensions_free(model_frame_dimensions_t *model_frame_dimensions);

model_frame_dimensions_t *model_frame_dimensions_parseFromJSON(cJSON *model_frame_dimensionsJSON);

cJSON *model_frame_dimensions_convertToJSON(model_frame_dimensions_t *model_frame_dimensions);

#endif /* _model_frame_dimensions_H_ */

