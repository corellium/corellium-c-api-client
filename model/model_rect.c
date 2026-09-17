#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "model_rect.h"



static model_rect_t *model_rect_create_internal(
    double top,
    double left,
    double width,
    double height,
    double radius
    ) {
    model_rect_t *model_rect_local_var = malloc(sizeof(model_rect_t));
    if (!model_rect_local_var) {
        return NULL;
    }
    model_rect_local_var->top = top;
    model_rect_local_var->left = left;
    model_rect_local_var->width = width;
    model_rect_local_var->height = height;
    model_rect_local_var->radius = radius;

    model_rect_local_var->_library_owned = 1;
    return model_rect_local_var;
}

__attribute__((deprecated)) model_rect_t *model_rect_create(
    double top,
    double left,
    double width,
    double height,
    double radius
    ) {
    return model_rect_create_internal (
        top,
        left,
        width,
        height,
        radius
        );
}

void model_rect_free(model_rect_t *model_rect) {
    if(NULL == model_rect){
        return ;
    }
    if(model_rect->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "model_rect_free");
        return ;
    }
    listEntry_t *listEntry;
    free(model_rect);
}

cJSON *model_rect_convertToJSON(model_rect_t *model_rect) {
    cJSON *item = cJSON_CreateObject();

    // model_rect->top
    if (!model_rect->top) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "top", model_rect->top) == NULL) {
    goto fail; //Numeric
    }


    // model_rect->left
    if (!model_rect->left) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "left", model_rect->left) == NULL) {
    goto fail; //Numeric
    }


    // model_rect->width
    if (!model_rect->width) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "width", model_rect->width) == NULL) {
    goto fail; //Numeric
    }


    // model_rect->height
    if (!model_rect->height) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "height", model_rect->height) == NULL) {
    goto fail; //Numeric
    }


    // model_rect->radius
    if(model_rect->radius) {
    if(cJSON_AddNumberToObject(item, "radius", model_rect->radius) == NULL) {
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

model_rect_t *model_rect_parseFromJSON(cJSON *model_rectJSON){

    model_rect_t *model_rect_local_var = NULL;

    // model_rect->top
    cJSON *top = cJSON_GetObjectItemCaseSensitive(model_rectJSON, "top");
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

    // model_rect->left
    cJSON *left = cJSON_GetObjectItemCaseSensitive(model_rectJSON, "left");
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

    // model_rect->width
    cJSON *width = cJSON_GetObjectItemCaseSensitive(model_rectJSON, "width");
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

    // model_rect->height
    cJSON *height = cJSON_GetObjectItemCaseSensitive(model_rectJSON, "height");
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

    // model_rect->radius
    cJSON *radius = cJSON_GetObjectItemCaseSensitive(model_rectJSON, "radius");
    if (cJSON_IsNull(radius)) {
        radius = NULL;
    }
    if (radius) { 
    if(!cJSON_IsNumber(radius))
    {
    goto end; //Numeric
    }
    }


    model_rect_local_var = model_rect_create_internal (
        top->valuedouble,
        left->valuedouble,
        width->valuedouble,
        height->valuedouble,
        radius ? radius->valuedouble : 0
        );

    return model_rect_local_var;
end:
    return NULL;

}
