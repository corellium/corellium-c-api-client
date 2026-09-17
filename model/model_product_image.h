/*
 * model_product_image.h
 *
 * Product image geometry, or null when this model has none.
 */

#ifndef _model_product_image_H_
#define _model_product_image_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct model_product_image_t model_product_image_t;

#include "model_product_image_inner.h"



typedef struct model_product_image_t {
    double width; //numeric
    struct model_product_image_inner_t *inner; //model
    int has_image; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} model_product_image_t;

__attribute__((deprecated)) model_product_image_t *model_product_image_create(
    double width,
    model_product_image_inner_t *inner,
    int has_image
);

void model_product_image_free(model_product_image_t *model_product_image);

model_product_image_t *model_product_image_parseFromJSON(cJSON *model_product_imageJSON);

cJSON *model_product_image_convertToJSON(model_product_image_t *model_product_image);

#endif /* _model_product_image_H_ */

