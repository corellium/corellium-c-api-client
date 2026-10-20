#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "model_product_image_inner.h"



static model_product_image_inner_t *model_product_image_inner_create_internal(
    double top,
    double left,
    double width,
    double height,
    double radius
    ) {
    model_product_image_inner_t *model_product_image_inner_local_var = malloc(sizeof(model_product_image_inner_t));
    if (!model_product_image_inner_local_var) {
        return NULL;
    }
    model_product_image_inner_local_var->top = top;
    model_product_image_inner_local_var->left = left;
    model_product_image_inner_local_var->width = width;
    model_product_image_inner_local_var->height = height;
    model_product_image_inner_local_var->radius = radius;

    model_product_image_inner_local_var->_library_owned = 1;
    return model_product_image_inner_local_var;
}

__attribute__((deprecated)) model_product_image_inner_t *model_product_image_inner_create(
    double top,
    double left,
    double width,
    double height,
    double radius
    ) {
    return model_product_image_inner_create_internal (
        top,
        left,
        width,
        height,
        radius
        );
}

void model_product_image_inner_free(model_product_image_inner_t *model_product_image_inner) {
    if(NULL == model_product_image_inner){
        return ;
    }
    if(model_product_image_inner->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "model_product_image_inner_free");
        return ;
    }
    listEntry_t *listEntry;
    free(model_product_image_inner);
}

cJSON *model_product_image_inner_convertToJSON(model_product_image_inner_t *model_product_image_inner) {
    cJSON *item = cJSON_CreateObject();

    // model_product_image_inner->top
    if (!model_product_image_inner->top) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "top", model_product_image_inner->top) == NULL) {
    goto fail; //Numeric
    }


    // model_product_image_inner->left
    if (!model_product_image_inner->left) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "left", model_product_image_inner->left) == NULL) {
    goto fail; //Numeric
    }


    // model_product_image_inner->width
    if (!model_product_image_inner->width) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "width", model_product_image_inner->width) == NULL) {
    goto fail; //Numeric
    }


    // model_product_image_inner->height
    if (!model_product_image_inner->height) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "height", model_product_image_inner->height) == NULL) {
    goto fail; //Numeric
    }


    // model_product_image_inner->radius
    if(model_product_image_inner->radius) {
    if(cJSON_AddNumberToObject(item, "radius", model_product_image_inner->radius) == NULL) {
    goto fail; //Numeric
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

model_product_image_inner_t *model_product_image_inner_parseFromJSON(cJSON *model_product_image_innerJSON){

    model_product_image_inner_t *model_product_image_inner_local_var = NULL;

    // model_product_image_inner->top
    cJSON *top = cJSON_GetObjectItemCaseSensitive(model_product_image_innerJSON, "top");
    if (cJSON_IsNull(top)) {
        top = NULL;
    }
    if (!top) {
        goto end;
    }

    
    if(!cJSON_IsNumber(top))
    {
    goto end; //Numeric
    }

    // model_product_image_inner->left
    cJSON *left = cJSON_GetObjectItemCaseSensitive(model_product_image_innerJSON, "left");
    if (cJSON_IsNull(left)) {
        left = NULL;
    }
    if (!left) {
        goto end;
    }

    
    if(!cJSON_IsNumber(left))
    {
    goto end; //Numeric
    }

    // model_product_image_inner->width
    cJSON *width = cJSON_GetObjectItemCaseSensitive(model_product_image_innerJSON, "width");
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

    // model_product_image_inner->height
    cJSON *height = cJSON_GetObjectItemCaseSensitive(model_product_image_innerJSON, "height");
    if (cJSON_IsNull(height)) {
        height = NULL;
    }
    if (!height) {
        goto end;
    }

    
    if(!cJSON_IsNumber(height))
    {
    goto end; //Numeric
    }

    // model_product_image_inner->radius
    cJSON *radius = cJSON_GetObjectItemCaseSensitive(model_product_image_innerJSON, "radius");
    if (cJSON_IsNull(radius)) {
        radius = NULL;
    }
    if (radius) { 
    if(!cJSON_IsNumber(radius))
    {
    goto end; //Numeric
    }
    }


    model_product_image_inner_local_var = model_product_image_inner_create_internal (
        top->valuedouble,
        left->valuedouble,
        width->valuedouble,
        height->valuedouble,
        radius ? radius->valuedouble : 0
        );

    return model_product_image_inner_local_var;
end:
    return NULL;

}
