/*
 * model_frame.h
 *
 * Bezel geometry, or null when this model has no bezel.
 */

#ifndef _model_frame_H_
#define _model_frame_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct model_frame_t model_frame_t;

#include "model_frame_dimensions.h"
#include "model_frame_home.h"
#include "model_rect.h"



typedef struct model_frame_t {
    double width; //numeric
    double height; //numeric
    struct model_rect_t *inner; //model
    struct model_frame_home_t *home; //model
    struct model_frame_dimensions_t *dimensions; //model
    double scale; //numeric
    int has_image; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} model_frame_t;

__attribute__((deprecated)) model_frame_t *model_frame_create(
    double width,
    double height,
    model_rect_t *inner,
    model_frame_home_t *home,
    model_frame_dimensions_t *dimensions,
    double scale,
    int has_image
);

void model_frame_free(model_frame_t *model_frame);

model_frame_t *model_frame_parseFromJSON(cJSON *model_frameJSON);

cJSON *model_frame_convertToJSON(model_frame_t *model_frame);

#endif /* _model_frame_H_ */

