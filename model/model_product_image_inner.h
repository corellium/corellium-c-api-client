/*
 * model_product_image_inner.h
 *
 * 
 */

#ifndef _model_product_image_inner_H_
#define _model_product_image_inner_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct model_product_image_inner_t model_product_image_inner_t;




typedef struct model_product_image_inner_t {
    double top; //numeric
    double left; //numeric
    double width; //numeric
    double height; //numeric
    double radius; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} model_product_image_inner_t;

__attribute__((deprecated)) model_product_image_inner_t *model_product_image_inner_create(
    double top,
    double left,
    double width,
    double height,
    double radius
);

void model_product_image_inner_free(model_product_image_inner_t *model_product_image_inner);

model_product_image_inner_t *model_product_image_inner_parseFromJSON(cJSON *model_product_image_innerJSON);

cJSON *model_product_image_inner_convertToJSON(model_product_image_inner_t *model_product_image_inner);

#endif /* _model_product_image_inner_H_ */

