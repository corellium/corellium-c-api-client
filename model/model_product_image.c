#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "model_product_image.h"



static model_product_image_t *model_product_image_create_internal(
    double width,
    model_product_image_inner_t *inner,
    int has_image
    ) {
    model_product_image_t *model_product_image_local_var = malloc(sizeof(model_product_image_t));
    if (!model_product_image_local_var) {
        return NULL;
    }
    model_product_image_local_var->width = width;
    model_product_image_local_var->inner = inner;
    model_product_image_local_var->has_image = has_image;

    model_product_image_local_var->_library_owned = 1;
    return model_product_image_local_var;
}

__attribute__((deprecated)) model_product_image_t *model_product_image_create(
    double width,
    model_product_image_inner_t *inner,
    int has_image
    ) {
    return model_product_image_create_internal (
        width,
        inner,
        has_image
        );
}

void model_product_image_free(model_product_image_t *model_product_image) {
    if(NULL == model_product_image){
        return ;
    }
    if(model_product_image->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "model_product_image_free");
        return ;
    }
    listEntry_t *listEntry;
    if (model_product_image->inner) {
        model_product_image_inner_free(model_product_image->inner);
        model_product_image->inner = NULL;
    }
    free(model_product_image);
}

cJSON *model_product_image_convertToJSON(model_product_image_t *model_product_image) {
    cJSON *item = cJSON_CreateObject();

    // model_product_image->width
    if (!model_product_image->width) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "width", model_product_image->width) == NULL) {
    goto fail; //Numeric
    }


    // model_product_image->inner
    if(model_product_image->inner) {
    cJSON *inner_local_JSON = model_product_image_inner_convertToJSON(model_product_image->inner);
    if(inner_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "inner", inner_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // model_product_image->has_image
    if (!model_product_image->has_image) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "hasImage", model_product_image->has_image) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

model_product_image_t *model_product_image_parseFromJSON(cJSON *model_product_imageJSON){

    model_product_image_t *model_product_image_local_var = NULL;

    // define the local variable for model_product_image->inner
    model_product_image_inner_t *inner_local_nonprim = NULL;

    // model_product_image->width
    cJSON *width = cJSON_GetObjectItemCaseSensitive(model_product_imageJSON, "width");
    if (cJSON_IsNull(width)) {
        width = NULL;
    }
    if (!width) {
        goto end;
    }

    
    if(!cJSON_IsNumber(width))
    {
    goto end; //Numeric
    }

    // model_product_image->inner
    cJSON *inner = cJSON_GetObjectItemCaseSensitive(model_product_imageJSON, "inner");
    if (cJSON_IsNull(inner)) {
        inner = NULL;
    }
    if (inner) { 
    inner_local_nonprim = model_product_image_inner_parseFromJSON(inner); //nonprimitive
    }

    // model_product_image->has_image
    cJSON *has_image = cJSON_GetObjectItemCaseSensitive(model_product_imageJSON, "hasImage");
    if (cJSON_IsNull(has_image)) {
        has_image = NULL;
    }
    if (!has_image) {
        goto end;
    }

    
    if(!cJSON_IsBool(has_image))
    {
    goto end; //Bool
    }


    model_product_image_local_var = model_product_image_create_internal (
        width->valuedouble,
        inner ? inner_local_nonprim : NULL,
        has_image->valueint
        );

    return model_product_image_local_var;
end:
    if (inner_local_nonprim) {
        model_product_image_inner_free(inner_local_nonprim);
        inner_local_nonprim = NULL;
    }
    return NULL;

}
