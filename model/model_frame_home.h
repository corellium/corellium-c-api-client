/*
 * model_frame_home.h
 *
 * 
 */

#ifndef _model_frame_home_H_
#define _model_frame_home_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct model_frame_home_t model_frame_home_t;




typedef struct model_frame_home_t {
    double top; //numeric
    double left; //numeric
    double width; //numeric
    double height; //numeric
    double radius; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} model_frame_home_t;

__attribute__((deprecated)) model_frame_home_t *model_frame_home_create(
    double top,
    double left,
    double width,
    double height,
    double radius
);

void model_frame_home_free(model_frame_home_t *model_frame_home);

model_frame_home_t *model_frame_home_parseFromJSON(cJSON *model_frame_homeJSON);

cJSON *model_frame_home_convertToJSON(model_frame_home_t *model_frame_home);

#endif /* _model_frame_home_H_ */

