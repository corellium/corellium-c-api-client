/*
 * model_rect.h
 *
 * Screen area within the bezel.
 */

#ifndef _model_rect_H_
#define _model_rect_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct model_rect_t model_rect_t;




typedef struct model_rect_t {
    double top; //numeric
    double left; //numeric
    double width; //numeric
    double height; //numeric
    double radius; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} model_rect_t;

__attribute__((deprecated)) model_rect_t *model_rect_create(
    double top,
    double left,
    double width,
    double height,
    double radius
);

void model_rect_free(model_rect_t *model_rect);

model_rect_t *model_rect_parseFromJSON(cJSON *model_rectJSON);

cJSON *model_rect_convertToJSON(model_rect_t *model_rect);

#endif /* _model_rect_H_ */

